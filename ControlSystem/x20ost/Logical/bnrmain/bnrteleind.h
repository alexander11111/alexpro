/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TELEIND_H__
#define __TELEIND_H__
#include "typedefs.h"
#include "bnrtelesensor.h"
enum _tagEnTIParam
{
	 EN_HIL_PR=0, 
	 EN_HIG_PR, 
	 EN_LOL_PR, 
	 EN_LOG_PR, 
	 EN_DTM_PR, 
};
#define DEF_HILIMIT 29000
#define DEF_HIGISTR 28000
#define DEF_LOLIMIT 19000
#define DEF_LOGISTR 18000
#define DEF_DRTIMER 20
Class CTeleInd
{
	 void (*CCTeleInd)(This);
	 void (*DCTeleInd)(This);
Public
     WORD (*CheckTI)(This);
	 void (*SetEventHi)(This,BOOL *bl0,BOOL *bl1,BYTE byEvent);
	 void (*SetEventTimerHi)(This,BYTE byEvent);
	 void (*SetEventLo)(This,BOOL *bl0,BOOL *bl1,BYTE byEvent);
	 void (*SetEventTimerLo)(This,BYTE byEvent);
	 void (*SetChandgeTimer)(This,BYTE byEvent);
	 void (*InitMeter)(This);
	 void (*SetEventEv)(This,BOOL *bl0,BOOL *bl1,BYTE byEvent);
     Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*SetInPinEvent)(This);
	 Virtual void (*SaveAlarmPin)(This);
	 Virtual void (*SendObsrveMsg)(This);
Public
     STIPARAM *pP;
	 WORD *m_pnIN;
	 WORD m_wOldIN;
	 
	 BYTE m_byEvent;
	 BYTE m_byErEventCh;

     BOOL m_blTmSetState; 
     BYTE m_bySetTimer;
	 BYTE m_byErEventHi;
	 
	 BOOL m_blTmRemState; 
     BYTE m_byRemTimer;
	 BYTE m_byErEventLo;

	 BOOL m_blChState; 
     BYTE m_byChTimer;

	 BOOL m_blSHIL,m_blRHIL;
	 BOOL m_blSLOL,m_blRLOL;
	 DECLARE_IMPLEMENT_BASE(CTeleSensor)
}
DECLARE_DEFINITION(CTeleInd)
#endif
