/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnringate.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
void  CInputGate_Init(This,BYTE byID,UINT *pInputAddr,REAL rBaseRes,REAL rCurrRes)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	BYTE i;
	pT->m_byID     = byID;
	pT->m_pInpGate = pInputAddr;
	pT->m_rBaseRes = rBaseRes; 
	pT->m_rCurrRes = rCurrRes; 
	pT->m_rKoef = pT->m_rBaseRes/pT->m_rCurrRes;
    pT->m_blFEnable = FALSE;
	pT->m_pHiFilMask = 0xffff;
	pT->m_pInpValue = 0;
	pT->m_pInpFreeValue = 0;
	/*
	for (i=0;i<250;i++) pT->PressFilter[i] = 0;
	pT->Fnum  = 0;
	pT->FSumm = 0;
	pT->I1    = 0;
	pT->I2    = 0; 
	pT->I3    = 0;
    pT->Fval  = 0;
	*/
}
void CInputGate_SetResistance(This,REAL rCurrRes)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	if (rCurrRes==0) return;
	pT->m_rCurrRes = rCurrRes; 
	pT->m_rKoef = pT->m_rBaseRes/pT->m_rCurrRes;
}
void CInputGate_SetInput(This,UINT nValue)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	*pT->m_pInpGate = nValue;
}
UINT CInputGate_HiFilter(This,UINT nInput)
{
    DECLARE_SINGLE_OPEN(CInputGate)
	/*BYTE i;
	pT->I3 = (DINT)nInput - pT->I1;
	pT->I1 +=  pT->I3;
	if(pT->Fnum>=250)
	{
     pT->Fnum  = 0;
	 pT->FSumm = 0;
	 for(i=0;i<250;i++) pT->FSumm += pT->PressFilter[i];
	}
    pT->FSumm = pT->FSumm - pT->PressFilter[pT->Fnum] + pT->I1;
	pT->PressFilter[pT->Fnum] = pT->I1;
    pT->Fnum++;
	return (UINT)(pT->FSumm/250.0);
	*/
	return 0;
}
UINT CInputGate_GetInput(This)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	UINT nInput;
	nInput = (UINT)(REAL)(*pT->m_pInpGate)*pT->m_rKoef;
    if(nInput<ACP_MIN) nInput=ACP_MIN;
	if(nInput>ACP_MAX) nInput=ACP_MAX;
	if (pT->m_blFEnable==FALSE)return nInput; 
	else return nInput & pT->m_pHiFilMask;
}
UINT CInputGate_GetMInput(This)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	UINT nInput;
	nInput = (UINT)(REAL)(*pT->m_pInpGate)*pT->m_rKoef;
	pT->m_pInpValue = nInput;
    if(nInput<ACP_MIN)nInput=ACP_MIN;
	if(nInput>ACP_MAX)nInput=ACP_MAX;
	if (pT->m_blFEnable==FALSE)return nInput;
	else return nInput & pT->m_pHiFilMask;
}
UINT CInputGate_GetRealInput(This)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
    return pT->m_pInpValue;
}
void CInputGate_FilterEnable(This,BYTE byEnable)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	if(byEnable==0) pT->m_blFEnable = FALSE;
	if(byEnable!=0) 
	{
	  pT->m_blFEnable = TRUE;
      pT->m_pHiFilMask = ~((0xffff >> (16-byEnable))); 
	}
}
void CInputGate_CInputGate(This)
{
    DECLARE_SINGLE_OPEN(CInputGate) 
	DECLARE_REGISTRATION(CInputGate,Init)
	DECLARE_REGISTRATION(CInputGate,GetInput)
	DECLARE_REGISTRATION(CInputGate,GetRealInput)
	DECLARE_REGISTRATION(CInputGate,SetResistance)
	DECLARE_REGISTRATION(CInputGate,SetInput)
	DECLARE_REGISTRATION(CInputGate,HiFilter)
	DECLARE_REGISTRATION(CInputGate,GetMInput)
	DECLARE_REGISTRATION(CInputGate,FilterEnable)
}
void CInputGate_DCInputGate(This)
{
	DECLARE_SINGLE_OPEN(CInputGate)
}
DECLARE_SINGLE_CREATE(CInputGate)

