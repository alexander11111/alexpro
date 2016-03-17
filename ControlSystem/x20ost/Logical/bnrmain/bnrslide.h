/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DEVICESlot_H__
#define __DEVICESlot_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrpin.h"
Class CSlot
{
	 void (*CCSlot)(This);
	 void (*DCSlot)(This);
Public
     void (*Init)(This,SHARDSLOT *psvSlot);
     Virtual void (*InitSlot)(This,SHARDSLOT *pSlot);
	 Virtual CPin* (*GetPin)(This,BYTE byNumber);
Private
     BYTE m_bySlotNumber;
     BYTE m_bySlotType;
	 BYTE m_byAmPin;
	 BYTE m_byState;
	 PVOID m_pvAlmState;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CSlot)
#endif
