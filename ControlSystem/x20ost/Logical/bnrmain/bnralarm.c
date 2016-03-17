/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrtmcounter.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CTmCounter_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice)
    pT->pP = (STMPARAM*)psTable;
	pB->m_nSize = 2*sizeof(WORD);
    #ifdef DEB_CTmCounter
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CTmCounter_PreProc(This)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice)
	
}
_GLOBAL INT nTSCH;
void CTmCounter_Processing(This)
{
	DECLARE_MULTI_OPEN(CTmCounter,CDevice)
}
void CTmCounter_PostProc(This)
{
	DECLARE_MULTI_OPEN(CTmCounter,CDevice)
	BOOL res = FALSE;
}
BYTE CTmCounter_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice) 
    //return pB->m_pPN->GetState(pB->m_pPN);
	return 0;
}
BOOL CTmCounter_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice) 
    BYTE byID = pMsg->m_sbySensor;
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CTmCounter
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
void CTmCounter_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice)
}
void CTmCounter_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CTmCounter,CDevice)
}
void CTmCounter_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice)
}
/*
typedef struct _tagTTMData
{
UINT wJob;
UINT wParam;
}STTMDATA;
*/
PVOID CTmCounter_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice)
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJob,&pData[0]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wParam,&pData[2]);	
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CTmCounter_CTmCounter(This)
{
    DECLARE_MULTI_OPEN(CTmCounter,CDevice) 
	DECLARE_REGISTRATION(CTmCounter,CheckTS)
	DECLARE_VIRTUAL_FUNC(CTmCounter,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTmCounter,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CTmCounter,PreProc)
	DECLARE_VIRTUAL_FUNC(CTmCounter,Processing)
	DECLARE_VIRTUAL_FUNC(CTmCounter,PostProc)
	DECLARE_VIRTUAL_FUNC(CTmCounter,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CTmCounter,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CTmCounter,SendObsrveMsg)
	DECLARE_VIRTUAL_FUNC(CTmCounter,GetData)
}
void CTmCounter_DCTmCounter(This)
{
	DECLARE_MULTI_OPEN(CTmCounter,CDevice)
}
DECLARE_MULTI_CREATE(CTmCounter,CDevice)

