/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MSMODULE_H__
#define __MSMODULE_H__
#include "typedefs.h"
#include "bnrcyclicsystem.h"
#include "bnrtu.h"
#include "bnrts.h"
#include "bnrtemper.h"
#include "bnrstgate.h"
#include "bnrpunit.h"
#include "bnrpress.h"
#include "bnrfreq.h"
#include "bnrcount.h"
#include "bnrlevel.h"
#include "bnrdevice.h"
#include "bnrdvs.h"
#include "bnrobsys.h"
//#include "bnrswitcher.h"
//#include "bnrtmcounter.h"
//#include "bnralarm.h"
#include "bnrcomputer.h"
#include "bnrflash.h"

Class CMsModule
{
	 void (*CCMsModule)(This);
	 void (*DCMsModule)(This);
Public
     void (*Init)(This,SHARDCOMPUTERTABLE *pPCTable,SSOFTSWITCHTABLE *pMsTable);
     void (*CreateChannels)(This,SDIRTABLE *pDTable);
     BOOL (*ScadaHandler)(This,SMESSAGE *pMsg);
	 BOOL (*HardControl)(This,SMESSAGE *pMsg);
	 void (*ObserveOutProc)(This);
     Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This); 
Public
     //SMESSAGE m_nMsg;
     CDevice **m_pDevice; 
     CComputer *m_pComputer;
	 CMTimer m_nOutTMR;
	 SCONTENSTTABLE m_nST,m_nCT;
	 SHARDCOMPUTERTABLE *m_pPCT;
	 SSOFTSWITCHTABLE   *m_pPST;
	 UINT m_wAmChannel;
	 STOUTTBL mOUT;
	 //BYTE m_nSND[]
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CMsModule)
#endif
