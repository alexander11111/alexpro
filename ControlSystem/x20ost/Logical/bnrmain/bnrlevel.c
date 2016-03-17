/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrlevel.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CLevel_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CLevel,CDevice)
	CSlot *pSL;
	CPin *m_pPN0;
	BOOL *m_pbAVL0;
	CComputer *pCM = pB->m_pComputer;

    pT->pP = (SLVPARAM*)psTable;
	pB->m_nSize = 4*sizeof(WORD);

    //¬ход нижнее положение
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTS),pT->pTS0);
	InitObject(CDevTS,pT->pTS0);
    pT->pTS0->Init(pT->pTS0,m_pPN0, m_pbAVL0,pT->pP->byID,0,EN_OPEN,PRI_HI,3,3,EN_AL_TO_AL);    
	pT->pTS0->SetTS(pT->pTS0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);	
	
	//¬ход верхнее положение
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot1);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin1);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTS),pT->pTS1);
	InitObject(CDevTS,pT->pTS1);
    pT->pTS1->Init(pT->pTS1,m_pPN0, m_pbAVL0,pT->pP->byID,1,EN_OPEN,PRI_HI,3,3,EN_AL_TO_AL);    
	pT->pTS1->SetTS(pT->pTS1,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);	
    #ifdef DEB_CLevel
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CLevel_PreProc(This)
{
    DECLARE_MULTI_OPEN(CLevel,CDevice)
	pT->pTS0->Run(pT->pTS0);
	pT->pTS1->Run(pT->pTS1);	
}
_GLOBAL INT nTSCH;
void CLevel_Processing(This)
{
	DECLARE_MULTI_OPEN(CLevel,CDevice)
}
void CLevel_PostProc(This)
{
	DECLARE_MULTI_OPEN(CLevel,CDevice)
	BOOL res = FALSE;
}
/*
typedef struct _tagLVData
{
WORD wSt0; 
WORD wJob0;
WORD wJob1;
WORD wParam;
}SLVDATA;
*/
BOOL CLevel_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CLevel,CDevice) 
	SKPEVENT pEV;
    #ifdef DEB_CLevel
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
					    switch (pB->m_nCD.byParam1)
					    {
						  case 0: 
							  if ((WORD)pB->m_nCD.fParam0>pT->pP->sDT.wJob1) 
							  pT->pP->sDT.wJob0 = (WORD)(pB->m_nCD.fParam0);
						  break;
						  case 1:
							  if ((WORD)pB->m_nCD.fParam0<pT->pP->sDT.wJob0)  
							  pT->pP->sDT.wJob1 = (WORD)(pB->m_nCD.fParam0);
						  break;
						  default:
						  break;
					    }
				   break;
				   case CTR_TU:
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
						//	pT->pP->sDT.wSt0 |=  (0x02);else
						//if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==0))
						//	pT->pP->sDT.wSt0 &= ~(0x02);else
					break;
					case REG_SOFTS_ADDR:
						//јктивность верхнего входа
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==0))
						{
						 pT->pP->sDT.wSt0 |=  (0x01);
						 pT->pP->sDT.wParam = pT->pP->sDT.wJob0; 
						} else
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==0))
						{
						 pT->pP->sDT.wSt0 &= ~(0x01);
						 pT->pP->sDT.wParam = pT->pP->sDT.wJob1; 
                         if (!(pT->pP->sDT.wSt0 & 0x02)) pT->pP->sDT.wParam = 0; 
						} else
						//јктивность нижнего входа
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==1))
						{
					  	 pT->pP->sDT.wSt0 |=  (0x02);
						 if (!(pT->pP->sDT.wSt0 & 0x01)) pT->pP->sDT.wParam = pT->pP->sDT.wJob1; 
						} else
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==1))
						{
 						 pT->pP->sDT.wSt0 &= ~(0x02);
						 if (!(pT->pP->sDT.wSt0 & 0x01)) pT->pP->sDT.wParam = 0; 
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
/*
typedef struct _tagLVData
{
UINT wParam;
}SLVDATA;
*/
PVOID CLevel_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CLevel,CDevice)
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wSt0,&pData[0]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJob0,&pData[2]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJob1,&pData[4]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wParam,&pData[6]);
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CLevel_CLevel(This)
{
    DECLARE_MULTI_OPEN(CLevel,CDevice) 
	DECLARE_VIRTUAL_FUNC(CLevel,EventHandler)
	DECLARE_VIRTUAL_FUNC(CLevel,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CLevel,PreProc)
	DECLARE_VIRTUAL_FUNC(CLevel,Processing)
	DECLARE_VIRTUAL_FUNC(CLevel,PostProc)
	DECLARE_VIRTUAL_FUNC(CLevel,GetData)
}
void CLevel_DCLevel(This)
{
	DECLARE_MULTI_OPEN(CLevel,CDevice)
}
DECLARE_MULTI_CREATE(CLevel,CDevice)

