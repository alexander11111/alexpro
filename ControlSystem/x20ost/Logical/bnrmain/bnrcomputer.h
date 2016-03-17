/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __COMPUTER_H__
#define __COMPUTER_H__
#include "typedefs.h"
#include "bnrslide.h"
#include "bnraninput.h"
#include "bnrmessage.h"
//#include "bnrtcpdriver.h"
#include "bnrprocmanager.h"
Class CComputer
{
	 void (*CCComputer)(This);
	 void (*DCComputer)(This);
Public
     void   (*Init)(This,SHARDCOMPUTERTABLE *pTable); 
     void   (*InitDevModule)(This,SHARDCOMPUTERTABLE *pTable);
	 CSlot* (*CreateSlot)(This,SHARDSLOT *psvSlot);
	 void   (*Connect)(This,CSlot *psSlot);
	 CSlot* (*GetSlot)(This,BYTE byNumber);
	 CSlot* (*CreateSlotCPU_260)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlotIF_681)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlot3DI477_6)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlot3DO477_6)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlot3AI375_6)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlotAT2222)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlotDI2377)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlot3AI4622)(This,SHARDSLOT *psvSlot);
	 CSlot* (*CreateSlot3AO775_6)(This,SHARDSLOT *psvSlot);
Private
     CSlot **m_pvSlot;
	 BYTE  m_byArmAmout;
     BYTE  m_byComputerType;
     SINT  m_chComputerName[DEV_MAX_TEXT_NAME];
     SINT  m_chProgrammVersion[DEV_MAX_TEXT_NAME];
     SINT  m_chDateOfWrite[DEV_MAX_TEXT_NAME];
	 BYTE  m_bySlotAmout;
     SHARDCOMPUTERTABLE *m_pConfigTable;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CComputer)
#endif
