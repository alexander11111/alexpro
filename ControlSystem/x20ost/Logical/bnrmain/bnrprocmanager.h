/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __PROCMANAGER_H__
#define __PROCMANAGER_H__
#include "typedefs.h"
#include "bnrcyclicsystem.h"
#include "bnrsystemtimer.h"
#define PRC_MAN_CH_QUANT  1500
Class CProcManager
{
	 void (*CCProcManager)(This);
	 void (*DCProcManager)(This);
Public
     void (*Init)(This,DWORD dwTicTime,BOOL blStatistic);
     void (*SetTicTime)(This,DWORD);
	 void (*GetTimeStatistic)(This);
     BOOL (*Find)(This,SINT *chName);
	 BOOL (*ConnectProc)(This,CCyclicSystem *pCSystem);
	 BOOL (*ConnectTimer)(This,CSystemTimer *pSTimer);
	 BOOL (*DisconnectTimer)(This,CSystemTimer *pSTimer);
	 void (*DeleteProc)(This,SINT *chName);
	 void (*SuspendThread)(This,SINT *chName);
	 void (*ResumeThread)(This,SINT *chName);
	 void (*SuspendAll)(This);
	 void (*ResumeAll)(This);
	 void (*Run)(This);
	 void (*Start)(This);
	 void (*Stop)(This);
Private
     CCyclicSystem *m_nCyclicSystem[DEV_MAX_CYC_PROC];
     CSystemTimer *m_nSystemTimer[DEV_MAX_SYS_TIMR];
     BYTE m_byCheckQuant;
     BOOL m_blState;
	 BOOL m_blStatistic;
     BYTE m_nMaxProc; 
	 BYTE m_nMaxTimer;
	 DWORD m_iProcCounter;
	 DWORD m_dwTicTime;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CProcManager)
#endif
