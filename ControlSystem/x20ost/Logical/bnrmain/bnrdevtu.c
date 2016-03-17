/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrdevtu.h"
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
/*
BYTE byID;
    BYTE byAmParam; 
	STUMPARAMS nTU = {10,TU,{
	{45  ,0 ,TU ,10, 2 , 0, EN_OPEN, EN_DIRECT, 5, 1},
	typedef struct _tagTUMParam
	{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	BYTE byPulceType;
    WORD byCSetPulce;
	STUMDATA sDT;
}STUMPARAM; 
*/
void CDevTU_Init(This,BOOL *pblValue,BYTE byID,BYTE byIID,BYTE byState,BYTE byPulceType,DWORD byCSetPulce)
{
    DECLARE_SINGLE_OPEN(CDevTU)
	//memcpy(pTU,&pT->pP,sizeof(STUMPARAM));
	pT->pP.byID        = byID;
	pT->pP.byAmParam   = byIID;
    pT->pP.byState     = byState;  
    pT->pP.byPulceType = byPulceType;  
    pT->pP.byCSetPulce = byCSetPulce;  
	pT->m_dwJob        = byPulceType;  

	pT->m_pbOT       = pblValue;
	pT->m_byType     = REG_SOFTU_ADDR;
	pT->m_byStPulce  = FALSE;
	pT->m_byID       = pT->pP.byID;
    pT->m_byPinID    = pT->pP.byAmParam;
	pT->m_byOldEvent = 0xff;
	//pT->InvPin(pT);
	//if (pT->pP.byPulceType==EN_DIRECT) *pT->m_pbOT = FALSE; else
	//if (pT->pP.byPulceType==EN_INVERT) *pT->m_pbOT = TRUE;
}
void CDevTU_SetTU(This,BYTE byBox,BYTE byFor,BYTE byEv)
{
    DECLARE_SINGLE_OPEN(CDevTU)
	pT->m_byBox  = byBox;
	pT->m_byFor  = byFor;
	pT->m_byEv   = byEv;
}
void CDevTU_PreProc(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
}
_GLOBAL INT nTCCH;
void CDevTU_Processing(This)
{
	DECLARE_SINGLE_OPEN(CDevTU)
	if (pT->m_byID==5)	nTCCH++;
	if(pT->pP.byState==EN_OPEN)
	{  
	 if(pT->m_byStPulce==TRUE)
	 {
	 if (--pT->m_bySetPulce==0)
	 {
	   if(*pT->m_pbOT==FALSE)
	   {
	   *pT->m_pbOT = TRUE;
	   pT->SaveChange(pT,EV_0T1_ST,1,FALSE);
	   }else
	   if(*pT->m_pbOT==TRUE )
	   {
	   *pT->m_pbOT = FALSE;
	   pT->SaveChange(pT,EV_1T0_ST,0,FALSE);
	   } 
       #ifdef DEB_CDevTU
	   Info("\n(%b)CTLCT::>SetPulce::STOP.",&pT->m_byID);
       #endif	 
	   pT->m_byStPulce  = FALSE;
	 }
	 }
	 pT->pP.sDT.byParam = *pT->m_pbOT;
	}
}
void CDevTU_PostProc(This)
{
	DECLARE_SINGLE_OPEN(CDevTU)
}
void CDevTU_Stop(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
    if(pT->pP.byState==EN_OPEN)	
	{
	if(pT->m_byStPulce==TRUE)
	{
	  pT->m_bySetPulce = pT->pP.byCSetPulce;
	  pT->m_dwJob      = pT->pP.byCSetPulce;
	  pT->m_bySetPulce = 0;
	  pT->m_byStPulce  = FALSE;
	  if(*pT->m_pbOT==FALSE)
	  {
	   *pT->m_pbOT = TRUE;
	   pT->SaveChange(pT,EV_0T1_ST,1,FALSE);
	  }else
	  if(*pT->m_pbOT==TRUE )
	  {
	   *pT->m_pbOT = FALSE;
	   pT->SaveChange(pT,EV_1T0_ST,0,FALSE);
	  } 
	 #ifdef DEB_CDevTU
	 Info("\n(%b)CTLCT::>StopPulce",&pT->m_byID);
     #endif
	}
	}
}
void CDevTU_PreparePulce(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
	if(pT->pP.byState==EN_OPEN)	
	{
	 //pT->m_bySetPulce = pT->pP.byCSetPulce;
	 pT->m_byStPulce  = TRUE;
	 if (pT->pP.byPulceType==EN_DIRECT) 
	 {
	  *pT->m_pbOT = TRUE;
	  pT->SaveChange(pT,EV_0T1_ST,1,FALSE);
	 }
	 if (pT->pP.byPulceType==EN_INVERT) 
	 {
	  *pT->m_pbOT = FALSE;
	  pT->SaveChange(pT,EV_1T0_ST,0,FALSE);
	 }
	 #ifdef DEB_CDevTU
	 Info("\n(%b)CTLCT::>SetPulce::START.",&pT->m_byID);
     #endif
	}
}
void CDevTU_SetPulce(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
    pT->m_bySetPulce = pT->pP.byCSetPulce;
	pT->m_dwJob      = pT->pP.byCSetPulce;
	pT->PreparePulce(pT);
}
void CDevTU_SetPulceEx(This,DWORD dwPulce)
{
    DECLARE_SINGLE_OPEN(CDevTU)
    pT->m_bySetPulce = dwPulce;
	pT->m_dwJob      = dwPulce;
	pT->PreparePulce(pT);
}
void CDevTU_SetPin(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
	if(pT->pP.byState==EN_OPEN)	
	{
	 //pT->m_bySetPulce = pT->pP.byCSetPulce;
	 //pT->m_byStPulce  = TRUE;
	 if (pT->pP.byPulceType==EN_DIRECT) 
	 {
	  *pT->m_pbOT = TRUE;
	  pT->SaveChange(pT,EV_0T1_ST,1,FALSE);
	 }
	 if (pT->pP.byPulceType==EN_INVERT) 
	 {
	  *pT->m_pbOT = FALSE;
	  pT->SaveChange(pT,EV_1T0_ST,0,FALSE);
	 }
	 pT->pP.sDT.byParam = *pT->m_pbOT;
	 #ifdef DEB_CDevTU
	 Info("\n(%b)CTLCT::>SetPulce::START.",&pT->m_byID);
     #endif
	}
}
void CDevTU_InvPin(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
	if(pT->pP.byState==EN_OPEN)	
	{
	 //pT->m_bySetPulce = pT->pP.byCSetPulce;
	 //pT->m_byStPulce  = TRUE;
	 if (pT->pP.byPulceType==EN_DIRECT) 
	 {
	  *pT->m_pbOT = FALSE;
	  pT->SaveChange(pT,EV_1T0_ST,0,FALSE);
	 }
	 if (pT->pP.byPulceType==EN_INVERT) 
	 {
	  *pT->m_pbOT = TRUE;
	  pT->SaveChange(pT,EV_0T1_ST,1,FALSE);
	 }
	 pT->pP.sDT.byParam = *pT->m_pbOT;
	 #ifdef DEB_CDevTU
	 Info("\n(%b)CTLCT::>InvPulce::START.",&pT->m_byID);
     #endif
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
BOOL CDevTU_SaveChange(This,BYTE byEvent,WORD wValue,BOOL blAlarm)
{
    DECLARE_SINGLE_OPEN(CDevTU)  
	SKPEVENT sEV;
    if((byEvent!=pT->m_byOldEvent)||(byEvent==EV_CHG_PR))
	{
   	 pT->m_byOldEvent = byEvent;
	 sEV.wLen         = sizeof(SKPEVENT);
     sEV.byType       = pT->m_byType;
	 sEV.byCause      = byEvent;
	 sEV.wValue       = wValue; 
	 sEV.byAddr       = pT->m_byPinID;
     if(!blAlarm)
	 pT->SendEvent(pT,&sEV);
	}
	return TRUE;
}
void CDevTU_SendEvent(This,SKPEVENT *pEV)
{
    DECLARE_SINGLE_OPEN(CDevTU)
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
DWORD CDevTU_Run(This)
{
    DECLARE_SINGLE_OPEN(CDevTU)
	DWORD dwRes=0;
	pT->PreProc(pT);
	pT->Processing(pT);
	pT->PostProc(pT);
	if ((pT->m_dwJob>=pT->m_bySetPulce)&&(pT->m_bySetPulce!=0)) dwRes = pT->m_dwJob-pT->m_bySetPulce;
	return dwRes;
}
void CDevTU_CDevTU(This)
{
    DECLARE_SINGLE_OPEN(CDevTU) 
	DECLARE_REGISTRATION(CDevTU,SetPulce)
	DECLARE_REGISTRATION(CDevTU,Stop)
	DECLARE_REGISTRATION(CDevTU,SetPulceEx)
	DECLARE_REGISTRATION(CDevTU,PreparePulce)
	DECLARE_REGISTRATION(CDevTU,SaveChange)
	DECLARE_REGISTRATION(CDevTU,SendEvent)
	DECLARE_REGISTRATION(CDevTU,SetTU)
	DECLARE_REGISTRATION(CDevTU,SetPin)
	DECLARE_REGISTRATION(CDevTU,InvPin)
	DECLARE_REGISTRATION(CDevTU,Init)
	DECLARE_REGISTRATION(CDevTU,Run)
	DECLARE_REGISTRATION(CDevTU,PreProc)
	DECLARE_REGISTRATION(CDevTU,Processing)
	DECLARE_REGISTRATION(CDevTU,PostProc)
}
void CDevTU_DCDevTU(This)
{
	DECLARE_SINGLE_OPEN(CDevTU)
}
DECLARE_SINGLE_CREATE(CDevTU)

