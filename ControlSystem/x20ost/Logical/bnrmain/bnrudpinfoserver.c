/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrudpinfoserver.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

#ifdef WIN32
//void UdpOpen(UdpOpen_typ *pCL){};
//void UdpSend(UdpSend_typ *pCL){};
//void UdpRecv(UdpRecv_typ *pCL){pCL->status = 1;};
//void UdpClose(UdpClose_typ *pCL){};
#endif
//_GLOBAL INT iCreate1;
_GLOBAL UINT iCreateUdpInfo;
void CUdpInfoServer_Init(This,SARMINTERFACE *pArm)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	FDEFINE(DEV_UDPINFORM_BOX_ID,DEV_RSMMD_BOX_SZ);
	FDEFINE(DEV_UDPINFOBF_BOX_ID,DEV_RSBUF_BOX_SZ);
	pB->SetBoxID(pB,DEV_UDPINFORM_BOX_ID);
	InitObject(CMTimer,&pT->m_nConnTMR);
	pT->m_nConnTMR.SetTimer(&pT->m_nConnTMR,DIR_URTOUR,DIR_URTOUR,EV_TMR_SRR_REQ,0,0,DEV_UDPINFORM_BOX_ID);
	pT->m_pArm = pArm;
	pT->m_dwAPortNumber = pArm->dwpPortNumber[0];
	pT->m_dwBPortNumber = pArm->dwpPortNumber[1];
	strcpy(pT->m_stUdpAddr,pArm->chTcpAddr);
	#ifdef DEB_CUdpServer
	Info("\n\r(__)CUDPS::>Create Uds.PA: %d.PB: %d. Addr[%s]",&pT->m_dwAPortNumber,&pT->m_dwBPortNumber,pT->m_stUdpAddr);
    #endif
	
	pT->m_npListen.enable  = TRUE; 
	//pT->m_npListen.pIfAddr = pT->m_stUdpAddr;
	pT->m_npListen.port    = pT->m_dwAPortNumber;
	pT->m_npListen.pIfAddr = 0;
	//pT->m_npListen.port    = 20002;
	pT->m_npListen.status  = 1; 
	pT->m_npListen.options = 0;
	
	pT->m_blSState = TRUE;
	pT->m_blRState = TRUE; 
	pT->m_bSrvState = DRV_ST_DISC;
	//#ifdef WIN32
	pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,50); 
	//#endif
}
BOOL CUdpInfoServer_Open(This)
{
	DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem)
	if(pT->m_bSrvState==DRV_ST_DISC)
	{
	 if (pT->m_byConnReq++%3==0)
	 {
	  pT->CloseRecc(pT);
	  pT->CloseSend(pT);
	 }
     pT->Listen(pT);
	}
    return TRUE;
}
_GLOBAL UdpOpen_typ sServrInfo;
_GLOBAL INT iListenUdpInfo;
BOOL CUdpInfoServer_Listen(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 	
	iListenUdpInfo++;	
    UdpOpen(&pT->m_npListen);
 	memcpy(&sServrInfo,&pT->m_npListen,sizeof(UdpOpen_typ));
	if(pT->m_npListen.status==0)
	{
	 //Client Init
     pT->m_npRecc.enable   = 1;
     pT->m_npRecc.ident    = pT->m_npListen.ident;	
	 pT->m_npRecc.datamax  = sizeof(SMESSAGE)-10;
	 pT->m_npRecc.flags     = 0;
	 //pT->m_npRecc.flags    = 1;  
	 pT->m_npRecc.pIpAddr  = 0;
	 
	 //Server Init
	 pT->m_npSend.enable   = 1;
	 pT->m_npSend.ident    = pT->m_npListen.ident;
	 pT->m_npSend.pHost    = pT->m_stUdpAddr;
	 pT->m_npSend.port     = pT->m_dwAPortNumber;
	 pT->m_npSend.datalen  = sizeof(SMESSAGE);
	 //pT->m_npSend.flags     = 2;
	 pT->m_npSend.flags    = 0;
	 
	 pT->m_bSrvState = DRV_ST_CONN;
  	 return TRUE;
	}
	pT->m_bSrvState = DRV_ST_DISC;
    return FALSE;
}
_GLOBAL UdpSend_typ sSendUdpInfo;
_GLOBAL INT iCUdpSrvValUdpInfo;
//_GLOBAL INT iLnSSend;
BOOL CUdpInfoServer_SendMessage(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	iCUdpSrvValUdpInfo++;
	//pT->m_blSState = TRUE;
	//pT->AddCRC(pT,TRUE,pMsg);
	pT->m_npSend.pData   = &pMsg->m_sbyInfo[0]; 
	pT->m_npSend.datalen = pMsg->m_swLen-9;
	UdpSend(&pT->m_npSend);
	memcpy(&sSendUdpInfo,&pT->m_npSend,sizeof(UdpSend_typ));
	if(pT->m_npSend.status!=0)
	{
	 pT->m_blSState = FALSE;
	 return FALSE;
    }
	return TRUE;
}
_GLOBAL INT iPSendUdpInfo;
//_GLOBAL INT iLnPSend;
void CUdpInfoServer_PostSend(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	iPSendUdpInfo++;
	UdpSend(&pT->m_npSend);
	memcpy(&sSendUdpInfo,&pT->m_npSend,sizeof(UdpSend_typ));
  	if(pT->m_npSend.status==0)pT->m_blSState = TRUE;
}
_GLOBAL UdpRecv_typ sReccUdpInfo;
//_GLOBAL INT iCUdpCliVal;
_GLOBAL INT iCUdpInDataUdpInfo;
//_GLOBAL SMESSAGE sMS;
BOOL CUdpInfoServer_GetMessage(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 	
	pT->m_npRecc.pData = &pMsg->m_sbyInfo[0];
	UdpRecv(&pT->m_npRecc);
	memcpy(&sReccUdpInfo,&pT->m_npRecc,sizeof(UdpRecv_typ));
	if(pT->m_npRecc.status==0)
	{ 
	 iCUdpInDataUdpInfo++;
	 pMsg->m_swLen  = 9 + pT->m_npRecc.recvlen; 
	 pMsg->m_sbyFor = DIR_RMTOMD;
	 if (pMsg->m_swLen<300) return TRUE; else return FALSE;
	}
	else
    return FALSE;	
}
_GLOBAL INT nReceiveThreadUdpInfo,nSendThreadUdpInfo,nSNDURInfo;
void CUdpInfoServer_SendThread(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem)  
	nSendThreadUdpInfo++;
	if(pT->m_bSrvState==DRV_ST_CONN)
    {
	 if(pT->m_blSState==FALSE)
		 pT->PostSend(pT);else
	 if(FGET(DEV_UDPINFOBF_BOX_ID,&pT->m_sMsg0))
	 {
	  //Info("\n(__)CUDPR::>TX:%M",&pT->m_sMsg);
	  nSNDURInfo++;
      pT->SendMessage(pT,&pT->m_sMsg0);
	 }
	}
}
_GLOBAL INT nUdpRecc;
void CUdpInfoServer_ReceiveThread(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	nReceiveThreadUdpInfo++;
	if(pT->GetMessage(pT,&pT->m_sMsg)==TRUE)
	{
	 nUdpRecc++;	
	  //Info("\n(__)CRSSM::>RX:%M",&pT->m_sMsg);
	  //FPUT(BOX_MDB_BOX,(BYTE*)&pT->m_sMsg);
	  //FPUT(DEV_UDPBF_BOX_ID,&pT->m_sMsg);
	}
}
//_GLOBAL INT iPRecv;
BOOL CUdpInfoServer_PostGet(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	return FALSE;
}
//_GLOBAL Udpclose_typ sClose;
BOOL CUdpInfoServer_Close(This,UDINT uModule)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 	
    BOOL res = TRUE;
	pT->m_bSrvState      = DRV_ST_DISC;
	pT->m_npClose.enable = TRUE;
	pT->m_npClose.ident  = uModule;
	UdpClose(&pT->m_npClose);
	//pT->Init(pT,pT->m_pArm);
	//memcpy(&sClose,&pT->m_npClose,sizeof(Udpclose_typ));
	if(pT->m_npClose.status==0)return TRUE;
    return FALSE;	
}
BOOL CUdpInfoServer_CloseSend(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	BOOL res =pT->Close(pT,pT->m_npSend.ident);
	pT->m_bSrvState = DRV_ST_DISC;
	memset(&pT->m_npSend,0,sizeof(UdpSend_typ));
	return res;
}
BOOL CUdpInfoServer_CloseRecc(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	BOOL res = pT->Close(pT,pT->m_npRecc.ident);
	pT->m_bSrvState = DRV_ST_DISC;
	memset(&pT->m_npRecc,0,sizeof(UdpRecv_typ));
    return res;
}
BOOL CUdpInfoServer_CheckSend(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem)  
    return TRUE;
}
void CUdpInfoServer_WordXCHG(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
    #ifndef WIN32
	BYTE byTmp,*pW = (BYTE*)pMsg; 
	byTmp = pW[0];
	pW[0] = pW[1];
	pW[1] = byTmp;
    #endif
}
BOOL CUdpInfoServer_CheckCRC(This,BOOL blCrc,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
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
DWORD CUdpInfoServer_ClcCRC(This,BOOL blCrc,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	WORD i;
	WORD wLen;
	DWORD dwCrc = 0;
	BYTE *pCRC,*pM = (BYTE*)pMsg;
	if (blCrc) pMsg->m_swLen += 4; 
	wLen = pMsg->m_swLen-4;
	pCRC = &pM[wLen];
	for(i=0;i<wLen;i++)
	{
	 dwCrc += pM[i];
	 if(i>700) 
		 break;
	}
	return dwCrc;	
}
void CUdpInfoServer_AddCRC(This,BOOL blCrc,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
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
_GLOBAL INT nCheckOpenUDPInfo;
BOOL CUdpInfoServer_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	switch(pMsg->m_sbyFor)
	{
	  case DIR_MDTOUR:
	       #ifdef DEB_CComSrvIst
		   //Info("\n(__)CUDPR::>OUTP::%M",pMsg);
		   #endif
		   FPUT(DEV_UDPINFOBF_BOX_ID,pMsg);
	  break;
	  case DIR_URTOUR:
	       if (pMsg->m_sbyType==EV_TMR_SRR_REQ)
		   {
			nCheckOpenUDPInfo++;
 		    pT->Open(pT);
			pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,50); 
			/*
			pT->m_sMsg0.m_swLen      = 9+5;
			pT->m_sMsg0.m_sbyInfo[0] = 0;
			pT->m_sMsg0.m_sbyInfo[1] = 1;
			pT->m_sMsg0.m_sbyInfo[2] = 2;
			pT->m_sMsg0.m_sbyInfo[3] = 3;
			pT->m_sMsg0.m_sbyInfo[4] = 4;
			FPUT(DEV_UDPBF_BOX_ID,&pT->m_sMsg0);
			*/
		   }
	  break;
	  default:
	  break;
	}
	return TRUE;
}
void CUdpInfoServer_CyclicProc(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem)  
	pT->SendThread(pT);
	pT->ReceiveThread(pT);
}
void CUdpInfoServer_CUdpInfoServer(This)
{
    DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
	DECLARE_REGISTRATION(CUdpInfoServer,Init)
	DECLARE_REGISTRATION(CUdpInfoServer,PostSend)
	DECLARE_REGISTRATION(CUdpInfoServer,PostGet)
	DECLARE_REGISTRATION(CUdpInfoServer,SendMessage)
	DECLARE_REGISTRATION(CUdpInfoServer,GetMessage)
	DECLARE_REGISTRATION(CUdpInfoServer,CheckSend)
	DECLARE_REGISTRATION(CUdpInfoServer,Open)
	DECLARE_REGISTRATION(CUdpInfoServer,Listen)
	DECLARE_REGISTRATION(CUdpInfoServer,Close)
	DECLARE_REGISTRATION(CUdpInfoServer,CloseSend)
	DECLARE_REGISTRATION(CUdpInfoServer,CloseRecc)
	DECLARE_REGISTRATION(CUdpInfoServer,WordXCHG)
	DECLARE_REGISTRATION(CUdpInfoServer,AddCRC)
	DECLARE_REGISTRATION(CUdpInfoServer,CheckCRC)
	DECLARE_REGISTRATION(CUdpInfoServer,ClcCRC)
	DECLARE_REGISTRATION(CUdpInfoServer,ReceiveThread)
	DECLARE_REGISTRATION(CUdpInfoServer,SendThread)
	DECLARE_VIRTUAL_FUNC(CUdpInfoServer,EventHandler)
	DECLARE_VIRTUAL_FUNC(CUdpInfoServer,CyclicProc)
}
void CUdpInfoServer_DCUdpInfoServer(This)
{
	DECLARE_MULTI_OPEN(CUdpInfoServer,CCyclicSystem) 
}
DECLARE_MULTI_CREATE(CUdpInfoServer,CCyclicSystem)

