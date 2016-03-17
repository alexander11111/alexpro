/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __OBSYS_H__
#define __OBSYS_H__
#include "typedefs.h"
#include "bnrdevice.h"
#include "bnrpin.h"
#include "bnrcyclicsystem.h"
#include "bnrfreq.h"
#include "bnrpunit.h"
/*
//Модуль слежения
typedef struct _tagODSData
{
	//BYTE byAutoStart;
	//BYTE byPreStart;
	//BYTE byStart;
	//BYTE byStop;
	//BYTE byFinish;
    //BYTE byMode;
    DWORD dwSysState;
	WORD wJTMPreStart;
	WORD wTMPreStart;
	WORD wJTMStart;
	WORD wTMtart;
}SOBSMDATA;
*/

//Состояния модуля проливной 
#define MWSY_NULL_ST00               0 
#define MWSY_WAIT_OPER_ST01          1 
#define MWSY_OPER_ST02               2 
#define MWSY_WAIT_STOP_ST03          3
//таймеры
#define TMR_WTOP               0 
#define TMR_OPER               1 
#define TMR_WTST               2 
//признаки
#define MS_IS_AUST          0x0001 
#define MS_IS_WGHT          0x0002  
#define MS_CM_AUST          0x0100
#define MS_CM_HNST          0x0200
#define MS_CM_HSTP          0x0400
#define MS_CM_FNSH          0x0800

Class CObsSys
{
	 void (*CCObsSys)(This);
	 void (*DCObsSys)(This);
Public
	 Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual void (*InitTCHN)(This,PVOID psTable);
     Virtual void (*PreProc)(This);
	 Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual PVOID (*GetData)(This,BYTE *pData,WORD *nLen);
	 void (*SetMask)(This,DWORD dwMask);
	 void (*RemMask)(This,DWORD dwMask);
	 void (*StopPU)(This);
	 void (*StartPU)(This);
	 void (*StopFC)(This);
	 void (*StartFC)(This);
	 void (*StopCT)(This);
	 void (*StartCT)(This);
Protected
     BOOL (*SendMessage)(This,BYTE,BYTE);
     Virtual BOOL (*HandleTask)(This,TTask* pvTask);
	 Virtual TStateList* (*GetStateList)(This);
Public
     SOBSPARAM *pP;
     CFreq *pF0,*pF1,*pF2;
     CPunit *pPU0,*pPU1;
     BYTE m_byModuleID;
	 DECLARE_IMPLEMENT_BASE(CDevice)
}
DECLARE_DEFINITION(CObsSys)
#endif
