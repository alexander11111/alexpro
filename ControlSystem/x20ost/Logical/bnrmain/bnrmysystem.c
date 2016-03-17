/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrmysystem.h"
#include "bnrdirmodule.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#ifdef WIN32
BOOL blStateConnecting = FALSE;
#endif
_GLOBAL INT iCSystemVal;
extern SSOFTSWITCHTABLE  nSoftSwitchTable;
void CSystem_CreateSystem(This,SHARDCOMPUTERTABLE *pTable)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem)
	 #ifdef DEB_CSystem
	 Info("\n(__)CSYST::>Create System: %s",pTable->chProgrammVersion);
     #endif
	 FINIT();
	 pT->m_pAdmin         = NULL;
     pT->m_pComputer      = NULL;
	 pT->m_pObsModule     = NULL;
	 pT->m_byTcpConn      = FALSE;
	 pT->m_bySystemID     = pTable->bySystemID;
	 pB->SetBoxID(pB,DEV_SYSTM_BOX_ID);
	 iCSystemVal++;
	 pT->CreateSysBox(pT);
     pT->CreateComputer(pT,pTable);
	 pT->CreateAdmin(pT);
	 pT->CreateProc(pT);
	 pT->CreateObserveModule(pT,pTable,&nSoftSwitchTable);
     #ifdef WIN32
	 //CreateGetProc(pT);
     #endif
	 //pT->m_blSystemInitState = 0;
}
void CSystem_CreateComputer(This,SHARDCOMPUTERTABLE *pTable)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	 pT->m_pComputer = NULL;
     New(sizeof(CComputer),pT->m_pComputer);
	 InitObject(CComputer,pT->m_pComputer);
	 if(pT->m_pComputer!=NULL)
	 {
      pT->m_pComputer->Init(pT->m_pComputer,pTable);
	 }
}
void CSystem_CreateAdmin(This)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	 pT->m_pAdmin = NULL;
     New(sizeof(CAdmin),pT->m_pAdmin);
	 InitObject(CAdmin,pT->m_pAdmin);
	 if(pT->m_pAdmin!=NULL)
	 {
	  pT->m_pAdmin->SetSystemID(pT->m_pAdmin,pT->m_bySystemID);
	  pT->m_pAdmin->Init(pT->m_pAdmin);
	 }
}
void CSystem_CreateSysBox(This)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
 	 //FDEFINE(DEV_SYSTM_BOX_ID,DEV_SYSTM_BOX_SZ);
	 FDEFINE(DEV_ADMIN_BOX_ID,DEV_ADMIN_BOX_SZ);
	 //FDEFINE(DEV_ARMOT_BOX_ID,DEV_ARMOT_BOX_SZ);
 	 //FDEFINE(DEV_ARMAD_BOX_ID,DEV_ARMAD_BOX_SZ);
} 
/*
     CComVS0    *m_nCVS0;
     CComVS1    *m_nCVS1;
	 CTcpServer *m_nTCP;
*/


