/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __PIN_H__
#define __PIN_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrdebug.h"
typedef struct _tagSPin
{
	 UINT iValue;
	 BOOL blValue;
}SPIN;
Class CPin
{
	 void (*CCPin)(This);
	 void (*DCPin)(This);
Public
     void (*Init)(This,SHARDPIN*,SHARDPIN*);
     void (*SetSlot)(This,BYTE bySlot);
	 BYTE (*GetState)(This);
	 Virtual PVOID (*GetAddrPin)(This);
	 Virtual void (*InitPin)(This,PVOID);
     Virtual void (*SetPin)(This,SPIN*);
	 Virtual void (*GetPin)(This,SPIN*);
Private
     BOOL m_blPinON;
     BOOL m_blPinOFF;
     BYTE m_byPinNumber; 
	 BYTE m_bySlotNumber; 
	 BYTE m_byPinState; 
	 PVOID m_pvAlmState;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CPin)
#endif
