package src;

import java.io.IOException;
import java.util.Vector;

import com.siemens.icm.io.ATCommand;
import com.siemens.icm.io.ATCommandFailedException;
import com.siemens.icm.io.InPort;
import com.siemens.icm.io.OutPort;

public class CIoHandler {
	//final int PH_BASE_ADDR_SET_PORT = 0x98;
	//final int PH_BASE_ADDR_PIN_PORT = 0x78;
	final int PH_DIRECT_PIN         = 0;
	final int PH_INVERT_PIN         = 1;
	final byte PH_0_TO_1_EV          = 0;
	final byte PH_1_TO_0_EV          = 1;
	final byte PH_X_TO_X_EV          = 2;
	final int PH_NULL_EV            = 3;
	final int PIN_STATE_ONN         = 0;
	final int PIN_STATE_OFF         = 1;
	final int PIN_STATE_TRI         = 2;
	final int PIN_INPUT             = 0;
	final int PIN_OUTPT             = 1;
	private boolean m_blEnable;
	private boolean m_blInEnable;
	private boolean m_blOutEnable;

	private boolean m_blPinON;
	private boolean m_blPinOFF;

	private boolean m_blTmSetState;
	private boolean m_blTmRemState;
	private boolean m_byStPulce;
	private boolean m_blLockState;
	private byte m_byInPort;

	private short m_wAddr;
	private short m_wProgAddr;
	private byte m_byCSetPulce;
	private byte m_byCRemPulce;
	private byte m_bySetPulce;
	private byte m_byRemPulce;
	private byte m_byPulceTact;
	private byte m_byPin;
	private byte m_byLPin;
	private byte m_byPinType;
	private byte m_byDirPin;

