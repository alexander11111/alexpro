/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TELESENSOR_H__
#define __TELESENSOR_H__
#include "typedefs.h"
#include "bnrdebug.h"
#include "bnrpob.h"
#include "bnrmessage.h"
#include "bnrcomputer.h"


Class CTeleSensor
{
	 void (*CCTeleSensor)(This);
	 void (*DCTeleSensor)(This);
Public
     void (*Init)(This,PVOID *psTable);
     void (*ObserveProc)(This);
	 //UINT (*GetW)(This,BYTE *pbyParam);
	 void (*CheckAlarm)(This);
	 BOOL (*SaveChange)(This,BYTE byEvent,WORD wValue,BOOL blAlarm);
	 BOOL (*SavePinState)(This,BYTE byEvent,WORD wValue);
	 void (*SendBroadcast)(This,SKPEVENT *pEV);
	 void (*SendSMessage)(This,BYTE byBox,BYTE byFor,BYTE byType);
	 void (*Switch)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
	 Virtual void (*PostProc)(This);
	 Virtual void (*SaveAlarmPin)(This);
	 Virtual void (*SetInPinEvent)(This);
	 Virtual void (*SendObsrveMsg)(This);

Public
     STIPARAM *pP;
	 BOOL m_blSetAlarm;
     BYTE m_byID;
     BYTE m_byType;
	 BYTE m_byALC;
	 BYTE m_byOldEvent;
	 SHARDCOMPUTERTABLE *m_pPCT;
     CPin *m_pPN;
	 PVOID m_pvValue;
	 BOOL *m_pvAlValue;
     CComputer *m_pComputer; 
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CTeleSensor)
#endif
