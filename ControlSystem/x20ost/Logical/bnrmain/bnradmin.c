/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnradmin.h"
#include "bnrpob.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#define SYS_REQ_ALL_PARAM                0x6673 // isf - Авария интерфейса
#define SYS_SET_OUT                      0x746f // iot xxx
#define SYS_SET_OUT_BOX                  0x626f // iob xxx
#define SYS_SET_TST_MSG                  0x6d74 // itm xxx
#define SYS_SET_OUT_DIR                  0x736f // iob xxx
#define SYS_SET_DEV_VER                  0x766f // iov xxx
extern SSOFTSWITCHTABLE nSoftSwitchTable;
extern BOOL *blpValueDI8[];
extern UINT *uipValueAI2[];

extern BOOL *blpAlValueAI2[];
extern BOOL *blAsValueAI[];
//_GLOBAL INT iCAdminVal;
SINT *chAdmState[] = 
{
	"ST00_NULL",
    "ST01_DISC",
	"ST02_CONN",
	"ST03_WAIT_CONF",
	"ST04_SYST_READY",
	"ST05_WAIT_READY",
};
_GLOBAL INT16 wTICode,nSG;
void CAdmin_Init(This)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem)
     #ifdef DEB_CAdmin 
	 Info("\n(__)CADMN::>Create Admin.");
     #endif
	 wTICode = 0;
	 nSG     = 0;
	 //pT->m_blArmState = FALSE;
	 //dwFL  |= DEB_OUT_BOX_ADMIN;
	 //dwFL = 48;
	 pB->SetBoxID(pB,DEV_ADMIN_BOX_ID);
	 pT->m_bySystemState = SYS_ST01_DISC;
	 pT->m_blArmState = TRUE;
}
_GLOBAL UINT nTICHA;
void CAdmin_CyclicProc(This)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem)
	 pB->m_dwAmoutQuant++;
	 
	 if(wTICode>=32000) 
	 nSG = -400; 
	 if(wTICode<=0) 
	 nSG = 400; 
	 
	 //wTICode =  wTICode + nSG;
	 //*uipValueAI2[0] = wTICode;
	 
	 //nTICHA++;
	 //if ((nTICHA % 2)==0)
	 //Info("\n(__)CADMN::>TI:%w",uipValueAI2[0]);
}

