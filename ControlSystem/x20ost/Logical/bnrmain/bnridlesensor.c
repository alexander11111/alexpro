/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnridlesensor.h"
#if MYSYSTEM_ID != 5
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
extern SINT *chSensType[];
extern SINT *chParType[];
void CIdleSensor_InitSensor(This,PVOID pvParam)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	SNSPARAMTABLE *pParam = (SNSPARAMTABLE*)pvParam;
	pT->SetState(pT,TRUE);
    #ifdef DEB_CIdleSensor
	Info("\n(%b)CISNS::>Create SNS.:%s.:%s.Rng:[%w..%w].AlarmRng:[%w..%w]",
    &pB->m_bySensorID,
    chSensType[pB->m_bySensorType],
	chParType[pB->m_byParamType],
	&pB->m_iLoLimit,&pB->m_iHiLimit,
	&pB->m_iLoAlmLimit,&pB->m_iHiAlmLimit
	);
	#endif
}
void CIdleSensor_IncInput(This,INT16 wParam)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[0];
	pG0->SetGate(pG0,pB->m_nInPin);
	pB->m_nInPin += wParam;
	//Info("\n(%b)CIDSN::>DC(%b,%b)PR_INC::%w.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,&pB->m_sInPin.iValue);
}
void CIdleSensor_SetInput(This,SPIN *pValue)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[0];
	pB->m_nInPin = pValue->iValue;
	pG0->SetGate(pG0,pB->m_nInPin);
	//Info("\n(%b)CIDSN::>DC(%b,%b)PR_X::%w.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,&pB->m_sInPin.iValue);
}
void CIdleSensor_SetOutput(This,BYTE byNumber,SPIN *pValue)
{
	DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[byNumber];
	pB->m_nOutPin = pValue->iValue;
	if(pG0)pG0->SetGate(pG0,pB->m_nOutPin);
}
void CIdleSensor_PreProc(This)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	pB->m_nInPin = pB->m_nInp->GetInput(pB->m_nInp);
}
void CIdleSensor_Processing(This)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
}
void CIdleSensor_PostProc(This)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
}
void CIdleSensor_CaptureData(This)
{
	DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	INT16 wValue = 0;
	INT16 wValue1 = 0;
	COutGate *pG0 = pB->m_pOutGate[0];
	COutGate *pG1 = pB->m_pOutGate[1];
	if(pG0)wValue  = pG0->GetGate(pG0);
	if(pG1)wValue1 = pG1->GetGate(pG1);
	pB->OpenGate(pB);
	pB->AddData(pB,(DINT)pB->m_nInPin);
	pB->AddData(pB,(DINT)wValue1);
	pB->AddData(pB,(DINT)wValue);
	pB->AddData(pB,0);
	pB->AddData(pB,0);
	pB->AddData(pB,0);
	pB->AddData(pB,0);
	pB->CloseGate(pB);
}
BOOL CIdleSensor_GetState(This)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	return pT->m_blState;
}
void CIdleSensor_SetState(This,BOOL blBool)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	pT->m_blState = blBool;
}
void CIdleSensor_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	SPIN nPin;
	REAL rlParam;
	BYTE byLen,byInitType,byPType,byPLen,*pR=(BYTE*)&rlParam;
	switch(pMsg->m_sbyType)
	{
	  case EV_SMSNS_SET_PARAM_REQ:
		 byLen      = pMsg->m_sbyInfo[0];
		 byInitType = pMsg->m_sbyInfo[1];
		 byPType    = pMsg->m_sbyInfo[2];
		 byPLen     = pMsg->m_sbyInfo[3];
         #ifdef DEB_CIdleSensor
		 Info("\n(%b)CIDSN::>DC(%b,%b)SSP:%M.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,(BYTE*)pMsg);
         #endif
		 if(byInitType==SNS_SENS_INI)
		 {
		  if(byPType==PR_X)
		  {
			nPin.iValue = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);
    		pT->SetInput(pT,&nPin);
		  }
		 }
	  break;
	  default:
	  break;
	};
}
void CIdleSensor_CIdleSensor(This)
{
    DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	DECLARE_REGISTRATION(CIdleSensor,SetState)
	DECLARE_REGISTRATION(CIdleSensor,GetState)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,EventHandler)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,SetInput)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,SetOutput)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,InitSensor)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,PreProc)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,Processing)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,PostProc)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,IncInput)
	DECLARE_VIRTUAL_FUNC(CIdleSensor,CaptureData)
}
void CIdleSensor_DCIdleSensor(This)
{
	DECLARE_MULTI_OPEN(CIdleSensor,CSensor)
	DestroyObjectB(CSensor,pB);
}
DECLARE_MULTI_CREATE(CIdleSensor,CSensor)
#endif
