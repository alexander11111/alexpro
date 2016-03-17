/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrdevts.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CDevTS_Init(This,CPin *pPN,BOOL *pTlValue,BYTE byID,BYTE byIID,BYTE byState,BYTE byPriority,BYTE byCRemPulce,BYTE byCSetPulce,BYTE byAlarmMode)
{
    DECLARE_SINGLE_OPEN(CDevTS)
	//memcpy(pTU,&pT->pP,sizeof(STUMPARAM));
	pT->m_pPN          = pPN;
	pT->pP.byID        = byID;
	pT->pP.byAmParam   = byIID;
    pT->pP.byState     = byState;  
    pT->pP.byPriority  = byPriority;  
    pT->pP.byCRemPulce = byCRemPulce;  
	pT->pP.byCSetPulce = byCSetPulce;  
	pT->pP.byAlarmMode = byAlarmMode;  
	
	pT->m_blTmSetState = FALSE;   
	pT->m_blTmRemState = FALSE;   
	pT->m_byType       = REG_SOFTS_ADDR;
	pT->m_blFSignal    = FALSE;

	pT->m_pTIN         = pTlValue;
	pT->m_byID         = pT->pP.byID;
    pT->m_byPinID      = pT->pP.byAmParam;
	pT->m_byOldEvent   = 0xff;
}
void CDevTS_SetTS(This,BYTE byBox,BYTE byFor,BYTE byEv)
{
    DECLARE_SINGLE_OPEN(CDevTS)
	pT->m_byBox  = byBox;
	pT->m_byFor  = byFor;
	pT->m_byEv   = byEv;
}
void CDevTS_PreProc(This)
{
    DECLARE_SINGLE_OPEN(CDevTS)
}
_GLOBAL INT nTSCH;
void CDevTS_Processing(This)
{
	DECLARE_SINGLE_OPEN(CDevTS)
	BYTE byState;
	if (pT->m_byID==40)	nTSCH++;
	if (pT->pP.byState==EN_OPEN) 
	{
	 byState = pT->CheckTS(pT);
	 if(byState==PIN_STATE_ONN)
	 {
		 pT->m_blTmSetState = TRUE;pT->m_blTmRemState = FALSE;pT->m_bySetPulce = pT->pP.byCSetPulce;}
	 if(byState==PIN_STATE_OFF)
	 {
		 pT->m_blTmRemState = TRUE;pT->m_blTmSetState = FALSE;pT->m_byRemPulce = pT->pP.byCRemPulce;}
	 pT->pP.sDT.byParam = *pT->m_pTIN;
	}
}
void CDevTS_PostProc(This)
{
	DECLARE_SINGLE_OPEN(CDevTS)
	BOOL res = FALSE;
	//Set Timer
	if (pT->pP.byState==EN_OPEN) 
	{
	if(pT->m_blTmSetState==TRUE)
	{
	 if (--pT->m_bySetPulce==0)
	 {
	  if((pT->pP.byPriority==PRI_HI)&&((pT->pP.byAlarmMode==EN_AL_TO_AL)||(pT->pP.byAlarmMode==EN_LO_TO_HI))) res = TRUE;
	  pT->SaveChange(pT,EV_0T1_CH,1,res);
	  pT->m_blTmSetState = FALSE;
	 }
	}
    //Rem Timer
	if(pT->m_blTmRemState==TRUE)
	{
	 if (--pT->m_byRemPulce==0)
	 {
	  if((pT->pP.byPriority==PRI_HI)&&((pT->pP.byAlarmMode==EN_AL_TO_AL)||(pT->pP.byAlarmMode==EN_HI_TO_LO))) res = TRUE;
	  if( pT->m_blFSignal)pT->SaveChange(pT,EV_1T0_CH,0,res);
	  pT->m_blTmRemState = FALSE;
	  pT->m_blFSignal = TRUE;
	 }
	}
	}
}
/*
typedef struct _tagKpEvent
{
WORD wLen;
BYTE byType;
BYTE byAddr;
BYTE byCause;
WORD wValue;
STIME sTime;
}SKPEVENT;
*/
BOOL CDevTS_SaveChange(This,BYTE byEvent,WORD wValue,BOOL blAlarm)
{
    DECLARE_SINGLE_OPEN(CDevTS)  
	SKPEVENT sEV;
    if((byEvent!=pT->m_byOldEvent)||(byEvent==EV_CHG_PR))
	{
   	 pT->m_byOldEvent = byEvent;
	 sEV.wLen         = sizeof(SKPEVENT);
     sEV.byType       = pT->m_byType;
	 sEV.byCause      = byEvent;
	 sEV.wValue       = wValue; 
	 sEV.byAddr       = pT->m_byPinID;
     if(blAlarm)
	 pT->SendEvent(pT,&sEV);
	}
	return TRUE;
}
void CDevTS_SendEvent(This,SKPEVENT *pEV)
{
    DECLARE_SINGLE_OPEN(CDevTS)
	SHORTMESSAGE m_sMsg	;
	m_sMsg.m_swLen        = 9 + sizeof(SKPEVENT);  
	m_sMsg.m_sbyFrom      = pT->m_byFor;
	m_sMsg.m_sbyFor       = pT->m_byFor;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = pT->m_byEv;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = pT->m_byID;
	memcpy(&m_sMsg.m_sbyInfo[0],pEV,sizeof(SKPEVENT));
	FPUT(pT->m_byBox,(BYTE*)&m_sMsg);
}
BYTE CDevTS_CheckTS(This)
{
    DECLARE_SINGLE_OPEN(CDevTS)
	return pT->m_pPN->GetState(pT->m_pPN);
}
void CDevTS_Run(This)
{
    DECLARE_SINGLE_OPEN(CDevTS)
	pT->PreProc(pT);
	pT->Processing(pT);
	pT->PostProc(pT);
}
void CDevTS_CDevTS(This)
{
    DECLARE_SINGLE_OPEN(CDevTS) 
	DECLARE_REGISTRATION(CDevTS,SaveChange)
	DECLARE_REGISTRATION(CDevTS,SendEvent)
	DECLARE_REGISTRATION(CDevTS,CheckTS)
	DECLARE_REGISTRATION(CDevTS,SetTS)
	DECLARE_REGISTRATION(CDevTS,Init)
	DECLARE_REGISTRATION(CDevTS,Run)
	DECLARE_REGISTRATION(CDevTS,PreProc)
	DECLARE_REGISTRATION(CDevTS,Processing)
	DECLARE_REGISTRATION(CDevTS,PostProc)
}
void CDevTS_DCDevTS(This)
{
	DECLARE_SINGLE_OPEN(CDevTS)
}
DECLARE_SINGLE_CREATE(CDevTS)

