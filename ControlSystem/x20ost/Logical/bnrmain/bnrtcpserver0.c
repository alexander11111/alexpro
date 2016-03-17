/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrtcpserver.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL	 TcpServer_typ m_npServer[1];
_GLOBAL  TcpOpen_typ m_npListen[1];
_GLOBAL  TcpSend_typ m_npSend[1];
_GLOBAL	 TcpRecv_typ m_npRecc[1];
_GLOBAL  TcpClose_typ m_npClose[1];
#ifdef WIN32
DWORD dwThreadId;
//void TcpOpen(TcpOpen_typ *pServer){pServer->status=0;}
SOCKET sClient;
DWORD WINAPI GetArm(PVOID pVoid);
void TcpClose(TcpClose_typ *pCL){};
void TcpServer(TcpServer_typ *pServer){pServer->identclnt=pServer->ident;pServer->status=0;}
void TcpOpen(TcpOpen_typ *pServer)
{
	BOOL    bInterface = FALSE;
    WSADATA wsd;
	int iAddrSize;
	struct sockaddr_in local,client;
	struct sockaddr_in server;
    struct hostent *host = NULL;
	pServer->status = 1;
	if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        printf("Failed to load Winsock!\n");
        return ;
    }
	pServer->sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (pServer->sListen == SOCKET_ERROR)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        return ;
    }
    if (bInterface)
    {
        //local.sin_addr.s_addr = inet_addr(pServer->pIfAddr);
		local.sin_addr.s_addr = inet_addr("0.0.0.0");
        if (local.sin_addr.s_addr == INADDR_NONE)
		{
			printf("socket() failed: %s\n", pServer->pIfAddr);
			return;
		}
    }
    else
		local.sin_addr.s_addr = htonl(INADDR_ANY);
	local.sin_family = AF_INET;
	local.sin_port = htons((u_short)pServer->port);
    if (bind(pServer->sListen, (struct sockaddr *)&local,sizeof(local)) == SOCKET_ERROR)
    {
        printf("bind() failed: %d\n", WSAGetLastError());
        return ;
    }
    listen(pServer->sListen, 8);
    iAddrSize = sizeof(client);
    //pServer->sClient = accept(pServer->sListen, (struct sockaddr *)&client,&iAddrSize);        
	pServer->sClient = accept(pServer->sListen, (struct sockaddr *)&client,&iAddrSize);                     
    if (pServer->sClient == INVALID_SOCKET)
    {        
		printf("accept() failed: %d\n", WSAGetLastError());
		return ;
    }
	sClient = pServer->sClient; 
	pServer->ident = &pServer->sClient;
	Info("\n(__)CTCPS::>Connect");
	pServer->status = 0;
}
//void TcpSend(TcpSend_typ *pCL){};
void TcpSend(TcpSend_typ *pSend)
{
	int ret;
	ret = send(sClient, (char*)pSend->pData, pSend->datalen, 0);
	//Info("\n(__)ARM_0:%M",pSend->buffer);
	if (ret == 0)
	{
		//printf("Send Not Poss \n");
		//Sleep(500);
		pSend->status = 1;
		return;
	}
	else if (ret == SOCKET_ERROR)
	{
		//printf("send() failed: %d\n",WSAGetLastError());
		//Sleep(500);
		pSend->status = 1; 
		return;
	}
	//Sleep(50);
	pSend->status = 0; 
	
}
void TcpRecv(TcpRecv_typ *pRecv)
{
	int ret;
	//printf("RCV\n");
	ret = recv(sClient,(char*)pRecv->pData,pRecv->datamax , 0);
	if (ret == 0)  
	{
		//Sleep(500);
		printf("recv() failed 0: %d\n", WSAGetLastError());
		pRecv->status = 1;
		return;
	}
	else if (ret == SOCKET_ERROR)
	{
		printf("recv() failed: %d\n", WSAGetLastError());
        //Sleep(500);
		pRecv->status = 1;
		return;
	}
	//printf("Reccive OK! \n");
	pRecv->recvlen = ret;
	pRecv->status = 0;
}
#endif

