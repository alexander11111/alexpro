/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrobsys.h"
#include "bnrmain.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
_GLOBAL BYTE nFSignal;
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
char *CmpInfoSYS[]  =
{
    "==",  //JE
    "!=",  //JNE
    ">",   //JA
    "<=",  //JBE
};
char *StateInfoSYS[]  =
{
    "NULL_ST00",
	"WAIT_OPER_ST01",
	"OPER_ST02",
	"WAIT_STOP_ST03",
};
char *ValInfoSYS[]  =
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
	"STATE",
};
IMPORT_TASKCHAIN(Skip);
IMPORT_STATE(BadState);
DECLARE_TASKCHAIN(TS_EV_START_WSY_ST00)
{
	//CMD_SEND,PH_CONN_IND,DIR_101TOKP,
	CMD_START_FC,
	//CMD_SETVALUE,ACD,0,
	CMD_TIMERON,TMR_WTOP,
	CMD_SETSTATE,MWSY_WAIT_OPER_ST01, 
	EXIT_D,
};
DECLARE_TASKCHAIN(TS_EV_HAND_STOP_WSY_ST00)
{
	CMD_STOP_FC,
	CMD_STOP_PU,
	CMD_STOP_CT,
	CMD_TIMEROFF,TMR_WTOP,
	CMD_TIMEROFF,TMR_OPER,
	CMD_TIMEROFF,TMR_WTST,
	CMD_SETSTATE,MWSY_NULL_ST00, 
	EXIT_D,
};
//ST_01///////////////////////////////////////
DECLARE_TASKCHAIN(TS_EV_TMR_WTOP_ST01)
{
	CMD_START_PU,
	CMD_START_CT,
	CMD_TIMERON,TMR_OPER,
	CMD_SETSTATE,MWSY_OPER_ST02, 
	EXIT_D,
};
//ST_02///////////////////////////////////////
DECLARE_TASKCHAIN(TS_EV_TMR_OPER_ST02)
{
	CMD_STOP_PU,
	CMD_TIMERON,TMR_WTST,
    CMD_SETSTATE,MWSY_WAIT_STOP_ST03, 
	EXIT_D,
};
DECLARE_TASKCHAIN(TS_EV_CT_OFF_ST02)
{
	CMD_STOP_CT,
	CMD_STOP_PU,
	CMD_STOP_FC,
	CMD_TIMERON,TMR_WTST,
	CMD_SETSTATE,MWSY_WAIT_STOP_ST03, 
	EXIT_D,
};
//ST_03///////////////////////////////////////
DECLARE_TASKCHAIN(TS_EV_TMR_WTST_ST03)
{
	CMD_STOP_FC,
	CMD_SETSTATE,MWSY_NULL_ST00, 
	EXIT_D,
};
DECLARE_STATE(ST_MWSY_NULL_ST00)
{
	{ EV_START_WSY_REQ,         TS_EV_START_WSY_ST00 },
	{ EV_HAND_START_WSY_REQ,    TS_EV_TMR_WTOP_ST01 },
	{ EV_HAND_STOP_WSY_REQ,     TS_EV_HAND_STOP_WSY_ST00 },
    { EV_UNKNOWN_REQ,           Skip               }
};
DECLARE_STATE(ST_MWSY_WAIT_OPER_ST01)
{
    { EV_TMR_WTOP_REQ,          TS_EV_TMR_WTOP_ST01  },
	{ EV_HAND_STOP_WSY_REQ,     TS_EV_HAND_STOP_WSY_ST00 },
    { EV_UNKNOWN_REQ,           Skip               }
};
DECLARE_STATE(ST_MWSY_OPER_ST02)
{
    { EV_TMR_OPER_REQ,          TS_EV_TMR_OPER_ST02  },
    { EV_CT_OFF_REQ,            TS_EV_CT_OFF_ST02  },
	{ EV_HAND_STOP_WSY_REQ,     TS_EV_HAND_STOP_WSY_ST00 },
    { EV_UNKNOWN_REQ,           Skip               }
};
DECLARE_STATE(ST_MWSY_WAIT_STOP_ST03)
{
    { EV_TMR_WTST_REQ,          TS_EV_TMR_WTST_ST03  },
	{ EV_HAND_STOP_WSY_REQ,     TS_EV_HAND_STOP_WSY_ST00 },
    { EV_UNKNOWN_REQ,           Skip               }
};
DECLARE_STATELIST(STL_OSY_PROT)
{
    { MWSY_NULL_ST00,           ST_MWSY_NULL_ST00 },
	{ MWSY_WAIT_OPER_ST01,      ST_MWSY_WAIT_OPER_ST01 },
	{ MWSY_OPER_ST02,           ST_MWSY_OPER_ST02 },
	{ MWSY_WAIT_STOP_ST03,      ST_MWSY_WAIT_STOP_ST03 },
    { S_BAD,                    BadState       }
};
_GLOBAL WORD wglValue;
BOOL CObsSys_HandleTask(This,TTask* pTask)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
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
         case CMD_INCC:
			  pB->v[*(++pTask)]++;
			  pB->v[*pTask] &= 0x01; 
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>INCC::%s=%b",&pT->m_byModuleID,ValInfoSYS[*pTask],&pB->v[*pTask]);
              #endif
		 break;
	  	 case CMD_SETSTATE:
			  V1 = *(++pTask);
			  //if(*pTask==STATE_101) V1 = pB->v[STATE_101];
			  pB->SetState(pB,V1);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>STAT::%s->%s ",&pT->m_byModuleID,StateInfoSYS[pB->v[STATE_WSY]],StateInfoSYS[V1]);
			  //Info("\n(%b)CWSYS[%b]::>STAT:/--------New--------/",&pT->m_bySystemID,&pT->m_bySensorID);
              #endif
			  pB->v[STATE_WSY] = V1;
         break;
		 case CMD_SEND:
			  V0 = *(++pTask);
			  V1 = *(++pTask);
			  //pT->SendMessage(pT,V0,V1);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>SEND::[%b][%b]",&pT->m_byModuleID,&V0,&V1);
              #endif
		 break;
		 case CMD_SETVALUE:
			  V0 = *(++pTask);
			  pB->v[V0] = *(++pTask);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>SETV::%s=%b",&pT->m_byModuleID,ValInfoSYS[V0],&pB->v[V0]);
              #endif
		 break;
		 case CMD_MOV:
			  V1 = *(++pTask);
			  pB->v[V1] = pB->v[*(++pTask)];
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>MOVV::%s<-%s",&pT->m_byModuleID,ValInfoSYS[*(pTask-1)],ValInfoSYS[*pTask]);
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
               #ifdef DEB_CObsSys
               Info("\n(%b)COBSY::>CMPV::%s%s%s",&pT->m_byModuleID,ValInfoSYS[*(pTask-3)],CmpInfoSYS[SIGN+byLoop],ValInfoSYS[*(pTask-1)]);
               #endif
               if(byLoop==0) pTask = p_EvArr+LBL-1;
		 break;
		 case CMD_TIMERON:
			  V0 = *(++pTask);//Timer ID
			  //V1 = *(++pTask);//Time
			  pB->m_nATmr[V0].OnTimer(&pB->m_nATmr[V0],pB->m_dwTM[V0]);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>TMON::[%b][%b]",&pT->m_byModuleID,&V0,&pB->m_dwTM[V0]);
	          #endif
		 break;
		 case CMD_TIMEROFF:
			  V0 = *(++pTask);
			  pB->m_nATmr[V0].OfTimer(&pB->m_nATmr[V0]);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>TMOF::[%b]",&pT->m_byModuleID,&V0);
              #endif
		 break;
		 case CMD_STOP_FC:
			  pT->StopFC(pT);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>STOP_FC",&pT->m_byModuleID);
              #endif
		 break;
		 case CMD_START_FC:
			  pT->StartFC(pT);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>START_FC",&pT->m_byModuleID);
              #endif
		 break;
		 case CMD_STOP_PU:
			  pT->StopPU(pT);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>STOP_PU",&pT->m_byModuleID);
              #endif
		 break;
		 case CMD_START_PU:
			  pT->StartPU(pT);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>START_PU",&pT->m_byModuleID);
              #endif
		 break;
		 case CMD_STOP_CT:
			  pT->StopCT(pT);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>STOP_CT",&pT->m_byModuleID);
              #endif
		 break;
		 case CMD_START_CT:
			  pT->StartCT(pT);
              #ifdef DEB_CObsSys
			  Info("\n(%b)COBSY::>START_CT",&pT->m_byModuleID);
              #endif
		 break;
		 default:
		 break;
	  };
	}
	return TRUE;
}
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
	WORD wTMStart;
	WORD wJTMWait;
	WORD wTMWait;
}SOBSMDATA;
/*
//Состояния модуля проливной 
#define MWSY_NULL_ST00               0 
#define MWSY_WAIT_OPER_ST01          1 
#define MWSY_OPER_ST02               2 
#define MWSY_WAIT_STOP_ST03          3

  //Сообщения пролива
#define EV_START_WSY_REQ             _KPMOD_SHIFT + 76 //Запуск модуля
#define EV_HAND_STOP_WSY_REQ         _KPMOD_SHIFT + 77 //Ручной останов
#define EV_HAND_START_WSY_REQ        _KPMOD_SHIFT + 78 //Ручной старт
#define EV_TMR_WTOP_REQ              _KPMOD_SHIFT + 79 //Таймер Ожидания Операционного режима
#define EV_TMR_OPER_REQ              _KPMOD_SHIFT + 80 //Таймер Операционного режима
#define EV_TMR_WTST_REQ              _KPMOD_SHIFT + 81 //Таймер Ожидания Успокоения Жидкости
*/
void CObsSys_InitTCHN(This,PVOID psTable)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	CSlot *pSL;
	CComputer *pCM = pB->m_pComputer;
	pT->pP = (SOBSPARAM*)psTable;
	pB->m_nSize = sizeof(DWORD)+6*sizeof(WORD);

	pB->m_pStateList  = STL_OSY_PROT;
    pB->m_byAutoState = MWSY_NULL_ST00;
	pB->SetState(pB,MWSY_NULL_ST00);
	InitObject(CMTimer,&pB->m_nATmr[TMR_WTOP]);
	InitObject(CMTimer,&pB->m_nATmr[TMR_OPER]);
	InitObject(CMTimer,&pB->m_nATmr[TMR_WTST]);
	pT->m_byModuleID  = pT->pP->byID;
	pB->v[STATE_WSY]  = MWSY_NULL_ST00; 
    //void (*SetTimer)(This,BYTE byFor,BYTE byFrom,BYTE byEvent,BYTE byDir,BYTE bySens,BYTE byBox);

	pB->m_nATmr[TMR_WTOP].SetTimer(&pB->m_nATmr[TMR_WTOP],DIR_OSYTOOSY,DIR_OSYTOOSY,EV_TMR_WTOP_REQ,0,pT->pP->byID,DEV_MSMDL_BOX_ID);
	pB->m_dwTM[TMR_WTOP] = 10*pT->pP->sDT.wJTMPreStart;

	pB->m_nATmr[TMR_OPER].SetTimer(&pB->m_nATmr[TMR_OPER],DIR_OSYTOOSY,DIR_OSYTOOSY,EV_TMR_OPER_REQ,0,pT->pP->byID,DEV_MSMDL_BOX_ID);
	pB->m_dwTM[TMR_OPER] = 10*pT->pP->sDT.wJTMStart;
	
	pB->m_nATmr[TMR_WTST].SetTimer(&pB->m_nATmr[TMR_WTST],DIR_OSYTOOSY,DIR_OSYTOOSY,EV_TMR_WTST_REQ,0,pT->pP->byID,DEV_MSMDL_BOX_ID);
	pB->m_dwTM[TMR_WTST] = 10*pT->pP->sDT.wJTMWait;
    
	//pB->HandleEvent(pB,pMsg->m_sbyType);
    #ifdef DEB_CObsSys
	//Info("\n(%b)CTLSG::>Create TeleSignal.",&pB->m_byID);
    #endif
}
TStateList* CObsSys_GetStateList(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	return pB->m_pStateList;
}
void CObsSys_PreProc(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
}
_GLOBAL INT nTSCH;
void CObsSys_Processing(This)
{
	DECLARE_MULTI_OPEN(CObsSys,CDevice)
}
void CObsSys_PostProc(This)
{
	DECLARE_MULTI_OPEN(CObsSys,CDevice)
}
BOOL CObsSys_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice) 
    #ifdef DEB_CObsSys
	Info("\n(%b)CTLSG::>INPT::%M",&pB->m_nCD.wDeviceID,pMsg);
    #endif
	switch(pMsg->m_sbyFor)
	{
	  case DIR_MSTODV:
		   switch(pMsg->m_sbyType)
		   {
		    case PL_DATA_IND:
                 switch(pB->m_nCD.byParam0)
				 {
				   case CTR_TR:
                        switch (pB->m_nCD.byParam1)
					    {
						  case 0: 
							   pT->pP->sDT.wJTMPreStart = (WORD)(pB->m_nCD.fParam0);
							   pB->m_dwTM[TMR_WTOP] = 10*pT->pP->sDT.wJTMPreStart;
						  break;
						  case 1:
							   pT->pP->sDT.wJTMStart = (WORD)(pB->m_nCD.fParam0);
							   pB->m_dwTM[TMR_OPER] = 10*pT->pP->sDT.wJTMStart;
						  break;
						  case 2:
							   pT->pP->sDT.wJTMWait = (WORD)(pB->m_nCD.fParam0);
							   pB->m_dwTM[TMR_WTST] = 10*pT->pP->sDT.wJTMWait;
						  break;
						  default:
						  break;
					    }				   
				   break;
                   case CTR_TU:
                         switch (pB->m_nCD.byParam1)
					    {
						  case 0: 
							   if (pB->m_nCD.wParam0==0) pT->RemMask(pT,MS_IS_AUST);else  //Признак Автостарта
							   if (pB->m_nCD.wParam0==1) pT->SetMask(pT,MS_IS_AUST);      //Признак Автостарта
						  break;
						  case 1:
							   //Признак работы на весы
							   if (pB->m_nCD.wParam0==0) 
							   {
								pT->RemMask(pT,MS_IS_WGHT);
                                pT->pPU0->ClosePU(pT->pPU0);
                                pT->pPU1->ClosePU(pT->pPU1);
							   }
							   if (pB->m_nCD.wParam0==1) pT->SetMask(pT,MS_IS_WGHT);//Признак работы на весы
						  break;
						  case 2:
							   if (pB->m_nCD.wParam0==1) pT->SetMask(pT,MS_CM_AUST);//Автостарт с продувкой
							   pT->RemMask(pT,MS_CM_HSTP);
							   pT->RemMask(pT,MS_CM_FNSH);
							   if (pT->pP->sDT.wSt0 & MS_IS_AUST)    pB->HandleEvent(pB,EV_START_WSY_REQ); else
							   if (!(pT->pP->sDT.wSt0 & MS_IS_AUST)) pT->StartFC(pT);
						  break;
						  case 3:
							   if (!(pT->pP->sDT.wSt0 & MS_CM_AUST)) break;
							   if (pB->m_nCD.wParam0==1) pT->SetMask(pT,MS_CM_HNST);//Ручной Старт начала счета
							   if (!(pT->pP->sDT.wSt0 & MS_IS_AUST)) 
							   {
								 pT->RemMask(pT,MS_CM_AUST);
								 pB->HandleEvent(pB,EV_HAND_START_WSY_REQ);	
							   }
							   pT->RemMask(pT,MS_CM_HSTP);
						  break;
						  case 4:
							   if (pB->m_nCD.wParam0==1) pT->SetMask(pT,MS_CM_HSTP);//Ручной Стоп установки с АРМ
							   pT->RemMask(pT,MS_CM_AUST);
							   pT->RemMask(pT,MS_CM_HNST);
							   pT->RemMask(pT,MS_CM_FNSH);
							   pB->HandleEvent(pB,EV_HAND_STOP_WSY_REQ);	   
						  break;
  					      default:
						  break;
					    }				   
				   break;
				   default:
				   break;
				 }
		    break;  
			default:
			 //pB->HandleEvent(pB,pMsg->m_sbyType);
            break;  
		   }
      break;
	  case DIR_OSYTOOSY:
		   switch (pMsg->m_sbyType)
		   {
		    case EV_TMR_WTOP_REQ:
				 pT->RemMask(pT,MS_CM_AUST);
				 pT->SetMask(pT,MS_CM_HNST);
			break;
		    case EV_TMR_OPER_REQ:
				 pT->RemMask(pT,MS_CM_AUST);
			break;
		    case EV_TMR_WTST_REQ:
				 pT->RemMask(pT,MS_CM_AUST);
				 pT->RemMask(pT,MS_CM_HNST);
				 pT->SetMask(pT,MS_CM_FNSH);
			break;
		   }
           pB->HandleEvent(pB,pMsg->m_sbyType);	   
	  break;
	  default:
	  break;
	}
	return TRUE;
}
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
	WORD wTMStart;
	WORD wJTMWait;
	WORD wTMWait;
}SOBSMDATA;
*/
void CObsSys_StopPU(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	if (pT->pP->sDT.wSt0 & MS_IS_WGHT)
	{
	 pT->pPU0->StopPU(pT->pPU0);
     pT->pPU1->StopPU(pT->pPU1);
	}
}
void CObsSys_StartPU(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	if (pT->pP->sDT.wSt0 & MS_IS_WGHT)
	{
	 pT->pPU0->StartPU(pT->pPU0);
     pT->pPU1->StartPU(pT->pPU1);
	}
}
void CObsSys_StopFC(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	pT->pF0->StopFC(pT->pF0);
	pT->pF1->StopFC(pT->pF1);
	pT->pF2->StopFC(pT->pF2);
}
void CObsSys_StartFC(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	pT->pF0->StartFC(pT->pF0);
	pT->pF1->StartFC(pT->pF1);
	pT->pF2->StartFC(pT->pF2);
}
void CObsSys_SetMask(This,DWORD dwMask)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	pT->pP->sDT.wSt0 |= dwMask; 
}
void CObsSys_RemMask(This,DWORD dwMask)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	pT->pP->sDT.wSt0 &= ~dwMask; 
}
void CObsSys_StopCT(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)

}
void CObsSys_StartCT(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)

}

