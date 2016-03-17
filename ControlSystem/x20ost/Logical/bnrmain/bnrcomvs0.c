/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrcomvs0.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
extern SINT *chPortType[];
extern SINT *chPortRate[];
extern SINT *chPortParity[];
extern SINT *chPortData[];
extern SINT *chPortStop[];
_GLOBAL FRM_xopen_typ m_sXOpenVS0; 
_GLOBAL XOPENCONFIG   m_sConfigVS0;
_GLOBAL FRM_gbuf_typ  m_sFrameBuffVS0;
_GLOBAL FRM_rbuf_typ  m_sRBuffVS0;
_GLOBAL FRM_write_typ m_sSendVS0;
_GLOBAL FRM_read_typ  m_sReccVS0;
_GLOBAL FRM_close_typ m_sCloseVS0;
_GLOBAL FRM_robuf_typ m_sRobuffVS0;
#ifndef WIN32
_GLOBAL FRM_mode_typ FrameModeStructVS0;
#endif

void CComVS0_Init(This,SARMINTERFACE *pArm)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
    //#ifdef WIN32
	//m_nCommServer = pT;
    //#endif
	pT->m_pArm = pArm;
	FDEFINE(DEV_RSVS0MMD_BOX_ID,1024);
	FDEFINE(DEV_RSVBS0_BOX_ID,1024);
	pB->SetBoxID(pB,DEV_RSVS0MMD_BOX_ID);
	
	InitObject(CMTimer,&pT->m_nConnTMR);
	pT->m_nConnTMR.SetTimer(&pT->m_nConnTMR,DIR_PHTOPH,DIR_PHTOPH,EV_TMR_SRR_REQ,0,0,DEV_RSVS0MMD_BOX_ID);

	pT->m_blMsgFind = FALSE;
	pT->m_byType = pArm->byType;
	pT->m_byRate = pArm->byPortRate;
	pT->InByteCount_DATA = 0;
	
	strcpy(pT->m_chStringMode, chPortType[pT->m_pArm->byType]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortRate[pT->m_pArm->byPortRate]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortParity[pT->m_pArm->stTcpAddr.byAddr0]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortData[pT->m_pArm->stTcpAddr.byAddr1]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortStop[pT->m_pArm->stTcpAddr.byAddr2]);
	
	strcpy(pT->m_chStringDevice, "IF4.ST1");
	#ifdef DEB_CComVS0
	Info("\n(__)CTCPS::>Create %s.Device: %s Mode: %s",
	chPortType[pT->m_byType],pT->m_chStringDevice,pT->m_chStringMode);
	#endif
	pT->SynBuff(pT);
    pT->InitSRV(pT);
	//pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,200);
	pT->m_StatusWrite = 0;
	pT->m_bSrvState = DRV_ST_CONN;
	pT->m_bCliState = DRV_ST_CONN;
}
void CComVS0_SetPortSett(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
    strcpy(pT->m_chStringDevice, "IF4.ST1");  
	memset(pT->m_chStringNewMode,0,sizeof(pT->m_chStringNewMode));

	strcpy(pT->m_chStringNewMode, chPortType[pT->m_pArm->byType]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortRate[pT->m_pArm->byPortRate]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortParity[pT->m_pArm->stTcpAddr.byAddr0]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortData[pT->m_pArm->stTcpAddr.byAddr1]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortStop[pT->m_pArm->stTcpAddr.byAddr2]);
    #ifndef WIN32
    FrameModeStructVS0.ident  = m_sXOpenVS0.ident;
    FrameModeStructVS0.mode   = (UDINT)pT->m_chStringNewMode;
    FrameModeStructVS0.enable = 1;
    FRM_mode(&FrameModeStructVS0); 
    #endif
}
void CComVS0_SynBuff(This)//CANOpen
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	pT->w_mBoxSize  = BUFF_SZ_VS0;
    pT->w_mBoxCSize = BUFF_SZ_VS0;
	pT->w_mBoxWrite = 0;
	pT->w_mBoxRead  = 0;
	pT->m_sSize     = 0;
	pT->w_lLength   = 0;
	pT->w_lMsgLen   = 0;
	memset(&pT->pb_mBoxCont[0],0,10);
	#ifdef DEB_CComVS0
	Info("\n(__)CTCPS::>Synchro.");
    #endif
}
//_GLOBAL FRM_xopen_typ FrameXOpenStruct; 
//_GLOBAL XOPENCONFIG XOpenConfigStruct; 
void CComVS0_InitSRV(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	//Server Init
    m_sConfigVS0.idle     = 10;
    m_sConfigVS0.delimc   = 0;
    m_sConfigVS0.delim[0] = 0;
	m_sConfigVS0.delim[1] = 0;
	m_sConfigVS0.tx_cnt   = 2;
	m_sConfigVS0.rx_cnt   = 2;
	m_sConfigVS0.tx_len   = 256;
	m_sConfigVS0.rx_len   = 256;
	m_sConfigVS0.argc     = 0;
	m_sConfigVS0.argv     = 0;

	strcpy(pT->m_chStringMode, "RS232, 1200, N, 8, 1");	
	m_sXOpenVS0.device    = (UDINT) pT->m_chStringDevice;
	m_sXOpenVS0.mode      = (UDINT) pT->m_chStringMode;	
    m_sXOpenVS0.config    = (UDINT)&m_sConfigVS0;
	m_sXOpenVS0.enable    = 1;
	pT->m_StatusOpen   = 0;
    #ifndef WIN32
	pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30); 
    #else
	pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30); 
	//pT->Open(pT); 
    #endif
}
_GLOBAL INT nOPEN,nCLOSE;

