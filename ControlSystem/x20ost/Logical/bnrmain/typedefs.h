/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: typedefs.h
 * Author: Alex
 * Created: January 22, 2009
 *******************************************************************/
#ifndef __TYPED_H__
#define __TYPED_H__
#include "bnrconst.h"
#include "bnrdbout.h"
//Start Automat
enum _tagTIEvent
{
	EV_SET_HI=0,
	EV_REM_HI,
	EV_SET_LO,
	EV_REM_LO,
	EV_CHG_PR,
	EV_0T1_CH,
	EV_1T0_CH,
	EV_SAL_CH,
	EV_RAL_CH,
	EV_0T1_ST,
	EV_1T0_ST,
	EV_INI_CH,
	EV_ALP_CH,
	EV_ALS_CH,
	EV_CHK_CH,
};
enum _enTSParam
{
	EN_SET_PERIOD,
	EN_REM_PERIOD,
	EN_PIN_ALMODE,
};

enum _enCmdTypeParam
{
	CTR_TU,
	CTR_TR,
	CTR_OPEN,
	CTR_CLOSE,
	CTR_STOP,
};

#define S_BAD 0xFF
#define EXIT_D 0xFF
#define MSGIR_REQ              0x80
#define MC_UNKNOWN             0x7F  
#define EV_UNKNOWN_REQ         (MC_UNKNOWN|MSGIR_REQ)
#define MAXNBVALUE             100
typedef unsigned char  TStateCode;
typedef unsigned char  TTask;
typedef unsigned char  TEvent;
typedef struct _tagTState
{
    TEvent m_vEvent;
    TTask* m_pvTask;
}TState;
typedef struct _tagTStateList
{
    TStateCode m_vStateCode;
    TState*    m_pvState;
}TStateList;
#define DECLARE_TASKCHAIN(Name) TTask          Name[]=
#define IMPORT_TASKCHAIN(Name)  extern TTask   Name[]
#define DECLARE_STATE(Name)     TState         Name[]=
#define IMPORT_STATE(Name)      extern TState  Name[]
#define DECLARE_STATELIST(Name) TStateList   Name[]=
#define IMPORT_STATELIST(Name)  extern TStateList  Name[]
//End Automat
#ifndef WIN32
 typedef UINT WORD;
 typedef UDINT DWORD;
 typedef UINT USHORT;
 typedef USINT BYTE;
 typedef void* PVOID;
 typedef BYTE* MESSAGE;
  typedef INT INT16;
#else
 #include <stdio.h>   
 #include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>
 #define MEM_alloc(X,Y) Y = malloc(X);
 #define MEM_free(X,Y)  free(Y);
 typedef unsigned char USINT;
 //typedef WORD UINT;
 typedef char SINT;
 typedef _int16 INT16;
 //typedef unsigned int WORD;

 typedef float REAL; 
 typedef INT DINT;
 typedef unsigned long UDINT;
 typedef unsigned long DWORD;
 typedef unsigned char BYTE;
 typedef void* PVOID;
 typedef BYTE* MESSAGE;
 #define _GLOBAL
 #define _INIT
 #define _CYCLIC
 #define _EXIT
#endif
typedef BOOL (*PCLB)(PVOID,BYTE);
#define This PVOID pV
_GLOBAL void **pGlobalMemoryPointer;
_GLOBAL DWORD dwFL;
void CrateProcess(PVOID,SINT*,BYTE,BYTE);
#define FCREATE(X0,X1,X2,X3) CrateProcess(X0,X1,X2,X3);
void CrateTimer(PVOID);
void DeleteTimer(PVOID);
#define FCTIMER(X0) CrateTimer(X0);
#define FDTIMER(X0) DeleteTimer(X0);
void NEW(int nSize,void **pVoid);
void FREE(int nSize,void **pVoid);
#define New(X,Y) NEW(X,(void**)&Y)
#define Delete(X,Y) FREE(X,(void**)Y)
#define Public
#define Private
#define Protected
#define Virtual
#define Class typedef struct 

