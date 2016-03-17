/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TS_H__
#define __TS_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"
#include "bnrdevts.h"
Class CTs
{
	 void (*CCTs)(This);
	 void (*DCTs)(This);
Public
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
Public
     STSMPARAM *pP;
     CDevTS *pTS0;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CTs)
#endif
