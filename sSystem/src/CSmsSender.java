package src;

import com.siemens.icm.io.ATCommand;
import com.siemens.icm.io.ATCommandFailedException;

/**
 * ����� ��� �������� (� ����� - � ������) SMS, ������ ��� 
 * ���������, ��� � ��65 �� �������� WTK25, � ������� ��� ���
 * ��������� ����.
 * @author dvk
 *
 */

public class CSmsSender {
	private ATCommand atCommand;
	//private Tc65SerialPort tc65SerialPort;
	private byte sbuf[];
//	String smsReceivedText;
//	String smsReceivedFromNumber;
	
	// �����, �����������, ����� �������� ���������� ��������� ���
	public CPdu pdu;
	public CSerialPort pPort;
	public CSmsSender(ATCommand atCommand0)
	{
		try{
		//atCommand = new ATCommand(false);
		this.atCommand = atCommand0;
		//this.tc65SerialPort = tc65SerialPort;
		sbuf = new byte[512]; // � ������� 
		pdu = new CPdu();
		System.out.println("CSmsSender::>Create");
		}catch (Exception e)
		{
			System.out.println("CMain::>Exception!!!");
		}
	}
/**
 * ��������� ������ ��� �������� SMS, ����������� ���� ���
 * ��� ������� ���������.
 * @return true = ��.
 */	
	
	boolean init()
	{
		boolean bRet = true;
		
		// ����� ���� ������� � ����� ��������� ���-������
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
 * ������ ��������� ���������� SMS �������� at+cmgl=0
 * @return true ���� SMS ������
 */	
	public boolean receiveSMS()
	{
		boolean bRet = false;
		try 
		{
			String strReply = atCommand.send("AT+CMGL=0\r");
			int pos = strReply.indexOf("+CMGL:");
			boolean badFmt = true;
			if(strReply.length() < 30) // ������ �� - ��� ���������
				badFmt = false;
			else
			{
				if(pos != -1) // ���� PDU
				{
					pos++;
					// ���� Enter  � ������ +CMGL: xx,yy,zz
					pos = strReply.indexOf(0x0d, pos);
					if(pos != -1)
					{
						pos+=2;
						// ���� Enter ����� PDU
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
	 * ��������� SMS �� �������� �����. �������� ������� SMS (�����
	 * ������ � ���� ��������� ��-������, Unicode)
	 * @param anum - �����, �� ������� ���� ������� SMS 
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
	 * �������� ��� ������� ������������, ��� ����� ����������, ���� ��
	 * ����� ���. ���� ���� - ����� �������� ��� � ������� �� ������.
	 * @return true ���� ��� ����.
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
			case '�': c = 'A';break; case '�': c = 'a';break;
			case '�': c = 'B';break; case '�': c = 'b';break;
			case '�': c = 'V';break; case '�': c = 'v';break;
			case '�': c = 'G';break; case '�': c = 'g';break;
			case '�': c = 'D';break; case '�': c = 'd';break;
			case '�': c = 'E';break; case '�': c = 'e';break;
			case '�': c = 'Z';break; case '�': c = 'z';break;
			case '�': c = 'Z';break; case '�': c = 'z';break;
			case '�': c = 'I';break; case '�': c = 'i';break;
			case '�': c = 'J';break; case '�': c = 'j';break;
			case '�': c = 'K';break; case '�': c = 'k';break;
			case '�': c = 'L';break; case '�': c = 'l';break;
			case '�': c = 'M';break; case '�': c = 'm';break;
			case '�': c = 'N';break; case '�': c = 'n';break;
			case '�': c = 'O';break; case '�': c = 'o';break;
			case '�': c = 'P';break; case '�': c = 'p';break;
			case '�': c = 'R';break; case '�': c = 'r';break;
			case '�': c = 'S';break; case '�': c = 's';break;
			case '�': c = 'T';break; case '�': c = 't';break;
			case '�': c = 'U';break; case '�': c = 'u';break;
			case '�': c = 'F';break; case '�': c = 'f';break;
			case '�': c = 'H';break; case '�': c = 'h';break;
			case '�': c = 'C';break; case '�': c = 'c';break;
			case '�': c = 'H';break; case '�': c = 'h';break;
			case '�': c = 'S';break; case '�': c = 's';break;
			case '�': c = 'S';break; case '�': c = 's';break;
			case '�': c = '\'';break; case '�': c = '\'';break;
			case '�': c = 'Y';break; case '�': c = 'y';break;
			case '�': c = '\'';break; case '�': c = '\'';break;
			case '�': c = 'E';break; case '�': c = 'e';break;
			case '�': c = 'U';break; case '�': c = 'u';break;
			case '�': c = 'A';break; case '�': c = 'a';break;
			}
			sb.append(c);
		}
		return sb.toString();
	}
}

	
