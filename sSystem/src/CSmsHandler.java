package src;

import java.util.Vector;

import com.siemens.icm.io.ATCommand;
import com.siemens.icm.io.ATCommandFailedException;

public class CSmsHandler implements ISomeEventListener {
	   private ATAlarmListener atAlarmListener;
	   private ATCommand atCommand;
	   private long dwCount;
	   private CSmsSender sSms;
	   private Vector pVAdmins;
	   public CSmsHandler(ATCommand aCom,CSmsSender nSms,Vector pVAdmins){
		   atCommand = aCom;
		   sSms = nSms;
		   this.pVAdmins = pVAdmins;
           atAlarmListener = new ATAlarmListener();
           atCommand.addListener(atAlarmListener);
	   }
	   public void RunProc(){
	   if((dwCount++%2)==0) SMSParcer();
	   }
	         
	   private void SMSParcer(){
	   	   ProcessUnsolicitedEvents();
	   	   //System.out.println("CSmsHandler::>SMSParcer.");  
	   }
	   public int getID(){
		   return -1;
	   }      
	   void ProcessUnsolicitedEvents()
	   	{
	   	//rNew incoming SMS from 375291730879 at 11/09/14 11:01:49 GMT+3: Jgm
	   		if(atAlarmListener.hasNewEvent())
	   		{
	   			if(atAlarmListener.strATCommand.indexOf("RING") != -1)
	   			{
	   				//System.out.println("New event: incoming ring");			  
	   			}
	   			else if(atAlarmListener.strATCommand.indexOf("+CMTI:") != 0)
	   			{
	   				//int i = atAlarmListener.strATCommand.indexOf(",");
	   		        //String m_strSMSID = atAlarmListener.strATCommand.substring(i+1,atAlarmListener.strATCommand.length()-i);
	   			    //System.out.println("CSmsHandler::>MSG"+atAlarmListener.strATCommand+" I:"+i);
	   			    //System.out.println("CSmsHandler::>ID"+m_strSMSID);
	   		        //if m_strSMSID<>'' then SendCommand('AT+CMGR='+m_strSMSID);
	   				//AT+CMGD
	   				if(sSms.receiveSMS())
	   				{
	   					SendToAdmin(sSms);
	   					/*
	   					 System.out.println("rNew incoming SMS from " +
	   							sSms.pdu.smsSenderID +
	   							" at " + sSms.pdu.smsTime +
	   							": "+sSms.pdu.smsText);
	   					*/
		   				try{
		   					//at+cmgd=21
		   					String res = atCommand.send("AT+CMGD=1\r");	
		   					//System.out.println("CSmsHandler::>AT+CMGD=1 "+res);
		   				}catch (ATCommandFailedException e){
		   					System.out.println("CSmsHandler::>ATCommandFailedException!!!");
		   				}
		   				
	   				}
	   			}
	   			else
	   				System.out.println("New event (not processed): " + atAlarmListener.strATCommand);			  
	   		}
	   	}
	   private void SendToAdmin(CSmsSender sSms)
	   {
		   try{
		   for(int i=0;i<pVAdmins.size();i++)
		   {
			   CAdmin pA = (CAdmin)pVAdmins.elementAt(i);
			   //String str = sSms.Translit(sSms.pdu.smsText);
			   pA.EventHandler(sSms.pdu.smsSenderID,sSms.pdu.smsText);
		   }
		   }catch(Exception e){
			   System.out.println("CSmsHandler::>SendToAdmin.Exception!!! "+e.getMessage());   
		   }
	   }
	   public void eventHappens(CHMessage sMsg)
       {
       //
       }
}
