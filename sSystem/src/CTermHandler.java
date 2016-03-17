package src;

import com.siemens.icm.io.ATCommand;


public class CTermHandler implements ISomeEventListener {
	final byte EV_TERM_PRG          = 2;
	final int  PH_DIRECT_PIN        = 0;
	final int  PH_INVERT_PIN        = 1;
	final byte PH_0_TO_1_EV         = 0;
	final byte PH_1_TO_0_EV         = 1;
	final byte PH_X_TO_X_EV         = 2;
	final int  PIN_INPUT            = 0;
	final int  PIN_OUTPT            = 1;	
	   private CIoHandler nPin;
	   private boolean blState;
       public CTermHandler(ATCommand aCommand,byte byPin)
       {
    	   blState = false;
    	   nPin = new CIoHandler(aCommand,(byte)3,(byte)3,(byte)2,(byte)byPin,(int)PH_DIRECT_PIN,(int)PIN_INPUT);
    	   nPin.SetEvent(this,(byte)EV_TERM_PRG);
    	   nPin.Enabled(true);
    	   System.out.println("CTermHandler::>Create");
       }
       public void eventHappens(CHMessage sMsg)
       {
    	   //System.out.println("CAlarmHandler::>eventHappens");
    	   switch(sMsg.m_sbyType){
    	    case EV_TERM_PRG:
    	    	 if (sMsg.m_sbyDirID==PH_0_TO_1_EV)
    	    	 {
    	    		  blState = true;
        	    	  System.out.println("CTermHandler::>EV_TERM_PRG. Module Must Be Terminated!");
    	    	 }       	    	 
    	    	 if (sMsg.m_sbyDirID==PH_1_TO_0_EV)
       	    	 {
    	    		  blState = false;
           	    	  System.out.println("CTermHandler::>EV_TERM_PRG. Module Must Be Runing!");
       	    	 };
    	    break;	
    	   }
       }
	   public int getID(){
		   return -1;
	   } 
       public void RunProc(){
       if (nPin!=null) nPin.Run();  
       }
       public boolean getState(){
    	   return blState;
       }
}
