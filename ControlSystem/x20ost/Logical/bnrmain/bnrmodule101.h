/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MODULE101_H__
#define __MODULE101_H__
#include "typedefs.h"
#include "bnrcyclicsystem.h"
#include "bnrregedit.h"
Class CModule101
{
	 void (*CCModule101)(This);
	 void (*DCModule101)(This);
Public
     void (*Init)(This);
     BOOL (*LoLevelHandler)(This,SMESSAGE *pMsg);
     BOOL (*HiLevelHandler)(This,SMESSAGE *pMsg);
	 BOOL (*SendMessage)(This,BYTE,BYTE);
	 BYTE (*CreateCRC)(This,BYTE *pMsg,BYTE byLen);
	 BYTE (*AddADSU)(This,BYTE *pMsg,BYTE byNum);
	 BYTE (*AddADSU1)(This,BYTE *pMsg,BYTE byNum);
	 BYTE (*PackADSU)(This,BYTE *pMsg);
	 WORD (*GetW)(This,BYTE *pbyParam);
	 BOOL (*GetSettings)(This);
	 BOOL (*SetSettings)(This);
	 void (*CopyW)(This,PVOID pvDst,PVOID pvSrc);
	 BOOL (*SendBroadcast)(This,SMESSAGE *pMsg);
	 BYTE (*AddBroadADSU)(This,BYTE *pMsg,SKPEVENT *pEV);
	 BOOL (*Autorisation)(This,WORD wKeyCode,BYTE byKpID);
     Virtual BOOL (*HandleTask)(This,TTask* pvTask);
     Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
	 Virtual TStateList* (*GetStateList)(This);
     //Virtual void (*CyclicProc)(This); 
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
Private
     CRegModule m_nRM;
     BYTE m_byModuleID;
	 BOOL m_blRepFree;
	 //STISTAG  m_sTiTsMsg;
	 SREGADDR m_pA;
	 SREGPARAM m_nRD;
	 SMESSAGE *m_pOutMsg;
	 SMESSAGE m_sOutMsg;
	 SMESSAGE m_sSvOutMsg;
}
DECLARE_DEFINITION(CModule101)
#define TIMER_SRR_00 10

/*
typedef struct   {
BYTE bt0; // à¥§¥à¢ ¢ ­ ç «¥
BYTE bt1; //
BYTE Len;
unsigned nGlUnit:6; //ÉÍÍÍÍ»
unsigned nLocUnit:5;//º    º
unsigned nP1:4;      //º ID º
unsigned bit1:1;
unsigned nP2:11;
unsigned nP3:5;
BYTE Data[0x100-7];
} MSG_FPO1;
*/
typedef struct _tagAdsuHead
{
    BYTE Type;
    BYTE VSQ;
    BYTE Cause;
    //BYTE Ordinator;
    BYTE CAA00;
    BYTE CAA01;
}SADSUHEAD;
typedef struct _tagIEA
{
    BYTE IOA00;
    BYTE IOA01;
    BYTE IOA02;
}SIEA;
typedef struct _tagSIQ
{
	BYTE SPI:1;  
	BYTE RES:3;  
	BYTE BL:1;  
	BYTE SB:1;  
	BYTE NT:1;  
	BYTE IV:1;  
}SIQ;
typedef struct _tagTime24
{
    BYTE MSecL;
	BYTE MSecH;
	BYTE Min:6;
	BYTE Res:1;
	BYTE IV:1;
}STIME24;
typedef struct _tagNVA
{
    BYTE byNvaL;
	BYTE byNvaH;
}NVA;
typedef struct _tagFDCO
{
    BYTE IOA00;
    BYTE IOA01;
    BYTE IOA02;
	BYTE DCS:4;  
	BYTE BL:1;  
	BYTE SB:1;  
	BYTE NT:1;  
	BYTE IV:1;
    BYTE MSecL;
	BYTE MSecH;
	BYTE Min:6;
	BYTE Rest:1;
	BYTE IVt:1;	
}FDCO;


typedef struct _tagFTIME
{
    BYTE IOA00;
    BYTE IOA01;
    BYTE IOA02;
	BYTE MSecL;
	BYTE MSecH;
	//BYTE IV:1;	
	//BYTE Res1:1;
	BYTE Min;
	
	//BYTE SU:1;
	//BYTE Res2:2;
	BYTE Hour;	
	
	//BYTE DayN:3;
	BYTE DayM;
	
	//BYTE Res3:4;
	BYTE Month;
	
	//BYTE Res4:1;
	BYTE Year;
}FTIME;


typedef struct _tagFSIQ
{
    BYTE IOA00;
    BYTE IOA01;
    BYTE IOA02;
	
	BYTE SPI:1;  
	BYTE RES:3;  
	BYTE BL:1;  
	BYTE SB:1;  
	BYTE NT:1;  
	BYTE IV:1;
    BYTE MSecL;
	BYTE MSecH;
	BYTE Min:6;
	BYTE Rest:1;
	BYTE IVt:1;	
}FSIQ;
typedef struct _tagFNVA
{
    BYTE IOA00;
    BYTE IOA01;
    BYTE IOA02;
    BYTE byNvaL;
	BYTE byNvaH;
	BYTE OV:1;  
	BYTE RES:3;  
	BYTE BL:1;  
	BYTE SB:1;  
	BYTE NT:1;  
	BYTE IV:1;
}FNVA;
typedef struct _tagFTNVA
{
    BYTE IOA00;
    BYTE IOA01;
    BYTE IOA02;
    BYTE byNvaL;
	BYTE byNvaH;

	BYTE byQDS;
    /*#ifdef WIN32
    BYTE MSecL;
	BYTE MSecH;
	BYTE Min:6;
	BYTE Res1:1;
	BYTE IV:1;	
	BYTE Hour:5;	
	BYTE Res2:2;
	BYTE SU:1;
	BYTE DayM:5;
	BYTE DayN:3;
	BYTE Month:4;
	BYTE Res3:4;
	BYTE Year:7;
	BYTE Res4:1;
	#else
	*/
    BYTE MSecL;
	BYTE MSecH;
	BYTE Min;
	BYTE Hour;	
	BYTE DayM;
	BYTE Month;
	BYTE Year;
	
	/*
	BYTE IV:1;	
	BYTE Res1:1;
	BYTE Min:6;
	
	BYTE SU:1;
	BYTE Res2:2;
	BYTE Hour:5;	
	
	BYTE DayN:3;
	BYTE DayM:5;
	
	BYTE Res3:4;
	BYTE Month:4;
	
	BYTE Res4:1;
	BYTE Year:7;
	*/
	//#endif
}FTNVA;
enum _tagAuto101Value
{
	 FCB=0,
	 FCV,
	 ACD,
	 DFC,
	 MFCB,
	 MFCV,
     CACK,
	 MCMD,
	 ISERROR,
	 ISCHNG,
	 ISCHNGTI,
	 ONE,
	 ZERO,
	 VAL0,
	 STATE_101,
	 STATE_WSY,
};
enum
{
	TMR_SRR=0,
	TMR_SSC,
};
#endif
