/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __ANINPUT_H__
#define __ANINPUT_H__
#include "typedefs.h"
#include "bnrslide.h"
#include "bnrhardpin.h"
//Analog Slot
Class CAnIOSlot
{
	 void (*CCAnIOSlot)(This);
	 void (*DCAnIOSlot)(This);
Public
     Virtual void (*InitSlot)(This,SHARDSLOT *pSlot);
     Virtual CPin* (*GetPin)(This,BYTE byNumber);
	 void (*Connect)(This,CAnalogPin *pPin);
Private
     CAnalogPin m_pPin[2]; 
     DECLARE_IMPLEMENT_BASE(CSlot)
}
DECLARE_DEFINITION(CAnIOSlot)
//Analog Slot 4
Class CAnIOSlot4
{
	 void (*CCAnIOSlot4)(This);
	 void (*DCAnIOSlot4)(This);
Public
     Virtual void (*InitSlot)(This,SHARDSLOT *pSlot);
     Virtual CPin* (*GetPin)(This,BYTE byNumber);
	 void (*Connect)(This,CAnalogPin *pPin);
Private
     CAnalogPin m_pPin[DEV_MAX_AI_X20AI4622_PIN]; 
     DECLARE_IMPLEMENT_BASE(CSlot)
}
DECLARE_DEFINITION(CAnIOSlot4)
//Digital Slot
Class CDgIOSlot
{
	 void (*CCDgIOSlot)(This);
	 void (*DCDgIOSlot)(This);
Public
     Virtual void (*InitSlot)(This,SHARDSLOT *pSlot);
     Virtual CPin* (*GetPin)(This,BYTE byNumber);
     void (*Connect)(This,CDigitalPin *pPin);
Private
     #if MYSYSTEM_ID != 5 
	 CDigitalPin m_pPin[32]; 
     #else
	 CDigitalPin m_pPin[12]; 
     #endif
	 DECLARE_IMPLEMENT_BASE(CSlot)
}
DECLARE_DEFINITION(CDgIOSlot)
//Counter Slot
Class CCountSlot
{
	 void (*CCCountSlot)(This);
	 void (*DCCountSlot)(This);
Public
	 Virtual void (*InitSlot)(This,SHARDSLOT *pSlot);
	 Virtual CPin* (*GetPin)(This,BYTE byNumber);
	 void (*Connect)(This,CDCounterPin *pPin);
Private
	 CDCounterPin m_pPin[2]; 
	 DECLARE_IMPLEMENT_BASE(CSlot)
}
DECLARE_DEFINITION(CCountSlot)
//Temperature Slot
Class CTemperatureSlot
{
	void (*CCTemperatureSlot)(This);
	void (*DCTemperatureSlot)(This);
Public
	Virtual void (*InitSlot)(This,SHARDSLOT *pSlot);
	Virtual CPin* (*GetPin)(This,BYTE byNumber);
	void (*Connect)(This,CTemperaturePin *pPin);
Private
	CTemperaturePin m_pPin[2]; 
	DECLARE_IMPLEMENT_BASE(CSlot)
}
DECLARE_DEFINITION(CTemperatureSlot)
#endif
