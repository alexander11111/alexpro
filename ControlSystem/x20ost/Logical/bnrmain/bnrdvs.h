/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DVS_H__
#define __DVS_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"

Class CDvs
{
	 void (*CCDvs)(This);
	 void (*DCDvs)(This);
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
     STVSPARAM *pP;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CDvs)
#endif
