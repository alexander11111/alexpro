/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrdigsensor.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#if MYSYSTEM_ID != 5
IMPORT_TASKCHAIN(Skip);
//пустое состояние
IMPORT_STATE(BadState);
//Обработчик событий дискретного датчика
//Digital Sensor Logic///////////////////////////////////////
DECLARE_TASKCHAIN(EvMcSetIn00){/*CMD_SETSTATE,SNS_STATE_FREE,*/EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn00){/*CMD_SETSTATE,SNS_STATE_FREE,*/EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn01){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn01){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn02){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn02){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn03){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn03){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn04){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn04){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn05){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn05){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn06){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn06){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn07){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn07){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn08){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn08){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn09){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn09){EXIT_D,};
/*DECLARE_TASKCHAIN(EvMcSetIn10){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn10){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn11){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn11){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn12){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn12){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn13){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn13){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn14){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn14){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn15){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn15){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn16){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn16){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn17){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn17){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn18){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn18){EXIT_D,};
DECLARE_TASKCHAIN(EvMcSetIn19){EXIT_D,};
DECLARE_TASKCHAIN(EvMcRemIn19){EXIT_D,};*/
DECLARE_STATE(Dig00StateFree)
{
    { EV_MCSET_IN00,          EvMcSetIn00},
	{ EV_MCREM_IN00,          EvMcRemIn00},
    { EV_MCSET_IN01,          EvMcSetIn01},
	{ EV_MCREM_IN01,          EvMcRemIn01},
    { EV_MCSET_IN02,          EvMcSetIn02},
	{ EV_MCREM_IN02,          EvMcRemIn02},
    { EV_MCSET_IN03,          EvMcSetIn03},
	{ EV_MCREM_IN03,          EvMcRemIn03},
    { EV_MCSET_IN04,          EvMcSetIn04},
	{ EV_MCREM_IN04,          EvMcRemIn04},
    { EV_MCSET_IN05,          EvMcSetIn05},
	{ EV_MCREM_IN05,          EvMcRemIn05},
    { EV_MCSET_IN06,          EvMcSetIn06},
	{ EV_MCREM_IN06,          EvMcRemIn06},
    { EV_MCSET_IN07,          EvMcSetIn07},
	{ EV_MCREM_IN07,          EvMcRemIn07},
    { EV_MCSET_IN08,          EvMcSetIn08},
	{ EV_MCREM_IN08,          EvMcRemIn08},
    { EV_MCSET_IN09,          EvMcSetIn09},
	{ EV_MCREM_IN09,          EvMcRemIn09},
    /*{ EV_MCSET_IN10,          EvMcSetIn10},
	{ EV_MCREM_IN10,          EvMcRemIn10},
    { EV_MCSET_IN11,          EvMcSetIn11},
	{ EV_MCREM_IN11,          EvMcRemIn11},
    { EV_MCSET_IN12,          EvMcSetIn12},
	{ EV_MCREM_IN12,          EvMcRemIn12},
    { EV_MCSET_IN13,          EvMcSetIn13},
	{ EV_MCREM_IN13,          EvMcRemIn13},
    { EV_MCSET_IN14,          EvMcSetIn14},
	{ EV_MCREM_IN14,          EvMcRemIn14},
    { EV_MCSET_IN15,          EvMcSetIn15},
	{ EV_MCREM_IN15,          EvMcRemIn15},
    { EV_MCSET_IN16,          EvMcSetIn16},
	{ EV_MCREM_IN16,          EvMcRemIn16},
    { EV_MCSET_IN17,          EvMcSetIn17},
	{ EV_MCREM_IN17,          EvMcRemIn17},
    { EV_MCSET_IN18,          EvMcSetIn18},
	{ EV_MCREM_IN18,          EvMcRemIn18},
    { EV_MCSET_IN19,          EvMcSetIn19},
	{ EV_MCREM_IN19,          EvMcRemIn19},*/
    { EV_UNKNOWN_REQ,         Skip       }
};
DECLARE_STATELIST(STL_DIGS00_SENS)
{
    { SNS_STATE_FREE,         Dig00StateFree     },
    { S_BAD,                  BadState           }
};
void CDigitalSensor_InitSensor(This,PVOID pParam)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor)
	 BYTE i;
	 SSWITCHTABLE *pS = (SSWITCHTABLE*)pParam;
	 SDIGGATE *pDIN = pS->sSensorParamTable;
	 SDIGGATE *pDOT = pS->sOutGate[0];
	 pB->m_wAmInput  = pDIN->swAmpin;
	 pB->m_wAmOutput = pDOT->swAmpin;
	 New(sizeof(CPin*)*pB->m_wAmInput  ,pB->m_pINP);
	 New(sizeof(CPin*)*pB->m_wAmOutput ,pB->m_pOUT);
	 New(sizeof(BOOL*)*pB->m_wAmOutput ,pB->m_bINP);
	 New(sizeof(BOOL*)*pB->m_wAmOutput ,pB->m_bOUT);
	 New(sizeof(INT16*)*pB->m_wAmOutput,pB->m_nINP);
	 New(sizeof(INT16*)*pB->m_wAmOutput,pB->m_nOUT);
	 for (i=0;i<pB->m_wAmInput;i++) 
	 {
	  pB->m_pINP[i]=0;
	  pB->m_bINP[i]=0;
	  pB->m_nINP[i]=0;
	 }
	 for (i=0;i<pB->m_wAmOutput;i++)
	 {
	  pT->m_nPulceTime[i] = 0;
	  pT->m_blPulceGo[i]  = FALSE;
	  pT->m_nCurrValue[i] = 0xffff;
	  pB->m_pOUT[i]=0;
	  pB->m_bOUT[i]=0;
	  pB->m_nOUT[i]=0;
	 }
	 pB->m_dwInState  = 0x00;
	 pB->m_dwOutState = 0;
     #ifdef DEB_CDigitalSensor
     Info("\n(%b)CDSNS::>Create Digital:In[%b]:Out[%b]",&pB->m_bySensorID,&pDIN->swAmpin,&pDOT->swAmpin);
     #endif
}
//INT _GLOBAL nOutDN,nOutUP,nNumber_D,nTime_D,nVal_D,nInC,nPS_GO,nPS_ST,nTM_STOP,nPL_OUT,n0_PL,n1_PL;
void CDigitalSensor_EventHandler(This,SMESSAGE *pMsg)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
	 BYTE  byNumber;
	 UINT  wTime;
	 UINT  wValue;
	 switch (pMsg->m_sbyType)
	 {
	   case EV_SENSR_SET_DIGT_OUT_REQ:
		    byNumber = pMsg->m_sbyInfo[1];
			wValue   = pB->GetWordParam(pB,&pMsg->m_sbyInfo[2]);
			if(byNumber<pB->m_wAmOutput)
		    pT->SetRemOut(pT,byNumber,wValue);
	   break;
	   case EV_SENSR_SET_DIGT_PULCE_REQ:
		    byNumber = pMsg->m_sbyInfo[1];
			wTime    = pB->GetWordParam(pB,&pMsg->m_sbyInfo[2]);   
			wValue   = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);   
			pT->SetPulce(pT,byNumber,wValue,wTime);
			//nNumber_D = byNumber;
			//nTime_D   = wTime;
			//nVal_D    = wValue;
			//nInC++;
	   break;
	   default:
	   break; 
	 }
}
INT _GLOBAL nINrem;
void CDigitalSensor_SetPulce(This,BYTE byNumber,UINT wValue,UINT wTime)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor)
	 pT->m_blPulceGo[byNumber]  = FALSE;
	 pT->m_nCurrValue[byNumber] = wValue;
	 if(wTime==0xffff)
	 {
 	  if(byNumber<pB->m_wAmOutput)
	  pT->SetRemOut(pT,byNumber,wValue);
	 }else
	 {
	  nINrem++;
 	  if(pT->m_nCurrValue[byNumber]==1) 
	  {
	   #ifdef MY_MODEL
	   pB->m_dwInState  |= 1<<byNumber;
	   #endif
       pB->m_dwOutState |= 1<<byNumber;
	   *pB->m_bOUT[byNumber] = 1;
	   
	  }
	  if(pT->m_nCurrValue[byNumber]==0) 
	  {
	   #ifdef MY_MODEL
       pB->m_dwInState  &= ~(1<<byNumber);
	   #endif
	   pB->m_dwOutState &= ~(1<<byNumber);
	   *pB->m_bOUT[byNumber] = 0;
	  }
	  pT->m_blPulceGo[byNumber] = TRUE;
	  pT->m_nPulceTime[byNumber] = wTime/SYSTEM_QTIME;
	 }
}
void CDigitalSensor_SetRemOut(This,BYTE byNumber,UINT wValue)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor)
	 CPin *pN;
	 pN = pB->m_pINP[byNumber];
     if (pN->m_byPinType==PIN_DG_INOT_BOL) *pB->m_bOUT[byNumber] = (BOOL)wValue;
     if (pN->m_byPinType==PIN_AN_INOT_INT) *pB->m_nOUT[byNumber] = wValue;
	 if (wValue)pB->m_dwOutState |= 1<<byNumber;else pB->m_dwOutState &= ~(1<<byNumber);
}
void CDigitalSensor_PreProc(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor)
	 pT->EventGen(pT);
	 pT->PulceGen(pT);
}
void CDigitalSensor_PulceGen(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
	 BYTE i;
	 for (i=0;i<pB->m_wAmOutput;i++)
	 if(pT->m_blPulceGo[i])
	 {
	  if(pT->m_nPulceTime[i]--==0)
	  {
	  if(pT->m_nCurrValue[i]==TRUE)
	  {
       pB->m_dwOutState &= ~(1<<i);
	   *pB->m_bOUT[i] = 0;
	  }
	  if(pT->m_nCurrValue[i]==FALSE)
	  {
	   pB->m_dwOutState |= 1<<i;	 
	   *pB->m_bOUT[i] = 1;
	  }
	  pT->m_blPulceGo[i] = FALSE;
	 }
	}
}
void CDigitalSensor_EventGen(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
	 BYTE i,byState;
	 CPin *pN;
	 //nPL_GEN++;
     for (i=0;i<pB->m_wAmInput;i++) 
	 {
	  pN = pB->m_pINP[i];
	  byState = pN->GetState(pN);
	  if(byState==PIN_STATE_ONN)
	  {
       #ifdef DEB_CDigitalSensor
	   //Info("\n(%b)CDSNS::>PIN[ON ] :L[%b]:S[%b]:P[%b]",&pB->m_bySensorID,&i,&pN->m_bySlotNumber,&pN->m_byPinNumber);
       #endif
	   pB->SetAutoEvent(pB,i+EV_MCSET_IN00);
	   pB->m_dwInState |= 1<<i;
	  }
	  if(byState==PIN_STATE_OFF)
	  {
       #ifdef DEB_CDigitalSensor
	   //Info("\n(%b)CDSNS::>PIN[OFF] :L[%b]:S[%b]:P[%b]",&pB->m_bySensorID,&i,&pN->m_bySlotNumber,&pN->m_byPinNumber);
       #endif	  
	   pB->SetAutoEvent(pB,i+EV_MCREM_IN00);
	   pB->m_dwInState &= ~(1<<i);
	  }
	  if(byState==PIN_STATE_TRI){}
	 }
}
void CDigitalSensor_Processing(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
}
void CDigitalSensor_PostProc(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
}
void CDigitalSensor_RunAutomat(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
}
void CDigitalSensor_CDigitalSensor(This)
{
     DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
	 DECLARE_REGISTRATION(CDigitalSensor,EventGen)
	 DECLARE_REGISTRATION(CDigitalSensor,SetRemOut)
	 DECLARE_REGISTRATION(CDigitalSensor,SetPulce)
	 DECLARE_REGISTRATION(CDigitalSensor,PulceGen)
	 DECLARE_VIRTUAL_FUNC(CDigitalSensor,InitSensor)
	 DECLARE_VIRTUAL_FUNC(CDigitalSensor,EventHandler)
	 DECLARE_VIRTUAL_FUNC(CDigitalSensor,PreProc)
	 DECLARE_VIRTUAL_FUNC(CDigitalSensor,Processing)
	 DECLARE_VIRTUAL_FUNC(CDigitalSensor,PostProc)
	 DECLARE_VIRTUAL_FUNC(CDigitalSensor,RunAutomat)
}
void CDigitalSensor_DCDigitalSensor(This)
{
	 DECLARE_MULTI_OPEN(CDigitalSensor,CSensor) 
	 Delete(sizeof(CPin*)*pB->m_wAmInput  ,pB->m_pINP);
	 Delete(sizeof(CPin*)*pB->m_wAmOutput ,pB->m_pOUT);
	 Delete(sizeof(BOOL*)*pB->m_wAmOutput ,pB->m_bINP);
	 Delete(sizeof(BOOL*)*pB->m_wAmOutput ,pB->m_bOUT);
	 Delete(sizeof(INT16*)*pB->m_wAmOutput,pB->m_nINP);
	 Delete(sizeof(INT16*)*pB->m_wAmOutput,pB->m_nOUT);
}
DECLARE_MULTI_CREATE(CDigitalSensor,CSensor)
#endif
