/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DEVTS_H__
#define __DEVTS_H__
#include "typedefs.h"
#include "bnrtelesensor.h"
#include "bnrpin.h"
#define DEF_SET_PULSE 5
#define DEF_REM_PULSE 5
/*
STSMPARAMS nTS = {16,TS,{
{29  ,0 ,TS ,7 ,8 , 0, EN_OPEN, PRI_HI, 5, 5, EN_AL_TO_AL, 1},
typedef struct _tagTSMParam
{
BYTE byID;
BYTE byAmParam; 
BYTE byType;
BYTE bySlot; 
BYTE byPin;
BYTE byAlmState;
BYTE byState;
BYTE byPriority;
BYTE byCRemPulce;
BYTE byCSetPulce;
BYTE byAlarmMode;
STSMDATA sDT;
}STSMPARAM; 
*/
Class CDevTS
{
	 void (*CCDevTS)(This);
	 void (*DCDevTS)(This);
Public
     BYTE (*CheckTS)(This);
     void (*Init)(This,CPin *pPN,BOOL *pblValue,BYTE byID,BYTE byIID,BYTE byState,BYTE byPriority,BYTE byCRemPulce,BYTE byCSetPulce,BYTE byAlarmMode);
	 void (*SetTS)(This,BYTE byBox,BYTE byFor,BYTE byEv);
     void (*PreProc)(This);
     void (*Processing)(This);
	 void (*PostProc)(This);
	 void (*SendEvent)(This,SKPEVENT *pEV);
	 BOOL (*SaveChange)(This,BYTE byEvent,WORD wValue,BOOL blAlarm);
	 void (*Run)(This);
Public
     STSMPARAM pP;
     BYTE m_byBox;
     BYTE m_byFor;
     BYTE m_byEv;   
     BYTE m_byID;
	 BYTE m_byPinID;
	 BYTE m_byOldEvent;
     
	 BOOL *m_pTIN;
	 BOOL m_blFSignal;
     BOOL m_blTmSetState; 
	 BOOL m_blTmRemState;   
     BYTE m_bySetPulce;
	 BYTE m_byRemPulce;
	 BYTE m_byType;
	 CPin *m_pPN;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CDevTS)
#endif
