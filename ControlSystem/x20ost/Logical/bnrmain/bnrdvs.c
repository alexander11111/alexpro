/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrdvs.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
SINT *chDV[] = 
{
	"010.145000",
};
void CDvs_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice)
	pT->pP = (STVSPARAM*)psTable;
	pB->m_nSize = 11;
	strcpy(pT->pP->sDT.byData,chDV[0]);
    #ifdef DEB_CDvs
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CDvs_PreProc(This)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice)
	
}
_GLOBAL INT nTSCH;
void CDvs_Processing(This)
{
	DECLARE_MULTI_OPEN(CDvs,CDevice)
}
void CDvs_PostProc(This)
{
	DECLARE_MULTI_OPEN(CDvs,CDevice)
}
BYTE CDvs_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice) 
	//return pB->m_pPN->GetState(pB->m_pPN);
	return 0;
}
BOOL CDvs_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice) 
    BYTE byID = pMsg->m_sbySensor;
	BYTE byParamType = pMsg->m_sbyInfo[3];
    #ifdef DEB_CDvs
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
void CDvs_SetInPinEvent(This)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice)
}
void CDvs_SaveAlarmPin(This)
{
	DECLARE_MULTI_OPEN(CDvs,CDevice)
}
void CDvs_SendObsrveMsg(This)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice)
}
/*
typedef struct _tagTVSData 
{
BYTE byData[11];
}STVSDATA;
*/
PVOID CDvs_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice)
	memcpy(pData,&pT->pP->sDT.byData[0],11);
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CDvs_CDvs(This)
{
    DECLARE_MULTI_OPEN(CDvs,CDevice) 
	DECLARE_REGISTRATION(CDvs,CheckTS)
	DECLARE_VIRTUAL_FUNC(CDvs,EventHandler)
	DECLARE_VIRTUAL_FUNC(CDvs,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CDvs,PreProc)
	DECLARE_VIRTUAL_FUNC(CDvs,Processing)
	DECLARE_VIRTUAL_FUNC(CDvs,PostProc)
	DECLARE_VIRTUAL_FUNC(CDvs,SetInPinEvent)
	DECLARE_VIRTUAL_FUNC(CDvs,SaveAlarmPin)
	DECLARE_VIRTUAL_FUNC(CDvs,SendObsrveMsg)
	DECLARE_VIRTUAL_FUNC(CDvs,GetData)
}
void CDvs_DCDvs(This)
{
	DECLARE_MULTI_OPEN(CDvs,CDevice)
}
DECLARE_MULTI_CREATE(CDvs,CDevice)

