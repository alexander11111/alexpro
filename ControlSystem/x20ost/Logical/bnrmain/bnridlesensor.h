/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __IDLESENSOR_H__
#define __IDLESENSOR_H__
#include "typedefs.h"
#if MYSYSTEM_ID != 5
#include "bnrsensr.h"
Class CIdleSensor
{
	 void (*CCIdleSensor)(This);
	 void (*DCIdleSensor)(This);
Public
	 void (*SetMode)(This,USINT);
	 void (*SetState)(This,BOOL);
	 BOOL (*GetState)(This);
Public
	 Virtual void (*InitSensor)(This,PVOID pParam);
     Virtual void (*EventHandler)(This,SMESSAGE*);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual void (*SetInput)(This,SPIN*);
	 Virtual void (*IncInput)(This,INT16 wParam);
	 Virtual void (*SetOutput)(This,BYTE,SPIN*);
	 Virtual void (*CaptureData)(This);
Private
     BOOL m_blIncInput;
     BOOL m_blDecInput;
     WORD m_iInp;
     WORD m_iOut;
     BOOL m_blState;
	 DECLARE_IMPLEMENT_BASE(CSensor)
}
DECLARE_DEFINITION(CIdleSensor)
#endif
#endif
