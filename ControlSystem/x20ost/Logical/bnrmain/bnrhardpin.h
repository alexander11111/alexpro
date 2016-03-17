/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __HARDPIN_H__
#define __HARDPIN_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrpin.h"
//Analog Pin
Class CAnalogPin
{
	 void (*CCAnalogPin)(This);
	 void (*DCAnalogPin)(This);
Public
	 Virtual void (*InitPin)(This,PVOID);
     Virtual void (*SetPin)(This,SPIN*);
	 Virtual void (*GetPin)(This,SPIN*);
	 Virtual PVOID (*GetAddrPin)(This);
	 Virtual PVOID (*GetAddrAlmStatePin)(This);
Private
     UINT *m_vpHardPin;
	 DECLARE_IMPLEMENT_BASE(CPin)
}
DECLARE_DEFINITION(CAnalogPin)
//Digital Pin
Class CDigitalPin
{
	 void (*CCDigitalPin)(This);
	 void (*DCDigitalPin)(This);
Public
	 Virtual void (*InitPin)(This,PVOID);
	 Virtual void (*SetPin)(This,SPIN*);
	 Virtual void (*GetPin)(This,SPIN*);
	 Virtual PVOID (*GetAddrPin)(This);
	 Virtual PVOID (*GetAddrAlmStatePin)(This);
Private
     BOOL *m_vpHardPin;
	 DECLARE_IMPLEMENT_BASE(CPin)
}
DECLARE_DEFINITION(CDigitalPin)
//Counter Pin
Class CDCounterPin
{
	void (*CCDCounterPin)(This);
	void (*DCDCounterPin)(This);
Public
	Virtual void (*InitPin)(This,PVOID);
	Virtual void (*SetPin)(This,SPIN*);
	Virtual void (*GetPin)(This,SPIN*);
	Virtual PVOID (*GetAddrPin)(This);
	Virtual PVOID (*GetAddrAlmStatePin)(This);
Private
	UINT *m_vpHardPin;
	DECLARE_IMPLEMENT_BASE(CPin)
}
DECLARE_DEFINITION(CDCounterPin)
//Temperature Pin
Class CTemperaturePin
{
	void (*CCTemperaturePin)(This);
	void (*DCTemperaturePin)(This);
Public
	Virtual void (*InitPin)(This,PVOID);
	Virtual void (*SetPin)(This,SPIN*);
	Virtual void (*GetPin)(This,SPIN*);
	Virtual PVOID (*GetAddrPin)(This);
	Virtual PVOID (*GetAddrAlmStatePin)(This);
Private
	UINT *m_vpHardPin;
	DECLARE_IMPLEMENT_BASE(CPin)
}
DECLARE_DEFINITION(CTemperaturePin)
#endif