//_GLOBAL INT iCreate1;
_GLOBAL UINT iCreateTcp1;
void CTcpServer_Init(This,SARMINTERFACE *pArm)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	FDEFINE(DEV_TCPRM_BOX_ID,1024);
	FDEFINE(DEV_TCPBF_BOX_ID,1024);
	pB->SetBoxID(pB,DEV_TCPRM_BOX_ID);
	InitObject(CMTimer,&pT->m_nConnTMR);
	pT->m_nConnTMR.SetTimer(&pT->m_nConnTMR,DIR_TCPTOTCP,DIR_TCPTOTCP,EV_TMR_SRR_REQ,0,0,DEV_TCPRM_BOX_ID);
	pT->m_pArm = pArm;
	pT->m_dwAPortNumber = pArm->dwpPortNumber[0];
	pT->m_dwBPortNumber = pArm->dwpPortNumber[1];
	strcpy(pT->m_stTcpAddr,pArm->chTcpAddr);
	#ifdef DEB_CTcpServer
	Info("\n\r(__)CTcpS::>Create Tcp.PA: %d.PB: %d. Addr[%s]",&pT->m_dwAPortNumber,&pT->m_dwBPortNumber,pT->m_stTcpAddr);
    #endif
 	pT->m_npListen =  &m_npListen[0];
	pT->m_npSend   =  &m_npSend[0];
	pT->m_npRecc   =  &m_npRecc[0];
	pT->m_npClose  =  &m_npClose[0];
	pT->m_npServer =  &m_npServer[0];
	
	memset(pT->m_npListen,0,sizeof(TcpOpen_typ));
	//memset(pT->m_npSend,0,sizeof(TcpSend_typ));
	//memset(&pT->m_npRecc,0,sizeof(TcpRecv_typ));
	pT->m_npListen->enable  = TRUE; 
	pT->m_npListen->port    = pT->m_dwAPortNumber;
	pT->m_npListen->pIfAddr = 0;
	pT->m_npListen->status  = 1; 
	pT->m_npListen->options = 0;
	
	pT->m_blSState = TRUE;
	pT->m_blRState = TRUE; 
	pT->m_bSrvState = DRV_ST_DISC;
	
	pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,100); 
    #ifdef WIN32
	CreateThread(NULL,0,GetArm ,pT,0,&dwThreadId);
	#endif
}
_GLOBAL TcpServer_typ sServer;
_GLOBAL TcpRecv_typ sRecc;
BOOL CTcpServer_Open(This)
{
	DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem)
	
	if(pT->m_bSrvState==DRV_ST_DISC)
	{
	 if (pT->m_byConnReq++%2==0)
	 {
	  pT->CloseRecc(pT);
	  pT->CloseSend(pT);
	  pT->CloseOpen(pT);
	 }
	 pT->Listen(pT);
	}
	
	if(pT->m_bSrvState==DRV_ST_OPEN)
	{
	 //memset(pT->m_npServer,0,sizeof(TcpServer_typ));
	 pT->m_npServer->enable  = 1;
	 pT->m_npServer->ident   = pT->m_npListen->ident;
	 pT->m_npServer->backlog = 1;
	 pT->m_npServer->pIpAddr = pT->m_stTcpAddr;
     TcpServer(pT->m_npServer);
	 memcpy(&sServer,pT->m_npServer,sizeof(TcpServer_typ));
     if(pT->m_npServer->status==0)
	 {
	  
	  //if(pT->m_bSrvState==DRV_ST_OPEN)
      pT->m_npRecc->enable   = 1;
      pT->m_npRecc->ident    = pT->m_npServer->identclnt;	
	  pT->m_npRecc->datamax  = sizeof(SMESSAGE)-10;
	  pT->m_npRecc->flags     = 0;

	  pT->m_npSend->enable   = 1;
	  pT->m_npSend->ident    = pT->m_npServer->identclnt;
	  pT->m_npSend->datalen  = sizeof(SMESSAGE);
	  pT->m_npSend->flags    = 0;
	  pT->m_bSrvState = DRV_ST_CONN;
	  pT->m_blSState = TRUE;
	  //pT->Connect(pT);
	  //pT->SendSMessage(pT,DEV_KPMDL_BOX_ID,DIR_PHTOKP,PH_CALL_REQ);
  	  return TRUE;	  
	 }
	}
    return TRUE;
}
_GLOBAL TcpOpen_typ sOpen;
_GLOBAL INT iListen;
BOOL CTcpServer_Listen(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	iListen++;	
	memset(pT->m_npListen,0,sizeof(TcpOpen_typ));
	pT->m_npListen->enable  = 1; 
	pT->m_npListen->port    = pT->m_dwAPortNumber;
	pT->m_npListen->pIfAddr = 0;
	pT->m_npListen->status  = 1; 
	pT->m_npListen->options = 0;
	//memcpy(&sOpen,pT->m_npListen,sizeof(TcpOpen_typ));
    TcpOpen(pT->m_npListen);
	//TcpOpen(&sOpen);
 	memcpy(&sOpen,pT->m_npListen,sizeof(TcpOpen_typ));
	if(pT->m_npListen->status==32602){pT->Close(pT,pT->m_npListen->ident);};
	if(pT->m_npListen->status==0)
	{
	 pT->m_bSrvState = DRV_ST_OPEN;
	 return TRUE;
	}
}

