/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrmeasur.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
//extern SKPPARAM nKP;
//extern SARMINTERFACE nARM0;
_GLOBAL INT nSendTmrQry;
void CMsModule_Init(This,SHARDCOMPUTERTABLE *pPCTable,SSOFTSWITCHTABLE *pMsTable)
{
    DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem) 
	FDEFINE(DEV_MSMDL_BOX_ID,1024);
    //InitObject(CMFlash,&pT->m_nFlash);
	//pT->m_pFlash = &pT->m_nFlash;
    pB->SetBoxID(pB,DEV_MSMDL_BOX_ID);

	InitObject(CMTimer,&pT->m_nOutTMR);
	pT->m_nOutTMR.SetTimer(&pT->m_nOutTMR,DIR_MSTOMS,DIR_MSTOMS,EV_TMR_OUT_REQ,0,0,DEV_MSMDL_BOX_ID);
	pT->m_nOutTMR.OnTimer(&pT->m_nOutTMR,10);

	//blSerialize = pT->Serialize(pT,FALSE); 
	pT->CreateChannels(pT,&pMsTable->sDirectionTable[0]);
	
	#ifdef DEB_CMsModule
 	Info("\n(__)CKPMD::>Create Ms Module");
    #endif
	//pT->SaveInPin(pT);
}
/*
typedef struct _tagDirectionTable
{
BYTE byDirectionID;
BYTE byDirectionCode;
BYTE byAmSwitching;
BYTE byAmTI;
BYTE byAmTS;
BYTE byAmTU;
BYTE byAmTR;

  PVOID pvIn;
  PVOID pvOut;
  PVOID pSwitchTable[DEV_AMT_SWC_IDIR]; 
}SDIRTABLE;
typedef struct _tagTTMParams
{
BYTE byAmSlot; 
BYTE byType;
STTMPARAM sTTM[4];
}STTMPARAMS;
enum _tagTeleSignal
{
TS=0,
TI,
TU,
TIS,
TC,
TPR,
TTM,
TF,
TKP,
TPU,
};
*/
void CMsModule_CreateChannels(This,SDIRTABLE *pDTable)
{
    DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem)  
	BYTE i,j,k=0;
	STTMPARAMS *pTT;
	PVOID pVV;
	CTu *pTU;
	CTs *pTS;
	CDevice *pD;
	CStGate *pTKP;
	CTemper *pTTM;
	CPunit  *pTPU;
	CPress  *pTPR;
	CFreq   *pTF;
	CCount  *pTC;
	CDvs    *pTVS;
	CLevel  *pLV;
	CObsSys *pOS;
	STOUTTBL mm;
	//UINT d=sizeof(STOUTTBL);
	pT->m_wAmChannel = pDTable->byAmTI;
	New(sizeof(CDevice*)*pT->m_wAmChannel,pT->m_pDevice);
	for (i=0;i<pT->m_wAmChannel;i++) pT->m_pDevice[i]=0;
	for(i=0;i<pDTable->byAmSwitching;i++)
	{
	 pTT = (STSPARAM*)pDTable->pSwitchTable[i];//Find Type
	 pVV = (PVOID)pTT;
	 switch (pTT->byType)
	 {
 	  case TKP:
 	 	 for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CStGate),pTKP);
		   InitObject(CStGate,pTKP);
		   pTKP->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTKP->pBase;k++; 
		   pD->Init(pD,(PVOID)&((STKPARAMS*)pVV)->sTK[j]);
		 }
 	  break;
      case TC:
		 for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CCount),pTC);
		   InitObject(CCount,pTC);
		   pTC->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTC->pBase;k++; 
		   pD->Init(pD,(PVOID)&((STCPARAMS*)pVV)->sTC[j]);
		 }
	  break;
      case TPR:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CPress),pTPR);
		   InitObject(CPress,pTPR);
		   pTPR->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTPR->pBase;k++;  
		   pD->Init(pD,(PVOID)&((STPRPARAMS*)pVV)->sTPR[j]);
		 }
	  break;
      case TTM:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CTemper),pTTM);
		   InitObject(CTemper,pTTM);
		   pTTM->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTTM->pBase;k++;  
		   pD->Init(pD,(PVOID)&((STTMPARAMS*)pVV)->sTTM[j]);
		 }
	  break;
      case TF:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CFreq),pTF);
		   InitObject(CFreq,pTF);
		   pTF->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTF->pBase;k++;  
		   pD->Init(pD,(PVOID)&((STFPARAMS*)pVV)->sTF[j]);
		 }
	  break;
      case TPU:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CPunit),pTPU);
		   InitObject(CPunit,pTPU);
		   pTPU->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTPU->pBase;k++;  
		   pD->Init(pD,(PVOID)&((SPUPARAMS*)pVV)->sTPU[j]);
		 }
	  break;
      case TU:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CTu),pTU);
		   InitObject(CTu,pTU);
		   pTU->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTU->pBase;k++;  
		   pD->Init(pD,(PVOID)&((STUMPARAMS*)pVV)->sTU[j]);
		 }
	  break;
      case TS:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CTs),pTS);
		   InitObject(CTs,pTS);
		   pTS->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTS->pBase;k++;  
		   pD->Init(pD,(PVOID)&((STSMPARAMS*)pVV)->sTS[j]);
		 }
	  break;
      case TVS:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CDvs),pTVS);
		   InitObject(CDvs,pTVS);
		   pTVS->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pTVS->pBase;k++;  
		   pD->Init(pD,(PVOID)&((STVSPARAMS*)pVV)->sTVS[j]);
		 }
	  break;
      case TLV:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CLevel),pLV);
		   InitObject(CLevel,pLV);
		   pLV->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pLV->pBase;k++;  
		   pD->Init(pD,(PVOID)&((SLVPARAMS*)pVV)->sLV[j]);
		 }
	  break;
      case TOS:
 	     for(j=0;j<pTT->byAmSlot;j++)
		 {
		   New(sizeof(CObsSys),pOS);
		   InitObject(CObsSys,pOS);
		   pOS->pF0  = pT->m_pDevice[20]->pChld;
		   pOS->pF1  = pT->m_pDevice[21]->pChld;
		   pOS->pF2  = pT->m_pDevice[22]->pChld;
		   pOS->pPU0 = pT->m_pDevice[27]->pChld;
		   pOS->pPU1 = pT->m_pDevice[28]->pChld;
		   pOS->pBase->m_pComputer = pT->m_pComputer;
		   pD = pT->m_pDevice[k] = pOS->pBase;k++;  
		   pD->Init(pD,(PVOID)&((SOBSPARAMS*)pVV)->sOS[j]);
		 }
	  break;
	 }
     //switch(pMsg->m_sbyFor)  
	}
}
BOOL CMsModule_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem) 
	CDevice *pD;
	WORD wDID;
	SINT chVS0[60],*chMS;
	REAL fVal0;
	CDvs *pVS;
	switch(pMsg->m_sbyFor)
	{
	  case DIR_MSTOMS:
		  if (pMsg->m_sbyType==EV_TMR_OUT_REQ)
		  {
			  pT->ObserveOutProc(pT);
			  pT->m_nOutTMR.OnTimer(&pT->m_nOutTMR,10);
			  //Info("\n(__)CMSMD::>EV_TMR_OUT_REQ"); 
		  }
		  if (pMsg->m_sbyType==EV_CHNG_PIN_REQ)
		  {
			  pT->HardControl(pT,pMsg);
		  }
	  break;
	  case DIR_OSYTOOSY:
           wDID = pMsg->m_sbySensor;
	       if (wDID<pT->m_wAmChannel)
		   {
			pD = pT->m_pDevice[wDID];
            if (pD!=0) pD->EventHandler(pD->pChld,pMsg);
		   }
	  break;
	  case DIR_PHTOMS:
		   switch(pMsg->m_sbyType)
		   {
		     case PH_VS0_REQ:
 				  pVS = pT->m_pDevice[45]->pChld;
				  strcpy((SINT*)&pVS->pP->sDT.byData[0],(SINT*)&pMsg->m_sbyInfo[0]);
 			  	  #ifdef DEB_CMsModule
				   fVal0 = atof(strcpy(chVS0,(SINT*)&pVS->pP->sDT.byData[0]));
				   printf("\n(0)VS0=%f",fVal0);
                  #endif
			 break;
		     case PH_VS1_REQ:
				  pVS = pT->m_pDevice[46]->pChld;
				  strcpy((SINT*)&pVS->pP->sDT.byData[0],(SINT*)&pMsg->m_sbyInfo[0]);
				  #ifdef DEB_CMsModule
				   fVal0 = atof(strcpy(chVS0,(SINT*)&pVS->pP->sDT.byData[0]));
 				   printf("\n(0)VS1=%f",fVal0);
				  #endif
			 break;
			 case PH_SCMD_REQ: 
				  pT->ScadaHandler(pT,pMsg);
			 break;
		   }
	  break;
	  default:
	  break;
	}
	return TRUE;
}
BOOL CMsModule_ScadaHandler(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem)  
	CDevice *pD;
	WORD wDID;
    #ifdef DEB_CMsModule
	Info("\n(__)CMSMM::>Scada Command:%M",pMsg);
    #endif
	pB->GetWordParam(pB,&pMsg->m_sbyInfo[0],(BYTE*)&wDID);
	if (wDID<pT->m_wAmChannel)
	{
	 pD=pT->m_pDevice[wDID];
     if (pD!=0)
	 {
	  pMsg->m_sbyFor  = DIR_MSTODV;
	  pMsg->m_sbyType = PL_DATA_IND;
      pD->SEventHandler(pD,pMsg);
	 }
	}
}
BOOL CMsModule_HardControl(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem)  
	CDevice *pD;
	WORD wDID;
    #ifdef DEB_CMsModule
	Info("\n(__)CMSMM::>Hard Command:%M",pMsg);
    #endif
    wDID = pMsg->m_sbySensor;
	if (wDID<pT->m_wAmChannel)
	{
	 pD=pT->m_pDevice[wDID];
     if (pD!=0)
	 {
	  pMsg->m_sbyFor  = DIR_MSTODV;
      pD->EventHandler(pD->pChld,pMsg);
	 }
	}
}
void CMsModule_ObserveOutProc(This)
{
    DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem)  
	SMESSAGE m_sMsg;
	CDevice *pD;
    WORD i,nLen=0;
	for (i=0;i<pT->m_wAmChannel;i++)
	{
     pD = pT->m_pDevice[i]; 
     pD->GetData(pD->pChld,&m_sMsg.m_sbyInfo[nLen],&nLen);
	}
	m_sMsg.m_swLen        = 9+nLen;
	m_sMsg.m_sbyFrom      = DIR_MSTOTCP;
	m_sMsg.m_sbyFor       = DIR_MSTOTCP;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PL_DATA_REQ;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(DEV_TCPRM_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CMsModule
	//Info("I",&m_sMsg);
	//Info("\n(__)CMSMM::>OBS::%M",&m_sMsg);
	#endif
}
_GLOBAL INT nKPC,nKPC1;
void CMsModule_CyclicProc(This)
{
    DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem)  
	CDevice *pD;
	WORD i;
	for (i=0;i<pT->m_wAmChannel;i++)
	{
     pD = pT->m_pDevice[i];
	 if (pD!=0)
	 pD->ObserveProc(pD);
	}
    //if (++nKPC1%20==0)pT->CheckSlot(pT);
}
void CMsModule_CMsModule(This)
{
    DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem) 
	DECLARE_REGISTRATION(CMsModule,Init)
	DECLARE_REGISTRATION(CMsModule,CreateChannels)
	DECLARE_REGISTRATION(CMsModule,ObserveOutProc)
	DECLARE_REGISTRATION(CMsModule,ScadaHandler)
	DECLARE_REGISTRATION(CMsModule,HardControl)
	DECLARE_VIRTUAL_FUNC(CMsModule,EventHandler)
	DECLARE_VIRTUAL_FUNC(CMsModule,CyclicProc)
}
void CMsModule_DCMsModule(This)
{
	DECLARE_MULTI_OPEN(CMsModule,CCyclicSystem)
}
DECLARE_MULTI_CREATE(CMsModule,CCyclicSystem)

