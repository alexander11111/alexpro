package src;

public class CPdu {

	// ��������� ��������������� ���
	boolean smsMultipartMsg = false;
	int smsSenderIDType = 0;
	String smsSenderID = new String(); 
	int smsProtocolIdentifier = 0;
	String smsTime = new String();
	String smsText = new String();
	
/*	
	private byte hex2bin(byte c)  
	{
		return (byte)( ((((c)&0x4F)&0x40)!=0) ? (((c)&0x4F)-0x37) : ((c)&0x4F) );
	}
	*/
/*
	private byte bin2hex(byte n)
	{
		n = (byte)(n & 0x0F); 
		if(n>9) 
			return (byte)(n-10+'A'); 
		else return (byte)(n+'0');
	}
*/

	public String ParsePDU(String pdu)
	{
//		byte[] arPDUBytes = pdu.getBytes();

		// ���������
		int idx = 0; // ������ � �������
		String sHex = pdu.substring(idx, idx+2); // 0: ����� ���������� �� SMSC
		int hex = Integer.parseInt(sHex, 16);
		int lenSMSC = hex*2; // 0+lenSMSC: ������������� ����� ���������� �� SMSC
		idx += lenSMSC + 2;
		sHex = pdu.substring(idx, idx+2); // ���� SMS-DELIVER CPdu
		hex = Integer.parseInt(sHex, 16);
//		SMSDeliver format
//		Bit no 7      6       5       4        3       2      1      0 
//		Name TP-RP TP-UDHI TP-SRI (unused) (unused) TP-MMS TP-MTI TP-MTI 
		int SMSDeliver = hex;
		if((SMSDeliver & 0x03) != 0) // ��� ���, ���� ���� 1 � 0 ����� 0
			return "(Not an SMS)";
		smsMultipartMsg = false;
		if((SMSDeliver & 0x4) == 0) // ��� ���, ���� ���� 1 � 0 ����� 0
			smsMultipartMsg = true;

		idx+=2;
		sHex = pdu.substring(idx, idx+2); // ����� ������ ��� ID �����������
		hex = Integer.parseInt(sHex, 16);
		int SenderIDLength = hex;
		
		idx+=2;
		sHex = pdu.substring(idx, idx+2); // ��� ID ����������� 
/*
Bit no         7        |      6 5 4       |          3 2 1 0 
Name   Always set to 1  |  Type-of-number  |   Numbering Plan Identification 

Note that bit no 7 should always be set to 1
Bits 6, 5 and 4 deonte the Type-of-number
Bits 3, 2, 1, 0 denote the Numbering-Plan-Identification 
*/		
		hex = Integer.parseInt(sHex, 16);
		smsSenderIDType = hex;
		StringBuffer SenderID = new StringBuffer(64);
		idx +=2;
		for(int i=0; i<SenderIDLength; i+=2) // ������ ������ ����� ��������, ��������� � ������� �������
		{
			char ch = pdu.charAt(idx+1); 
			if(( ch >= '0' && ch <= '9'))
				SenderID.append(pdu.charAt(idx+1));
			ch = pdu.charAt(idx);
			SenderID.append(ch);
			idx +=2;
		}
//		idx += (SenderIDLength + 1);

		smsSenderID = SenderID.toString();
		sHex = pdu.substring(idx, idx+2); // ������������� ���������
		hex = Integer.parseInt(sHex, 16);
		smsProtocolIdentifier = hex;

		idx+=2;
		sHex = pdu.substring(idx, idx+2); // ����� �����������
		hex = Integer.parseInt(sHex, 16);
		int DataCodingScheme = hex;
		//		boolean bRet = false;

		idx+=2;
		StringBuffer sbTime = new StringBuffer(20);
		// Time stamp (7 swapped-nibble semi-octets)
		//E.g.: 0x99 0x20 0x21 0x50 0x75 0x03 0x21 means 12. Feb 1999 05:57:30 GMT+3
		sbTime.append(pdu.charAt(idx+5)).append(pdu.charAt(idx+4)).append('/'); // Day
		smsTime = sbTime.toString();
		sbTime.append(pdu.charAt(idx+3)).append(pdu.charAt(idx+2)).append('/'); // Month
		smsTime = sbTime.toString();
		sbTime.append(pdu.charAt(idx+1)).append(pdu.charAt(idx)).append(' '); // Year
		smsTime = sbTime.toString();
		sbTime.append(pdu.charAt(idx+7)).append(pdu.charAt(idx+6)).append(':'); // Day
		smsTime = sbTime.toString();
		sbTime.append(pdu.charAt(idx+9)).append(pdu.charAt(idx+8)).append(':'); // Month
		smsTime = sbTime.toString();
		sbTime.append(pdu.charAt(idx+11)).append(pdu.charAt(idx+10)).append(' '); // Year
		smsTime = sbTime.toString();
		sbTime.append("GMT");
		//char arGMT[] = {pdu.charAt(idx+13), pdu.charAt(idx+12)};
		Character ch1 = new Character(pdu.charAt(idx+13));
		Character ch2 = new Character(pdu.charAt(idx+12));
		hex = Integer.parseInt(ch1.toString(), 16)*10 + Integer.parseInt(ch2.toString(), 16);
		if(hex>0)
			sbTime.append("+");
		sbTime.append(Integer.toString(hex/4));
		smsTime = sbTime.toString();

		idx += 14;
		sHex = pdu.substring(idx, idx+2); // ����� ������ ������������
		hex = Integer.parseInt(sHex, 16);
		int UserDataLength = hex; 
		idx +=2;
		
		StringBuffer sbText = new StringBuffer(160);
		
		if(DataCodingScheme == 0)  // GSM
		{
			int next = 0;
			int shift=0;
			int mask=0;
			
//			while(idx < pdu.length())
			while(sbText.length() < UserDataLength)
			{
				char ch;
				
				if(mask == 0x7f)
				{
					next &= mask;
					ch = (char)(next & 0x7f); // ����� ��������� 7-������ ������
					sbText.append(ch);
					shift = 0; mask = 0; next = 0;
				}
				
				if(idx+2 < pdu.length())
					sHex = pdu.substring(idx, idx+2);
				else // ����� ������
					sHex = pdu.substring(idx);
				
				hex = Integer.parseInt(sHex, 16);
				hex <<= shift;
				next &= mask;
				next |= hex;
				ch = (char)(next & 0x7f); // ����� ��������� 7-������ ������
				sbText.append(ch);
				next >>= 7;
				mask <<= 1; // �������� ����� 
				shift++;
				mask |= 1;
				idx+=2;
			}
		}
		if(DataCodingScheme == 4)  // ASCII
		{
			while(sbText.length() < UserDataLength && idx < pdu.length())
			{
				char NextCh;
				sHex = pdu.substring(idx, idx+2); // ����� ������ ������������
				hex = Integer.parseInt(sHex, 16);
				NextCh = (char)(hex); 
				sbText.append(NextCh);
				idx +=2;
			}
		}
		if(DataCodingScheme == 8)  // UCS2
		{
			while(sbText.length() < UserDataLength && idx < pdu.length())
			{
				char NextCh;
				sHex = pdu.substring(idx, idx+2); // ����� ������ ������������
				hex = Integer.parseInt(sHex, 16);
				NextCh = (char)(hex<<8); 
				idx +=2;
				sHex = pdu.substring(idx, idx+2); // ����� ������ ������������
				hex = Integer.parseInt(sHex, 16);
				NextCh |= (char)(hex&0xff); 
				sbText.append(NextCh);
				idx +=2;
			}
		}
		
		smsText = sbText.toString();
		return smsText;
	}

}
