/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __INGATE_H__
#define __INGATE_H__
#include "typedefs.h"
Class CInputGate
{
	 void (*CCInputGate)(This);
	 void (*DCInputGate)(This);
	 void (*Init)(This,BYTE,UINT*,REAL,REAL);
	 UINT (*GetInput)(This);
	 UINT (*GetMInput)(This);
	 UINT (*GetRealInput)(This);
	 UINT (*HiFilter)(This,UINT);
	 void (*SetResistance)(This,REAL rCurrRes);
	 void (*SetInput)(This,UINT nValue);
     void (*FilterEnable)(This,BYTE);
Public
     BYTE m_byID;
	 BOOL m_blFEnable;
	 BOOL m_blHiInput;
	 UINT *m_pInpGate;
	 UINT m_pInpValue;
	 UINT m_pHiFilMask;
	 UINT m_pInpFreeValue;
     REAL m_rBaseRes; 
	 REAL m_rCurrRes; 
     REAL m_rKoef; 
     /*
	 DINT  PressFilter[260];
     INT16 Fnum;
	 DINT  FSumm, I1, I2, I3;
     INT16 Fval;
	 */
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CInputGate)
#endif