void CSystem_CreateObserveModule(This,SHARDCOMPUTERTABLE *pTable,SSOFTSWITCHTABLE *pSoftSwitchTable)
{
	 
	 DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	 	 	 
	 /*
	 New(sizeof(CKpModule),pT->m_pObsModule);
     InitObject(CKpModule,pT->m_pObsModule);
	 pT->m_pObsModule->m_pComputer = pT->m_pComputer;
	 if(pT->m_pObsModule!=NULL)pT->m_pObsModule->Init(pT->m_pObsModule,pTable,pSoftSwitchTable);
	 FCREATE(pT->m_pObsModule->pBase,"KPProc",DEV_CJOB_ST_RESM,1);

	 New(sizeof(CModule101),pT->m_p101);
	 InitObject(CModule101,pT->m_p101);
	 if(pT->m_p101!=NULL)pT->m_p101->Init(pT->m_p101);
	 FCREATE(pT->m_p101->pBase,"M101Proc",DEV_CJOB_ST_RESM,1);
	 */
/*
SARMINTERFACE nARM0   = {0,DEV_ARM_PORT_COM232,DEV_ARM_RATE_57600,0,{0    ,    0},{  EVEN,  D_8,  S_1,  0}};
SARMINTERFACE nARM1   = {1,DEV_ARM_PORT_COM232,DEV_ARM_RATE_57600,0,{0    ,    0},{  EVEN,  D_8,  S_1,  0}};
SARMINTERFACE nARM2   = {2,DEV_ARM_PORT_COM232,DEV_ARM_RATE_57600,0,{0    ,    0},{  EVEN,  D_8,  S_1,  0}};

SARMINTERFACE nARMTCP = {3,DEV_ARM_PORT_TCP,DEV_ARM_RATE_57600,0,{20001   ,20002},{  192,  168,  1,  4},"192.168.1.4"};
SARMINTERFACE nARMUDP = {4,DEV_ARM_PORT_UDP,DEV_ARM_RATE_100MB,0,{20003   ,20004},{  192,  168,  1,  5},"192.168.1.5"};
*/
     
	 
	 New(sizeof(CMsModule),pT->m_nMS);
	 InitObject(CMsModule,pT->m_nMS);
	 pT->m_nMS->m_pComputer = pT->m_pComputer; 
	 if(pT->m_nMS!=NULL)pT->m_nMS->Init(pT->m_nMS,pTable,pSoftSwitchTable);
	 FCREATE(pT->m_nMS->pBase,"Measure",DEV_CJOB_ST_RESM,1);
     

	 New(sizeof(CComServer),pT->m_nCom);
     InitObject(CComServer,pT->m_nCom);
	 if(pT->m_nCom!=NULL)pT->m_nCom->Init(pT->m_nCom,pTable->pArmInterface[0]);
	 FCREATE(pT->m_nCom->pBase,"RsProc",DEV_CJOB_ST_RESM,1);
	 
	 New(sizeof(CComVS0),pT->m_nCVS0);
	 InitObject(CComVS0,pT->m_nCVS0);
	 if(pT->m_nCVS0!=NULL)pT->m_nCVS0->Init(pT->m_nCVS0,pTable->pArmInterface[1]);
	 FCREATE(pT->m_nCVS0->pBase,"RsVS0Proc",DEV_CJOB_ST_RESM,1);

	 New(sizeof(CComVS1),pT->m_nCVS1);
	 InitObject(CComVS1,pT->m_nCVS1);
	 if(pT->m_nCVS1!=NULL)pT->m_nCVS1->Init(pT->m_nCVS1,pTable->pArmInterface[2]);
	 FCREATE(pT->m_nCVS1->pBase,"RsVS1Proc",DEV_CJOB_ST_RESM,1);

	 
	 New(sizeof(CTcpServer),pT->m_nTCP);
	 InitObject(CTcpServer,pT->m_nTCP);
	 if(pT->m_nTCP!=NULL)pT->m_nTCP->Init(pT->m_nTCP,pTable->pArmInterface[3]);
	 FCREATE(pT->m_nTCP->pBase,"RsTCPProc",DEV_CJOB_ST_RESM,1);
	 
}
void CSystem_CreateProc(This)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem)
	 //FCREATE(pB                         ,"SystemProc" ,DEV_CJOB_ST_RESM,1);
	 FCREATE(pT->m_pAdmin->pBase        ,"AdminProc"  ,DEV_CJOB_ST_RESM,4);
}
/*
void CSystem_CyclicProc(This)
{
	 DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	 pB->m_dwAmoutQuant++;
     #ifdef DEB_CSystem 
	 if(dwFL&DEB_OUT_CYC_SYSTM)
	 Info("\n(%b)CSYST::>Cyclic Process.",&pB->m_dwAmoutQuant);
     #endif
 	 pB->GetMessage(pB);
}
*/
BOOL CSystem_EventHandler(This,SMESSAGE *pMsg)
{
	 DECLARE_MULTI_OPEN(CSystem,CCyclicSystem)
	 BOOL res = TRUE;
	 //CObserveModule *pOB;
	 //CDirectionModule *pD;
     BYTE byFrequency;
     #ifdef DEB_CSystem 
	 if(dwFL&DEB_OUT_BOX_SYSTM)
	 Info("\n(%b)CSYST::>MSG::%M",&pMsg->m_sbyServerID,(BYTE*)pMsg);
	 #endif
	 switch (pMsg->m_sbyFor)
	 {
       case MDL_HCOMM: 
	   case MDL_ADMIN:
            FPUT(DEV_ADMIN_BOX_ID,(BYTE*)pMsg);
	   break;
	   case MDL_SYSTM:
		   switch(pMsg->m_sbyType)
		   {
		     case EV_SYSTM_RESET_BOARD_IND:
                  #if MYSYSTEM_ID != 5
				  pD = pT->m_pObsModule->m_pDirectionModule[0]; 
				  pD->m_byDefSett = pMsg->m_sbyInfo[1];
				  pD->Serialize(pD,TRUE);
                  #endif
				  pT->m_pResetTimer.OnTimer(&pT->m_pResetTimer,T5SEC);
			 break;  
			 case EV_SYSTM_RESET_TIM_BRD_IND:
				  //Info("\n(%w)CSYST::>Reset Board",&pT->m_bySystemID);
				  #ifndef WIN32
				  SYSreset(1, 1);
				  #endif
			 break;
		     case EV_SYSTM_INIT_OBS_REQ:
				  //Info("\n(%w)CSYST::>%M",&pT->m_bySystemID,(BYTE*)pMsg);
				  //pT->CreateObserveModule(pT,&nSoftSwitchTable);
				  pT->SendMessage(pT,MDL_ADMIN,EV_SYSTM_INIT_OBS_IND);
			 break;
		     case EV_SYSTM_CLOSE_INPOTRS_REQ:  //Закрыть все входные порты 	96
			 break;  
		     case EV_SYSTM_OPEN_INPOTRS_REQ:   //Открыть все входные порты	97
			 break;  
		     case EV_SYSTM_CLOSE_OUTPOTRS_REQ: //Закрыть все выходные порты	98
			 break;   
		     case EV_SYSTM_OPEN_OUTPOTRS_REQ:  //Открыть все выходные порты	99
			 break;  
		     case EV_SYSTM_STOP_JOB_REQ:       //Остановить задачу	100
				  if (pMsg->m_sbyInfo[1]==0)  pT->m_pObsModule->pBase->Stop(pT->m_pObsModule->pBase);               //Observe
				  if (pMsg->m_sbyInfo[1]==1)  pT->pBase->Stop(pT->pBase);                                                   //System
				  if (pMsg->m_sbyInfo[1]==2)  pT->m_pAdmin->pBase->Stop(pT->m_pAdmin->pBase);                               //Admin
			 break;  
		     case EV_SYSTM_START_JOB_REQ:      //Запустить задачу	101
				  if (pMsg->m_sbyInfo[1]==0)  pT->m_pObsModule->pBase->Start(pT->m_pObsModule->pBase);               //Observe
				  if (pMsg->m_sbyInfo[1]==1)  pT->pBase->Start(pT->pBase);                                                   //System
				  if (pMsg->m_sbyInfo[1]==2)  pT->m_pAdmin->pBase->Start(pT->m_pAdmin->pBase);                               //Admin
			 break;  
		     case EV_SYSTM_FREQ_JOB_REQ:       //Установить частоту вызова задачи	102
				  byFrequency = pMsg->m_sbyInfo[2];
				  if (pMsg->m_sbyInfo[1]==0)  pT->m_pObsModule->pBase->SetPeriod(pT->m_pObsModule->pBase,byFrequency);//Observe
				  if (pMsg->m_sbyInfo[1]==1)  pT->pBase->SetPeriod(pT->pBase,byFrequency);                                    //System
				  if (pMsg->m_sbyInfo[1]==2)  pT->m_pAdmin->pBase->SetPeriod(pT->m_pAdmin->pBase,byFrequency);                //Admin
			 break;  
		     default:
			 break;
			}
	   break;
	   case MDL_PSENS:
	   case MDL_SENSR:
       case MDL_SSENS:
	   case MDL_DIRMD:
       case MDL_OBSRV:
		    pT->m_pObsModule->EventHandler(pT->m_pObsModule,pMsg);
	   break;
	   case MDL_COMPT:
	   break;
	   default:
	   break;
	 }
     return res;
}
BOOL CSystem_SendMessage(This,BYTE byFor,BYTE byType)
{
	 BOOL res = TRUE;
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	 SHORTMESSAGE m_sSysMsg;
	 m_sSysMsg.m_swLen        = 9;
	 m_sSysMsg.m_sbyFrom      = MDL_SYSTM;
	 m_sSysMsg.m_sbyFor       = byFor;
	 m_sSysMsg.m_sbyIntType   = DEV_SYS_INTERFACE;
	 m_sSysMsg.m_sbyServerID  = pT->m_bySystemID;
	 m_sSysMsg.m_sbyType      = byType;
	 m_sSysMsg.m_sbyDirection = 0;
	 m_sSysMsg.m_sbySensor    = 0;
	 FPUT(DEV_SYSTM_BOX_ID,(BYTE*)&m_sSysMsg);		 
	 return res;
}
void CSystem_SendMsg(This,SMESSAGE *pMsg)
{
	 DECLARE_MULTI_OPEN(CSystem,CCyclicSystem)  
	 /*
	 INT byMsg;
	 pT->m_sSysMsg.m_swLen        = 20;
	 pT->m_sSysMsg.m_sbyFrom      = MDL_SYSTM;  
	 pT->m_sSysMsg.m_sbyFor       = MDL_ANOUT;  
	 pT->m_sSysMsg.m_sbyIntType   = 0;  
	 pT->m_sSysMsg.m_sbyServerID  = 0;  
	 pT->m_sSysMsg.m_sbyType      = 23;
	 pT->m_sSysMsg.m_sbyDirection = 5;
	 pT->m_sSysMsg.m_sbySensor    = 4;
	 pT->m_sSysMsg.m_sbyInfo[0]++;  
	 for(byMsg=1;byMsg<400;byMsg++)pT->m_sSysMsg.m_sbyInfo[byMsg] = byMsg;
	 FPUT(DEV_ARMOT_BOX_ID,(BYTE*)&pT->m_sSysMsg);	 
	 */
}
void CSystem_SwitchSystem(This,SSOFTSWITCHTABLE *pSoftSwitchTable)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
}
void CSystem_CSystem(This)
{
     DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	 DECLARE_REGISTRATION(CSystem,CreateSystem)
	 DECLARE_REGISTRATION(CSystem,CreateComputer)
	 DECLARE_REGISTRATION(CSystem,CreateAdmin)
	 DECLARE_REGISTRATION(CSystem,CreateSysBox)
	 DECLARE_REGISTRATION(CSystem,CreateObserveModule)
	 DECLARE_REGISTRATION(CSystem,SwitchSystem)
	 DECLARE_REGISTRATION(CSystem,CreateProc)
	 DECLARE_REGISTRATION(CSystem,SendMsg)
	 DECLARE_REGISTRATION(CSystem,SendMessage)
	 //DECLARE_VIRTUAL_FUNC(CSystem,CyclicProc)
	 DECLARE_VIRTUAL_FUNC(CSystem,EventHandler)
	 InitObject(CMTimer,&pT->m_pResetTimer);
 	 pT->m_pResetTimer.SetTimer(&pT->m_pResetTimer,MDL_SYSTM,MDL_SYSTM,EV_SYSTM_RESET_TIM_BRD_IND,0,0,DEV_SYSTM_BOX_ID);	
}
void CSystem_DCSystem(This)
{
	DECLARE_MULTI_OPEN(CSystem,CCyclicSystem) 
	DestroyObject(CComputer,pT->m_pComputer);
	DestroyObject(CAdmin,pT->m_pAdmin);
    #if MYSYSTEM_ID != 5
	DestroyObject(CObserveModule,pT->m_pObsModule);
    #else
    #endif
	FDELETE(DEV_SYSTM_BOX_ID);
	FDELETE(DEV_ADMIN_BOX_ID);
	FDELETE(DEV_ARMOT_BOX_ID);
 	FDELETE(DEV_ARMAD_BOX_ID);	
}
DECLARE_MULTI_CREATE(CSystem,CCyclicSystem)
#ifdef WIN32
SLMESSAGE sMSG;
SLMESSAGE gMSG;
INT ret;
WSADATA       wsd;
SOCKET        sClient1;
char          szBuffer[255];
char          szServer[255];
int           i;
struct sockaddr_in server;
struct hostent    *host = NULL;
DWORD dwTic;
DWORD WINAPI GetArmToSyst(PVOID pVoid)
{
	while(1)
	{
		ret = recv(sClient1, (BYTE*)&gMSG,sizeof(SLMESSAGE) , 0);
		if((ret!=0)&&(blStateConnecting)&&(ret != SOCKET_ERROR))
		{
		 //Info("\n(__)GET_SYS::%M",(BYTE*)&gMSG);
		 //printf("\n(%d)GET_SYS::%d",gMSG.m_swLen,gMSG.m_sbyType);
		 FPUT(DEV_SYSTM_BOX_ID,(BYTE*)&gMSG);
		}//else Sleep(10);
	}
	return 0;
}
DWORD WINAPI SendToArm(PVOID pVoid)
{
//	BYTE i;
//	SMESSAGE *pS;
//  BYTE *pM;
	while(1)
	{
		if(FGET(DEV_ARMOT_BOX_ID,(BYTE*)&sMSG)!=0)
		{ 
			//pS = &sMSG;
			//pM = (BYTE*)pS;
			//printf("\nOMSG::>");
			//for(i=0;i<pS->m_swLen;i++)printf(" %x",pM[i]);
			//Info("\n(__)PUT_ARM::%M",(BYTE*)&sMSG);
            //printf("\n(%d)PUT_ARM::%d",gMSG.m_swLen,sMSG.m_sbyType);
			ret = send(sClient1, (BYTE*)&sMSG, sMSG.m_swLen,  0);
		}//else 
		Sleep(50);
		///////////////////////////////////////
        if(dwTic++%20==0) 
		{
		  if(blStateConnecting==FALSE)
			if (connect(sClient1, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
			{
		 	 printf("\n(%d)Query connection",dwTic);
			 blStateConnecting = FALSE;
			}else
			{
				printf("\n(%d)Connection complette.",dwTic);
				blStateConnecting = TRUE;
				
			}
		}
		///////////////////////////////////////
	}
	return 0;
}
void CreateGetProc(PVOID pVD)
{
	DWORD dwThreadId, dwThrdParam = 1; 
	HANDLE hThread; 
    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        printf("Failed to load Winsock library!\n");
        return ;
    }
    sClient1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sClient1 == INVALID_SOCKET)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        return ;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(20010);
    server.sin_addr.s_addr = inet_addr("127.0.0.2");
    if (server.sin_addr.s_addr == INADDR_NONE)
    {
        host = gethostbyname(szServer);
        if (host == NULL)
        {
            printf("Unable to resolve server: %s\n", szServer);
            return ;
        }
        CopyMemory(&server.sin_addr, host->h_addr_list[0],host->h_length);
    }
	blStateConnecting = TRUE;
    if (connect(sClient1, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        printf("\nconnect() failed: %d", WSAGetLastError());
		blStateConnecting = FALSE;
    }else
	{
		printf("\n(%d)Connection complette.",dwTic);
		blStateConnecting = TRUE;
	}
	hThread = CreateThread(NULL,0,GetArmToSyst    ,pVD,0,&dwThreadId);
	hThread = CreateThread(NULL,0,SendToArm,pVD,0,&dwThreadId);
}
#endif