BOOL CComVS0_Open(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
	SHORTMESSAGE m_sMsg;
    if(pT->m_StatusOpen==0)
	{
	#ifndef WIN32
	FRM_xopen(&m_sXOpenVS0);                  
    #endif
	if(m_sXOpenVS0.status==0)
	{
	 nOPEN++;
	 m_sReccVS0.ident      = m_sXOpenVS0.ident;
	 m_sSendVS0.ident      = m_sXOpenVS0.ident;
	 m_sCloseVS0.ident     = m_sXOpenVS0.ident;
	 m_sFrameBuffVS0.ident = m_sXOpenVS0.ident;
	 m_sRBuffVS0.ident     = m_sXOpenVS0.ident;
	 m_sReccVS0.buffer	    = (UDINT)&pT->m_ReadBuffer[0];
	 m_sSendVS0.buffer     = (UDINT)&pT->m_SendBuffer[0];
	 m_sFrameBuffVS0.buffer= m_sSendVS0.buffer;
	 m_sRBuffVS0.buffer    = m_sReccVS0.buffer;
	 m_sReccVS0.enable     = 1; 
	 m_sSendVS0.enable     = 1; 
	 m_sCloseVS0.enable    = 1; 
	 m_sFrameBuffVS0.enable= 1; 
	 m_sRBuffVS0.enable    = 1; 
	 pT->m_StatusOpen   = 1;
	 pT->m_StatusWrite  = 0;
	 //pT->SendSMessage(pT,DEV_KPMDL_BOX_ID,DIR_PHTOKP,PH_CALL_REQ);
	 return TRUE;
	}
 	}
	return FALSE;
}
void CComVS0_Enable(This)
{
	DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	m_sXOpenVS0.enable = 1;
}
void CComVS0_Disable(This)
{
	DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	m_sXOpenVS0.enable = 0;
}
void CComVS0_Close(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
	m_sCloseVS0.enable = 1;
	FRM_close(&m_sCloseVS0);            
}
BOOL CComVS0_SendMessage(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
	BOOL res = TRUE;
	if(pT->m_StatusOpen==1)
	{
	 FRM_gbuf(&m_sFrameBuffVS0);
     m_sSendVS0.buflng = pMsg->m_swLen-9;
	 memcpy(m_sSendVS0.buffer, &pMsg->m_sbyInfo[0],m_sSendVS0.buflng);
	 FRM_write(&m_sSendVS0);          
	 pT->m_StatusWrite  = m_sSendVS0.status;
	 if(pT->m_StatusWrite==0) res = TRUE;else res = FALSE;
	}
	return res;
}
_GLOBAL INT nSNDVS0;
_GLOBAL INT nSendThreadVS0;
void CComVS0_SendThread(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)  
	nSendThreadVS0++;
    //if(pT->m_StatusWrite==0)
	if(pT->m_StatusOpen==1)
    {
	 if(FGET(DEV_RSBUF_BOX_ID,&pT->m_sMsg))
	 {
	  //Info("\n(__)CRSVO::>TX:%M",&pT->m_sMsg);
	  if(pT->m_sMsg.m_swLen<=256)
	  {
	   nSNDVS0++;
       pT->SendMessage(pT,&pT->m_sMsg);
	  }//else
	    //Info("\n(__)CRSVO::>Wery Long Message!");
	 }
	}
 	 //else
 	 //{
 	 // #ifdef DEB_CComVS0
 	 // ///Info("\n(__)Wait.");
 	 // #endif
 	 //}
}
_GLOBAL INT nGETL1VS0;
BOOL CComVS0_GetMessage(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)  
	BYTE i,*pBuff;
	BOOL res=FALSE;
	SMESSAGE csM;
	if(pT->m_StatusOpen==1)
	{
	FRM_read(&m_sReccVS0);                       
	pT->m_StatusRead       = m_sReccVS0.status; 
	if(pT->m_StatusRead==0)    
	{
	 pT->m_ReadBufferLength = m_sReccVS0.buflng;
	 pBuff                  = m_sReccVS0.buffer;
	 /*
	 csM.m_sbyInfo[0] = 0x7e;
	 csM.m_sbyInfo[1] = 'A';
	 csM.m_sbyInfo[2] = 'l';
	 csM.m_sbyInfo[3] = 'e';
	 csM.m_sbyInfo[4] = 'x';
	 csM.m_sbyInfo[5] = 'a';
	 csM.m_sbyInfo[6] = 'n';
	 csM.m_sbyInfo[7] = 'd';
	 csM.m_sbyInfo[8] = 'e';
	 csM.m_sbyInfo[9] = 'r';
	 csM.m_sbyInfo[10] = 0xe7;
	 */

	 //memcpy(&csM.m_sbyInfo[0],m_sReccVS0.buffer,pT->m_ReadBufferLength);
	 //csM.m_swLen = 9 + pT->m_ReadBufferLength;
	 //Info("\n(__)CRSVO::>MSG:%M",&csM);
	 
	 //m_sRBuffVS0.buffer = m_sReccVS0.buffer;
	 //m_sRBuffVS0.buflng = pT->m_ReadBufferLength;
	 //FRM_rbuf(&m_sRBuffVS0); 
	 //res = TRUE;   
	 //nGETL1++;
	 //Info("\nMSG::>");
	 //csM.m_swLen = pT->m_ReadBufferLength+9;
	 for( i=0;i<pT->m_ReadBufferLength;i++)
	 {
	  pT->pb_mBoxCont[pT->w_mBoxWrite] = pBuff[i];
      //Info(" %b",&pT->pb_mBoxCont[pT->w_mBoxWrite]);
	  //printf(" %c",pT->pb_mBoxCont[pT->w_mBoxWrite]);
      pT->w_mBoxWrite = (pT->w_mBoxWrite + 1) & BUFF_SZ_VS0;
	 }
	 //FPUT(DEV_RSBUF_BOX_ID,(BYTE*)&csM);
	 pT->w_mBoxSize -= pT->m_ReadBufferLength;
	 pT->m_sSize     = pT->w_mBoxCSize-pT->w_mBoxSize;
	 //Info("\nRD::>%b PRD::>%w PWD::>%w FND::>%b",&pT->pb_mBoxCont[pT->w_mBoxRead],&pT->w_mBoxRead,&pT->w_mBoxWrite,&pT->m_blMsgFind);
	 if ((pT->pb_mBoxCont[pT->w_mBoxRead]==0x3d)) 
	 {
		 pT->m_blMsgFind = TRUE;
		 if(res = pT->MakeMsgData(pT,pMsg))
		 {
			 pT->m_blMsgFind = FALSE;
			 res = TRUE;   
		 }
	 }else 
		 pT->SynBuff(pT);
	 m_sRBuffVS0.buffer = m_sReccVS0.buffer;
	 m_sRBuffVS0.buflng = pT->m_ReadBufferLength;
	 FRM_rbuf(&m_sRBuffVS0); 
     }
	}
	return res;
}
BOOL CComVS0_MakeMsgData(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	WORD lLen,i,nCM=0;
	BOOL res = FALSE;
	lLen = 1;
	pT->w_lMsgLen = pT->w_lMsgLen + pT->m_ReadBufferLength;
	if (pT->w_lMsgLen>BUFF_SZ_VS0) {pT->SynBuff(pT);return res;} 
    for (i=1;i<pT->w_lMsgLen-1;i++)
	{
	 lLen++;
	 if (pT->pb_mBoxCont[(pT->w_mBoxRead+i)& BUFF_SZ_VS0]==0x2e) nCM++;
	 if (nCM>1){pT->SynBuff(pT);return res;} 
	 if (lLen>300) {pT->SynBuff(pT);return res;} 
     if (pT->pb_mBoxCont[(pT->w_mBoxRead+i)& BUFF_SZ_VS0]==0x3d)
     {
	  pT->CopyMessage(pT,lLen,pMsg);
	  //pT->SynBuff(pT);
	  pT->w_lMsgLen = 0;
	  return TRUE;
	 }
	}
	return res;
}
BOOL CComVS0_CopyMessage(This,WORD wLen,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	INT i,j=0;BYTE byCRC;
	BOOL blCRC;
	for(i=0;i<wLen;i++)
	{
 	 if ((i!=0)&&(i!=wLen-1)){pMsg->m_sbyInfo[j]=pT->pb_mBoxCont[pT->w_mBoxRead];j++;}
	 pT->w_mBoxSize =(pT->w_mBoxSize+1)& BUFF_SZ_VS0;
	 pT->w_mBoxRead=(pT->w_mBoxRead+1)& BUFF_SZ_VS0;
	 //Info(" %b",&pMsg->m_sbyInfo[i]);
	 //printf(" %x",pMsg->m_sbyInfo[i]);
	}
	pMsg->m_sbyInfo[j++] = 0x00;
	pT->w_mBoxRead=(pT->w_mBoxRead-1)& BUFF_SZ_VS0;
	pT->m_sSize = (pT->w_mBoxCSize-pT->w_mBoxSize) & BUFF_SZ_VS0;
	pMsg->m_swLen         = j+9;
	pMsg->m_sbyFrom       = DIR_PHMDL;
	pMsg->m_sbyFor        = DIR_PHTOMS;
	pMsg->m_sbyIntType    = 0;
	pMsg->m_sbyServerID   = 0;
	pMsg->m_sbyType       = PH_VS0_REQ;
	pMsg->m_sbyDirection  = 0;
	pMsg->m_sbySensor     = 0;
	return TRUE;
}
BYTE CComVS0_CreateCRC(This,BYTE *pMsg,BYTE byLen)
{
	DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	BYTE i,sum = 0;
	for(i=0;i<=byLen-1;i++)sum += pMsg[i];
	return sum;
}
_GLOBAL INT nReceiveThreadVS0;
void CComVS0_ReceiveThread(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	nReceiveThreadVS0++;
	#ifndef WIN32
	if(pT->GetMessage(pT,&pT->m_sMsg)==TRUE)
	{
	 //Info("\n(__)CRSVO::>RX:%M",&pT->m_sMsg);
	 FPUT(DEV_MSMDL_BOX_ID,(BYTE*)&pT->m_sMsg);
		//FPUT(DEV_RSBUF_BOX_ID,(BYTE*)&pT->m_sMsg);
	}
    #endif
}
_GLOBAL INT nRSEventHandlerVS0,nCheckOpenVS0,nWatchOpenVS0;
BOOL CComVS0_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
	switch(pMsg->m_sbyFor)
	{
	  case DIR_101TOPH:
	       #ifdef DEB_CComVS0
		   Info("\n(__)CRSVO::>OUTP::%M",pMsg);
		   #endif
		   FPUT(DEV_RSBUF_BOX_ID,pMsg);
	  break;
	  case DIR_PHTOPH:
	       if (pMsg->m_sbyType==EV_TMR_SRR_REQ)
		   {
		   	//if(pT->m_StatusOpen==0)
			{
			 nCheckOpenVS0++;
 		     pT->Open(pT);
			}
			pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30); 
		   }
	  break;
      case DIR_KPTOPH:
	       if (pMsg->m_sbyType==PH_CLOSE_PORT_REQ)
		   {
            //pT->Close(pT); 
		   }
		   if(pMsg->m_sbyType==PH_INIT_PORT_REQ)
		   {
             pT->SetPortSett(pT);
		   }
	  break;
	  default:
	  break;
	}
	return TRUE;
}
void CComVS0_Connect(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
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
    #ifdef DEB_CComVS0
	Info("\n(__)CRSVO::>OUTT::%M",&m_sMsg);
    #endif
}
void CComVS0_SendSMessage(This,BYTE byBox,BYTE byFor,BYTE byType)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
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
    #ifdef DEB_CComVS0
	Info("\n(__)CRSVO::>OUTT::%M",&m_sMsg);
    #endif
}
void CComVS0_Disconnect(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem) 
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
    #ifdef DEB_CComVS0
	Info("\n(__)CRSVO::>OUTT::%M",&m_sMsg);
    #endif
}
void CComVS0_CyclicProc(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)  
	pT->ReceiveThread(pT);
}
void CComVS0_CComVS0(This)
{
    DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)  
	DECLARE_REGISTRATION(CComVS0,Init)
	DECLARE_REGISTRATION(CComVS0,InitSRV)
	DECLARE_REGISTRATION(CComVS0,SendMessage)
	DECLARE_REGISTRATION(CComVS0,GetMessage)
    DECLARE_REGISTRATION(CComVS0,Close)
	DECLARE_REGISTRATION(CComVS0,Disable)
	DECLARE_REGISTRATION(CComVS0,Enable)
	DECLARE_REGISTRATION(CComVS0,Open)
	DECLARE_REGISTRATION(CComVS0,ReceiveThread)
	DECLARE_REGISTRATION(CComVS0,SendThread)
	DECLARE_REGISTRATION(CComVS0,SynBuff)
	DECLARE_REGISTRATION(CComVS0,MakeMsgData)
	DECLARE_REGISTRATION(CComVS0,CopyMessage)
	DECLARE_REGISTRATION(CComVS0,CreateCRC)
	DECLARE_REGISTRATION(CComVS0,Connect)
	DECLARE_REGISTRATION(CComVS0,Disconnect)
	DECLARE_REGISTRATION(CComVS0,SendSMessage)
	DECLARE_REGISTRATION(CComVS0,SetPortSett)
	DECLARE_VIRTUAL_FUNC(CComVS0,EventHandler)
	DECLARE_VIRTUAL_FUNC(CComVS0,CyclicProc)
}

void CComVS0_DCComVS0(This)
{
	DECLARE_MULTI_OPEN(CComVS0,CCyclicSystem)
	//DESTROY
}

DECLARE_MULTI_CREATE(CComVS0,CCyclicSystem)