#define DIP12_AVL(X) _GLOBAL BOOL  *blpValueDI##X##[DEV_MAX_DI_X20DM9371_PIN];
#define DIP2_AVL(X)  _GLOBAL UINT  *uipValueDI##X##[DEV_MAX_DI_X20DI2377_PIN];
#define DIP_AVL(X)   _GLOBAL BOOL  *blpValueDI##X##[DEV_MAX_DI_3DI477_PIN];
#define DOP_AVL(X)   _GLOBAL BOOL  *blpValueDO##X##[DEV_MAX_DO_3DO760_PIN];
#define DOP12_AVL(X) _GLOBAL BOOL  *blpValueDO##X##[DEV_MAX_DO_X20DM9322_PIN];
#define AIP4_AVL(X)  _GLOBAL UINT  *uipValueAI##X##[DEV_MAX_AI_X20AI4622_PIN];
#define AIP2_AVL(X)  _GLOBAL UINT  *uipValueAI##X##[DEV_MAX_AI_X20AI2622_PIN];
#define AIP_AVL(X)   _GLOBAL UINT  *uipValueAI##X##[DEV_MAX_AI_3AI375_PIN];
#define AOP_AVL(X)   _GLOBAL UINT  *uipValueAO##X##[DEV_MAX_AO_3AO775_PIN];
#define AOP4_AVL(X)  _GLOBAL UINT  *uipValueAO##X##[4];

#define DIP12_ALVL(X) _GLOBAL BOOL  *blpAlValueDI##X##[DEV_MAX_DI_X20DM9371_PIN];
#define DIP2_ALVL(X)  _GLOBAL BOOL  *blpAlValueDI##X##[DEV_MAX_DI_X20DI2377_PIN];
#define DOP12_ALVL(X) _GLOBAL BOOL  *blpAlValueDO##X##[DEV_MAX_DO_X20DM9322_PIN];
#define AIP4_ALVL(X)  _GLOBAL BOOL  *blpAlValueAI##X##[DEV_MAX_AI_X20AI4622_PIN];
#define AIP2_ALVL(X)  _GLOBAL BOOL  *blpAlValueAI##X##[DEV_MAX_AI_X20AI2622_PIN];
#define AOP4_ALVL(X)  _GLOBAL BOOL  *blpAlValueAO##X##[DEV_MAX_AO_X20AO4622_PIN];

#define DI_VL(X,Y)   _GLOBAL BOOL  blValueDI##X##_##Y##;
#define DIC_VL(X,Y)  _GLOBAL BOOL  uiValueDI##X##_##Y##;
#define DO_VL(X,Y)   _GLOBAL BOOL  blValueDO##X##_##Y##;
#define AI_VL(X,Y)   _GLOBAL INT16 uiValueAI##X##_##Y##;
#define AO_VL(X,Y)   _GLOBAL INT16 uiValueAO##X##_##Y##;

#define DI_ALVL(X,Y) _GLOBAL BOOL  blAlValueDI##X##_##Y##;
#define DO_ALVL(X,Y) _GLOBAL BOOL  blAlValueDO##X##_##Y##;
#define AI_ALVL(X,Y) _GLOBAL BOOL  blAlValueAI##X##_##Y##;
#define AO_ALVL(X,Y) _GLOBAL BOOL  blAlValueAO##X##_##Y##;

#define AI_ASVL(X)   _GLOBAL BOOL  blAsValueAI##X##;
#define AO_ASVL(X)   _GLOBAL BOOL  blAsValueAO##X##;
#define DI_ASVL(X)   _GLOBAL BOOL  blAsValueDI##X##;
#define DO_ASVL(X)   _GLOBAL BOOL  blAsValueDO##X##;


