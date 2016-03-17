/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrtu.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CTu_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CTu,CDevice)
	CSlot *pSL;
	CPin *m_pPN0;
	BOOL *m_pbVL0;
	CComputer *pCM = pB->m_pComputer;
	pT->pP = (STUMPARAM*)psTable;
	pB->m_nSize = 1;

    //Выход запуска
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    m_pbVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTU),pT->pTU0);
	InitObject(CDevTU,pT->pTU0);
    pT->pTU0->Init(pT->pTU0,m_pbVL0,pT->pP->byID,0,EN_OPEN,pT->pP->byPulceType,pT->pP->byCSetPulce);    
	pT->pTU0->SetTU(pT->pTU0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);
    #ifdef DEB_CTu
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CTu_PreProc(This)
{
    DECLARE_MULTI_OPEN(CTu,CDevice)
    pT->pTU0->Run(pT->pTU0);	
}
_GLOBAL INT nTSCH;
void CTu_Processing(This)
{
	DECLARE_MULTI_OPEN(CTu,CDevice)
}
void CTu_PostProc(This)
{
	DECLARE_MULTI_OPEN(CTu,CDevice)
	BOOL res = FALSE;
}
BOOL CTu_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTu,CDevice) 
	SKPEVENT pEV;
    #ifdef DEB_CTu
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
					    switch (pB->m_nCD.byParam1)
					    {
						  case 0:
					           if (pB->m_nCD.wParam0==1) pT->pTU0->SetPin(pT->pTU0); else
					           if (pB->m_nCD.wParam0==0) pT->pTU0->InvPin(pT->pTU0);
						  break;
						  case 1:
							   pT->pTU0->SetPulce(pT->pTU0);
						  break;
						  default:
						  break;
					    }
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
						if ((pEV.byCause==EV_0T1_ST)&&(pEV.byAddr==0))
							pT->pP->sDT.byParam = 1;else
						if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==0))
							pT->pP->sDT.byParam = 0;
					break;
					case REG_SOFTS_ADDR:
						//Активность верхнего входа
						//if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==0))
						//{
						// pT->pP->sDT.byParam = 1;
						//} else
						//if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==0))
						//{
						// pT->pP->sDT.byParam = 0;
						//}
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
PVOID CTu_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CTu,CDevice)
	pData[0] = pT->pP->sDT.byParam;
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CTu_CTu(This)
{
    DECLARE_MULTI_OPEN(CTu,CDevice) 
	DECLARE_VIRTUAL_FUNC(CTu,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTu,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CTu,PreProc)
	DECLARE_VIRTUAL_FUNC(CTu,Processing)
	DECLARE_VIRTUAL_FUNC(CTu,PostProc)
	DECLARE_VIRTUAL_FUNC(CTu,GetData)
}
void CTu_DCTu(This)
{
	DECLARE_MULTI_OPEN(CTu,CDevice)
}
DECLARE_MULTI_CREATE(CTu,CDevice)

