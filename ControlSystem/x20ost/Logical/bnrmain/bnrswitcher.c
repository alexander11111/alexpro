/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrswitcher.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CSwitcher_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice)
    pT->pP = (SPLPARAM*)psTable;
	pB->m_nSize = 1;
    #ifdef DEB_CSwitcher
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CSwitcher_PreProc(This)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice)
	
}
_GLOBAL INT nTSCH;
void CSwitcher_Processing(This)
{
	DECLARE_MULTI_OPEN(CSwitcher,CDevice)
}
void CSwitcher_PostProc(This)
{
	DECLARE_MULTI_OPEN(CSwitcher,CDevice)
	BOOL res = FALSE;
}
BYTE CSwitcher_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice) 
    //return pB->m_pPN->GetState(pB->m_pPN);
	return 0;
}
BOOL CSwitcher_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice) 
    BYTE byID = pMsg->m_sbySensor;
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CSwitcher
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
void CSwitcher_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice)
}
void CSwitcher_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CSwitcher,CDevice)
}
void CSwitcher_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice)
}
/*
typedef struct _tagTTMData
{
UINT wJob;
UINT wParam;
}STTMDATA;
*/
PVOID CSwitcher_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice)
    pData[0] = pT->pP->sDT.byParam;
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CSwitcher_CSwitcher(This)
{
    DECLARE_MULTI_OPEN(CSwitcher,CDevice) 
	DECLARE_REGISTRATION(CSwitcher,CheckTS)
	DECLARE_VIRTUAL_FUNC(CSwitcher,EventHandler)
	DECLARE_VIRTUAL_FUNC(CSwitcher,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CSwitcher,PreProc)
	DECLARE_VIRTUAL_FUNC(CSwitcher,Processing)
	DECLARE_VIRTUAL_FUNC(CSwitcher,PostProc)
	DECLARE_VIRTUAL_FUNC(CSwitcher,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CSwitcher,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CSwitcher,SendObsrveMsg)
	DECLARE_VIRTUAL_FUNC(CSwitcher,GetData)
}
void CSwitcher_DCSwitcher(This)
{
	DECLARE_MULTI_OPEN(CSwitcher,CDevice)
}
DECLARE_MULTI_CREATE(CSwitcher,CDevice)

