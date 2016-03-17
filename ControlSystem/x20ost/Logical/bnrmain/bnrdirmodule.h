/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __OBSERVEMODULE_H__
#define __OBSERVEMODULE_H__
#include "typedefs.h"
#if MYSYSTEM_ID != 5
#include "bnrmessage.h"
#include "bnrsmartsensor.h"
#include "bnridlesensor.h"
#include "bnrdigsensor.h"
#include "bnrcomputer.h"
#include "bnradmin.h"
#include "bnroutgate.h"
#include "bnrflash.h"
#include "bnringate.h"
Class CDirectionModule
{
	void (*CCDirectionModule)(This);
	void (*DCDirectionModule)(This);
Public
	void (*Init)(This,SDIRTABLE *pDirect,CMFlash *pFlash);
    void (*ObserveProc)(This);
	WORD (*GetInOutData)(This,SMESSAGE*);
	void (*SwitchSensor)(This,CSensor *pSensor,SSWITCHTABLE *pSwitchTable);
	void (*SwitchDigitalSensor)(This,CSensor *pSensor,SSWITCHTABLE *pSwitchTable);
	void (*ConnectSensor)(This,CSensor *pSensor,SSWITCHTABLE *pSwitchTable);
	void (*ConnectToComputer)(This,CComputer *pComputer);
	void (*EnableGetData)(This,BOOL);
	void (*ConnectToAdmin)(This,CAdmin*);
	BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	void (*SendMessage)(This,SMESSAGE *pMsg);
	void (*WordXCHG)(This,SMESSAGE *pMsg);
	WORD (*GetXWData)(This,SMESSAGE *pMsg);
	WORD (*GetDigMcData)(This,SMESSAGE *pMsg);
	void (*GetDirMode)(This,SMESSAGE *pMsg);
	void (*SetDirMode)(This,SMESSAGE *pMsg);
	DWORD (*GetDwordParam)(This,BYTE *pbyParam);
	WORD (*GetWordParam)(This,BYTE *pbyParam);
	void (*AddDword)(This,WORD *pwLen,BYTE *byMsg,BYTE *byParam);
	void (*AddWord)(This,WORD *pwLen,BYTE *byMsg,BYTE *byParam);
	void (*SetInputGate)(This,SINPUTGATE *pING);
	BOOL (*Serialize)(This,BOOL blDir);
	BOOL (*SaveContenst)(This);
    BOOL (*LoadContenst)(This);
	void (*SetCurentTank)(This,BYTE byTank);
	void (*SaveTable)(This,SCONTENSTTABLE *psTable);
    void (*LoadTable)(This,SCONTENSTTABLE *psTable);
Private
    CMFlash *m_pFlash;
    CAdmin *m_pAdmin;
	CMTimer m_pStatSnsTmr;
    CComputer *m_pComputer;
	CInputGate m_nInpGate[32];
	PVOID m_pvInGate;
	PVOID m_pvOutGate;
	WORD m_wSensorMode;
	WORD m_wLayerMode;
	BYTE m_byAmInpGate;
	BYTE m_byTypeTest;
	BYTE m_byStatSnsConn;
	BYTE m_byDirectionID;
	BYTE m_byDirectionCode;
	BYTE m_bySystemID;
	BYTE m_byAmSwitching;   
	BYTE m_byDefSett;   
	BOOL m_blGetData;
	BOOL m_blArmState;
	CSensor **m_pSensor;
	SDIRTABLE *m_pDirTable;
	SCONTENSTTABLE m_nST,m_nCT;
	DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CDirectionModule)
#endif
#endif
