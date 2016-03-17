/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrtelecontrol.h"
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
void CTeleControl_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
	//BYTE i;
	pT->pP       = (STUPARAM*)psTable;
	pT->m_pbOT   = (BOOL*)pB->m_pvValue;
	pB->m_byType = REG_SOFTU_ADDR;
	pT->m_byStPulce  = FALSE;
	//pB->SaveChange(pB,EV_INI_CH,*pT->m_pbOT);
	//for(i=0;i<5;i++) pB->SaveChange(pB,EV_1T0_CH,i);
	//pT->m_bySetPulce = pT->pP->byCSetPulce;
    #ifdef DEB_CTeleControl
	//Info("\n(%b)CTLCT::>Create CTeleControl.",&pB->m_byID);
    #endif
}
void CTeleControl_PreProc(This)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
}
_GLOBAL INT nTCCH;
void CTeleControl_Processing(This)
{
	DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
	if (pB->m_byID==5)	nTCCH++;
	if(pT->pP->byState==EN_OPEN)
	{  
	 if(pT->m_byStPulce==TRUE)
	 {
	 if (--pT->m_bySetPulce==0)
	 {
	   if(*pT->m_pbOT==FALSE)
	   {
	   *pT->m_pbOT = TRUE;
	   pB->SaveChange(pB,EV_0T1_ST,1,FALSE);
	   }else
	   if(*pT->m_pbOT==TRUE )
	   {
	   *pT->m_pbOT = FALSE;
	   pB->SaveChange(pB,EV_1T0_ST,0,FALSE);
	   } 
       #ifdef DEB_CTeleControl
	   Info("\n(%b)CTLCT::>SetPulce::STOP.",&pB->m_byID);
       #endif	 
	   pT->m_byStPulce  = FALSE;
	 }
	 }
	 pT->pP->byParam = *pT->m_pbOT;
	}
}
void CTeleControl_PostProc(This)
{
	DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
}
void CTeleControl_SetPulce(This)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
	if(pT->pP->byState==EN_OPEN)	
	{
	 pT->m_bySetPulce = pT->pP->byCSetPulce;
	 pT->m_byStPulce  = TRUE;
	 if (pT->pP->byPulceType==EN_DIRECT) 
	 {
	  *pT->m_pbOT = TRUE;
	  pB->SaveChange(pB,EV_0T1_ST,1,FALSE);
	 }
	 if (pT->pP->byPulceType==EN_INVERT) 
	 {
	  *pT->m_pbOT = FALSE;
	  pB->SaveChange(pB,EV_1T0_ST,0,FALSE);
	 }
	 #ifdef DEB_CTeleControl
	 Info("\n(%b)CTLCT::>SetPulce::START.",&pB->m_byID);
     #endif
	}
}
void CTeleControl_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
	pB->SavePinState(pB,EV_INI_CH,*pT->m_pbOT);
}
void CTeleControl_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
	pB->SavePinState(pB,EV_ALP_CH,(WORD)pT->pP->byAlmState);
}
void CTeleControl_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
    SKPEVENT sEV;
	sEV.wLen    = sizeof(SKPEVENT);
	sEV.byType  = pB->m_byType;
    sEV.byCause = EV_CHK_CH;
	sEV.byAddr  = pB->m_byID;
	sEV.wValue  = (WORD)*pT->m_pbOT; 
	GetCurTime(&sEV.sTime);
    pB->SendBroadcast(pB,&sEV);
}
BOOL CTeleControl_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CTeleControl
	Info("\n(%b)CTLCT::>INPT::%M",&pB->m_byID,pMsg);
    #endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_101TOKP:
		   switch(pMsg->m_sbyType)
		   {
		    case PL_DATA_IND:
				 switch(byParamType)
				 {
				   case EN_STT_PULCE:
					    pT->SetPulce(pT);
				   break;
				   case EN_STT_SIGN:
					   //pT->SetPulce(pT,pT->pP->byPulceType);
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
void CTeleControl_CTeleControl(This)
{
    DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor) 
	DECLARE_REGISTRATION(CTeleControl,SetPulce)
	DECLARE_VIRTUAL_FUNC(CTeleControl,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CTeleControl,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CTeleControl,PreProc)
	DECLARE_VIRTUAL_FUNC(CTeleControl,Processing)
	DECLARE_VIRTUAL_FUNC(CTeleControl,PostProc)
	DECLARE_VIRTUAL_FUNC(CTeleControl,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTeleControl,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CTeleControl,SendObsrveMsg)
}
void CTeleControl_DCTeleControl(This)
{
	DECLARE_MULTI_OPEN(CTeleControl,CTeleSensor)
}
DECLARE_MULTI_CREATE(CTeleControl,CTeleSensor)

