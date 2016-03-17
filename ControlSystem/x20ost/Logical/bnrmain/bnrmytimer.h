/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MTIMER_H__
#define __MTIMER_H__
#include "typedefs.h"
#include "bnrsystemtimer.h"
#include "bnrmessage.h"
#include "bnrpob.h"
Class CMTimer
{
	 void (*CCMTimer)(This);
	 void (*DCMTimer)(This);
Public
	 void (*SetTimer)(This,BYTE byFor,BYTE byFrom,BYTE byEvent,BYTE byDir,BYTE bySens,BYTE byBox);
     void (*Restart)(This);
     void (*OnTimer)(This,DWORD);
	 void (*OfTimer)(This);
	 DWORD (*GetTime)(This);
	 Virtual void (*DoAction)(This);
Private
     SHORTMESSAGE sMsg;
     DWORD m_dwSTime;
     BYTE m_byFor;
	 BYTE m_byFrom;
	 BYTE m_byEvent;
	 BYTE m_byDir;
	 BYTE m_bySens;
	 BYTE m_byBox;
	 DECLARE_IMPLEMENT_BASE(CSystemTimer)
}
DECLARE_DEFINITION(CMTimer)
#endif
