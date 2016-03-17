package src;

import com.siemens.icm.io.ATCommand;
import src.CConfigItem;
import java.util.Vector;

public class CLoopHandler implements ISomeEventListener {
	   final byte EV_DOOR_OPEN          = 0;
	   final byte EV_DOOR_CLOSE         = 1;
	   final int  PH_DIRECT_PIN         = 0;
	   final int  PH_INVERT_PIN         = 1;
	   final byte PH_0_TO_1_EV          = 0;
	   final byte PH_1_TO_0_EV          = 1;
	   final byte PH_X_TO_X_EV          = 2;
	   final int  PIN_INPUT             = 0;
	   final int  PIN_OUTPT             = 1;	
	   private CSmsSender sSms;
	   private CIoHandler nPin;
	   private Vector pList;
	   private CConfigItem phI;
	   //private long dwCount = 0;
	   private int nID;
	   public CLoopHandler(ATCommand aCommand,CSmsSender Sms,Vector pList)
       {
    	   this.pList = pList;
    	   sSms = Sms;
    	   phI  = (CConfigItem)pList.elementAt(0);
    	   nID  = phI.getID();
    	   nPin = new CIoHandler(aCommand,(byte)phI.getOpenTime(),(byte)phI.getCloseTime(),(byte)2,(byte)phI.getPinID(),(int)PH_DIRECT_PIN,(int)PIN_INPUT);
    	   nPin.SetEvent(this,(byte)EV_DOOR_OPEN);
    	   nPin.Enabled(true);
    	   //System.out.println("("+nID+")CAlarmHandler::>Create");
    	   for(int i=1;i<pList.size();i++)
  		   {
	    	 phI = (CConfigItem)pList.elementAt(i);
    	     System.out.println("("+phI.strLoop+")CLoopHandler::>Create. :"+phI.strPhone+" OpenMsg:"+phI.strMsgOpen+" CloseMsg:"+phI.strMsgClose);
  		   }
       }
	   public void closeLoop(){
		   System.out.println("("+nID+")CLoopHandler::>closeLoop");
		   nPin.Lock();
	   }
	   public void openLoop(){
		   System.out.println("("+nID+")CLoopHandler::>openLoop");
		   nPin.UnLock();
	   }
	   public int getID(){
		   return nID;
	   }
       public void eventHappens(CHMessage sMsg)
       {
    	   //System.out.println("("+nID+")CLoopHandler::>eventHappens");
    	   switch(sMsg.m_sbyType){
    	    case EV_DOOR_OPEN:
    	    	 if (sMsg.m_sbyDirID==PH_0_TO_1_EV)
    	    	 {
    	    		 for(int i=1;i<pList.size();i++)
    	    		 {
        	    	  phI = (CConfigItem)pList.elementAt(i);
        	    	  sSms.sendSMS(phI.strPhone,phI.strMsgOpen);
        	    	  System.out.println("("+nID+")CLoopHandler::>EV_DOOR_OPEN. Send: msg: "+phI.strMsgOpen);
        	    	  //System.out.println("("+nID+")CLoopHandler::>EV_DOOR_OPEN. Send:"+phI.strPhone+" msg: "+phI.strMsgOpen);
    	    		 }
    	    	 }else
       	    	 if (sMsg.m_sbyDirID==PH_1_TO_0_EV)
       	    	 {
    	    		 for(int i=1;i<pList.size();i++)
    	    		 {
           	    	  phI = (CConfigItem)pList.elementAt(i);
           	    	  sSms.sendSMS(phI.strPhone,phI.strMsgClose);
           	    	  System.out.println("("+nID+")CLoopHandler::>EV_DOOR_CLOSE. Send: msg: "+phI.strMsgClose);
           	    	  //System.out.println("("+nID+")CLoopHandler::>EV_DOOR_CLOSE. Send:"+phI.strPhone+" msg: "+phI.strMsgClose);
    	    		 }
       	    	 };
    	    break;	
    	   }
       }
       public void RunProc(){
       if (nPin!=null) nPin.Run();  
        }
 }
