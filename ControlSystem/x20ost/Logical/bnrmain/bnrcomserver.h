/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __COMSERVER_H__
#define __COMSERVER_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrdebug.h"
#include "bnrcyclicsystem.h"

#ifndef WIN32
//#include <DVFrame.h>
#endif
#ifdef WIN32
void FRM_xopen(FRM_xopen_typ*);
void FRM_close(FRM_close_typ*);
void FRM_gbuf(FRM_gbuf_typ*);
void FRM_rbuf(FRM_rbuf_typ*);
void FRM_robuf(FRM_robuf_typ*);
void FRM_write(FRM_write_typ*);
void FRM_read(FRM_read_typ*);
#endif
#define BUFF_SZ 0x3ff
Class CComServer
{
	 void (*CCComServer)(This);
	 void (*DCComServer)(This);
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
	 BOOL (*MakeTextMessage)(This);
	 void (*ATHandler)(This,USINT *pComm,WORD wLen);
	 BOOL (*CopyMessage)(This,WORD wLen,SMESSAGE *pMsg);
	 BYTE (*CreateCRC)(This,BYTE *pMsg,BYTE byLen);
	 INT (*FindText)(This,SINT *pSrc,SINT *pChar);
	 WORD (*CalckSumm)(This,BYTE *pCH,WORD wLen);
	 void (*SendSMessage)(This,BYTE byBox,BYTE byFor,BYTE byType);
	 BOOL (*Connect)(This);
	 BOOL (*Disconnect)(This);
	 void (*SetPortSett)(This);
	 void (*TestMsg)(This);
     Virtual BOOL (*EventHandler)(This,SMESSAGE *pMsg);
     Virtual void (*CyclicProc)(This); 
Private 
     /*
	 FRM_xopen_typ m_sXOpen; 
     XOPENCONFIG m_sConfig;
     FRM_gbuf_typ m_sFrameBuff;
     FRM_rbuf_typ m_sRBuff;
     FRM_write_typ m_sSend;
	 FRM_read_typ m_sRecc;
	 FRM_close_typ m_sClose;
	 FRM_robuf_typ m_sRobuff;
	 */
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
 
	 USINT m_SendBuffer[300];
	 USINT m_ReadBuffer[300];
	 USINT pb_mBoxDoTextRead[120];
	 //USINT *m_SendBuffer;
	 //USINT *m_ReadBuffer;

	 //BYTE pb_mBoxDoRead[5000];
	 //BYTE pb_mBoxRead[3000];
	 BYTE pb_mBoxCont[BUFF_SZ];
	 WORD w_mBoxSize;
	 WORD w_mBoxCSize;
	 WORD w_mBoxWrite;
	 WORD w_mBoxRead;
	 WORD m_sSize;
     WORD w_lLength;
	 WORD w_lMsgLen;
	 WORD InByteCount_DATA;

	 WORD nWsCount;

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
DECLARE_DEFINITION(CComServer)
#endif
