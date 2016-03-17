//Ejemplo que muestra como configurar entradas y salidas GPIO mediante las
//clases InPOrt y OutPort

package src;


import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;

import com.siemens.icm.io.ATCommand;
import com.siemens.icm.misc.Watchdog;
import java.util.Vector;

import src.CLoopHandler;

public class CMain extends MIDlet {
	final int PIN_INPUT             = 0;
	final int PIN_OUTPT             = 1;	
	final int PH_DIRECT_PIN         = 0;
	final int PH_INVERT_PIN         = 1;
	private ATCommand atCommand,atSmsState,atScanState;
	private CAlarmThread tAlarm;
	private CConfigList nConfList;
	private CSmsSender nSms;
	private Vector vAdmins;
	private CTermHandler hTerm;
	
	protected void startApp() throws MIDletStateChangeException 
	{
		try{
 		  PrepareSystem();
		  CreateSystem();
		  int i=0,nGsmRest=0;
		  boolean blStation = false;
		  boolean blState=hTerm.getState(); 
		  //Watchdog.start(15);
          //Watchdog.kick();
		  while(blState==false)
		  {
			 blState = hTerm.getState(); 
			 if((i%10)==0) 
			 {
				 System.out.println("CMain::>a2000.Thread. Count:"+i+" Term State: "+blState+" GSM Station:"+blStation+" RST:"+nGsmRest+" of 3600. Alarm TC:"+tAlarm.getCount());
				 String strRes = scanGSM();
				 System.out.println("CMain::>Scan Station: "+strRes);
				 if (strRes.indexOf("+CREG: 0,1")>=0)
				 {
					 blStation = true;
					 nGsmRest = 0;
				 }	else
				 {
					 blStation = false;
					 nGsmRest++;
					 if (nGsmRest>3600) {restartModule();nGsmRest=0;}
				 }
			 }
			 i++;
			 Thread.sleep(1000);
			 //if (i>150) break;
		  };
		}
		catch (Exception e)
		{
			System.out.println("CMain::>Exception!!!");
		}
        
        //Fin del progama
        destroyApp(true);
	}
synchronized public String scanGSM(){
	try{
	 return atScanState.send("AT+CREG?\r");
	}
	catch (Exception e)
	{
		System.out.println("CMain::>Exception!!!");
	}
	return "";
}
synchronized public void restartModule(){
	try{
	 atScanState.send("AT+CFUN=1,1\r");
	}
	catch (Exception e)
	{
		System.out.println("CMain::>Exception!!!");
	}
}
public void PrepareSystem(){
	try{
	  atCommand   = new ATCommand(false);	
	  atSmsState  = new ATCommand(false);
	  atScanState = new ATCommand(false);
	  //atCommand.send("AT^SCFG=Userware/Stdout,ASC0\r");
	  atCommand.send("AT^SPIO=0\r");
	  atCommand.send("AT^SPIO=1\r");
	  System.out.println("Automation 2000 for TC65.Wait 20 сек");
	}catch(Exception e)
	{
		System.out.println("CMain::>PrepareSystem Exception!!! "+e.getMessage());
	}
}
public void CreateSystem(){
	nConfList = new CConfigList("file:///a:/msgbook.dat");
	nSms      = new CSmsSender(atSmsState);  
	nSms.init();
	tAlarm = new CAlarmThread(1000);
	for(int i=0;i<8;i++)
	{
		Vector pVec = new Vector();
		if (nConfList.GetLoops(i,pVec)==true)
		tAlarm.addObj(new CLoopHandler(atCommand,nSms,pVec));
	}
	vAdmins = new Vector();
	Vector pVec = new Vector();
	if(nConfList.GetAdmins(pVec)==true)
	{
	   for(int i=0;i<pVec.size();i++)
	   {
		CConfigItem pCI = (CConfigItem)pVec.elementAt(i);
		CLoopHandler pL = FindHandler(Integer.valueOf(pCI.strLoop).intValue());
		if (pL!=null)
	    vAdmins.addElement(new CAdmin(pCI,pL));else
	    	System.out.println("CMain::>CreateSystem Exception!!! CLoopHandler pL=null!");
	   }
	}
	hTerm  = new CTermHandler(atCommand,(byte)8);
	tAlarm.addObj(hTerm);
	tAlarm.addObj(new CSmsHandler(atSmsState,nSms,vAdmins));
	tAlarm.start();
	tAlarm.MyRessume();
}
private CLoopHandler FindHandler(int nID){
	Vector pV = tAlarm.getObjects(); 
	//System.out.println("("+nID+")FindHandler Size:"+pV.size());
	for(int i=0;i<pV.size();i++)
	{
		ISomeEventListener ifHdl;
		ifHdl=(ISomeEventListener)pV.elementAt(i);
   	    //System.out.println("("+nID+")FindHandler:instanceof CLoopHandler:"+ifHdl.getID());
		if ((ifHdl instanceof CLoopHandler)==true)
		if (nID==ifHdl.getID())
		return (CLoopHandler)ifHdl;
	}
	return null;
}

	
	
 
    
    
	protected void pauseApp()	{}
	

	
	protected void destroyApp(boolean arg0) throws MIDletStateChangeException 
	{
        notifyDestroyed();
	}
 
	
	
	
	
	
	
    
    
}
