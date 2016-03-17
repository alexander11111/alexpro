/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrsensr.h
 * Author: Abramenya
 * Created: January 23, 2009
 *******************************************************************/
#ifndef __BSSENSOR_H__
#define __BSSENSOR_H__
#include "typedefs.h"
#if MYSYSTEM_ID != 5
#include "bnrdebug.h"
#include "bnrpin.h"
#include "bnrmessage.h"
#include "bnroutgate.h"
#include "bnrauto.h"
#include "bnrmytimer.h"
#include "bnringate.h"
Class CSensor
{
     void (*CCSensor)(This);
	 void (*DCSensor)(This);
Public
     void (*Init)(This,SSWITCHTABLE*);
     void (*InitDigital)(This,SSWITCHTABLE*);
     void (*SetSensorID)(This,BYTE);
     BYTE (*GetSensorID)(This);
	 void (*SetParType)(This,BYTE);
     BYTE (*GetParType)(This);
     void (*SetDirection)(This,PVOID,BYTE);
	 BYTE (*GetDirection)(This);
	 void (*ObserveProc)(This);
     void (*ConnectFCP)(This,CInputGate*);
	 void (*ConnectOutGate)(This,COutGate*);
	 ///////////////////////////////
     void (*SetLoLimit)(This,UINT);
	 void (*SetHiLimit)(This,UINT);
     void (*SetLoAlLimit)(This,INT16);
	 void (*SetHiAlLimit)(This,INT16);
	 ///////////////////////////////
	 void (*EnableInput)(This,BOOL);
	 void (*EnableProc)(This,BOOL);
	 void (*EnableOutput)(This,BOOL);
     ///////////////////////////////
	 void (*SetLoopMode)(This);
	 void (*SetManMode)(This);
	 void (*SetAutoMode)(This);
     ///////////////////////////////
	 void (*Enable)(This);
	 void (*Disable)(This);
	 void (*SetCallBackProc)(This,PCLB);
	 void (*SetState)(This,DWORD dwState);
	 DWORD (*GetState)(This);
	 void (*SendCommand)(This,BYTE byFor,BYTE byType);
	 SPIN* (*GetInput)(This);
	 SPIN* (*GetOutput)(This);
	 //Statistic
	 void (*AddCaptureData)(This,DINT,DINT,DINT);
	 Virtual void (*CaptureData)(This);
	 void (*StartCaptureProc)(This);
	 void (*StopCaptureProc)(This);
	 INT16**(*GetCaptureBuffer)(This);
	 void (*RestartCaptureProc)(This);
     void (*OpenGate)(This);
	 void (*AddData)(This,DINT);
	 void (*CloseGate)(This);
     void (*GetParamTable)(This,BYTE);
     INT16 (*GetWordParam)(This,BYTE *pbyParam);
	 //Event Handler
	 void (*ConnectPinAddres)(This);
	 void (*SEventHandler)(This,SMESSAGE *pMsg);
	 void (*SetEvent)(This,BOOL*,BOOL*,BYTE);
	 void (*SetAutoEvent)(This,BYTE byEvent);
	 Virtual void (*EventGate)(This,BYTE byEvent);
	 //Utilites
	 REAL (*GetRealParam)(This,BYTE *pbyParam);
	 UINT (*GetInParam)(This,REAL nParam);
     void (*CalcGate)(This);
	 UINT (*AcpToInt)(This,UINT);
	 UINT (*IntToAcp)(This,UINT);
	 REAL (*AcpToReal)(This,UINT nAcpCode);
     UINT (*RealToAcp)(This,REAL nParam);
	 void (*SetOutState)(This,BYTE);
	 void (*SetForAll)(This,BYTE byPType,BYTE byPCode,REAL rParam,UINT nParam);
	 void (*SetLEMode)(This);
	 Virtual void (*IncInput)(This,INT16 wParam);
     Virtual void (*GetParam)(This,BYTE);
	 Virtual void (*SetInput)(This,SPIN*);
	 Virtual void (*SetOutput)(This,BYTE,SPIN*);
	 Virtual BYTE (*CheckLimit)(This);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual void (*InitSensor)(This,PVOID);
	 Virtual void (*RunAutomat)(This);
	 Virtual void (*EventGen)(This);
	 Virtual void (*EventHandler)(This,SMESSAGE*);
	 Virtual void (*Serialize)(This,BOOL byDir);
	 //Automat
	 void (*SetMsgAuto)(This,SMESSAGE*);
	 Virtual BOOL (*HandleTask)(This,TTask* pvTask);
     Virtual TStateList* (*GetStateList)(This);
Private
     UINT m_nInPin;
     UINT m_nOutPin;
	 CInputGate *m_nInp;
	 WORD m_wSnsMode;
	 BYTE m_byPidMode;
	 BOOL m_blSensorState;
	 BOOL m_blInState;
	 BOOL m_blProcState;
	 BOOL m_blOutState;
     PCLB m_pfnCallBackProc; 
     DWORD m_dwState;
	 BYTE m_byEvent;
	 SNSPARAMTABLE *m_pvPT;
     SNSPARAMTABLE m_sPT;
	 UINT m_nAcpOutRamp;
	 UINT m_nAcpMin;
	 UINT m_nAcpMax;
	 UINT m_nIniValue;
	 UINT m_iLoLimit; 
	 UINT m_iHiLimit; 
	 UINT m_iPLoLimit; 
	 UINT m_iPHiLimit; 
	 UINT m_iPHiOldLimit; 
	 UINT m_iLoAlmLimit; 
	 UINT m_iHiAlmLimit; 
	 UINT m_iIPLoLimit; 
	 UINT m_iIPHiLimit; 
	 BYTE m_bySystemID; 
	 BYTE m_bySensorID; 
     BYTE m_bySensorType; 
	 BYTE m_bySwitchCommand;
	 BYTE m_byDirection;
	 BYTE m_byParamType;
	 //Statistic
	 BOOL m_blStatState;
	 WORD m_wStatIndex;
	 BOOL m_blCaptureState;
	 WORD m_wStatQuant;
	 DINT m_pwStatBuff[20];
     //Out Gate
	 BYTE m_byAmOutGate;
     WORD m_wAmInput;
     WORD m_wAmOutput;
	 SOUTGATE m_sGT;
	 COutGate *m_pOutGate[DEV_AMT_GATE_SNS];
	 CPin **m_pINP;
     CPin **m_pOUT;
	 BOOL **m_bINP;
	 BOOL **m_bOUT;
	 UINT **m_nINP;
	 UINT **m_nOUT;
	 DWORD m_dwInState;
     DWORD m_dwOutState;
	 //Proc Alarm Gate Clock
	 BOOL m_blAlmLoLevel;
	 BOOL m_blRAlmLoLevel;
     BOOL m_blAlmHiLevel;
     BOOL m_blRAlmHiLevel;
	 BOOL m_blProcLoLevel;
     BOOL m_blProcHiLevel;
	 PVOID m_pvDirection;
	 //Automat 
     TStateList *m_pStateList;
	 CMTimer m_nATmr[4];
	 BYTE m_byAutoState;
	 BYTE V0,V1;
	 DWORD m_dwAutoTime;
	 DECLARE_IMPLEMENT_BASE(CAuto)
}
DECLARE_DEFINITION(CSensor)
#endif
#endif
