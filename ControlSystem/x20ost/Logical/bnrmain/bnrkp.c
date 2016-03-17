/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrkp.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
extern SKPPARAM nKP;
extern SARMINTERFACE nARM0;
extern STIPARAMS nTI;
extern STSPARAMS nTS;
extern STUPARAMS nTU;
extern char *STTS[];
_GLOBAL INT nSendTmrQry;
void CKpModule_Init(This,SHARDCOMPUTERTABLE *pPCTable,SSOFTSWITCHTABLE *pKPTable)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	BOOL blSerialize;
	//pT->m_byKpID = pKPTable->sDirectionTable[0].byDirectionID;
	FDEFINE(DEV_KPMDL_BOX_ID,DEV_KPMDL_BOX_SZ);
    FDEFINE(BOX_L4,BOX_L4_SZ);
	FDEFINE(BOX_L4_1,BOX_L4_1_SZ);
	nSendTmrQry = 0;
    InitObject(CMFlash,&pT->m_nFlash);
	pT->m_pFlash = &pT->m_nFlash;
    pB->SetBoxID(pB,DEV_KPMDL_BOX_ID);
	pT->m_pPCT   = pPCTable;
	pT->m_pPST   = pKPTable;
	pT->m_pKP    = pPCTable->pKpParam;
	pT->m_byKpID = pT->m_pKP->byKpID;
	pT->m_pD     = &pT->m_pPST->sDirectionTable[0];
	pT->m_wCallTime = pT->m_pKP->byCallPeriod*10;
	pT->m_blDiscStart = FALSE;
	pT->m_byDiscProc  = 0;

	pT->m_byObsObject = 0;
	pT->m_byObsTime   = 0;
	pT->m_blIfConnect = TRUE; 


    pT->m_byKpState    = MKP_NULL_ST00; 	
	//pT->m_byConnCT = 0;
	pT->m_blBufferST = TRUE; 
	InitObject(CMTimer,&pT->m_nConnTMR);
	pT->m_nConnTMR.SetTimer(&pT->m_nConnTMR,DIR_KPTOKP,DIR_KPTOKP,EV_TMR_SRR_REQ,0,0,DEV_KPMDL_BOX_ID);
	
	InitObject(CMTimer,&pT->m_nRepConnTMR);
	pT->m_nRepConnTMR.SetTimer(&pT->m_nRepConnTMR,DIR_KPTOKP,DIR_KPTOKP,EV_TMR_RCAL_REQ,0,0,DEV_KPMDL_BOX_ID);

	InitObject(CMTimer,&pT->m_nDiscTMR);
	pT->m_nDiscTMR.SetTimer(&pT->m_nDiscTMR,DIR_KPTOKP,DIR_KPTOKP,EV_TMR_DISC_REQ,0,0,DEV_KPMDL_BOX_ID);

	InitObject(CMTimer,&pT->m_pResetTimer);
 	pT->m_pResetTimer.SetTimer(&pT->m_pResetTimer,DIR_KPTOKP,DIR_KPTOKP,EV_SYSTM_RESET_TIM_BRD_IND,0,0,DEV_KPMDL_BOX_ID);

	InitObject(CMTimer,&pT->m_nConnRepTMP);
	pT->m_nConnRepTMP.SetTimer(&pT->m_nConnRepTMP,DIR_KPTOKP,DIR_KPTOKP,EV_TMR_CNRP_REQ,0,0,DEV_KPMDL_BOX_ID);

	InitObject(CMTimer,&pT->m_nPuCommTMR);
	pT->m_nPuCommTMR.SetTimer(&pT->m_nPuCommTMR,DIR_KPTOKP,DIR_KPTOKP,EV_TMR_PUCM_REQ,0,0,DEV_KPMDL_BOX_ID);

	InitObject(CMTimer,&pT->m_nSDiscTMR);
	pT->m_nSDiscTMR.SetTimer(&pT->m_nSDiscTMR,DIR_KPTOKP,DIR_KPTOKP,EV_TMR_SDIS_REQ,0,0,DEV_KPMDL_BOX_ID);

	blSerialize = pT->Serialize(pT,FALSE); 
	pT->CreateChannels(pT,&pKPTable->sDirectionTable[0]);
	
	#ifdef DEB_CKpModule
 	Info("\n(__)CKPMD::>Create Kp Module");
    #endif
	//pT->SaveInPin(pT);
}
_GLOBAL BYTE nTUU; 
void CKpModule_CreateChannels(This,SDIRTABLE *pDTable)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	WORD i;
	CTeleInd *pTI;
	CTeleSignal *pTS;
	CTeleControl *pTU;
	STSPARAM *pPV;
	pT->m_wAmChannel = pDTable->byAmSwitching;
	New(sizeof(CTeleSensor*)*pT->m_wAmChannel,pT->m_pTeleSensor);
	for(i=0;i<pT->m_wAmChannel;i++)
	{
	 pPV = (STSPARAM*)pDTable->pSwitchTable[i];//Find Type
	 switch (pPV->byType)
	 {
	   case TI:
		    New(sizeof(CTeleInd),pTI);
			InitObject(CTeleInd,pTI);
			pTI->pBase->m_pComputer = pT->m_pComputer;
			pT->m_pTeleSensor[i]    = pTI->pBase; 
			pTI->pBase->m_pPCT      = pT->m_pPCT; 
			pTI->pBase->Init(pTI->pBase,(PVOID)pPV);
	   break;
	   case TS:
		    New(sizeof(CTeleSignal),pTS);
			InitObject(CTeleSignal,pTS);
			pTS->pBase->m_pComputer = pT->m_pComputer;
		    pT->m_pTeleSensor[i]    = pTS->pBase; 
			pTS->pBase->m_pPCT      = pT->m_pPCT;
			pTS->pBase->Init(pTS->pBase,(PVOID)pPV);
	   break;
	   case TU:
		    New(sizeof(CTeleControl),pTU);
			InitObject(CTeleControl,pTU);
			pTU->pBase->m_pComputer = pT->m_pComputer;
		    pT->m_pTeleSensor[i]    = pTU->pBase; 
			pTU->pBase->m_pPCT      = pT->m_pPCT;
			pTU->pBase->Init(pTU->pBase,(PVOID)pPV);
	   break;
	   default:
	   break;
	 }
	}
}
/*
REG_KPPAR_ADDR=0,
REG_PORTT_ADDR,
REG_HARDT_ADDR,
REG_SOFTI_ADDR,
REG_SOFTS_ADDR,
REG_SOFTU_ADDR,
REG_SOFTR_ADDR,
*/
BOOL CKpModule_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	CTeleSensor *pTS;
	WORD wValue = 0;
	BYTE byID;
	BYTE byA0   = pMsg->m_sbyInfo[1];
	BYTE byA1   = pMsg->m_sbyInfo[2];
	BYTE byA2   = pMsg->m_sbyInfo[3];
	BYTE byLen  = pMsg->m_sbyInfo[0];
	WORD wParam;
	#ifdef DEB_CKpModule
	Info("\n(__)CKPMM::>INPT::%M",pMsg);
	#endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_101TOKP:
		   switch(pMsg->m_sbyType)
		   {
		    case PL_DATA_IND:
				 switch(byA0)
				 {
				   case REG_KPPAR_ADDR:
					    if ((byA1 == CKP_SETT_TIME)||(byA1 == CKP_SETT_KPID)) 
						{   
						    if (byA1 == CKP_SETT_TIME) SetBoardTime(&pMsg->m_sbyInfo[4]);
							pT->m_nPuCommTMR.OfTimer(&pT->m_nPuCommTMR);
							pT->m_nConnTMR.OfTimer(&pT->m_nConnTMR);
							pT->m_nConnRepTMP.OfTimer(&pT->m_nConnRepTMP);
							//pT->m_nRepConnTMR.OfTimer(&pT->m_nRepConnTMR);
							//pT->m_blIfConnect = FALSE;
							#ifdef DEB_CKpModule
	    					Info("\n(__)CKPMM::>PU TIMER OFF");
							#endif
						}
				   	    if (byA1 == CKP_CLSE_PORT) SendSMessage(DEV_RSMMD_BOX_ID,DIR_KPTOPH,PH_CLOSE_PORT_REQ);
						if (byA1 == CKP_SAVE_SETT) {pT->m_nCT.byDefSett = 0;pT->Serialize(pT,TRUE);} 
						if (byA1 == CKP_REST_BORD) pT->m_pResetTimer.OnTimer(&pT->m_pResetTimer,100);
						if (byA1 == CKP_REST_12BR)
						{
						 memcpy(&wParam,&pMsg->m_sbyInfo[5],2);
						 pT->m_nCT.byDefSett = (BYTE)wParam;
				         pT->Serialize(pT,TRUE);
						 pT->m_pResetTimer.OnTimer(&pT->m_pResetTimer,100);
						}
						if (byA1 == CKP_STOP_REST) pT->m_pResetTimer.OfTimer(&pT->m_pResetTimer);
						if (byA1 == CKP_FREE_BXL4) FFREE(BOX_L4);
						if (byA1 == CKP_SETT_BL41) pT->SaveInPin(pT);
						if (byA1 == CKP_REMT_DISC) pT->m_nSDiscTMR.OnTimer(&pT->m_nSDiscTMR,30);
						if (byA1 == CKP_SVAL_PINS) pT->SaveAlarmPin(pT);
						if (byA1 == CKP_SVAL_SLOT) pT->SaveSlotState(pT);
						if (byA1 == CKP_STRT_CHTM) 
						{
							#ifdef WIN32
							pT->m_byObsObject = pMsg->m_sbyInfo[5];
							pT->m_byObsTime   = pMsg->m_sbyInfo[6]*10;
							#else
							pT->m_byObsObject = pMsg->m_sbyInfo[6];
							pT->m_byObsTime   = pMsg->m_sbyInfo[5]*10;
							#endif
							pT->StartCheck(pT,pT->m_byObsTime,pT->m_byObsObject);
						}
						if (byA1 == CKP_STOP_CHTM) pT->StopCheck(pT);
						if (byA1 == CKP_INIT_PORT) SendSMessage(DEV_RSMMD_BOX_ID,DIR_KPTOPH,PH_INIT_PORT_REQ);
						

						
				   break;
				   case REG_PORTT_ADDR:
				   break;
				   case REG_HARDT_ADDR:
				   break;
				   case REG_SOFTI_ADDR:
					    byID = byA1;
						if(byA1<pT->m_pD->byAmTI)
						{
					   	 pTS = pT->m_pTeleSensor[byID];
						 if((byA2==3)||(byA2==4)) pTS->Switch(pTS);
						 pTS->EventHandler(pTS->pChld,pMsg);
						}
				   break;
				   case REG_SOFTS_ADDR:
					    byID = byA1+pT->m_pD->byAmTI;
						if(byA1<pT->m_pD->byAmTS)
						{
					     pTS = pT->m_pTeleSensor[byID];
						 if((byA2==3)||(byA2==4)) pTS->Switch(pTS);
					     pTS->EventHandler(pTS->pChld,pMsg);
						}
				   break;
				   case REG_SOFTU_ADDR:
					    byID = byA1+pT->m_pD->byAmTI+pT->m_pD->byAmTS;
						if(byA1<pT->m_pD->byAmTU)
						{
					     pTS = pT->m_pTeleSensor[byID];
						 if((byA2==3)||(byA2==4)) pTS->Switch(pTS);
					     pTS->EventHandler(pTS->pChld,pMsg);
						}
				   break;
				   case REG_SOFTR_ADDR:
				   break;
				 }
		    break;  
			case PH_CONN_IND:
                 #ifdef DEB_CKpModule
				 Info("\n(__)CKPMM::>CONNECT");
                 #endif
				 pT->m_byKpState = MKP_CONN_ST01; 
				 pT->m_nPuCommTMR.OnTimer(&pT->m_nPuCommTMR,100);
				 pT->m_nConnTMR.OfTimer(&pT->m_nConnTMR);
				 pT->m_blIfConnect = TRUE;
				 //pT->m_nConnRepTMP.OfTimer(&pT->m_nConnRepTMP);
	             //pT->m_wCallTime = 300;
				 //pT->m_byConnCT  = 0;
				 pT->SaveInPin(pT);
                 //pT->SaveAlarmPin(pT);
				 //pT->SaveSlotState(pT);
			break;
			case PH_DISC_IND:
                 #ifdef DEB_CKpModule
				 Info("\n(__)CKPMM::>DISCONNECT");
                 #endif
				 pT->m_byKpState = MKP_DISC_ST02; 	
				 pT->m_nDiscTMR.OfTimer(&pT->m_nDiscTMR);
				 pT->m_nConnTMR.OfTimer(&pT->m_nConnTMR);
				 //pT->m_nRepConnTMR.OfTimer(&pT->m_nRepConnTMR);
				 if(FCHECK(BOX_L4)!=0) pT->StartConnect(pT); 
				 //pT->m_nConnRepTMP.OfTimer(&pT->m_nConnRepTMP);
	             //pT->m_wCallTime = 600;
				 //pT->m_byConnCT  = 0;
			break;
			default:
            break;  
		   }
      break;
	  case DIR_KPTOKP:
		   if (pMsg->m_sbyType==EV_SYSTM_RESET_TIM_BRD_IND)
		   {
            #ifndef WIN32
			SYSreset(1, 2);
            #endif
			pMsg->m_sbyType=EV_SYSTM_RESET_TIM_BRD_IND;
		   }

           if (pMsg->m_sbyType==EV_TMR_SDIS_REQ)  
		   {
		   	#ifdef DEB_CKpModule
	        Info("\n(__)CKPMM::>GO REM DISC.");
			#endif
	        pT->Disconnect(pT);
		   }

           if (pMsg->m_sbyType==EV_TMR_PUCM_REQ)  
		   {
		   	#ifdef DEB_CKpModule
			Info("\n(__)CKPMM::>PU TIMER EMPTY + DISC.");
			#endif
			pT->m_nConnTMR.OfTimer(&pT->m_nConnTMR);
            pT->Disconnect(pT);
		   }

		   if (pMsg->m_sbyType==EV_TMR_CNRP_REQ) 
		   {
		   	#ifdef DEB_CKpModule
		    Info("\n(__)CKPMM::>EV_TMR_CNRP_REQ.");
			#endif
			pT->SendObserveMsg(pT);
		    //pT->StartConnect(pT);
		   }
		   
	       if (pMsg->m_sbyType==EV_TMR_SRR_REQ) 
		   {
		   	#ifdef DEB_CKpModule
			Info("\n(__)CKPMM::>EV_TMR_SRR_REQ.");
			#endif
			pT->StartConnect(pT);
		   }
		   
		   if (pMsg->m_sbyType==EV_TMR_RCAL_REQ) 
		   {
		   	/*
			#ifdef DEB_CKpModule
			Info("\n(__)CKPMM::>EV_TMR_RCAL_REQ.");
			#endif
			 if((pT->m_byKpState==MKP_DISC_ST02)||(pT->m_byKpState==MKP_NULL_ST00)) pT->StartConnect(pT);
			 else
			 {
			  pT->m_byConnCT  = 0;
		      pT->m_byCallCT  = 3*pT->m_pKP->byAmCall;
			  pT->m_wCallTime = pT->m_pKP->byCallPeriod*10;
			  pT->m_nRepConnTMR.OnTimer(&pT->m_nRepConnTMR,pT->m_wCallTime); 
			 }
			 */
		   }


	       if (pMsg->m_sbyType==EV_TMR_DISC_REQ)
		   {
		   	#ifdef DEB_CKpModule
			Info("\n(__)CKPMM::>EV_TMR_DISC_REQ.");
			#endif
			SendCommand(PH_DISC_REQ,"ATH");
			pT->m_byKpState = MKP_NULL_ST00;
			pT->DisconnectL2(pT);
			pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30);
			//pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,pT->m_wCallTime);
		   }
	  break;
	  case DIR_PHTOKP:
	       if (pMsg->m_sbyType==PH_CALL_REQ)
		   {
            #ifdef DEB_CKpModule
			Info("\n(__)CKPMM::>Set Call Proc.");
            #endif
			pT->m_byConnCT  = 0;
		    pT->m_byCallCT  = 3*pT->m_pKP->byAmCall;
			pT->m_wCallTime = pT->m_pKP->byCallPeriod*10;
		    pT->StartConnect(pT);
			//pT->m_wCallTime = pT->m_pKP->byCallPeriod*10;
			//pT->m_nRepConnTMR.OnTimer(&pT->m_nRepConnTMR,pT->m_wCallTime); 
		   }
	  break;
	  default:
	  break;
	}
	return TRUE;
}
_GLOBAL INT nSendTmr;
/*
BYTE byAmCall;
BYTE byCallPeriod;
*/
void CKpModule_StartConnect(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)
	WORD wTIME = pT->m_pKP->byCallPeriod*10;
	#ifdef DEB_CKpModule
    Info("\n(__)CKPMM::>Start CONNECT::>%b",&pT->m_byConnCT);
    #endif
	if(pT->m_byCallCT--!=0)
	{
     if((pT->m_byKpState==MKP_DISC_ST02)||(pT->m_byKpState==MKP_NULL_ST00))
	 {
	  if(pT->m_byConnCT==0)if(pT->m_pKP->byPhone0[0]!='0'){pT->Connect(pT,pT->m_pKP->byPhone0);wTIME=pT->m_wCallTime;}else wTIME = 10;
	  if(pT->m_byConnCT==1)if(pT->m_pKP->byPhone1[0]!='0'){pT->Connect(pT,pT->m_pKP->byPhone1);wTIME=pT->m_wCallTime;}else wTIME = 10;
	  if(pT->m_byConnCT==2)if(pT->m_pKP->byPhone2[0]!='0'){pT->Connect(pT,pT->m_pKP->byPhone2);wTIME=pT->m_wCallTime;}else wTIME = 10;
	  pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,wTIME);
	  if(++pT->m_byConnCT>2)pT->m_byConnCT = 0;
	 }else
	 {
      #ifdef DEB_CKpModule
	  Info("\n(__)CKPMM::>Already In Join.Reset Call Proc.");
      #endif
	  pT->m_byCallCT = 3*pT->m_pKP->byAmCall;
	  pT->m_wCallTime = pT->m_pKP->byCallPeriod*10;
	  pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,pT->m_wCallTime); 
	 }
	}else
	{
      #ifdef DEB_CKpModule
	  Info("\n(__)CKPMM::>Join Is Not Installed::%w.",&pT->m_wCallTime);
      #endif
	  pT->m_byCallCT = 3*pT->m_pKP->byAmCall;
	  if (pT->m_blIfConnect==TRUE)
	  {
	   if (pT->m_wCallTime<36000) 
	   {
	    pT->m_wCallTime *= 2;
	   }else pT->m_wCallTime = 36000;
	   pT->m_byKpState = MKP_NULL_ST00;
	   pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,pT->m_wCallTime); 
	   pT->m_blIfConnect = FALSE;
	  }else
	  {
	   //pT->m_byCallCT = 3*pT->m_pKP->byAmCall;
	   //pT->m_wCallTime = pT->m_1pKP->byCallPeriod*10; 
	   pT->m_blIfConnect = TRUE;
       pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,60*10); 
	  }
	}
}
void CKpModule_Connect(This,SINT *pchPhone)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	SINT chPhone[30]; 
	memset(chPhone,0,sizeof(chPhone));
	strcat(chPhone,"ATD");
    strcat(chPhone,pchPhone);
    SendCommand(PH_CONN_REQ,chPhone);
	/*
	SHORTMESSAGE m_sMsg;
	BYTE byNbLen;
    #ifdef DEB_CKpModule
	Info("\n(__)CKPMM::>Connect Phone:%s",pchPhone);
    #endif
	//SINT *pchPhone;
	m_sMsg.m_sbyFrom      = DIR_KPMOD;
	m_sMsg.m_sbyFor       = DIR_KPTO101;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_CONN_REQ;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	m_sMsg.m_sbyInfo[0]   = 'A';
	m_sMsg.m_sbyInfo[1]   = 'T';
	m_sMsg.m_sbyInfo[2]   = 'D';
	byNbLen = strlen(pchPhone);
    memcpy(&m_sMsg.m_sbyInfo[3],pchPhone,byNbLen);
	m_sMsg.m_sbyInfo[2+byNbLen+1] = 13;
	m_sMsg.m_sbyInfo[2+byNbLen+2] = 10;
	m_sMsg.m_swLen                = 9+byNbLen+5;
	//#ifdef DEB_C101Module
    Info("\n(__)CKPMM::>Connect Phone:%s",pchPhone);
    //#endif
	FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&m_sMsg);
	*/
	
}
void CKpModule_DisconnectL2(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
	SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = DIR_KPTO101;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_DISC_IND;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(DEV_101MD_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CKpModule
	Info("\n(__)CKPMM::>OUTT::%M",&m_sMsg);
    #endif
}
void CKpModule_Disconnect(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)  
	#ifdef DEB_CKpModule
	Info("\n(__)CKPMM::>Start DISCONNECT::>");
    #endif
	pT->m_blDiscStart = TRUE;
	pT->m_byDiscProc  = 0;
	//SendChar(PH_DISC0_REQ,"+");		
	//SendChar(PH_DISC0_REQ,"+");		
	//SendChar(PH_DISC0_REQ,"+");		
	//pT->m_nDiscTMR.OnTimer(&pT->m_nDiscTMR,40);

	//SendCommand(PH_DISC0_REQ,"+++ ");
	//pT->m_nDiscTMR.OnTimer(&pT->m_nDiscTMR,20);
}
void CKpModule_StartCheck(This,BYTE byTime)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)
	pT->m_nConnRepTMP.OnTimer(&pT->m_nConnRepTMP,byTime);
}
void CKpModule_StopCheck(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	pT->m_nConnRepTMP.OfTimer(&pT->m_nConnRepTMP);
}
void CKpModule_SendObserveMsg(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	CTeleSensor *pSN;
	if(pT->m_byObsObject<pT->m_wAmChannel)
	{
     pSN = pT->m_pTeleSensor[pT->m_byObsObject];
     pSN->SendObsrveMsg(pSN->pChld);
	 pT->m_nConnRepTMP.OnTimer(&pT->m_nConnRepTMP,pT->m_byObsTime);
	}
}
void CKpModule_SaveInPin(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)  
	CTeleSensor *pSN;WORD i;
	FFREE(BOX_L4_1);
	for (i=0;i<pT->m_wAmChannel;i++)
	{
		pSN = pT->m_pTeleSensor[i];
		pSN->SetInPinEvent(pSN->pChld);
	}
}
void CKpModule_SaveAlarmPin(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)  
	CTeleSensor *pSN;WORD i;
	FFREE(BOX_L4_1);
	for (i=0;i<pT->m_wAmChannel;i++)
	{
		pSN = pT->m_pTeleSensor[i];
		pSN->SaveAlarmPin(pSN->pChld);
	}
}