#define DI_SL(X) \
DI_VL(X,0)  DI_VL(X,1)  DI_VL(X,2)  DI_VL(X,3)  DI_VL(X,4)  DI_VL(X,5)  DI_VL(X,6)  DI_VL(X,7) \
DI_VL(X,8)  DI_VL(X,9)  DI_VL(X,10) DI_VL(X,11) DI_VL(X,12) DI_VL(X,13) DI_VL(X,14) DI_VL(X,15) \
DI_VL(X,16) DI_VL(X,17) DI_VL(X,18) DI_VL(X,19) DI_VL(X,20) DI_VL(X,21) DI_VL(X,22) DI_VL(X,23) \
DI_VL(X,24) DI_VL(X,25) DI_VL(X,26) DI_VL(X,27) DI_VL(X,28) DI_VL(X,29) DI_VL(X,30) DI_VL(X,31) 
#define DI8_SL(X) DI_VL(X,0) DI_VL(X,1) DI_VL(X,2) DI_VL(X,3) DI_VL(X,4) DI_VL(X,5) DI_VL(X,6) DI_VL(X,7) 
#define DO_SL(X)  DO_VL(X,0) DO_VL(X,1) DO_VL(X,2) DO_VL(X,3) DO_VL(X,4) DO_VL(X,5) DO_VL(X,6) DO_VL(X,7)

#define DI12_SL(X) DI_VL(X,0) DI_VL(X,1) DI_VL(X,2) DI_VL(X,3) DI_VL(X,4) DI_VL(X,5) DI_VL(X,6) DI_VL(X,7) DI_VL(X,8) DI_VL(X,9) DI_VL(X,10) DI_VL(X,11) 
#define DIC2_SL(X) DIC_VL(X,0) DIC_VL(X,1) 
#define DI12_ALSL(X) DI_ALVL(X,0) DI_ALVL(X,1) DI_ALVL(X,2) DI_ALVL(X,3) DI_ALVL(X,4) DI_ALVL(X,5) DI_ALVL(X,6) DI_ALVL(X,7) DI_ALVL(X,8) DI_ALVL(X,9) DI_ALVL(X,10) DI_ALVL(X,11) 
#define DI2_ALSL(X) DI_ALVL(X,0) DI_ALVL(X,1) 

#define DO12_SL(X)  DO_VL(X,0) DO_VL(X,1) DO_VL(X,2) DO_VL(X,3) DO_VL(X,4) DO_VL(X,5) DO_VL(X,6) DO_VL(X,7) DO_VL(X,8) DO_VL(X,9) DO_VL(X,10) DO_VL(X,11)
#define DO12_ALSL(X) DO_ALVL(X,0) DO_ALVL(X,1) DO_ALVL(X,2) DO_ALVL(X,3) DO_ALVL(X,4) DO_ALVL(X,5)  DO_ALVL(X,6) DO_ALVL(X,7) DO_ALVL(X,8) DO_ALVL(X,9) DO_ALVL(X,10) DO_ALVL(X,11)

#define AI_SL(X)  AI_VL(X,0) AI_VL(X,1) AI_VL(X,2) AI_VL(X,3) AI_VL(X,4) AI_VL(X,5) AI_VL(X,6) AI_VL(X,7)

#define AI2_SL(X) AI_VL(X,0) AI_VL(X,1) 
#define AI4_SL(X) AI_VL(X,0) AI_VL(X,1) AI_VL(X,2) AI_VL(X,3)
#define AO4_SL(X) AO_VL(X,0) AO_VL(X,1) AO_VL(X,2) AO_VL(X,3)
#define AI4_ALSL(X) AI_ALVL(X,0) AI_ALVL(X,1) AI_ALVL(X,2) AI_ALVL(X,3)
#define AI2_ALSL(X) AI_ALVL(X,0) AI_ALVL(X,1) 

#define AO4_ALSL(X) AO_ALVL(X,0) AO_ALVL(X,1) AO_ALVL(X,2) AO_ALVL(X,3)

#define AO_SL(X)  AO_VL(X,0) AO_VL(X,1) AO_VL(X,2) AO_VL(X,3) AO_VL(X,4) AO_VL(X,5) AO_VL(X,6) AO_VL(X,7)

//Connection
#define DI_CON(X,Y)  blpValueDI##X##[##Y##]   = &blValueDI##X##_##Y##;
#define DIC_CON(X,Y) uipValueDI##X##[##Y##]   = &uiValueDI##X##_##Y##;
#define DO_CON(X,Y)  blpValueDO##X##[##Y##]   = &blValueDO##X##_##Y##;
#define AI_CON(X,Y)  uipValueAI##X##[##Y##]   = &uiValueAI##X##_##Y##;
#define AO_CON(X,Y)  uipValueAO##X##[##Y##]   = &uiValueAO##X##_##Y##;

