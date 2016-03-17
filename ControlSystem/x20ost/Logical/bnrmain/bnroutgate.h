/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __OUTGATE_H__
#define __OUTGATE_H__
#include "typedefs.h"
#if MYSYSTEM_ID != 5
#include "bnrhardpin.h"
Class COutGate
{
	 void (*CCOutGate)(This);
	 void (*DCOutGate)(This);
Public
     void (*Init)(This,BYTE byID,BYTE byType,BYTE byOType,BYTE byMode,REAL rMinRamp,REAL rMaxRamp,CPin *pPin,UINT wLo,UINT wHi,UINT wIni,BYTE byState,WORD wBase,WORD wOTime,SINT *pName);
     void (*OpenGate)(This,REAL rOpenState);
	 void (*OpenGateReq)(This,BYTE);
	 void (*StopGate)(This);
	 void (*SetGate)(This,UINT wValue);
	 void (*SetManGate)(This,UINT wValue);
	 void (*SetDefault)(This);
	 UINT (*GetGate)(This);
	 BYTE (*GetPrcGate)(This);
	 void (*RunGate)(This);
	 void (*SetState)(This,BYTE);
	 void (*SetMinRamp)(This,REAL);
	 void (*SetMaxRamp)(This,REAL);
	 void (*SetHiLimit)(This,WORD wValue);
	 void (*SetOutTime)(This,WORD wValue);
Private
     BYTE m_byGateID;
	 BYTE m_byOType;
	 BYTE m_byMode;
     BYTE m_byType;
	 BYTE m_byState;
	 REAL m_rMinRamp;
     REAL m_rMaxRamp;
	 REAL m_wMaxQt;
	 UINT *m_pwOut;
	 UINT m_wOTime;
	 UINT m_wOut;
	 UINT m_wMinRampValue;
	 UINT m_wMaxRampValue;
	 REAL m_wOperGate;
	 UINT m_wBase;
     UINT m_wLoLimit;
     UINT m_wHiLimit;
	 REAL m_wTickOpen;
	 REAL m_wTickConst;
	 UINT m_wCurrOpenState;
	 UINT m_wIniState;
	 DWORD m_wTick;

	 WORD  m_wQTime;
	 DWORD m_dwTime;
	 BOOL  m_blProccState;
	 CPin  *m_pConnectionPin;
	 SINT  m_chName[30];
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(COutGate)
#endif
#endif
