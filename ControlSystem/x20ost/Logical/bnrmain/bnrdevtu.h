/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DEVTU_H__
#define __DEVTU_H__
#include "typedefs.h"
#include "bnrtelesensor.h"
/*
enum _enTUCommand
{
     EN_STT_PULCE=9,
	 EN_STT_SIGN =10,
};
*/
#define DEF_PULCE 20
/*
//Телеуправление1(дискретное)
typedef struct _tagTUMData
{
	BYTE byParam;
}STUMDATA;
typedef struct _tagTUMParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	BYTE byPulceType;
    BYTE byCSetPulce;
	STUMDATA sDT;
}STUMPARAM; 
*/
Class CDevTU
{
	 void (*CCDevTU)(This);
	 void (*DCDevTU)(This);
Public
     void (*Init)(This,BOOL *pblValue,BYTE byID,BYTE byIID,BYTE byState,BYTE byPulceType,DWORD byCSetPulce);
	 void (*SetTU)(This,BYTE byBox,BYTE byFor,BYTE byEv);
     void (*PreProc)(This);
     void (*Processing)(This);
	 void (*PostProc)(This);
	 void (*SendEvent)(This,SKPEVENT *pEV);
	 BOOL (*SaveChange)(This,BYTE byEvent,WORD wValue,BOOL blAlarm);
     void (*SetPulce)(This);
     void (*PreparePulce)(This);
     void (*SetPulceEx)(This,DWORD wPulce);
     void (*SetPin)(This);
     void (*InvPin)(This);
	 DWORD (*Run)(This);
	 void (*Stop)(This);
Public
	 STUMPARAM pP;
     BYTE m_byBox;
	 BYTE m_byFor;
	 BYTE m_byEv;   
	 BYTE m_byID;
	 BYTE m_byPinID;
     BYTE m_byOldEvent;
     DWORD m_bySetPulce;
	 DWORD m_dwJob;
	 BYTE m_byStPulce;
	 BYTE m_byType;
	 BOOL *m_pbOT;
	 DECLARE_IMPLEMENT
	 //DECLARE_IMPLEMENT_BASE(CTeleSensor)
}
DECLARE_DEFINITION(CDevTU)
#endif
