/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrdebug.h"
#include "bnrpob.h"
#include "bnrcyclicsystem.h"
#ifdef WIN32
#include "AsTCP1.h"
#include "winsock.h"
#else
//#include <Ethernet.h>
#endif
Class CTcpServer
{
	 void (*CCTcpServer)(This);
	 void (*DCTcpServer)(This);
Public
     //Connection Disconnection Procedure 
     void (*Init)(This,SARMINTERFACE *pArm);
     BOOL (*SendMessage)(This,SMESSAGE *pMsg);
	 BOOL (*GetMessage)(This,SMESSAGE *pMsg);
Private     
	 BOOL (*Open)(This);
	 BOOL (*Listen)(This);
	 BOOL (*Close)(This,UDINT uModule);
	 BOOL (*CloseSend)(This);
	 BOOL (*CloseRecc)(This);
	 BOOL (*CheckSend)(This);
	 BOOL (*CloseOpen)(This);
	 void (*PostSend)(This);
	 BOOL (*PostGet)(This);
	 void (*WordXCHG)(This,SMESSAGE *pMsg);
	 BOOL (*CheckCRC)(This,BOOL,SMESSAGE *pMsg);
     void (*AddCRC)(This,BOOL,SMESSAGE *pMsg);
	 BOOL (*Connect)(This);
	 BOOL (*Disconnect)(This);
	 void (*SendSMessage)(This,BYTE byBox,BYTE byFor,BYTE byType);
	 DWORD (*ClcCRC)(This,BOOL,SMESSAGE *pMsg);
	 void (*ReceiveThread)(This);
	 void (*SendThread)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This); 
Private 
     SARMINTERFACE *m_pArm;
	 TcpServer_typ m_npServer;
     TcpOpen_typ m_npListen;
     TcpSend_typ m_npSend;
	 TcpRecv_typ m_npRecc;
     TcpClose_typ m_npClose;
     BOOL m_blSState;
	 BOOL m_blRState;
     DWORD m_dwAPortNumber;
	 DWORD m_dwBPortNumber;
     char m_stTcpAddr[50];  
	 BYTE m_bSrvState;
	 BYTE m_bCliState;
	 BYTE m_byConnReq;
	 SMESSAGE m_sMsg;
	 SMESSAGE m_sMsg0;
	 CMTimer m_nConnTMR;
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CTcpServer)
#endif