_GLOBAL TcpSend_typ sSend;
_GLOBAL INT iCTcpSrvVal,iCTcpSendCh;
//_GLOBAL INT iLnSSend;
BOOL CTcpServer_SendMessage(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	iCTcpSrvVal++;
	//pT->m_blSState = TRUE;
	//pT->AddCRC(pT,TRUE,pMsg);
	pT->m_npSend->pData   = &pMsg->m_sbyInfo[0]; 
	pT->m_npSend->datalen = pMsg->m_swLen-9;
	TcpSend(pT->m_npSend);
	memcpy(&sSend,pT->m_npSend,sizeof(TcpSend_typ));
	if(pT->m_npSend->status!=0)
	{
	 if(pT->m_npSend->status==32609)
	 {
		 iCTcpSendCh++;
		 pT->CloseSend(pT);
		 pT->CloseRecc(pT);
		 pT->CloseOpen(pT);
		 pT->Disconnect(pT);
	 }
	 pT->m_blSState = FALSE;
	 return FALSE;
    }
	return TRUE;
}
_GLOBAL INT iPSend;
//_GLOBAL INT iLnPSend;
void CTcpServer_PostSend(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	iPSend++;
	TcpSend(pT->m_npSend);
	memcpy(&sSend,pT->m_npSend,sizeof(TcpSend_typ));
  	if(pT->m_npSend->status==0)pT->m_blSState = TRUE;
	if(pT->m_npSend->status==32609){iCTcpSendCh++;pT->CloseSend(pT);pT->CloseRecc(pT);pT->CloseOpen(pT);pT->Disconnect(pT);}
}

//_GLOBAL INT iCTcpCliVal;
_GLOBAL INT iCTcpInData;
//_GLOBAL SMESSAGE sMS;

