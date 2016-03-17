/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrpin.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#ifdef DEB_CPin
SINT *chPinState[] = 
{
	"DEF",
	"ONN",
	"OFF",
	"TRI",
};
SINT *chPinType[] = 
{
	"DEFAULT_PIN",
	"AN_INOT_INT",
	"DG_INOT_BOL",
	"ST_INPT_USI",
	"ST_OUTP_USI"
};
#endif
void CPin_Init(This,SHARDPIN*pPin,SHARDPIN *pAlPin)
{
    DECLARE_SINGLE_OPEN(CPin) 
	pT->m_pvAlmState  = pAlPin->pvValue;
	pT->m_byPinState  = pPin->byPinState;
	pT->m_byPinNumber = pPin->byPinNumber;
	pT->InitPin(pC,pPin->pvValue);
	pT->m_blPinON  = FALSE;
	pT->m_blPinOFF = FALSE;
    #ifdef DEB_CPin
	Info("\n(%b)CPINS::>Create Pin: State:[%s] Type:[%s]",&pPin->byPinNumber,chPinState[pPin->byPinState],chPinType[pPin->byPinType]);
    #endif
}

void CPin_SetSlot(This,BYTE bySlot)
{
	DECLARE_SINGLE_OPEN(CPin) 
    pT->m_bySlotNumber = bySlot;
}
PVOID CPin_GetAddrPin(This)
{
	DECLARE_SINGLE_OPEN(CPin)
	return 0;
}
BYTE CPin_GetState(This)
{
    DECLARE_SINGLE_OPEN(CPin)
	SPIN sP;
	pT->GetPin(pC,&sP);
	if(sP.blValue)
	{
	 if(pT->m_blPinON==FALSE)
	 {
	  pT->m_blPinON = TRUE;
	  pT->m_blPinOFF= FALSE;
	  return PIN_STATE_ONN;
	 }else return PIN_STATE_TRI;
	}else
	{
	 if(pT->m_blPinOFF==FALSE)
	 {
	  pT->m_blPinOFF= TRUE;
	  pT->m_blPinON = FALSE;
	  return PIN_STATE_OFF;
	 }else return PIN_STATE_TRI;
	}
} 
void CPin_GetPin(This,SPIN *sP)
{
    DECLARE_SINGLE_OPEN(CPin) 
}
void CPin_CPin(This)
{
    DECLARE_SINGLE_OPEN(CPin) 
	DECLARE_REGISTRATION(CPin,Init)	 
	DECLARE_REGISTRATION(CPin,SetSlot)
	DECLARE_REGISTRATION(CPin,GetAddrPin)
	DECLARE_REGISTRATION(CPin,GetPin)
	DECLARE_REGISTRATION(CPin,GetState)
}
void CPin_DCPin(This)
{
	DECLARE_SINGLE_OPEN(CPin)
}
DECLARE_SINGLE_CREATE(CPin)

