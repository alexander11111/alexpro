/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrmytimer.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
void CMTimer_OfTimer(This)
{
     DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)  
     pB->OfTimer(pB);
}
void CMTimer_OnTimer(This,DWORD dwTime)
{
     DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)  
	 pB->OnTimer(pB,dwTime);
	 pT->m_dwSTime = dwTime; 
}
void CMTimer_Restart(This)
{ 
	 DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)
	 pB->OnTimer(pB,pT->m_dwSTime);
}
DWORD CMTimer_GetTime(This)
{ 
	DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)
	//if pB->m_dwTime
    return pB->m_dwTime;
}
void CMTimer_SetTimer(This,BYTE byFor,BYTE byFrom,BYTE byEvent,BYTE byDir,BYTE bySens,BYTE byBox)
{
     DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)  
	 pT->m_byFor   = byFor;
	 pT->m_byFrom  = byFrom;
	 pT->m_byEvent = byEvent;
	 pT->m_byDir   = byDir;
	 pT->m_bySens  = bySens;
	 pT->m_byBox   = byBox;
}
void CMTimer_DoAction(This)
{
	 DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)
	 pT->sMsg.m_swLen        = 9;
	 pT->sMsg.m_sbyFrom      = pT->m_byFrom;
	 pT->sMsg.m_sbyFor       = pT->m_byFor;
	 pT->sMsg.m_sbyIntType   = 0;
	 pT->sMsg.m_sbyServerID  = MYSYSTEM_ID;
	 pT->sMsg.m_sbyDirection = pT->m_byDir;
	 pT->sMsg.m_sbySensor    = pT->m_bySens;
	 pT->sMsg.m_sbyType      = pT->m_byEvent;
	 FPUT(pT->m_byBox,(BYTE*)&pT->sMsg);
}
void CMTimer_CMTimer(This)
{
     DECLARE_MULTI_OPEN(CMTimer,CSystemTimer) 
	 DECLARE_REGISTRATION(CMTimer,GetTime)
	 DECLARE_REGISTRATION(CMTimer,OnTimer)
	 DECLARE_REGISTRATION(CMTimer,OfTimer)
	 DECLARE_REGISTRATION(CMTimer,SetTimer)
	 DECLARE_REGISTRATION(CMTimer,Restart)
	 DECLARE_VIRTUAL_FUNC(CMTimer,DoAction)
}
void CMTimer_DCMTimer(This)
{
	 DECLARE_MULTI_OPEN(CMTimer,CSystemTimer)
}
DECLARE_MULTI_CREATE(CMTimer,CSystemTimer)

