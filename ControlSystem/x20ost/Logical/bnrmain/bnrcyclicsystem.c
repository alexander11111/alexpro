/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrcyclicsystem.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
SINT *chProcState[] = 
{
	 "OFF",
 	 "ON"
};
DECLARE_TASKCHAIN(SkipCC)
{
    {EXIT_D}
};
DECLARE_STATE(BadStateCC)
{
    {EV_UNKNOWN_REQ, SkipCC}
};
DECLARE_STATELIST(StateListCC)
{
    {S_BAD, BadStateCC}
};
BOOL CCyclicSystem_SetState(This,TStateCode vNewState)
{
	 DECLARE_SINGLE_OPEN(CCyclicSystem)
     TStateList * pvList = pT->GetStateList(pC);
     pT->m_pvState = pvList[(INT16)vNewState].m_pvState;
     pT->m_vState  = vNewState;
	 //pT->v[STATE] = vNewState;
     return TRUE;
}
BOOL CCyclicSystem_HandleEvent(This,TEvent vEvent)
{
	 DECLARE_SINGLE_OPEN(CCyclicSystem)
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
BOOL CCyclicSystem_HandleTask(This,TTask* pvTask)
{   
	 DECLARE_SINGLE_OPEN(CCyclicSystem)
     return (*pvTask==EXIT_D)?TRUE:FALSE;
}
TStateList* CCyclicSystem_GetStateList(This)
{   
	 DECLARE_SINGLE_OPEN(CCyclicSystem)
     return (TStateList*)&StateListCC;
}
TStateCode CCyclicSystem_GetStateCode(This)
{   
	 DECLARE_SINGLE_OPEN(CCyclicSystem)
	 return pT->m_vState;
}
TState* CCyclicSystem_GetState(This)
{ 
	 DECLARE_SINGLE_OPEN(CCyclicSystem)
	 return pT->m_pvState;
}
void CCyclicSystem_SetMsgAuto(This,SMESSAGE *pMsg)
{
     DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 BYTE byEvent = pMsg->m_sbyType;
	 pT->HandleEvent(pT,byEvent);
}
void CCyclicSystem_SetAutoState(This,TStateCode vNewState)
{
     DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->SetState(pT,vNewState);
}
/////////////////////////////////////////////////////////////////
void CCyclicSystem_Create(This,SINT* chProcName,BYTE byStateProc,BYTE byPeriod)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->SetName(pT,chProcName);
	 pT->SetStateProc(pT,byStateProc);
	 pT->SetPeriod(pT,byPeriod);
	 pT->m_dwAmoutQuant = 0;
	 #ifdef DEB_CCyclicSystem
	 Info("\n(__)CYCLS::>Create Process::State:%s Period:%b Process:%s.",chProcState[byStateProc],&byPeriod,chProcName);
     #endif
}
void CCyclicSystem_CreateSuspend(This,SINT* chProcName,BYTE byPeriod)
{
	 //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->SetName(pT,chProcName);
	 pT->Stop(pT);
	 pT->SetPeriod(pT,byPeriod);
}
void CCyclicSystem_Start(This)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->SetStateProc(pT,DEV_CJOB_ST_RESM);
}
void CCyclicSystem_Stop(This)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->SetStateProc(pT,DEV_CJOB_ST_SUSP);
}
void CCyclicSystem_SetStateProc(This,BYTE byStateProc)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->m_byStateProc = byStateProc; 
}
void CCyclicSystem_SetPeriod(This,BYTE byPeriod)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->m_byPeriod = byPeriod;
}
BYTE CCyclicSystem_GetStateProc(This)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 return pT->m_byStateProc;
}
void CCyclicSystem_SetName(This,SINT* chProcName)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
     strcpy(pT->m_chProcName,chProcName);
}
void CCyclicSystem_SetBoxID(This,BYTE byID)
{
     //DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 DECLARE_SINGLE_OPEN(CCyclicSystem) 
	 pT->m_byBoxID = byID;
}
BOOL CCyclicSystem_GetMessage(This)
{
	BOOL res = TRUE;
	DECLARE_SINGLE_OPEN(CCyclicSystem) 
	if( pT->m_byBoxID!=0xff)
	//if( pT->m_byBoxID==7)
	if(FGET(pT->m_byBoxID,(BYTE*)&pT->m_nsMessage)!=0)
	pT->EventHandler(pC,&pT->m_nsMessage);
	return res;
}
BOOL CCyclicSystem_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CCyclicSystem) 
	return TRUE;
}
void CCyclicSystem_CyclicProc(This)
{
	//DECLARE_SINGLE_OPEN(CCyclicSystem) 
	DECLARE_SINGLE_OPEN(CCyclicSystem) 
}
void CCyclicSystem_SendMessageData(This,BYTE byBox,BYTE byFor,BYTE byType,PVOID pData,WORD wLen)
{
    DECLARE_SINGLE_OPEN(CCyclicSystem) 
	SMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9+wLen;
	m_sMsg.m_sbyFrom      = byFor;
	m_sMsg.m_sbyFor       = byFor;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = byType;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	memcpy(&m_sMsg.m_sbyInfo[0],pData,wLen);
	FPUT(byBox,(BYTE*)&m_sMsg);	
	return TRUE;
}
void CCyclicSystem_SendMessageData1(This,BYTE byBox,BYTE byFor,BYTE byType,SMESSAGE *pInMsg, PVOID pData,WORD wLen)
{
    DECLARE_SINGLE_OPEN(CCyclicSystem) 
	pInMsg->m_swLen        = 9+wLen;
	pInMsg->m_sbyFrom      = byFor;
	pInMsg->m_sbyFor       = byFor;
	pInMsg->m_sbyIntType   = 0;
	pInMsg->m_sbyServerID  = 0;
	pInMsg->m_sbyType      = byType;
	pInMsg->m_sbyDirection = 0;
	pInMsg->m_sbySensor    = 0;
	memcpy(&pInMsg->m_sbyInfo[0],pData,wLen);
	FPUT(byBox,(BYTE*)pInMsg);	
	return TRUE;
}
WORD CCyclicSystem_GetWordParam(This,BYTE *pbyParam,BYTE *pbyOut)
{
    DECLARE_SINGLE_OPEN(CCyclicSystem) 
    #ifndef WIN32 
	pbyOut[0] = pbyParam[1];
	pbyOut[1] = pbyParam[0];
    #else
	pbyOut[0] = pbyParam[0];
	pbyOut[1] = pbyParam[1];
    #endif 
	return (WORD)*((WORD*)pbyOut);
}
void CCyclicSystem_CCyclicSystem(This)
{
	DECLARE_SINGLE_OPEN(CCyclicSystem) 
	DECLARE_REGISTRATION(CCyclicSystem,SetBoxID)
	DECLARE_REGISTRATION(CCyclicSystem,CyclicProc)
	DECLARE_REGISTRATION(CCyclicSystem,Create)
	DECLARE_REGISTRATION(CCyclicSystem,CreateSuspend)
	DECLARE_REGISTRATION(CCyclicSystem,Start)
	DECLARE_REGISTRATION(CCyclicSystem,Stop)
	DECLARE_REGISTRATION(CCyclicSystem,SetStateProc)
	DECLARE_REGISTRATION(CCyclicSystem,SetPeriod)
	DECLARE_REGISTRATION(CCyclicSystem,GetStateProc)
	DECLARE_REGISTRATION(CCyclicSystem,SetName)
	DECLARE_REGISTRATION(CCyclicSystem,EventHandler)
	DECLARE_REGISTRATION(CCyclicSystem,GetMessage)
	
	DECLARE_REGISTRATION(CCyclicSystem,SetMsgAuto)
	DECLARE_REGISTRATION(CCyclicSystem,GetStateList)
	DECLARE_REGISTRATION(CCyclicSystem,HandleTask)
	DECLARE_REGISTRATION(CCyclicSystem,HandleEvent)
	DECLARE_REGISTRATION(CCyclicSystem,SetState)
	DECLARE_REGISTRATION(CCyclicSystem,GetStateCode)
	DECLARE_REGISTRATION(CCyclicSystem,GetState)
	DECLARE_REGISTRATION(CCyclicSystem,SendMessageData)
	DECLARE_REGISTRATION(CCyclicSystem,SendMessageData1)
	DECLARE_REGISTRATION(CCyclicSystem,GetWordParam)
	pT->m_byBoxID = 0xff;
    pT->m_pvState = BadStateCC;
    pT->m_vState  = S_BAD;
}
void CCyclicSystem_DCCyclicSystem(This)
{
	//DECLARE_SINGLE_OPEN(CCyclicSystem)
	DECLARE_SINGLE_OPEN(CCyclicSystem) 
}
//DECLARE_SINGLE_CREATE(CCyclicSystem)
DECLARE_SINGLE_CREATE(CCyclicSystem)