void CAdmin_SetSystemID(This,BYTE bySystemID)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	 pT->m_bySystemID = bySystemID;
}  
BOOL CAdmin_EventHandler(This,SMESSAGE *pMsg)
{
	 BOOL res = TRUE;
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	 BYTE byState;
	 byState = pT->GetState(pT);
	 switch (pMsg->m_sbyFor)
	 {
		case MDL_HCOMM:
			 pT->PreCommHandler(pT,pMsg);
		break;
		case MDL_ADMIN:
			 pT->AdminAutomat(pT,pMsg);
		break;
		case MDL_SYSTM:
		break;
		case MDL_DIRMD:
		break;
		case MDL_COMPT:
		break;
		default:
		break;
	 }
	 return res;
}
BOOL CAdmin_AdminAutomat(This,SMESSAGE *pMsg)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	 BOOL res = FALSE;
	 BYTE byEvent = pMsg->m_sbyType;
	 switch(pT->GetState(pT))
	 {
	    case SYS_ST00_NULL:
        break; 
	    case SYS_ST01_DISC:
			 if((byEvent==EV_ADMIN_ARM_CONN_IND))
			 {
              #ifdef DEB_CAdmin 
			  Info("\n(%b)CADMN::>ARM_CONN_IND:%M",&pT->m_bySystemID,(BYTE*)pMsg);
              #endif
			  pT->m_blArmState = TRUE;
              pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_ARM_CONN_IND,0,0);   
			  pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_SYS_CONFIG_IND,0,0); //Запросить конфигурацию
			  pT->m_pTAskConfig.OnTimer(&pT->m_pTAskConfig,T4SEC);
			  pT->SetState(pT,SYS_ST03_WAIT_CONF);			 
			  res = TRUE;
			 }
        break; 
		case SYS_ST02_CONN:
        break; 
	    case SYS_ST03_WAIT_CONF:
			 if(byEvent==EV_ADMIN_ASK_CONF_TIM_IND)
			 {
              #ifdef DEB_CAdmin 
			  Info("\n(%b)CADMN::>ASK_CONF_TIM_IND:%M",&pT->m_bySystemID,(BYTE*)pMsg);
              #endif
			  pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_SYS_CONFIG_IND,0,0); //Запросить конфигурацию
			  pT->m_pTAskConfig.OnTimer(&pT->m_pTAskConfig,T4SEC);
			  res = TRUE;
			 }else
			 if(byEvent==EV_ADMIN_SYS_CONFIG_REQ)
			 {
              #ifdef DEB_CAdmin 
			  Info("\n(%b)CADMN::>SYS_CONFIG_REQ:%M",&pT->m_bySystemID,(BYTE*)pMsg);
              #endif
			  pT->m_pTAskConfig.OfTimer(&pT->m_pTAskConfig);
			  pT->SendMessage(pT,DEV_SYSTM_BOX_ID,MDL_SYSTM,EV_SYSTM_INIT_OBS_REQ,0,0);
			  res = TRUE;
			 }else
			 if(byEvent==EV_SYSTM_INIT_OBS_IND)
			 {
              #ifdef DEB_CAdmin 
			  Info("\n(%b)CADMN::>INIT_OBS_IND:%M",&pT->m_bySystemID,(BYTE*)pMsg);
              #endif
			  Info("\n(%b)CADMN::>B&R System Ready!",&pT->m_bySystemID);
			  pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_SYS_READY_IND,0,0);
			  pT->SetState(pT,SYS_ST04_SYST_READY);
			  res = TRUE;
			 }
			 if(byEvent==EV_ADMIN_ARM_DISC_IND)pT->SetState(pT,SYS_ST01_DISC);			 
        break; 
		case SYS_ST05_WAIT_READY:
			 switch(byEvent)
			 {
			  case EV_ADMIN_TMR_SSTATE_IND:
				   pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_SYS_READY_IND,0,0);       				  
				   pT->m_pTSendState.OnTimer(&pT->m_pTSendState,T4SEC);
			  break;
			  case EV_ADMIN_ARM_READY_REQ:
				   //pT->m_pTSendState->OfTimer(pT->m_pTSendState);
				   pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_SYS_READY_IND,0,0);       				  
				   pT->m_blArmState = TRUE;
				   pT->SetState(pT,SYS_ST04_SYST_READY);
			  break;
			  default:
			  break;
			 }
		break;
	    case SYS_ST04_SYST_READY:
			 switch(byEvent)
			 {
			  case EV_ADMIN_ARM_READY_REQ:
				   pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,EV_ADMIN_SYS_READY_IND,0,0);       				  
			  break;
			  case EV_ADMIN_ARM_DISC_IND:
				   //pT->m_pTSendState->OnTimer(pT->m_pTSendState,T4SEC);
				   pT->SetState(pT,SYS_ST05_WAIT_READY);
				   pT->m_blArmState = FALSE;
			  break;
			  case EV_ADMIN_SET_ALM_HILEV_REQ: //Авария превышения верхнего ав. предела 	68
                   #ifdef DEB_CAdmin 
			       Info("\n(%b)CADMN::>SET_ALM_HILEV_REQ:%M",&pT->m_bySystemID,(BYTE*)pMsg);
                   #endif
			   	   pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,pMsg->m_sbyType,pMsg->m_sbyDirection,pMsg->m_sbySensor);
			  break; 
			  case EV_ADMIN_REM_ALM_HILEV_REQ: //Устранение аварии превышения верхнего ав. предела 	69
                   #ifdef DEB_CAdmin 
			       Info("\n(%b)CADMN::>REM_ALM_HILEV_REQ:%M",&pT->m_bySystemID,(BYTE*)pMsg);
                   #endif
			       pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,pMsg->m_sbyType,pMsg->m_sbyDirection,pMsg->m_sbySensor);
			  break; 
			  case EV_ADMIN_SET_ALM_LOLEV_REQ: //Авария превышения нижнего ав. предела 	70
                   #ifdef DEB_CAdmin 
			       Info("\n(%b)CADMN::>REM_ALM_LOLEV_REQ:%M",&pT->m_bySystemID,(BYTE*)pMsg);
                   #endif
			       pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,pMsg->m_sbyType,pMsg->m_sbyDirection,pMsg->m_sbySensor);
			  break; 
			  case EV_ADMIN_REM_ALM_LOLEV_REQ: //Устранение аварии превышения нижнего ав. предела 	71
                   #ifdef DEB_CAdmin 
			       Info("\n(%b)CADMN::>REM_ALM_LOLEV_REQ:%M",&pT->m_bySystemID,(BYTE*)pMsg);
                   #endif
			       pT->SendMessage(pT,DEV_ARMOT_BOX_ID,MDL_ARMSY,pMsg->m_sbyType,pMsg->m_sbyDirection,pMsg->m_sbySensor);
			  break;
	          case EV_ADMIN_ARM_STOP_REQ:
		           //pT->CloseInterface(pC);
			       //Info("\n(%b)CADMN::>EV_ADMIN_ARM_STOP_REQ:%M",&pT->m_bySystemID,(BYTE*)pMsg);
	       	  break;			  
			 }
        default:
		break;
	 }
	 return res;
}
BOOL CAdmin_SendMessage(This,BYTE byBox,BYTE byFor,BYTE byType,BYTE byDir,BYTE bySens)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	 BOOL res = TRUE;
	 SHORTMESSAGE m_sMsg;
	 m_sMsg.m_swLen        = 9;
	 m_sMsg.m_sbyFrom      = MDL_ADMIN;
	 m_sMsg.m_sbyFor       = byFor;
	 m_sMsg.m_sbyIntType   = DEV_SYS_INTERFACE;
	 m_sMsg.m_sbyServerID  = pT->m_bySystemID;
	 m_sMsg.m_sbyType      = byType;
	 m_sMsg.m_sbyDirection = byDir;
	 m_sMsg.m_sbySensor    = bySens;
	 //if(pT->m_blArmState)
     FPUT(byBox,(BYTE*)&m_sMsg);		 
	 return res;
}
void CAdmin_PreCommHandler(This,SMESSAGE *pMsg)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem)
	 BYTE byLength;
	 DWORD Code;
	 BYTE ps,*pD=(BYTE*)&Code;
     #ifdef DEB_CAdmin 
 	 Info("\n(__)CHAND::>HSYST_O <- %m",pMsg->m_sbyInfo);
     #endif 
	 Code = 0;
	 byLength = pMsg->m_sbyInfo[0];
	 for (ps = 0;ps<byLength;ps++)
	 if ((char)pMsg->m_sbyInfo[ps]==' ') 
	 break;
	 if (ps<=MAX_COMMAND_LENGTH)
	 {
	 #ifdef WIN32
	 memcpy(&Code,&pMsg->m_sbyInfo[2],ps-2);
	 #else
	 pD[3] = pMsg->m_sbyInfo[2];
	 pD[2] = pMsg->m_sbyInfo[3];
	 #endif
	 pT->HandCommHandler(pT,Code,ps,pMsg->m_sbyInfo,byLength);
	 
	 }
}
void CAdmin_HandCommHandler(This,DWORD b_lCode,BYTE ps,BYTE *pbyBuffer,BYTE byLength)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem)
	 SHORTMESSAGE m_sMsg;
	 BYTE byParam0,byParam1;
	 WORD wValue;
	 #ifdef DEB_CAdmin 
	 //Info("\n(##)CHAND::>Code:%d, PS:%b LN:%b MS0:%b",&b_lCode,&ps,&byLength,&pbyBuffer[ps]);
     #endif
	 switch(b_lCode)
	 {
       case SYS_REQ_ALL_PARAM:
		   if (ps<(byLength-1))
		   {
            ps++;
			byParam0=pbyBuffer[ps]-0x30;
		    //Info("\nCHAND::>Command SYS_REQ_ALL_PARAM.Param0:%b",&byParam0);
		   }
	   break;
       case SYS_SET_TST_MSG:// itm xxx
		    if (ps<(byLength-1))
			{
			   ps++;
			   byParam0=pbyBuffer[ps]-0x30;
			   ps++;
			   byParam1=pbyBuffer[ps]-0x30;
               #ifdef DEB_CAdmin 
			   Info("\n(__)CHAND::>SET DIG PIN[%b]:STT[%b]",&byParam0,&byParam1);
			   #endif
			   *blpValueDI8[byParam0] = byParam1;
			   //*blpAlValueAI2[byParam0] = byParam1;
			   //*blAsValueAI = byParam1;
			   //Info("\n(%b)SetPin In %b",&byParam0,&byParam1);
			}
	   break;
       case SYS_SET_OUT://iot 
		   {
		    ps++;
		    if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_CYC_ADMIN;else dwFL &= ~DEB_OUT_CYC_ADMIN;
		    ps++;
		    if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_CYC_SYSTM;else dwFL &= ~DEB_OUT_CYC_SYSTM;
		    ps++;
		    if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_CYC_OBSRV;else dwFL &= ~DEB_OUT_CYC_OBSRV;
			ps++;
			if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_PMAN_STAT;else dwFL &= ~DEB_OUT_PMAN_STAT;
		    Info("\n(__)CHAND::>Out SYS_SET_OUT[%w] ",&dwFL);
		   }
       break;  
       case SYS_SET_OUT_DIR://ios 
		   {
		    ps++;
		    if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_OBSR_COMM;else dwFL &= ~DEB_OUT_OBSR_COMM;
		    ps++;
		    if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_DIRC_COMM;else dwFL &= ~DEB_OUT_DIRC_COMM;
		    Info("\n(__)CHAND::>Out SYS_SET_OUT_DIR[%w] ",&dwFL);
		   }
       break;  
	   case SYS_SET_OUT_BOX: //iob 
		   {
			ps++;
			if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_BOX_ADMIN;else dwFL &= ~DEB_OUT_BOX_ADMIN;
			ps++;
			if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_BOX_SYSTM;else dwFL &= ~DEB_OUT_BOX_SYSTM;
			ps++;
			if((pbyBuffer[ps]-0x30)) dwFL |= DEB_OUT_BOX_OBSRV;else dwFL &= ~DEB_OUT_BOX_OBSRV;
			Info("\n(__)CHAND::>Out SYS_SET_OUT_[%w]",&dwFL);
		   }
	   break;
	   case SYS_SET_DEV_VER:// iov 
           pT->DevVersion(pT) ;
	   break;
	   default:
	   break;
	 };
}
void CAdmin_DevVersion(This)
{
	  DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	  Info("\n/----------------/Automation 2k/---------------------------/");
	  Info("\n/ Объект     :Бобруйский ЗСКГШ............................./");
      #if MYSYSTEM_ID==0
	  Info("\n/ Назначение :Управление параметрами в контуре АС-1......../");
      #elif MYSYSTEM_ID == 1
	  Info("\n/ Назначение :Управление параметрами в контуре АС-2......../");
	  #elif MYSYSTEM_ID == 2
	  Info("\n/ Назначение :Управление параметрами в контуре АС-3......../");
      #elif MYSYSTEM_ID == 3
	  Info("\n/ Назначение :Управление параметрами в контуре КОП........./");
      #elif MYSYSTEM_ID == 4
	  Info("\n/ Назначение :Управление ЧРЭП............................../");
	  #endif
	  Info("\n/ Версия     :[09.09.2009]................................./");
	  Info("\n/ Устройство :Контроллер B&R 2005........................../");
	  Info("\n/ Разработчик:Абраменя Александр Васильевич(2009г)........./");
	  Info("\n/ Тел/mail   :(8-029-563-76-78/alex_mpowt@tut.by)........../");
	  Info("\n/----------------------------------------------------------/");	 
}
void CAdmin_SetState(This,BYTE byState)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
     #ifdef DEB_CAdmin 
	 Info("\n(%b)CADMN::>State:(%s)->(%s):",&pT->m_bySystemID,chAdmState[pT->m_bySystemState],chAdmState[byState]);
     #endif	
     pT->m_bySystemState = byState;
} 
BYTE CAdmin_GetState(This)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	 return pT->m_bySystemState;
}
void CAdmin_CAdmin(This)
{
     DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem) 
	 DECLARE_REGISTRATION(CAdmin,Init)
	 DECLARE_REGISTRATION(CAdmin,SendMessage)
	 DECLARE_REGISTRATION(CAdmin,HandCommHandler)
	 DECLARE_REGISTRATION(CAdmin,PreCommHandler)
	 DECLARE_REGISTRATION(CAdmin,SetSystemID)
	 DECLARE_REGISTRATION(CAdmin,SetState)
	 DECLARE_REGISTRATION(CAdmin,GetState)
	 DECLARE_REGISTRATION(CAdmin,AdminAutomat)
	 DECLARE_REGISTRATION(CAdmin,DevVersion)
	 DECLARE_VIRTUAL_FUNC(CAdmin,CyclicProc)
	 DECLARE_VIRTUAL_FUNC(CAdmin,EventHandler)
	 InitObject(CMTimer,&pT->m_pTAskConfig);
     pT->m_pTAskConfig.SetTimer(&pT->m_pTAskConfig,MDL_ADMIN,MDL_ADMIN,EV_ADMIN_ASK_CONF_TIM_IND,0,0,DEV_ADMIN_BOX_ID);
	 InitObject(CMTimer,&pT->m_pTSendState);
     pT->m_pTSendState.SetTimer(&pT->m_pTSendState,MDL_ADMIN,MDL_ADMIN,EV_ADMIN_TMR_SSTATE_IND,0,0,DEV_ADMIN_BOX_ID);
}
void CAdmin_DCAdmin(This)
{
	 DECLARE_MULTI_OPEN(CAdmin,CCyclicSystem)
}
DECLARE_MULTI_CREATE(CAdmin,CCyclicSystem)

