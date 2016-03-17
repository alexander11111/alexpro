/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __SYSTEMTIMER_H__
#define __SYSTEMTIMER_H__
#include "typedefs.h"
Class CSystemTimer
{
	 void (*CCSystemTimer)(This);
	 void (*DCSystemTimer)(This);
	 void (*RunTimer)(This);
	 void (*OnTimer)(This,DWORD);
	 void (*OfTimer)(This);
	 void (*SetTimerID)(This,BYTE);
     Virtual void (*DoAction)(This);
Public
	 DECLARE_IMPLEMENT
     BOOL m_blTimerState;
	 DWORD m_dwTime;
	 BYTE m_byTimerID;
}
DECLARE_DEFINITION(CSystemTimer)
#endif