#define DI_ACN(X,Y)  blpAlValueDI##X##[##Y##] = &blAlValueDI##X##_##Y##;
#define DO_ACN(X,Y)  blpAlValueDO##X##[##Y##] = &blAlValueDO##X##_##Y##;
#define AI_ACN(X,Y)  blpAlValueAI##X##[##Y##] = &blAlValueAI##X##_##Y##;
#define AO_ACN(X,Y)  blpAlValueAO##X##[##Y##] = &blAlValueAO##X##_##Y##;

#define DI_CSL(X) \
DI_CON(X,0)  DI_CON(X,1)  DI_CON(X,2)  DI_CON(X,3)  DI_CON(X,4)  DI_CON(X,5)  DI_CON(X,6)  DI_CON(X,7) \
DI_CON(X,8)  DI_CON(X,9)  DI_CON(X,10) DI_CON(X,11) DI_CON(X,12) DI_CON(X,13) DI_CON(X,14) DI_CON(X,15) \
DI_CON(X,16) DI_CON(X,17) DI_CON(X,18) DI_CON(X,19) DI_CON(X,20) DI_CON(X,21) DI_CON(X,22) DI_CON(X,23) \
DI_CON(X,24) DI_CON(X,25) DI_CON(X,26) DI_CON(X,27) DI_CON(X,28) DI_CON(X,29) DI_CON(X,30) DI_CON(X,31) 

#define DI12_CSL(X) DI_CON(X,0) DI_CON(X,1) DI_CON(X,2) DI_CON(X,3) DI_CON(X,4) DI_CON(X,5) DI_CON(X,6) DI_CON(X,7) DI_CON(X,8) DI_CON(X,9) DI_CON(X,10) DI_CON(X,11)
#define DIC2_CSL(X) DIC_CON(X,0) DIC_CON(X,1) 
#define DO_CSL(X)   DO_CON(X,0) DO_CON(X,1) DO_CON(X,2) DO_CON(X,3) DO_CON(X,4) DO_CON(X,5) DO_CON(X,6) DO_CON(X,7)
#define DO12_CSL(X) DO_CON(X,0) DO_CON(X,1) DO_CON(X,2) DO_CON(X,3) DO_CON(X,4) DO_CON(X,5) DO_CON(X,6) DO_CON(X,7) DO_CON(X,8) DO_CON(X,9) DO_CON(X,10) DO_CON(X,11)
#define AI_CSL(X)   AI_CON(X,0) AI_CON(X,1) AI_CON(X,2) AI_CON(X,3) AI_CON(X,4) AI_CON(X,5) AI_CON(X,6) AI_CON(X,7)
#define AI4_CSL(X)  AI_CON(X,0) AI_CON(X,1) AI_CON(X,2) AI_CON(X,3) 
#define AO4_CSL(X)  AO_CON(X,0) AO_CON(X,1) AO_CON(X,2) AO_CON(X,3) 
#define AI2_CSL(X)  AI_CON(X,0) AI_CON(X,1) 

#define DI12_ALCSL(X) DI_ACN(X,0) DI_ACN(X,1) DI_ACN(X,2) DI_ACN(X,3) DI_ACN(X,4) DI_ACN(X,5) DI_ACN(X,6) DI_ACN(X,7) DI_ACN(X,8) DI_ACN(X,9) DI_ACN(X,10) DI_ACN(X,11)
#define DI2_ALCSL(X)  DI_ACN(X,0) DI_ACN(X,1) 

#define DO12_ALCSL(X) DO_ACN(X,0) DO_ACN(X,1) DO_ACN(X,2) DO_ACN(X,3) DO_ACN(X,4) DO_ACN(X,5) DO_ACN(X,6) DO_ACN(X,7) DO_ACN(X,8) DO_ACN(X,9) DO_ACN(X,10) DO_ACN(X,11)
#define AI4_ALCSL(X ) AI_ACN(X,0) AI_ACN(X,1) AI_ACN(X,2) AI_ACN(X,3) 
#define AI2_ALCSL(X ) AI_ACN(X,0) AI_ACN(X,1) 
#define AO4_ALCSL(X ) AO_ACN(X,0) AO_ACN(X,1) AO_ACN(X,2) AO_ACN(X,3) 

