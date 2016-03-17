/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnroutgate.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#if MYSYSTEM_ID != 5
void COutGate_Init(This,BYTE byID,BYTE byType,BYTE byOType,BYTE byMode,REAL rMinRamp,REAL rMaxRamp,CPin *pPin,UINT wLo,UINT wHi,UINT wIni,BYTE byState,WORD wBase,WORD wOTime,SINT *pName)
{
    DECLARE_SINGLE_OPEN(COutGate)
	REAL rHL        = (REAL)(wHi-wLo);
	REAL rIP        = (REAL)wIni;
	pT->m_rMinRamp  = rMinRamp;
	pT->m_rMaxRamp  = rMaxRamp;
	pT->m_wBase     = wBase;
	pT->m_byState   = byState;
	pT->m_byGateID  = byID;
	pT->m_byType    = byType;
	pT->m_byOType   = byOType;  //BASE_GTE
	pT->m_byMode    = byMode;
	pT->m_wQTime    = SYSTEM_QTIME;
	pT->m_wLoLimit  = 0;
	pT->m_wHiLimit  = wHi-wLo;
    pT->m_wIniState = (UINT)(rHL*rIP/100.0);
	pT->m_wCurrOpenState = pT->m_wIniState;
	pT->m_dwTime    = 0;
	pT->m_pConnectionPin = pPin;
	if(pPin!=0)pT->m_pwOut = (UINT*)pPin->GetAddrPin(pPin->pChld); else
	pT->m_pwOut = &pT->m_wOut;
	pT->m_wTick     = 0;
	pT->m_wOTime = wOTime;
	if(pT->m_wOTime==0) pT->m_wOTime=1;
	pT->m_wMaxQt = (REAL)pT->m_wOTime*10;
	pT->m_wTickConst = (REAL)pT->m_wHiLimit/pT->m_wMaxQt;
    pT->m_wTickOpen  = pT->m_wTickConst; 
	pT->m_blProccState = FALSE;
	pT->m_wMinRampValue = (UINT)(rHL*pT->m_rMinRamp);
	pT->m_wMaxRampValue = (UINT)(rHL*pT->m_rMaxRamp); 
	
	strcpy(pT->m_chName,pName);
}
void COutGate_SetOutTime(This,WORD wValue)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	pT->m_wMaxQt = (REAL)wValue*10;
	if(pT->m_wMaxQt==0)return;
    pT->m_wTickConst = pT->m_wHiLimit/pT->m_wMaxQt;
	pT->m_wTickOpen  = pT->m_wTickConst; 
}
void COutGate_SetHiLimit(This,WORD wValue)
{
    DECLARE_SINGLE_OPEN(COutGate) 
    pT->m_wHiLimit = wValue;
	pT->m_wTickConst = pT->m_wHiLimit/pT->m_wMaxQt;
    pT->m_wTickOpen  = pT->m_wTickConst; 
}
//UINT _GLOBAL nmMaxRamp,nOutVal,nMinR,nMaxR,nCOpen;
//REAL _GLOBAL rgValue,rHILM,rMaxRamp;
void COutGate_SetMinRamp(This,REAL rValue)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	REAL rMaxValue = (REAL)pT->m_wHiLimit;
    pT->m_rMinRamp = rValue;
	pT->m_wMinRampValue = (UINT)(rMaxValue*pT->m_rMinRamp);
}
void COutGate_SetMaxRamp(This,REAL rValue)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	REAL rMaxValue = (REAL)pT->m_wHiLimit;
	pT->m_rMaxRamp = rValue;
	pT->m_wMaxRampValue = (UINT)(rMaxValue*pT->m_rMaxRamp);
	
	//nmMaxRamp = pT->m_wHiLimit;
	//rHILM     = rMaxValue;
	//rgValue   = rValue; 
	//rMaxRamp  = pT->m_wMaxRampValue;
}
void COutGate_OpenGate(This,REAL rOpenState)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	UINT wEndState;
	REAL rHi;
	//if(!pT->m_blProccState)
	{
	 rHi = (REAL)pT->m_wHiLimit;
	 wEndState = (UINT)(rOpenState*rHi/100.0);
	 if (wEndState==pT->m_wCurrOpenState) return;
	 pT->m_wTickOpen = pT->m_wTickConst;
	 if (wEndState < pT->m_wCurrOpenState)
     pT->m_wTickOpen = -pT->m_wTickConst;
     pT->m_wTick = (DWORD)(abs(pT->m_wCurrOpenState-wEndState)/pT->m_wTickConst);
	 pT->m_wOperGate = (REAL)pT->m_wCurrOpenState;
	 pT->m_blProccState = TRUE;
	};
}
void COutGate_OpenGateReq(This,BYTE byOpenState)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	UINT wEndState;
	REAL rHi;
	if (byOpenState<=100)
	{
	 rHi = (REAL)pT->m_wHiLimit; 
     wEndState = (UINT)((REAL)byOpenState*rHi/100.0);
	 pT->SetManGate(pT,wEndState);
	}
}
void COutGate_StopGate(This)
{
    DECLARE_SINGLE_OPEN(COutGate) 
    pT->m_blProccState = FALSE;
	pT->m_wTick = 0; 
}
void COutGate_SetGate(This,UINT wValue)
{
	DECLARE_SINGLE_OPEN(COutGate)
	//nOutVal = wValue;
	//nMinR   = pT->m_wMinRampValue;
	//nMaxR   = pT->m_wMaxRampValue;
	if (wValue<pT->m_wMinRampValue) wValue = pT->m_wMinRampValue;
	if (wValue>pT->m_wMaxRampValue) wValue = pT->m_wMaxRampValue;
	//if((wValue>=pT->m_wMinRampValue)&&(wValue<=pT->m_wMaxRampValue+20))
	//{
	pT->m_wCurrOpenState = wValue;
	//nCOpen = wValue;
    if(pT->m_byState==ST_OPEN) 
	{
	 if(pT->m_byOType==NZ) *pT->m_pwOut = pT->m_wBase+pT->m_wCurrOpenState;   
	 if(pT->m_byOType==NO) *pT->m_pwOut = pT->m_wBase+(pT->m_wHiLimit-pT->m_wCurrOpenState);   
	}
	//}
}
void COutGate_SetManGate(This,UINT wValue)
{
	DECLARE_SINGLE_OPEN(COutGate)
	pT->m_wCurrOpenState = wValue;
    if(pT->m_byState==ST_OPEN) 
	{
	 if(pT->m_byOType==NZ) *pT->m_pwOut = pT->m_wBase+pT->m_wCurrOpenState;   
	 if(pT->m_byOType==NO) *pT->m_pwOut = pT->m_wBase+(pT->m_wHiLimit-pT->m_wCurrOpenState);   
	}
}
UINT COutGate_GetGate(This)
{
	DECLARE_SINGLE_OPEN(COutGate) 
	if(pT->m_byOType==NZ)return pT->m_wBase+pT->m_wCurrOpenState;
	if(pT->m_byOType==NO)return pT->m_wBase+(pT->m_wHiLimit-pT->m_wCurrOpenState);
	return 0;
}
BYTE COutGate_GetPrcGate(This)
{
	DECLARE_SINGLE_OPEN(COutGate)
	//REAL rC = pT->m_wCurrOpenState;
	//REAL rH = pT->m_wHiLimit;
	//return (BYTE)(100.0*rC/rH);
	return (BYTE)(100.0*pT->m_wCurrOpenState/pT->m_wHiLimit);
	//return (BYTE)(100.0*pT->m_wCurrOpenState/6683.0);
}
void COutGate_RunGate(This)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	if(pT->m_blProccState)
	{
	 if(pT->m_wTick!=0) 
	 {
	  pT->m_wOperGate += pT->m_wTickOpen;
	  //Info("\n(__)Tick:%b Val:%w",&pT->m_wTick,&pT->m_wCurrOpenState.iValue);
	  pT->SetManGate(pT,(UINT)pT->m_wOperGate);
	  pT->m_wTick--;
	 }else pT->m_blProccState = FALSE;
	}
}
void COutGate_SetDefault(This)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	pT->SetGate(pT,pT->m_wIniState);
}
void COutGate_SetState(This,BYTE byState)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	if(byState==ST_INIT)pT->SetDefault(pT);
	pT->m_byState = byState;
}
void COutGate_COutGate(This)
{
    DECLARE_SINGLE_OPEN(COutGate) 
	DECLARE_REGISTRATION(COutGate,Init)
	DECLARE_REGISTRATION(COutGate,OpenGate)
    DECLARE_REGISTRATION(COutGate,SetGate)
	DECLARE_REGISTRATION(COutGate,GetGate)
	DECLARE_REGISTRATION(COutGate,RunGate)
	DECLARE_REGISTRATION(COutGate,SetDefault)
	DECLARE_REGISTRATION(COutGate,SetState)
	DECLARE_REGISTRATION(COutGate,GetPrcGate)
	DECLARE_REGISTRATION(COutGate,SetMinRamp)
	DECLARE_REGISTRATION(COutGate,SetMaxRamp)
	DECLARE_REGISTRATION(COutGate,SetHiLimit)
	DECLARE_REGISTRATION(COutGate,SetManGate)
	DECLARE_REGISTRATION(COutGate,StopGate)
	DECLARE_REGISTRATION(COutGate,SetOutTime)
	DECLARE_REGISTRATION(COutGate,OpenGateReq)
}
void COutGate_DCOutGate(This)
{
	DECLARE_SINGLE_OPEN(COutGate)
}
DECLARE_SINGLE_CREATE(COutGate)
#endif

