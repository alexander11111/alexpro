/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __FREQ_H__
#define __FREQ_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"
#include "bnrdevtu.h"
#include "bnrdevts.h"
Class CFreq
{
	 void (*CCFreq)(This);
	 void (*DCFreq)(This);
Public
     void (*StartFC)(This);
     void (*StopFC)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
Public
     STFPARAM *pP;
     CDevTU *pTU0;
     CDevTU *pTU1;
	 CDevTS *pTS0;
	 CDevTS *pTS1;
     WORD *m_pwVL0;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CFreq)
#endif
