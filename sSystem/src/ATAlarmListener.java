package src;

import com.siemens.icm.io.ATCommandListener;

/*
 * Класс для реакции на самопроизвольные АТ-команды, вываливающиеся
 * из модема (типа RING).
 */

public class ATAlarmListener implements ATCommandListener
{
	public String strATCommand;
	//Tc65SerialPort tc65SerialPort;
	boolean HasNewEvent = false;
	boolean ProcessIo = false;
	//Tc65Io tc65Io; // Вызывать при приходе текста об изменении состояния ноги
	
    public ATAlarmListener(){
    	HasNewEvent = false;
    	ProcessIo = false;   	
    }
	
	public boolean hasNewEvent()
	{
		//System.out.println("ATAlarmListener::>hasNewEvent.");  
		if(HasNewEvent)
		{
			HasNewEvent = false; // сбрасываем
			return true;
		}
		return false;
	}
	
	public void RINGChanged(boolean ring)
	{
	// Мы ничего не делаем, потому что нам это событие обраратывать не нужно.
	}
	
	public void ATEvent(String str)
	{
		//System.out.println("ATAlarmListener::>ATEvent."+str);  
		strATCommand = str;
		HasNewEvent = true;
	}
	
	public void CONNChanged(boolean ring)
	{
		// Мы ничего не делаем, потому что нам это событие обраратывать не нужно.
	}
	public void DSRChanged(boolean ring)
	{
		// Мы ничего не делаем, потому что нам это событие обраратывать не нужно.
	}
	public void DCDChanged(boolean ring)
	{
		// Мы ничего не делаем, потому что нам это событие обраратывать не нужно.
	}
}