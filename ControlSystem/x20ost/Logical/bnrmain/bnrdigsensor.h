/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DIGITALSENSOR_H__
#define __DIGITALSENSOR_H__
#include "typedefs.h"
#include "bnrsensr.h"
#if MYSYSTEM_ID != 5
Class CDigitalSensor
{
	 void (*CCDigitalSensor)(This);
	 void (*DCDigitalSensor)(This);
Private
     void (*EventGen)(This);
     void (*SetRemOut)(This,BYTE byNumber,UINT Value);
	 void (*SetPulce)(This,BYTE byNumber,UINT wValue,UINT wTime);
	 void (*PulceGen)(This);
     Virtual void (*InitSensor)(This,SSWITCHTABLE *pSTable);
     Virtual void (*EventHandler)(This,SMESSAGE*);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual void (*RunAutomat)(This);
Public
     //DWORD m_dwInState;
     //DWORD m_dwOutState;
	 UINT m_nCurrValue[32];
	 UINT m_nPulceTime[32];
	 //BYTE m_byNumber;
     BOOL m_blPulceGo[32]; 
Private
	 DECLARE_IMPLEMENT_BASE(CSensor)
}
DECLARE_DEFINITION(CDigitalSensor)
#endif
#endif
