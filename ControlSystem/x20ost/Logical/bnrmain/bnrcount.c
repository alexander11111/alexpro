/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrcount.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CCount_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CCount,CDevice)
	pT->pP = (STCPARAM*)psTable;
	pB->m_nSize = sizeof(REAL)+sizeof(DWORD);
    #ifdef DEB_CCount
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CCount_PreProc(This)
{
    DECLARE_MULTI_OPEN(CCount,CDevice)
	
}
_GLOBAL INT nTSCH;
void CCount_Processing(This)
{
	DECLARE_MULTI_OPEN(CCount,CDevice)
}
void CCount_PostProc(This)
{
	DECLARE_MULTI_OPEN(CCount,CDevice)
}
BYTE CCount_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CCount,CDevice) 
	//return pB->m_pPN->GetState(pB->m_pPN);
	return 0;
}
BOOL CCount_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CCount,CDevice) 
    #ifdef DEB_CCount
	Info("\n(%b)CTLSG::>INPT::%M",&pB->m_nCD.wDeviceID,pMsg);
    #endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_MSTODV:
		   switch(pMsg->m_sbyType)
		   {
		    case PL_DATA_IND:
				 switch(pB->m_nCD.byParam0)
				 {
				   case CTR_TR:
                        //#ifdef DEB_CCount
	                    //Info("\n(%b)CTLSG::>CTR_TR::%d",&pB->m_nCD.wDeviceID,&pB->m_nCD.fParam0);
                        //#endif
						pT->pP->sDT.fKoeff = pB->m_nCD.fParam0;
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
void CCount_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CCount,CDevice)
}
void CCount_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CCount,CDevice)
}
void CCount_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CCount,CDevice)
}
/*
typedef struct _tagTCData
{
	REAL fKoeff;
	DWORD dwParam;
}STCDATA;
*/
PVOID CCount_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CCount,CDevice)
	pB->GetRealParam(pB,(BYTE*)&pT->pP->sDT.fKoeff,pData);
	pB->GetDWordParam(pB,(BYTE*)&pT->pP->sDT.dwParam,&pData[4]);
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CCount_CCount(This)
{
    DECLARE_MULTI_OPEN(CCount,CDevice) 
	DECLARE_REGISTRATION(CCount,CheckTS)
	DECLARE_VIRTUAL_FUNC(CCount,EventHandler)
	DECLARE_VIRTUAL_FUNC(CCount,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CCount,PreProc)
	DECLARE_VIRTUAL_FUNC(CCount,Processing)
	DECLARE_VIRTUAL_FUNC(CCount,PostProc)
	DECLARE_VIRTUAL_FUNC(CCount,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CCount,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CCount,SendObsrveMsg)
	DECLARE_VIRTUAL_FUNC(CCount,GetData)
}
void CCount_DCCount(This)
{
	DECLARE_MULTI_OPEN(CCount,CDevice)
}
DECLARE_MULTI_CREATE(CCount,CDevice)