#define AO_CSL(X)  AO_CON(X,0) AO_CON(X,1) AO_CON(X,2) AO_CON(X,3) AO_CON(X,4) AO_CON(X,5) AO_CON(X,6) AO_CON(X,7)
#define DI_INI12(X,Y) for(i=0;i<11;i++) *blpValueDI##X##[i] = Y;
#define DIC_INI2(X,Y) for(i=0;i<2;i++) *uipValueDI##X##[i] = Y;

#define AI_ALIN4(X,Y)  for(i=0;i<4;i++)  *blpAlValueAI##X##[i] = Y;
#define AO_ALOT4(X,Y)  for(i=0;i<4;i++)  *blpAlValueAO##X##[i] = Y;
#define AI_ALIN2(X,Y)  for(i=0;i<2;i++)  *blpAlValueAI##X##[i] = Y;
#define DI_ALIN12(X,Y) for(i=0;i<11;i++) *blpAlValueDI##X##[i] = Y;
#define DI_ALIN2(X,Y) for(i=0;i<2;i++) *blpAlValueDI##X##[i] = Y;
#define DO_ALIN12(X,Y) for(i=0;i<11;i++) *blpAlValueDO##X##[i] = Y;


#define DI_INI(X,Y) for(i=0;i<20;i++) *blpValueDI##X##[i] = Y;
#define DI8_INI(X,Y)for(i=0;i<7;i++) *blpValueDI##X##[i] = Y;
#define DECLARE_DEFINITION(X)X; void X##_CreateClass(##X *pM);void X##_DestroyClass(##X *pM);
#define DECLARE_IMPLEMENT_BASE(X)  \
	X m_n##X; \
	X *pBase; \
	PVOID pThis; \
	PVOID pChld; 
#define DECLARE_IMPLEMENT  \
	PVOID pBase; \
	PVOID pThis; \
	PVOID pChld; 
#define DECLARE_SINGLE_CREATE(X) \
	void X##_CreateClass(##X *pM)\
	{ \
    pM->pBase = NULL; \
	pM->pThis = pM; \
	pM->pChld = pM; \
	pM->C##X = X##_##X; \
    pM->D##X = X##_D##X; \
	pM->C##X(pM); \
	}; \
	void X##_DestroyClass(##X *pM) \
	{	\
     X##_D##X##(pM); \
	};
#define DECLARE_MULTI_CREATE(X,Y) \
	void X##_CreateClass(##X *pM)\
	{ \
	pM->pBase = &pM->m_n##Y; \
	pM->pThis = pM; \
	pM->pChld = NULL; \
	InitObject(Y,&pM->m_n##Y) \
	pM->m_n##Y##.pChld = pM; \
	pM->C##X = X##_##X; \
	pM->D##X = X##_D##X; \
	pM->C##X(pM); \
	}; \
	void X##_DestroyClass(##X *pM) \
	{ \
	 X##_D##X##(pM); \
	}; 
#define DECLARE_SINGLE_OPEN(X) \
	X *pT = pV; \
	X *pC = pT->pChld;  
#define DECLARE_MULTI_OPEN(X,Y) \
	X *pT = pV; \
	Y *pB = pT->pBase; \
    PVOID *pC = pT->pChld;   
#define DECLARE_REGISTRATION(X,Y) pT->Y = X##_##Y;
#define DECLARE_VIRTUAL_FUNC(X,Y) pT->Y = X##_##Y; pB->Y = pT->Y;
#define DECLARE_VIRTUAL1_FUNC(X,Y) pT->Y = X##_##Y; pB->pBase->Y = pT->Y;
#define InitObject(X,Y) X##_CreateClass(Y); 
#define DeleteObject(X) if(X!=0)Delete(sizeof(*X),X);X=0;
#define DestroyObject(X,Y) if(Y!=NULL){X##_DestroyClass(Y);Delete(sizeof(*((X*)Y)),Y);}
#define DestroyObjectB(X,Y) if(Y!=NULL){X##_DestroyClass(Y);}
#define DESTROY Delete(sizeof(*pT),pT);
#endif




