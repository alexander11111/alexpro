/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __SMARTSENSOR_H__
#define __SMARTSENSOR_H__
#include "typedefs.h"
#if MYSYSTEM_ID != 5
#include "bnrsensr.h"
#ifndef WIN32
//#include "loopconr.h"
#include "loopcont.h"
#endif
#ifdef WIN32
//fbk_mode
#define LCPID_FBK_MODE_INTERN       0
#define LCPID_FBK_MODE_EXTERN       1
#define LCPID_FBK_MODE_EXT_SELECTOR 2 
//d_mode
#define LCPID_D_MODE_X              0
#define LCPID_D_MODE_E              1
//calc_mode
#define LCPID_CALC_MODE_EXACT       0
#define LCPID_CALC_MODE_FAST        1

#define LCPID_OUT_MODE_AUTO            1
#define LCPID_OUT_MODE_CLOSE		   4 
#define LCPID_OUT_MODE_CLOSE_JOLTFREE  104 
#define LCPID_OUT_MODE_FREEZE          5 
#define LCPID_OUT_MODE_FREEZE_JOLTFREE 105 
#define LCPID_OUT_MODE_MAN             2 
#define LCPID_OUT_MODE_MAN_JOLTFREE    102 
#define LCPID_OUT_MODE_OFF             0 
#define LCPID_OUT_MODE_OPEN            3 
#define LCPID_OUT_MODE_OPEN_JOLTFREE   0

typedef struct _tagSnsParam
{
	 BOOL enable;
     BOOL enter;
     INT16 Y_max;
     INT16 Y_min;
	 REAL dY_max;
     REAL Kp;
	 REAL Tn;
     REAL Tv;
	 REAL Tf;
	 REAL Kw;
     REAL Kfbk;
	 USINT fbk_mode;
     USINT d_mode;
     USINT calc_mode;
     UINT status;
     UDINT *ident;
}LCPIDpara_typ;
typedef struct _tagLcPid
{
	 BOOL enable;
	 UDINT *ident;
	 INT16 W;
	 INT16 X;
	 INT16 A;
	 INT16 Y_man;
	 INT16 Y_fbk;
	 BOOL hold_I;
	 USINT out_mode;
	 UDINT basetime;
	 UINT status;
	 DINT e;
	 INT16 Y;
	 DINT Yp;
	 DINT Yi;
	 DINT Yd;
	 UDINT time_old;
	 DINT Tv_Tf_old;
	 BOOL enable_old;
	 DINT e_old;
}LCPID_typ;
typedef struct _tagCounter
{
	 UDINT muscnt;
	 UDINT mus100cnt;
	 UDINT mscnt;
	 UDINT ms100cnt;
	 UDINT seccnt;
}LCCounter_typ;
typedef struct _tagLcRprt2
{ 
	 BOOL enable;
	 REAL V;
	 REAL T1;
	 REAL T2;
	 REAL x;
	 REAL y_set;
	 USINT set;
	 REAL y;
	 UINT status;
}LCRPT2_typ;
void LCPIDpara(LCPIDpara_typ *pPara);
void LCPID(LCPID_typ *pPid);
void LCCounter(LCCounter_typ *pCounder);
void LCRPT2(LCRPT2_typ *pLowPas);
#endif
typedef struct _tagPidParam
{
    REAL  Kp;
    REAL  Tn; 	
    REAL  Tv; 	
    REAL  Tf; 	
    REAL  Kw; 	
    REAL  Kfbk; //24	
    REAL  dY_max;
    INT16 Y_max; 
    INT16 Y_min;
    INT16 W;
    INT16 X;
    INT16 A;
    INT16 Y_man; //14
	BYTE  enable;
	BYTE  out_mode;
	BYTE  enabled; //3 41
}SPIDPARAM;    
Class CSmartSensor
{
	 void (*CCSmartSensor)(This);
	 void (*DCSmartSensor)(This);
	 void (*SetMode)(This,USINT);
	 void (*SetState)(This,BOOL);
	 BOOL (*GetState)(This);
Public
     Virtual void (*InitSensor)(This,PVOID pParam);
     Virtual void (*PreProc)(This);
     Virtual void (*Processing)(This);
     Virtual void (*PostProc)(This);
	 Virtual void (*GetParam)(This,BYTE byOwner);
	 Virtual void (*IncInput)(This,INT16);
	 Virtual void (*SetInput)(This,SPIN*);
	 Virtual void (*SetOutput)(This,BYTE,SPIN*);
	 Virtual void (*EventHandler)(This,SMESSAGE*);
	 Virtual void (*CaptureData)(This);
	 Virtual void (*RunAutomat)(This);
	 Virtual void (*EventGen)(This);
	 Virtual void (*Serialize)(This,BOOL byDir);
	 DWORD (*MotToInt)(This,DWORD dwData);
Private
	 UINT m_wExtError;
     USINT m_byMode;
     BOOL m_blState;
	 INT16 m_iInpV;
     LCPIDpara_typ m_sSNSParam;
     LCPID_typ m_sLCPid;
	 LCCounter_typ m_sCounter;
	 DECLARE_IMPLEMENT_BASE(CSensor)
}
DECLARE_DEFINITION(CSmartSensor)
#endif
#endif
