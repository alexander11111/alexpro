/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __UDPINFOSERVER_H__
#define __UDPINFOSERVER_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrdebug.h"
#include "bnrpob.h"
#include "bnrcyclicsystem.h"
#ifdef WIN32
#include "AsUdp1.h"
#include "winsock.h"
#else
//#include <Ethernet.h>
#endif
Class CUdpInfoServer
{
	 void (*CCUdpInfoServer)(This);
	 void (*DCUdpInfoServer)(This);
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
	 void (*PostSend)(This);
	 BOOL (*PostGet)(This);
	 void (*WordXCHG)(This,SMESSAGE *pMsg);
	 BOOL (*CheckCRC)(This,BOOL,SMESSAGE *pMsg);
     void (*AddCRC)(This,BOOL,SMESSAGE *pMsg);
	 DWORD (*ClcCRC)(This,BOOL,SMESSAGE *pMsg);
	 void (*ReceiveThread)(This);
	 void (*SendThread)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This); 
Private 
     SARMINTERFACE *m_pArm;
     UdpOpen_typ m_npListen;
     UdpSend_typ m_npSend;
	 UdpRecv_typ m_npRecc;
     UdpClose_typ m_npClose;
     BOOL m_blSState;
	 BOOL m_blRState;
     DWORD m_dwAPortNumber;
	 DWORD m_dwBPortNumber;
     char m_stUdpAddr[50];  
	 BYTE m_bSrvState;
	 BYTE m_bCliState;
	 BYTE m_byConnReq;
	 SMESSAGE m_sMsg;
	 SMESSAGE m_sMsg0;
	 CMTimer m_nConnTMR;
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CUdpInfoServer)
#endif
