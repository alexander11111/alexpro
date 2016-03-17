package src;

import com.siemens.icm.io.ATCommand;
import com.siemens.icm.io.ATCommandFailedException;

/**
 * Класс для отправки (а потом - и приема) SMS, потому что 
 * оказалось, что с ТС65 не работает WTK25, в котором вся эта
 * обработка есть.
 * @author dvk
 *
 */

public class CSmsSender {
	private ATCommand atCommand;
	//private Tc65SerialPort tc65SerialPort;
	private byte sbuf[];
//	String smsReceivedText;
//	String smsReceivedFromNumber;
	
	// Текст, отправитель, время отправки последнего принятого СМС
	public CPdu pdu;
	public CSerialPort pPort;
	public CSmsSender(ATCommand atCommand0)
	{
		try{
		//atCommand = new ATCommand(false);
		this.atCommand = atCommand0;
		//this.tc65SerialPort = tc65SerialPort;
		sbuf = new byte[512]; // С запасом 
		pdu = new CPdu();
		System.out.println("CSmsSender::>Create");
		}catch (Exception e)
		{
			System.out.println("CMain::>Exception!!!");
		}
	}
/**
 * Настройка модема для передачи SMS, выполняется один раз
 * при запуске программы.
 * @return true = ОК.
 */	
	
	boolean init()
	{
		boolean bRet = true;
		
		// Здесь надо послать в модем настройки СМС-канала
		try 
		{
			atCommand.send("AT+CMGF=0\r");// use PDU mode
			Thread.sleep(300);
			atCommand.send("AT+CSCS=\"UCS2\"\r");// UCS encoding
			Thread.sleep(300);
			atCommand.send("AT+CPMS=\"SM\",\"SM\",\"SM\"\r");// UCS encoding
			atCommand.send("AT+CNMI=1,1\r");// Report incoming SMS
			for(int i=0;i<25;i++)
			atCommand.send("AT+CMGD="+i+"\r");	
			//atCommand.send("AT+CNMI=0,1\r");// Report incoming SMS
			//Thread.sleep(300);
		} 
		catch (IllegalStateException e) 
		{
			System.out.println("\n\r"+e.getMessage()+"\n\r");
		} 
		catch (IllegalArgumentException e) 
		{
			System.out.println("\n\r"+e.getMessage()+"\n\r");
		} 
		catch (ATCommandFailedException e) 
		{
			System.out.println("\n\r"+e.getMessage()+"\n\r");
		}
		catch (Exception e)
		{
			System.out.println("CMain::>Exception!!!");
		}
		return bRet;
	}

	
/**
 * Читает последний полученный SMS командой at+cmgl=0
 * @return true если SMS принят
 */	
	public boolean receiveSMS()
	{
		boolean bRet = false;
		try 
		{
			String strReply = atCommand.send("AT+CMGL=0\r");
			int pos = strReply.indexOf("+CMGL:");
			boolean badFmt = true;
			if(strReply.length() < 30) // Просто ОК - это нормально
				badFmt = false;
			else
			{
				if(pos != -1) // есть PDU
				{
					pos++;
					// Ищем Enter  в строке +CMGL: xx,yy,zz
					pos = strReply.indexOf(0x0d, pos);
					if(pos != -1)
					{
						pos+=2;
						// Ищем Enter после PDU
						int pos2 = strReply.indexOf(0x0d, pos); 
						//System.out.println("\n\rpos(Enter)="+pos+", pos2="+pos2+"\n\r");
						if(pos2 != -1)
						{
							String strPDU = strReply.substring(pos, pos2);
							//System.out.println("PDU: "+strPDU+"(end PDU)\n\r");
							pdu.ParsePDU(strPDU);
							badFmt = false;
							bRet = true;
						}
					}
				}
			}
			if(badFmt == true)
				System.out.println("Bad CMGL: format:"+strReply+"\n\r");
		} 
		catch (IllegalStateException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalArgumentException e) 
		{
			e.printStackTrace();
		} 
		catch (ATCommandFailedException e) 
		{
			e.printStackTrace();
		}
		return bRet;
	}

	private byte bin2hex(byte n)
	{
		n = (byte)(n & 0x0F); 
		if(n>9) 
			return (byte)(n-10+'A'); 
		else return (byte)(n+'0');
	}

	private int create_pdu_mem(byte num[], char msg[])
	{
		int i;
		int j;
		byte n;
		short u;

		for (i=0;i<7;i++) sbuf[i]='0'; 		// Make pattern
		sbuf[3]='1'; 
		sbuf[9]='1';

		if (num[0]=='+') {sbuf[8]='9'; i=1;} 	// If the number is international
		else {sbuf[8]='8'; i=0;}
		j=11; n=0;

		while((num[i]<='9')&&(num[i]>='0'))	// Number
		{
			sbuf[j]=num[i++]; 
			n++;
			if((j&1) != 0) j--; else j+=3;		
		}
		if((n&1) != 0) {sbuf[j]='F'; j+=2;} else j-=1;	// align to byte boundary

		sbuf[7]=bin2hex(n);			// length of number
		sbuf[6]=bin2hex((byte)(n>>4));

		sbuf[j++]='0'; 				// Protocol Phone-to-phone, Operator specific
		sbuf[j++]='0'; 
		sbuf[j++]='0'; 				// Charset UNICODE
		sbuf[j++]='8';

		n=(byte)j; j+=2; i=0;				// Encode the message

		while( ( u=(short)msg[i] ) !=0 )
		{
			sbuf[j++] = bin2hex((byte)(u>>12));
			sbuf[j++] = bin2hex((byte)(u>>8));
			sbuf[j++] = bin2hex((byte)(u>>4));
			sbuf[j++] = bin2hex((byte)(u));
			i++;
		}

		System.out.println("d");

		i<<=1; 					// Length of message (UNICODE is twice longer)
		sbuf[n++]=bin2hex((byte)(i>>4));
		sbuf[n++]=bin2hex((byte)i);
		sbuf[j]=0x1A;				// End of pdu
		sbuf[j+1]=13;				// End of the string
		sbuf[j+2]=0;				// End of the string

		return ((j>>1)-1);			// Length of pdu for +CMGS command
	}

