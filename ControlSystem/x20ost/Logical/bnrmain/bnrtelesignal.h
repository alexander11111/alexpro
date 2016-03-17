/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TELESIGNAL_H__
#define __TELESIGNAL_H__
#include "typedefs.h"
#include "bnrtelesensor.h"
#include "bnrpin.h"
#define DEF_SET_PULSE 5
#define DEF_REM_PULSE 5
Class CTeleSignal
{
	 void (*CCTeleSignal)(This);
	 void (*DCTeleSignal)(This);
Public
     BYTE (*CheckTS)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual void (*SetInPinEvent)(This);
	 Virtual void (*SaveAlarmPin)(This);
	 Virtual void (*SendObsrveMsg)(This);
Public
     STSPARAM *pP;
	 BOOL *m_pbIN;
	 BOOL m_blFSignal;
     BOOL m_blTmSetState; 
	 BOOL m_blTmRemState;   
     BYTE m_bySetPulce;
	 BYTE m_byRemPulce;
	 DECLARE_IMPLEMENT_BASE(CTeleSensor)
}
DECLARE_DEFINITION(CTeleSignal)
#endif
