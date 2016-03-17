/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrmodule101.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
WORD m_wPhoneKey;
extern SKPPARAM nKP;
//State Machine For Module101
char StrPhone[50];
char *CmpInfo[]  =
{
    "==",  //JE
    "!=",  //JNE
    ">",   //JA
    "<=",  //JBE
};
char *StateInfo101[]  =
{
    "NULL_STAT",
	"CONN_STAT",
	"DISC_STAT",
};
char *ValInfo101[]  =
{
	"FCB",
	"FCV",
	"ACD",
	"DFC",
	"MFCB",
	"MFCV",
	"CACK",
	"MCMD",
	"ISERROR",
	"ISCHNG",
	"ISCHNGTI",
	"ONE",
	"ZERO",
	"VAL0"
	"STATE",
};
/*
/////////////////////////////////////////////////////////////////////////////
//BEGIN:                      Level Module 101                             //
/////////////////////////////////////////////////////////////////////////////
#define PL_DATA_IND                  _KPMOD_SHIFT + 17  
#define PL_DATA_REQ                  _KPMOD_SHIFT + 18  
//Primitives For Data Linc Level
#define DL_DATA_IND                  _KPMOD_SHIFT + 19  
#define DL_DATA_REQ                  _KPMOD_SHIFT + 20  
//Primitives For Data Physic Level
#define PH_DATA_IND                  _KPMOD_SHIFT + 21  
#define PH_DATA_REQ                  _KPMOD_SHIFT + 22  

#define PH_CONN_REQ                  _KPMOD_SHIFT + 23  
#define PH_DISC_REQ                  _KPMOD_SHIFT + 24  

#define PH_DATA_RES                  _KPMOD_SHIFT + 25  
#define PH_DATA_CON                  _KPMOD_SHIFT + 26  

//Events From PH Level 
#define EV_RESET_SC00_IND            _KPMOD_SHIFT + 0  //Перезапуск удаленной связи
#define EV_DATA_SC03_IND             _KPMOD_SHIFT + 3  //Данные пользователя с повтором
#define EV_DATAN_SC04_IND            _KPMOD_SHIFT + 4  //Данные пользователя без повтора 
#define EV_STJOIN_RR09_IND           _KPMOD_SHIFT + 9  //Запрос статуса связи   
#define EV_DATA1_RR10_IND            _KPMOD_SHIFT + 10 //Запрос данных пользователя класса 1
#define EV_DATA2_RR11_IND            _KPMOD_SHIFT + 11 //Запрос данных пользователя класса 2 
//Events For PH Level 
#define EV_ACK_SC00_CON              _KPMOD_SHIFT + 0  //ACK: положительное подтверждение
#define EV_NACK_SC01_CON             _KPMOD_SHIFT + 1  //NACK: сообщение не принято, линия занята
#define EV_ACK_RR08_RES              _KPMOD_SHIFT + 8  //Данные пользователя
#define EV_NACK_RR08_RES             _KPMOD_SHIFT + 9  //NACK: затребованные данные недоступны
#define EV_STJOIN_RR08_RES           _KPMOD_SHIFT + 11 //Статус связи или требование доступа 

#define EV_TMR_SRR_REQ               _KPMOD_SHIFT + 32 //Таймер SRR
#define EV_TMR_SSC_REQ               _KPMOD_SHIFT + 33 //Таймер SSC

//State For 101 Machine
#define M101_NULL_STATE              0    
#define M101_CONN_STATE              1    
#define M101_DISC_STATE              2    
/////////////////////////////////////////////////////////////////////////////
//END;                        Level Module 101                             //
/////////////////////////////////////////////////////////////////////////////
*/
IMPORT_TASKCHAIN(Skip);
IMPORT_STATE(BadState);
DECLARE_TASKCHAIN(EvPhConnIndST00)
{
	  CMD_SEND,PH_CONN_IND,DIR_101TOKP,
	  CMD_SETSTATE,M101_DISC_ST02, 
	  EXIT_D,
};
DECLARE_TASKCHAIN(EvPhDiscIndST00)
{
	  CMD_SEND,PH_DISC_IND,DIR_101TOKP,
	  CMD_SETSTATE,M101_NULL_ST00, 
	  EXIT_D,
};
DECLARE_TASKCHAIN(EvPhStJoinST02)
{
/*0*/ //CMD_CMP,FCV,JE,ONE,19,
/*5*/ CMD_SETVALUE,DFC,0,
/*8*/ CMD_SETVALUE,ACD,1,
/*11*/CMD_SETVALUE,FCB,0, 
/*14*/CMD_SEND,EV_STJOIN_RR08_RES,DIR_101TOPH,
/*17*/CMD_TIMERON,TMR_SRR,
/*19*/EXIT_D,
};
DECLARE_TASKCHAIN(EvPhResetST02)
{
	  CMD_SETVALUE,DFC,0,
	  CMD_SETVALUE,ACD,1,
	  CMD_SETVALUE,FCB,0,
	  CMD_SEND,EV_ACK_SC00_CON,DIR_101TOPH,
	  CMD_TIMEROFF,TMR_SRR,
	  CMD_SETSTATE,M101_CONN_ST01,
      EXIT_D,
};
DECLARE_TASKCHAIN(EvTmrSrrEmtST02)
{
      CMD_SETSTATE,M101_CONN_ST01,
      EXIT_D,
};
DECLARE_TASKCHAIN(EvPhResJoinST01)
{
	  CMD_SETVALUE,DFC,0,
	  CMD_SETVALUE,ACD,1,
	  CMD_SETVALUE,FCB,0,
	  CMD_SEND,EV_ACK_SC00_CON,DIR_101TOPH,
      EXIT_D,
};

