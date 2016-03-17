/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrfreq.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
/*
typedef struct _tagTFParam
{
BYTE byID;
BYTE byAmParam; 
BYTE byType;
BYTE bySlot; //Для задания
BYTE byPin;  //Для задания

  BYTE bySlot1; //Запуск
  BYTE byPin1;  //Запуск
  
	BYTE bySlot2; //Останов
	BYTE byPin2;  //Останов
	
	  BYTE bySlot3; //Авария1
	  BYTE byPin3;  //Авария1
	  
		BYTE bySlot4; //Авария2
		BYTE byPin4;  //Авария2
		STFDATA sDT;
}STFPARAM;
*/
void CFreq_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice)
	CSlot *pSL;
	CPin *m_pPN0;
	BOOL *m_pbVL0;
	BOOL *m_pbVL1;
	BOOL *m_pbAVL0;
	BOOL *m_pbAVL1;
	CComputer *pCM = pB->m_pComputer;
    pT->pP = (STFPARAM*)psTable;
	pB->m_nSize = 3*sizeof(WORD);
    //Задание
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    pT->m_pwVL0 = (WORD*)m_pPN0->GetAddrPin(m_pPN0->pChld);   

    //Выход запуска
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot1);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin1);
    m_pbVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	New(sizeof(CDevTU),pT->pTU0);
	InitObject(CDevTU,pT->pTU0);
    pT->pTU0->Init(pT->pTU0,m_pbVL0,pT->pP->byID,0,EN_OPEN,EN_DIRECT,10);    
	pT->pTU0->SetTU(pT->pTU0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);
	
	//Выход останова
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot2);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin2);
    m_pbVL1 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   

	New(sizeof(CDevTU),pT->pTU1);
	InitObject(CDevTU,pT->pTU1);
    pT->pTU1->Init(pT->pTU1,m_pbVL1,pT->pP->byID,1,EN_OPEN,EN_DIRECT,10);    
	pT->pTU1->SetTU(pT->pTU1,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);

	//Вход активности 
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot3);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin3);
    m_pbAVL0 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   

	New(sizeof(CDevTS),pT->pTS0);
	InitObject(CDevTS,pT->pTS0);
    pT->pTS0->Init(pT->pTS0,m_pPN0, m_pbAVL0,pT->pP->byID,0,EN_OPEN,PRI_HI,10,10,EN_AL_TO_AL);    
	pT->pTS0->SetTS(pT->pTS0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);

	//Вход Аварии
	pSL          = pCM->GetSlot(pCM,pT->pP->bySlot4);
	m_pPN0       = pSL->GetPin(pSL->pChld,pT->pP->byPin4);
    m_pbAVL1 = (BOOL*)m_pPN0->GetAddrPin(m_pPN0->pChld);   
	
	New(sizeof(CDevTS),pT->pTS1);
	InitObject(CDevTS,pT->pTS1);
    pT->pTS1->Init(pT->pTS1,m_pPN0, m_pbAVL1,pT->pP->byID,1,EN_OPEN,PRI_HI,10,10,EN_AL_TO_AL);    
	pT->pTS1->SetTS(pT->pTS1,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);

    #ifdef DEB_CFreq
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CFreq_PreProc(This)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice)
	pT->pTU0->Run(pT->pTU0);
	pT->pTU1->Run(pT->pTU1);
	pT->pTS0->Run(pT->pTS0);
	pT->pTS1->Run(pT->pTS1);
}
_GLOBAL INT nTSCH;
void CFreq_Processing(This)
{
	DECLARE_MULTI_OPEN(CFreq,CDevice)
}
void CFreq_PostProc(This)
{
	DECLARE_MULTI_OPEN(CFreq,CDevice)
}
/*
typedef struct _tagTFData
{
BYTE byStartST;
BYTE byStopST;
BYTE byAlST0;
BYTE byAlST1;
WORD wTask;
WORD wParam;
}STFDATA;
typedef struct _tagKpEvent
{
WORD wLen;
BYTE byType;
BYTE byAddr;
BYTE byCause;
WORD wValue;
STIME sTime;
}SKPEVENT;
*/
BOOL CFreq_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice) 
	SKPEVENT pEV;
    #ifdef DEB_CFreq
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
                        //#ifdef DEB_CFreq
	                    //Info("\n(%b)CTLSG::>CTR_TR::%d",&pB->m_nCD.wDeviceID,&pB->m_nCD.fParam0);
                        //#endif
						pT->pP->sDT.wTask = (WORD)pB->m_nCD.fParam0;
						*pT->m_pwVL0      = (WORD)pB->m_nCD.fParam0;  
				   break;
				   case CTR_TU:
					   switch (pB->m_nCD.byParam1)
					   {
					      case 0:
					         if (pB->m_nCD.wParam0==1) pT->StartFC(pT);else
					         if (pB->m_nCD.wParam0==0) pT->StopFC(pT);
						  break;
						  case 1:
							  if (pB->m_nCD.wParam0==0) 
							  {
							   pT->pP->sDT.wSt0 &= ~(0x02);
							   pT->pTU0->InvPin(pT->pTU0); 
                               pT->pTU1->SetPin(pT->pTU1); 
							  }
							  else
							  if (pB->m_nCD.wParam0==1) pT->pP->sDT.wSt0 |=  (0x02);
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
							pT->pP->sDT.wSt0 |=  (0x01);
						if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==0))
							pT->pP->sDT.wSt0 &= ~(0x01);
					break;
					case REG_SOFTS_ADDR:
						//Активность с релейного выхода
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==0))
							pT->pP->sDT.wSt0 |=  (0x04);
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==0))
							pT->pP->sDT.wSt0 &= ~(0x04);
						//Авария
						if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==1))
							pT->pP->sDT.wSt0 |=  (0x08);
						if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==1))
							pT->pP->sDT.wSt0 &= ~(0x08);
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
void CFreq_StartFC(This)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice) 
	if(pT->pP->sDT.wSt0 & 0x02)
	{
	 pT->pTU0->SetPin(pT->pTU0); 
	 pT->pTU1->InvPin(pT->pTU1); 
	}
}
void CFreq_StopFC(This)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice) 
	if(pT->pP->sDT.wSt0 & 0x02)
	{
	 pT->pTU0->InvPin(pT->pTU0); 
	 pT->pTU1->SetPin(pT->pTU1); 
	}
}
/*
typedef struct _tagTFData
{
BYTE byStartST;
BYTE byStopST;
BYTE byAlST0;
BYTE byAlST1;
WORD wTask;
WORD wParam;
}STFDATA;
*/
PVOID CFreq_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice)
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wSt0,&pData[0]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wTask,&pData[2]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wParam,&pData[4]);
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CFreq_CFreq(This)
{
    DECLARE_MULTI_OPEN(CFreq,CDevice) 
	DECLARE_REGISTRATION(CFreq,StartFC)
	DECLARE_REGISTRATION(CFreq,StopFC)
	DECLARE_VIRTUAL_FUNC(CFreq,EventHandler)
	DECLARE_VIRTUAL_FUNC(CFreq,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CFreq,PreProc)
	DECLARE_VIRTUAL_FUNC(CFreq,Processing)
	DECLARE_VIRTUAL_FUNC(CFreq,PostProc)
	DECLARE_VIRTUAL_FUNC(CFreq,GetData)
}
void CFreq_DCFreq(This)
{
	DECLARE_MULTI_OPEN(CFreq,CDevice)
}
DECLARE_MULTI_CREATE(CFreq,CDevice)

