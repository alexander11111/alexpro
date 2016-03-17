/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TEMPER_H__
#define __TEMPER_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"

Class CTemper
{
	 void (*CCTemper)(This);
	 void (*DCTemper)(This);
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
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
Public
     STTMPARAM *pP;
	 WORD *m_pwVL0;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CTemper)
#endif
