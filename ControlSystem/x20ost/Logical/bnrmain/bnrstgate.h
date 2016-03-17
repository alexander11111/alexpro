/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __STGATE_H__
#define __STGATE_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"
#include "bnrdevtu.h"
/*
//”правл€емые краны
typedef struct _tagTKParam
{
BYTE byID;
BYTE byAmParam; 
BYTE byType;
BYTE bySlot; 
BYTE byPin; 
BYTE bySlot1; 
BYTE byPin1; 
BYTE byStOP;
BYTE byStCL;
UINT wMaxOpenTime;
UINT wOpenState;
}STKPARAM; 
*/
Class CStGate
{
	 void (*CCStGate)(This);
	 void (*DCStGate)(This);
Public
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
Public
     void (*Open)(This,REAL fOpenPrc);  
	 WORD (*PrcToPulce)(This,REAL fOpenPrc);
	 REAL (*PulceToPrc)(This,DWORD dwPulce);
	 DWORD (*SecToPulce)(This,WORD wOpenTime);
	 BOOL (*GetOpenDir)(This,DWORD dwPulce);
	 WORD (*GetOpenPulce)(This,BOOL blDir,DWORD dwOpenPulce);
	 void (*OpenGate)(This,BOOL blDir,DWORD dwOpenPulce);
Public
     STKPARAM *pP;
     CDevTU *pTU0;
     CDevTU *pTU1;
	 DWORD m_dwOpenState;
	 DWORD m_dwOldJob;
	 DWORD m_dwOpenGate;
	 DWORD m_dwCloseGate;
	 DWORD m_dwPulce;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CStGate)
#endif