BOOL CTcpServer_GetMessage(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 	
	pT->m_npRecc->pData = &pMsg->m_sbyInfo[0];
	TcpRecv(&pT->m_npRecc);
	memcpy(&sRecc,&pT->m_npRecc,sizeof(TcpRecv_typ));
	if(pT->m_npRecc->status==0)
	{ 
	 iCTcpInData++;
	 pMsg->m_swLen  = 9 + pT->m_npRecc->recvlen; 
	 pMsg->m_sbyFor = DIR_PHTO101;
	 if (pMsg->m_swLen<300) return TRUE; else return FALSE;
	}
	else
    return FALSE;	
}
_GLOBAL INT nReceiveThreadTcp,nSendThreadTcp,nSNDUR;
void CTcpServer_SendThread(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem)  
	nSendThreadTcp++;
	if(pT->m_bSrvState==DRV_ST_CONN)
    {
	 if(pT->m_blSState==FALSE)
	 	 pT->PostSend(pT);else
	 if(FGET(DEV_TCPBF_BOX_ID,&pT->m_sMsg0))
	 {
	  //Info("\n(__)CTcpR::>TX:%M",&pT->m_sMsg);
	  nSNDUR++;
	  pT->AddCRC(pT,TRUE,&pT->m_sMsg0);
      pT->SendMessage(pT,&pT->m_sMsg0);
	 }
	}
}
_GLOBAL INT nCheckOpenTcp,nCheckSendCheck;
void CTcpServer_ReceiveThread(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	nReceiveThreadTcp++;
	if(pT->m_bSrvState==DRV_ST_CONN)
	if(pT->GetMessage(pT,&pT->m_sMsg)==TRUE)
	{
	  nCheckOpenTcp = 0;
	  pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,100); 	
	  //Info("\n(__)CTCPM::>RX:%M",&pT->m_sMsg);
	  if(pT->CheckCRC(pT,FALSE,&pT->m_sMsg)==TRUE)
	  {
	   pT->m_sMsg.m_swLen -= 4;
	   pT->m_sMsg.m_sbyFrom       = DIR_PHMDL;
	   pT->m_sMsg.m_sbyFor        = DIR_PHTOMS;
	   pT->m_sMsg.m_sbyIntType    = 0;
	   pT->m_sMsg.m_sbyServerID   = 0;
	   pT->m_sMsg.m_sbyType       = PH_SCMD_REQ;
	   pT->m_sMsg.m_sbyDirection  = 0;
	   pT->m_sMsg.m_sbySensor     = 0;
       FPUT(DEV_MSMDL_BOX_ID,(BYTE*)&pT->m_sMsg); 
	  }
	}
}
//_GLOBAL INT iPRecv;
BOOL CTcpServer_PostGet(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	return FALSE;
}
//_GLOBAL Tcpclose_typ sClose;
BOOL CTcpServer_Close(This,UDINT uModule)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 	
    BOOL res = TRUE;
	pT->m_bSrvState      = DRV_ST_DISC;
	pT->m_npClose->enable = TRUE;
	pT->m_npClose->ident  = uModule;
	pT->m_npClose->how    = 3;
	TcpClose(pT->m_npClose);
	//pT->Init(pT,pT->m_pArm);
	//memcpy(&sClose,pT->m_npClose,sizeof(Tcpclose_typ));
	if(pT->m_npClose->status==0)return TRUE;
    return FALSE;	
}
BOOL CTcpServer_CloseOpen(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	BOOL res =pT->Close(pT,pT->m_npListen->ident);
	pT->m_bSrvState = DRV_ST_DISC;
	memset(pT->m_npSend,0,sizeof(TcpSend_typ));
	return res;
}
BOOL CTcpServer_CloseSend(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	BOOL res =pT->Close(pT,pT->m_npSend->ident);
	pT->m_bSrvState = DRV_ST_DISC;
	memset(pT->m_npSend,0,sizeof(TcpSend_typ));
	memset(&sSend,0,sizeof(TcpRecv_typ));
	return res;
}
BOOL CTcpServer_CloseRecc(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	BOOL res = pT->Close(pT,pT->m_npRecc->ident);
	pT->m_bSrvState = DRV_ST_DISC;
	memset(&pT->m_npRecc,0,sizeof(TcpRecv_typ));
	memset(&sRecc,0,sizeof(TcpRecv_typ));
    return res;
}
BOOL CTcpServer_CheckSend(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem)  
    return TRUE;
}
void CTcpServer_WordXCHG(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
    #ifndef WIN32
	BYTE byTmp,*pW = (BYTE*)pMsg; 
	byTmp = pW[0];
	pW[0] = pW[1];
	pW[1] = byTmp;
    #endif
}
BOOL CTcpServer_CheckCRC(This,BOOL blCrc,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	DWORD dwCrc = 0;
	WORD wLen = pMsg->m_swLen;
	BYTE *pR = (BYTE*)&dwCrc;
	BYTE *pM = (BYTE*)pMsg;
	BYTE *pCRC = &pM[wLen-4];
    #ifndef WIN32
	pR[3] = pCRC[0];
	pR[2] = pCRC[1];
	pR[1] = pCRC[2];
	pR[0] = pCRC[3];
    #else
	memcpy(&dwCrc,pCRC,4);
    #endif
	if(dwCrc==pT->ClcCRC(pT,blCrc,pMsg)) return TRUE;
	return FALSE;
}
DWORD CTcpServer_ClcCRC(This,BOOL blCrc,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	WORD i;
	WORD wLen;
	DWORD dwCrc = 0;
	//BYTE *pCRC,*pM = (BYTE*)&pMsg;
	BYTE *pCRC,*pM = (BYTE*)&pMsg->m_sbyInfo[0];
	if (blCrc) pMsg->m_swLen += 4; 
	//wLen = pMsg->m_swLen-4;
	wLen = pMsg->m_swLen-4-9;
	pCRC = &pM[wLen];
	for(i=0;i<wLen;i++)
	{
	 dwCrc += pM[i];
	 if(i>700) 
		 break;
	}
	return dwCrc;	
}
void CTcpServer_AddCRC(This,BOOL blCrc,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	DWORD dwCrc = 0;
	WORD wLen = pMsg->m_swLen;
	BYTE *pR = (BYTE*)&dwCrc;
	BYTE *pM = (BYTE*)pMsg;
	BYTE *pCRC = &pM[wLen];
	dwCrc = pT->ClcCRC(pT,blCrc,pMsg);
    #ifndef WIN32
	pCRC[3] = pR[0];
	pCRC[2] = pR[1];
	pCRC[1] = pR[2];
	pCRC[0] = pR[3];
    #else
	memcpy(pCRC,pR,4);
    #endif
}

