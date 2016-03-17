/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrdevice.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
//#include "bnrmain.h"
//#ifdef WIN32
char *STTS1[]  =
{
    "EV_SET_HI",
	"EV_REM_HI",
	"EV_SET_LO",
	"EV_REM_LO",
	"EV_CHG_PR",
	"EV_0T1_CH",
	"EV_1T0_CH",
	"EV_SAL_CH",
	"EV_RAL_CH",
	"EV_0T1_ST",
	"EV_1T0_ST",
	"EV_INI_CH",
	"EV_ALP_CH",
	"EV_ALS_CH",
	"EV_DSC_CH",

};
//#endif
DECLARE_TASKCHAIN(SkipDV)
{
    {EXIT_D}
};
DECLARE_STATE(BadStateDV)
{
    {EV_UNKNOWN_REQ, SkipDV}
};
DECLARE_STATELIST(StateListDV)
{
    {S_BAD, BadStateDV}
};
BOOL CDevice_SetState(This,TStateCode vNewState)
{
	 DECLARE_SINGLE_OPEN(CDevice)
     TStateList * pvList = pT->GetStateList(pC);
     pT->m_pvState = pvList[(INT16)vNewState].m_pvState;
     pT->m_vState  = vNewState;
	 //pT->v[STATE] = vNewState;
     return TRUE;
}
BOOL CDevice_HandleEvent(This,TEvent vEvent)
{
	 DECLARE_SINGLE_OPEN(CDevice)
	 TState* pvState;
     for(pvState=pT->m_pvState; pvState->m_vEvent!=EV_UNKNOWN_REQ; pvState++)
	 {
        if(pvState->m_vEvent==vEvent)
        {
            return pT->HandleTask(pC,pvState->m_pvTask);
        }
	 }
     return FALSE;
}
BOOL CDevice_HandleTask(This,TTask* pvTask)
{   
	 DECLARE_SINGLE_OPEN(CDevice)
     return (*pvTask==EXIT_D)?TRUE:FALSE;
}
TStateList* CDevice_GetStateList(This)
{   
	 DECLARE_SINGLE_OPEN(CDevice)
     return (TStateList*)&StateListDV;
}
TStateCode CDevice_GetStateCode(This)
{   
	 DECLARE_SINGLE_OPEN(CDevice)
	 return pT->m_vState;
}
TState* CDevice_GetState(This)
{ 
	 DECLARE_SINGLE_OPEN(CDevice)
	 return pT->m_pvState;
}
void CDevice_SetMsgAuto(This,SMESSAGE *pMsg)
{
     DECLARE_SINGLE_OPEN(CDevice) 
	 BYTE byEvent = pMsg->m_sbyType;
	 pT->HandleEvent(pT,byEvent);
}
void CDevice_SetAutoState(This,TStateCode vNewState)
{
     DECLARE_SINGLE_OPEN(CDevice) 
	 pT->SetState(pT,vNewState);
}
/////////////////////////////////////////////////////////////////
BYTE byIDD;
void CDevice_Init(This,PVOID *psTable)
{
    DECLARE_SINGLE_OPEN(CDevice)  
    //pT->pP       = psTable;
	//pT->m_byType = ((STKPARAM*)psTable)->byType;
	//pT->m_byID   = ((STKPARAM*)psTable)->byID;
	//pT->m_byIID  = ((STKPARAM*)psTable)->byAmParam;
	
	//pT->m_blSetAlarm = FALSE;
	//pT->m_byOldEvent = 0xff;
	pT->InitTCHN(pC,psTable);
}
void CDevice_Switch(This)
{
   DECLARE_SINGLE_OPEN(CDevice) 
}
void CDevice_InitTCHN(This,SSWITCHTABLE *psTable){}
void CDevice_PreProc(This){}
void CDevice_Processing(This){}
void CDevice_PostProc(This){}
void CDevice_ObserveProc(This)
{
     DECLARE_SINGLE_OPEN(CDevice) 
	 pT->PreProc(pC);
	 pT->Processing(pC);
	 pT->PostProc(pC);
     //if(++pT->m_byALC%20==0) pT->CheckAlarm(pT);
}
void CDevice_CheckAlarm(This)
{
     DECLARE_SINGLE_OPEN(CDevice) 
}
BOOL CDevice_SEventHandler(This,SMESSAGE *pMsg)
{
	 DECLARE_SINGLE_OPEN(CDevice) 
     switch(pMsg->m_sbyFor)
	 {
	  case DIR_MSTODV:
		   if (pMsg->m_sbyType==PL_DATA_IND)
		   {
            pT->ExtractCMD(pT,pMsg);
			pT->EventHandler(pC,pMsg);
		   }
	  break;
	  default:
	  break;
	 }	 	 
	 return TRUE;
}
/*
{
    CDataCommand = packed record
     wDeviceID : Word;
     byParam0  : Byte;
     byParam1  : Byte;
     byParam2  : Byte;
     wParam0   : Word;
     wParam1   : Word;
     wParam2   : Word;
     fParam0   : Single;
     fParam1   : Single;
     fParam2   : Single;
    End;
}
*/
BOOL CDevice_ExtractCMD(This,SMESSAGE *pMsg)
{
	 DECLARE_SINGLE_OPEN(CDevice) 
	 CDataCommand *pCD;
	 pCD = &pT->m_nCD;
	 memset(pCD,0,11);pCD->fParam0 = pCD->fParam1 = pCD->fParam2 = 0;
 	 pT->GetWordParam(pT,&pMsg->m_sbyInfo[0],(BYTE*)&pCD->wDeviceID);
	 pCD->byParam0 = pMsg->m_sbyInfo[2];
	 pCD->byParam1 = pMsg->m_sbyInfo[3];
	 pCD->byParam2 = pMsg->m_sbyInfo[4];
	 pT->GetWordParam(pT,&pMsg->m_sbyInfo[5],(BYTE*)&pCD->wParam0);
	 pT->GetWordParam(pT,&pMsg->m_sbyInfo[7],(BYTE*)&pCD->wParam1);
	 pT->GetWordParam(pT,&pMsg->m_sbyInfo[9],(BYTE*)&pCD->wParam2);
	 pT->GetRealParam(pT,&pMsg->m_sbyInfo[11],(BYTE*)&pCD->fParam0);
	 pT->GetRealParam(pT,&pMsg->m_sbyInfo[15],(BYTE*)&pCD->fParam1);
	 pT->GetRealParam(pT,&pMsg->m_sbyInfo[19],(BYTE*)&pCD->fParam2);
     return TRUE;
}
BOOL CDevice_EventHandler(This,SMESSAGE *pMsg)
{
	 DECLARE_SINGLE_OPEN(CDevice) 
	 return TRUE;
}
BOOL CDevice_SaveChange(This,BYTE byEvent,WORD wValue,BOOL blAlarm)
{
    DECLARE_SINGLE_OPEN(CDevice)  
}
BOOL CDevice_SavePinState(This,BYTE byEvent,WORD wValue)
{
    DECLARE_SINGLE_OPEN(CDevice)  
}
void CDevice_SendSMessage(This,BYTE byBox,BYTE byFor,BYTE byType)
{
    DECLARE_SINGLE_OPEN(CDevice)
    SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = byFor;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = byType;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(byBox,(BYTE*)&m_sMsg);	
    #ifdef DEB_CDevice
	Info("\n(__)CTLSN::>OUTT::%M",&m_sMsg);
    #endif
}
void CDevice_SendBroadcast(This,SKPEVENT *pEV)
{
}
void CDevice_SetInPinEvent(This)
{
    DECLARE_SINGLE_OPEN(CDevice) 
}
void CDevice_SaveAlarmPin(This)
{
    DECLARE_SINGLE_OPEN(CDevice) 
}
void CDevice_SendObsrveMsg(This)
{
    DECLARE_SINGLE_OPEN(CDevice) 
}
PVOID CDevice_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_SINGLE_OPEN(CDevice) 
}
WORD CDevice_GetWordParam(This,BYTE *pbyParam,BYTE *pbyOut)
{
    DECLARE_SINGLE_OPEN(CDevice) 
	WORD wRes;
	#ifndef WIN32 
	pbyOut[0] = pbyParam[1];
	pbyOut[1] = pbyParam[0];
    #else
	pbyOut[0] = pbyParam[0];
	pbyOut[1] = pbyParam[1];
    #endif 
	memcpy(&wRes,&pbyOut[0],2);
	return wRes;
	//return (WORD)*((WORD*)pbyOut);
}
UDINT CDevice_GetDWordParam(This,BYTE *pbyParam,BYTE *pbyOut)
{
    DECLARE_SINGLE_OPEN(CDevice) 
	DWORD wRes;
    #ifndef WIN32
	 pbyOut[3] = pbyParam[0];
	 pbyOut[2] = pbyParam[1];
	 pbyOut[1] = pbyParam[2];
	 pbyOut[0] = pbyParam[3];
    #else
	 memcpy(pbyOut,pbyParam,4);
    #endif
	memcpy(&wRes,&pbyOut[0],4);
	return wRes;
	//return (DWORD)*((DWORD*)pbyOut);
}
REAL CDevice_GetRealParam(This,BYTE *pbyParam,BYTE *pbyOut)
{
    DECLARE_SINGLE_OPEN(CDevice) 
	REAL wRes;
    #ifndef WIN32
	pbyOut[3] = pbyParam[0];
	pbyOut[2] = pbyParam[1];
	pbyOut[1] = pbyParam[2];
	pbyOut[0] = pbyParam[3];
    #else    		
	memcpy(pbyOut,pbyParam,4);
	#endif    		
	memcpy(&wRes,&pbyOut[0],4);
	return wRes;
	//return (REAL)*((REAL*)pbyOut);
}
void CDevice_CDevice(This)
{
     DECLARE_SINGLE_OPEN(CDevice) 
	 DECLARE_REGISTRATION(CDevice,Init)
	 //DECLARE_REGISTRATION(CDevice,GetW)
	 DECLARE_REGISTRATION(CDevice,SendSMessage)
	 DECLARE_REGISTRATION(CDevice,ObserveProc)
	 DECLARE_REGISTRATION(CDevice,PreProc)
	 DECLARE_REGISTRATION(CDevice,Processing)
	 DECLARE_REGISTRATION(CDevice,PostProc)
	 DECLARE_REGISTRATION(CDevice,SEventHandler)
	 DECLARE_REGISTRATION(CDevice,EventHandler)
	 DECLARE_REGISTRATION(CDevice,SaveChange)
	 DECLARE_REGISTRATION(CDevice,SavePinState)
	 DECLARE_REGISTRATION(CDevice,SendBroadcast)
	 DECLARE_REGISTRATION(CDevice,CheckAlarm)
	 DECLARE_REGISTRATION(CDevice,Switch)
	 DECLARE_REGISTRATION(CDevice,SetInPinEvent)
	 DECLARE_REGISTRATION(CDevice,SaveAlarmPin)
	 DECLARE_REGISTRATION(CDevice,SendObsrveMsg)
	 //DECLARE_REGISTRATION(CDevice,GetData)
	 DECLARE_REGISTRATION(CDevice,GetDWordParam)
	 DECLARE_REGISTRATION(CDevice,GetWordParam)
	 DECLARE_REGISTRATION(CDevice,GetRealParam)
	 DECLARE_REGISTRATION(CDevice,ExtractCMD)
	 /////////////////////////
	 DECLARE_REGISTRATION(CDevice,SetMsgAuto)
	 DECLARE_REGISTRATION(CDevice,GetStateList)
	 DECLARE_REGISTRATION(CDevice,HandleTask)
	 DECLARE_REGISTRATION(CDevice,HandleEvent)
	 DECLARE_REGISTRATION(CDevice,SetState)
	 DECLARE_REGISTRATION(CDevice,GetStateCode)
	 DECLARE_REGISTRATION(CDevice,GetState)
}
void CDevice_DCDevice(This)
{
	 DECLARE_SINGLE_OPEN(CDevice)
}
DECLARE_SINGLE_CREATE(CDevice)

