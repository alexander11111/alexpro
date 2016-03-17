/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrsystemtimer.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
void CSystemTimer_RunTimer(This)
{
     DECLARE_SINGLE_OPEN(CSystemTimer)
	 if(pT->m_blTimerState==TRUE)
	 {
	  //Info("\nTime[%w]",&pT->m_dwTime);
      if (pT->m_dwTime--==0)
	  {
		 //Info("\nTime[%w]",&pT->m_dwTime);
         pT->DoAction(pC);
		 pT->m_dwTime = 0;
		 pT->m_blTimerState = FALSE;
		 return;
	  }
	 }
}
void CSystemTimer_DoAction(This)
{
     DECLARE_SINGLE_OPEN(CSystemTimer)
}
void CSystemTimer_OfTimer(This)
{
     DECLARE_SINGLE_OPEN(CSystemTimer) 
	 pT->m_blTimerState = FALSE;
     pT->m_dwTime = 0;
}
void CSystemTimer_OnTimer(This,DWORD dwTime)
{
     DECLARE_SINGLE_OPEN(CSystemTimer) 
	 pT->m_blTimerState = TRUE;
     pT->m_dwTime = dwTime;
}
void CSystemTimer_SetTimerID(This,BYTE byTimerID)
{
     DECLARE_SINGLE_OPEN(CSystemTimer) 
	 pT->m_byTimerID = byTimerID;
}
void CSystemTimer_CSystemTimer(This)
{
     DECLARE_SINGLE_OPEN(CSystemTimer) 
	 DECLARE_REGISTRATION(CSystemTimer,RunTimer)
	 DECLARE_REGISTRATION(CSystemTimer,OnTimer)
	 DECLARE_REGISTRATION(CSystemTimer,OfTimer)
	 DECLARE_REGISTRATION(CSystemTimer,DoAction)
	 DECLARE_REGISTRATION(CSystemTimer,SetTimerID)
	 pT->m_dwTime = 0;
	 pT->m_blTimerState = FALSE;
	 FCTIMER(pT);
}
void CSystemTimer_DCSystemTimer(This)
{
	 DECLARE_SINGLE_OPEN(CSystemTimer)
	 FDTIMER(pT);
}
DECLARE_SINGLE_CREATE(CSystemTimer)

