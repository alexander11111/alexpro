/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrdirmodule.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#if MYSYSTEM_ID != 5
void CDirectionModule_Init(This,SDIRTABLE *pDirect,CMFlash *pFlash)
{
    DECLARE_SINGLE_OPEN(CDirectionModule) 
	INT i,nCreated;
	BOOL blSerialize;
	BYTE bySensorType,byLen;
	CSensor *pSensor;
	CSmartSensor *pSmartSensor;
	CIdleSensor *pIdleSensor;
	CDigitalSensor *pDgSensor;
	SNSPARAMTABLE *sP;
	pT->m_pDirTable = pDirect; 
	pT->m_pFlash = pFlash;
	pT->m_wSensorMode = 0;
	pT->m_pvInGate = pDirect->pvIn;
	pT->m_pvOutGate = pDirect->pvOut;
	pT->m_byDefSett = 0;
    #if MYSYSTEM_ID == 4 
	pT->m_byAmInpGate = ((SDIGGATES*)pT->m_pvInGate)->byAmGate;
    #else
    pT->m_byAmInpGate = ((SINPUTGATE*)pT->m_pvInGate)->byAmInGate;
    #endif
	pT->m_wLayerMode  = 0x2;
	/*
	#if   MYSYSTEM_ID == 0 
	 pT->m_wLayerMode  = 0x2;
	#elif MYSYSTEM_ID == 1
	 pT->m_wLayerMode  = 0x1;
	#elif MYSYSTEM_ID == 2
	 pT->m_wLayerMode  = 0x2;
	#elif MYSYSTEM_ID == 3
	 pT->m_wLayerMode  = 0x1a;
	#endif
	*/
	pT->m_blGetData = FALSE;
    #ifdef DEB_CDirectionModule
	Info("\n(%b)CDIRC::>Create Direction.",&pDirect->byDirectionID);
    #endif
	pT->m_byStatSnsConn = 0xff;
	pT->m_byDirectionID = pDirect->byDirectionID;
	pT->m_byAmSwitching = pDirect->byAmSwitching;
	pT->m_byDirectionCode = pDirect->byDirectionCode;
    New(sizeof(CSensor*)*pT->m_byAmSwitching,pT->m_pSensor);
	for (i=0;i<pT->m_byAmSwitching;i++)pT->m_pSensor[i]=0;
	for (nCreated=0;nCreated<=1;nCreated++)
	{
	if(nCreated)
	{
     #if MYSYSTEM_ID != 4 
	 pT->SetInputGate(pT,pT->m_pvInGate);
     #endif
	 blSerialize = pT->Serialize(pT,FALSE); 
	}
	for (i=0;i<pT->m_byAmSwitching;i++)
	{
	 bySensorType = pDirect->sSwitchTable[i].bySwitchCommand;
	 switch(bySensorType)
	 {
	    case SWC_CMD_SMR_CON:
			{
			 if(nCreated==0){
			 New(sizeof(CSmartSensor),pSmartSensor);
			 InitObject(CSmartSensor,pSmartSensor);
			 pSmartSensor->pBase->m_bySystemID = pT->m_bySystemID;
			 pT->m_pSensor[i] = pSmartSensor->pBase;}
			 if(nCreated==1){
			 pSmartSensor->pBase = pT->m_pSensor[i]; 
			 pT->SwitchSensor(pT,pSmartSensor->pBase,&pDirect->sSwitchTable[i]);
			 pSmartSensor->pBase->SetDirection(pSmartSensor->pBase,pT,pT->m_byDirectionID);
			 pSmartSensor->pBase->Init(pSmartSensor->pBase,&pDirect->sSwitchTable[i]);}
			}
		break;
		case SWC_CMD_IDL_CON:
			{
			 if(nCreated==0){
			 New(sizeof(CIdleSensor),pIdleSensor);
			 InitObject(CIdleSensor,pIdleSensor);
			 pIdleSensor->pBase->m_bySystemID = pT->m_bySystemID;
			 pT->m_pSensor[i] = pIdleSensor->pBase;}
			 if(nCreated==1){
			 pIdleSensor->pBase = pT->m_pSensor[i]; 
			 pT->SwitchSensor(pT,pIdleSensor->pBase,&pDirect->sSwitchTable[i]);
			 pIdleSensor->pBase->SetDirection(pIdleSensor->pBase,pT,pT->m_byDirectionID);
			 pIdleSensor->pBase->Init(pIdleSensor->pBase,&pDirect->sSwitchTable[i]);}
			}
		break;
		case SWC_CMD_EMT_CON:
			{
			 if(nCreated==0){
			 New(sizeof(CSensor),pSensor);
			 InitObject(CSensor,pSensor);
			 pSensor->m_bySystemID = pT->m_bySystemID;
			 pT->m_pSensor[i] = pSensor;}
			 if(nCreated==1){
			 pSensor->pBase = pT->m_pSensor[i]; 
			 pSensor->SetDirection(pSensor,pT,pT->m_byDirectionID);
			 pSensor->Init(pSensor,&pDirect->sSwitchTable[i]);}
			}
		break;
		case SWC_CMD_LOG_CON:
			{
			 if(nCreated==0){
			 New(sizeof(CDigitalSensor),pDgSensor);
			 InitObject(CDigitalSensor,pDgSensor);
			 pDgSensor->pBase->m_bySystemID = pT->m_bySystemID;
			 pT->m_pSensor[i] = pDgSensor->pBase;}
			 if(nCreated==1){
			 pDgSensor->pBase = pT->m_pSensor[i]; 
             pDgSensor->pBase->SetDirection(pDgSensor->pBase,pT,pT->m_byDirectionID);
			 pDgSensor->pBase->InitDigital(pDgSensor->pBase,&pDirect->sSwitchTable[i]);//Create In Out
			 pT->SwitchDigitalSensor(pT,pDgSensor->pBase,&pDirect->sSwitchTable[i]);}   //Connect In or Out
			}
		break;
		default:
		break;
	 }
	}
	}
    #if MYSYSTEM_ID != 4 
	if (blSerialize)for(i=0;i<8;i++)if(pT->m_nST.m_wLayerMode&(1<<i))pT->SetCurentTank(pT,i);
    #endif
}
BOOL CDirectionModule_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	INT16 **pwData;
	CSensor *pSN;
	BYTE byParam;
    switch(pMsg->m_sbyFor)
	{
		case MDL_DIRMD:
			 switch(pMsg->m_sbyType)
			 {
			    case EV_DIRMD_SET_TANK_REQ:
	                 pT->SetCurentTank(pT,pMsg->m_sbySensor);
                     #ifdef DEB_CDirectionModule
					 Info("\n(%b)CDIRC::>(%b)(%b)SetTank.",&pT->m_bySystemID,&pT->m_byDirectionID,&pMsg->m_sbySensor);
                     #endif
				break; 
				#if MYSYSTEM_ID != 4 
			 	case EV_DIRMD_GET_PARAM_REQ:
					 if(pMsg->m_sbySensor<pT->m_byAmSwitching)
					 {
					  pSN = pT->m_pSensor[pMsg->m_sbySensor];
					  byParam = pMsg->m_sbyInfo[1];
					  pSN->GetParamTable(pSN,pMsg->m_sbyInfo[1]);
                      #ifdef DEB_CDirectionModule
					  Info("\n(%b)CDIRC::>(%b)(%b)GetParam.",&pT->m_bySystemID,&pT->m_byDirectionID,&pMsg->m_sbySensor);
                      #endif
					 }
				break;
				case EV_DIRMD_CONN_STAT_SNS_IND:
                     #ifdef DEB_CDirectionModule
					 Info("\n(%b)CDIRC::>(%b)(%b)Connect To Sensor.",&pT->m_bySystemID,&pT->m_byDirectionID,&pMsg->m_sbySensor);
                     #endif
					 pT->m_byStatSnsConn  = pMsg->m_sbySensor;
					 pT->m_byTypeTest     = 0;
					 if(pMsg->m_sbySensor<pT->m_byAmSwitching)
					 {
					  pSN = pT->m_pSensor[pMsg->m_sbySensor];
					  pT->m_pStatSnsTmr.SetTimer(&pT->m_pStatSnsTmr,MDL_DIRMD,MDL_DIRMD,EV_DIRMD_REFR_TIM_PROC_IND,pSN->m_byDirection,0,DEV_SYSTM_BOX_ID);
					  pSN->GetParamTable(pSN,MDL_TPIDT);
					 }
				break;
			    case EV_DIRMD_DISC_STAT_SNS_IND:
                     #ifdef DEB_CDirectionModule
					 Info("\n(%b)CDIRC::>(%b)Disconnect To Sensor.",&pT->m_bySystemID,&pT->m_byDirectionID);
                     #endif
					 pT->m_byStatSnsConn = 0xff;
				break;
                #endif
			    case EV_DIRMD_CONN_STAT_START_IND:
                     #ifdef DEB_CDirectionModule
					 Info("\n(%b)CDIRC::>(%b)(%b)Start Stat Proc:%b.",&pT->m_bySystemID,&pT->m_byDirectionID,&pMsg->m_sbySensor,&pMsg->m_sbyInfo[1]);
                     #endif
					 if((pMsg->m_sbySensor<pT->m_byAmSwitching)&&(pT->m_byStatSnsConn!=0xff))
					 {
					  pSN = pT->m_pSensor[pMsg->m_sbySensor];
					  pT->m_byTypeTest = pMsg->m_sbyInfo[2]; 
					  if(pT->m_byTypeTest==0)pSN->StartCaptureProc(pSN);
					  pT->m_pStatSnsTmr.OnTimer(&pT->m_pStatSnsTmr,pMsg->m_sbyInfo[1]*SYSTEM_QTIME/100);
					 }
				break;
			    case EV_DIRMD_CONN_STAT_STOP_IND:
                     #ifdef DEB_CDirectionModule
					 Info("\n(%b)CDIRC::>(%b)(%b)Stop Stat Proc.",&pT->m_bySystemID,&pT->m_byDirectionID,&pMsg->m_sbySensor);
                     #endif
					 if(pMsg->m_sbySensor<pT->m_byAmSwitching)
					 {
					  pSN = pT->m_pSensor[pMsg->m_sbySensor];
 					  pT->m_pStatSnsTmr.OfTimer(&pT->m_pStatSnsTmr);					 
					 }
			    break;
				case EV_DIRMD_REFR_TIM_PROC_IND:
					 if(pT->m_byStatSnsConn!=0xff)
					 {
					 pMsg->m_sbyFrom      = MDL_DIRMD;  
					 pMsg->m_sbyFor       = MDL_TPIDT;  
					 pMsg->m_sbyIntType   = DEV_ARM_PORT_TCP;  
					 pMsg->m_sbyServerID  = pT->m_bySystemID;  
					 pMsg->m_sbyType      = EV_DIRMD_STAT_DATA_IND;
					 pMsg->m_sbyDirection = pT->m_byDirectionID;
	                 pMsg->m_sbySensor    = pT->m_byStatSnsConn;
 				     pSN                  = pT->m_pSensor[pT->m_byStatSnsConn];
                     if(pT->m_byTypeTest==0)
					 {
					  pMsg->m_sbyInfo[0] = (BYTE)pSN->m_wStatIndex;
					  pMsg->m_sbyInfo[1] = (BYTE)pSN->m_wStatIndex;
					  pwData = pSN->GetCaptureBuffer(pSN);
					  memcpy(&pMsg->m_sbyInfo[2],pwData,12*pSN->m_wStatQuant);
					  pMsg->m_swLen = 9+1+1+12*pSN->m_wStatQuant;
					 }
					 if(pT->m_byTypeTest==1)
					 {
					  pSN->CaptureData(pSN->pChld);
					  pwData = pSN->GetCaptureBuffer(pSN);
					  pMsg->m_sbyInfo[0] = (BYTE)pSN->m_wStatIndex;
					  pMsg->m_sbyInfo[1] = (BYTE)pSN->m_wStatIndex;
					  memcpy(&pMsg->m_sbyInfo[2],pwData,4*pSN->m_wStatIndex);
					  pMsg->m_swLen = 9+1+1+4*pSN->m_wStatIndex;
					 }
					 FPUT(DEV_ARMOT_BOX_ID,(BYTE*)&pMsg->m_swLen);
                     if(dwFL&DEB_OUT_OBSR_COMM)
	                 Info("\n(%b)COBSE::>msg:%M",&pT->m_bySystemID,(BYTE*)pMsg); 					 
					 pSN->RestartCaptureProc(pSN);
					 pT->m_pStatSnsTmr.Restart(&pT->m_pStatSnsTmr);
					 }
				break;
			    default:
			    break;
			 }
		break;
		default:
		break;
	}
	return TRUE;
}
void CDirectionModule_SetInputGate(This,SINPUTGATE *pING)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	REAL Imin,Imax,R; 
	BYTE i;
	CSlot *pSL;
	CPin  *pPN;
	for (i=0;i<pT->m_byAmInpGate;i++)
	{
	 pSL = pT->m_pComputer->GetSlot(pT->m_pComputer,pING->mIn[i].bySrcSlotNumber);
     pPN = pSL->GetPin(pSL->pChld,pING->mIn[i].bySrcPinNumber);
	 InitObject(CInputGate,&pT->m_nInpGate[i]);
	 pT->m_nInpGate[i].Init(&pT->m_nInpGate[i],i,pPN->GetAddrPin(pPN->pChld),500.0,pING->mIn[i].m_swResistance);
	 #ifdef MY_MODEL
	 pT->m_pSensor[0]->m_sPT.m_swHiLimit = pING->mIn[i].m_swHiLimit;
	 pT->m_nInpGate[i].SetInput(&pT->m_nInpGate[i],pT->m_pSensor[0]->GetInParam(pT->m_pSensor[0],pING->mIn[i].m_swInitValue)/pT->m_nInpGate[i].m_rKoef);
     #endif
	}
}
void CDirectionModule_SwitchSensor(This,CSensor *pSensor,SSWITCHTABLE *pSwitchTable)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	BYTE i;
	CSlot *pSL;
	CPin  *pPN;
	SOUTGATE *sG;
	COutGate *pGate;
	SNSPARAMTABLE *sP = (SNSPARAMTABLE*)pSwitchTable->sSensorParamTable;
	BYTE byOutState = sP->m_sbyOutState;
	pSensor->ConnectFCP(pSensor,&pT->m_nInpGate[sP->m_byID]);
	pSensor->m_byAmOutGate = pSwitchTable->byAmOutGate;
    for (i=0;i<pSwitchTable->byAmOutGate;i++)
    {
	  New(sizeof(COutGate),pGate);
	  InitObject(COutGate,pGate);
	  sG = (SOUTGATE*)pSwitchTable->sOutGate[i];
	  pSL = pT->m_pComputer->GetSlot(pT->m_pComputer,sG->byOutSlotNumber);
	  pPN = pSL->GetPin(pSL->pChld,sG->byOutPinNumber);
	  pGate->Init(pGate,
		          sG->byID,
		          sG->byType,
		          sG->byOType,
		          sG->byMode,
                  sG->rMinRamp,  
		          sG->rMaxRamp,
		          pPN,
		          sG->wLoLimit,
		          sG->wHiLimit,
		          sG->wCurrOpen,
		          byOutState,
                  sP->m_swMaxAcpInp,  
				  sG->wOpenTime,
		          sG->chName);
	  pSensor->ConnectOutGate(pSensor,pGate);
    }
}
void CDirectionModule_SwitchDigitalSensor(This,CSensor *pSensor,SSWITCHTABLE *pSwitchTable)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	BYTE i;
	CSlot *pSL;
	CPin  *pPN;
	CComputer *pCM = pT->m_pComputer;
	SDIGGATE  *pDIN = pSwitchTable->sSensorParamTable;
	SDIGGATE  *pDOT = pSwitchTable->sOutGate[0];
    for (i=0;i<pDIN->swAmpin;i++)
    {
	  pSL = pCM->GetSlot(pCM,pDIN->sPinGate[i].sbySlot);
	  pPN = pSL->GetPin(pSL->pChld,pDIN->sPinGate[i].sbyPin);
	  pSensor->m_pINP[i] = pPN;
	}
    for (i=0;i<pDOT->swAmpin;i++)
    {
	  pSL = pCM->GetSlot(pCM,pDOT->sPinGate[i].sbySlot);
	  pPN = pSL->GetPin(pSL->pChld,pDOT->sPinGate[i].sbyPin);
	  pSensor->m_pOUT[i] = pPN;
	}
	pSensor->ConnectPinAddres(pSensor);
}
void CDirectionModule_ConnectToAdmin(This,CAdmin *pAdmin)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	pT->m_pAdmin = pAdmin;
}
_GLOBAL INT  inAmSens,wwLen;
WORD CDirectionModule_GetInOutData(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	INT i,wLen;
	CSensor *p;
	BYTE *pM,*pIT,*pOT,*pW;
    pMsg->m_sbyFrom      = MDL_DIRMD;  
	pMsg->m_sbyFor       = MDL_ARMSY;  
	pMsg->m_sbyIntType   = DEV_ARM_PORT_TCP;  
	pMsg->m_sbyType      = EV_OBSRV_GET_INOUT_SDATA_IND;
	pMsg->m_sbyServerID  = pT->m_bySystemID;  
	pMsg->m_sbyDirection = pT->m_byDirectionID;
	pMsg->m_sbySensor    = 0xff;
	pM    = &pMsg->m_sbyInfo[0];
	pM[0] = pT->m_byAmSwitching;
	pM[1] = 4;
	inAmSens = 0;
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	  p = pT->m_pSensor[i];
	  pIT = (BYTE*)&p->m_nInPin;
	  pOT = (BYTE*)&p->m_nOutPin;
	  inAmSens++;
      #ifndef WIN32	  
	  pM[2+4*i+1]   = pIT[0];
	  pM[2+4*i+0]   = pIT[1];
	  pM[2+4*i+2+1] = pOT[0];
	  pM[2+4*i+2+0] = pOT[1];
	  #else
	  pM[2+4*i+0]   = pIT[0];
	  pM[2+4*i+1]   = pIT[1];
	  pM[2+4*i+2+0] = pOT[0];
	  pM[2+4*i+2+1] = pOT[1];
	  #endif
	}
	wLen = 9+1+1+4*pT->m_byAmSwitching;
	#ifndef WIN32	  
	pIT   = (BYTE*)pMsg;
	pOT   = (BYTE*)&wLen;
	pIT[1] = pOT[0];
	pIT[0] = pOT[1];
    #endif
	return wLen;
}
void CDirectionModule_GetDirMode(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	BYTE i;
	WORD wState = 0;
	CSensor *p;
	BYTE *pM,*pW,*pW0;
    pMsg->m_sbyFrom      = MDL_DIRMD;  
	pMsg->m_sbyFor       = MDL_ARMSY;  
	pMsg->m_sbyIntType   = DEV_ARM_PORT_TCP;  
	pMsg->m_sbyType      = EV_OBSRV_GET_MODE_IND;
	pMsg->m_sbyServerID  = pT->m_bySystemID;  
	pMsg->m_sbyDirection = pT->m_byDirectionID;
	pMsg->m_sbySensor    = 0xff;
	pMsg->m_sbyInfo[0]   = pT->m_byAmSwitching;
	pMsg->m_sbyInfo[1]   = 2;
	pM = &pMsg->m_sbyInfo[2];
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	 p = pT->m_pSensor[i];
	 if(p->m_sPT.m_sbyMode==SNS_MD_AUTO)wState |= 1<<i;
	}
	pMsg->m_swLen = 9+1+1+2;
	pW  = (BYTE*)&wState;
    #ifndef WIN32	  
	pM[1] = pW[0];
	pM[0] = pW[1];
    #else
    memcpy(pM,pW,2);
    #endif
	FPUT(DEV_ARMOT_BOX_ID,(BYTE*)pMsg);
	//Info("\n(%b)CDIRC::>MOD:MSG:%M",&pT->m_bySystemID,(BYTE*)pMsg); 
}
void CDirectionModule_SetDirMode(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	BYTE i;
	WORD wMode;
	CSensor *p;
	wMode  = pT->GetWordParam(pT,&pMsg->m_sbyInfo[2]);
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	 p = pT->m_pSensor[i];
     if(wMode&(1<<i))p->SetAutoMode(p);else p->SetManMode(p);
	}
}
DWORD CDirectionModule_GetDwordParam(This,BYTE *pbyParam)
{
    DECLARE_SINGLE_OPEN(CSensor)
	DWORD dwValue;
	BYTE *pR = (BYTE*)&dwValue;
    #ifndef WIN32
	pR[3] = pbyParam[0];
	pR[2] = pbyParam[1];
	pR[1] = pbyParam[2];
	pR[0] = pbyParam[3];
    #else    		
	memcpy(&dwValue,pbyParam,4);
	#endif    		
	return dwValue;
}
WORD CDirectionModule_GetWordParam(This,BYTE *pbyParam)
{
    DECLARE_SINGLE_OPEN(CSensor)
	WORD wValue;
	BYTE *pR = (BYTE*)&wValue;
    #ifndef WIN32
	pR[1] = pbyParam[0];
	pR[0] = pbyParam[1];
    #else    		
	memcpy(&wValue,pbyParam,2);
	#endif    		
	return wValue;
}
WORD CDirectionModule_GetDigMcData(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	INT i,j;
	WORD wLen,wOut;
	CSensor *p;
	BYTE *pM,*pIT,*pOT;
    pMsg->m_sbyFrom      = MDL_DIRMD;  
	pMsg->m_sbyFor       = MDL_ARMSY;  
	pMsg->m_sbyIntType   = DEV_ARM_PORT_TCP;  
	pMsg->m_sbyType      = EV_OBSRV_GET_DMC_DATA_IND;
	pMsg->m_sbyServerID  = pT->m_bySystemID;  
	pMsg->m_sbyDirection = pT->m_byDirectionID;
	pMsg->m_sbySensor    = 0xff;
	pM    = &pMsg->m_sbyInfo[0];
	pM[0] = pT->m_byAmSwitching;
	pM[1] = 8;
	wLen = 9+1+1;
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	 p = pT->m_pSensor[i];
	 pT->AddDword(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&p->m_dwInState);
	 pT->AddDword(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&p->m_dwOutState);
	}
	#ifndef WIN32	  
	pIT   = (BYTE*)pMsg;
	pOT   = (BYTE*)&wLen;
	pIT[1] = pOT[0];
	pIT[0] = pOT[1];
    #else
    pMsg->m_swLen = wLen; 
    #endif
	return wLen;
}
WORD CDirectionModule_GetXWData(This,SMESSAGE *pMsg)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	INT i;
	WORD wLen,wOut,wIN;
	WORD wState=0,wLoArarmLimit=0,wHiArarmLimit=0,wSensorAlarm=0;
	CSensor *p;
	COutGate *pG;
	CInputGate *pI;
	UINT nInput;
	BYTE *pM,*pIT,*pOT,k=0;
    pMsg->m_sbyFrom      = MDL_DIRMD;  
	pMsg->m_sbyFor       = MDL_ARMSY;  
	pMsg->m_sbyIntType   = DEV_ARM_PORT_TCP;  
	pMsg->m_sbyType      = EV_OBSRV_GET_OUT_DATA_IND;
	pMsg->m_sbyServerID  = pT->m_bySystemID;  
	pMsg->m_sbyDirection = pT->m_byDirectionID;
	pMsg->m_sbySensor    = 0xff;
	pM    = &pMsg->m_sbyInfo[0];
	pM[0] = pT->m_byAmInpGate;
	pM[1] = pT->m_byAmSwitching;
	wLen = 9+1+1;wIN = 9+1+1+2*pT->m_byAmInpGate+4*pT->m_byAmSwitching;
	for(i=0;i<pT->m_byAmInpGate;i++)
	{
	 pI = &pT->m_nInpGate[i];
	 nInput = pI->GetMInput(pI);
	 pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&nInput);
	 nInput = pI->m_pInpValue;
	 if((nInput>32700)||(nInput<6000))wSensorAlarm |= 0x1<<i;
	}
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	 p = pT->m_pSensor[i];
	 pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&p->m_iIPHiLimit);
	 pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&p->m_iIPLoLimit);
	 pG = p->m_pOutGate[0]; pM[wIN-9+k++] = pG->GetPrcGate(pG);
	 if(abs(p->m_nInPin-p->m_iPHiLimit)<1000) wState |= 0x1<<i;
	 if(p->m_blAlmLoLevel) wLoArarmLimit |= 0x1<<i;
	 if(p->m_blAlmHiLevel) wHiArarmLimit |= 0x1<<i;
	}
    wLen+=k; 
    pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&wState);
	pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&pT->m_wSensorMode);
	pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&pT->m_wLayerMode);
	pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&wLoArarmLimit);
	pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&wHiArarmLimit);
	pT->AddWord(pT,&wLen,((BYTE*)pMsg+wLen),(BYTE*)&wSensorAlarm);
	#ifndef WIN32	  
	pIT   = (BYTE*)pMsg;
	pOT   = (BYTE*)&wLen;
	pIT[1] = pOT[0];
	pIT[0] = pOT[1];
    #else
    pMsg->m_swLen = wLen; 
    #endif
	return wLen;
}
void CDirectionModule_AddDword(This,WORD *pwLen,BYTE *byMsg,BYTE *byParam)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
    #ifndef WIN32	  
    byMsg[3] = byParam[0];
    byMsg[2] = byParam[1];
    byMsg[1] = byParam[2];
    byMsg[0] = byParam[3];
    #else
    memcpy(byMsg,byParam,4);
    #endif
    *pwLen += 4;
}
void CDirectionModule_AddWord(This,WORD *pwLen,BYTE *byMsg,BYTE *byParam)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
    #ifndef WIN32	  
    byMsg[1] = byParam[0];
    byMsg[0] = byParam[1];
    #else
    memcpy(byMsg,byParam,2);
    #endif
    *pwLen += 2;
}
void CDirectionModule_WordXCHG(This,SMESSAGE *pMsg)
{
	DECLARE_SINGLE_OPEN(CDirectionModule)
    #ifndef WIN32
	BYTE byTmp,*pW = (BYTE*)pMsg; 
	byTmp = pW[0];
	pW[0] = pW[1];
	pW[1] = byTmp;
    #endif
}
void CDirectionModule_EnableGetData(This,BOOL byState)
{
     DECLARE_SINGLE_OPEN(CDirectionModule)
	 pT->m_blGetData = byState;
}
void CDirectionModule_ObserveProc(This)
{
	DECLARE_SINGLE_OPEN(CDirectionModule) 
	CSensor *p;INT i;
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	 p = pT->m_pSensor[i];
	 if (p->m_bySensorType!=SNS_EMPTY) p->ObserveProc(p);
	}
}
void CDirectionModule_ConnectToComputer(This,CComputer *pComputer)
{
    DECLARE_SINGLE_OPEN(CDirectionModule) 
	pT->m_pComputer = pComputer;
}
//_GLOBAL INT nValue_0,nValue_1,nValue_2,nValue_3,nValue_4,nValue_5,nValue_6;
BOOL CDirectionModule_Serialize(This,BOOL blDir)
{
	DECLARE_SINGLE_OPEN(CDirectionModule)
	BOOL res = TRUE;
	if (blDir==TRUE) res = pT->SaveContenst(pT);
	if (blDir==FALSE)res = pT->LoadContenst(pT);
	return res;
}
BOOL CDirectionModule_SaveContenst(This)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	BOOL res = TRUE;
	pT->SaveTable(pT,&pT->m_nCT);
	//nValue_0++;
	if (!pT->m_pFlash->CompareMemory(pT->m_pFlash,(BYTE*)&pT->m_nCT,sizeof(SCONTENSTTABLE)))
	{
	 //nValue_1++;
	 //if (!pT->m_pFlash->WriteFlash(pT->m_pFlash,(BYTE*)&pT->m_nCT,sizeof(SCONTENSTTABLE))) 
     if (!pT->m_pFlash->WriteFlashRem(pT->m_pFlash,(BYTE*)&pT->m_nCT,sizeof(SCONTENSTTABLE))) 
	 {
	 	//nValue_2++;
		res = FALSE;
	 }
	}
	return res;
}
BOOL CDirectionModule_LoadContenst(This)
{
    DECLARE_SINGLE_OPEN(CDirectionModule)
	BOOL res = FALSE;
	pT->m_nST.m_bySystemID = 0xff;
	if (pT->m_pFlash->ReadFlash(pT->m_pFlash,(BYTE*)&pT->m_nST,sizeof(SCONTENSTTABLE)))
	{
	 if(pT->m_nST.m_byDefInit==1) return FALSE;
	 if(pT->m_nST.m_byDefInit==0)
	 {
	  if (pT->m_nST.m_bySystemID==pT->m_bySystemID)
	  {
      pT->LoadTable(pT,&pT->m_nST);
	  res = TRUE;
	  }
	 }
	}
	return res;
}
void CDirectionModule_SaveTable(This,SCONTENSTTABLE *psTable)
{
    DECLARE_SINGLE_OPEN(CDirectionModule) 
	BYTE i;
	COutGate *pG;
	memset(psTable,0,sizeof(SCONTENSTTABLE));
	#if MYSYSTEM_ID != 4 
	psTable->sInGate.byAmInGate   = pT->m_byAmInpGate;
	psTable->sOutGate.byAmOutGate = pT->m_byAmSwitching;
	psTable->m_byDefInit          = pT->m_byDefSett;
	for(i=0;i<pT->m_byAmInpGate;i++) psTable->mInResistance[i] = pT->m_nInpGate[i].m_rCurrRes;
	for(i=0;i<pT->m_byAmSwitching;i++) 
	{
     memcpy(&psTable->sInGate.mIn[i],&pT->m_pSensor[i]->m_sPT,sizeof(SNSPARAMTABLE));
	 memcpy(&psTable->sOutGate.mOut[i],&pT->m_pSensor[i]->m_sGT,sizeof(SOUTGATE));
	 pG = pT->m_pSensor[i]->m_pOutGate[0];
	 psTable->sOutGate.mOut[i].wCurrOpen = pG->GetPrcGate(pG);
	 psTable->m_bySystemID = pT->m_bySystemID;
	}
	psTable->m_wLayerMode = pT->m_wLayerMode;
    #else
	psTable->m_bySystemID = pT->m_bySystemID;
    for(i=0;i<pT->m_byAmSwitching;i++) psTable->m_dwOutState[i] = pT->m_pSensor[i]->m_dwOutState;
    #endif
}
void CDirectionModule_LoadTable(This,SCONTENSTTABLE *psTable)
{
    DECLARE_SINGLE_OPEN(CDirectionModule) 
	BYTE i;
	pT->m_byDefSett = psTable->m_byDefInit;
	#if MYSYSTEM_ID != 4 
	for(i=0;i<pT->m_byAmInpGate;i++) pT->m_nInpGate[i].SetResistance(&pT->m_nInpGate[i],psTable->mInResistance[i]);
	for(i=0;i<pT->m_byAmSwitching;i++)
	{
	 pT->m_pDirTable->sSwitchTable[i].sSensorParamTable = &psTable->sInGate.mIn[i];
	 pT->m_pDirTable->sSwitchTable[i].sOutGate[0]       = &psTable->sOutGate.mOut[i];
	}
    #else
	for(i=0;i<pT->m_byAmSwitching;i++) pT->m_pSensor[i]->m_dwOutState = psTable->m_dwOutState[i];
    #endif
}
void CDirectionModule_SetCurentTank(This,BYTE byTank)
{
    DECLARE_SINGLE_OPEN(CDirectionModule) 
	if(pT->m_bySystemID==3)
	{
	 if((byTank>=0)&&(byTank<=1))
	 {
	  pT->m_wLayerMode &= 0xfc;
	  pT->m_pSensor[0]->m_nInp = &pT->m_nInpGate[byTank];
	  pT->m_pSensor[0]->m_sPT.m_swResistance = pT->m_nInpGate[byTank].m_rCurrRes;
	 }
	 if((byTank>=2)&&(byTank<=3))
	 {
	  pT->m_wLayerMode &= 0xf3;
	  pT->m_pSensor[1]->m_nInp = &pT->m_nInpGate[byTank];
	  pT->m_pSensor[1]->m_sPT.m_swResistance = pT->m_nInpGate[byTank].m_rCurrRes;
	 }
 	 if((byTank>=4)&&(byTank<=7))
	 {
	  pT->m_wLayerMode &= 0x0f;
	  pT->m_pSensor[2]->m_nInp = &pT->m_nInpGate[byTank];
	  pT->m_pSensor[3]->m_nInp = &pT->m_nInpGate[byTank];
	  pT->m_pSensor[2]->m_sPT.m_swResistance = pT->m_nInpGate[byTank].m_rCurrRes;
	  pT->m_pSensor[3]->m_sPT.m_swResistance = pT->m_nInpGate[byTank].m_rCurrRes;
	 }
	}else 
	{
	  pT->m_wLayerMode = 0;
	  pT->m_pSensor[0]->m_nInp = &pT->m_nInpGate[byTank];
	  pT->m_pSensor[1]->m_nInp = &pT->m_nInpGate[byTank];
	  pT->m_pSensor[0]->m_sPT.m_swResistance = pT->m_nInpGate[byTank].m_rCurrRes;
	  pT->m_pSensor[1]->m_sPT.m_swResistance = pT->m_nInpGate[byTank].m_rCurrRes;
	}
	pT->m_wLayerMode |= 1<<byTank;
}
void CDirectionModule_CDirectionModule(This)
{
    DECLARE_SINGLE_OPEN(CDirectionModule) 
	DECLARE_REGISTRATION(CDirectionModule,Init)
	DECLARE_REGISTRATION(CDirectionModule,ConnectToComputer)
	DECLARE_REGISTRATION(CDirectionModule,SwitchSensor)
	DECLARE_REGISTRATION(CDirectionModule,ObserveProc)
	DECLARE_REGISTRATION(CDirectionModule,GetInOutData)
	DECLARE_REGISTRATION(CDirectionModule,EnableGetData)
	DECLARE_REGISTRATION(CDirectionModule,ConnectToAdmin)
	DECLARE_REGISTRATION(CDirectionModule,EventHandler)
	DECLARE_REGISTRATION(CDirectionModule,WordXCHG)
	DECLARE_REGISTRATION(CDirectionModule,GetXWData)
	DECLARE_REGISTRATION(CDirectionModule,GetDirMode)
	DECLARE_REGISTRATION(CDirectionModule,SetDirMode)
	DECLARE_REGISTRATION(CDirectionModule,GetDwordParam)
	DECLARE_REGISTRATION(CDirectionModule,GetWordParam)
	DECLARE_REGISTRATION(CDirectionModule,AddDword)
	DECLARE_REGISTRATION(CDirectionModule,AddWord)
	DECLARE_REGISTRATION(CDirectionModule,SwitchDigitalSensor)
	DECLARE_REGISTRATION(CDirectionModule,GetDigMcData)
	DECLARE_REGISTRATION(CDirectionModule,SetInputGate)
 	DECLARE_REGISTRATION(CDirectionModule,Serialize)
	DECLARE_REGISTRATION(CDirectionModule,SaveContenst)
	DECLARE_REGISTRATION(CDirectionModule,LoadContenst)
	DECLARE_REGISTRATION(CDirectionModule,SaveTable)
	DECLARE_REGISTRATION(CDirectionModule,LoadTable)
	DECLARE_REGISTRATION(CDirectionModule,SetCurentTank)
	InitObject(CMTimer,&pT->m_pStatSnsTmr);
	pT->m_pStatSnsTmr.SetTimer(&pT->m_pStatSnsTmr,MDL_DIRMD,MDL_DIRMD,EV_DIRMD_REFR_TIM_PROC_IND,0,0,DEV_SYSTM_BOX_ID);	
}
void CDirectionModule_DCDirectionModule(This)
{
	DECLARE_SINGLE_OPEN(CDirectionModule) 
	BYTE i,byType;
	for (i=0;i<pT->m_byAmSwitching;i++)
	{
	 byType = pT->m_pSensor[i]->m_bySwitchCommand;
	 if(byType==SWC_CMD_SMR_CON)DestroyObject(CSmartSensor,pT->m_pSensor[i]->pChld);
	 if(byType==SWC_CMD_IDL_CON)DestroyObject(CIdleSensor,pT->m_pSensor[i]->pChld);
	 if(byType==SWC_CMD_EMT_CON)DestroyObject(CSensor,pT->m_pSensor[i]);
	 if(byType==SWC_CMD_LOG_CON)DestroyObject(CDigitalSensor,pT->m_pSensor[i]->pChld);
	}
	Delete(sizeof(CSensor*)*pT->m_byAmSwitching,pT->m_pSensor);
}
DECLARE_SINGLE_CREATE(CDirectionModule)
#endif
