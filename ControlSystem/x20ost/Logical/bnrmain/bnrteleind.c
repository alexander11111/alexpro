/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrteleind.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
extern UINT *uipValueAI2[];
void CTeleInd_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	//BYTE i;
	pT->pP = (STIPARAM*)psTable;
	pT->m_pnIN = (WORD*)pB->m_pvValue;

	pT->m_byRemTimer   = pT->pP->byDrTimer;
	pT->m_blTmRemState = FALSE;
	
	pT->m_bySetTimer   = pT->pP->byDrTimer;
	pT->m_blTmSetState = FALSE;

	pT->m_blChState    = pT->pP->byDrTimer;
	pT->m_byChTimer    = FALSE;

	pT->m_byErEventCh  = EV_CHG_PR;
	pT->m_byErEventHi  = EV_CHG_PR;
	pT->m_byErEventLo  = EV_CHG_PR;
	pB->m_byType       = REG_SOFTI_ADDR;
	//pB->SaveChange(pB,EV_INI_CH,*pT->m_pnIN);
    pT->InitMeter(pT);
	//for(i=0;i<5;i++) pB->SaveChange(pB,pT->m_byEvent,i);
    #ifdef DEB_CTeleInd
	//Info("\n(%b)CTIMD::>Create CTeleInd:",&pB->m_byID);
    #endif
}
void CTeleInd_InitMeter(This)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	WORD wIN = *pT->m_pnIN;
	if(wIN>=pT->pP->wHiLimit)
	{
	 pT->m_blSHIL   = TRUE;
	 pT->m_blRHIL   = FALSE;
	 pT->m_blSLOL   = FALSE;
	 pT->m_blRLOL   = TRUE;
	}
	if(wIN<=pT->pP->wLoLimit)
	{
	 pT->m_blSLOL   = TRUE;
	 pT->m_blRLOL   = FALSE;
	 pT->m_blSHIL   = FALSE;
	 pT->m_blRHIL   = TRUE;
	}
	if((wIN<=pT->pP->wHiGister)&&(wIN>=pT->pP->wLoGister))
	{
	 pT->m_blSHIL   = FALSE;
	 pT->m_blRHIL   = TRUE;
	 pT->m_blSLOL   = FALSE;
	 pT->m_blRLOL   = TRUE;
	}
	pT->m_wOldIN = wIN;
}
void CTeleInd_PreProc(This)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	BOOL res = FALSE;
	
	if(pT->m_blTmSetState==TRUE)
	{
	 if (--pT->m_bySetTimer==0)
	 {
	  if((pT->pP->byPriority==PRI_HI)&&(pT->m_byErEventHi==EV_SET_HI))res = TRUE;
	  pB->SaveChange(pB,pT->m_byErEventHi,*pT->m_pnIN,res);
	  pT->m_blTmSetState = FALSE;
	 }
	}
	res = FALSE;
	
	if(pT->m_blTmRemState==TRUE)
	{
	 if (--pT->m_byRemTimer==0)
	 {
	  if((pT->pP->byPriority==PRI_HI)&&(pT->m_byErEventLo==EV_SET_LO))res = TRUE;
	  pB->SaveChange(pB,pT->m_byErEventLo,*pT->m_pnIN,res);
	  pT->m_blTmRemState = FALSE;
	 }
	}
	res = FALSE;
	
	if(pT->m_blChState==TRUE)
	{
	 if (--pT->m_byChTimer==0)
	 {
	  //Info("\n(%b)CTIMD::>TI:%w",&pB->m_byID,pT->m_pnIN);
	  if(pT->pP->byPriority==PRI_HI)res = TRUE;
	  pB->SaveChange(pB,pT->m_byErEventCh,*pT->m_pnIN,FALSE);
	  pT->m_blChState = FALSE;
	 }
	}
	
}
void CTeleInd_Processing(This)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	if(pT->pP->byState==EN_OPEN)
	{
  	 pT->CheckTI(pT);
     pT->pP->wParam = *pT->m_pnIN;
	}
}
void CTeleInd_PostProc(This)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
}
_GLOBAL INT nTICH;
WORD CTeleInd_CheckTI(This)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor) 
	WORD res;
	WORD wIN = *pT->m_pnIN;
	WORD wHI =  pT->pP->wHiLimit;
	WORD wLO =  pT->pP->wLoLimit;
	WORD wHG =  pT->pP->wHiGister;
	WORD wLG =  pT->pP->wLoGister;
	//Deviation Section
	if(abs(wIN-pT->m_wOldIN)>pT->pP->wEvPercent)
	{
		pT->SetChandgeTimer(pT,EV_CHG_PR);
		pT->m_wOldIN = wIN;
	}
	//Hi Section
	//if (pB->m_byID==0)
	//if ((++nTICH % 20)==0)Info("\n(__)IN:%w HI:%w HG:%w LG:%w LO:%w BRLO:%b BSLO:%b",&wIN,&wHI,&wHG,&wLG,&wLO,&pT->m_blRLOL,&pT->m_blSLOL);
	if(wIN>=wHI)
	{
	  pT->SetEventHi(pT,&pT->m_blSHIL,&pT->m_blRHIL,EV_SET_HI);
	}
	//if((wIN<wHG)&&(wIN>wLG))
	if(wIN<wHG)
	{
	  pT->SetEventHi(pT,&pT->m_blRHIL,&pT->m_blSHIL,EV_REM_HI);
	}
	//if((wIN>wLG)&&(wIN<wHG)) 
	if(wIN>wLG)
	{
	  pT->SetEventLo(pT,&pT->m_blRLOL,&pT->m_blSLOL,EV_REM_LO);
	}
	if(wIN<wLO)
	{
	  pT->SetEventLo(pT,&pT->m_blSLOL,&pT->m_blRLOL,EV_SET_LO);
	}
	return res=wIN;
}
void CTeleInd_SetEventHi(This,BOOL *bl0,BOOL *bl1,BYTE byEvent)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	if (*bl0 == FALSE)
	{
	 pT->SetEventTimerHi(pT,byEvent);
     *bl0 = TRUE;
     *bl1 = FALSE;
	}
}
void CTeleInd_SetEventLo(This,BOOL *bl0,BOOL *bl1,BYTE byEvent)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	if (*bl0 == FALSE)
	{
	 pT->SetEventTimerLo(pT,byEvent);
     *bl0 = TRUE;
     *bl1 = FALSE;
	}
}
void CTeleInd_SetEventEv(This,BOOL *bl0,BOOL *bl1,BYTE byEvent)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	if (*bl0 == FALSE)
	{
	 //pT->SetEventTimer(pT,byEvent);
	 pT->m_byErEventCh = byEvent;
	 pB->SaveChange(pB,pT->m_byErEventCh,*pT->m_pnIN,FALSE);
     *bl0 = TRUE;
     *bl1 = FALSE;
	}
}
void CTeleInd_SetEventTimerHi(This,BYTE byEvent)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	pT->m_blTmSetState = TRUE;
	pT->m_bySetTimer   = pT->pP->byDrTimer;
	pT->m_byErEventHi  = byEvent;
}
void CTeleInd_SetEventTimerLo(This,BYTE byEvent)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	pT->m_blTmRemState = TRUE;
	pT->m_byRemTimer   = pT->pP->byDrTimer;
	pT->m_byErEventLo  = byEvent;
}
void CTeleInd_SetChandgeTimer(This,BYTE byEvent)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	pT->m_blChState    = TRUE;
	pT->m_byChTimer    = pT->pP->byDrTimer;
	pT->m_byErEventCh  = byEvent;
}
void CTeleInd_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	pB->SavePinState(pB,EV_INI_CH,*pT->m_pnIN);
}
void CTeleInd_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
	pB->SavePinState(pB,EV_ALP_CH,(WORD)pT->pP->byAlmState);
}
void CTeleInd_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
    SKPEVENT sEV;
	sEV.wLen    = sizeof(SKPEVENT);
	sEV.byType  = pB->m_byType;
    sEV.byCause = EV_CHK_CH;
	sEV.byAddr  = pB->m_byID;
	sEV.wValue  = (WORD)*pT->m_pnIN; 
	GetCurTime(&sEV.sTime);
    pB->SendBroadcast(pB,&sEV);
}
BOOL CTeleInd_EventHandler(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor) 
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CTeleInd
	Info("\n(%b)CTIMD::>INPT::%M",&pB->m_byID,pMsg);
    #endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_101TOKP:
		   switch(pMsg->m_sbyType)
		   {
		    case PL_DATA_IND:
				 switch(byParamType)
				 {
				   case EN_HIL_PR:
					    //pT->m_wHiLimit  = pB->GetW(pB,&pMsg->m_sbyInfo[3]);
				   break;
				   case EN_HIG_PR:
					    //pT->m_wHiGister = pB->GetW(pB,&pMsg->m_sbyInfo[3]);
				   break;
				   case EN_LOL_PR:
					    //pT->m_wLoLimit  = pB->GetW(pB,&pMsg->m_sbyInfo[3]);
				   break;
				   case EN_LOG_PR:
					    //pT->m_wLoGister = pB->GetW(pB,&pMsg->m_sbyInfo[3]);
				   break;
				   case EN_DTM_PR:
					    //pT->m_byDrTimer = pMsg->m_sbyInfo[3]; 
				   break;
				   default:
				   break;
				 }
		    break;  
			default:
            break;  
		   }
      break;
	  case DIR_101MD:
	  break;
	  default:
	  break;
	}
	return TRUE;
}
void CTeleInd_CTeleInd(This)
{
    DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor) 
	DECLARE_REGISTRATION(CTeleInd,CheckTI)
	DECLARE_REGISTRATION(CTeleInd,InitMeter)
	DECLARE_REGISTRATION(CTeleInd,SetEventHi)
	DECLARE_REGISTRATION(CTeleInd,SetEventLo)
	DECLARE_REGISTRATION(CTeleInd,SetEventTimerHi)
	DECLARE_REGISTRATION(CTeleInd,SetEventTimerLo)
	DECLARE_REGISTRATION(CTeleInd,SetChandgeTimer)
	DECLARE_REGISTRATION(CTeleInd,SetEventEv)
	
	DECLARE_VIRTUAL_FUNC(CTeleInd,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CTeleInd,PreProc)
	DECLARE_VIRTUAL_FUNC(CTeleInd,Processing)
	DECLARE_VIRTUAL_FUNC(CTeleInd,PostProc)
	DECLARE_VIRTUAL_FUNC(CTeleInd,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTeleInd,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CTeleInd,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CTeleInd,SendObsrveMsg)
}
void CTeleInd_DCTeleInd(This)
{
	DECLARE_MULTI_OPEN(CTeleInd,CTeleSensor)
}
DECLARE_MULTI_CREATE(CTeleInd,CTeleSensor)

