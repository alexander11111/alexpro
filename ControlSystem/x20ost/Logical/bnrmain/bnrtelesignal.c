/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrtelesignal.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CTeleSignal_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
	//BYTE i;
	pT->pP = (STSPARAM*)psTable;
	pT->m_pbIN = (BOOL*)pB->m_pvValue;
	pT->m_blTmSetState = FALSE;   
	pT->m_blTmRemState = FALSE;   
	pB->m_byType       = REG_SOFTS_ADDR;
	pT->m_blFSignal    = FALSE;
	//pB->SaveChange(pB,EV_INI_CH,*pT->m_pbIN);
	//for(i=0;i<5;i++) pB->SaveChange(pB,EV_0T1_CH,i);
    #ifdef DEB_CTeleSignal
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CTeleSignal_PreProc(This)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
	
}
_GLOBAL INT nTSCH;
void CTeleSignal_Processing(This)
{
	DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
	BYTE byState;
	if (pB->m_byID==40)	nTSCH++;
	if (pT->pP->byState==EN_OPEN) 
	{
	 byState = pT->CheckTS(pT);
	 if(byState==PIN_STATE_ONN){pT->m_blTmSetState = TRUE;pT->m_blTmRemState = FALSE;pT->m_bySetPulce = pT->pP->byCSetPulce;}
	 if(byState==PIN_STATE_OFF){pT->m_blTmRemState = TRUE;pT->m_blTmSetState = FALSE;pT->m_byRemPulce = pT->pP->byCRemPulce;}
	 pT->pP->byParam = *pT->m_pbIN;
	}
}
void CTeleSignal_PostProc(This)
{
	DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
	BOOL res = FALSE;
	//Set Timer
	if (pT->pP->byState==EN_OPEN) 
	{
	if(pT->m_blTmSetState==TRUE)
	{
	 if (--pT->m_bySetPulce==0)
	 {
	  if((pT->pP->byPriority==PRI_HI)&&((pT->pP->byAlarmMode==EN_AL_TO_AL)||(pT->pP->byAlarmMode==EN_LO_TO_HI))) res = TRUE;
	  pB->SaveChange(pB,EV_0T1_CH,1,res);
	  pT->m_blTmSetState = FALSE;
	 }
	}
    //Rem Timer
	if(pT->m_blTmRemState==TRUE)
	{
	 if (--pT->m_byRemPulce==0)
	 {
	  if((pT->pP->byPriority==PRI_HI)&&((pT->pP->byAlarmMode==EN_AL_TO_AL)||(pT->pP->byAlarmMode==EN_HI_TO_LO))) res = TRUE;
	  if( pT->m_blFSignal)pB->SaveChange(pB,EV_1T0_CH,0,res);
	  pT->m_blTmRemState = FALSE;
	  pT->m_blFSignal = TRUE;
	 }
	}
	}
}
BYTE CTeleSignal_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor) 
	return pB->m_pPN->GetState(pB->m_pPN);
}
BOOL CTeleSignal_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor) 
    BYTE byID = pMsg->m_sbySensor;
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CTeleSignal
	Info("\n(%b)CTLSG::>INPT::%M",&pB->m_byID,pMsg);
    #endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_101TOKP:
		   switch(pMsg->m_sbyType)
		   {
		    case PL_DATA_IND:
				 //Info("\n(%b)CTLSG::>DL_DATA_IND::>%M",&pB->m_byID,pMsg);
				 switch(byParamType)
				 {
				   case EN_SET_PERIOD:
					    //pT->m_byCSetPulce = pMsg->m_sbyInfo[3];
					    //pT->m_bySetPulce  = pT->m_byCSetPulce;
				   break;
				   case EN_REM_PERIOD:
					    //pT->m_byRemPulce  = pMsg->m_sbyInfo[3]; 
						//pT->m_byCRemPulce = pT->m_byRemPulce;
				   break;
				   case EN_PIN_ALMODE:
                        //pT->m_byAlarmMode = pMsg->m_sbyInfo[3];
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
void CTeleSignal_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
	pB->SavePinState(pB,EV_INI_CH,*pT->m_pbIN);
}
void CTeleSignal_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
	pB->SavePinState(pB,EV_ALP_CH,(WORD)pT->pP->byAlmState);
}
void CTeleSignal_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
    SKPEVENT sEV;
	sEV.wLen    = sizeof(SKPEVENT);
	sEV.byType  = pB->m_byType;
    sEV.byCause = EV_CHK_CH;
	sEV.byAddr  = pB->m_byID;
	sEV.wValue  = (WORD)*pT->m_pbIN; 
	GetCurTime(&sEV.sTime);
    pB->SendBroadcast(pB,&sEV);
}
void CTeleSignal_CTeleSignal(This)
{
    DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor) 
	DECLARE_REGISTRATION(CTeleSignal,CheckTS)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,PreProc)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,Processing)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,PostProc)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CTeleSignal,SendObsrveMsg)
}
void CTeleSignal_DCTeleSignal(This)
{
	DECLARE_MULTI_OPEN(CTeleSignal,CTeleSensor)
}
DECLARE_MULTI_CREATE(CTeleSignal,CTeleSensor)

