/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrobserve.h"
#if MYSYSTEM_ID != 5
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
CObserveModule *pvOBS;
_GLOBAL PFNVOID pfnAnalogDataReq; 
_GLOBAL PFNVOID pfnDigitalDataReq; 
void AnalogDataReq(void);
void DigitalDataReq(void);
void CObserveModule_Init(This,SSOFTSWITCHTABLE *pSoftSwitchTable)
{
    DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem) 
	pvOBS = pT;
	pfnAnalogDataReq  = AnalogDataReq;
    pfnDigitalDataReq = DigitalDataReq;
	pT->m_byTableVersion = pSoftSwitchTable->byTableVersion;
	strcpy(pT->m_chTableVersionName,pSoftSwitchTable->chTableVersionName);
	pT->m_byAmDirection = pSoftSwitchTable->byAmDirection;
    //#ifdef DEB_CObserveModule
	Info("\n(__)COBSE::>Create Observation Module: %s",pSoftSwitchTable->chTableVersionName);
    //#endif
    pT->CreateObserve(pT,pSoftSwitchTable);
	pT->m_byObsTime = T2SEC;
	InitObject(CMTimer,&pT->m_pRefrechTmr);
	pT->m_pRefrechTmr.SetTimer(&pT->m_pRefrechTmr,MDL_OBSRV,MDL_OBSRV,EV_OBSRV_REFR_TIM_PROC_IND,0,0,DEV_SYSTM_BOX_ID);
}
_GLOBAL INT iCObserveModuleVal;
void CObserveModule_CreateObserve(This,SSOFTSWITCHTABLE *pSoftSwitchTable)
{
    DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem) 
	CDirectionModule *p;
	INT i;
	InitObject(CMFlash,&pT->m_nFlash);
	pT->m_byAmDirection = pSoftSwitchTable->byAmDirection;
	New(sizeof(CDirectionModule*)*pT->m_byAmDirection,pT->m_pDirectionModule);
	for(i=0;i<pT->m_byAmDirection;i++)
	{
	 New(sizeof(CDirectionModule),p);
	 InitObject(CDirectionModule,p);
	 if(p!=NULL)
	 {
	  iCObserveModuleVal++;
	  p->ConnectToComputer(p,pT->m_pComputer);
      p->ConnectToAdmin(p,pT->m_pAdmin);
	  p->m_bySystemID = pT->m_bySystemID;
	  p->Init(p,&pSoftSwitchTable->sDirectionTable[i],&pT->m_nFlash);
	  pT->m_pDirectionModule[i] = p;
	 }
	}
}
void CObserveModule_SetSystemID(This,BYTE bySystemID)
{
     DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
     pT->m_bySystemID = bySystemID;
}
void CObserveModule_ConnectToAdmin(This,CAdmin *pAdmin)
{
     DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
	 pT->m_pAdmin = pAdmin;
}
//_GLOBAL INT nVAL_0;
BOOL CObserveModule_EventHandler(This,SMESSAGE *pMsg)
{
	 BOOL res = TRUE;
     DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
	 CDirectionModule *pD;SPIN sP;CSensor *pS;
	 WORD wValue,wValue1; BYTE byValue,*pBT;
	 #ifdef DEB_CObserveModule
	 if(dwFL&DEB_OUT_OBSR_COMM)
	 Info("\n(%b)COBSE::>MSG::%M",&pT->m_bySystemID,(BYTE*)pMsg);
     #endif
     switch (pMsg->m_sbyFor)
	 {
		case MDL_OBSRV:
             switch (pMsg->m_sbyType)
			 {
                case EV_OBSRV_GET_MODE_REQ: //Запросить выходное состояние сенсоров направления	140
                     if((pD=pT->GetDirection(pT,pMsg->m_sbyDirection))!=0)
					 {
					 pD->GetDirMode(pD,pMsg);
					 #ifdef DEB_CObserveModule
					 if(dwFL&DEB_OUT_OBSR_COMM)
					 Info("\n(%b)COBSE::>DC(%b,X)SET_MODE",&pT->m_bySystemID,&pMsg->m_sbyDirection);
                     #endif					 
					 }
     	        break;
				case EV_OBSRV_SET_MODE_REQ:
					 if((pD=pT->GetDirection(pT,pMsg->m_sbyDirection))!=0)
					 {
					 pD->SetDirMode(pD,pMsg);
                     #ifdef DEB_CObserveModule
					 if(dwFL&DEB_OUT_OBSR_COMM)
					 Info("\n(%b)COBSE::>DC(%b,X)SET_MODE",&pT->m_bySystemID,&pMsg->m_sbyDirection);
                     #endif					 
					 }
				break;
				case EV_OBSRV_START_DATA_PROC_REQ:
					 byValue = pMsg->m_sbyInfo[1];
					 pT->m_byObserveProc = pMsg->m_sbyInfo[2];
                     pT->m_byObsTime = byValue;
                     pT->m_pRefrechTmr.OnTimer(&pT->m_pRefrechTmr,pT->m_byObsTime);
					 //pT->m_pRefrechTmr.OnTimer(&pT->m_pRefrechTmr,10);
                     //#ifdef DEB_CObserveModule
					 //if(dwFL&DEB_OUT_OBSR_COMM)
					 //Info("\n(%b)COBSE::>DC(%b,X)START_DATA_PROC_REQ:[%b]:[%b]",&pT->m_bySystemID,&pMsg->m_sbyDirection,&byValue,&pT->m_byObserveProc);
                     //#endif
				break;
				case EV_OBSRV_STOP_DATA_PROC_REQ:
					 pT->m_pRefrechTmr.OfTimer(&pT->m_pRefrechTmr);
                     #ifdef DEB_CObserveModule
					 if(dwFL&DEB_OUT_OBSR_COMM)
					 Info("\n(%b)COBSE::>DC(%b,X)STOP_DATA_PROC_REQ",&pT->m_bySystemID,&pMsg->m_sbyDirection);
                     #endif
				break;                
                case EV_OBSRV_REFR_TIM_PROC_IND: //Таймер обновления данных
					 if(pT->m_byObserveProc==0)pT->GetObserveData(pT,EV_OBSRV_GET_OUT_DATA_IND);
					 if(pT->m_byObserveProc==1)pT->GetObserveData(pT,EV_OBSRV_GET_DMC_DATA_IND);
					 //if(pT->m_byObserveProc==0)pfnAnalogDataReq();
					 //if(pT->m_byObserveProc==1)pfnDigitalDataReq();
					 pT->m_pRefrechTmr.OnTimer(&pT->m_pRefrechTmr,pT->m_byObsTime);
					 //pT->m_pRefrechTmr.OnTimer(&pT->m_pRefrechTmr,10);
                     #ifdef DEB_CObserveModule
					 if(dwFL&DEB_OUT_OBSR_COMM)
					 Info("\n(%b)COBSE::>DC(%b,X)GET_INOUT_SDATA_IND",&pT->m_bySystemID,&pMsg->m_sbyDirection);
                     #endif
				break;
				case EV_OBSRV_RFLASH_SAVE_REQ:
				     //nVAL_0++;
					 pT->m_pDirectionModule[0]->m_byDefSett = 0;
			         pT->m_pDirectionModule[0]->Serialize(pT->m_pDirectionModule[0],TRUE);
				break;
                default:
		        break;
			 } 
		break;
		case MDL_PSENS://Digital Sensor
			 if((pS=pT->GetSensor(pT,&pD,pMsg->m_sbyDirection,pMsg->m_sbySensor))!=0)
			 pS->EventHandler(pS->pChld,pMsg);
		break;
        #if MYSYSTEM_ID !=4
		case MDL_SENSR:
			 if((pS=pT->GetSensor(pT,&pD,pMsg->m_sbyDirection,pMsg->m_sbySensor))!=0)
			 pS->SEventHandler(pS,pMsg);
		break;
		case MDL_SSENS:
			 if((pS=pT->GetSensor(pT,&pD,pMsg->m_sbyDirection,pMsg->m_sbySensor))!=0)
	         pS->EventHandler(pS->pChld,pMsg);
		break;
        #endif
		case MDL_DIRMD:
			 if((pD=pT->GetDirection(pT,pMsg->m_sbyDirection))!=0)
			 pD->EventHandler(pD,pMsg);
		break; 
		default:
		break;
	};
	return res;
}
//_GLOBAL INT nAnData;
void AnalogDataReq(void)
{
	pvOBS->GetObserveData(pvOBS,EV_OBSRV_GET_OUT_DATA_IND);
	//nAnData++;
}
void DigitalDataReq(void)
{
    pvOBS->GetObserveData(pvOBS,EV_OBSRV_GET_DMC_DATA_IND);
}
void CObserveModule_GetObserveData(This,BYTE byEvent)
{
	DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
	INT i,j=0;
	CDirectionModule *p;
	SMESSAGE *pM = &pT->m_nMsg;
	BYTE *pMB = &pM->m_sbyInfo[0];
	pM->m_sbyFrom      = MDL_OBSRV;  
	pM->m_sbyFor       = MDL_ARMSY;  
	pM->m_sbyIntType   = DEV_ARM_PORT_TCP;  
	pM->m_sbyType      = byEvent;
	pM->m_sbyServerID  = pT->m_bySystemID;  
	pM->m_sbySensor    = 0xff;
	pM->m_swLen        = 9;
	for(i=0;i<pT->m_byAmDirection;i++)
	{
	 p = pT->m_pDirectionModule[i];
	 if(byEvent==EV_OBSRV_GET_OUT_DATA_IND)j = p->GetXWData(p,(SMESSAGE*)&pMB[j]);
	 if(byEvent==EV_OBSRV_GET_DMC_DATA_IND)j = p->GetDigMcData(p,(SMESSAGE*)&pMB[j]);
	 pM->m_swLen += j;
	 //Info("\n(%b)COBSE::>Put:%w",&pT->m_bySystemID,&pM->m_swLen); 
	}    
	pM->m_sbyDirection = pT->m_byAmDirection;
	if(pT->m_pAdmin->m_blArmState)
	FPUT(DEV_ARMOT_BOX_ID,(BYTE*)pM);
	if(dwFL&DEB_OUT_OBSR_COMM)
	Info("\n(%b)COBSE::>MSG:%M",&pT->m_bySystemID,(BYTE*)pM); 
}
CDirectionModule* CObserveModule_GetDirection(This,BYTE byDir)
{
	DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
	CDirectionModule *pD;
	if(byDir<pT->m_byAmDirection)
		return pD = pT->m_pDirectionModule[byDir];
	return 0;
}
CSensor* CObserveModule_GetSensor(This,CDirectionModule **pD,BYTE byDir,BYTE bySensor)
{
	DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
	CDirectionModule *pDM = *pD;
	if(byDir<pT->m_byAmDirection)
	{
	 pDM = pT->m_pDirectionModule[byDir];
	 *pD = pDM;
	 if(bySensor < pDM->m_byAmSwitching)
	 return pDM->m_pSensor[bySensor];
	}
	return 0;
}
void CObserveModule_CyclicProc(This)
{
	DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem) 
	CDirectionModule *p;INT i;
    for(i=0;i<pT->m_byAmDirection;i++)
	{
	  p = pT->m_pDirectionModule[i];
	  p->ObserveProc(p);
	}
}
void CObserveModule_ConnectToComputer(This,CComputer *pComputer)
{
    DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem) 
	pT->m_pComputer = pComputer;
}
void CObserveModule_CObserveModule(This)
{
    DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem) 
	DECLARE_REGISTRATION(CObserveModule,Init)
	DECLARE_REGISTRATION(CObserveModule,ConnectToComputer)
	DECLARE_REGISTRATION(CObserveModule,CreateObserve)
	DECLARE_REGISTRATION(CObserveModule,GetObserveData)
	DECLARE_REGISTRATION(CObserveModule,SetSystemID)
	DECLARE_REGISTRATION(CObserveModule,GetDirection)
	DECLARE_REGISTRATION(CObserveModule,GetSensor)
	DECLARE_REGISTRATION(CObserveModule,SetSystemID)
	DECLARE_REGISTRATION(CObserveModule,ConnectToAdmin)
	DECLARE_VIRTUAL_FUNC(CObserveModule,EventHandler)
	DECLARE_VIRTUAL_FUNC(CObserveModule,CyclicProc)
}
void CObserveModule_DCObserveModule(This)
{
	DECLARE_MULTI_OPEN(CObserveModule,CCyclicSystem)
	BYTE i;
	for(i=0;i<pT->m_byAmDirection;i++)
	DestroyObject(CDirectionModule,pT->m_pDirectionModule[i]); 
	Delete(sizeof(CDirectionModule*)*pT->m_byAmDirection,pT->m_pDirectionModule);
}
DECLARE_MULTI_CREATE(CObserveModule,CCyclicSystem)
#endif
