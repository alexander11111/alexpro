/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrslide.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
void CSlot_Init(This,SHARDSLOT *psvSlot)
{
     DECLARE_SINGLE_OPEN(CSlot)
	 pT->m_bySlotNumber = psvSlot->bySlotNumber;
	 pT->m_bySlotType   = psvSlot->bySlotType;
	 pT->m_byAmPin      = psvSlot->byPinAmout;
	 pT->m_byState      = psvSlot->byState;
	 pT->m_pvAlmState   = psvSlot->pvAlmState;
	 pT->InitSlot(pC,psvSlot);
}
void CSlot_InitSlot(This,SHARDSLOT *psvSlot)
{
     DECLARE_SINGLE_OPEN(CSlot)
}
//Constructor-Destructor
void CSlot_CSlot(This)
{
     DECLARE_SINGLE_OPEN(CSlot) 
	 DECLARE_REGISTRATION(CSlot,Init)
	 DECLARE_REGISTRATION(CSlot,InitSlot)
}
void CSlot_DCSlot(This)
{
	 DECLARE_SINGLE_OPEN(CSlot)
}
DECLARE_SINGLE_CREATE(CSlot)

