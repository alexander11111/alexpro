/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrtelesensor.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
//#include "bnrmain.h"
//#ifdef WIN32
char *STTS[]  =
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
BYTE byIDD;
void CTeleSensor_Init(This,PVOID *psTable)
{
    DECLARE_SINGLE_OPEN(CTeleSensor)  
	CSlot *pSL;
	CComputer *pCM   = pT->m_pComputer;
	STIPARAM  *pPV   = (STIPARAM*)psTable;
    pT->pP           = pPV;
	pT->m_byID       = pPV->byID;
	byIDD            = pT->m_byID;
	pSL              = pCM->GetSlot(pCM,pT->pP->bySlot);
	pT->m_pPN        = pSL->GetPin(pSL->pChld,pT->pP->byPin);
	pT->m_pvValue    = (PVOID)pT->m_pPN->GetAddrPin(pT->m_pPN->pChld);
    pT->m_pvAlValue  = (BOOL*)pT->m_pPN->m_pvAlmState;	
	pT->m_blSetAlarm = FALSE;
	pT->m_byOldEvent = 0xff;
	#ifdef WIN32
    if(pPV->byType==TI) 
	{
	 *((WORD*)pT->m_pvValue) = pT->m_byID;
	 pT->pP->wParam = pT->m_byID;
    }
	if(pPV->byType==TU) *((BOOL*)pT->m_pvValue) = FALSE;
	#endif
	pT->InitTCHN(pC,psTable);
}
void CTeleSensor_Switch(This)
{
   DECLARE_SINGLE_OPEN(CTeleSensor) 
   CSlot *pSL;
   CComputer *pCM  = pT->m_pComputer;
   pSL             = pCM->GetSlot(pCM,pT->pP->bySlot);
   pT->m_pPN       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
   pT->m_pvValue   = (PVOID)pT->m_pPN->GetAddrPin(pT->m_pPN->pChld);
   pT->m_pvAlValue = (BOOL*)pT->m_pPN->m_pvAlmState;	
   pT->InitTCHN(pC,pT->pP);
}
void CTeleSensor_InitTCHN(This,SSWITCHTABLE *psTable){}
void CTeleSensor_PreProc(This){}
void CTeleSensor_Processing(This){}
void CTeleSensor_PostProc(This){}
void CTeleSensor_ObserveProc(This)
{
     DECLARE_SINGLE_OPEN(CTeleSensor) 
	 pT->PreProc(pC);
	 pT->Processing(pC);
	 pT->PostProc(pC);
     if(++pT->m_byALC%20==0) pT->CheckAlarm(pT);
}
void CTeleSensor_CheckAlarm(This)
{
     DECLARE_SINGLE_OPEN(CTeleSensor) 
	 if(*pT->m_pvAlValue==TRUE)
	 {
      if (pT->m_blSetAlarm==FALSE)
      {
	    pT->m_blSetAlarm = TRUE;
		pT->SaveChange(pT,EV_SAL_CH,1,TRUE);
		pT->pP->byAlmState = 1;
      }
	 }else
	 if(*pT->m_pvAlValue==FALSE)
	 {
      if (pT->m_blSetAlarm==TRUE)
      {
	   pT->m_blSetAlarm = FALSE;
	   pT->SaveChange(pT,EV_RAL_CH,0,TRUE);
	   pT->pP->byAlmState = 0;
	  }
	 }
}
BOOL CTeleSensor_EventHandler(This,SMESSAGE *pMsg)
{
	 DECLARE_SINGLE_OPEN(CTeleSensor) 
	 return TRUE;
}
BOOL CTeleSensor_SaveChange(This,BYTE byEvent,WORD wValue,BOOL blAlarm)
{
    DECLARE_SINGLE_OPEN(CTeleSensor)  
	SKPEVENT sEV;
	STSPARAM *pTS;STIPARAM *pTI;
	SKPPARAM *pH = pT->m_pPCT->pKpParam;
	sEV.wLen    = sizeof(SKPEVENT);
	sEV.byType  = pT->m_byType;
    sEV.byCause = byEvent;
    if((byEvent!=pT->m_byOldEvent)||(byEvent==EV_CHG_PR))
	{
	 pT->m_byOldEvent = byEvent;
	 sEV.byAddr  = pT->m_byID;
	 sEV.wValue  = wValue; 
	 GetCurTime(&sEV.sTime);
     if(blAlarm)
	 {
	  #ifdef DEB_CTeleSensor
      Info("\n(%b)CTLSN::>Send Alarm[%s]:",&pT->m_byID,STTS[sEV.byCause]);
      #endif
	  pT->SendSMessage(pT,DEV_KPMDL_BOX_ID,DIR_PHTOKP,PH_CALL_REQ);
	 }
	 FPUT1(BOX_L4,(BYTE*)&sEV);
	 if((pH->byStoreMode&SBM_TIUNLOAD)&&(sEV.byType==REG_SOFTI_ADDR)) pT->SendBroadcast(pT,&sEV);
	 if((pH->byStoreMode&SBM_TSUNLOAD)&&(sEV.byType==REG_SOFTS_ADDR)) pT->SendBroadcast(pT,&sEV);
	 if((pH->byStoreMode&SBM_TUUNLOAD)&&(sEV.byType==REG_SOFTU_ADDR)) pT->SendBroadcast(pT,&sEV);
	 /*
	 Info("\n(%b)CTLSN::>Y[%b]:M[%b]:D[%b]:H[%b]:M[%b]::S[%b]::L[%b]::H[%b]:",
	 &pT->m_byID,
	 &sEV.sTime.tYear,
	 &sEV.sTime.tMonth,
	 &sEV.sTime.tDay,
	 &sEV.sTime.tHour,
	 &sEV.sTime.tMin,
	 &sEV.sTime.tSec,
	 &sEV.sTime.tMSecL,
	 &sEV.sTime.tMSecH);
	 */
	 #ifdef DEB_CTeleSensor
	 Info("\n(%b)CTLSN::>TP[%b]:AD[%b]:VL[%w]:CS[%s]:",&pT->m_byID,&sEV.byType,&sEV.byAddr,&sEV.wValue,STTS[sEV.byCause]);
     #endif
	}
	return TRUE;
}
BOOL CTeleSensor_SavePinState(This,BYTE byEvent,WORD wValue)
{
    DECLARE_SINGLE_OPEN(CTeleSensor)  
	SKPEVENT sEV;
	STSPARAM *pTS;
	SHARDCOMPUTERTABLE *pH = pT->m_pPCT;
	sEV.wLen    = sizeof(SKPEVENT);
	sEV.byType  = pT->m_byType;
    sEV.byCause = byEvent;
	sEV.byAddr  = pT->m_byID;
	sEV.wValue  = wValue; 
	GetCurTime(&sEV.sTime);
	FPUT1(BOX_L4_1,(BYTE*)&sEV);
	#ifdef DEB_CTeleSensor
	Info("\n(%b)CTLIN::>TP[%b]:AD[%b]:VL[%w]:CS[%s]:",&pT->m_byID,&sEV.byType,&sEV.byAddr,&sEV.wValue,STTS[sEV.byCause]);
    #endif
	return TRUE;
}
void CTeleSensor_SendSMessage(This,BYTE byBox,BYTE byFor,BYTE byType)
{
    DECLARE_SINGLE_OPEN(CTeleSensor)
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
    #ifdef DEB_CTeleSensor
	Info("\n(__)CTLSN::>OUTT::%M",&m_sMsg);
    #endif
}
void CTeleSensor_SendBroadcast(This,SKPEVENT *pEV)
{
    DECLARE_SINGLE_OPEN(CTeleSensor) 
	SHORTMESSAGE m_sMsg	;
	m_sMsg.m_swLen        = 9 + sizeof(SKPEVENT);  
	m_sMsg.m_sbyFrom      = DIR_KPMOD;
	m_sMsg.m_sbyFor       = DIR_KPTO101;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PL_DATA_REQ;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	memcpy(&m_sMsg.m_sbyInfo[0],pEV,sizeof(SKPEVENT));
	FPUT(DEV_101MD_BOX_ID,(BYTE*)&m_sMsg);
}
void CTeleSensor_SetInPinEvent(This)
{
    DECLARE_SINGLE_OPEN(CTeleSensor) 
}
void CTeleSensor_SaveAlarmPin(This)
{
    DECLARE_SINGLE_OPEN(CTeleSensor) 
}
void CTeleSensor_SendObsrveMsg(This)
{
    DECLARE_SINGLE_OPEN(CTeleSensor) 
}
void CTeleSensor_CTeleSensor(This)
{
     DECLARE_SINGLE_OPEN(CTeleSensor) 
	 DECLARE_REGISTRATION(CTeleSensor,Init)
	 //DECLARE_REGISTRATION(CTeleSensor,GetW)
	 DECLARE_REGISTRATION(CTeleSensor,SendSMessage)
	 DECLARE_REGISTRATION(CTeleSensor,ObserveProc)
	 DECLARE_REGISTRATION(CTeleSensor,PreProc)
	 DECLARE_REGISTRATION(CTeleSensor,Processing)
	 DECLARE_REGISTRATION(CTeleSensor,PostProc)
	 DECLARE_REGISTRATION(CTeleSensor,EventHandler)
	 DECLARE_REGISTRATION(CTeleSensor,SaveChange)
	 DECLARE_REGISTRATION(CTeleSensor,SavePinState)
	 DECLARE_REGISTRATION(CTeleSensor,SendBroadcast)
	 DECLARE_REGISTRATION(CTeleSensor,CheckAlarm)
	 DECLARE_REGISTRATION(CTeleSensor,Switch)
	 DECLARE_REGISTRATION(CTeleSensor,SetInPinEvent)
	 DECLARE_REGISTRATION(CTeleSensor,SaveAlarmPin)
	 DECLARE_REGISTRATION(CTeleSensor,SendObsrveMsg)
}
void CTeleSensor_DCTeleSensor(This)
{
	 DECLARE_SINGLE_OPEN(CTeleSensor)
}
DECLARE_SINGLE_CREATE(CTeleSensor)

