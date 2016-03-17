package src;

import com.siemens.icm.io.ATCommandListener;

/*
 * ����� ��� ������� �� ���������������� ��-�������, ��������������
 * �� ������ (���� RING).
 */

public class ATAlarmListener implements ATCommandListener
{
	public String strATCommand;
	//Tc65SerialPort tc65SerialPort;
	boolean HasNewEvent = false;
	boolean ProcessIo = false;
	//Tc65Io tc65Io; // �������� ��� ������� ������ �� ��������� ��������� ����
	
    public ATAlarmListener(){
    	HasNewEvent = false;
    	ProcessIo = false;   	
    }
	
	public boolean hasNewEvent()
	{
		//System.out.println("ATAlarmListener::>hasNewEvent.");  
		if(HasNewEvent)
		{
			HasNewEvent = false; // ����������
			return true;
		}
		return false;
	}
	
	public void RINGChanged(boolean ring)
	{
	// �� ������ �� ������, ������ ��� ��� ��� ������� ������������ �� �����.
	}
	
	public void ATEvent(String str)
	{
		//System.out.println("ATAlarmListener::>ATEvent."+str);  
		strATCommand = str;
		HasNewEvent = true;
	}
	
	public void CONNChanged(boolean ring)
	{
		// �� ������ �� ������, ������ ��� ��� ��� ������� ������������ �� �����.
	}
	public void DSRChanged(boolean ring)
	{
		// �� ������ �� ������, ������ ��� ��� ��� ������� ������������ �� �����.
	}
	public void DCDChanged(boolean ring)
	{
		// �� ������ �� ������, ������ ��� ��� ��� ������� ������������ �� �����.
	}
}