/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrsmartsensor.h"
#if MYSYSTEM_ID != 5
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
extern BYTE *chSensType[];
extern BYTE *chParType[];
#ifdef WIN32
void LCPIDpara(LCPIDpara_typ *pPara){}
void LCPID(LCPID_typ *pPid){};
void LCCounter(LCCounter_typ *pCounder){};
#endif
_GLOBAL LCPIDpara_typ lParaTyp;
void CSmartSensor_InitSensor(This,PVOID pvParam)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	SNSPARAMTABLE *pParam = (SNSPARAMTABLE*)pvParam;
	COutGate *pG = pB->m_pOutGate[0];
    pT->SetState(pT,TRUE);
	pT->m_wExtError = 0;
	pT->m_sSNSParam.enable    = pT->GetState(pT); 
	pT->m_sSNSParam.enter     = pT->GetState(pT); 
	pT->m_sSNSParam.Y_min     = (UINT)(pG->m_rMinRamp*pB->m_sPT.m_swMaxAcpOut);
	pT->m_sSNSParam.Y_max     = (UINT)(pG->m_rMaxRamp*pB->m_sPT.m_swMaxAcpOut);
	pT->m_sSNSParam.dY_max    = pB->m_sPT.m_rlDy;
	pT->m_sSNSParam.Kp        = pB->m_sPT.m_rlKp;
	pT->m_sSNSParam.Tn        = pB->m_sPT.m_rlTn;
	pT->m_sSNSParam.Tv        = pB->m_sPT.m_rlTv;
	pT->m_sSNSParam.Tf        = pB->m_sPT.m_rlTf;
	pT->m_sSNSParam.Kw        = pB->m_sPT.m_rlKw;           
	pT->m_sSNSParam.Kfbk      = pB->m_sPT.m_rlKfbk;		
	pT->m_sSNSParam.fbk_mode  = LCPID_FBK_MODE_INTERN;
	if (pB->m_sPT.m_swPidDiffMode==0)pT->m_sSNSParam.d_mode = LCPID_D_MODE_X;
	if (pB->m_sPT.m_swPidDiffMode==1)pT->m_sSNSParam.d_mode = LCPID_D_MODE_E;
	pT->m_sSNSParam.calc_mode = LCPID_CALC_MODE_FAST;
	LCPIDpara(&pT->m_sSNSParam);
	pT->m_sLCPid.enable       = pT->GetState(pT); 
	pT->m_sLCPid.A            = pB->m_sPT.m_rlA;//500;
	pT->m_sLCPid.Y_man	      = pB->m_sPT.m_rlYman;
	pT->m_sLCPid.Y_fbk        = 0;
	pB->m_nInPin              = pB->m_nIniValue;
	pT->m_sLCPid.X            = pB->m_nInPin;
	pT->m_sLCPid.W            = pB->m_iPHiLimit;
	pT->m_sLCPid.Y            = pB->m_pOutGate[0]->m_wCurrOpenState;
	pB->m_nOutPin             = 0;
	pT->m_sLCPid.e            = 0;
	pT->m_sLCPid.Yi           = 0;
	pT->m_sLCPid.Yp           = 0;
	pT->m_sLCPid.Yd           = 0;
	pT->m_sLCPid.hold_I       = 0;
	if (pB->m_sPT.m_sbyMode==SNS_MD_MANU)pT->SetMode(pT,LCPID_OUT_MODE_MAN);
	if (pB->m_sPT.m_sbyMode==SNS_MD_AUTO)pT->SetMode(pT,LCPID_OUT_MODE_AUTO);
    pT->m_sLCPid.ident        = pT->m_sSNSParam.ident;
	LCPID(&pT->m_sLCPid);
	#ifdef DEB_CSmartSensor
	Info("\n(%b)CISNS::>Create SNS.:%s.:%s.Rng:[%w..%w].AlarmRng:[%w..%w]",
		&pB->m_bySensorID,
		chSensType[pB->m_bySensorType],
		chParType[pB->m_byParamType],
		&pB->m_iLoLimit,&pB->m_iHiLimit,
		&pB->m_iLoAlmLimit,&pB->m_iHiAlmLimit
	);
	#endif
}
void CSmartSensor_IncInput(This,INT16 wParam)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
    pT->m_wExtError += wParam;
	//Info("\n(%b)CSMSN::>DC(%b,%b)PR_INC::%w.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,&pB->m_nInPin);
}
void CSmartSensor_SetInput(This,SPIN *pValue)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	pB->m_nInPin = pValue->iValue;
    //Info("\n(%b)CSMSN::>DC(%b,%b)PR_X::%w.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,&pB->m_nInPin);
}
void CSmartSensor_SetOutput(This,BYTE byNumber,SPIN *pValue)
{
	DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[byNumber];
	pB->m_nOutPin = pValue->iValue;
	if(pG0)pG0->SetGate(pG0,pB->m_nOutPin);
}
void CSmartSensor_PreProc(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	CInputGate *pI = pB->m_nInp;
	if(pB->m_byPidMode==SDIR)pB->m_nInPin = pI->GetInput(pI); else
	if(pB->m_byPidMode==SINV)pB->m_nInPin = pB->m_nAcpMax-pI->GetInput(pI);
	if(pB->m_sPT.m_sbyMode==SNS_MD_LOOP) pB->m_nInPin += pT->m_wExtError;
}
_GLOBAL LCPID_typ lPtyp;
void CSmartSensor_Processing(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
    #ifndef WIN32
	#ifdef MY_MODEL
	REAL rRes,rOut;
	#endif
	LCCounter(&pT->m_sCounter);
	pT->m_sLCPid.W        = pB->m_iPHiLimit;
	pT->m_sLCPid.X        = pB->m_nInPin;
	pT->m_sLCPid.basetime = pT->m_sCounter.mscnt;
	LCPID(&pT->m_sLCPid);	
	#ifdef MY_MODEL
	rOut = (REAL)pT->m_sLCPid.Y;
	rRes = (rOut/378.0)-2.0;
	if((pB->m_nInPin+(INT16)rRes)>32760)pB->m_nInPin = 32760;else
	if((pB->m_nInPin+(INT16)rRes)<0)pB->m_nInPin = 0;else
	pB->m_nInPin += (INT16)rRes;
	#endif
	pB->m_nOutPin = pT->m_sLCPid.Y;
    #else
	pT->m_sLCPid.W   = pB->m_iPHiLimit;  
  	pT->m_sLCPid.X   = pB->m_nInPin;
	pB->m_nOutPin    = pT->m_sLCPid.Y;
    #endif
	//pB->AddStatData(pB,pT->m_sLCPid.Y,pT->m_sLCPid.Yi,pT->m_sLCPid.Yp);
}
void CSmartSensor_PostProc(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[0];
    if(pG0)pG0->SetGate(pG0,pB->m_nOutPin);
}
void CSmartSensor_Serialize(This,BOOL byDir)
{
	DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[0];
	if (byDir==TRUE)if(pG0)pG0->SetGate(pG0,pB->m_nOutPin);
	if (byDir==FALSE)
	{
	 pT->m_sLCPid.Y = pG0->m_wCurrOpenState;
	 pG0->StopGate(pG0);
	}
}
void CSmartSensor_RunAutomat(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	BYTE i;
	COutGate *pG;
	if(pB->m_dwAutoTime++%5==0)
	{
	 pB->EventGen(pB);
	 for (i=0;i<pB->m_byAmOutGate;i++){pG = pB->m_pOutGate[i];pG->RunGate(pG);}
	}
}
void CSmartSensor_CaptureData(This)
{
	DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	COutGate *pG0 = pB->m_pOutGate[0];
    pB->OpenGate(pB);
	pB->AddData(pB,(DINT)pB->m_nInPin);
	pB->AddData(pB,(DINT)pT->m_sLCPid.W);
	pB->AddData(pB,(DINT)(pG0->GetGate(pG0)));
	pB->AddData(pB,pT->m_sLCPid.e);
	pB->AddData(pB,pT->m_sLCPid.Yi);
	pB->AddData(pB,pT->m_sLCPid.Yp);
	pB->AddData(pB,pT->m_sLCPid.Yd);
	pB->CloseGate(pB);
}
USINT CSmartSensor_GetMode(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	return pT->m_sLCPid.out_mode;
}
void CSmartSensor_SetMode(This,USINT uMode)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	pT->m_sLCPid.out_mode = uMode;
}
BOOL CSmartSensor_GetState(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	return pT->m_blState;
}
void CSmartSensor_SetState(This,BOOL blBool)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	pT->m_sSNSParam.enable    = blBool;
	pT->m_sSNSParam.enter     = blBool;   
	pT->m_sLCPid.enable       = blBool; 
	pT->m_blState             = blBool;
	LCPIDpara(&pT->m_sSNSParam);
}
//_GLOBAL REAL rKP;
//_GLOBAL INT  i16Param;
void CSmartSensor_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	SPIN nPin;
	REAL rlParam;
	INT16 wParam;
	BYTE byLen,byInitType,byPType,byPLen,*pR=(BYTE*)&rlParam;
	switch(pMsg->m_sbyType)
	{
      case EV_SMSNS_SET_PARAM_REQ:
		   byLen      = pMsg->m_sbyInfo[0];
		   byInitType = pMsg->m_sbyInfo[1];
		   byPType    = pMsg->m_sbyInfo[2];
		   byPLen     = pMsg->m_sbyInfo[3];
           #ifdef DEB_CSmartSensor
 		   //Info("\n(%b)CSMSN::>DC(%b,%b)SSP:%M.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,(BYTE*)pMsg);
           #endif
		   if(byInitType==SNS_SENS_OUT)
		   {
			 switch(byPType)
			 {
			  case PR_OMIN: 
				   rlParam = pB->GetRealParam(pT,&pMsg->m_sbyInfo[4]);
				   pT->m_sSNSParam.Y_min = (UINT)(rlParam*pB->m_sPT.m_swMaxAcpOut);
				   LCPIDpara(&pT->m_sSNSParam);
			  break;
			  case PR_OMAX: 
				   rlParam = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				   pT->m_sSNSParam.Y_max = (UINT)(rlParam*pB->m_sPT.m_swMaxAcpOut);
				   LCPIDpara(&pT->m_sSNSParam);
			  break;
			  default:
			  break;
			 }
		   }
		   if(byInitType==SNS_PARA_INI)
		   {
		    switch(byPType)
			{
			 case PR_Y_max:  
				  pT->m_sSNSParam.Y_max  = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sGT.wHiLimit     = pT->m_sSNSParam.Y_max;
                  pB->m_pOutGate[0]->SetHiLimit(pB->m_pOutGate[0],pB->m_sGT.wHiLimit);
			 break;
			 case PR_Y_min:
				  pT->m_sSNSParam.Y_min  = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);
			 break;
			 case PR_dY_max:
				  pT->m_sSNSParam.dY_max = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlDy       = pT->m_sSNSParam.dY_max; 
			 break;
			 case PR_Kp:
				  pT->m_sSNSParam.Kp     = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlKp       = pT->m_sSNSParam.Kp; 
			 break;
			 case PR_Tn:
				  pT->m_sSNSParam.Tn     = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlTn       = pT->m_sSNSParam.Tn; 
			 break;
			 case PR_Tv:
				  pT->m_sSNSParam.Tv     = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlTv       = pT->m_sSNSParam.Tv;
			 break;
			 case PR_Tf:
				  pT->m_sSNSParam.Tf     = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlTf       = pT->m_sSNSParam.Tf;
			 break;
			 case PR_Kw:
				  pT->m_sSNSParam.Kw     = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlKw       = pT->m_sSNSParam.Kw; 
			 break;
			 case PR_Kfbk:
				  pT->m_sSNSParam.Kfbk   = pB->GetRealParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlKfbk     = pT->m_sSNSParam.Kfbk; 
			 break;
			 case PR_PrEn:   
				  pB->m_sPT.m_swPidDiffMode = 0;
				  pT->m_sSNSParam.enable = (BOOL)pMsg->m_sbyInfo[4];
				  pB->m_sPT.m_swPidDiffMode = pT->m_sSNSParam.enable;
				  if (pB->m_sPT.m_swPidDiffMode==0)pT->m_sSNSParam.d_mode = LCPID_D_MODE_X;
				  if (pB->m_sPT.m_swPidDiffMode==1)pT->m_sSNSParam.d_mode = LCPID_D_MODE_E;
				  #ifdef DEB_CSmartSensor
				  Info("\n(%b)CSMSN::>DC(%b,%b)PR_PrEn.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID);
				  #endif
			 break;
			 default:
			 break;
			}
		    LCPIDpara(&pT->m_sSNSParam);
		   }
		   if((byInitType==SNS_PIDC_INI)||(byInitType==SNS_SENS_INI))
		   {
			switch(byPType)
			{
			 case PR_W:     
				  wParam = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]); 
				  if(pB->m_byPidMode==SINV) wParam = pB->m_nAcpMax-wParam;
				  pB->m_sPT.m_swHiOper = pB->AcpToReal(pB,wParam);
   			      pT->m_sLCPid.W = wParam;
				  pB->SetHiLimit(pB,wParam);
			 break;
			 case PR_X:     
				  nPin.iValue = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);
				  pT->m_sLCPid.X = nPin.iValue;
    			  pT->SetInput(pT,&nPin);
			 break;
			 case PR_A:
				  pT->m_sLCPid.A  = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlA = pT->m_sLCPid.A;
			 break;
			 case PR_Y_man:
				  pT->m_sLCPid.Y_man = pB->GetWordParam(pB,&pMsg->m_sbyInfo[4]);
				  pB->m_sPT.m_rlYman = pT->m_sLCPid.Y_man;
			 break;
			 case PR_out_mode:
			      if(pMsg->m_sbyInfo[4]==0)
				  {
				   #ifdef DEB_CSmartSensor
				   Info("\n(%b)CSMSN::>DC(%b,%b)SNS_MD_MANU.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID);
				   #endif
				  }
			      if(pMsg->m_sbyInfo[4]==1)
				  {
				   pT->m_sLCPid.out_mode = LCPID_OUT_MODE_AUTO;
				   #ifdef DEB_CSmartSensor
				   Info("\n(%b)CSMSN::>DC(%b,%b)SNS_MD_AUTO.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID);
				   #endif
				  }
			      if(pMsg->m_sbyInfo[4]==2)
				  {
				   pT->m_sLCPid.out_mode = LCPID_OUT_MODE_AUTO;
				   #ifdef DEB_CSmartSensor
				   Info("\n(%b)CSMSN::>DC(%b,%b)SNS_MD_LOOP.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID);
				   #endif
				  }
			 break;
			 case PR_PidEn:  
				  pT->m_sLCPid.enable   = (BOOL)pMsg->m_sbyInfo[4];
				  #ifdef DEB_CSmartSensor
				  Info("\n(%b)CSMSN::>DC(%b,%b)PR_PidEn.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID);
				  #endif
			 break;
			 default:
			 break;
			}
			LCPID(&pT->m_sLCPid);		
		   }
  	  break;
	  default:
	  break;
	};
}
void CSmartSensor_GetParam(This,BYTE byOwner)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	SHMESSAGE m_sMsg;
	BYTE *pP = &m_sMsg.m_sbyInfo[1];
	SPIDPARAM sP;
	INT nSS = sizeof(SPIDPARAM);
    m_sMsg.m_sbyFrom      = MDL_DIRMD;  
    m_sMsg.m_sbyFor       = byOwner;  
    m_sMsg.m_sbyIntType   = DEV_ARM_PORT_TCP;  
    m_sMsg.m_sbyType      = EV_SENSR_GET_PDPARAM_IND;
    m_sMsg.m_sbyServerID  = pB->m_bySystemID;  
    m_sMsg.m_sbyDirection = pB->m_byDirection;
	m_sMsg.m_sbySensor  = pB->m_bySensorID;
    sP.Kp     = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.Kp);	 
    sP.Tn     = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.Tn);	 
    sP.Tv     = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.Tv);	 
    sP.Tf     = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.Tf);	 
    sP.Kw     = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.Kw);	 
	sP.Kfbk   = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.Kfbk);
	sP.Y_max  = pB->GetWordParam(pB,(BYTE*)&pT->m_sSNSParam.Y_max);
    sP.Y_min  = pB->GetWordParam(pB,(BYTE*)&pT->m_sSNSParam.Y_min);
    sP.dY_max = pB->GetRealParam(pB,(BYTE*)&pT->m_sSNSParam.dY_max);
    sP.enable = (BYTE)pT->m_sSNSParam.enable;
	pT->m_sLCPid.W = pB->m_iPHiLimit;
	sP.W      = pB->GetWordParam(pB,(BYTE*)&pT->m_sLCPid.W);
	sP.X      = pB->GetWordParam(pB,(BYTE*)&pT->m_sLCPid.X);
	sP.A      = pB->GetWordParam(pB,(BYTE*)&pT->m_sLCPid.A);
	sP.Y_man  = pB->GetWordParam(pB,(BYTE*)&pT->m_sLCPid.Y_man);
    if(pT->m_sLCPid.out_mode == LCPID_OUT_MODE_MAN) sP.out_mode = 0;
	if(pT->m_sLCPid.out_mode == LCPID_OUT_MODE_AUTO)sP.out_mode = 1;
	sP.enabled = (BYTE)pT->m_sLCPid.enable;
	m_sMsg.m_sbyInfo[0] = 1+ sizeof(SPIDPARAM);
	memcpy(&m_sMsg.m_sbyInfo[1],&sP,sizeof(SPIDPARAM));
    m_sMsg.m_swLen = 9 + m_sMsg.m_sbyInfo[0];
	#ifdef DEB_CSmartSensor
	Info("\n(%b)CSMSN::>DC(%b,%b)SFF:%M.",&pB->m_bySystemID,&pB->m_byDirection,&pB->m_bySensorID,(BYTE*)&m_sMsg);
	#endif
    FPUT(DEV_ARMOT_BOX_ID,(BYTE*)&m_sMsg.m_swLen);    
}
DWORD CSmartSensor_MotToInt(This,DWORD dwData)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	DWORD dwValue;
	BYTE *pTR = (BYTE*)&dwValue;
	BYTE *pSR = (BYTE*)&dwData; 
    #ifndef WIN32
	pTR[3] = pSR[0];
	pTR[2] = pSR[1];
	pTR[1] = pSR[2];
	pTR[0] = pSR[3];
    #else    		
	memcpy(pTR,pSR,4);
    #endif    		
	return dwValue;
}
void CSmartSensor_CSmartSensor(This)
{
    DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	DECLARE_REGISTRATION(CSmartSensor,SetMode)
	DECLARE_REGISTRATION(CSmartSensor,SetState)
	DECLARE_REGISTRATION(CSmartSensor,GetState)
	DECLARE_REGISTRATION(CSmartSensor,MotToInt)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,EventHandler)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,SetInput)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,SetOutput)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,InitSensor)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,PreProc)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,Processing)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,PostProc)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,CaptureData)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,GetParam)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,IncInput)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,RunAutomat)
	DECLARE_VIRTUAL_FUNC(CSmartSensor,Serialize)
}
void CSmartSensor_DCSmartSensor(This)
{
	DECLARE_MULTI_OPEN(CSmartSensor,CSensor)
	DestroyObjectB(CSensor,pB);
}
DECLARE_MULTI_CREATE(CSmartSensor,CSensor)
#endif
