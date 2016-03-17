/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DEVICE_H__
#define __DEVICE_H__
#include "typedefs.h"
#include "bnrdebug.h"
#include "bnrpob.h"
#include "bnrmessage.h"
#include "bnrcomputer.h"
Class CDevice
{
	 void (*CCDevice)(This);
	 void (*DCDevice)(This);
Public
     void (*Init)(This,PVOID *psTable);
     void (*ObserveProc)(This);
	 void (*CheckAlarm)(This);
	 BOOL (*SaveChange)(This,BYTE byEvent,WORD wValue,BOOL blAlarm);
	 BOOL (*SavePinState)(This,BYTE byEvent,WORD wValue);
	 void (*SendBroadcast)(This,SKPEVENT *pEV);
	 void (*SendSMessage)(This,BYTE byBox,BYTE byFor,BYTE byType);
	 void (*Switch)(This);
	 REAL (*GetRealParam)(This,BYTE *pbyParam,BYTE *pbyOut);
	 WORD (*GetWordParam)(This,BYTE *pbyParam,BYTE *pbyOut);
	 UDINT (*GetDWordParam)(This,BYTE *pbyParam,BYTE *pbyOut);
	 BOOL (*SEventHandler)(This,SMESSAGE *pMsg);
	 BOOL (*ExtractCMD)(This,SMESSAGE *pMsg);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
	 Virtual void (*PostProc)(This);
	 Virtual void (*SaveAlarmPin)(This);
	 Virtual void (*SetInPinEvent)(This);
	 Virtual void (*SendObsrveMsg)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);

	 void (*SetMsgAuto)(This,SMESSAGE*);
	 BOOL (*SetState)(This,TStateCode vNewState);
	 TStateCode (*GetStateCode)(This);
	 BOOL (*HandleEvent)(This,TEvent vEvent);
Protected
	 Virtual BOOL (*HandleTask)(This,TTask* pvTask);
	 Virtual TStateList* (*GetStateList)(This);
	 TState* (*GetState)(This);
Protected
	 BYTE v[20];
	 TState*  m_pvState; 
     TStateCode m_vState; 
	 TStateList *m_pStateList;
	 CMTimer m_nATmr[4];
	 DWORD m_dwTM[4];
	 BYTE  m_byAutoState;
Public
/*
{
    CDataCommand = packed record
     wDeviceID : Word;
     byParam0  : Byte;
     byParam1  : Byte;
     byParam2  : Byte;
     wParam0   : Word;
     wParam1   : Word;
     wParam2   : Word;
     fParam0   : Single;
     fParam1   : Single;
     fParam2   : Single;
    End;
}
*/
     PVOID pP;
	 BOOL m_blSetAlarm;
     BYTE m_byID;
	 BYTE m_byIID;
	 WORD m_nSize;
	 SHARDCOMPUTERTABLE *m_pPCT;
	 CDataCommand m_nCD;
     //CPin *m_pPN;
	 //PVOID m_pvValue;
	 //BOOL *m_pvAlValue;
     CComputer *m_pComputer; 
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CDevice)
#endif
