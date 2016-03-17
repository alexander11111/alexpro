/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __TPUNIT_H__
#define __TPUNIT_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"
#include "bnrdevtu.h"
#include "bnrdevts.h"
Class CPunit
{
	 void (*CCPunit)(This);
	 void (*DCPunit)(This);
Public
     void (*StartPU)(This);
     void (*StopPU)(This);
     void (*ClosePU)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
Public
     SPUPARAM *pP;
	 CDevTU *pTU0;
     CDevTS *pTS0;
     CDevTS *pTS1;
     CDevTS *pTS2;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CPunit)
#endif
