/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrpress.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CPress_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CPress,CDevice)
	CSlot *pSL;
	CPin *m_pPN0;
	BOOL *m_pbVL0;
	CComputer *pCM = pB->m_pComputer;

	pT->pP = (STPRPARAM*)psTable;
	pB->m_nSize = 2*sizeof(WORD);

	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    pT->m_pwVL0 = (WORD*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	
    #ifdef DEB_CPress
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CPress_PreProc(This)
{
    DECLARE_MULTI_OPEN(CPress,CDevice)
	pT->pP->sDT.wParam = *pT->m_pwVL0;
}
_GLOBAL INT nTSCH;
void CPress_Processing(This)
{
	DECLARE_MULTI_OPEN(CPress,CDevice)
}
void CPress_PostProc(This)
{
	DECLARE_MULTI_OPEN(CPress,CDevice)
}
BYTE CPress_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CPress,CDevice) 
    //return pB->m_pPN->GetState(pB->m_pPN);
	return 0;
}
BOOL CPress_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CPress,CDevice) 
    BYTE byID = pMsg->m_sbySensor;
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CPress
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
void CPress_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CPress,CDevice)
}
void CPress_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CPress,CDevice)
}
void CPress_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CPress,CDevice)
}
/*
typedef struct _tagTPRData
{
UINT wJob;
UINT wParam;
}SPRMDATA;
*/
PVOID CPress_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CPress,CDevice)
    pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJob,&pData[0]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wParam,&pData[2]);
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CPress_CPress(This)
{
    DECLARE_MULTI_OPEN(CPress,CDevice) 
	DECLARE_REGISTRATION(CPress,CheckTS)
	DECLARE_VIRTUAL_FUNC(CPress,EventHandler)
	DECLARE_VIRTUAL_FUNC(CPress,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CPress,PreProc)
	DECLARE_VIRTUAL_FUNC(CPress,Processing)
	DECLARE_VIRTUAL_FUNC(CPress,PostProc)
	DECLARE_VIRTUAL_FUNC(CPress,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CPress,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CPress,SendObsrveMsg)
	DECLARE_VIRTUAL_FUNC(CPress,GetData)
}
void CPress_DCPress(This)
{
	DECLARE_MULTI_OPEN(CPress,CDevice)
}
DECLARE_MULTI_CREATE(CPress,CDevice)

