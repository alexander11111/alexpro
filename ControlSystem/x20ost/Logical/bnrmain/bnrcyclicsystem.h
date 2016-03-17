/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __CYCLICSYSTEM_H__
#define __CYCLICSYSTEM_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrpob.h"
//#include "bnrauto.h"
#include "bnrmytimer.h"
Class CCyclicSystem
{
	 void (*CCCyclicSystem)(This);
	 void (*DCCyclicSystem)(This);
Public
     void (*Create)(This,SINT* chProcName,BYTE byStateProc,BYTE byPeriod);
     void (*CreateSuspend)(This,SINT* chProcName,BYTE byPeriod);
     void (*Start)(This);
	 void (*Stop)(This);
	 void (*SetStateProc)(This,BYTE byStateProc);
	 void (*SetBoxID)(This,BYTE byID);
	 void (*SetPeriod)(This,BYTE byPeriod);
	 void (*SetName)(This,SINT* chProcName);
	 void (*SendMessageData)(This,BYTE byBox,BYTE byFor,BYTE byType,PVOID pData,WORD wLen);
	 void (*SendMessageData1)(This,BYTE byBox,BYTE byFor,BYTE byType,SMESSAGE *pInMsg, PVOID pData,WORD wLen);
	 BYTE (*GetStateProc)(This);
	 WORD (*GetWordParam)(This,BYTE *pbyParam,BYTE *pbyOut);
     Virtual void (*CyclicProc)(This);
	 Virtual BOOL (*GetMessage)(This);
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);

	 void (*SetMsgAuto)(This,SMESSAGE*);
	 BOOL (*SetState)(This,TStateCode vNewState);
	 TStateCode (*GetStateCode)(This);
	 BOOL (*HandleEvent)(This,TEvent vEvent);
Protected
	 Virtual BOOL (*HandleTask)(This,TTask* pvTask);
	 Virtual TStateList* (*GetStateList)(This);
	 TState* (*GetState)(This);
Protected
	 BYTE v[20];
	 TState*  m_pvState; 
     TStateCode m_vState; 
	 TStateList *m_pStateList;
Private
	 BYTE  m_byPeriod;
	 BYTE  m_byStateProc;
	 BYTE  m_byBoxID;
	 SINT  m_chProcName[DEV_JOB_MAX_PNME];
	 SMESSAGE m_nsMessage;
	 DWORD m_dwAmoutQuant;
	 CMTimer m_nATmr[4];
	 DWORD m_dwTM[4];
	 BYTE m_byAutoState;
	 BYTE V0,V1;
	 DWORD m_dwAutoTime;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CCyclicSystem)
#endif
