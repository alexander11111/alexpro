/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TU_H__
#define __TU_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"
#include "bnrdevtu.h"
Class CTu
{
	 void (*CCTu)(This);
	 void (*DCTu)(This);
Public
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
Public
     STUMPARAM *pP;
     CDevTU *pTU0;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CTu)
#endif
