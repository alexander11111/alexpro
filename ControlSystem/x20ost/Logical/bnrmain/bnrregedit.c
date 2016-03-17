/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrregedit.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
extern SSOFTSWITCHTABLE nSoftSwitchTable;
extern SHARDCOMPUTERTABLE nConfigTable;
void CRegModule_Init(This)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	SREGADDR nA;
	nA.byA0 = 0;
	nA.byA1 = 0;
	nA.byA2 = 0;
	FDEFINE(BOX_REG,BOX_REG_SZ);
	pT->m_pSCT = &nSoftSwitchTable;
    pT->m_pHCT = &nConfigTable;
	//pT->CreateKpParam(pT,&nA);
	//pT->CreatePortParam(pT,&nA);
	//pT->CreateHardParam(pT,&nA);
	//pT->CreateSoftParam(pT,&nA);
	//pT->SetKpParam(pT,&nA);
}

BYTE CRegModule_QueryParam(This,SREGADDR *pA)
{   
    DECLARE_SINGLE_OPEN(CRegModule) 	 
	switch(pA->byA0)
	{
	  case REG_KPPAR_ADDR:
		   return pT->CreateKpParam(pT,pA);
	  case REG_PORTT_ADDR:
		   return pT->CreatePortParam(pT,pA);
	  case REG_HARDT_ADDR:
		   return pT->CreateHardParam(pT,pA);
	  case REG_SOFTI_ADDR:
		   return pT->CreateSoftTIParam(pT,pA);
	  case REG_SOFTS_ADDR:
		   return pT->CreateSoftTSParam(pT,pA);
	  case REG_SOFTU_ADDR:
		   return pT->CreateSoftTUParam(pT,pA);
	  case REG_SOFTR_ADDR:
		   return pT->CreateSoftTRParam(pT,pA);
	}
	return 0;
}
BYTE CRegModule_SaveParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	switch(pA->byA0)
	{
	  case REG_KPPAR_ADDR:
		   return pT->SetKpParam(pT,pA);
	  case REG_PORTT_ADDR:
		   return pT->SetPortParam(pT,pA);
	  case REG_HARDT_ADDR:
		   return pT->SetHardParam(pT,pA);
	  case REG_SOFTI_ADDR:
		   return pT->SetSoftTIParam(pT,pA);
	  case REG_SOFTS_ADDR:
		   return pT->SetSoftTSParam(pT,pA);
	  case REG_SOFTU_ADDR:
		   return pT->SetSoftTUParam(pT,pA);
	  case REG_SOFTR_ADDR:
		   return pT->SetSoftTRParam(pT,pA);
	  default:
	  return 0;
	}
}
BYTE CRegModule_CreateKpParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	BYTE i;
	SREGPARAM sP;
	BYTE *pM = (BYTE*)&sP;
	SKPPARAM *pH = pT->m_pHCT->pKpParam;
	FFREE(BOX_REG);
    sP.wSize  = sizeof(SREGPARAM);
	sP.byA0   = pA->byA0;
	sP.byA1   = pA->byA1;
	//if(sP.byA1==0xff)
    if(pA->byA1==0){sP.byA2 = 0;for(i=0;i<8;i++){pT->CopyW(pT,&sP.wParam,&pH->byPassword[i*2]);FPUT(BOX_REG,pM);sP.byA2++;}sP.byA1++;} //5 KP Password
    if(pA->byA1==1){sP.byA2 = 0;for(i=0;i<8;i++){pT->CopyW(pT,&sP.wParam,&pH->byPhone0[i*2]);  FPUT(BOX_REG,pM);sP.byA2++;}sP.byA1++;} //6 Kp Phone 0
	if(pA->byA1==2){sP.byA2 = 0;for(i=0;i<8;i++){pT->CopyW(pT,&sP.wParam,&pH->byPhone1[i*2]);  FPUT(BOX_REG,pM);sP.byA2++;}sP.byA1++;} //7 Kp Phone 1 
    if(pA->byA1==3){sP.byA2 = 0;for(i=0;i<8;i++){pT->CopyW(pT,&sP.wParam,&pH->byPhone2[i*2] ); FPUT(BOX_REG,pM);sP.byA2++;}sP.byA1++;} //8 Kp Phone 2

	if(pA->byA1==4){sP.byA2 = 0;sP.wParam = (WORD)pH->byKpID;      FPUT(BOX_REG,pM);sP.byA1++;}//0 Kp ID
	if(pA->byA1==5){sP.byA2 = 0;sP.wParam = (WORD)pH->byStoreMode; FPUT(BOX_REG,pM);sP.byA1++;}//1 Buffer Mode 
	if(pA->byA1==6){sP.byA2 = 0;sP.wParam = (WORD)pH->byAmCall;    FPUT(BOX_REG,pM);sP.byA1++;}//2 Amout Call 
	if(pA->byA1==7){sP.byA2 = 0;sP.wParam = (WORD)pH->byCallPeriod;FPUT(BOX_REG,pM);sP.byA1++;}//3 Call Period
	//if(pA->byA1==8){sP.byA2 = 0;sP.wParam = (WORD)pH->bySetChann;  FPUT(BOX_REG,pM);sP.byA1++;}//4 Call Period
    return FCHECK(BOX_REG);
}
BYTE CRegModule_CreatePortParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	SREGPARAM sP;
	BYTE *pM = (BYTE*)&sP;
	SHARDCOMPUTERTABLE *pH = pT->m_pHCT;

	SARMINTERFACE *pR;
	BYTE byID = pA->byA1;
    sP.wSize  = sizeof(SREGPARAM);
	sP.byA0   = pA->byA0;
	sP.byA1   = pA->byA1;
	sP.byA2   = 0;
	if(byID<pH->byArmAmout)
	{
	 FFREE(BOX_REG);
	 pR = pH->pArmInterface[byID];
     sP.wParam = (WORD)pR->byNumber;         FPUT(BOX_REG,pM);sP.byA2++;  //0 Port Number
     sP.wParam = (WORD)pR->byType;           FPUT(BOX_REG,pM);sP.byA2++;  //1 Port Type
     sP.wParam = (WORD)pR->byPortRate;       FPUT(BOX_REG,pM);sP.byA2++;  //2 Port Type
     sP.wParam = (WORD)pR->stTcpAddr.byAddr0;FPUT(BOX_REG,pM);sP.byA2++;  //3 Parity
     sP.wParam = (WORD)pR->stTcpAddr.byAddr1;FPUT(BOX_REG,pM);sP.byA2++;  //4 Data Bits
     sP.wParam = (WORD)pR->stTcpAddr.byAddr2;FPUT(BOX_REG,pM);sP.byA2++;  //5 Stop Bits
	 return FCHECK(BOX_REG);
	}
	return 0;
}
BYTE CRegModule_CreateHardParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	SREGPARAM sP;
	BYTE *pM = (BYTE*)&sP;
	SHARDCOMPUTERTABLE *pH = pT->m_pHCT;
	SHARDSLOT *pR;
	BYTE byID = pA->byA1;
    sP.wSize  = sizeof(SREGPARAM);
	sP.byA0   = pA->byA0;
	sP.byA1   = pA->byA1;
	sP.byA2   = 0;
	if(byID<pH->bySlotAmout)
	{
	 FFREE(BOX_REG);
	 pR = &pH->sSlot[byID];
	 sP.wParam = (WORD)pR->bySlotNumber;   FPUT(BOX_REG,pM);sP.byA2++; //0 
	 sP.wParam = (WORD)pR->bySlotType;     FPUT(BOX_REG,pM);sP.byA2++; //1  
	 sP.wParam = (WORD)pR->byPinAmout;     FPUT(BOX_REG,pM);sP.byA2++; //2   
	 sP.wParam = (WORD)pR->byState;        FPUT(BOX_REG,pM);sP.byA2++; //3   
	 sP.wParam = (WORD)pR->byAlmState;     FPUT(BOX_REG,pM);sP.byA2++; //4   
	 return FCHECK(BOX_REG); 
	}
    return 0;
}
BYTE CRegModule_CreateSoftTIParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	SREGPARAM sP;
	BYTE *pM        = (BYTE*)&sP;
	SDIRTABLE *pD   = &pT->m_pSCT->sDirectionTable[0];
	BYTE byAmObject = pD->byAmSwitching;
	STIPARAM *pTI; 
	BYTE byID = pA->byA1;
    sP.wSize  = sizeof(SREGPARAM);
	sP.byA0   = pA->byA0;
	sP.byA1   = pA->byA1;
	sP.byA2   = 0;
	sP.wParam = 0;
	if(pA->byA1<pD->byAmTI)
	{
 	 FFREE(BOX_REG);
     pTI = (STIPARAM*)pD->pSwitchTable[byID];
	 sP.wParam = (WORD)pTI->byID;          FPUT(BOX_REG,pM);sP.byA2++; //0 
	 sP.wParam = (WORD)pTI->byAmParam;     FPUT(BOX_REG,pM);sP.byA2++; //1 
	 sP.wParam = (WORD)pTI->byType;        FPUT(BOX_REG,pM);sP.byA2++; //2 
	 sP.wParam = (WORD)pTI->bySlot;        FPUT(BOX_REG,pM);sP.byA2++; //3 
	 sP.wParam = (WORD)pTI->byPin;         FPUT(BOX_REG,pM);sP.byA2++; //4 
	 sP.wParam = (WORD)pTI->byAlmState;    FPUT(BOX_REG,pM);sP.byA2++; //5
	 sP.wParam = (WORD)pTI->byState;       FPUT(BOX_REG,pM);sP.byA2++; //6 
	 sP.wParam = (WORD)pTI->byPriority;    FPUT(BOX_REG,pM);sP.byA2++; //7 
	 sP.wParam = (WORD)pTI->byDrTimer;     FPUT(BOX_REG,pM);sP.byA2++; //8 
	 sP.wParam = pTI->wHiLimit;            FPUT(BOX_REG,pM);sP.byA2++; //9 
	 sP.wParam = pTI->wHiGister;           FPUT(BOX_REG,pM);sP.byA2++; //10 
	 sP.wParam = pTI->wLoGister;           FPUT(BOX_REG,pM);sP.byA2++; //11 
	 sP.wParam = pTI->wLoLimit;            FPUT(BOX_REG,pM);sP.byA2++; //12 
	 sP.wParam = pTI->wLo;                 FPUT(BOX_REG,pM);sP.byA2++; //13 
	 sP.wParam = pTI->wHi;                 FPUT(BOX_REG,pM);sP.byA2++; //14 
	 sP.wParam = pTI->wEvPercent;          FPUT(BOX_REG,pM);sP.byA2++; //15 
	 sP.wParam = pTI->wParam;              FPUT(BOX_REG,pM);sP.byA2++; //16
	 return FCHECK(BOX_REG); 
	}
	return 0; 
}
BYTE CRegModule_CreateSoftTSParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	SREGPARAM sP;
	BYTE *pM        = (BYTE*)&sP;
	SDIRTABLE *pD   = &pT->m_pSCT->sDirectionTable[0];
	BYTE byAmObject = pD->byAmSwitching;
	STSPARAM *pTS; 
	BYTE byID = pA->byA1+pD->byAmTI;
    sP.wSize  = sizeof(SREGPARAM);
	sP.byA0   = pA->byA0;
	sP.byA1   = pA->byA1;
	sP.byA2   = 0;
	sP.wParam = 0;
	if(pA->byA1<pD->byAmTS)
	{
 	 FFREE(BOX_REG);
	 pTS = (STSPARAM*)pD->pSwitchTable[byID];
	 sP.wParam = (WORD)pTS->byID;               FPUT(BOX_REG,pM);sP.byA2++; //0  
	 sP.wParam = (WORD)pTS->byAmParam;          FPUT(BOX_REG,pM);sP.byA2++; //1   
	 sP.wParam = (WORD)pTS->byType;		        FPUT(BOX_REG,pM);sP.byA2++; //2   
	 sP.wParam = (WORD)pTS->bySlot;             FPUT(BOX_REG,pM);sP.byA2++; //3   
	 sP.wParam = (WORD)pTS->byPin;              FPUT(BOX_REG,pM);sP.byA2++; //4   
	 sP.wParam = (WORD)pTS->byAlmState;         FPUT(BOX_REG,pM);sP.byA2++; //5  
     sP.wParam = (WORD)pTS->byState;            FPUT(BOX_REG,pM);sP.byA2++; //6 
	 sP.wParam = (WORD)pTS->byPriority;         FPUT(BOX_REG,pM);sP.byA2++; //7 
	 sP.wParam = (WORD)pTS->byCRemPulce;        FPUT(BOX_REG,pM);sP.byA2++; //8   
	 sP.wParam = (WORD)pTS->byCSetPulce;        FPUT(BOX_REG,pM);sP.byA2++; //9   
	 sP.wParam = (WORD)pTS->byAlarmMode;        FPUT(BOX_REG,pM);sP.byA2++; //10   
	 sP.wParam = (WORD)pTS->byParam;            FPUT(BOX_REG,pM);sP.byA2++; //12   
	 return FCHECK(BOX_REG); 
	}
	return 0; 
}
BYTE CRegModule_CreateSoftTUParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	SREGPARAM sP;
	BYTE *pM        = (BYTE*)&sP;
	SDIRTABLE *pD   = &pT->m_pSCT->sDirectionTable[0];
	BYTE byAmObject = pD->byAmSwitching;
	STUPARAM *pTU; 
	BYTE byID = pA->byA1+pD->byAmTI+pD->byAmTS;
    sP.wSize  = sizeof(SREGPARAM);
	sP.byA0   = pA->byA0;
	sP.byA1   = pA->byA1;
	sP.byA2   = 0;
	sP.wParam = 0;
	if(pA->byA1<pD->byAmTU)
	{
 	 FFREE(BOX_REG);
	 pTU = (STUPARAM*)pD->pSwitchTable[byID];
	 sP.wParam = (WORD)pTU->byID;              FPUT(BOX_REG,pM);sP.byA2++; //0   
	 sP.wParam = (WORD)pTU->byAmParam;         FPUT(BOX_REG,pM);sP.byA2++; //1   
	 sP.wParam = (WORD)pTU->byType;            FPUT(BOX_REG,pM);sP.byA2++; //2   
	 sP.wParam = (WORD)pTU->bySlot;            FPUT(BOX_REG,pM);sP.byA2++; //3   
	 sP.wParam = (WORD)pTU->byPin;             FPUT(BOX_REG,pM);sP.byA2++; //4   
	 sP.wParam = (WORD)pTU->byAlmState;        FPUT(BOX_REG,pM);sP.byA2++; //5  
	 sP.wParam = (WORD)pTU->byState;           FPUT(BOX_REG,pM);sP.byA2++; //6   
	 sP.wParam = (WORD)pTU->byPulceType;       FPUT(BOX_REG,pM);sP.byA2++; //7   
	 sP.wParam = (WORD)pTU->byCSetPulce;       FPUT(BOX_REG,pM);sP.byA2++; //8   
	 sP.wParam = (WORD)pTU->byParam;           FPUT(BOX_REG,pM);sP.byA2++; //9   
	 return FCHECK(BOX_REG); 
	}
	return 0; 
}
BYTE CRegModule_CreateSoftTRParam(This,SREGADDR *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	return 0;
}
BYTE CRegModule_SetKpParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
    BYTE a1 = pA->byA1;
    BYTE a2 = pA->byA2;
	BYTE *pM = (BYTE*)pA;
	BYTE bySmode,byMask;
	SKPPARAM *pH   = pT->m_pHCT->pKpParam;
	if(a1==0) pT->CopyW(pT,&pH->byPassword[a2],&pA->wParam);else
	if(a1==1) pT->CopyW(pT,&pH->byPhone0[a2]  ,&pA->wParam);else
	if(a1==2) pT->CopyW(pT,&pH->byPhone1[a2]  ,&pA->wParam);else
	if(a1==3) pT->CopyW(pT,&pH->byPhone2[a2]  ,&pA->wParam);else
	if(a1==4) pH->byKpID       = (BYTE*)pA->wParam;
	if(a1==5)
	{
	 bySmode = (BYTE)pA->wParam;
	 byMask  = bySmode & 0x7f; 
	 if(!(bySmode&0x80)) pH->byStoreMode |= byMask; 
	 if(bySmode&0x80)    pH->byStoreMode &= ~byMask; 
	}else
	if(a1==6) pH->byAmCall     = (BYTE)pA->wParam;else
	if(a1==7) pH->byCallPeriod = (BYTE)pA->wParam;else
	//if(a1==8) pH->bySetChann   = (BYTE)pA->wParam;else
	return 1;
}
BYTE CRegModule_SetPortParam(This,SREGPARAM *pA)
{
	DECLARE_SINGLE_OPEN(CRegModule) 
	BYTE *pM = (BYTE*)pA;
	SHARDCOMPUTERTABLE *pH = pT->m_pHCT;
	SARMINTERFACE *pR;
	BYTE byID = pA->byA1;
	if(byID<pH->byArmAmout)
	{
	 pR = pH->pArmInterface[byID];
	 if(pA->byA2==0) pR->byNumber          = (BYTE)pA->wParam; //Port Number
	 if(pA->byA2==1) pR->byType            = (BYTE)pA->wParam; //Port Type
	 if(pA->byA2==2) pR->byPortRate        = (BYTE)pA->wParam; //Port Rate
	 if(pA->byA2==3) pR->stTcpAddr.byAddr0 = (BYTE)pA->wParam; //Parity
	 if(pA->byA2==4) pR->stTcpAddr.byAddr1 = (BYTE)pA->wParam; //Data Bits
	 if(pA->byA2==5) pR->stTcpAddr.byAddr2 = (BYTE)pA->wParam; //Stop Bits
	 return 1;
	}
	return 0;
}
BYTE CRegModule_SetHardParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	BYTE *pM = (BYTE*)pA;
	SHARDCOMPUTERTABLE *pH = pT->m_pHCT;
	SHARDSLOT *pR;
	BYTE byID = pA->byA1;
	if(byID<pH->bySlotAmout)
	{
	 pR = &pH->sSlot[byID];
	 if(pA->byA2==0) pR->bySlotNumber = (BYTE)pA->wParam;
     if(pA->byA2==1) pR->bySlotType   = (BYTE)pA->wParam;
	 if(pA->byA2==2) pR->byPinAmout   = (BYTE)pA->wParam;
	 if(pA->byA2==3) pR->byState      = (BYTE)pA->wParam;
	 if(pA->byA2==4) pR->byAlmState   = (BYTE)pA->wParam;
	 return 1;
	}
	return 0;
}
BYTE CRegModule_SetSoftTIParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	STIPARAM *pTI; 
	SDIRTABLE *pD = &pT->m_pSCT->sDirectionTable[0];
	BYTE byID = pA->byA1;
	if(byID<pD->byAmSwitching)
	{
	 pTI = (STIPARAM*)pD->pSwitchTable[byID];
	 if(pA->byA2==0)  pTI->byID        = (BYTE)pA->wParam;
	 if(pA->byA2==1)  pTI->byAmParam   = (BYTE)pA->wParam;
	 if(pA->byA2==2)  pTI->byType      = (BYTE)pA->wParam;
	 if(pA->byA2==3)  pTI->bySlot      = (BYTE)pA->wParam;
	 if(pA->byA2==4)  pTI->byPin       = (BYTE)pA->wParam;
	 if(pA->byA2==5)  pTI->byAlmState  = (BYTE)pA->wParam;
	 if(pA->byA2==6)  pTI->byState     = (BYTE)pA->wParam;
	 if(pA->byA2==7)  pTI->byPriority  = (BYTE)pA->wParam;
	 if(pA->byA2==8) {pTI->byDrTimer   = (BYTE)pA->wParam;if(pTI->byDrTimer==0)pTI->byDrTimer=1;}
	 if(pA->byA2==9)  pTI->wHiLimit    = pA->wParam;
	 if(pA->byA2==10) pTI->wHiGister   = pA->wParam;
	 if(pA->byA2==11) pTI->wLoGister   = pA->wParam;
	 if(pA->byA2==12) pTI->wLoLimit    = pA->wParam;
	 if(pA->byA2==13) pTI->wLo         = pA->wParam;
	 if(pA->byA2==14) pTI->wHi         = pA->wParam;
	 if(pA->byA2==15) pTI->wEvPercent  = pA->wParam;
	 if(pA->byA2==16) pTI->wParam      = pA->wParam;
	 return 1;
	}
	return 0;
}
BYTE CRegModule_SetSoftTSParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	STSPARAM *pTS; 
	SDIRTABLE *pD = &pT->m_pSCT->sDirectionTable[0];
	BYTE byID = pA->byA1+pD->byAmTI;
	if(byID<pD->byAmSwitching)
	{
	 pTS = (STSPARAM*)pD->pSwitchTable[byID];
	 if(pA->byA2==0)  pTS->byID        = (BYTE)pA->wParam;
	 if(pA->byA2==1)  pTS->byAmParam   = (BYTE)pA->wParam;
	 if(pA->byA2==2)  pTS->byType      = (BYTE)pA->wParam;
	 if(pA->byA2==3)  pTS->bySlot      = (BYTE)pA->wParam;
	 if(pA->byA2==4)  pTS->byPin       = (BYTE)pA->wParam;
	 if(pA->byA2==5)  pTS->byAlmState  = (BYTE)pA->wParam;
	 if(pA->byA2==6)  pTS->byState     = (BYTE)pA->wParam;
	 if(pA->byA2==7)  pTS->byPriority  = (BYTE)pA->wParam;
	 if(pA->byA2==8) {pTS->byCRemPulce = (BYTE)pA->wParam;if(pTS->byCRemPulce==0)pTS->byCRemPulce = 1;}
	 if(pA->byA2==9) {pTS->byCSetPulce = (BYTE)pA->wParam;if(pTS->byCSetPulce==0)pTS->byCSetPulce = 1;}
	 if(pA->byA2==10) pTS->byAlarmMode = (BYTE)pA->wParam;
	 if(pA->byA2==11) pTS->byParam     = (BYTE)pA->wParam;
	 return 1;
	}
	return 0;
}
BYTE CRegModule_SetSoftTUParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	STUPARAM *pTU; 
	SDIRTABLE *pD = &pT->m_pSCT->sDirectionTable[0];
	BYTE byID = pA->byA1+pD->byAmTI+pD->byAmTS;
	if(byID<pD->byAmSwitching)
	{
	 pTU = (STUPARAM*)pD->pSwitchTable[byID];
	 if(pA->byA2==0)  pTU->byID        = (BYTE)pA->wParam;
	 if(pA->byA2==1)  pTU->byAmParam   = (BYTE)pA->wParam;
	 if(pA->byA2==2)  pTU->byType      = (BYTE)pA->wParam;
	 if(pA->byA2==3)  pTU->bySlot      = (BYTE)pA->wParam;
	 if(pA->byA2==4)  pTU->byPin       = (BYTE)pA->wParam;
	 if(pA->byA2==5)  pTU->byAlmState  = (BYTE)pA->wParam;
	 if(pA->byA2==6)  pTU->byState     = (BYTE)pA->wParam;
	 if(pA->byA2==7)  pTU->byPulceType = (BYTE)pA->wParam;
	 if(pA->byA2==8) {pTU->byCSetPulce = (BYTE)pA->wParam;if(pTU->byCSetPulce==0)pTU->byCSetPulce = 1;}
	 if(pA->byA2==9)  pTU->byParam     = (BYTE)pA->wParam;
	 return 1;
	}
	return 0;
}
BYTE CRegModule_SetSoftTRParam(This,SREGPARAM *pA)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
    return 0;   
}
void CRegModule_CopyW(This,PVOID pvDst,PVOID pvSrc)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	BYTE *pDS = (BYTE*)pvDst;
	BYTE *pSR = (BYTE*)pvSrc;
    #ifndef WIN32 
	pDS[0] = pSR[1];
	pDS[1] = pSR[0];
    #else
	pDS[0] = pSR[0];
	pDS[1] = pSR[1];
    #endif 
}
void CRegModule_CRegModule(This)
{
    DECLARE_SINGLE_OPEN(CRegModule) 
	DECLARE_REGISTRATION(CRegModule,Init)
	DECLARE_REGISTRATION(CRegModule,QueryParam)
	DECLARE_REGISTRATION(CRegModule,SaveParam)
	DECLARE_REGISTRATION(CRegModule,CreateKpParam)
	DECLARE_REGISTRATION(CRegModule,CreatePortParam)
	DECLARE_REGISTRATION(CRegModule,CreateHardParam)
	DECLARE_REGISTRATION(CRegModule,CreateSoftTIParam)
	DECLARE_REGISTRATION(CRegModule,CreateSoftTSParam)
	DECLARE_REGISTRATION(CRegModule,CreateSoftTUParam)
	DECLARE_REGISTRATION(CRegModule,CreateSoftTRParam)

	DECLARE_REGISTRATION(CRegModule,SetKpParam)
	DECLARE_REGISTRATION(CRegModule,SetPortParam)
	DECLARE_REGISTRATION(CRegModule,SetHardParam)
	DECLARE_REGISTRATION(CRegModule,SetSoftTIParam)
	DECLARE_REGISTRATION(CRegModule,SetSoftTSParam)
	DECLARE_REGISTRATION(CRegModule,SetSoftTUParam)
	DECLARE_REGISTRATION(CRegModule,SetSoftTRParam)

	DECLARE_REGISTRATION(CRegModule,CopyW)
}
void CRegModule_DCRegModule(This)
{
	DECLARE_SINGLE_OPEN(CRegModule)
}
DECLARE_SINGLE_CREATE(CRegModule)

