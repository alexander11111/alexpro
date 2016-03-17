/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrts.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CTs_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CTs,CDevice)
	CSlot *pSL;
	CPin *m_pPN0;
	BOOL *m_pbAVL0;
	CComputer *pCM = pB->m_pComputer;
	pT->pP = (STSMPARAM*)psTable;
	pB->m_nSize = 1;
    //¬ход 
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTS),pT->pTS0);
	InitObject(CDevTS,pT->pTS0);
    pT->pTS0->Init(pT->pTS0,m_pPN0, m_pbAVL0,pT->pP->byID,0,EN_OPEN,PRI_HI,pT->pP->byCRemPulce,pT->pP->byCSetPulce,EN_AL_TO_AL);    
	pT->pTS0->SetTS(pT->pTS0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);	

    #ifdef DEB_CTs
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CTs_PreProc(This)
{
    DECLARE_MULTI_OPEN(CTs,CDevice)
	pT->pTS0->Run(pT->pTS0);	
}
_GLOBAL INT nTSCH;
void CTs_Processing(This)
{
	DECLARE_MULTI_OPEN(CTs,CDevice)
}
void CTs_PostProc(This)
{
	DECLARE_MULTI_OPEN(CTs,CDevice)
	BOOL res = FALSE;
}
BYTE CTs_CheckTS(This)
{
    DECLARE_MULTI_OPEN(CTs,CDevice) 
	//return pB->m_pPN->GetState(pB->m_pPN);
	return 0;
}
BOOL CTs_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTs,CDevice) 
	SKPEVENT pEV;
    #ifdef DEB_CTs
	//Info("\n(%b)CTLSG::>INPT::%M",&pB->m_nCD.wDeviceID,pMsg);
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
				   break;
				   case CTR_TU:
					    //if (pB->m_nCD.wParam0==1)
						//{
						// pT->pTU0->SetPin(pT->pTU0); 
						//}else
					    //if (pB->m_nCD.wParam0==0)
						//{
						// pT->pTU0->InvPin(pT->pTU0);
						//}
				   break;
				   default:
				   break;
				 }
		    break;  
			case EV_CHNG_PIN_REQ:
 				 memcpy(&pEV,&pMsg->m_sbyInfo[0],sizeof(SKPEVENT));
				 switch (pEV.byType)
				 {
				    case REG_SOFTU_ADDR:
						//if ((pEV.byCause==EV_0T1_ST)&&(pEV.byAddr==0))
						//	pT->pP->sDT.byParam = 1;else
						//if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==0))
						//	pT->pP->sDT.byParam = 0;
					break;
					case REG_SOFTS_ADDR:
						//јктивность входа
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==0))
						{
						 pT->pP->sDT.byParam = 1;
						} else
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==0))
						{
						 pT->pP->sDT.byParam = 0;
						}
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
PVOID CTs_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CTs,CDevice)
	pData[0] = pT->pP->sDT.byParam;
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CTs_CTs(This)
{
    DECLARE_MULTI_OPEN(CTs,CDevice) 
	DECLARE_VIRTUAL_FUNC(CTs,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTs,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CTs,PreProc)
	DECLARE_VIRTUAL_FUNC(CTs,Processing)
	DECLARE_VIRTUAL_FUNC(CTs,PostProc)
	DECLARE_VIRTUAL_FUNC(CTs,GetData)
}
void CTs_DCTs(This)
{
	DECLARE_MULTI_OPEN(CTs,CDevice)
}
DECLARE_MULTI_CREATE(CTs,CDevice)

