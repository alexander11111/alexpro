/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __PRESS_H__
#define __PRESS_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"

Class CPress
{
	 void (*CCPress)(This);
	 void (*DCPress)(This);
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
     STPRPARAM *pP;
	 WORD *m_pwVL0;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CPress)
#endif