	/**
	 * Отправить SMS на заданный номер. Понимает русские SMS (можно
	 * писать в теле программы по-русски, Unicode)
	 * @param anum - номер, на который надо послать SMS 
	 * @param amsg
	 */	
	public void sendSMS(String anum, String amsg)
	{
		//String amsg = Translit(str);
		byte num[] = new byte[anum.length()+10];

		byte[] snum = anum.getBytes();
		char[] smsg = new char[amsg.length()+10];
		amsg.getChars(0, amsg.length(), smsg, 0);

		for(int i=0; i<anum.length(); i++)
			num[i] = snum[i];
		
		int len;
		len=create_pdu_mem(num,smsg);
		try 
		{
			//System.out.println("\n\r"+"sending "+"AT+CMGS="+len+"\r"+"\n\r");
			String strAnswer = atCommand.send("AT+CMGS="+len+"\r");
			if(strAnswer.indexOf((int)'>') > 0)
			{
				String strAT2 = new String(sbuf, 0, sbuf.length); //
				String strAnswer2 = atCommand.send(strAT2);
				if(strAnswer2.indexOf("OK")!= -1)
					{
					//System.out.println("\n\rShort message has been sent.\n\r");
					}
				else
				{
					//atCommand = new ATCommand(false);
					//System.out.println("\n\rShort message has NOT been sent (no OK found in reply).\n\r");
				}
			}
		} 
		catch (IllegalStateException e) 
		{
			System.out.println("IllegalStateException "+e.getMessage()+"\n\r");
		} 
		catch (IllegalArgumentException e) 
		{
			System.out.println("IllegalArgumentException "+e.getMessage()+"\n\r");
		} 
		catch (ATCommandFailedException e) 
		{
			System.out.println("ATCommandFailedException "+e.getMessage()+"\n\r");
		}
	}
	
	/**
	 * Вызывать эту функцию периодически, она будет спрашивать, есть ли
	 * новые СМС. Если есть - будет получать его и удалять из памяти.
	 * @return true если СМС есть.
	 */
	public boolean PollNewSMS()
	{
		return receiveSMS();
	}
	public String Translit(String text)
	{
		StringBuffer sb = new StringBuffer(text.length()+10);
		for(int i=0; i<text.length(); i++)
		{
			char c = text.charAt(i);
			switch(c)
			{
			case 'А': c = 'A';break; case 'а': c = 'a';break;
			case 'Б': c = 'B';break; case 'б': c = 'b';break;
			case 'В': c = 'V';break; case 'в': c = 'v';break;
			case 'Г': c = 'G';break; case 'г': c = 'g';break;
			case 'Д': c = 'D';break; case 'д': c = 'd';break;
			case 'Е': c = 'E';break; case 'е': c = 'e';break;
			case 'Ж': c = 'Z';break; case 'ж': c = 'z';break;
			case 'З': c = 'Z';break; case 'з': c = 'z';break;
			case 'И': c = 'I';break; case 'и': c = 'i';break;
			case 'Й': c = 'J';break; case 'й': c = 'j';break;
			case 'К': c = 'K';break; case 'к': c = 'k';break;
			case 'Л': c = 'L';break; case 'л': c = 'l';break;
			case 'М': c = 'M';break; case 'м': c = 'm';break;
			case 'Н': c = 'N';break; case 'н': c = 'n';break;
			case 'О': c = 'O';break; case 'о': c = 'o';break;
			case 'П': c = 'P';break; case 'п': c = 'p';break;
			case 'Р': c = 'R';break; case 'р': c = 'r';break;
			case 'С': c = 'S';break; case 'с': c = 's';break;
			case 'Т': c = 'T';break; case 'т': c = 't';break;
			case 'У': c = 'U';break; case 'у': c = 'u';break;
			case 'Ф': c = 'F';break; case 'ф': c = 'f';break;
			case 'Х': c = 'H';break; case 'х': c = 'h';break;
			case 'Ц': c = 'C';break; case 'ц': c = 'c';break;
			case 'Ч': c = 'H';break; case 'ч': c = 'h';break;
			case 'Ш': c = 'S';break; case 'ш': c = 's';break;
			case 'Щ': c = 'S';break; case 'щ': c = 's';break;
			case 'Ъ': c = '\'';break; case 'ъ': c = '\'';break;
			case 'Ы': c = 'Y';break; case 'ы': c = 'y';break;
			case 'Ь': c = '\'';break; case 'ь': c = '\'';break;
			case 'Э': c = 'E';break; case 'э': c = 'e';break;
			case 'Ю': c = 'U';break; case 'ю': c = 'u';break;
			case 'Я': c = 'A';break; case 'я': c = 'a';break;
			}
			sb.append(c);
		}
		return sb.toString();
	}
}

	
