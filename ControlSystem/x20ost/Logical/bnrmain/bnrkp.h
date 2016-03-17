/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __KPMODULE_H__
#define __KPMODULE_H__
#include "typedefs.h"
#include "bnrcyclicsystem.h"
#include "bnrtelesensor.h"
#include "bnrtelesignal.h"
#include "bnrteleind.h"
#include "bnrtelecontrol.h"
#include "bnrcomputer.h"
#include "bnrflash.h"

Class CKpModule
{
	 void (*CCKpModule)(This);
	 void (*DCKpModule)(This);
Public
     void (*Init)(This,SHARDCOMPUTERTABLE *pPCTable,SSOFTSWITCHTABLE *pKPTable);
     void (*SaveInPin)(This);
	 void (*SaveAlarmPin)(This);
	 BOOL (*SaveSlotState)(This);
     void (*CreateChannels)(This,SDIRTABLE *pDTable);
	 void (*Connect)(This,SINT *pchPhone);
	 void (*Disconnect)(This);
	 void (*DisconnectL2)(This);
	 void (*StartConnect)(This);
	 void (*CheckSlot)(This);
	 BOOL (*Serialize)(This,BOOL blDir);
	 BOOL (*SaveContenst)(This);
     BOOL (*LoadContenst)(This);
	 void (*StartCheck)(This,BYTE byTime,BYTE byObject);
	 void (*StopCheck)(This);
	 void (*SendObserveMsg)(This);
 	 void (*SaveTable)(This,SCONTENSTTABLE *psTable);
     void (*LoadTable)(This,SCONTENSTTABLE *psTable);
     Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This); 
Public
     CTeleSensor **m_pTeleSensor; 
     CComputer *m_pComputer;
	 CMTimer m_nConnTMR,m_nDiscTMR,m_pResetTimer,m_nConnRepTMP,m_nPuCommTMR,m_nSDiscTMR,m_nRepConnTMR;
	 SCONTENSTTABLE m_nST,m_nCT;
	 SHARDCOMPUTERTABLE *m_pPCT;
	 SSOFTSWITCHTABLE   *m_pPST;
	 SKPPARAM *m_pKP;
	 SDIRTABLE *m_pD;
	 CMFlash m_nFlash;
	 CMFlash *m_pFlash;
	 BOOL m_blBufferST;
	 BOOL m_blDiscStart;
	 BOOL m_blIfConnect;
	 BYTE m_byObsTime;
	 BYTE m_byObsObject;
	 BYTE m_byDiscProc;
	 BYTE m_byConnCT;
	 BYTE m_byCallCT;
	 BYTE m_byKpState;
     BYTE m_byKpID;
	 WORD m_wAmChannel,m_wCallTime;
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CKpModule)
#endif