_GLOBAL INT nKPC,nKPC1;
void CKpModule_CyclicProc(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)  
	CTeleSensor *pSN;WORD i;
	
	if(pT->m_blDiscStart) 
	{
	 if(++nKPC%10==0)
	 { 
	  SendChar(PH_DISC0_REQ,"+");		
	  if(++pT->m_byDiscProc==3)
	  { 
	   pT->m_blDiscStart = FALSE;
	   pT->m_byDiscProc  = 0;
	   pT->m_nDiscTMR.OnTimer(&pT->m_nDiscTMR,20);
	  }
	 }
	}
	
	for (i=0;i<pT->m_wAmChannel;i++)
	{
     pSN = pT->m_pTeleSensor[i];
	 pSN->ObserveProc(pSN);
	}
    if (++nKPC1%20==0)pT->CheckSlot(pT);
	//if (++nKP%10==0)pT->CheckEventProc(pT);
	//Info("\n(%b)CKPMD::> CyclicProc",&pT->m_byKpID);
}
void CKpModule_CheckSlot(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
    BYTE i;
	BOOL *blpSlotState,blState=TRUE;
	for(i=0;i<pT->m_pComputer->m_bySlotAmout;i++)
	{
	 blpSlotState = (BOOL*)pT->m_pComputer->m_pvSlot[i]->m_pvAlmState;
	 if(*blpSlotState==FALSE) pT->m_pPCT->sSlot[i].byAlmState = 1;
	 if(*blpSlotState==TRUE)  pT->m_pPCT->sSlot[i].byAlmState = 0;
	}
}
BOOL CKpModule_SaveSlotState(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	SKPEVENT sEV;
	//STSPARAM *pTS;
	//SHARDCOMPUTERTABLE *pH = pT->m_pPCT;
    BYTE i;
	for(i=0;i<pT->m_pComputer->m_bySlotAmout;i++)
	{
	 sEV.wLen    = sizeof(SKPEVENT);
	 sEV.byType  = REG_HARDT_ADDR;
     sEV.byCause = EV_ALS_CH;
	 sEV.byAddr  = i;
	 sEV.wValue  = (WORD)pT->m_pPCT->sSlot[i].byAlmState; 
	 GetCurTime(&sEV.sTime);
	 FPUT1(BOX_L4_1,(BYTE*)&sEV);
	 #ifdef DEB_CTeleSensor
	 Info("\n(%b)CTLIN::>TP[%b]:AD[%b]:VL[%w]:CS[%s]:",&i,&sEV.byType,&sEV.byAddr,&sEV.wValue,STTS[sEV.byCause]);
     #endif
	}
	return TRUE;
}
BOOL CKpModule_Serialize(This,BOOL blDir)
{
	DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	BOOL res = TRUE;
	if (blDir==TRUE) res = pT->SaveContenst(pT);
	if (blDir==FALSE)res = pT->LoadContenst(pT);
	return res;
}
BOOL CKpModule_SaveContenst(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	BOOL res = TRUE;
	pT->SaveTable(pT,&pT->m_nCT);
	//nValue_0++;
	if (!pT->m_pFlash->CompareMemory(pT->m_pFlash,(BYTE*)&pT->m_nCT,sizeof(SCONTENSTTABLE)))
	{
	 //nValue_1++;
	 if (!pT->m_pFlash->WriteFlash(pT->m_pFlash,(BYTE*)&pT->m_nCT,sizeof(SCONTENSTTABLE))) 
 	 {
	 	//nValue_2++;
		res = FALSE;
	 }
	}
	return res;
}
_GLOBAL INT nWR0,nWR1,nWR2,nWR3;
BOOL CKpModule_LoadContenst(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	BOOL res = FALSE;
	pT->m_nST.byKpID = 0xff;
	if (pT->m_pFlash->ReadFlash(pT->m_pFlash,(BYTE*)&pT->m_nST,sizeof(SCONTENSTTABLE)))
	{
		nWR0++;
	 if(pT->m_nST.byDefSett==1)
	 {
	 	nWR1++;
	 	 return FALSE;
	 }
	 if(pT->m_nST.byDefSett==0)
	 {
	  nWR2++;
	  if (pT->m_nST.byKpID==pT->m_byKpID)
	  {
	  nWR3++;
      pT->LoadTable(pT,&pT->m_nST);
	  res = TRUE;
	  }
	 }
	}
	return res;
}
void CKpModule_SaveTable(This,SCONTENSTTABLE *psTable)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	psTable->byKpID = pT->m_byKpID;
    memcpy(&psTable->sKP ,&nKP ,sizeof(SKPPARAM));
	memcpy(&psTable->sARM,&nARM0,sizeof(SARMINTERFACE));
    memcpy(&psTable->sTI ,&nTI ,sizeof(STIPARAMS));
	memcpy(&psTable->sTS ,&nTS ,sizeof(STSPARAMS));
	memcpy(&psTable->sTU ,&nTU ,sizeof(STUPARAMS));
}
void CKpModule_LoadTable(This,SCONTENSTTABLE *psTable)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	pT->m_byKpID = psTable->byKpID;
    memcpy(&nKP ,&psTable->sKP ,sizeof(SKPPARAM));
	memcpy(&nARM0,&psTable->sARM,sizeof(SARMINTERFACE));
    memcpy(&nTI ,&psTable->sTI ,sizeof(STIPARAMS));
	memcpy(&nTS ,&psTable->sTS ,sizeof(STSPARAMS));
	memcpy(&nTU ,&psTable->sTU ,sizeof(STUPARAMS));
}
void CKpModule_CKpModule(This)
{
    DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem) 
	DECLARE_REGISTRATION(CKpModule,Init)
	DECLARE_REGISTRATION(CKpModule,CreateChannels)
	DECLARE_REGISTRATION(CKpModule,StartConnect)
	DECLARE_REGISTRATION(CKpModule,Connect)
	DECLARE_REGISTRATION(CKpModule,Disconnect)
	DECLARE_REGISTRATION(CKpModule,DisconnectL2)
	DECLARE_REGISTRATION(CKpModule,CheckSlot)
	DECLARE_REGISTRATION(CKpModule,Serialize)
	DECLARE_REGISTRATION(CKpModule,SaveContenst)
	DECLARE_REGISTRATION(CKpModule,LoadContenst)
	DECLARE_REGISTRATION(CKpModule,SaveTable)
	DECLARE_REGISTRATION(CKpModule,LoadTable)
	DECLARE_REGISTRATION(CKpModule,SaveInPin)
	DECLARE_REGISTRATION(CKpModule,SaveAlarmPin)
	DECLARE_REGISTRATION(CKpModule,SaveSlotState)
	DECLARE_REGISTRATION(CKpModule,StartCheck)
	DECLARE_REGISTRATION(CKpModule,StopCheck)
	DECLARE_REGISTRATION(CKpModule,SendObserveMsg)
	DECLARE_VIRTUAL_FUNC(CKpModule,EventHandler)
	DECLARE_VIRTUAL_FUNC(CKpModule,CyclicProc)
}
void CKpModule_DCKpModule(This)
{
	DECLARE_MULTI_OPEN(CKpModule,CCyclicSystem)
}
DECLARE_MULTI_CREATE(CKpModule,CCyclicSystem)

