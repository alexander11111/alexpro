/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrprocmanager.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#ifdef DEB_CProcManager
SINT *chManState[] = 
{
	"ONN",
    "OFF",
};
#endif
void CProcManager_Init(This,DWORD dwTicTime,BOOL blStatistic)
{
	 INT i;
     DECLARE_SINGLE_OPEN(CProcManager) 
	 for(i=0;i<DEV_MAX_CYC_PROC;i++)
	 pT->m_nCyclicSystem[i] = NULL;
     for(i=0;i<DEV_MAX_SYS_TIMR;i++)
	 pT->m_nSystemTimer[i] = NULL;
	 pT->m_iProcCounter = 0;
	 pT->m_dwTicTime = dwTicTime;
	 pT->m_nMaxProc = 0;
	 pT->m_byCheckQuant = 0;
	 pT->m_nMaxTimer = 0;
	 pT->m_blStatistic = blStatistic;
     #ifdef DEB_CProcManager
	 Info("\n(__)CPMAN::>Create Process Manager:State:%s ",chManState[pT->m_blState]);
     #endif
}
void CProcManager_SetTicTime(This,DWORD dwTicTime)
{
     DECLARE_SINGLE_OPEN(CProcManager)
	 pT->m_dwTicTime = dwTicTime;
}
BOOL CProcManager_ConnectTimer(This,CSystemTimer *pSTimer)
{
	BYTE i;
	DECLARE_SINGLE_OPEN(CProcManager)
	for(i=0;i<DEV_MAX_SYS_TIMR;i++)
	{
	  if(pT->m_nSystemTimer[i]==NULL)    
	  {
        pT->m_nSystemTimer[i] = pSTimer;
		pT->m_nSystemTimer[i]->SetTimerID(pT->m_nSystemTimer[i],i);
		pT->m_nMaxTimer++;
		return TRUE;
	  }
	}
	return FALSE;
}
BOOL CProcManager_DisconnectTimer(This,CSystemTimer *pSTimer)
{
	int i;
	DECLARE_SINGLE_OPEN(CProcManager)
	CSystemTimer *p;
	for(i=0;i<pT->m_nMaxTimer;i++)
	{
	 p = pT->m_nSystemTimer[i];  
	 if(p!=NULL)    
	 {
	  if(p->m_byTimerID==i)
	  {
       p = NULL;
	   if(pT->m_nMaxTimer>0)pT->m_nMaxTimer--;
	   return TRUE;
	  }
	 }
	}
	return FALSE;
}
BOOL CProcManager_ConnectProc(This,CCyclicSystem *pCSystem)
{
	 int i;
     DECLARE_SINGLE_OPEN(CProcManager)
	 for(i=0;i<DEV_MAX_CYC_PROC;i++)
	 {
       if(pT->m_nCyclicSystem[i]==NULL)    
	   {
         pT->m_nCyclicSystem[i] = pCSystem;
		 pT->m_nMaxProc++;
		 return TRUE;
	   }
	 }
	 return FALSE;
}
void CProcManager_DeleteProc(This,SINT *chName)
{
	 INT iIndex;
     DECLARE_SINGLE_OPEN(CProcManager) 
	 if((iIndex=pT->Find(pT,chName))==-1)
	 {
	   pT->m_nCyclicSystem[iIndex] = NULL;
	   if(pT->m_nMaxProc>0)pT->m_nMaxProc--;
	 }
}
int CProcManager_Find(This,SINT *chName)
{
	 INT i;
     DECLARE_SINGLE_OPEN(CProcManager) 
	 for(i=0;i<DEV_MAX_CYC_PROC;i++)
	 {
	  if(strcmp(pT->m_nCyclicSystem[i]->m_chProcName,chName)==0)
	     return i;
	 }
	 return -1;
}
void CProcManager_SuspendThread(This,SINT *chName)
{
	 INT iIndex;
	 CCyclicSystem *p;
     DECLARE_SINGLE_OPEN(CProcManager)
	 if((iIndex=pT->Find(pT,chName))==-1)
	 {
	  p = pT->m_nCyclicSystem[iIndex];
	  p->SetState(p,DEV_CJOB_ST_SUSP);
	 }
}
void CProcManager_ResumeThread(This,SINT *chName)
{
	INT iIndex;
	CCyclicSystem *p;
	DECLARE_SINGLE_OPEN(CProcManager)
	if((iIndex=pT->Find(pT,chName))==-1)
	{
	 p = pT->m_nCyclicSystem[iIndex];
	 p->SetState(p,DEV_CJOB_ST_RESM);
	}
}
void CProcManager_SuspendAll(This)
{
	int i;
	CCyclicSystem *p;
	DECLARE_SINGLE_OPEN(CProcManager)
	for(i=0;i<DEV_MAX_CYC_PROC;i++)
	{
     p = pT->m_nCyclicSystem[i];
	 if(p!=NULL)    
  	 p->SetState(p,DEV_CJOB_ST_SUSP);
	}
}
void CProcManager_ResumeAll(This)
{
	int i;
	CCyclicSystem *p;
	DECLARE_SINGLE_OPEN(CProcManager)
	for(i=0;i<DEV_MAX_CYC_PROC;i++)
	{
	 p = pT->m_nCyclicSystem[i];
	 if(p!=NULL)    
	 p->SetState(p,DEV_CJOB_ST_RESM);
	}
}
//_GLOBAL INT nProc00;
void CProcManager_Run(This)
{
	 INT i;
	 CCyclicSystem *p;
	 CSystemTimer *pS;
     DECLARE_SINGLE_OPEN(CProcManager) 
	 //Proc Section
     if(pT->m_blState == DEV_PROC_STT_ONN)
	 {
     for(i=0;i<pT->m_nMaxProc;i++)
     {
	  p = pT->m_nCyclicSystem[i];
	  //if (p!=NULL)
      if ((pT->m_iProcCounter%p->m_byPeriod)==0)
      if(p->m_byStateProc==DEV_CJOB_ST_RESM) 	 
	  {
      p->CyclicProc(p->pChld);
	  p->GetMessage(p);
	  }
     }
	 }
     //Timer Section
	 if(pT->m_iProcCounter%2==0)
	 {
	 //nProc00++;
	 for(i=0;i<pT->m_nMaxTimer;i++){pS = pT->m_nSystemTimer[i];pS->RunTimer(pS);}
	 }
	 pT->m_iProcCounter++;
	 
	 //Info("\nTime[%w]",&pT->m_iProcCounter);
	 //if(dwFL&DEB_OUT_PMAN_STAT)
	 //if (pT->m_iProcCounter%PRC_MAN_CH_QUANT==0) pT->GetTimeStatistic(pT);
}
void CProcManager_GetTimeStatistic(This)
{
     DECLARE_SINGLE_OPEN(CProcManager)
	 INT i;
	 CCyclicSystem *p;
	 DWORD dwTime;
	 for(i=0;i<pT->m_nMaxProc;i++)
     {
	   p = pT->m_nCyclicSystem[i];
	   dwTime = p->m_dwAmoutQuant*pT->m_dwTicTime;
	   #ifdef DEB_CProcManager
	   Info("\n(%b)CPMAN::>Tic: %d.Time: %d.Proc: %s",&pT->m_byCheckQuant,&p->m_dwAmoutQuant,&dwTime,p->m_chProcName);
	   #endif
	 }
	 pT->m_byCheckQuant++;
}
void CProcManager_Start(This)
{
     DECLARE_SINGLE_OPEN(CProcManager) 
     pT->m_blState = DEV_PROC_STT_ONN;
     #ifdef DEB_CProcManager
	 Info("\n(__)CPMAN::>Start Process Manager");
     #endif
}
void CProcManager_Stop(This)
{
     DECLARE_SINGLE_OPEN(CProcManager)  
     pT->m_blState = DEV_PROC_STT_OFF;
     #ifdef DEB_CProcManager
	 Info("\n(__)CPMAN::>Stop Process Manager");
     #endif
}
void CProcManager_CProcManager(This)
{
     DECLARE_SINGLE_OPEN(CProcManager) 
	 DECLARE_REGISTRATION(CProcManager,Init)
	 DECLARE_REGISTRATION(CProcManager,ConnectProc)
	 DECLARE_REGISTRATION(CProcManager,ConnectTimer)
	 DECLARE_REGISTRATION(CProcManager,DisconnectTimer)
     DECLARE_REGISTRATION(CProcManager,DeleteProc)
	 DECLARE_REGISTRATION(CProcManager,SuspendThread)
     DECLARE_REGISTRATION(CProcManager,ResumeThread)
	 DECLARE_REGISTRATION(CProcManager,SuspendAll)
	 DECLARE_REGISTRATION(CProcManager,ResumeAll)
	 DECLARE_REGISTRATION(CProcManager,Find)
	 DECLARE_REGISTRATION(CProcManager,Run)
	 DECLARE_REGISTRATION(CProcManager,Start)
	 DECLARE_REGISTRATION(CProcManager,Stop)
	 DECLARE_REGISTRATION(CProcManager,SetTicTime)
	 DECLARE_REGISTRATION(CProcManager,GetTimeStatistic)
	 pT->m_blState = DEV_PROC_STT_OFF;
}
void CProcManager_DCProcManager(This)
{
	DECLARE_SINGLE_OPEN(CProcManager)
}
DECLARE_SINGLE_CREATE(CProcManager)

