/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrpunit.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
void CPunit_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice)
	CSlot *pSL;
	CPin *m_pPN0;
	BOOL *m_pbVL0;
	BOOL *m_pbAVL0;
	CComputer *pCM = pB->m_pComputer;
	pT->pP = (SPUPARAM*)psTable;
	pB->m_nSize = 3*sizeof(WORD);

	//Выход открытия
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    m_pbVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTU),pT->pTU0);
	InitObject(CDevTU,pT->pTU0);
    pT->pTU0->Init(pT->pTU0,m_pbVL0,pT->pP->byID,0,EN_OPEN,EN_DIRECT,10);    
	pT->pTU0->SetTU(pT->pTU0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);

	//Вход левое положение
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot1);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin1);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTS),pT->pTS0);
	InitObject(CDevTS,pT->pTS0);
    pT->pTS0->Init(pT->pTS0,m_pPN0, m_pbAVL0,pT->pP->byID,0,EN_OPEN,PRI_HI,3,3,EN_AL_TO_AL);    
	pT->pTS0->SetTS(pT->pTS0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);	
	
	//Вход среднее положение
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot2);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin2);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTS),pT->pTS1);
	InitObject(CDevTS,pT->pTS1);
    pT->pTS1->Init(pT->pTS1,m_pPN0, m_pbAVL0,pT->pP->byID,1,EN_OPEN,PRI_HI,3,3,EN_AL_TO_AL);    
	pT->pTS1->SetTS(pT->pTS1,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);	

	//Вход правое положение
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot3);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin3);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTS),pT->pTS2);
	InitObject(CDevTS,pT->pTS2);
    pT->pTS2->Init(pT->pTS2,m_pPN0, m_pbAVL0,pT->pP->byID,2,EN_OPEN,PRI_HI,3,3,EN_AL_TO_AL);    
	pT->pTS2->SetTS(pT->pTS2,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);	

    #ifdef DEB_CPunit
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CPunit_PreProc(This)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice)
	pT->pTU0->Run(pT->pTU0);
	pT->pTS0->Run(pT->pTS0);
	pT->pTS1->Run(pT->pTS1);
	pT->pTS2->Run(pT->pTS2);
}
_GLOBAL INT nTSCH;
void CPunit_Processing(This)
{
	DECLARE_MULTI_OPEN(CPunit,CDevice)
}
void CPunit_PostProc(This)
{
	DECLARE_MULTI_OPEN(CPunit,CDevice)
}
/*
typedef struct _tagPUData
{
BYTE bySt0;
BYTE bySt1;
BYTE bySt2;
WORD dwTimeConst;
WORD dwOpenTime;
}SPUDATA;
/*
*/
BOOL CPunit_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice) 
	SKPEVENT pEV;
    #ifdef DEB_CPunit
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
				   case CTR_TU:
					   switch (pB->m_nCD.byParam1)
					   {
					      case 0:
					         if (pB->m_nCD.wParam0==1) pT->StartPU(pT);else
							 if (pB->m_nCD.wParam0==0) pT->StopPU(pT);
						  break;
						  case 1:
							  if (pB->m_nCD.wParam0==0) 
							  {
								pT->pP->sDT.wSt0 &= ~(0x01);
                                pT->pTU0->InvPin(pT->pTU0); 
							  }else
							  if (pB->m_nCD.wParam0==1) pT->pP->sDT.wSt0 |=  (0x01);
						  break;
						  default:
						  break;
					   }
					    
                        //#ifdef DEB_CFreq
	                    //Info("\n(%b)CTLSG::>CTR_TR::%d",&pB->m_nCD.wDeviceID,&pB->m_nCD.fParam0);
                        //#endif
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
							pT->pP->sDT.wSt0 |=  (0x02);else
						if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==0))
							pT->pP->sDT.wSt0 &= ~(0x02);else
					break;
					case REG_SOFTS_ADDR:
						//Активность левого выхода
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==0))
							pT->pP->sDT.wSt0 |=  (0x04);else
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==0))
							pT->pP->sDT.wSt0 &= ~(0x04);else
						//Активность среднего выхода
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==1))
							pT->pP->sDT.wSt0 |=  (0x08);else
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==1))
							pT->pP->sDT.wSt0 &= ~(0x08);else
						//Активность левого выхода
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==2))
							pT->pP->sDT.wSt0 |=  (0x10);else
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==2))
							pT->pP->sDT.wSt0 &= ~(0x10);else
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
void CPunit_StartPU(This)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice) 
	if(pT->pP->sDT.wSt0 & 0x01)
	{
     pT->pTU0->SetPin(pT->pTU0); 
     #ifdef DEB_CPunit
	 Info("\n(%b)CPUNT::>OPEN PU",&pB->m_nCD.wDeviceID);
     #endif
	}
}
void CPunit_StopPU(This)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice) 
	if(pT->pP->sDT.wSt0 & 0x01)
	{
     pT->pTU0->InvPin(pT->pTU0); 
     #ifdef DEB_CPunit
	 Info("\n(%b)CPUNT::>CLOSE PU",&pB->m_nCD.wDeviceID);
     #endif
	}
}
void CPunit_ClosePU(This)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice) 
    //pT->pP->sDT.wSt0 &= ~(0x01);
    pT->pTU0->InvPin(pT->pTU0); 
    #ifdef DEB_CPunit
	Info("\n(%b)CPUNT::>STOP PU",&pB->m_nCD.wDeviceID);
    #endif
}
/*
typedef struct _tagPUData
{
BYTE bySt0;
BYTE bySt1;
BYTE bySt2;
UINT dwTimeConst;
UINT dwOpenTime;
}SPUDATA;
*/
PVOID CPunit_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice)
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wSt0,&pData[0]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.dwTimeConst,&pData[2]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.dwOpenTime,&pData[4]);	
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CPunit_CPunit(This)
{
    DECLARE_MULTI_OPEN(CPunit,CDevice) 
	DECLARE_REGISTRATION(CPunit,StartPU)
	DECLARE_REGISTRATION(CPunit,StopPU)
	DECLARE_REGISTRATION(CPunit,ClosePU)
	DECLARE_VIRTUAL_FUNC(CPunit,EventHandler)
	DECLARE_VIRTUAL_FUNC(CPunit,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CPunit,PreProc)
	DECLARE_VIRTUAL_FUNC(CPunit,Processing)
	DECLARE_VIRTUAL_FUNC(CPunit,PostProc)
	DECLARE_VIRTUAL_FUNC(CPunit,GetData)
}
void CPunit_DCPunit(This)
{
	DECLARE_MULTI_OPEN(CPunit,CDevice)
}
DECLARE_MULTI_CREATE(CPunit,CDevice)