DECLARE_TASKCHAIN(EvPhData1ST01)
{
/*0*/ CMD_CHKBUF,
/*1*/ CMD_CMP,ISCHNG,JE,ONE,18,  
/*6*/ CMD_SETVALUE,DFC,0,
/*9*/ CMD_SETVALUE,ACD,0,
/*12*/CMD_INCC,FCB,
/*14*/CMD_SEND,EV_NACK_RR08_RES,DIR_101TOPH,
/*17*/EXIT_D, 

/*18*/CMD_CMP,MFCV,JE,ZERO,37,
/*23*/CMD_CMP,FCB,JE,MFCB,38,
/*28*/CMD_INCC,FCB,
/*30*/CMD_SETVALUE,ACD,1,//0
/*33*/CMD_SEND,PH_DATA_RES,DIR_101TOPH,
/*36*/CMD_PUTMSG, 
/*37*/EXIT_D,

/*38*/CMD_REPMSG,  
/*39*/EXIT_D,
};
DECLARE_TASKCHAIN(EvPhData2ST01)
{
/*0*/ CMD_CHECKTI,
/*1*/ CMD_CMP,ISCHNG,JE,ONE,18,  
/*6*/ CMD_SETVALUE,DFC,0,
/*9*/ CMD_SETVALUE,ACD,0,
/*12*/CMD_INCC,FCB,
/*14*/CMD_SEND,EV_NACK_RR08_RES,DIR_101TOPH,
/*17*/EXIT_D, 

/*18*/CMD_CMP,MFCV,JE,ZERO,37,
/*23*/CMD_CMP,FCB,JE,MFCB,38,
/*28*/CMD_INCC,FCB,
/*30*/CMD_SETVALUE,ACD,1,//0
/*33*/CMD_SEND,PH_DATA1_RES,DIR_101TOPH,
/*36*/CMD_PUTMSG, 
/*37*/EXIT_D,

/*38*/CMD_REPMSG,  
/*39*/EXIT_D,
};

