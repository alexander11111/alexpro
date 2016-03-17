/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrstgate.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
/*
//Управляемые краны
typedef struct _tagTKParam
{
BYTE byID;
BYTE byAmParam; 
BYTE byType;
BYTE bySlot; 
BYTE byPin; 
BYTE bySlot1; 
BYTE byPin1; 
BYTE byStOP;
BYTE byStCL;
UINT wMaxOpenTime;
UINT wOpenState;
}STKPARAM; 
*/
void CStGate_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	BOOL  *m_pbVL;
	CSlot *pSL;
	CPin  *m_pPN;
	CComputer *pCM = pB->m_pComputer;
	pT->pP         = (STKPARAM*)psTable;
	pB->m_nSize    = 3+sizeof(WORD)+2*sizeof(REAL);

    pT->m_dwOpenState = 0;
	pT->m_dwOldJob    = 0;

	//Выход Открытия
	pSL    = pCM->GetSlot(pCM,pT->pP->bySlot);
	m_pPN  = pSL->GetPin(pSL->pChld,pT->pP->byPin);
    m_pbVL = (BOOL*)m_pPN->GetAddrPin(m_pPN->pChld);   
	New(sizeof(CDevTU),pT->pTU0);
	InitObject(CDevTU,pT->pTU0);
    pT->pTU0->Init(pT->pTU0,m_pbVL,pT->pP->byID,0,EN_OPEN,EN_DIRECT,100);    
	pT->pTU0->SetTU(pT->pTU0,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);
	
	//Выход Закрытия
	pSL     = pCM->GetSlot(pCM,pT->pP->bySlot1);
	m_pPN  = pSL->GetPin(pSL->pChld,pT->pP->byPin1);
    m_pbVL = (BOOL*)m_pPN->GetAddrPin(m_pPN->pChld);   
	New(sizeof(CDevTU),pT->pTU1);
	InitObject(CDevTU,pT->pTU1);
    pT->pTU1->Init(pT->pTU1,m_pbVL,pT->pP->byID,1,EN_OPEN,EN_DIRECT,100);    
	pT->pTU1->SetTU(pT->pTU1,DEV_MSMDL_BOX_ID,DIR_MSTOMS,EV_CHNG_PIN_REQ);

    #ifdef DEB_CStGate
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
void CStGate_PreProc(This)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	pT->m_dwOpenGate  = pT->pTU0->Run(pT->pTU0);
	pT->m_dwCloseGate = pT->pTU1->Run(pT->pTU1);
}
void CStGate_Processing(This)
{
	DECLARE_MULTI_OPEN(CStGate,CDevice)
}
void CStGate_PostProc(This)
{
	DECLARE_MULTI_OPEN(CStGate,CDevice)
}
/*
typedef struct _tagTKData
{
BYTE byStOP;
BYTE byStCL;
WORD wMaxOpenTime;
REAL fJobOpen;
REAL fOpenState;
}STKDATA;
*/
BOOL CStGate_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice) 
	SKPEVENT pEV;
    #ifdef DEB_CStGate
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
							  if (pT->m_dwOpenState==0) pT->pP->sDT.wMaxOpenTime = (WORD)(pB->m_nCD.fParam0);
						  break;
						  case 1:
							  if ((pB->m_nCD.fParam0>=0.0)&&(pB->m_nCD.fParam0<=100.0))
							  {
							   pT->pP->sDT.byStMD   = 1;
							   pT->pP->sDT.fJobOpen = pB->m_nCD.fParam0;
							   pT->Open(pT,pT->pP->sDT.fJobOpen);
							  }
						  break;
						  default:
						  break;
					    }
				   break;
				   case CTR_TU:
					   if (pB->m_nCD.wParam0==1) 
					   {
						 //pT->pTU0->SetPulce(pT->pTU0); 
					   } else
					   if (pB->m_nCD.wParam0==0) 
					   {
						 //pT->pTU1->SetPulce(pT->pTU1); 
					   }
				   break;
				   case CTR_STOP:
					    pT->m_dwOpenState = pT->m_dwOldJob+pT->m_dwOpenGate-pT->m_dwCloseGate; 
						pT->pTU0->Stop(pT->pTU0);
						pT->pTU1->Stop(pT->pTU1);
                        #ifdef DEB_CStGate
	                    Info("\n(%b)CSTGT::>STOP GATE",&pB->m_nCD.wDeviceID);
                        #endif
				   break;
				   case CTR_OPEN:
					    pT->Open(pT,pB->m_nCD.fParam0);
                        #ifdef DEB_CStGate
	                    Info("\n(%b)CSTGT::>OPEN GATE",&pB->m_nCD.wDeviceID);
                        #endif
				   break;
				   case CTR_CLOSE:
						pT->Open(pT,pB->m_nCD.fParam0);
                        #ifdef DEB_CStGate
	                    Info("\n(%b)CSTGT::>CLOSE GATE",&pB->m_nCD.wDeviceID);
                        #endif
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
						//Состояние открытия  
						if ((pEV.byCause==EV_0T1_ST)&&(pEV.byAddr==0))
						{
						 pT->pP->sDT.byStOP = 1;
						 #ifdef DEB_CStGate
						 Info("\n(%b)CSTGT::>START OPEN(%d)",&pB->m_nCD.wDeviceID,&pT->m_dwPulce);
                         #endif
						} else
						if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==0))
						{
						 pT->pP->sDT.byStOP     = 0;
						 pT->pP->sDT.fOpenState = pT->PulceToPrc(pT,pT->m_dwOpenState);
						 pT->m_dwOldJob         = pT->m_dwOpenState; 
						 if (pT->pP->sDT.byStMD==1) pT->pP->sDT.byStMD = 0;
						 #ifdef DEB_CStGate
						 Info("\n(%b)CSTGT::>STOP  OPEN(%d)",&pB->m_nCD.wDeviceID,&pT->m_dwPulce);
                         #endif
						} else
                        //Состояние закрытия    
						if ((pEV.byCause==EV_0T1_ST)&&(pEV.byAddr==1))
						{
						 pT->pP->sDT.byStCL = 1;
						 #ifdef DEB_CStGate
						 Info("\n(%b)CSTGT::>START CLOSE(%d)",&pB->m_nCD.wDeviceID,&pT->m_dwPulce);
                         #endif
						} else
						if ((pEV.byCause==EV_1T0_ST)&&(pEV.byAddr==1))
						{
						 pT->pP->sDT.byStCL     = 0;
						 pT->pP->sDT.fOpenState = pT->PulceToPrc(pT,pT->m_dwOpenState);
						 pT->m_dwOldJob         = pT->m_dwOpenState; 
						 if (pT->pP->sDT.byStMD==1) pT->pP->sDT.byStMD = 0;
						 #ifdef DEB_CStGate
						 Info("\n(%b)CSTGT::>STOP  CLOSE(%d)",&pB->m_nCD.wDeviceID,&pT->m_dwPulce);
                         #endif
						}
					break;
					case REG_SOFTS_ADDR:
						//Активность с релейного выхода
						//if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==0))
						//	pT->pP->sDT.byAlST0 = 1;
						//if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==0))
						//	pT->pP->sDT.byAlST0 = 0;
						//Авария
						//if ((pEV.byCause==EV_0T1_CH)&&(pEV.byAddr==1))
						//	pT->pP->sDT.byAlST1 = 1;
						//if ((pEV.byCause==EV_1T0_CH)&&(pEV.byAddr==1))
						//	pT->pP->sDT.byAlST1 = 0;
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
void CStGate_Open(This,REAL fOpenPrc)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	DWORD dwPulce = pT->PrcToPulce(pT,fOpenPrc);
	BOOL  blDir   = pT->GetOpenDir(pT,dwPulce); 
	DWORD nOPulce = pT->GetOpenPulce(pT,blDir,dwPulce); 
	pT->m_dwPulce = nOPulce; //для отладки
	if (pT->m_dwOpenState==dwPulce) return;
	pT->m_dwOpenState = dwPulce; 
	pT->OpenGate(pT,blDir,nOPulce);
}
DWORD CStGate_PrcToPulce(This,REAL fOpenPrc)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	REAL fTime     = (REAL)(1000*pT->pP->sDT.wMaxOpenTime);
	REAL fOpen     = (REAL)(fOpenPrc/100.0);
	REAL fSysQuant = (REAL)SYSTEM_QTIME;
    DWORD dwPulce  = (DWORD)(fTime*fOpen/fSysQuant);
    return dwPulce;
}
REAL CStGate_PulceToPrc(This,DWORD dwPulce)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	REAL fTime     = (REAL)(1000*pT->pP->sDT.wMaxOpenTime);
	REAL fSysQuant = (REAL)SYSTEM_QTIME;
	REAL fPulce    = (REAL)dwPulce;
	REAL fOpen     = (REAL)(100.0*fPulce/(fTime/fSysQuant));
    return fOpen;
}
DWORD CStGate_SecToPulce(This,WORD wOpenTime)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	REAL fTime     = (REAL)(1000*wOpenTime);
	REAL fSysQuant = (REAL)SYSTEM_QTIME;
    DWORD dwPulce  = (DWORD)(fTime/fSysQuant);
    return dwPulce;
}
BOOL CStGate_GetOpenDir(This,DWORD dwPulce)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	BOOL res = FALSE;
    if (dwPulce>=pT->m_dwOpenState) res = TRUE; else
    if (dwPulce<pT->m_dwOpenState)  res = FALSE;
	return res;	
}
DWORD CStGate_GetOpenPulce(This,BOOL blDir,DWORD dwOpenPulce)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	DWORD dwPulce=0;
	if (blDir==TRUE) 
     dwPulce = (dwOpenPulce-pT->m_dwOpenState); else
	if (blDir==FALSE) 
	 dwPulce = (pT->m_dwOpenState-dwOpenPulce);
    return dwPulce;
}
void CStGate_OpenGate(This,BOOL blDir,DWORD dwOpenPulce)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	if (blDir==TRUE) 
  	 pT->pTU0->SetPulceEx(pT->pTU0,dwOpenPulce); 
	if (blDir==FALSE) 
	 pT->pTU1->SetPulceEx(pT->pTU1,dwOpenPulce); 
}
/*
typedef struct _tagTKData
{
	BYTE byStOP;
	BYTE byStCL;
    WORD wMaxOpenTime;
    REAL fJobOpen;
    REAL fOpenState;
}STKDATA;
*/
PVOID CStGate_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice)
	pData[0] = pT->pP->sDT.byStOP;
	pData[1] = pT->pP->sDT.byStCL;
	pData[2] = pT->pP->sDT.byStMD;
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wMaxOpenTime,&pData[3]);
	pB->GetRealParam(pB,(BYTE*)&pT->pP->sDT.fJobOpen,&pData[5]);	
	pB->GetRealParam(pB,(BYTE*)&pT->pP->sDT.fOpenState,&pData[9]);	
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	pT->pP->sDT.fOpenState = pT->PulceToPrc(pT,pT->m_dwOldJob+pT->m_dwOpenGate-pT->m_dwCloseGate);
	return pData;
}
void CStGate_CStGate(This)
{
    DECLARE_MULTI_OPEN(CStGate,CDevice) 
	DECLARE_REGISTRATION(CStGate,Open)
	DECLARE_REGISTRATION(CStGate,PrcToPulce)
	DECLARE_REGISTRATION(CStGate,PulceToPrc)
	DECLARE_REGISTRATION(CStGate,SecToPulce)
	DECLARE_REGISTRATION(CStGate,GetOpenDir)
	DECLARE_REGISTRATION(CStGate,GetOpenPulce)
	DECLARE_REGISTRATION(CStGate,OpenGate)
	DECLARE_VIRTUAL_FUNC(CStGate,EventHandler)
	DECLARE_VIRTUAL_FUNC(CStGate,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CStGate,PreProc)
	DECLARE_VIRTUAL_FUNC(CStGate,Processing)
	DECLARE_VIRTUAL_FUNC(CStGate,PostProc)
	DECLARE_VIRTUAL_FUNC(CStGate,GetData)
}
void CStGate_DCStGate(This)
{
	DECLARE_MULTI_OPEN(CStGate,CDevice)
}
DECLARE_MULTI_CREATE(CStGate,CDevice)