BOOL CTcpServer_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	//SHORTMESSAGE m_sMsg;
	switch(pMsg->m_sbyFor)
	{
      case DIR_MSTOTCP:
	       #ifdef DEB_CTcpServer
		   Info("\n(__)CTCPR::>OUTP::%M",pMsg);
		   #endif
		   FPUT(DEV_TCPBF_BOX_ID,pMsg);
	  break;
	  case DIR_TCPTOTCP:
	       if (pMsg->m_sbyType==EV_TMR_SRR_REQ)
		   {
		
 		    pT->Open(pT);
			pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,100); 
			//if (nCheckOpenTcp%4==0)
			{
             nCheckSendCheck++;
			 pT->m_sMsg0.m_swLen      = 9+3;
			 pT->m_sMsg0.m_sbyInfo[0] = 0x55;
			 pT->m_sMsg0.m_sbyInfo[1] = 0xaa;
			 pT->m_sMsg0.m_sbyInfo[2] = 0x55;
			 pT->m_sMsg0.m_sbyInfo[3] = 3;
			 pT->m_sMsg0.m_sbyInfo[4] = 4;
			 ////SendMessage()
			 FPUT(DEV_TCPBF_BOX_ID,&pT->m_sMsg0);
			}
			nCheckOpenTcp++;
		   }
	  break;
	  default:
	  break;
	}
	return TRUE;
}
void CTcpServer_CyclicProc(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem)  
    #ifndef WIN32
	pT->SendThread(pT);
	pT->ReceiveThread(pT);
    #else
	pT->SendThread(pT);
    #endif
}
void CTcpServer_SendSMessage(This,BYTE byBox,BYTE byFor,BYTE byType)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = byFor;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = byType;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(byBox,(BYTE*)&m_sMsg);	
    #ifdef DEB_CTcpServer
	Info("\n(__)CTCPR::>OUTT::%M",&m_sMsg);
    #endif
}
void CTcpServer_Connect(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
    SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = DIR_PHTO101P;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_CONN_IND;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(DEV_101MD_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CTcpServer
	Info("\n(__)CTCPR::>OUTT::%M",&m_sMsg);
    #endif
}
void CTcpServer_Disconnect(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
    SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = DIR_PHTO101P;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_DISC_IND;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(DEV_101MD_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CTcpServer
	Info("\n(__)CTCPR::>OUTT::%M",&m_sMsg);
    #endif
}
void CTcpServer_CTcpServer(This)
{
    DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
	DECLARE_REGISTRATION(CTcpServer,Init)
	DECLARE_REGISTRATION(CTcpServer,PostSend)
	DECLARE_REGISTRATION(CTcpServer,PostGet)
	DECLARE_REGISTRATION(CTcpServer,SendMessage)
	DECLARE_REGISTRATION(CTcpServer,GetMessage)
	DECLARE_REGISTRATION(CTcpServer,CheckSend)
	DECLARE_REGISTRATION(CTcpServer,Open)
	DECLARE_REGISTRATION(CTcpServer,Listen)
	DECLARE_REGISTRATION(CTcpServer,Close)
	DECLARE_REGISTRATION(CTcpServer,CloseSend)
	DECLARE_REGISTRATION(CTcpServer,CloseRecc)
	DECLARE_REGISTRATION(CTcpServer,WordXCHG)
	DECLARE_REGISTRATION(CTcpServer,AddCRC)
	DECLARE_REGISTRATION(CTcpServer,CheckCRC)
	DECLARE_REGISTRATION(CTcpServer,ClcCRC)
	DECLARE_REGISTRATION(CTcpServer,ReceiveThread)
	DECLARE_REGISTRATION(CTcpServer,SendThread)
	DECLARE_REGISTRATION(CTcpServer,CloseOpen)
	DECLARE_REGISTRATION(CTcpServer,Connect)
	DECLARE_REGISTRATION(CTcpServer,Disconnect)
	DECLARE_REGISTRATION(CTcpServer,SendSMessage)
	DECLARE_VIRTUAL_FUNC(CTcpServer,EventHandler)
	DECLARE_VIRTUAL_FUNC(CTcpServer,CyclicProc)
}
void CTcpServer_DCTcpServer(This)
{
	DECLARE_MULTI_OPEN(CTcpServer,CCyclicSystem) 
}
DECLARE_MULTI_CREATE(CTcpServer,CCyclicSystem)
#ifdef WIN32 
DWORD WINAPI GetArm(PVOID pVoid)
{
	CTcpServer *pT = (CTcpServer*)pVoid;
	while(1)
	{
	 pT->ReceiveThread(pT);
	 //pT->SendThread(pT);
	 //Sleep(50);
     //printf("\nGetArm");
	}
	return 0;
}
#endif