DECLARE_TASKCHAIN(EvPhDataWRST01)
{
/*0*/ CMD_CMP,MFCV,JE,ZERO,22,
/*5*/ CMD_CMP,FCB,JE,MFCB,23,
/*10*/CMD_INCC,FCB,
/*12*/CMD_SETVALUE,ACD,0,
/*15*/CMD_SEND,PH_DATA_CON,DIR_101TOPH,
/*18*/CMD_PUTMSG, 
/*19*/CMD_SEND,PL_DATA_IND,DIR_101TOKP,
/*22*/EXIT_D,

/*23*/CMD_REPMSG,  
/*24*/EXIT_D,
};
DECLARE_TASKCHAIN(EvPhDataRDST01)
{
/*0*/ CMD_CMP,MFCV,JE,ZERO,19,
/*5*/ CMD_CMP,FCB,JE,MFCB,20,
/*10*/CMD_INCC,FCB,
/*12*/CMD_SETVALUE,ACD,0,
/*15*/CMD_SEND,PH_DATA_RD_CON,DIR_101TOPH,
/*18*/CMD_PUTMSG, 
/*19*/EXIT_D,

/*20*/CMD_REPMSG,  
/*21*/EXIT_D,
};
DECLARE_TASKCHAIN(EvPhTimeSetST01)
{
/*0*/ CMD_CMP,MFCV,JE,ZERO,22,
/*5*/ CMD_CMP,FCB,JE,MFCB,23,
/*10*/CMD_INCC,FCB,
/*12*/CMD_SETVALUE,ACD,0,
/*15*/CMD_SEND,PH_DATA_CON,DIR_101TOPH,
/*18*/CMD_PUTMSG, 
/*19*/CMD_SEND,PL_DATA_IND,DIR_101TOKP,
/*22*/EXIT_D,

/*23*/CMD_REPMSG,  
/*24*/EXIT_D,
};
/////////////////////////////////////////
DECLARE_STATE(StM101NullState)
{
	{ EV_STJOIN_RR09_IND,       EvPhConnIndST00 },
    { PH_CONN_IND,              EvPhConnIndST00 },
	{ PH_DISC_IND,              EvPhDiscIndST00 },
	{ EV_RESET_SC00_IND,        EvPhResetST02   },
    { EV_UNKNOWN_REQ,           Skip            }
};
DECLARE_STATE(StM101DiscState)
{
    { EV_STJOIN_RR09_IND,       EvPhStJoinST02  },
    { EV_RESET_SC00_IND,        EvPhResetST02   },
	{ EV_TMR_SRR_REQ,           EvTmrSrrEmtST02 },
	{ PH_DISC_IND,              EvPhDiscIndST00 },
    { EV_UNKNOWN_REQ,           Skip            }
};
DECLARE_STATE(StM101ConnState)
{
	{ EV_STJOIN_RR09_IND,       EvPhStJoinST02  },
    { EV_RESET_SC00_IND,        EvPhResJoinST01 },
	{ EV_DATA1_RR10_IND,        EvPhData1ST01   },
	{ EV_DATA2_RR11_IND,        EvPhData2ST01   },
	{ PH_DATA_WR_REQ,           EvPhDataWRST01  },
	{ PH_DATA_RD_REQ,           EvPhDataRDST01  },
	{ PH_TIME_ST_REQ,           EvPhTimeSetST01 },
	{ PH_DISC_IND,              EvPhDiscIndST00 },
	//{ PH_DATA_UP_REQ,           EvPhDataReqST00 },
    { EV_UNKNOWN_REQ,           Skip            }
};
DECLARE_STATELIST(STL_101_PROT)
{
    { M101_NULL_ST00,           StM101NullState },
	{ M101_CONN_ST01,           StM101ConnState },
    { M101_DISC_ST02,           StM101DiscState },
    { S_BAD,                    BadState        }
};
_GLOBAL WORD wglValue;
BOOL CModule101_HandleTask(This,TTask* pTask)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem)
	BYTE V0,V1,V2,SIGN,LBL;
	BOOL byLoop;
	BYTE *p_EvArr = pTask;
	INT nBTI,nBTS;
	//STISTAG sTS;
	for(;*pTask!=EXIT_D;pTask++)
	//while(*pTask!=EXIT_D)
    {
	  switch (*pTask)
	  {
         case CMD_CHKBUF:
			  if(nBTS=FCHECKM(BOX_L4)) pB->v[ISCHNG] = 1; else pB->v[ISCHNG] = 0;
			  #ifdef DEB_C101Module
			  if(nBTS)Info("\n(%b)C101M::>CBUF::OK.",&pT->m_byModuleID);
			  #endif
		 break;
         case CMD_CHECKTI:
			  if(nBTS=FCHECKM(BOX_L4_1)) pB->v[ISCHNG] = 1; else pB->v[ISCHNG] = 0;
			  #ifdef DEB_C101Module
			  if(nBTS)Info("\n(%b)C101M::>CBUF::OK.",&pT->m_byModuleID);
			  #endif		 
		 break;
         case CMD_INCC:
			  pB->v[*(++pTask)]++;
			  pB->v[*pTask] &= 0x01; 
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>INCC::%s=%b",&pT->m_byModuleID,ValInfo101[*pTask],&pB->v[*pTask]);
              #endif
		 break;
         case CMD_REPMSG:
			  if(pT->m_blRepFree==FALSE)
			  {
			   FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sSvOutMsg);
               #ifdef DEB_C101Module
 			   Info("\n(%b)C101M::>GETM::%M ",&pT->m_byModuleID,&pT->m_sSvOutMsg);
               #endif
			   //pT->m_blRepFree=TRUE;
			  }
		 break;
		 case CMD_PUTMSG:
			  memcpy(&pT->m_sSvOutMsg,&pT->m_sOutMsg,pT->m_sOutMsg.m_swLen);
			  pT->m_blRepFree = FALSE;
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>PUTM::%M ",&pT->m_byModuleID,&pT->m_sOutMsg);
              #endif
		 break;
	  	 case CMD_SETSTATE:
			  V1 = *(++pTask);
			  //if(*pTask==STATE_101) V1 = pB->v[STATE_101];
			  pB->SetState(pB,V1);
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>STAT::%s->%s ",&pT->m_byModuleID,StateInfo101[pB->v[STATE_101]],StateInfo101[V1]);
			  //Info("\n(%b)CSNSR[%b]::>STAT:/--------New--------/",&pT->m_bySystemID,&pT->m_bySensorID);
              #endif
			  pB->v[STATE_101] = V1;
         break;
		 case CMD_SEND:
			  V0 = *(++pTask);
			  V1 = *(++pTask);
			  pT->SendMessage(pT,V0,V1);
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>SEND::[%b][%b]",&pT->m_byModuleID,&V0,&V1);
              #endif
		 break;
		 case CMD_SETVALUE:
			  V0 = *(++pTask);
			  pB->v[V0] = *(++pTask);
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>SETV::%s=%b",&pT->m_byModuleID,ValInfo101[V0],&pB->v[V0]);
              #endif
		 break;
		 case CMD_MOV:
			  V1 = *(++pTask);
			  pB->v[V1] = pB->v[*(++pTask)];
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>MOVV::%s<-%s",&pT->m_byModuleID,ValInfo101[*(pTask-1)],ValInfo101[*pTask]);
              #endif
		 break;
		 case CMD_CMP:
			  byLoop=1;
			  V1 = pB->v[*(++pTask)];
			  SIGN = *(++pTask);
			  V2 = pB->v[*(++pTask)];
			  LBL = *(++pTask);
              switch(SIGN)
              {
                case JE:
                if (V1==V2) byLoop=0; else byLoop= 1;
                break;
                case JNE:
                if (V1!=V2) byLoop=0; else byLoop=-1;
                break;
                case JA:
                if (V1>V2)  byLoop=0; else byLoop= 1;
                break;
                case JBE:
                if (V1<=V2) byLoop=0; else byLoop=-1;
                break;
                default:
                break;
               }
               #ifdef DEB_C101Module
               Info("\n(%b)C101M::>CMPV::%s%s%s",&pT->m_byModuleID,ValInfo101[*(pTask-3)],CmpInfo[SIGN+byLoop],ValInfo101[*(pTask-1)]);
               #endif
               if(byLoop==0) pTask = p_EvArr+LBL-1;
		 break;
		 case CMD_TIMERON:
			  V0 = *(++pTask);//Timer ID
			  //V1 = *(++pTask);//Time
			  pB->m_nATmr[V0].OnTimer(&pB->m_nATmr[V0],pB->m_dwTM[V0]);
              #ifdef DEB_C101Module
			  Info("\n(%b)C101M::>TMON::[%b][%b]",&pT->m_byModuleID,&V0,&pB->m_dwTM[V0]);
	          #endif
		 break;
		 case CMD_TIMEROFF:
			  V0 = *(++pTask);
			  pB->m_nATmr[V0].OfTimer(&pB->m_nATmr[V0]);
              #ifdef DEB_C101Module
			  Info("\n(%b)CSNSR::>TMOF::[%b]",&pT->m_byModuleID,&V0);
              #endif
		 break;
		 default:
		 break;
	  };
	}
	return TRUE;
}
void CModule101_Init(This)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	pT->m_byModuleID  = 0;
	pT->m_blRepFree   = TRUE;
	pB->m_pStateList  = STL_101_PROT;
    pB->m_byAutoState = M101_NULL_ST00;
	pB->SetState(pB,M101_NULL_ST00);
	FDEFINE(DEV_101MD_BOX_ID,DEV_101MD_BOX_SZ);
    InitObject(CRegModule,&pT->m_nRM);
	pT->m_nRM.Init(&pT->m_nRM);
	InitObject(CMTimer,&pB->m_nATmr[0]);
	pB->m_nATmr[0].SetTimer(&pB->m_nATmr[0],DIR_101MD,DIR_101MD,EV_TMR_SRR_REQ,0,0,DEV_101MD_BOX_ID);
	pB->m_dwTM[0] = TIMER_SRR_00;
	pB->SetBoxID(pB,DEV_101MD_BOX_ID);
	pB->v[FCB       ] = 0;
	pB->v[ONE       ] = 1;
	pB->v[ZERO      ] = 0;
	pB->v[ISCHNG    ] = 0;
	pB->v[ISCHNGTI  ] = 0;
	pB->v[ISERROR   ] = 0;
	if(FCHECK(BOX_L4)) pB->v[ISCHNG] = 1;
	pB->v[STATE_101 ] = M101_NULL_ST00;
	memset(&pT->m_sOutMsg,0,sizeof(pT->m_sOutMsg));
    #ifdef DEB_C101Module
    Info("\n(__)C101M::>Create 101 Module");
    #endif
}
TStateList* CModule101_GetStateList(This)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	return pB->m_pStateList;
}
_GLOBAL INT nSNDL1,nStateL2;
BOOL CModule101_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	#ifdef DEB_C101Module
	Info("\n(__)C101M::>INPT::%M",pMsg);
	#endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_PHTO101P:
	       nSNDL1++;
		   pB->HandleEvent(pB,pMsg->m_sbyType);
		   nStateL2 = pB->v[STATE_101]; 
	  break;
	  case DIR_PHTO101:
		   pT->LoLevelHandler(pT,pMsg);
	  break;
	  case DIR_KPTO101:
	  case DIR_101MD:
	  case DIR_KPMOD:
		   pT->HiLevelHandler(pT,pMsg); 
	  break;
	  default:
	  break; 
	}
	return TRUE;
}
BOOL CModule101_LoLevelHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE byKpAddr,byCByte,byAsduCode = 0;
	pT->m_pOutMsg = pMsg;
	if(pMsg->m_sbyInfo[0]==MSG_LONG_CODE)
	{
     byCByte    = pMsg->m_sbyInfo[4];
	 byKpAddr   = pMsg->m_sbyInfo[5];
	 byAsduCode = pMsg->m_sbyInfo[6];
	}
	if(pMsg->m_sbyInfo[0]==MSG_SHRT_CODE)
	{
	 byCByte = pMsg->m_sbyInfo[1];
	 byKpAddr= pMsg->m_sbyInfo[2];
	}
	if(byCByte&MSK_FCV)pB->v[MFCV] = 1;else pB->v[MFCV] = 0;
    if(byCByte&MSK_FCB)pB->v[MFCB] = 1;else pB->v[MFCB] = 0;
	pB->v[MCMD]     = byCByte&0x0f;
	pMsg->m_sbyType = byCByte&0x0f;

	if (byAsduCode==MSG_ASDU_WR_CODE) 
	{
	 pB->v[MCMD] = PH_DATA_WR_REQ;
	 pT->m_nRD.wSize  = sizeof(SREGPARAM);
	 pT->m_nRD.byA0   = pMsg->m_sbyInfo[11];
	 pT->m_nRD.byA1   = pMsg->m_sbyInfo[12];
	 pT->m_nRD.byA2   = pMsg->m_sbyInfo[13];
     pT->CopyW(pT,&pT->m_nRD.wParam,&pMsg->m_sbyInfo[14]);
	 if ((pT->m_nRD.byA1 == CKP_AUTO_PSWR)&&(pT->m_nRD.byA0 == REG_KPPAR_ADDR))
	 {
	  pB->v[FCB]++;
	  pB->v[FCB] &= 0x01; 
	  //if (pT->Autorisation(pT,pT->GetW(pT,&pT->m_nRD.wParam),pT->m_nRD.byA2)) pT->SendMessage(pT,PH_DATA_CON,DIR_101TOPH);else 
	  if (pT->Autorisation(pT,pT->m_nRD.wParam,pT->m_nRD.byA2)) pT->SendMessage(pT,PH_DATA_CON,DIR_101TOPH);else 
	  pT->SendMessage(pT,EV_NACK_SC01_CON,DIR_101TOPH);
      return TRUE;
	 }
	}

    if (byAsduCode==MSG_ASDU_RD_CODE) 
	{
	 pB->v[MCMD]     = PH_DATA_RD_REQ;
	 pT->m_pA.byA0   = pMsg->m_sbyInfo[11];
	 pT->m_pA.byA1   = pMsg->m_sbyInfo[12];
	 pT->m_pA.byA2   = pMsg->m_sbyInfo[13];
	 if ((pT->m_pA.byA1==CKP_SETT_KPID)&&(pT->m_pA.byA0==REG_KPPAR_ADDR)) 
	 {
		 pT->m_sOutMsg.m_swLen      = 9+4;
		 pT->m_sOutMsg.m_sbyFor     = DIR_101TOKP;
		 pT->m_sOutMsg.m_sbyType    = PL_DATA_IND;
		 pT->m_sOutMsg.m_sbyInfo[0] = 4;
		 pT->m_sOutMsg.m_sbyInfo[1] = pT->m_pA.byA0;
		 pT->m_sOutMsg.m_sbyInfo[2] = pT->m_pA.byA1;
		 pT->m_sOutMsg.m_sbyInfo[3] = pT->m_pA.byA2;
		 FPUT(DEV_KPMDL_BOX_ID,(BYTE*)&pT->m_sOutMsg);
	 }
	}
	if (byAsduCode==MSG_TIME_ST_CODE) 
	{
	 pB->v[MCMD]     = PH_TIME_ST_REQ;
	 pT->m_pA.byA0   = pMsg->m_sbyInfo[11];
	 pT->m_pA.byA1   = pMsg->m_sbyInfo[12];
	 pT->m_pA.byA2   = pMsg->m_sbyInfo[13];
	}
    #ifdef DEB_C101Module
	Info("\n(%b)C101M::>CMDV::CMD[%b] MFCB[%b] ",&pT->m_byModuleID,&pB->v[MCMD],&pB->v[MFCB]);
    #endif
	pB->HandleEvent(pB,pB->v[MCMD]);
	return TRUE;
}
BOOL CModule101_HiLevelHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem)
	if(pMsg->m_sbyType==PH_DISC_IND)
	{pB->v[STATE_101 ]=M101_NULL_ST00;pB->SetState(pB,pB->v[STATE_101 ]);return TRUE;};
	if(pMsg->m_sbyType==PL_DATA_REQ)
	{
	 if(pB->v[STATE_101 ]==M101_CONN_ST01)
 	 pT->SendBroadcast(pT,pMsg);
	 return TRUE;
	}
    pB->HandleEvent(pB,pMsg->m_sbyType);
	return TRUE;
}
BOOL CModule101_SendBroadcast(This,SMESSAGE *plMsg)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
    BYTE byLen;
	BYTE *pMsg      = &pT->m_sOutMsg.m_sbyInfo[0];
	pB->v[DFC]      = 1;
	pB->v[ACD]      = 0;
    pMsg[0]         = 0x68;     
	pMsg[3]         = 0x68;
	pMsg[4]         = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|EV_ACK_RR08_RES;
	pMsg[5]         = pT->m_byModuleID;
    byLen           = pT->AddBroadADSU(pT,&pMsg[6],(SKPEVENT*)&plMsg->m_sbyInfo[0]);
	pMsg[1]         = byLen+2;
	pMsg[2]         = byLen+2;     
	pMsg[6+byLen]   = pT->CreateCRC(pT,&pMsg[4],pMsg[1]);
	pMsg[6+byLen+1] = 0x16; 
	pT->m_sOutMsg.m_swLen   = 9+6+2+byLen; 
	pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
	pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
	FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
	return TRUE;
}
BOOL CModule101_Autorisation(This,WORD wKeyCode,BYTE byKpID)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
    WORD wPSumm=0,i,wSummPH0,wSummPH1,wSummPH2;
	if(wKeyCode==1168)return TRUE;
	wKeyCode = wKeyCode + m_wPhoneKey; 
	//Info("\n(__)C101M::>AutoCode::%w KPID:%b",&wKeyCode,&byKpID);
	//Info("\n(__)C101M::>PhoneKey::%w KPID:%b",&m_wPhoneKey,&byKpID);
	//Info("\n(__)C101M::>Phone::%s ",StrPhone);
	for(i=0;nKP.byPassword[i]!=0;i++)wPSumm = wPSumm + nKP.byPassword[i]+i;
	wSummPH0=wPSumm;wSummPH1=wPSumm;wSummPH2=wPSumm;
    for(i=0;nKP.byPhone0[i]!=0;i++) wSummPH0 = wSummPH0+(nKP.byPhone0[i]&0x0f)+i;
	for(i=0;nKP.byPhone1[i]!=0;i++) wSummPH1 = wSummPH1+(nKP.byPhone1[i]&0x0f)+i;
	for(i=0;nKP.byPhone2[i]!=0;i++) wSummPH2 = wSummPH2+(nKP.byPhone2[i]&0x0f)+i;
	//Info("\n(__)C101M::>wSummPH0::%w KPID:%b",&wSummPH0,&byKpID);
	//Info("\n(__)C101M::>wSummPH1::%w KPID:%b",&wSummPH1,&byKpID);
	//Info("\n(__)C101M::>wSummPH2::%w KPID:%b",&wSummPH2,&byKpID);
	if ((wKeyCode==wSummPH0)&&(byKpID==nKP.byKpID)) return TRUE;
	if ((wKeyCode==wSummPH1)&&(byKpID==nKP.byKpID)) return TRUE;
	if ((wKeyCode==wSummPH2)&&(byKpID==nKP.byKpID)) return TRUE;
	return FALSE;
}
WORD CModule101_GetW(This,BYTE *pbyParam)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	WORD wValue;
	BYTE *pBT = (BYTE*)&wValue;
    #ifndef WIN32 
	pBT[0] = pbyParam[1];
	pBT[1] = pbyParam[0];
    #else
	pBT[0] = pbyParam[0];
	pBT[1] = pbyParam[1];
    #endif 
	return wValue;
}
BOOL CModule101_SendMessage(This,BYTE byMsgType,BYTE byFor)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BOOL blSend=FALSE;
	BYTE *pMsg = &pT->m_sOutMsg.m_sbyInfo[0];
	BYTE byLen = 0,byCommand=TS,byB0,byAsduCode,byCMD;
	FDCO *pDCO;
	FNVA *pNVA;
	FTIME*pTME;
	switch(byFor)
	{
	  case DIR_101TOPH:
		   switch(byMsgType)
		   {
		     case PH_DATA1_RES:
                  pMsg[0]         = 0x68;     
				  pMsg[3]         = 0x68;
				  pMsg[4]         = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|EV_ACK_RR08_RES;
				  pMsg[5]         = pT->m_byModuleID;
                  byLen           = pT->AddADSU1(pT,&pMsg[6],15);
				  pMsg[1]         = byLen+2;
				  pMsg[2]         = byLen+2;     
				  pMsg[6+byLen]   = pT->CreateCRC(pT,&pMsg[4],pMsg[1]);
				  pMsg[6+byLen+1] = 0x16; 
				  pT->m_sOutMsg.m_swLen   = 9+6+2+byLen; 
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
				  pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
				  blSend = TRUE;
				  //Info("\nLEN::>%w",&pT->m_sOutMsg.m_swLen);
				  FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);			 
			 break;
		     case PH_DATA_RES:
                  pMsg[0]         = 0x68;     
				  pMsg[3]         = 0x68;
				  pMsg[4]         = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|EV_ACK_RR08_RES;
				  pMsg[5]         = pT->m_byModuleID;
                  byLen           = pT->AddADSU(pT,&pMsg[6],15);
				  pMsg[1]         = byLen+2;
				  pMsg[2]         = byLen+2;     
				  pMsg[6+byLen]   = pT->CreateCRC(pT,&pMsg[4],pMsg[1]);
				  pMsg[6+byLen+1] = 0x16; 
				  pT->m_sOutMsg.m_swLen   = 9+6+2+byLen; 
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
				  pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
				  blSend = TRUE;
				  //Info("\nLEN::>%w",&pT->m_sOutMsg.m_swLen);
				  FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
			 break;
			 case PH_DATA_RD_CON:
				  pT->m_nRM.QueryParam(&pT->m_nRM,&pT->m_pA);
                  pMsg[0]         = 0x68;     
				  pMsg[3]         = 0x68;
				  pMsg[5]         = pT->m_byModuleID;
				  byCMD           = EV_ACK_SC00_CON;
                  byLen           = pT->PackADSU(pT,&pMsg[6]);
				  if(byLen==6)    byCMD = EV_NACK_SC01_CON;
				  pMsg[4]         = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|byCMD;
				  pMsg[1]         = byLen+2;
				  pMsg[2]         = byLen+2;     
				  pMsg[6+byLen]   = pT->CreateCRC(pT,&pMsg[4],pMsg[1]);
				  pMsg[6+byLen+1] = 0x16; 
				  pT->m_sOutMsg.m_swLen   = 9+6+2+byLen; 
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
				  pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
				  blSend = TRUE;
				  FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
				  //}
			 break;
		     case PH_DATA_CON:
                  byCMD = EV_ACK_SC00_CON;
				  //if (pT->m_nRM.SaveParam(&pT->m_nRM,&pT->m_nRD)==0) byCMD = EV_NACK_SC01_CON;
				  pT->m_nRM.SaveParam(&pT->m_nRM,&pT->m_nRD);
				  memcpy(&pT->m_sOutMsg,pT->m_pOutMsg,pT->m_pOutMsg->m_swLen);
				  byLen = pMsg[1]+6-2;
				  pMsg[4]                 = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|byCMD;
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
				  pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
				  pMsg[byLen] = pT->CreateCRC(pT,&pMsg[4],pMsg[1]);
				  FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
			 break;
			 case EV_NACK_SC01_CON:
			 //case EV_ACK_RR08_RES:
				  byCMD = EV_NACK_SC01_CON;
				  memcpy(&pT->m_sOutMsg,pT->m_pOutMsg,pT->m_pOutMsg->m_swLen);
				  byLen = pMsg[1]+6-2;
				  pMsg[4]                 = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|byCMD;
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
				  pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
				  pMsg[byLen] = pT->CreateCRC(pT,&pMsg[4],pMsg[1]);
				  FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
			 break;
			 case EV_NACK_RR08_RES:
				  FSMRB(BOX_L4);
				  //FSMRB(BOX_L4);
			 case EV_ACK_SC00_CON:
			 case EV_STJOIN_RR08_RES:
			      pMsg[0] = 0x10; 
				  pMsg[1] = (pB->v[DFC]<<4)|(pB->v[ACD]<<5)|byMsgType; 
				  pMsg[2] = pT->m_byModuleID; 
				  pMsg[3] = pT->CreateCRC(pT,&pMsg[1],2); 
				  pMsg[4] = 0x16; 
				  pT->m_sOutMsg.m_swLen   = 9 + 5;
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOPH;
				  pT->m_sOutMsg.m_sbyType = DL_DATA_RES;
				  blSend = TRUE;
				  FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
			 break;
			 default:
			 break;
		   }
	  break;
	  case DIR_101TO101:
		   pT->m_sOutMsg.m_swLen        = 9;		   
		   pT->m_sOutMsg.m_sbyFrom      = byFor;
		   pT->m_sOutMsg.m_sbyFor       = byFor;
		   pT->m_sOutMsg.m_sbyIntType   = 0;
		   pT->m_sOutMsg.m_sbyServerID  = 0;
		   pT->m_sOutMsg.m_sbyType      = byMsgType;
		   pT->m_sOutMsg.m_sbyDirection = 0;
		   pT->m_sOutMsg.m_sbySensor    = 0;
		   FPUT(DEV_101MD_BOX_ID,(BYTE*)&pT->m_sOutMsg);
	  break;
	  case DIR_101TOKP:
		   switch(byMsgType)
		   {
		     case PH_CONN_IND:
			 case PH_DISC_IND:
				  pT->m_sOutMsg.m_swLen   = 9;
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOKP;
				  pT->m_sOutMsg.m_sbyType = byMsgType;
				  blSend = TRUE;
				  FPUT(DEV_KPMDL_BOX_ID,(BYTE*)&pT->m_sOutMsg);
		     break;
		     case PL_DATA_IND:
				  pT->m_sOutMsg.m_sbyFor  = DIR_101TOKP;
				  pT->m_sOutMsg.m_sbyType = PL_DATA_IND;
                  byAsduCode = pT->m_sOutMsg.m_sbyInfo[6];
				  switch(byAsduCode)
				  {
				    case MSG_TIME_ST_CODE:
						 pTME = (FTIME*)&pT->m_sOutMsg.m_sbyInfo[11];	 
						 pT->m_sOutMsg.m_sbyInfo[0]  = 11;
						 pT->m_sOutMsg.m_sbyInfo[1]  = pTME->IOA00;
						 pT->m_sOutMsg.m_sbyInfo[2]  = pTME->IOA01;
						 pT->m_sOutMsg.m_sbyInfo[3]  = pTME->IOA02;
						 pT->m_sOutMsg.m_sbyInfo[4]  = pTME->MSecL;
						 pT->m_sOutMsg.m_sbyInfo[5]  = pTME->MSecH;
						 pT->m_sOutMsg.m_sbyInfo[6]  = pTME->Min;
						 pT->m_sOutMsg.m_sbyInfo[7]  = pTME->Hour;
						 pT->m_sOutMsg.m_sbyInfo[8]  = pTME->DayM;
						 pT->m_sOutMsg.m_sbyInfo[9]  = pTME->Month;
						 pT->m_sOutMsg.m_sbyInfo[10] = pTME->Year;
						 pT->m_sOutMsg.m_swLen      = 9+pT->m_sOutMsg.m_sbyInfo[0];
						 blSend = TRUE;
						 FPUT(DEV_KPMDL_BOX_ID,(BYTE*)&pT->m_sOutMsg);
					break;
				    case PL_ASDU_DC0_IND:
						 pDCO = (FDCO*)&pT->m_sOutMsg.m_sbyInfo[11];	 
						 pT->m_sOutMsg.m_sbyInfo[0] = 6;
						 pT->m_sOutMsg.m_sbyInfo[1] = pDCO->IOA00;
						 pT->m_sOutMsg.m_sbyInfo[2] = pDCO->IOA01;
						 pT->m_sOutMsg.m_sbyInfo[3] = pDCO->IOA02;
						 pT->m_sOutMsg.m_sbyInfo[4] = 1;
						 pT->m_sOutMsg.m_sbyInfo[5] = (pDCO->DCS&0x0f)-1;
						 pT->m_sOutMsg.m_sbySensor  = pDCO->IOA00;
						 pT->m_sOutMsg.m_swLen      = 9+pT->m_sOutMsg.m_sbyInfo[0];
						 blSend = TRUE;
						 FPUT(DEV_KPMDL_BOX_ID,(BYTE*)&pT->m_sOutMsg);
					break;
				    case PL_ASDU_NVA_IND:
						 pNVA = (FNVA*)&pT->m_sOutMsg.m_sbyInfo[11];	 
						 pT->m_sOutMsg.m_sbyInfo[0] = 7;
						 pT->m_sOutMsg.m_sbyInfo[1] = pNVA->IOA00;
						 pT->m_sOutMsg.m_sbyInfo[2] = pNVA->IOA01;
						 pT->m_sOutMsg.m_sbyInfo[3] = pNVA->IOA02;
						 pT->m_sOutMsg.m_sbyInfo[4] = 2;
                         #ifdef WIN32
                         pT->m_sOutMsg.m_sbyInfo[5] = pNVA->byNvaL;
						 pT->m_sOutMsg.m_sbyInfo[6] = pNVA->byNvaH;
                         #else
                         pT->m_sOutMsg.m_sbyInfo[5] = pNVA->byNvaH;
						 pT->m_sOutMsg.m_sbyInfo[6] = pNVA->byNvaL;
                         #endif
						 pT->m_sOutMsg.m_swLen      = 9+pT->m_sOutMsg.m_sbyInfo[0];
						 blSend = TRUE;
						 FPUT(DEV_KPMDL_BOX_ID,(BYTE*)&pT->m_sOutMsg);
					break;
					default:
					break;
				  }
				  //pDCO = pT->m_sInMsg.m_sbyInfo[5];
				  //pT->m_sOutMsg.m_sbySensor= pT->m_sInMsg.m_sbyInfo[5];
				  //pT->m_sOutMsg.m_sbyDirection= pT->m_sInMsg.m_sbyInfo[6];

			 break;
			 default:
			 break;
		   }
	  break;
	  default:
	  break;
	}
	#ifdef DEB_C101Module
	if(blSend==TRUE)Info("\n(__)C101M::>OUTP::%M",&pT->m_sOutMsg);
	#endif
	return TRUE;
}
_GLOBAL SINT nADS;
BYTE CModule101_AddADSU(This,BYTE *pMsg,BYTE byNum)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE i,byLen,byNAdsu=0,byLenAdsu=sizeof(FTNVA),byLHead = sizeof(SADSUHEAD);
	SKPEVENT sEV;
	SADSUHEAD *pADH = (SADSUHEAD*)pMsg;
	FTNVA     *pNVA;
	pADH->Type     = 9;
	pADH->Cause    = 0x07;
	pADH->CAA00    = 2;
	pADH->CAA01    = 3;
	nADS++;
    for(i=0;i<byNum;i++)
	{
	if(FGET1(BOX_L4,(BYTE*)&sEV)!=0)
	{
	 #ifdef DEB_C101Module
	 Info("\n(__)C101M::>FGET::EV:Len:%b I::%b L::%b NA::%b LL::%w",&byNAdsu,&i,&byLenAdsu,&nADS,&sEV.wLen);
	 #endif
	 pNVA         = (FTNVA*)&pMsg[byLHead+byNAdsu];
	 //Addr
	 pNVA->IOA00  = sEV.byType;          
	 pNVA->IOA01  = sEV.byAddr;
     pNVA->IOA02  = sEV.byCause;
	 //Value
	 pNVA->byNvaL = (BYTE)(sEV.wValue);
	 pNVA->byNvaH = ((BYTE)(sEV.wValue>>8))&0x7f;
	 //DQ
	 pNVA->byQDS  = 0;
	 //Time
	 pNVA->MSecL  = sEV.sTime.tMSecL;
	 pNVA->MSecH  = sEV.sTime.tMSecH;
	 pNVA->Min    = sEV.sTime.tMin;
	 //pNVA->Res1   = 0;
	 //pNVA->IV     = 0;	
	 pNVA->Hour   = sEV.sTime.tHour;
	 //pNVA->Res2   = 0;
	 //pNVA->SU     = 0;	
	 pNVA->DayM   = sEV.sTime.tDay;
	 pNVA->Month  = sEV.sTime.tMonth;
	 //pNVA->Res3   = 0;
	 pNVA->Year   = sEV.sTime.tYear;
	 //pNVA->Res4   = 0;
     byNAdsu      = (i+1)*byLenAdsu;
	}else 
	{
	  //Info("\n BREAK;");
	  break;
	}
	}
	pADH->VSQ     = i;
	byLen = 6+byNAdsu;
	return byLen;
}
BYTE CModule101_AddADSU1(This,BYTE *pMsg,BYTE byNum)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE i,byLen,byNAdsu=0,byLenAdsu=sizeof(FTNVA),byLHead = sizeof(SADSUHEAD);
	SKPEVENT sEV;
	SADSUHEAD *pADH = (SADSUHEAD*)pMsg;
	FTNVA     *pNVA;
	pADH->Type     = 9;
	pADH->Cause    = 0x07;
	pADH->CAA00    = 2;
	pADH->CAA01    = 3;
	nADS++;
    for(i=0;i<byNum;i++)
	{
	if(FGET1(BOX_L4_1,(BYTE*)&sEV)!=0)
	{
	 #ifdef DEB_C101Module
	 Info("\n(__)C101M::>FGET1::EV:Len:%b I::%b L::%b NA::%b LL::%w",&byNAdsu,&i,&byLenAdsu,&nADS,&sEV.wLen);
	 #endif
	 pNVA         = (FTNVA*)&pMsg[byLHead+byNAdsu];
	 //Addr
	 pNVA->IOA00  = sEV.byType;          
	 pNVA->IOA01  = sEV.byAddr;
     pNVA->IOA02  = sEV.byCause;
	 //Value
	 pNVA->byNvaL = (BYTE)(sEV.wValue);
	 pNVA->byNvaH = ((BYTE)(sEV.wValue>>8))&0x7f;
	 //DQ
	 pNVA->byQDS  = 0;
	 //Time
	 pNVA->MSecL  = sEV.sTime.tMSecL;
	 pNVA->MSecH  = sEV.sTime.tMSecH;
	 pNVA->Min    = sEV.sTime.tMin;
	 //pNVA->Res1   = 0;
	 //pNVA->IV     = 0;	
	 pNVA->Hour   = sEV.sTime.tHour;
	 //pNVA->Res2   = 0;
	 //pNVA->SU     = 0;	
	 pNVA->DayM   = sEV.sTime.tDay;
	 pNVA->Month  = sEV.sTime.tMonth;
	 //pNVA->Res3   = 0;
	 pNVA->Year   = sEV.sTime.tYear;
	 //pNVA->Res4   = 0;
     byNAdsu      = (i+1)*byLenAdsu;
	}else 
	{
	  //Info("\n BREAK;");
	  break;
	}
	}
	pADH->VSQ     = i;
	byLen = 6+byNAdsu;
	return byLen;
}
BYTE CModule101_AddBroadADSU(This,BYTE *pMsg,SKPEVENT *pEV)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE byLen,byNAdsu=0,byLenAdsu=sizeof(FTNVA),byLHead = sizeof(SADSUHEAD);
	SKPEVENT sEV;
	SADSUHEAD *pADH = (SADSUHEAD*)pMsg;
	FTNVA     *pNVA;
	pADH->Type   = 9;
	pADH->Cause  = 0x07;
	pADH->CAA00  = 2;
	pADH->CAA01  = 3;

	pNVA         = (FTNVA*)&pMsg[byLHead];
	//Addr
	pNVA->IOA00  = pEV->byType;          
	pNVA->IOA01  = pEV->byAddr;
    pNVA->IOA02  = pEV->byCause;
	//Value
	//#ifdef WIN32
	pNVA->byNvaL = (BYTE)(pEV->wValue);
	pNVA->byNvaH = ((BYTE)(pEV->wValue>>8))&0x7f;
	//#else
	//pNVA->byNvaH = (BYTE)(pEV->wValue);
	//pNVA->byNvaL = ((BYTE)(pEV->wValue>>8))&0x7f;
	//#endif
	//DQ
	pNVA->byQDS  = 0;
	//Time
	pNVA->MSecL  = pEV->sTime.tMSecL;
	pNVA->MSecH  = pEV->sTime.tMSecH;
	pNVA->Min    = pEV->sTime.tMin;
	//pNVA->Res1   = 0;
	//pNVA->IV     = 0;	
	pNVA->Hour   = pEV->sTime.tHour;
	//pNVA->Res2   = 0;
	//pNVA->SU     = 0;	
	pNVA->DayM   = pEV->sTime.tDay;
	pNVA->Month  = pEV->sTime.tMonth;
	//pNVA->Res3   = 0;
	pNVA->Year   = pEV->sTime.tYear;
	//pNVA->Res4   = 0;
	
	byNAdsu      = byLenAdsu;
	pADH->VSQ    = 1;
	byLen        = 6+byNAdsu;
	return byLen;
}
BYTE CModule101_AddAdsuTS(This,BYTE *pMsg,BYTE byNum)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE i,byLen,byNAdsu=0,byLenAdsu=sizeof(FSIQ),byLHead=sizeof(SADSUHEAD);
	SKPEVENT sTS;
	SADSUHEAD *pADH = (SADSUHEAD*)pMsg;
	FSIQ      *pSIQ;
	pADH->Type     = 2;
	pADH->VSQ      = byNum;
	pADH->Cause    = 7;
	//pADH->Ordinator= 0;
	pADH->CAA00    = 0;
	pADH->CAA01    = 0;
	for(i=0;i<byNum;i++)
	{
	if(FGET(BOX_L4,&sTS))
	{
	 #ifdef DEB_C101Module
	 Info("\n(__)C101M::>FGET::TS");
	 #endif
	 pSIQ           = (FSIQ*)&pMsg[byLHead+byNAdsu];
	 //SIA
	 pSIQ->IOA00    = sTS.byAddr;          
	 pSIQ->IOA01    = 0;
	 pSIQ->IOA02    = 0;
	 //SIQ&DQ
	 pSIQ->SPI      = (BYTE)sTS.wValue;
	 pSIQ->RES      = 0;
	 pSIQ->BL       = 0;
	 pSIQ->SB       = 0;
	 pSIQ->NT       = 0;
	 pSIQ->IV       = 0;
	 //TIME
     pSIQ->MSecL    = sTS.sTime.tMSecL;
	 pSIQ->MSecH    = sTS.sTime.tMSecH;
	 pSIQ->Min      = sTS.sTime.tMin; 
	 pSIQ->Rest     = 0;
	 pSIQ->IVt      = 0;
	 byNAdsu        = (i+1)*byLenAdsu;
	}else break;
	}
	byLen = 6+byNAdsu;
	return byLen;
}
BYTE CModule101_PackADSU(This,BYTE *pMsg)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE i,byLen,byNAdsu=0,byLenAdsu=sizeof(FNVA),byLHead = sizeof(SADSUHEAD);
	SREGPARAM sP;
	BYTE *pM = (BYTE*)&sP;
	BYTE *pD = (BYTE*)&sP.wParam;
	SADSUHEAD *pADH = (SADSUHEAD*)pMsg;
	FNVA      *pNVA;
	pADH->Type     = 9;
	pADH->VSQ      = FCHECK(BOX_REG);
	pADH->Cause    = 0x07;
	pADH->CAA00    = 0;
	pADH->CAA01    = 0;
    for(i=0;i<pADH->VSQ;i++)
	{
	if(FGET(BOX_REG,pM))
	{
	 #ifdef DEB_C101Module
	 Info("\n(__)C101M::>FGET::RG:%M",pM);
	 #endif
	 pNVA           = (FNVA*)&pMsg[byLHead+byNAdsu];
	 //Addr
	 pNVA->IOA00    = sP.byA0;          
	 pNVA->IOA01    = sP.byA1;
     pNVA->IOA02    = sP.byA2;
	 //Value
	 #ifdef WIN32
	 pNVA->byNvaL   = pD[0];
	 pNVA->byNvaH   = pD[1];
	 pNVA->byNvaH  &= 0x7f;
	 #else
	 pNVA->byNvaL   = pD[1];
	 pNVA->byNvaH   = pD[0];
	 pNVA->byNvaH  &= 0x7f;
	 #endif
	 //DQ
	 pNVA->OV       = 0;
	 pNVA->RES      = 0;
	 pNVA->BL       = 0;
	 pNVA->SB       = 0;
	 pNVA->NT       = 0;
	 pNVA->IV       = 0;
	 byNAdsu        = (i+1)*byLenAdsu;
	}else break;
	}
	byLen = 6+byNAdsu;
	return byLen;
}
void CModule101_CopyW(This,PVOID pvDst,PVOID pvSrc)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
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
BYTE CModule101_CreateCRC(This,BYTE *pMsg,BYTE byLen)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	BYTE i,sum = 0;
	for(i=0;i<=byLen-1;i++)sum += pMsg[i];
	return sum;
}
void CModule101_CModule101(This)
{
    DECLARE_MULTI_OPEN(CModule101,CCyclicSystem) 
	DECLARE_REGISTRATION(CModule101,Init)
	DECLARE_REGISTRATION(CModule101,LoLevelHandler)
	DECLARE_REGISTRATION(CModule101,HiLevelHandler)
	DECLARE_REGISTRATION(CModule101,SendMessage)
	DECLARE_REGISTRATION(CModule101,CreateCRC)
	DECLARE_REGISTRATION(CModule101,AddADSU)
	DECLARE_REGISTRATION(CModule101,AddADSU1)
	DECLARE_REGISTRATION(CModule101,PackADSU)
	DECLARE_REGISTRATION(CModule101,CopyW)
	DECLARE_REGISTRATION(CModule101,GetW)
	DECLARE_REGISTRATION(CModule101,SendBroadcast)
	DECLARE_REGISTRATION(CModule101,AddBroadADSU)
	DECLARE_REGISTRATION(CModule101,Autorisation)
	DECLARE_VIRTUAL_FUNC(CModule101,EventHandler)
	DECLARE_VIRTUAL_FUNC(CModule101,HandleTask)
	DECLARE_VIRTUAL_FUNC(CModule101,GetStateList)
}
void CModule101_DCModule101(This)
{
	DECLARE_MULTI_OPEN(CModule101,CCyclicSystem)
}
DECLARE_MULTI_CREATE(CModule101,CCyclicSystem)

