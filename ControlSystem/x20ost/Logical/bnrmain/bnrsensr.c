/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrsensr.c
 * Author: Abramenya
 * Created: January 23, 2009
 *******************************************************************/
#include "bnrsensr.h"
#include "bnrdirmodule.h"
#if MYSYSTEM_ID != 5
SINT *chSensType[] = 
{
	"SMART",
	"IDLES",
	"EMPTY"
};
SINT *chParType[] = 
{
	"LEVEL",   
	"TEMPR",   
	"PRESS"  
};
char *StateInfol[]  =
{
    "SNS_STATE_FREE",
};
char *ValInfol[]  =
{
	"INC_INP",
	"STATE",
};
void CSensor_Init(This,SSWITCHTABLE *pSTable)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE i;
	INT nS = sizeof(SNSPARAMTABLE);
	SNSPARAMTABLE *sP = (SNSPARAMTABLE*)pSTable->sSensorParamTable;
	COutGate *pG      = pT->m_pOutGate[0];
	pT->m_pvPT        = sP;
	pT->m_wSnsMode    = 0;
	pT->m_blSensorState = pSTable->blEnable;
	pT->m_pStateList   = pSTable->m_pStateList;
	pT->SetSensorID(pT,pSTable->bySensorID);
    memcpy(&pT->m_sPT,sP,sizeof(SNSPARAMTABLE));
	memcpy(&pT->m_sGT,pSTable->sOutGate[0],sizeof(SOUTGATE));
	strcpy(pT->m_sPT.m_chSNname,pG->m_chName);
	pT->m_sPT.m_swOpenTime = pG->m_wOTime;
	pT->m_sPT.m_sbyPmode   = pG->m_byMode;
	pT->m_sPT.m_sbyOmode   = pG->m_byOType;
	pT->m_sPT.m_srOmin     = pG->m_rMinRamp;
	pT->m_sPT.m_srOmax     = pG->m_rMaxRamp;
	pT->m_byPidMode        = pG->m_byMode;
	pG->SetMinRamp(pG,pT->m_sPT.m_srOmin);
	pG->SetMaxRamp(pG,pT->m_sPT.m_srOmax);
	pT->m_byParamType      = sP->m_sbyParamType;
	pT->m_bySensorType     = sP->m_snType;
	pT->m_bySwitchCommand  = pSTable->bySwitchCommand;
	if (pT->m_sPT.m_sbyInpState==ST_OPEN) pT->m_blInState  = TRUE; else pT->m_blInState   = FALSE;
	if ((pT->m_sPT.m_sbyOutState==ST_INIT)||(pT->m_sPT.m_sbyOutState==ST_CLOS)) 
	pT->m_blOutState = FALSE; else pT->m_blOutState = TRUE;
	pT->m_blProcState= TRUE;
	if (sP->m_sbyMode==SNS_MD_MANU) pT->SetManMode(pT);
	if (sP->m_sbyMode==SNS_MD_AUTO) pT->SetAutoMode(pT);
	if (sP->m_sbyMode==SNS_MD_LOOP) pT->SetLoopMode(pT);
	if(pT->m_bySensorType!=SNS_EMPTY)
	{
	 pT->CalcGate(pT);
	 if (!pT->m_blOutState)for (i=0;i<pT->m_byAmOutGate;i++)pT->m_pOutGate[i]->SetDefault(pT->m_pOutGate[i]);
	}
	pT->m_blStatState = FALSE;
	pT->m_wStatIndex  = 0;
	pT->m_wStatQuant  = 50;
	#ifdef DEB_CSensor
	//Info("\n(%b)CSSNS::>Create Sensor.Type:%s.",&pSTable->bySensorID,chSensType[pT->m_bySensorType]);
	#endif
	pT->m_blAlmLoLevel  = FALSE;
	pT->m_blRAlmLoLevel = FALSE;
	pT->m_blAlmHiLevel  = FALSE;
	pT->m_blRAlmHiLevel = FALSE;
	pT->m_blProcLoLevel = FALSE;
    pT->m_blProcHiLevel = FALSE;
	pT->m_dwAutoTime    = 0;
	pB->v[INC_INP]      = 0;
    pT->m_byAutoState   = SNS_STATE_FREE;
	pB->SetState(pB,SNS_STATE_FREE);
	pT->m_nInp->FilterEnable(pT->m_nInp,pT->m_sPT.m_byFilterOn);
  	pT->InitSensor(pC,sP);
	//pT->m_nInp = (INT16*)pT->m_pFCP->GetAddrPin(pT->m_pFCP->pChld);
	/*
	InitObject(CMTimer,&pT->m_nATmr[TMR_SET_ALM_HI]);
	InitObject(CMTimer,&pT->m_nATmr[TMR_REM_ALM_HI]);
	InitObject(CMTimer,&pT->m_nATmr[TMR_SET_ALM_LO]);
	InitObject(CMTimer,&pT->m_nATmr[TMR_REM_ALM_LO]);
	pT->m_nATmr[TMR_SET_ALM_HI].SetTimer(&pT->m_nATmr[TMR_SET_ALM_HI],MDL_SENSR,MDL_SENSR,EV_SENSR_TMR_SAHI+TMR_SET_ALM_HI,pT->m_byDirection,pT->m_bySensorID,DEV_SYSTM_BOX_ID);
	pT->m_nATmr[TMR_REM_ALM_HI].SetTimer(&pT->m_nATmr[TMR_REM_ALM_HI],MDL_SENSR,MDL_SENSR,EV_SENSR_TMR_SAHI+TMR_REM_ALM_HI,pT->m_byDirection,pT->m_bySensorID,DEV_SYSTM_BOX_ID);
	pT->m_nATmr[TMR_SET_ALM_LO].SetTimer(&pT->m_nATmr[TMR_SET_ALM_LO],MDL_SENSR,MDL_SENSR,EV_SENSR_TMR_SAHI+TMR_SET_ALM_LO,pT->m_byDirection,pT->m_bySensorID,DEV_SYSTM_BOX_ID);
	pT->m_nATmr[TMR_REM_ALM_LO].SetTimer(&pT->m_nATmr[TMR_REM_ALM_LO],MDL_SENSR,MDL_SENSR,EV_SENSR_TMR_SAHI+TMR_REM_ALM_LO,pT->m_byDirection,pT->m_bySensorID,DEV_SYSTM_BOX_ID);
	*/
}
void CSensor_InitDigital(This,SSWITCHTABLE *pSTable)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto) 
	pT->m_pStateList = pSTable->m_pStateList;
	pB->SetState(pB,SNS_STATE_FREE);
	pT->SetSensorID(pT,pSTable->bySensorID);
    pT->m_bySwitchCommand = pSTable->bySwitchCommand;
	pT->SetAutoMode(pT);
	pT->InitSensor(pC,pSTable);
}
void CSensor_SetOutState(This,BYTE byState)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto) 
	BYTE i;
    if ((byState==ST_INIT)||(byState==ST_CLOS)) pT->m_blOutState = FALSE; else pT->m_blOutState = TRUE;
	for (i=0;i<pT->m_byAmOutGate;i++) 
    pT->m_pOutGate[i]->SetState(pT->m_pOutGate[i],byState);
	pT->m_sPT.m_sbyOutState = byState;
}
void CSensor_CalcGate(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_nAcpMin     = ACP_MIN; 
	pT->m_nAcpMax     = ACP_MAX; 
	pT->m_iHiLimit    = pT->m_nAcpMax; 
	pT->m_iLoLimit    = pT->m_nAcpMin; 
	pT->m_iPHiLimit   = pT->GetInParam(pT,pT->m_sPT.m_swHiOper); 
	pT->m_iPLoLimit   = pT->GetInParam(pT,pT->m_sPT.m_swLoOper); 
	pT->m_iHiAlmLimit = pT->GetInParam(pT,pT->m_sPT.m_swHiAlLimit); 
	pT->m_iLoAlmLimit = pT->GetInParam(pT,pT->m_sPT.m_swLoAlLimit); 
	pT->m_nIniValue   = pT->GetInParam(pT,pT->m_sPT.m_swInitValue); 
	pT->m_iIPLoLimit  = pT->m_iPLoLimit;
	pT->m_iIPHiLimit  = pT->m_iPHiLimit; 
	if(pT->m_byPidMode==SINV)
	{
     pT->m_iPHiLimit   = pT->m_nAcpMax - pT->m_iPHiLimit;
	 pT->m_iLoLimit    = pT->m_nAcpMax - pT->m_iLoLimit;
	 pT->m_iHiAlmLimit = pT->m_nAcpMax - pT->m_iHiAlmLimit;
	 pT->m_iLoAlmLimit = pT->m_nAcpMax - pT->m_iLoAlmLimit;
	 pT->m_nIniValue   = pT->m_nAcpMax - pT->m_nIniValue;
	}
    #ifdef MY_MODEL
	if(pT->m_byPidMode==SDIR)
	{
	 pT->m_nInPin = (UINT)(REAL)(pT->m_nIniValue)/pT->m_nInp->m_rKoef;
	 pT->m_nInp->SetInput(pT->m_nInp,pT->m_nInPin);
	}
    #endif
}
void CSensor_InitSensor(This,SNSPARAMTABLE *pParam)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
    pT->m_blInState   = FALSE;
	pT->m_blProcState = FALSE;
	pT->m_blOutState  = FALSE;
	pT->m_nInPin      = -1;
	pT->m_nOutPin     = -1;
}
void CSensor_GetParamTable(This,BYTE byOwner)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	SNSPARAMTABLE psT;
	SHMESSAGE m_sMsg;
	COutGate *pG = pT->m_pOutGate[0];
    m_sMsg.m_sbyFrom      = MDL_DIRMD;  
	m_sMsg.m_sbyFor       = byOwner;  
	m_sMsg.m_sbyIntType   = DEV_ARM_PORT_TCP;  
	m_sMsg.m_sbyType      = EV_SENSR_GET_SNPARAM_IND;
	m_sMsg.m_sbyServerID  = pT->m_bySystemID;  
	m_sMsg.m_sbyDirection = pT->m_byDirection;
	m_sMsg.m_sbySensor    = pT->m_bySensorID;
    m_sMsg.m_sbyInfo[0]   = 1+sizeof(SNSPARAMTABLE);
	m_sMsg.m_swLen        = 9+m_sMsg.m_sbyInfo[0];
	psT.m_swResistance    = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swResistance);	
	psT.m_swHiLimit       = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swHiLimit);	
	psT.m_swLoLimit       = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swLoLimit);	
	psT.m_swHiAlLimit     = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swHiAlLimit);	
	psT.m_swLoAlLimit     = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swLoAlLimit);	
	psT.m_swHiOper        = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swHiOper);	
	psT.m_swLoOper        = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swLoOper);	
	psT.m_swInitValue     = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_swInitValue);	
	psT.m_swMaxAcpInp     = pT->GetWordParam(pT,(BYTE*)&pT->m_sPT.m_swMaxAcpInp);	
	psT.m_swMaxAcpOut     = pT->GetWordParam(pT,(BYTE*)&pT->m_sPT.m_swMaxAcpOut);	
	psT.m_swOpenTime      = pT->GetWordParam(pT,(BYTE*)&pT->m_sPT.m_swOpenTime);	
	//psT.m_swPidDiffMode   = pT->GetWordParam(pT,(BYTE*)&pT->m_sPT.m_swPidDiffMode);	
	psT.bySrcSlotNumber   = pT->m_sPT.bySrcSlotNumber;
	psT.m_swPidDiffMode   = pT->m_sPT.m_swPidDiffMode;	
	psT.m_snType          = pT->m_sPT.m_snType;	
	psT.m_sbyParamType    = pT->m_sPT.m_sbyParamType;	
	psT.m_sbyInpState     = pT->m_sPT.m_sbyInpState;	
	psT.m_sbyOutState     = pT->m_sPT.m_sbyOutState;
	if (byOwner==MDL_ARMSY) psT.m_sbyOutState = pG->GetPrcGate(pG);
	psT.m_sbyMode         = pT->m_sPT.m_sbyMode;	
	psT.m_snType          = pT->m_sPT.m_snType;	
	psT.m_byFilterOn      = pT->m_sPT.m_byFilterOn; 
	psT.m_sbyPmode        = pT->m_sPT.m_sbyPmode;
	psT.m_sbyOmode        = pT->m_sPT.m_sbyOmode;
	psT.m_srOmin          = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_srOmin);	
	psT.m_srOmax          = pT->GetRealParam(pT,(BYTE*)&pT->m_sPT.m_srOmax);

	strcpy(psT.m_chSNname,pT->m_sPT.m_chSNname);
    memcpy(&m_sMsg.m_sbyInfo[1],&psT,sizeof(SNSPARAMTABLE));
    FPUT(DEV_ARMOT_BOX_ID,(BYTE*)&m_sMsg); 
	pT->GetParam(pC,byOwner);
}
void CSensor_SEventHandler(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE byLen,byInitType,byPType,byPLen,i,byGate,byValue;
	REAL rlPrcOpen;
	COutGate *pG;
	INT16 wParam;
	UINT nParam;
	REAL rParam;
	switch(pMsg->m_sbyType)
	{
	  case EV_SENSR_TMR_SAHI: 
	  case EV_SENSR_TMR_RAHI:
	  case EV_SENSR_TMR_SALO: 
	  case EV_SENSR_TMR_RALO: 
		   pT->SetMsgAuto(pT,pMsg);
	  break;
      case EV_SMSNS_SET_PARAM_REQ:
		   byLen      = pMsg->m_sbyInfo[0];
		   byInitType = pMsg->m_sbyInfo[1];
		   byPType    = pMsg->m_sbyInfo[2];
		   byPLen     = pMsg->m_sbyInfo[3];
           #ifdef DEB_CSensor
		   Info("\n(%b)CSNSR::>DC(%b,%b)SSP:%M.",&pT->m_bySystemID,&pT->m_byDirection,&pT->m_bySensorID,(BYTE*)pMsg);
           #endif
		   if(byInitType==SNS_SENS_INI)
		   {
		   switch(byPType) 
		   {
		    case PR_Out_En:
		         pT->m_sPT.m_sbyOutState = pMsg->m_sbyInfo[4];
		         if(pT->m_sPT.m_sbyOutState==ST_INIT)
				 {
		          for (i=0;i<pT->m_byAmOutGate;i++)pT->m_pOutGate[i]->SetDefault(pT->m_pOutGate[i]);
		          pT->m_blOutState = FALSE;
				 }
		         if(pT->m_sPT.m_sbyOutState==ST_OPEN) 
				 {
		          for (i=0;i<pT->m_byAmOutGate;i++)pT->m_pOutGate[i]->SetState(pT->m_pOutGate[i],ST_OPEN);
		          pT->m_blOutState = TRUE;
				 }
		    break;
		    case PR_LO:  
			     rParam = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_sPT.m_swLoLimit = rParam; 
			     pT->m_iLoLimit        = pT->RealToAcp(pT,pT->m_sPT.m_swLoLimit);
		    break;
			case PR_HI:
                 rParam =  pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_sPT.m_swHiLimit = rParam; 
			     pT->m_iHiLimit        = pT->RealToAcp(pT,pT->m_sPT.m_swHiLimit);
		    break;
			case PR_ALO: 
			     rParam =  pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_sPT.m_swLoAlLimit = rParam; 
			     pT->m_iLoAlmLimit       = pT->RealToAcp(pT,pT->m_sPT.m_swLoAlLimit);
		    break;
			case PR_AHI: 
			     rParam =  pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_sPT.m_swHiAlLimit = rParam; 
			     pT->m_iHiAlmLimit       = pT->RealToAcp(pT,pT->m_sPT.m_swHiAlLimit);
		    break;
			case PR_PHI: 
			     rParam = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     nParam = pT->RealToAcp(pT,rParam);
				 if ((rParam>=pT->m_sPT.m_swLoOper)&&(rParam<=pT->m_sPT.m_swHiAlLimit))
				 {
			      if(pT->m_byParamType==P_PRESS)pT->SetForAll(pT,P_PRESS,PR_PHI,rParam,nParam);else
				  {
				   pT->m_iIPHiLimit     = nParam;
				   if(pT->m_byPidMode==SINV) nParam = pT->m_iHiLimit - nParam; 
				   pT->m_iPHiLimit      = nParam;
			       pT->m_sPT.m_swHiOper = rParam;
				  }
				 }
		    break;
			case PR_PLO: 
			     rParam = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     nParam = pT->RealToAcp(pT,rParam);
				 if ((rParam<=pT->m_sPT.m_swHiOper)&&(rParam>=pT->m_sPT.m_swLoAlLimit))
				 {
			      if(pT->m_byParamType==P_PRESS)pT->SetForAll(pT,P_PRESS,PR_PLO,rParam,nParam);else
				  {
				   pT->m_iIPLoLimit     = nParam; 
				   if(pT->m_byPidMode==SINV) nParam = pT->m_iHiLimit - nParam; 
 				   pT->m_iPLoLimit      = nParam;
			       pT->m_sPT.m_swLoOper = rParam;
				  }
				 }
		    break;
		    case PR_ACO: 
		 	     pT->m_sPT.m_swMaxAcpInp  = pT->GetWordParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_pOutGate[0]->m_wBase = pT->m_sPT.m_swMaxAcpInp;
		    break;
			case PR_ACM: 
				 pT->m_sPT.m_swMaxAcpOut  = pT->GetWordParam(pT,&pMsg->m_sbyInfo[4]);
				 pT->m_nAcpOutRamp        = pT->m_sPT.m_swMaxAcpOut;
			break;
			case PR_OTIME:
				 pT->m_sPT.m_swOpenTime   = pT->GetWordParam(pT,&pMsg->m_sbyInfo[4]);
				 pT->m_sGT.wOpenTime      = pT->m_sPT.m_swOpenTime;
				 pG = pT->m_pOutGate[0];
			     if(pG)pG->SetOutTime(pG,pT->m_sPT.m_swOpenTime);
            break;
		    case PR_RST: 
			     pT->m_sPT.m_swResistance = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
				 pT->m_nInp->SetResistance(pT->m_nInp,pT->m_sPT.m_swResistance);
		    break;
		    case PR_INI: 
			     pT->m_sPT.m_swInitValue  = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
		    break;
            case PR_X:   
			     pT->EventHandler(pC,pMsg);
		    break;
		    case PR_out_mode: 
			     if(pMsg->m_sbyInfo[4]==0) pT->SetManMode(pT);
		         if(pMsg->m_sbyInfo[4]==1) pT->SetAutoMode(pT);
			     if(pMsg->m_sbyInfo[4]==2) pT->SetLoopMode(pT);
			     pT->EventHandler(pC,pMsg);
		    break;
		    case PR_INC_IN:
				 wParam = pT->GetWordParam(pT,&pMsg->m_sbyInfo[4]);
				 pT->IncInput(pC,wParam);
		    break;
			case PR_EnFlt:
			     pT->m_sPT.m_byFilterOn = pMsg->m_sbyInfo[4];
				 pT->m_nInp->FilterEnable(pT->m_nInp,pT->m_sPT.m_byFilterOn);
			break;
		    default:
		    break;
		   }
		   }
		   if(byInitType==SNS_SENS_CTR)
		   {
		   switch(byPType)
		   {
		    case PR_OPN_GT:
			     byGate    = pMsg->m_sbyInfo[4];
			     rlPrcOpen = pT->GetRealParam(pT,&pMsg->m_sbyInfo[5]);
			     pT->m_bySensorID = pT->m_bySensorID;
                 if(pT->m_sPT.m_sbyMode==SNS_MD_MANU)
				 {
			      pG = pT->m_pOutGate[byGate];
			      if(pG)pG->OpenGate(pG,rlPrcOpen);
				 }
			break;
			case PR_STOP_GT:
				 byGate    = pMsg->m_sbyInfo[4];
				 if(pT->m_sPT.m_sbyMode==SNS_MD_MANU)
				 {
				  pG = pT->m_pOutGate[byGate];
				  if(pG)pG->StopGate(pG);
				 }
			break;
			case PR_PRC_GT:
                 byGate    = pMsg->m_sbyInfo[4];
				 byValue   = pMsg->m_sbyInfo[5];
				 if(pT->m_sPT.m_sbyMode==SNS_MD_MANU)
				 {
				  pG = pT->m_pOutGate[byGate];
				  if(pG)pG->OpenGateReq(pG,byValue);
				 } 				
			break;   
		    default:
            break;     
		   }
		   }
		   if(byInitType==SNS_SENS_OUT)
		   {
		   switch(byPType)
		   {
		    case PR_OMIN: 
			     pT->m_sPT.m_srOmin = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_sGT.rMinRamp = pT->m_sPT.m_srOmin;
			     pT->m_pOutGate[0]->SetMinRamp(pT->m_pOutGate[0],pT->m_sPT.m_srOmin);
				 pT->EventHandler(pC,pMsg);
			break;
			case PR_OMAX: 
			     pT->m_sPT.m_srOmax = pT->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
			     pT->m_sGT.rMaxRamp = pT->m_sPT.m_srOmax;
			     pT->m_pOutGate[0]->SetMaxRamp(pT->m_pOutGate[0],pT->m_sPT.m_srOmax);
				 pT->EventHandler(pC,pMsg);
			break;
			case PR_PMODE:
			     pT->m_sPT.m_sbyPmode = pMsg->m_sbyInfo[4]; 
			     pT->m_sGT.byMode = pT->m_sPT.m_sbyPmode;
			     pT->m_pOutGate[0]->m_byMode = pT->m_sPT.m_sbyPmode;
			     memcpy(&pT->m_sPT,pT->m_pvPT,sizeof(SNSPARAMTABLE));
			     strcpy(pT->m_sPT.m_chSNname,pT->m_pOutGate[0]->m_chName);
			     pT->m_sPT.m_sbyPmode = pT->m_pOutGate[0]->m_byMode;
			     pT->m_sPT.m_sbyOmode = pT->m_pOutGate[0]->m_byOType;
			     pT->m_sPT.m_srOmin   = pT->m_pOutGate[0]->m_rMinRamp;
			     pT->m_sPT.m_srOmax   = pT->m_pOutGate[0]->m_rMaxRamp;
			     pT->m_byPidMode      = pT->m_pOutGate[0]->m_byMode;
			     pT->CalcGate(pT);
			break;
			case PR_OMODE:
			     pT->m_sPT.m_sbyOmode = pMsg->m_sbyInfo[4]; 
			     pT->m_sGT.byOType = pT->m_sPT.m_sbyOmode; 
		  	     pT->m_pOutGate[0]->m_byOType = pT->m_sPT.m_sbyOmode;
			break;
			default:
			break; 
		   }
		   }
	  break;
	  default:
      break;
	}
}
void CSensor_SetForAll(This,BYTE byPType,BYTE byPCode,REAL rParam,UINT nParam)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE i;
	CSensor *p;
	DWORD dwSet = 0;
	CDirectionModule *pDR = (CDirectionModule*)pT->m_pvDirection;
	BYTE byAmSens = pDR->m_byAmSwitching;
	if((pT->m_bySystemID==3)&&(pT->m_bySensorID==2))dwSet = 0x0c;else
	if((pT->m_bySystemID!=3)&&(pT->m_bySensorID==0))dwSet = 0x03;else
	if((pT->m_bySystemID!=3)&&(pT->m_bySensorID==2))dwSet = 0x0c;else
	dwSet |= 1<<pT->m_bySensorID;
	for (i=0;i<byAmSens;i++)
	{
	 p = pDR->m_pSensor[i];
	 if(p->m_byParamType==byPType)
	 {
	  if(dwSet&(1<<i))
	  {
	   if(byPCode==PR_PLO) p->m_iIPLoLimit = nParam;
	   if(byPCode==PR_PHI) p->m_iIPHiLimit = nParam;
	   if(p->m_byPidMode==SINV)
	   {
	    nParam = p->m_iHiLimit - nParam; 
	   }
	   if(byPCode==PR_PLO)
	   {
		p->m_iPLoLimit = nParam;
		p->m_sPT.m_swLoOper = rParam;
	   }
	   if(byPCode==PR_PHI)
	   {
		p->m_iPHiLimit = nParam;
		p->m_sPT.m_swHiOper = rParam;
	   }
	  }
	 }
	}
}
void CSensor_SetLEMode(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
}
void CSensor_IncInput(This,INT16 wParam)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
}
INT16 CSensor_GetWordParam(This,BYTE *pbyParam)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	INT16 wValue;
	BYTE *pBT = (BYTE*)&wValue;
    #ifndef WIN32 
	pBT[0] = pbyParam[1];
	pBT[1] = pbyParam[0];
    #else
	pBT[0] = pbyParam[0];
	pBT[1] = pbyParam[1];
    #endif 
	return wValue;
}
REAL CSensor_GetRealParam(This,BYTE *pbyParam)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	REAL rlValue;
	BYTE *pR = (BYTE*)&rlValue;
    #ifndef WIN32
	pR[3] = pbyParam[0];
	pR[2] = pbyParam[1];
	pR[1] = pbyParam[2];
	pR[0] = pbyParam[3];
    #else    		
	memcpy(&rlValue,pbyParam,4);
	#endif    		
	return rlValue;
}
UINT CSensor_GetInParam(This,REAL nParam)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	REAL k;
	REAL rnParam  = nParam;
    REAL rnAcpMin = (REAL)pT->m_nAcpMin;
	REAL rnAcpMax = (REAL)pT->m_nAcpMax;
	REAL rnParamMax = pT->m_sPT.m_swHiLimit;
	k = rnParamMax/(rnAcpMax-rnAcpMin);
    return (UINT)(rnParam/k+rnAcpMin);
}
UINT CSensor_AcpToInt(This,UINT nAcpCode)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	REAL k;
    REAL rnAcpMin   = (REAL)pT->m_nAcpMin;
	REAL rnAcpMax   = (REAL)pT->m_nAcpMax;
	REAL rnParamMax = (REAL)pT->m_sPT.m_swHiLimit;
	REAL rnAcpCode  = (REAL)nAcpCode;
	k = rnParamMax/(rnAcpMax-rnAcpMin);
    return (UINT)((rnAcpCode-rnAcpMin)*k);
}
UINT CSensor_IntToAcp(This,UINT nParam)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	REAL k;
	REAL rnParam    = (REAL)nParam;
    REAL rnAcpMin   = (REAL)pT->m_nAcpMin;
	REAL rnAcpMax   = (REAL)pT->m_nAcpMax;
	REAL rnParamMax = (REAL)pT->m_sPT.m_swHiLimit;
	k = rnParamMax/(rnAcpMax-rnAcpMin);
    return (UINT)(rnParam/k+rnAcpMin);
}
REAL CSensor_AcpToReal(This,UINT nAcpCode)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	REAL k;
    REAL rnAcpMin   = (REAL)pT->m_nAcpMin;
	REAL rnAcpMax   = (REAL)pT->m_nAcpMax;
	REAL rnParamMax = (REAL)pT->m_sPT.m_swHiLimit;
	REAL rnAcpCode  = (REAL)nAcpCode;
	k = rnParamMax/(rnAcpMax-rnAcpMin);
    return (rnAcpCode-rnAcpMin)*k;
}
UINT CSensor_RealToAcp(This,REAL nParam)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	REAL k;
	REAL rnParam    = nParam;
    REAL rnAcpMin   = (REAL)pT->m_nAcpMin;
	REAL rnAcpMax   = (REAL)pT->m_nAcpMax;
	REAL rnParamMax = (REAL)pT->m_sPT.m_swHiLimit;
	k = rnParamMax/(rnAcpMax-rnAcpMin);
    return (UINT)(rnParam/k+rnAcpMin);
}
void CSensor_GetParam(This,BYTE byParam)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
}
void CSensor_SetLoopMode(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_sPT.m_sbyMode   = SNS_MD_LOOP;
    #ifdef DEB_CSensor 
	Info("\n(%b)CSNSR::>DC(%b,%b)SET:SNS_MD_LOOP.",&pT->m_bySystemID,&pT->m_byDirection,&pT->m_bySensorID);
    #endif
}
void CSensor_SetManMode(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	CDirectionModule *pDR = (CDirectionModule*)pT->m_pvDirection;
	pT->EnableInput(pT,FALSE);
	pT->EnableProc(pT,FALSE);
	pT->EnableOutput(pT,FALSE);
	pT->m_sPT.m_sbyMode = SNS_MD_MANU;
	pDR->m_wSensorMode &= ~(1<<pT->m_bySensorID);
	pT->Serialize(pC,TRUE);
    #ifdef DEB_CSensor 
	Info("\n(%b)CSNSR::>DC(%b,%b)SET:SNS_MD_MANU.",&pT->m_bySystemID,&pT->m_byDirection,&pT->m_bySensorID);
    #endif
}
void CSensor_SetAutoMode(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	CDirectionModule *pDR = (CDirectionModule*)pT->m_pvDirection;
	pT->EnableInput(pT,TRUE);
	pT->EnableProc(pT,TRUE);
	pT->EnableOutput(pT,TRUE);
	pT->m_sPT.m_sbyMode = SNS_MD_AUTO;
	pDR->m_wSensorMode |= 1<<pT->m_bySensorID;
	pT->Serialize(pC,FALSE);
    #ifdef DEB_CSensor 
	Info("\n(%b)CSNSR::>DC(%b,%b)SET:SNS_MD_AUTO.",&pT->m_bySystemID,&pT->m_byDirection,&pT->m_bySensorID);
    #endif
}
void CSensor_Serialize(This,BOOL byDir){}
INT16** CSensor_GetCaptureBuffer(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	return (INT16**)pT->m_pwStatBuff;
}
void CSensor_StartCaptureProc(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blStatState = TRUE;
	pT->m_wStatIndex  = 0;
	pT->m_wStatQuant  = 50;
}
void CSensor_StopCaptureProc(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blStatState = FALSE;
}
void CSensor_RestartCaptureProc(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blStatState = TRUE;
	pT->m_wStatIndex  = 0;
}
void CSensor_CaptureData(This){}
void CSensor_OpenGate(This)
{ 
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_wStatIndex = 0;
	pT->m_blCaptureState = TRUE;
}
void CSensor_CloseGate(This)
{ 
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blCaptureState = FALSE;
}
void CSensor_AddData(This,DINT dData)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE *pWT;
    #ifndef WIN32
	BYTE *pWS;
    #endif
	if (pT->m_blCaptureState)
	{
	 pWT = (BYTE*)&pT->m_pwStatBuff[pT->m_wStatIndex++]; 
     #ifndef WIN32
	 pWS = (BYTE*)&dData;
	 pWT[3] = pWS[0];
	 pWT[2] = pWS[1];
	 pWT[1] = pWS[2];
	 pWT[0] = pWS[3];
     #else
	 memcpy(pWT,&dData,4);
     #endif
	}
}
void CSensor_AddCaptureData(This,DINT nP0,DINT nP1,DINT nP2)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE *pWT;
    #ifndef WIN32
	BYTE *pWS;
    #endif
	if(pT->m_blStatState)
	{
		pWT = (BYTE*)&pT->m_pwStatBuff[pT->m_wStatIndex++]; 
		#ifndef WIN32
		pWS = (BYTE*)&nP0;
		pWT[3] = pWS[0];
		pWT[2] = pWS[1];
		pWT[1] = pWS[2];
		pWT[0] = pWS[3];
        #else
        memcpy(pWT,&nP0,4);
		#endif
		pWT = (BYTE*)&pT->m_pwStatBuff[pT->m_wStatIndex++]; 
        #ifndef WIN32
		pWS = (BYTE*)&nP1;
		pWT[3] = pWS[0];
		pWT[2] = pWS[1];
		pWT[1] = pWS[2];
		pWT[0] = pWS[3];
        #else
        memcpy(pWT,&nP1,4);
        #endif
		pWT = (BYTE*)&pT->m_pwStatBuff[pT->m_wStatIndex++]; 
        #ifndef WIN32
		pWS = (BYTE*)&nP2;
		pWT[3] = pWS[0];
		pWT[2] = pWS[1];
		pWT[1] = pWS[2];
		pWT[0] = pWS[3];
        #else
        memcpy(pWT,&nP2,4);
        #endif
	 if(pT->m_wStatIndex==3*pT->m_wStatQuant) 
	 pT->m_blStatState = FALSE;
	}
}
void CSensor_StopStatProc(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blStatState = TRUE;
}
void CSensor_EnableInput(This,BOOL blState)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blInState = blState;
	//Info("\n(%b)CHAND::>EnableInput:%b",&pT->m_bySensorID,&pT->m_blInState);
}
void CSensor_EnableProc(This,BOOL blState)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blProcState = blState;
	//Info("\n(%b)CHAND::>EnableProc:%b",&pT->m_bySensorID,&pT->m_blProcState);
}
void CSensor_EnableOutput(This,BOOL blState)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_blOutState = blState;
	//Info("\n(%b)CHAND::>EnableOutput:%b",&pT->m_bySensorID,&pT->m_blOutState);
}
void CSensor_SetParType(This,BYTE byParType)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_byParamType = byParType;
}
BYTE CSensor_GetParType(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	return pT->m_byParamType;
}
void CSensor_SetSensorID(This,BYTE bySensID)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_bySensorID = bySensID;
}
BYTE CSensor_GetSensorID(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	return pT->m_bySensorID;
}
BYTE CSensor_GetDirection(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	return pT->m_byDirection;
}
void CSensor_SetDirection(This,PVOID pvDir,BYTE byDir)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
    pT->m_byDirection = byDir;
	pT->m_pvDirection = pvDir;
}
void CSensor_ObserveProc(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	if(pT->m_blInState)   pT->PreProc(pC);
	if(pT->m_blProcState) pT->Processing(pC);
	if(pT->m_blOutState)  pT->PostProc(pC);
    pT->RunAutomat(pC);
}
void CSensor_RunAutomat(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
}
void CSensor_EventGen(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	UINT uVL  = (UINT)pT->m_nInPin;
	UINT uHIA = pT->m_iHiAlmLimit;
	UINT uLOA = pT->m_iLoAlmLimit;
    UINT uPHI = pT->m_iPHiLimit;
	UINT uPLO = pT->m_iPLoLimit;
    UINT Hi   = pT->m_nAcpMax;
	UINT Lo   = pT->m_nAcpMin;
	if(pT->m_byPidMode==SINV)
	{
	 uVL  = Hi-(UINT)pT->m_nInPin;
	 uHIA = Hi-pT->m_iHiAlmLimit;
	 uLOA = Hi-pT->m_iLoAlmLimit;
     uPHI = Hi-pT->m_iPHiLimit;
	 uPLO = Hi-pT->m_iPLoLimit;
	}
	if((uVL>=Lo)&&(uVL<uLOA))  pT->SetEvent(pT,&pT->m_blAlmLoLevel ,&pT->m_blRAlmLoLevel,EV_ADMIN_SET_ALM_LOLEV_REQ);
	else pT->SetEvent(pT,&pT->m_blRAlmLoLevel,&pT->m_blAlmLoLevel ,EV_ADMIN_REM_ALM_LOLEV_REQ);//Lo Alarm
    if((uVL>uLOA)&&(uVL<uPLO))pT->SetEvent(pT,&pT->m_blProcLoLevel,&pT->m_blProcHiLevel,EV_ADMIN_OPER_LO_REQ);//Proced  
    if((uVL>uPHI)&&(uVL<Hi))  pT->SetEvent(pT,&pT->m_blProcHiLevel,&pT->m_blProcLoLevel,EV_ADMIN_OPER_HI_REQ);//Proced  
    if((uVL>=uHIA)&&(uVL<=Hi))  pT->SetEvent(pT,&pT->m_blAlmHiLevel ,&pT->m_blRAlmHiLevel,EV_ADMIN_SET_ALM_HILEV_REQ);
	else pT->SetEvent(pT,&pT->m_blRAlmHiLevel,&pT->m_blAlmHiLevel ,EV_ADMIN_REM_ALM_HILEV_REQ);//Li Alarm
}
void CSensor_SetEvent(This,BOOL *bl0,BOOL *bl1,BYTE byEvent)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	if (*bl0 == FALSE)
	{
	 //Info("\n(%b)CSNSR[%b]::>SEND:EV[%b].",&pT->m_bySystemID,&pT->m_bySensorID,&byEvent);
	 pB->HandleEvent(pB,byEvent);
     *bl0 = TRUE;
     *bl1 = FALSE;
	}
}
void CSensor_ConnectFCP(This,CInputGate *pInputGate)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_nInp = pInputGate;
}
void CSensor_ConnectOutGate(This,COutGate *pOGate)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE byID = pOGate->m_byGateID;
    pT->m_pOutGate[byID] = pOGate;
}
void CSensor_SetLoLimit(This,UINT iValue)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_iPLoLimit = iValue;
}
void CSensor_SetHiLimit(This,UINT iValue)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_iPHiLimit  = iValue;
	pT->m_iIPHiLimit = iValue;
}
///////////////////////
void CSensor_SetLoAlLimit(This,INT16 iValue)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_iLoAlmLimit = iValue;
}
void CSensor_SetHiAlLimit(This,INT16 iValue)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_iHiAlmLimit = iValue;
}
void CSensor_SetCallBackProc(This,PCLB pfCallBack)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_pfnCallBackProc = pfCallBack;
}
void CSensor_SetState(This,DWORD dwState)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->m_dwState = dwState;
}
DWORD CSensor_GetState(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	return pT->m_dwState;
}
void CSensor_Enable(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->SetState(pT,ST01_SNS_OPEN);
}
void CSensor_Disable(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	pT->SetState(pT,ST02_SNS_CLOS);
}
void CSensor_PreProc(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto) 
}
void CSensor_Processing(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto) 
}
void CSensor_PostProc(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto) 
}
void CSensor_EventGate(This,BYTE byEvent)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto) 
}
void CSensor_ConnectPinAddres(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)  
	BYTE i;
	CPin *pPN;
    for (i=0;i<pT->m_wAmInput;i++) 
	{
     pPN = pT->m_pINP[i];
	 if(pPN->m_byPinType==PIN_AN_INOT_INT) pT->m_nINP[i] = pPN->GetAddrPin(pPN->pChld);
	 if(pPN->m_byPinType==PIN_DG_INOT_BOL) pT->m_bINP[i] = pPN->GetAddrPin(pPN->pChld);
	}
    for (i=0;i<pT->m_wAmOutput;i++) 
	{
	 pPN = pT->m_pOUT[i];
	 if(pPN->m_byPinType==PIN_AN_INOT_INT) pT->m_nOUT[i] = pPN->GetAddrPin(pPN->pChld);
	 if(pPN->m_byPinType==PIN_DG_INOT_BOL) pT->m_bOUT[i] = pPN->GetAddrPin(pPN->pChld);
	}
}
void CSensor_SendCommand(This,BYTE byFor,BYTE byType)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	SHORTMESSAGE sMsg;
    sMsg.m_swLen        = 9;
	sMsg.m_sbyFrom      = MDL_SSENS;
    sMsg.m_sbyFor       = byFor;
	sMsg.m_sbyIntType   = DEV_SYS_INTERFACE;
	sMsg.m_sbyServerID  = pT->m_bySystemID;
	sMsg.m_sbyType      = byType;
	sMsg.m_sbyDirection = pT->m_byDirection;
	sMsg.m_sbySensor    = pT->m_bySensorID;
	FPUT(DEV_ADMIN_BOX_ID,(BYTE*)&sMsg);
}
//Auto Section
BOOL CSensor_HandleTask(This,TTask* pTask)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	COutGate *pG;
	BYTE V0,V1;
    for(;*pTask!=EXIT_D;pTask++)
    {
	  switch (*pTask)
	  {
	  	 case CMD_OPENGATE:
			  V0 = *(++pTask);
			  V1 = *(++pTask);
			  pG = pT->m_pOutGate[V0];
			  if(pG)pG->OpenGate(pG,V1);
              #ifdef DEB_CSensor
			  Info("\n(%b)CSNSR[%b]::>GATE:[%b]am[%b]",&pT->m_bySystemID,&pT->m_bySensorID,&V0,&V1);
              #endif
         break;
	  	 case CMD_SETSTATE:
			  V1 = *(++pTask);
			  if(*pTask==STATE) V1 = pB->v[STATE];
			  pB->SetState(pB,V1);
              #ifdef DEB_CSensor
			  Info("\n(%b)CSNSR[%b]::>STAT:%s->%s ",&pT->m_bySystemID,&pT->m_bySensorID,StateInfol[pB->v[STATE]],StateInfol[V1]);
			  //Info("\n(%b)CSNSR[%b]::>STAT:/--------New--------/",&pT->m_bySystemID,&pT->m_bySensorID);
              #endif
			  pB->v[STATE] = V1;
         break;
		 case CMD_SEND:
			  V0 = *(++pTask);
			  V1 = *(++pTask);
			  pT->SendCommand(pT,V0,V1);
              #ifdef DEB_CSensor
			  Info("\n(%b)CSNSR[%b]::>SEND:[%b][%b].",&pT->m_bySystemID,&pT->m_bySensorID,&V0,&V1);
              #endif
		 break;
		 case CMD_SETVALUE:
			  V0 = *(++pTask);
			  pB->v[V0] = *(++pTask);
              #ifdef DEB_CSensor
			  Info("\n(%b)CSNSR[%b]::>SETV:%s=%b",&pT->m_bySystemID,&pT->m_bySensorID,ValInfol[V0],&pB->v[V0]);
              #endif
		 break;
		 case CMD_TIMERON:
			  V0 = *(++pTask);//Timer ID
			  V1 = *(++pTask);//Time
			  pT->m_nATmr[V0].OnTimer(&pT->m_nATmr[V0],V1);
              #ifdef DEB_CSensor
			  Info("\n(%b)CSNSR[%b]::>TMON:[%b][%b].",&pT->m_bySystemID,&pT->m_bySensorID,&V0,&V1);
	          #endif
		 break;
		 case CMD_TIMEROFF:
			  V0 = *(++pTask);
			  pT->m_nATmr[V0].OfTimer(&pT->m_nATmr[V0]);
              #ifdef DEB_CSensor
			  Info("\n(%b)CSNSR[%b]::>TMOF:[%b].",&pT->m_bySystemID,&pT->m_bySensorID,&V0);
              #endif
		 break;
		 default:
		 break;
	  };
	}
	return TRUE;
}
TStateList* CSensor_GetStateList(This)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	return pT->m_pStateList;
}
void CSensor_SetMsgAuto(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE byEvent = pMsg->m_sbyType;
	pB->HandleEvent(pB,byEvent);
}
void CSensor_SetAutoEvent(This,BYTE byEvent)
{
    DECLARE_MULTI_OPEN(CSensor,CAuto)
    pB->HandleEvent(pB,byEvent);
}
void CSensor_CSensor(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE i;
    DECLARE_REGISTRATION(CSensor,Init)
	DECLARE_REGISTRATION(CSensor,SetCallBackProc)
	DECLARE_REGISTRATION(CSensor,ObserveProc)
	DECLARE_REGISTRATION(CSensor,SetState)
	DECLARE_REGISTRATION(CSensor,GetState)
	DECLARE_REGISTRATION(CSensor,Enable)
	DECLARE_REGISTRATION(CSensor,Disable)
	DECLARE_REGISTRATION(CSensor,Init)
	DECLARE_REGISTRATION(CSensor,ConnectFCP)
	DECLARE_REGISTRATION(CSensor,SetLoLimit)
	DECLARE_REGISTRATION(CSensor,SetHiLimit)
	DECLARE_REGISTRATION(CSensor,SetLoAlLimit)
	DECLARE_REGISTRATION(CSensor,SetHiAlLimit)
	DECLARE_REGISTRATION(CSensor,SendCommand)

	DECLARE_REGISTRATION(CSensor,PreProc)
	DECLARE_REGISTRATION(CSensor,Processing)
	DECLARE_REGISTRATION(CSensor,PostProc)
	DECLARE_REGISTRATION(CSensor,SetDirection)
	DECLARE_REGISTRATION(CSensor,GetDirection)
	DECLARE_REGISTRATION(CSensor,SetSensorID)
	DECLARE_REGISTRATION(CSensor,GetSensorID)

	DECLARE_REGISTRATION(CSensor,SetParType) 
	DECLARE_REGISTRATION(CSensor,GetParType) 

	DECLARE_REGISTRATION(CSensor,EnableInput)
	DECLARE_REGISTRATION(CSensor,EnableProc)
	DECLARE_REGISTRATION(CSensor,EnableOutput)

	DECLARE_REGISTRATION(CSensor,SetLoopMode)
	DECLARE_REGISTRATION(CSensor,SetManMode)
	DECLARE_REGISTRATION(CSensor,SetAutoMode)
	//Statistic
	DECLARE_REGISTRATION(CSensor,StartCaptureProc)
	DECLARE_REGISTRATION(CSensor,StopCaptureProc)
	DECLARE_REGISTRATION(CSensor,AddCaptureData)
	DECLARE_REGISTRATION(CSensor,CaptureData)
	DECLARE_REGISTRATION(CSensor,RestartCaptureProc)
	DECLARE_REGISTRATION(CSensor,GetCaptureBuffer)
	DECLARE_REGISTRATION(CSensor,AddData)
	DECLARE_REGISTRATION(CSensor,OpenGate)
	DECLARE_REGISTRATION(CSensor,CloseGate)
	DECLARE_REGISTRATION(CSensor,GetParamTable)
	DECLARE_REGISTRATION(CSensor,GetParam)
	DECLARE_REGISTRATION(CSensor,SEventHandler)
	DECLARE_REGISTRATION(CSensor,GetWordParam)
	DECLARE_REGISTRATION(CSensor,GetRealParam)
	DECLARE_REGISTRATION(CSensor,InitSensor)
	DECLARE_REGISTRATION(CSensor,IncInput)
	DECLARE_REGISTRATION(CSensor,GetInParam)
	DECLARE_REGISTRATION(CSensor,CalcGate)
	DECLARE_REGISTRATION(CSensor,AcpToInt)
	DECLARE_REGISTRATION(CSensor,IntToAcp)
	DECLARE_REGISTRATION(CSensor,AcpToReal)
	DECLARE_REGISTRATION(CSensor,RealToAcp)
	DECLARE_REGISTRATION(CSensor,ConnectOutGate)
	DECLARE_REGISTRATION(CSensor,EventGen)

	DECLARE_REGISTRATION(CSensor,EventGate)
	DECLARE_REGISTRATION(CSensor,SetOutState)
	DECLARE_REGISTRATION(CSensor,RunAutomat)
	DECLARE_REGISTRATION(CSensor,SetForAll)
	DECLARE_REGISTRATION(CSensor,SetEvent)
	DECLARE_REGISTRATION(CSensor,RunAutomat)
	DECLARE_REGISTRATION(CSensor,InitDigital)
	DECLARE_REGISTRATION(CSensor,ConnectPinAddres)
	//Automat 
	DECLARE_REGISTRATION(CSensor,SetMsgAuto)
	DECLARE_REGISTRATION(CSensor,SetAutoEvent)
	DECLARE_REGISTRATION(CSensor,Serialize)
	
	DECLARE_VIRTUAL_FUNC(CSensor,HandleTask)
	DECLARE_VIRTUAL_FUNC(CSensor,GetStateList)
    for(i=0;i<DEV_AMT_GATE_SNS;i++) pT->m_pOutGate[i] = 0;
	pT->m_pfnCallBackProc = NULL;
	pT->m_byEvent = 0xff;
	pT->m_dwState = ST02_SNS_CLOS;
	pT->m_nAcpMin = 6552; 
	pT->m_nAcpMax = 32760; 
}
void CSensor_DCSensor(This)
{
	DECLARE_MULTI_OPEN(CSensor,CAuto)
	BYTE i;
    for (i=0;i<pT->m_byAmOutGate;i++)
    DestroyObject(COutGate,pT->m_pOutGate[i]);
}
DECLARE_MULTI_CREATE(CSensor,CAuto)
#endif