BOOL CObsSys_SendMessage(This,BYTE byMsgType,BYTE byFor)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	switch(byFor)
	{
	  case DIR_101TOPH:
		   switch(byMsgType)
		   {
		     case PH_DATA1_RES:

			 break;
		   }
	  break;
	}
    return TRUE;
}
PVOID CObsSys_GetData(This,BYTE *pData,WORD *nLen)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice)
	pT->pP->sDT.wTMPreStart = (WORD)(pB->m_nATmr[TMR_WTOP].GetTime(&pB->m_nATmr[TMR_WTOP])/10);
    pT->pP->sDT.wTMStart    = (WORD)(pB->m_nATmr[TMR_OPER].GetTime(&pB->m_nATmr[TMR_OPER])/10);
    pT->pP->sDT.wTMWait     = (WORD)(pB->m_nATmr[TMR_WTST].GetTime(&pB->m_nATmr[TMR_WTST])/10);
	pB->GetDWordParam(pB,(BYTE*)&pT->pP->sDT.wSt0,&pData[0]);
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJTMPreStart,&pData[4]);	
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wTMPreStart,&pData[6]);	
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJTMStart,&pData[8]);	
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wTMStart,&pData[10]);	
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wJTMWait,&pData[12]);	
	pB->GetWordParam(pB,(BYTE*)&pT->pP->sDT.wTMWait,&pData[14]);	
	*nLen += pB->m_nSize;if (*nLen>350) *nLen=0;
	return pData;
}
void CObsSys_CObsSys(This)
{
    DECLARE_MULTI_OPEN(CObsSys,CDevice) 
	DECLARE_REGISTRATION(CObsSys,SendMessage)
	DECLARE_REGISTRATION(CObsSys,StopPU)
	DECLARE_REGISTRATION(CObsSys,StartPU)
	DECLARE_REGISTRATION(CObsSys,StopFC)
	DECLARE_REGISTRATION(CObsSys,StartFC)
	DECLARE_REGISTRATION(CObsSys,StopCT)
	DECLARE_REGISTRATION(CObsSys,StartCT)
	DECLARE_REGISTRATION(CObsSys,SetMask)
	DECLARE_REGISTRATION(CObsSys,RemMask)
	DECLARE_VIRTUAL_FUNC(CObsSys,EventHandler)
	DECLARE_VIRTUAL_FUNC(CObsSys,InitTCHN)
	DECLARE_VIRTUAL_FUNC(CObsSys,PreProc)
	DECLARE_VIRTUAL_FUNC(CObsSys,Processing)
	DECLARE_VIRTUAL_FUNC(CObsSys,PostProc)
	DECLARE_VIRTUAL_FUNC(CObsSys,GetData)
	DECLARE_VIRTUAL_FUNC(CObsSys,HandleTask)
	DECLARE_VIRTUAL_FUNC(CObsSys,GetStateList)
}
void CObsSys_DCObsSys(This)
{
	DECLARE_MULTI_OPEN(CObsSys,CDevice)
}
DECLARE_MULTI_CREATE(CObsSys,CDevice)