	private int m_nBox;
	private byte m_byFor;
	private byte m_byPinEvent;
	private byte m_byLastEvent;
	private byte m_byEvent;
	private long m_dwCount;
	private ATCommand atCommand;
	private CHMessage m_sMsg;
	private Vector someEventListeners; 
	public CSerialPort pPort;
	private String[] sState={"PH_0_TO_1_EV","PH_1_TO_0_EV","PH_X_TO_X_EV",};
	public CIoHandler(ATCommand aCommand,byte byCSetPulce,byte byCRemPulce,byte byPulceTact,byte byPin)
    {
		System.out.println("("+m_byPin+")CIoHandler::>Create4");
    }
    public CIoHandler(ATCommand aCommand,byte byCSetPulce,byte byCRemPulce,byte byPulceTact,byte byPin,int byPinType,int byDirPin)
    {
    	try{
    	 m_sMsg         = new CHMessage();
    	 someEventListeners = new Vector();
    	 m_blLockState  = false;
         atCommand      = aCommand;
         m_byCSetPulce  = byCSetPulce;
         m_byCRemPulce  = byCRemPulce;
         m_byPulceTact  = byPulceTact;
         m_byPin        = byPin;
         m_byPinType    = (byte)byPinType;
         m_byDirPin     = (byte)byDirPin;
         
         m_blPinON      = false;
         m_blPinOFF     = false;
         m_bySetPulce   = 0;
         m_byRemPulce   = 0;
         m_blTmSetState = false;
         m_blTmRemState = false;
         m_byStPulce    = false;
         m_byInPort     = 0;
         
         //OpenIO();
         SetProgPin(m_byDirPin);
         m_byPinEvent   = GetTrueState();
         
         m_byLastEvent  = m_byPinEvent;
         Enabled(false);
         System.out.println("("+m_byPin+")CIoHandler::>Create.Last EV:"+sState[m_byLastEvent]);
    	}catch(Exception e)
    	{
    		System.out.println("("+m_byPin+")CIoHandler::>Error Create!!!");
    	}
    };
public void OpenIO(){

     sendAT("AT^SPIO=0");
     sendAT("AT^SPIO=1"); // ¬ключить порт I/O
}
private void SetAddrVal(short wAddr,byte byParam)
{
     m_wAddr = wAddr;
     m_byLPin= byParam;
};
private boolean EventHandler(/*var pMsg:CMessage*/)
{
	return true;
};
private void ProcInPulce()
{
     byte byState;
     if (m_blInEnable==true) 
     {
      byState = GetPinState();
      if(byState==PIN_STATE_ONN)  { m_blTmSetState = true;m_blTmRemState = false;m_bySetPulce = m_byCSetPulce;};
      if(byState==PIN_STATE_OFF)  { m_blTmRemState = true;m_blTmSetState = false;m_byRemPulce = m_byCRemPulce;};
      PostInProc();
     };
};
private byte CheckPinState()
{
      byte byState;
      byte Result;
      byState = GetPinState();
      Result  = PH_X_TO_X_EV;
      if(byState==PIN_STATE_ONN) 
      {
       if (m_byPinType==PH_DIRECT_PIN)  Result = PH_0_TO_1_EV; else
       if (m_byPinType==PH_INVERT_PIN)  Result = PH_1_TO_0_EV;
      } else
      if(byState==PIN_STATE_OFF) 
      {
       if (m_byPinType==PH_DIRECT_PIN)  Result = PH_1_TO_0_EV; else
       if (m_byPinType==PH_INVERT_PIN)  Result = PH_0_TO_1_EV;
      };
      return  Result;
};
private void PostInProc()
{
     //Set
	if (m_blTmSetState==true) 
    {
     if (m_bySetPulce==0) 
     {
      m_blTmSetState = false;
      SaveChange(PH_0_TO_1_EV);
     };
     m_bySetPulce--;
    };
    //Rem
    if (m_blTmRemState==true) 
    {
     if (m_byRemPulce==0) 
     {
      m_blTmRemState = false;
      SaveChange(PH_1_TO_0_EV);
     };
     m_byRemPulce--;
    };

};
public void SetEvent(ISomeEventListener listener,byte byEvent)
{
     m_nBox         = 0;
     m_byFor        = 0;
     m_byPinEvent   = CheckPinState();
     m_byEvent      = byEvent;
     m_blPinON      = false;
     m_blPinOFF     = false;
     m_bySetPulce   = 0;
     m_byRemPulce   = 0;
     m_blTmSetState = false;
     m_blTmRemState = false;
     m_byStPulce    = false;
     m_byLastEvent  = m_byPinEvent;
     addEventListener(listener);
};
//AT^SCPIN=<mode>, <pin_id>, <direction>
public void Lock(){
	m_blLockState = true;
}
public void UnLock(){
	m_blLockState = false;
}
private void SetProgPin(byte byDirPin)
{
      if (m_byDirPin==PIN_INPUT)
      {
    	sendAT("AT^SCPIN=0,"+m_byPin+",0,0"); // ¬кл. GPIO1, out, init_state=0 
    	sendAT("AT^SCPIN=1,"+m_byPin+",0,0"); // ¬кл. GPIO1, out, init_state=0 
      }else
      if (m_byDirPin==PIN_OUTPT)
      {
    	sendAT("AT^SCPIN=0,"+m_byPin+",1,0"); // ¬кл. GPIO1, out, init_state=0 
    	sendAT("AT^SCPIN=1,"+m_byPin+",1,0"); // ¬кл. GPIO1, out, init_state=0 
      }
};
private void SetPulce()
{
     if(m_blOutEnable==true) 
     {
      m_bySetPulce = m_byPulceTact;
      m_byStPulce  = true;
      SetPin();
      if (m_byPinType==PH_DIRECT_PIN)  SaveChange(PH_0_TO_1_EV);
      if (m_byPinType==PH_INVERT_PIN)  SaveChange(PH_1_TO_0_EV);
     };
};
private void SetPinState(byte byPinEvent)
{
     if(m_blOutEnable==true) 
     {
      if (byPinEvent==PH_0_TO_1_EV) 
      {
       SetPin();
       if (m_byPinType==PH_DIRECT_PIN)  SaveChange(PH_0_TO_1_EV);
       if (m_byPinType==PH_INVERT_PIN)  SaveChange(PH_1_TO_0_EV);
      } else
      if (byPinEvent==PH_1_TO_0_EV) 
      {
       RemPin();
       if (m_byPinType==PH_DIRECT_PIN)  SaveChange(PH_1_TO_0_EV);
       if (m_byPinType==PH_INVERT_PIN)  SaveChange(PH_0_TO_1_EV);
      };
     };
};
private void ProcOutPulce()
{
     if (m_blOutEnable==true) 
     {
      if(m_byStPulce==true) 
      {
       if (m_bySetPulce==0) 
       {
        m_byStPulce = false;
        RemPin();
        if (m_byPinType==PH_DIRECT_PIN)  SaveChange(PH_1_TO_0_EV);
        if (m_byPinType==PH_INVERT_PIN)  SaveChange(PH_0_TO_1_EV);
       };
       m_bySetPulce--;
      };
     };
};
public void Enabled(boolean blState)
{
     m_blEnable    = blState;
     m_blInEnable  = false;
     m_blOutEnable = false;
     if (m_byDirPin==PIN_INPUT)  m_blInEnable  = blState;
     if (m_byDirPin==PIN_OUTPT)  m_blOutEnable = blState;
     //atCommand.send("AT^SPIO=0\r"); // ¬ыключить порт I/O
};
private void DoAction()
{
     m_sMsg.m_swLen        = 11;
     m_sMsg.m_sbyFrom      = m_byFor;
     m_sMsg.m_sbyFor       = m_byFor;
     m_sMsg.m_sbyTypeIntID = m_byDirPin;
     m_sMsg.m_sbyServerID  = 0;
     m_sMsg.m_sbyDirID     = m_byPinEvent;
     m_sMsg.m_swObjID      = m_byPin;
     m_sMsg.m_sbyType      = m_byEvent;
     //System.out.println("\n\r("+m_byPin+")CIoHandler::>DoAction. PinEvent:"+m_byPinEvent);
     if(m_blLockState==false)
     riseSomeEvent();
     //if (m_nCheckPins==1) FPUT(m_nBox,@m_sMsg);
};
private void SaveChange(byte byPinEvent)
{
	 //System.out.println("\n\r("+m_byPin+")CIoHandler::>SaveChange:"+sState[m_byLastEvent]+"->"+sState[byPinEvent]);
     if (byPinEvent!=m_byLastEvent) 
     {
      m_byPinEvent  = byPinEvent;
      DoAction();
      m_byLastEvent = m_byPinEvent;
     };
};
private byte GetPinState()
{
     boolean blValue;
     byte Result = PIN_STATE_TRI;
     blValue = GetPin();
     //System.out.println("\n\r("+m_byPin+")CIoHandler::>GetPinState:m_blPinON:"+m_blPinON+" blValue:"+blValue+" m_blPinOFF:"+m_blPinOFF);
     if (blValue==true) 
     {
      if (m_blPinON==false) 
      {
       m_blPinON  = true;
       m_blPinOFF = false;
       //System.out.println("\n\r("+m_byPin+")CIoHandler::>GetPinState:m_blPinON:"+m_blPinON+" blValue:"+blValue+" m_blPinOFF:"+m_blPinOFF+" pinState:PIN_STATE_ONN");
       Result = PIN_STATE_ONN;
      }
     };
     if (blValue==false) 
     {
      if (m_blPinOFF==false) 
      {
       m_blPinOFF = true;
       m_blPinON  = false;
       //System.out.println("\n\r("+m_byPin+")CIoHandler::>GetPinState:m_blPinON:"+m_blPinON+" blValue:"+blValue+" m_blPinOFF:"+m_blPinOFF+" pinState:PIN_STATE_OFF");
       Result = PIN_STATE_OFF;
      }
     };
     return Result; 
};
private byte GetTrueState(){
	if (GetPin()==false){
		 if (m_byPinType==PH_DIRECT_PIN)  return (byte)PH_1_TO_0_EV;
	     if (m_byPinType==PH_INVERT_PIN)  return (byte)PH_0_TO_1_EV;
     }else{
		 if (m_byPinType==PH_DIRECT_PIN)  return (byte)PH_0_TO_1_EV;
	     if (m_byPinType==PH_INVERT_PIN)  return (byte)PH_1_TO_0_EV;
     }
	return 0;
}
private boolean GetPin()
{
	 boolean res = InP();
     //System.out.println("("+m_byPin+")CIoHandler::>GetPin="+res);
     return res;
};
public void SetPin()
{
     if (m_byPinType==PH_INVERT_PIN)  OutP(0); else
     if (m_byPinType==PH_DIRECT_PIN)  OutP(1);
};
private void RemPin()
{
     if (m_byPinType==PH_INVERT_PIN)  OutP(1); else
     if (m_byPinType==PH_DIRECT_PIN)  OutP(0);
};
private boolean OutP(int byParam)
{
	String respuestaAT; 
	respuestaAT=sendAT("at^ssio=" + m_byPin + "," + byParam);
	if (respuestaAT.indexOf("^SGIO: 1")>0)
		return true;
	else
		return false;
}    
private boolean InP()
{
	String respuestaAT; 
	respuestaAT=sendAT("at^sgio=" + m_byPin);
	//System.out.println("\n\r("+m_byPin+")CIoHandler::>InP.Seng:at^sgio=" + m_byPin+" Get: "+respuestaAT);
	if (respuestaAT.indexOf("^SGIO: 1")>0)
		return true;
	else
		return false;
};

private String sendAT(String str) 
{
	String strIN=str;
    try 
    {
        str = atCommand.send(str + "\r".toUpperCase());
    } 
    catch (Exception e) 
    {
    }
    //System.out.println("("+m_byPin+")CIOHandler::>sendAT :"+ strIN+" Out:"+str);
    return str;
}	

public void addEventListener(ISomeEventListener listener)
{
   someEventListeners.addElement(listener);
}

private void riseSomeEvent()
{
   for(int i = 0; i < someEventListeners.size(); i++)
   { 
      ((ISomeEventListener)someEventListeners.elementAt(i)).eventHappens(m_sMsg);
   }
}
public void Run()
{
     if (m_blEnable==true) 
     {
      ProcOutPulce();
      ProcInPulce();
     };
};


}
