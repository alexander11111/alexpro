/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnraninput.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
//Analog Slot
#ifdef DEB_CAnIOSlot
SINT *chSlotType[] = 
{
	"DEV_DEFAULT_PORT",
    "DEV_PLC_CPU_260",
	"DEV_PLC_CPU_X20",
	"DEV_TCPCOM_IF_681",
	"DEV_PWCOM_PS9500",
	"DEV_COM_CS1020",
	"DEV_AI_3AI375_6",
	"DEV_AI_X20AI4622",
	"DEV_AI_X20AI2622",
	"DEV_AO_3AO775_6",
	"DEV_AO_X20AO4622",
	"DEV_DI_3DI477_6",
	"DEV_DI_X20DM9371",
	"DEV_DI_X20DI9371",
	"DEV_DI_X20DI2377",
	"DEV_DO_3DO760_6",
	"DEV_DO_X20DM9322",
	"DEV_DO_X20DO9321",
	"DEV_AT_X20AT2222"
};
#endif
_GLOBAL INT iCAnIOSlotVal; 
void CAnIOSlot_InitSlot(This,SHARDSLOT *pSlot)
{ 
	 CAnalogPin *pvPin;
	 BYTE i;
	 SHARDPIN sPin,sAlPin;
	 UINT **pInput;
	 BOOL **pAlInput;
	 DECLARE_MULTI_OPEN(CAnIOSlot,CSlot)
     #ifdef DEB_CAnIOSlot
	 Info("\n(%b)CANIN::>Create Slot:[%s]x%b.",&pSlot->bySlotNumber,chSlotType[pSlot->bySlotType],&pSlot->byPinAmout);
     #endif
	 iCAnIOSlotVal++;
	 pInput   = (UINT**)pSlot->pvPin;
	 pAlInput = (BOOL**)pSlot->pvAlmPin;
	 
	 if(pSlot->byPinAmout>0)
	 {
	  for(i=0;i<pSlot->byPinAmout;i++)
	  {
		pvPin = &pT->m_pPin[i];
		sPin.byPinNumber = i;
		sPin.byPinState  = PIN_STATE_OFF;
		sPin.pvValue     = (PVOID)pInput[i];

		sAlPin.byPinNumber = i;
		sAlPin.byPinState  = PIN_STATE_OFF;
		sAlPin.pvValue     = (PVOID)pAlInput[i];

		if(pvPin!=NULL)
		{
 		 InitObject(CAnalogPin,pvPin);
		 pvPin->pBase->SetSlot(pvPin->pBase,pB->m_bySlotNumber);
		 pvPin->pBase->Init(pvPin->pBase,&sPin,&sAlPin);
		}
	  }
	 }
}
void CAnIOSlot_Connect(This,CAnalogPin *pPin)
{
     DECLARE_MULTI_OPEN(CAnIOSlot,CSlot)
}
CPin* CAnIOSlot_GetPin(This,BYTE byNumber)
{
     DECLARE_MULTI_OPEN(CAnIOSlot,CSlot)
	 if(byNumber<pB->m_byAmPin)
     return pT->m_pPin[byNumber].pBase;
	 return NULL;
}
void CAnIOSlot_CAnIOSlot(This)
{
     DECLARE_MULTI_OPEN(CAnIOSlot,CSlot)
	 DECLARE_REGISTRATION(CAnIOSlot,Connect)
	 DECLARE_VIRTUAL_FUNC(CAnIOSlot,InitSlot)
	 DECLARE_VIRTUAL_FUNC(CAnIOSlot,GetPin)
}
void CAnIOSlot_DCAnIOSlot(This)
{
	 DECLARE_MULTI_OPEN(CAnIOSlot,CSlot)
}
DECLARE_MULTI_CREATE(CAnIOSlot,CSlot)
//Analog Slot 4
void CAnIOSlot4_InitSlot(This,SHARDSLOT *pSlot)
{ 
	 CAnalogPin *pvPin;
	 BYTE i;
	 SHARDPIN sPin,sAlPin;
	 UINT **pInput;
	 BOOL **pAlInput;
	 DECLARE_MULTI_OPEN(CAnIOSlot4,CSlot)
     #ifdef DEB_CAnIOSlot
	 Info("\n(%b)CANIN::>Create Slot:[%s]x%b.",&pSlot->bySlotNumber,chSlotType[pSlot->bySlotType],&pSlot->byPinAmout);
     #endif
	 iCAnIOSlotVal++;
	 pInput   = (UINT**)pSlot->pvPin;
	 pAlInput = (BOOL**)pSlot->pvAlmPin;
	 if(pSlot->byPinAmout>0)
	 {
	  for(i=0;i<pSlot->byPinAmout;i++)
	  {
		pvPin = &pT->m_pPin[i];
		sPin.byPinNumber = i;
		sPin.byPinState  = PIN_STATE_OFF;
		sPin.pvValue     = (PVOID)pInput[i];

		sAlPin.byPinNumber = i;
		sAlPin.byPinState  = PIN_STATE_OFF;
		sAlPin.pvValue     = (PVOID)pAlInput[i];

		if(pvPin!=NULL)
		{
 		 InitObject(CAnalogPin,pvPin);
		 pvPin->pBase->SetSlot(pvPin->pBase,pB->m_bySlotNumber);
		 pvPin->pBase->Init(pvPin->pBase,&sPin,&sAlPin);
		}
	  }
	 }
}
void CAnIOSlot4_Connect(This,CAnalogPin *pPin)
{
     DECLARE_MULTI_OPEN(CAnIOSlot4,CSlot)
}
CPin* CAnIOSlot4_GetPin(This,BYTE byNumber)
{
     DECLARE_MULTI_OPEN(CAnIOSlot4,CSlot)
	 if(byNumber<pB->m_byAmPin)
     return pT->m_pPin[byNumber].pBase;
	 return NULL;
}
void CAnIOSlot4_CAnIOSlot4(This)
{
     DECLARE_MULTI_OPEN(CAnIOSlot4,CSlot)
	 DECLARE_REGISTRATION(CAnIOSlot4,Connect)
	 DECLARE_VIRTUAL_FUNC(CAnIOSlot4,InitSlot)
	 DECLARE_VIRTUAL_FUNC(CAnIOSlot4,GetPin)
}
void CAnIOSlot4_DCAnIOSlot4(This)
{
	 DECLARE_MULTI_OPEN(CAnIOSlot4,CSlot)
}
DECLARE_MULTI_CREATE(CAnIOSlot4,CSlot)
//Digital Slot
void CDgIOSlot_InitSlot(This,SHARDSLOT *pSlot)
{ 
	 CDigitalPin *pvPin;
	 BYTE i;
	 BOOL **pInput,**pAlInput;
	 SHARDPIN sPin,sAlPin;
	 DECLARE_MULTI_OPEN(CDgIOSlot,CSlot)
	 #ifdef DEB_CDgIOSlot
     Info("\n(%b)CDGIN::>Create Slot:[%s]x%b.",&pSlot->bySlotNumber,chSlotType[pSlot->bySlotType],&pSlot->byPinAmout);
     #endif
	 pInput   = (BOOL**)pSlot->pvPin;
	 pAlInput = (BOOL**)pSlot->pvAlmPin;
	 if(pSlot->byPinAmout>0)
	 {
	  for(i=0;i<pSlot->byPinAmout;i++)
	  {
		  pvPin = &pT->m_pPin[i];
		  sPin.byPinNumber = i;
		  //sPin.byPinType   = PIN_DG_INOT_BOL;
		  sPin.byPinState  = PIN_STATE_OFF;
		  sPin.pvValue     = (PVOID)pInput[i];
		  

		  sAlPin.byPinState  = PIN_STATE_OFF;
		  sAlPin.pvValue     = (PVOID)pAlInput[i];
		  sAlPin.byPinNumber = i;
		  if(pvPin!=NULL)
		  {
		   InitObject(CDigitalPin,pvPin);
		   pvPin->pBase->SetSlot(pvPin->pBase,pB->m_bySlotNumber);
		   pvPin->pBase->Init(pvPin->pBase,&sPin,&sAlPin);
		  }
	  }
	 }
}
void CDgIOSlot_Connect(This,CDigitalPin *pPin)
{
	 DECLARE_MULTI_OPEN(CDgIOSlot,CSlot)
	 //pT->m_pPin[pPin->pBase->m_byPinNumber] = pPin;
}
CPin* CDgIOSlot_GetPin(This,BYTE byNumber)
{
	 DECLARE_MULTI_OPEN(CDgIOSlot,CSlot)
	 if(byNumber<pB->m_byAmPin)
	 return pT->m_pPin[byNumber].pBase;
	 return NULL;
}
void CDgIOSlot_CDgIOSlot(This)
{
	 DECLARE_MULTI_OPEN(CDgIOSlot,CSlot)
	 DECLARE_REGISTRATION(CDgIOSlot,Connect)
  	 DECLARE_VIRTUAL_FUNC(CDgIOSlot,InitSlot)
	 DECLARE_VIRTUAL_FUNC(CDgIOSlot,GetPin)
}
void CDgIOSlot_DCDgIOSlot(This)
{
	 DECLARE_MULTI_OPEN(CDgIOSlot,CSlot)
}
DECLARE_MULTI_CREATE(CDgIOSlot,CSlot)
//CountSlot Slot
void CCountSlot_InitSlot(This,SHARDSLOT *pSlot)
{ 
	CDCounterPin *pvPin;
	BYTE i;
	BOOL **pInput,**pAlInput;
	SHARDPIN sPin,sAlPin;
	DECLARE_MULTI_OPEN(CCountSlot,CSlot)
    #ifdef DEB_CDgIOSlot
		Info("\n(%b)CDGIN::>Create Slot:[%s]x%b.",&pSlot->bySlotNumber,chSlotType[pSlot->bySlotType],&pSlot->byPinAmout);
    #endif
	pInput   = (BOOL**)pSlot->pvPin;
	pAlInput = (BOOL**)pSlot->pvAlmPin;
	if(pSlot->byPinAmout>0)
	{
		for(i=0;i<pSlot->byPinAmout;i++)
		{
			pvPin = &pT->m_pPin[i];
			sPin.byPinNumber = i;
			//sPin.byPinType   = PIN_DG_INOT_BOL;
			sPin.byPinState  = PIN_STATE_OFF;
			sPin.pvValue     = (PVOID)pInput[i];
			
			
			sAlPin.byPinState  = PIN_STATE_OFF;
			sAlPin.pvValue     = (PVOID)pAlInput[i];
			sAlPin.byPinNumber = i;
			if(pvPin!=NULL)
			{
				InitObject(CDCounterPin,pvPin);
				pvPin->pBase->SetSlot(pvPin->pBase,pB->m_bySlotNumber);
				pvPin->pBase->Init(pvPin->pBase,&sPin,&sAlPin);
			}
		}
	}
}
void CCountSlot_Connect(This,CDCounterPin *pPin)
{
	DECLARE_MULTI_OPEN(CCountSlot,CSlot)
	//pT->m_pPin[pPin->pBase->m_byPinNumber] = pPin;
}
CPin* CCountSlot_GetPin(This,BYTE byNumber)
{
	DECLARE_MULTI_OPEN(CCountSlot,CSlot)
	if(byNumber<pB->m_byAmPin)
	return pT->m_pPin[byNumber].pBase;
	return NULL;
}
void CCountSlot_CCountSlot(This)
{
	DECLARE_MULTI_OPEN(CCountSlot,CSlot)
	DECLARE_REGISTRATION(CCountSlot,Connect)
	DECLARE_VIRTUAL_FUNC(CCountSlot,InitSlot)
	DECLARE_VIRTUAL_FUNC(CCountSlot,GetPin)
}
void CCountSlot_DCCountSlot(This)
{
	DECLARE_MULTI_OPEN(CCountSlot,CSlot)
}
DECLARE_MULTI_CREATE(CCountSlot,CSlot)
//CountSlot Slot
void CTemperatureSlot_InitSlot(This,SHARDSLOT *pSlot)
{ 
	CTemperaturePin *pvPin;
	BYTE i;
	BOOL **pInput,**pAlInput;
	SHARDPIN sPin,sAlPin;
	DECLARE_MULTI_OPEN(CTemperatureSlot,CSlot)
    #ifdef DEB_CDgIOSlot
	Info("\n(%b)CDGIN::>Create Slot:[%s]x%b.",&pSlot->bySlotNumber,chSlotType[pSlot->bySlotType],&pSlot->byPinAmout);
    #endif
	pInput   = (BOOL**)pSlot->pvPin;
	pAlInput = (BOOL**)pSlot->pvAlmPin;
	if(pSlot->byPinAmout>0)
	{
		for(i=0;i<pSlot->byPinAmout;i++)
		{
			pvPin = &pT->m_pPin[i];
			sPin.byPinNumber = i;
			//sPin.byPinType   = PIN_DG_INOT_BOL;
			sPin.byPinState  = PIN_STATE_OFF;
			sPin.pvValue     = (PVOID)pInput[i];
			
			
			sAlPin.byPinState  = PIN_STATE_OFF;
			sAlPin.pvValue     = (PVOID)pAlInput[i];
			sAlPin.byPinNumber = i;
			if(pvPin!=NULL)
			{
				InitObject(CTemperaturePin,pvPin);
				pvPin->pBase->SetSlot(pvPin->pBase,pB->m_bySlotNumber);
				pvPin->pBase->Init(pvPin->pBase,&sPin,&sAlPin);
			}
		}
	}
}
void CTemperatureSlot_Connect(This,CDCounterPin *pPin)
{
	DECLARE_MULTI_OPEN(CTemperatureSlot,CSlot)
	//pT->m_pPin[pPin->pBase->m_byPinNumber] = pPin;
}
CPin* CTemperatureSlot_GetPin(This,BYTE byNumber)
{
	DECLARE_MULTI_OPEN(CTemperatureSlot,CSlot)
	if(byNumber<pB->m_byAmPin)
	return pT->m_pPin[byNumber].pBase;
	return NULL;
}
void CTemperatureSlot_CTemperatureSlot(This)
{
	DECLARE_MULTI_OPEN(CTemperatureSlot,CSlot)
	DECLARE_REGISTRATION(CTemperatureSlot,Connect)
	DECLARE_VIRTUAL_FUNC(CTemperatureSlot,InitSlot)
	DECLARE_VIRTUAL_FUNC(CTemperatureSlot,GetPin)
}
void CTemperatureSlot_DCTemperatureSlot(This)
{
	DECLARE_MULTI_OPEN(CTemperatureSlot,CSlot)
}
DECLARE_MULTI_CREATE(CTemperatureSlot,CSlot)