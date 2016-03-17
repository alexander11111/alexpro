/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __COMVS0_H__
#define __COMVS0_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrdebug.h"
#include "bnrcyclicsystem.h"

#ifndef WIN32
//#include <DVFrame.h>
#endif
#define BUFF_SZ_VS0 0x3ff
Class CComVS0
{
	 void (*CCComVS0)(This);
	 void (*DCComVS0)(This);
Public
     //Connection Disconnection Procedure 
     void (*Init)(This,SARMINTERFACE *pArm);
Private     
	 void (*Close)(This);
     void (*InitSRV)(This);
	 void (*Enable)(This);
	 void (*Disable)(This);
	 BOOL (*Open)(This);
     BOOL (*SendMessage)(This,SMESSAGE *pMsg);
	 BOOL (*GetMessage)(This,SMESSAGE *pMsg);
	 void (*ReceiveThread)(This);
	 void (*SendThread)(This);
	 void (*SynBuff)(This);
	 BOOL (*MakeMsgData)(This,SMESSAGE *pMsg);
	 BOOL (*CopyMessage)(This,WORD wLen,SMESSAGE *pMsg);
	 BYTE (*CreateCRC)(This,BYTE *pMsg,BYTE byLen);
	 void (*SendSMessage)(This,BYTE byBox,BYTE byFor,BYTE byType);
	 BOOL (*Connect)(This);
	 BOOL (*Disconnect)(This);
	 void (*SetPortSett)(This);
     Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This); 
Private 
	 SINT m_chStringDevice[50];
     SINT m_chStringMode[50];
	 SINT m_chStringNewMode[50];
     UINT m_StatusOpen;
	 UINT m_StatusClose;
	 UINT m_StatusWrite;
	 UINT m_StatusRead;
	 UINT m_StatusGetBuffer;
	 UINT m_StatusReleaseBuffer;
	 UINT m_StatusReleaseOutputBuffer;
	 UINT m_SendBufferLength;
	 UINT m_ReadBufferLength;
	 UINT m_Error;
	 UINT w_lMsgLen;
 
	 USINT m_SendBuffer[300];
	 USINT m_ReadBuffer[300];
	 USINT pb_mBoxDoTextRead[120];
	 BYTE pb_mBoxCont[BUFF_SZ_VS0];
	 WORD w_mBoxSize;
	 WORD w_mBoxCSize;
	 WORD w_mBoxWrite;
	 WORD w_mBoxRead;
	 WORD m_sSize;
     WORD w_lLength;
	 WORD InByteCount_DATA;

	 BYTE m_byType;
	 BYTE m_byRate;
	 BOOL m_blMsgFind;
     STCPADDR m_stTcpAddr;  
	 BYTE m_bSrvState;
	 BYTE m_bCliState;
	 SMESSAGE m_sMsg;
	 CMTimer m_nConnTMR;
	 SARMINTERFACE *m_pArm;
	 DECLARE_IMPLEMENT_BASE(CCyclicSystem)
}
DECLARE_DEFINITION(CComVS0)
#endif
