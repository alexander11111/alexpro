/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MYSYSTEM_H__
#define __MYSYSTEM_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrprocmanager.h"
#include "bnradmin.h"
#include "bnrcomputer.h"
#include "bnrobserve.h"
#include "bnrpob.h"
#include "bnrkp.h"
#include "bnrmodule101.h"
#include "bnrcomserver.h"
#include "bnrtcpserver.h"
#include "bnrcomvs0.h"
#include "bnrcomvs1.h"
#include "bnrtcpserver.h"
#include "bnrmeasur.h"
#ifdef WIN32
#include "winsock.h"
void CreateGetProc(PVOID pVoid);
#endif
Class CSystem
{
	 void (*CCSystem)(This);
	 void (*DCSystem)(This);
Public
	 void (*CreateSystem)(This,SHARDCOMPUTERTABLE *pTable);
     void (*CreateAdmin)(This);
     void (*CreateComputer)(This,SHARDCOMPUTERTABLE *pTable);
	 void (*CreateSysBox)(This);
	 void (*CreateObserveModule)(This,SHARDCOMPUTERTABLE *pTable,SSOFTSWITCHTABLE *pSoftSwitchTable);
	 void (*CreateProc)(This);
	 void (*SwitchSystem)(This,SSOFTSWITCHTABLE *pSoftSwitchTable);
	 BOOL (*SendMessage)(This,BYTE byFor,BYTE byType);
	 void (*SendMsg)(This,SMESSAGE*);
 	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 //Virtual void (*CyclicProc)(This);
Private
     CAdmin *m_pAdmin;
     CComputer *m_pComputer;
     #if MYSYSTEM_ID != 5
	 CObserveModule *m_pObsModule;
     #else
	 CKpModule  *m_pObsModule;
	 #endif
	 CModule101 *m_p101;
	 CComServer *m_nCom;
	 CComVS0    *m_nCVS0;
	 CComVS1    *m_nCVS1;
	 CTcpServer *m_nTCP;
	 CMsModule  *m_nMS;
	 CMTimer m_pResetTimer;
	 BYTE m_blSystemInitState;
	 BOOL m_byTcpConn;
	 BYTE m_byArmAmout;
	 BYTE m_bySystemID;
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CSystem)
_GLOBAL CSystem *m_pSystem;
#endif
