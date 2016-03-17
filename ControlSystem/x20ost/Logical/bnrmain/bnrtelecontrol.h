/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TELECTRL_H__
#define __TELECTRL_H__
#include "typedefs.h"
#include "bnrtelesensor.h"
enum _enTUCommand
{
     EN_STT_PULCE=9,
	 EN_STT_SIGN =10,
};
#define DEF_PULCE 20
Class CTeleControl
{
	 void (*CCTeleControl)(This);
	 void (*DCTeleControl)(This);
Public
     void (*SetPulce)(This);
     Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
	 Virtual void (*PostProc)(This);
	 Virtual void (*SetInPinEvent)(This);
	 Virtual void (*SaveAlarmPin)(This);
	 Virtual void (*SendObsrveMsg)(This);
Public
	 STUPARAM *pP;
     //BOOL m_blSetAlarm;
     BYTE m_bySetPulce;
	 BYTE m_byStPulce;
	 BOOL *m_pbOT;
	 DECLARE_IMPLEMENT_BASE(CTeleSensor)
}
DECLARE_DEFINITION(CTeleControl)
#endif
