/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "typedefs.h"
#include "bnrcyclicsystem.h"
#include "bnrmytimer.h"
#include "bnrmessage.h"
#include "bnrpob.h"
#define MAX_COMMAND_LENGTH 4
enum _tagSystemState
{
	 SYS_ST00_NULL=0,
	 SYS_ST01_DISC,
	 SYS_ST02_CONN,
	 SYS_ST03_WAIT_CONF,
	 SYS_ST04_SYST_READY,
	 SYS_ST05_WAIT_READY,
};
Class CAdmin
{
	 void (*CCAdmin)(This);
	 void (*DCAdmin)(This);
Public
     void (*Init)(This);
     BOOL (*SendMessage)(This,BYTE byBox,BYTE byFor,BYTE byType,BYTE byDir,BYTE bySens);
	 void (*PreCommHandler)(This,SMESSAGE *pMsg);
	 void (*HandCommHandler)(This,DWORD b_lCode,BYTE ps,BYTE *pbyBuffer,BYTE byLength);
	 void (*SetSystemID)(This,BYTE);
	 void (*SetState)(This,BYTE);
	 BYTE (*GetState)(This);
	 BOOL (*AdminAutomat)(This,SMESSAGE*);
	 void (*DevVersion)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This);
Private
     BYTE m_bySystemState;
     //SMESSAGE m_sMsg;
	 CMTimer m_pTAskConfig;
	 CMTimer m_pTSendState;
	 BOOL m_blArmState;
	 BYTE m_bySystemID;
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CAdmin)
#endif
