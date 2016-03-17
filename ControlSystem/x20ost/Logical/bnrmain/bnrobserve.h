/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/
//
#ifndef __DIRMODULE_H__
#define __DIRMODULE_H__
#include "typedefs.h"
#if MYSYSTEM_ID != 5
#include "bnrcyclicsystem.h"
#include "bnrdirmodule.h"
#include "bnrmytimer.h"
#include "bnradmin.h"
#include "bnrflash.h"
typedef void (*PFNVOID)(void);
Class CObserveModule
{
	void (*CCObserveModule)(This);
	void (*DCObserveModule)(This);
Public
	void (*Init)(This,SSOFTSWITCHTABLE *pSoftSwitchTable);
	void (*CreateObserve)(This,SSOFTSWITCHTABLE *pSoftSwitchTable);
	void (*ConnectToComputer)(This,CComputer *pComputer);
	void (*SetSystemID)(This,BYTE);
	void (*GetObserveData)(This,BYTE byEvent);
	CDirectionModule* (*GetDirection)(This,BYTE byDir);
    CSensor* (*GetSensor)(This,CDirectionModule**,BYTE,BYTE);
	void (*ConnectToAdmin)(This,CAdmin*);
	Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
    Virtual void (*CyclicProc)(This);
Private
    CMFlash m_nFlash;
    CAdmin *m_pAdmin;     
    CComputer *m_pComputer;
    CMTimer m_pRefrechTmr;
	CDirectionModule **m_pDirectionModule;
	SMESSAGE m_nMsg;
	BYTE m_byObserveProc;
	BYTE m_byObsTime;
	BYTE m_bySystemID;
	BYTE m_byTableVersion;
	SINT m_chTableVersionName[DEV_MAX_TEXT_NAME];
	BYTE m_byAmDirection;
	DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CObserveModule)
#endif
#endif