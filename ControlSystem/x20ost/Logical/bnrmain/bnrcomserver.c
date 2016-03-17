/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrcomserver.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
//extern SINT *chPortType[];
//extern SINT *chPortRate[];
extern WORD m_wPhoneKey;
extern char StrPhone[50];
/*
DEV_ARM_PORT_TCP=0,
DEV_ARM_PORT_UDP,
DEV_ARM_PORT_COM232,
DEV_ARM_PORT_COM458,
DEV_ARM_PORT_USB,
DEV_SYS_INTERFACE,
*/
SINT *chPortType[] = 
{
	"TCP",
	"UDP",
	"RS232",
	"RS485",
	"USB",
};
SINT *chPortRate[] = 
{
    "9600",
    "14400",
    "38400",
    "57600",
    "115200",
};
SINT *chPortParity[] = 
{
    "N",
	"E",
	"O",
};
SINT *chPortData[] = 
{
    "7",
	"8",
};
SINT *chPortStop[] = 
{
    "1",
    "1.5",
    "2",
};
SINT *chTest = {"000=1.23000=2.30400=5.60005=192.10000=12334.20001=423.20001=4342.20"};
///char test={'000=0.00000=0.00000=0.00000=0.00000=0.00000=0.}
_GLOBAL UINT node_nr;
_GLOBAL UDINT status;
_GLOBAL CANopen_typ CANopen_01;
_GLOBAL CANnode_typ CANnode_01;
_GLOBAL  FRM_xopen_typ m_sXOpen; 
_GLOBAL      XOPENCONFIG m_sConfig;
_GLOBAL      FRM_gbuf_typ m_sFrameBuff;
_GLOBAL      FRM_rbuf_typ m_sRBuff;
_GLOBAL      FRM_write_typ m_sSend;
_GLOBAL 	 FRM_read_typ m_sRecc;
_GLOBAL 	 FRM_close_typ m_sClose;
_GLOBAL 	 FRM_robuf_typ m_sRobuff;
#ifndef WIN32
_GLOBAL      FRM_mode_typ FrameModeStruct;
#endif
//USINT m_SendBuffer[300];
	 //USINT m_ReadBuffer[300];
#ifdef WIN32
#define  START_BYTE   0x7E
#define  STOP_BYTE    0xE7
#define  INVERSE_BYTE 0x55
CComServer *m_nCommServer;
BYTE m_byReadBuffer[300];
BYTE m_bySendBuffer[300];
HANDLE hCom;
OVERLAPPED  osReceive, osSend, osOverlap,osOverlapR;
COMSTAT  csStat;
HANDLE  hSendThread,hSendMsgThread,hReceiveThread,hMakeThread;
HANDLE  WaitEvents[2],evMake;
DWORD   dSendThreadId,dMakeThreadId,dSendMsgThreadId,dReceiveThreadId;
DWORD   dwThrdParam;
void RxCharProc(void);
static DWORD WINAPI SendRsThread(LPVOID lpCComm);
static DWORD WINAPI SendMsgThread(LPVOID lpCComm);
static DWORD WINAPI MakeThread(LPVOID lpCComm);
BOOL OpenPort(char *szComPort, DWORD dwBaud);
BOOL StartPort(char *szPortStr,DWORD dwBaud);
BOOL OpenPort(char *szComPort, DWORD dwBaud)
{
	DCB     dcb;
	COMMTIMEOUTS  ctCom;
	LPSTR lpMsgBuf;
	char  S[100];
	memset(&dcb,0,sizeof(DCB));
	dcb.DCBlength = sizeof(DCB);
    hCom = CreateFile(szComPort,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_FLAG_OVERLAPPED,
		NULL);
    if (hCom == INVALID_HANDLE_VALUE)
		// ошибка открытия порта
    {
        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            GetLastError(),
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL
			);
        strcpy(S, "Error Opening. ");
        strcat(S, lpMsgBuf);
		printf("\n(__)Com::>%s",S);
		//Info("\n(__)Com::>%s",);
        //MessageBox(NULL, S, "RS232.Open", MB_OK);
        LocalFree( lpMsgBuf );
        return FALSE;
    }
    if (!GetCommState(hCom, &dcb))
		// ошибка получения параметров DCB
    {
        //MessageBox(NULL," Ошибка получения параметров DCB", "RS232.Open", MB_OK);
		printf("\n(__)Com::>Error Get Patrameters DCB");
        CloseHandle(hCom);
        return FALSE;
    }
    dcb.BaudRate = dwBaud;
    dcb.ByteSize = 8;
    dcb.Parity   = NOPARITY;
	//dcb.Parity   = EVENPARITY;
    dcb.StopBits = ONESTOPBIT;
	dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
	dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
    //dcb.EvtChar  = (CHAR)STOP_BYTE;
    if (!SetCommState(hCom, &dcb))
		// ошибка установки параметров DCB
    {
        //MessageBox(NULL," Ошибка установки параметров DCB", "RS232.Open", MB_OK);
		printf("\n(__)Com::>Error Create State DCB");
        CloseHandle(hCom);
        return FALSE;
    }
    ctCom.ReadIntervalTimeout = 10;
    ctCom.ReadTotalTimeoutMultiplier  = ctCom.ReadTotalTimeoutConstant  = 1;
    ctCom.WriteTotalTimeoutMultiplier = ctCom.WriteTotalTimeoutConstant = 1;
    if (!SetCommTimeouts(hCom, &ctCom))
		// ошибка установки параметров COMMTIMEOUTS
    {
        //MessageBox(NULL," Ошибка установки параметров COMMTIMEOUTS", "RS232.Open", MB_OK);
		printf("\n(__)Com::>Error DCB");
        CloseHandle(hCom);
        return FALSE;
    }
    //if (!SetCommMask(hCom, EV_RXCHAR|EV_TXEMPTY))
	if (!SetCommMask(hCom, EV_TXEMPTY))
		//    if (!SetCommMask(hCom, EV_BREAK | EV_RXCHAR))
		// ошибка установки маски событий
    {
		printf("\n(__)Com::>Error Create Mask Events");
        CloseHandle(hCom);
        return FALSE;
    }
    PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);
    // COM-порт успешно открыт и инициализирован
    return TRUE;
}
BOOL StartPort(char *szPortStr,DWORD dwBaud)
{
	if (OpenPort(szPortStr, dwBaud) != TRUE)
	{
		return FALSE;
	}
	if ((osOverlap.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL)) == NULL)
	{
		printf("\n(__)Com::> Error Create osOverlap.hEvent");
		return FALSE;
	}

	if ((osReceive.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL)) == NULL)
	{
		printf("\n(__)Com::> Error Create osReceive.hEvent");
		return FALSE;
	}
	if ((osSend.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL)) == NULL)
	{
		printf("\n(__)Com::> Error Create osSend.hEvent");
		return FALSE;
	}
	if ((evMake = CreateEvent(NULL, FALSE, FALSE, NULL)) == NULL)
	{
		printf("\n(__)Com::> Error Create evMake");
		return FALSE;
	}
	if ((hMakeThread = CreateThread(NULL,0,MakeThread,&dwThrdParam,0,&dMakeThreadId)) == NULL)
	{
		printf("\n(__)Com::> Error Create hMakeThread"); 
		return FALSE;
	}
	if ((hSendThread = CreateThread(NULL,0,SendRsThread,&dwThrdParam,0,&dSendThreadId)) == NULL)
	{
		printf("\n(__)Com::> Error Create hReceiveThread"); 
		return FALSE;
	}

	if ((hSendMsgThread = CreateThread(NULL,0,SendMsgThread,&dwThrdParam,0,&dSendMsgThreadId)) == NULL)
	{
		printf("\n(__)Com::> Error Create hSensMsgThread"); 
		return FALSE;
	}
	SetThreadPriority(hSendThread, THREAD_PRIORITY_HIGHEST);
	SetThreadPriority(hSendMsgThread, THREAD_PRIORITY_NORMAL);
	SetThreadPriority(hMakeThread, THREAD_PRIORITY_NORMAL);
	ResumeThread(hSendThread);
	ResumeThread(hSendMsgThread);
	ResumeThread(hMakeThread);
	return TRUE;
}
void ClosePort(void)
{
    if (hCom != INVALID_HANDLE_VALUE)
    {
      CloseHandle(hCom);
      hCom = INVALID_HANDLE_VALUE;
    }
}
DWORD WINAPI SendMsgThread(LPVOID lpCComm)
{
    while(1)
    {
      m_nCommServer->SendThread(m_nCommServer);
	  Sleep(100);
    }
}
DWORD WINAPI SendRsThread(LPVOID lpCComm)
{
	DWORD dwMask,dwBytesTrans;
	//SMESSAGE mMsg;
	while(1)
	{
      //printf("\n(__)Com::>SendRsThread"); 
	  WaitCommEvent(hCom,&dwMask,&osOverlap);
	  //switch (WaitForSingleObject(osOverlap.hEvent,INFINITE))
	  switch (WaitForSingleObject(osOverlap.hEvent,5000))
	  {
	    case WAIT_OBJECT_0:
			 if (GetOverlappedResult(hCom,&osOverlap,&dwBytesTrans,TRUE))
			 {
               if (dwMask&EV_TXEMPTY)
               {
                //printf("\n(__)Com::>EV_TXEMPTY");
				m_sSend.status = 0;
				m_nCommServer->m_StatusWrite = 0;
               }
			   if (dwMask&EV_RXCHAR)
               {
				//printf("\n(__)Com::>EV_RXCHAR");
				//m_nCommServer->ReceiveThread(m_nCommServer);
				//RxCharProc();
               }
			 }
	  	break;
		case WAIT_TIMEOUT:
			 m_sSend.status = 0;
			 m_nCommServer->m_StatusWrite = 0;
			 PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);
			 //printf("\n(__)Com::>TX:WAIT_TIMEOUT"); 
		break;
	  }
	  //Sleep(1);
	}
}
void FRM_xopen(FRM_xopen_typ *pType)
{
    StartPort("COM4",1200); 
};
void FRM_close(FRM_close_typ *pType){};
void FRM_gbuf(FRM_gbuf_typ *pType)
{
	pType->status = 0;
	pType->buflng = 300;
	pType->buffer = &m_bySendBuffer[0];
};
void FRM_rbuf(FRM_rbuf_typ *pType){};
void FRM_robuf(FRM_robuf_typ *pType){};
char chBuff[100];
void FRM_write(FRM_write_typ *pType)
{
	DWORD dwSentBytes;
	BOOL res;
	pType->status = 1;
	m_nCommServer->m_StatusWrite = 1;
	if(!WriteFile(hCom, pType->buffer, pType->buflng, &dwSentBytes,&osSend))
	//strcpy(chBuff,"Abramenya Alex");
	//if(!WriteFile(hCom, chBuff, strlen(chBuff), &dwSentBytes,&osOverlap))
    {
     if(GetLastError() != ERROR_IO_PENDING)
     {
	  // Ошибка записи данных
      res = FALSE;
	  printf("\n(__)Com::>Write Error 0.");
     }else
     {
      if(!GetOverlappedResult(hCom, &osSend, &dwSentBytes, TRUE))
      {
	   printf("\n(__)Com::>Write Error 1.");
      }else
      {
	   // Запись данных закончена
       res = TRUE;
	   //pType->status = 1;
	   //m_nCommServer->m_StatusWrite = 1;
	   //printf("\n(__)Com::>Write Ok 0.");
      }
     }
    }
    else
    {
	 // Запись успешно завершена
     res = TRUE;
	 //printf("\n(__)Com::>Write Ok 1.");
    }
};
BYTE pb_mBoxDoRead[5000];
BYTE pb_mBoxRead[3000];
BYTE pb_mBoxCont[5000];
WORD w_mBoxSize  = 0x7ff;
WORD w_mBoxCSize = 0x7ff;
WORD w_mBoxWrite = 0;
WORD w_mBoxRead  = 0;
WORD w_mBoxMesCt = 0;
//WORD w_mBoxSEnd  = 50000;
WORD mCurLen=0;
WORD m_sSize=0;
WORD w_lLength=0;
void MakeMessage(void);
void CopyMessage(WORD wLen);
/*
Success := ReadFile(FHandle, pb_mBoxDoRead, w_lLength, BytesTrans, @Ov);
		 for i:=0 to w_lLength-1 do
		 Begin
		  pb_mBoxCont[w_mBoxWrite]:=pb_mBoxDoRead[i];
          w_mBoxWrite := (w_mBoxWrite + 1) and BSZ;
		  //SendDebug('(__)Synchro Buffer NULL.');
		 End;
			 
			 //SendDebug('(__)RD::');
			 //for i:=0 to w_lLength-1 do SendDebug(' '+IntToStr(pb_mBoxCont[i]));
			 //Success := Success and GetOverlappedResult(FHandle, Ov, BytesTrans, False);
			 //w_mBoxWrite := (w_mBoxWrite + w_lLength)and $7ff;
w_mBoxSize  := w_mBoxSize   - w_lLength;
m_sSize     := w_mBoxCSize  - w_mBoxSize;
			 if ((pb_mBoxCont[w_mBoxRead]=$68)or(pb_mBoxCont[w_mBoxRead]=$10)) then
				 Begin
m_byMType := 0;
			 SetEvent(hRxEvent);
			 End else
				 Begin
m_byMType  := 1;
w_mBoxSize  := BSZ;
w_mBoxCSize := BSZ;
w_mBoxWrite := 0;
w_mBoxRead  := 0;
w_mBoxMesCt := 0;
m_sSize:=0;
FBlTxEmpty := True;
			SendDebug('(__)Synchro Buffer.');
			//SetEvent(hRxEvent);
  End;
*/
void FRM_read(FRM_read_typ *pType)
{
	DWORD Errors,BytesTrans;
	BYTE i;
	ClearCommError(hCom, &Errors, &csStat);
	pType->status = 1;
	if (csStat.cbInQue!=0)
	{
	 pType->buffer = &m_byReadBuffer[0];
	 w_lLength = csStat.cbInQue;
     if(ReadFile(hCom, pType->buffer, w_lLength, &BytesTrans, &osReceive))
	 //if(ReadFile(hCom, m_byReadBuffer, w_lLength, &BytesTrans, &osReceive))
	 {
	  //for(i=0;i<w_lLength-1;i++)printf(" %x",m_byReadBuffer[i]);
	  pType->buflng = w_lLength;
	  pType->status = 0;
	 }else Info("\nError Read_0.");
	}
}
void RxCharProc(void)
{
	DWORD Errors,BytesTrans,dwB;
    BOOL  res;
	INT   i,wI,lLen;
	ClearCommError(hCom, &Errors, &csStat);
	if (csStat.cbInQue!=0)
	{
     w_lLength = csStat.cbInQue;
     if ((w_lLength<=0)||(w_lLength>500)) return;
     wI = w_mBoxWrite;
     if((wI+w_lLength)<=w_mBoxCSize)res = ReadFile(hCom, &pb_mBoxCont[wI], w_lLength, &BytesTrans, &osReceive);else
	 {
      res = ReadFile(hCom, &pb_mBoxDoRead[0], w_lLength, &BytesTrans, &osReceive);
	  for (i=0;i<w_lLength;i++){pb_mBoxCont[wI]=pb_mBoxDoRead[i];wI = (wI + 1) & 0x7ff;}
	 }
	 if(GetOverlappedResult(hCom, &osReceive, &dwB, TRUE))
	 {
	  //printf("\n(__)COM::>");for(i=0;i<w_lLength;i++)printf(" %x",pb_mBoxCont[w_mBoxWrite+i]);

	  w_mBoxWrite = (w_mBoxWrite + w_lLength)& 0x7ff;
      mCurLen=mCurLen+w_lLength;
      w_mBoxSize  = w_mBoxSize  - w_lLength;
	  if ((pb_mBoxCont[w_mBoxRead]==0x68)||(pb_mBoxCont[w_mBoxRead]==0x10))
	  {
       m_sSize=w_mBoxCSize-w_mBoxSize;
       SetEvent(evMake);
	   mCurLen=0;
	  }

	 }else printf("\n(__)Com::>RxRead Error.");
	}
}
void MakeMessage(void)
{
   WORD lLen,i;
   //printf("\n(__)COM::>MAKE_M:%x",pb_mBoxCont[w_mBoxRead]);
   lLen = pb_mBoxCont[(w_mBoxRead+1) & 0x7ff]; 
   while((m_sSize>=(lLen+6))&&(pb_mBoxCont[w_mBoxRead]==0x68))CopyMessage(lLen+6);
   lLen = 5;
   while((m_sSize>=lLen)&&(pb_mBoxCont[w_mBoxRead]==0x10))CopyMessage(lLen);
}
void CopyMessage(WORD wLen)
{
   INT i;
   SMESSAGE sMsg;
   for(i=0;i<wLen;i++)
   {
    pb_mBoxRead[i]=pb_mBoxCont[w_mBoxRead];
    w_mBoxSize++;
    w_mBoxRead=(w_mBoxRead+1)& 0x7ff;
   }
   m_sSize = (w_mBoxCSize-w_mBoxSize) & 0x7ff;
   m_sRecc.buflng = wLen;
   memcpy(&m_byReadBuffer[0],pb_mBoxRead, wLen);
   m_nCommServer->ReceiveThread(m_nCommServer);
   //printf("\n(__)COM::>");for(i=0;i<wLen;i++) printf(" %x",pb_mBoxRead[i]);
}
DWORD WINAPI MakeThread(LPVOID lpCComm)
{
	BYTE i;
	 while(1)
	 {
      WaitForSingleObject(evMake,INFINITE);
	  MakeMessage();
	  //printf("\n(__)COM::>MakeM.");
	 }
}
void CANopen(CANopen_typ *pCANOpen){};
void CANnode(CANnode_typ *pCANnode){};
#endif


void CComServer_Init(This,SARMINTERFACE *pArm)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
    #ifdef WIN32
	m_nCommServer = pT;
    #endif
	pT->m_pArm = pArm;
	FDEFINE(DEV_RSMMD_BOX_ID,DEV_RSMMD_BOX_SZ);
	FDEFINE(DEV_RSBUF_BOX_ID,DEV_RSBUF_BOX_SZ);
	pB->SetBoxID(pB,DEV_RSMMD_BOX_ID);
	
	InitObject(CMTimer,&pT->m_nConnTMR);
	pT->m_nConnTMR.SetTimer(&pT->m_nConnTMR,DIR_PHTOPH,DIR_PHTOPH,EV_TMR_SRR_REQ,0,0,DEV_RSMMD_BOX_ID);
	//pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,10);
	pT->m_blMsgFind = FALSE;
	pT->m_byType = pArm->byType;
	pT->m_byRate = pArm->byPortRate;
	pT->InByteCount_DATA = 0;
	
	strcpy(pT->m_chStringMode, chPortType[pT->m_pArm->byType]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortRate[pT->m_pArm->byPortRate]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortParity[pT->m_pArm->stTcpAddr.byAddr0]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortData[pT->m_pArm->stTcpAddr.byAddr1]);
	strcat(pT->m_chStringMode,", ");
	strcat(pT->m_chStringMode, chPortStop[pT->m_pArm->stTcpAddr.byAddr2]);
	
	strcpy(pT->m_chStringDevice, "SL0.IF1");
	#ifdef DEB_CComServer
	Info("\n(__)CTCPS::>Create %s.Device: %s Mode: %s",
	chPortType[pT->m_byType],pT->m_chStringDevice,pT->m_chStringMode);
	#endif
	pT->SynBuff(pT);
    pT->InitSRV(pT);
	//pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,200);
	pT->m_StatusWrite = 0;
	pT->m_bSrvState = DRV_ST_CONN;
	pT->m_bCliState = DRV_ST_CONN;
}
/*
if(pA->byA2==0) pR->byNumber          = (BYTE)pA->wParam; //Port Number
if(pA->byA2==1) pR->byType            = (BYTE)pA->wParam; //Port Type
if(pA->byA2==2) pR->byPortRate        = (BYTE)pA->wParam; //Port Rate
if(pA->byA2==3) pR->stTcpAddr.byAddr0 = (BYTE)pA->wParam; //Parity
if(pA->byA2==4) pR->stTcpAddr.byAddr1 = (BYTE)pA->wParam; //Data Bits
	 if(pA->byA2==5) pR->stTcpAddr.byAddr2 = (BYTE)pA->wParam; //Stop Bits
*/
void CComServer_SetPortSett(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
    strcpy(pT->m_chStringDevice, "SL0.IF1");  
	memset(pT->m_chStringNewMode,0,sizeof(pT->m_chStringNewMode));

	strcpy(pT->m_chStringNewMode, chPortType[pT->m_pArm->byType]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortRate[pT->m_pArm->byPortRate]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortParity[pT->m_pArm->stTcpAddr.byAddr0]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortData[pT->m_pArm->stTcpAddr.byAddr1]);
	strcat(pT->m_chStringNewMode,", ");
	strcat(pT->m_chStringNewMode, chPortStop[pT->m_pArm->stTcpAddr.byAddr2]);
    #ifndef WIN32
    FrameModeStruct.ident  = m_sXOpen.ident;
    FrameModeStruct.mode   = (UDINT)pT->m_chStringNewMode;
    FrameModeStruct.enable = 1;
    FRM_mode(&FrameModeStruct); 
    #endif
}
void CComServer_SynBuff(This)//CANOpen
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	pT->w_mBoxSize  = BUFF_SZ;
    pT->w_mBoxCSize = BUFF_SZ;
	pT->w_mBoxWrite = 0;
	pT->w_mBoxRead  = 0;
	pT->m_sSize     = 0;
	pT->w_lLength   = 0;
	pT->w_lMsgLen   = 0;
	memset(&pT->pb_mBoxCont[0],0,10);
	#ifdef DEB_CComServer
	Info("\n(__)CTCPS::>Synchro.");
    #endif
}
_GLOBAL FRM_xopen_typ FrameXOpenStruct; 
_GLOBAL XOPENCONFIG XOpenConfigStruct; 
void CComServer_InitSRV(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	
	CANopen_01.enable    = 1;         
    CANopen_01.baud_rate = 25;     
    CANopen_01.cob_anz   = 5;       
    CANopen_01.device    = 0;       
    CANopen(&CANopen_01); 
	

	//Server Init
    m_sConfig.idle     = 10;
    m_sConfig.delimc   = 0;
    m_sConfig.delim[0] = 0;
	m_sConfig.delim[1] = 0;
	m_sConfig.tx_cnt   = 2;
	m_sConfig.rx_cnt   = 2;
	m_sConfig.tx_len   = 256;
	m_sConfig.rx_len   = 256;
	m_sConfig.argc     = 0;
	m_sConfig.argv     = 0;

	strcpy(pT->m_chStringMode, "RS232, 57600, E, 8, 1");	
	m_sXOpen.device    = (UDINT) pT->m_chStringDevice;
	m_sXOpen.mode      = (UDINT) pT->m_chStringMode;	
    m_sXOpen.config    = (UDINT)&m_sConfig;
	m_sXOpen.enable    = 1;
	pT->m_StatusOpen   = 0;
    #ifndef WIN32
	pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30); 
    #else
	pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30); 
	//pT->Open(pT); 
    #endif
}
_GLOBAL INT nOPEN,nCLOSE;

BOOL CComServer_Open(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
	SHORTMESSAGE m_sMsg;

	CANnode_01.enable = 1;         
    CANnode(&CANnode_01);         
    node_nr = CANnode_01.node_nr;     
    #ifdef WIN32
	node_nr = 1; 
	//pT->m_StatusOpen = 0;
    #endif
    if((node_nr==1)&&(pT->m_StatusOpen==0))
	{
	FRM_xopen(&m_sXOpen);                  
	if(m_sXOpen.status==0)
	{
	 nOPEN++;
	 m_sRecc.ident      = m_sXOpen.ident;
	 m_sSend.ident      = m_sXOpen.ident;
	 m_sClose.ident     = m_sXOpen.ident;
	 m_sFrameBuff.ident = m_sXOpen.ident;
	 m_sRBuff.ident     = m_sXOpen.ident;
	 m_sRecc.buffer	    = (UDINT)&pT->m_ReadBuffer[0];
	 m_sSend.buffer     = (UDINT)&pT->m_SendBuffer[0];
	 m_sFrameBuff.buffer= m_sSend.buffer;
	 m_sRBuff.buffer    = m_sRecc.buffer;
	 m_sRecc.enable     = 1; 
	 m_sSend.enable     = 1; 
	 m_sClose.enable    = 1; 
	 m_sFrameBuff.enable= 1; 
	 m_sRBuff.enable    = 1; 
	 pT->m_StatusOpen   = 1;
	 pT->m_StatusWrite  = 0;
     #ifdef IF_MODEM  
	 SendCommand(PH_INIT_REQ,"AT+ipr=57600");
	 SendCommand(PH_INIT_REQ,"AT+icf=2,1");
	 SendCommand(PH_INIT_REQ,"AT+ifc=0,0");
	 SendCommand(PH_INIT_REQ,"AT&D1");
	 SendCommand(PH_INIT_REQ,"AT&C1");
	 //SendCommand(PH_INIT_REQ,"AT&S0");
	 SendCommand(PH_INIT_REQ,"ATS0=1");
	 SendCommand(PH_INIT_REQ,"AT+CLIP=1");
     #endif
	 pT->SendSMessage(pT,DEV_KPMDL_BOX_ID,DIR_PHTOKP,PH_CALL_REQ);
	 return TRUE;
	}
 	}
	if((node_nr==3)&&(pT->m_StatusOpen==1))
	{
	  nCLOSE++;
	  pT->m_StatusOpen = 0;
      pT->Close(pT);
	  return TRUE;
	}
	return FALSE;
}
void CComServer_Enable(This)
{
	DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	m_sXOpen.enable = 1;
}
void CComServer_Disable(This)
{
	DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	m_sXOpen.enable = 0;
}
void CComServer_Close(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
	m_sClose.enable = 1;
	FRM_close(&m_sClose);            
}
BOOL CComServer_SendMessage(This,SMESSAGE *pMsg)
{
	DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
	BOOL res = TRUE;
	if(pT->m_StatusOpen==1)
	{
	 FRM_gbuf(&m_sFrameBuff);
     m_sSend.buflng = pMsg->m_swLen-9;
	 memcpy(m_sSend.buffer, &pMsg->m_sbyInfo[0],m_sSend.buflng);
	 FRM_write(&m_sSend);          
	 pT->m_StatusWrite  = m_sSend.status;
	 if(pT->m_StatusWrite==0) res = TRUE;else res = FALSE;
	}
	return res;
}
_GLOBAL INT nSND;
_GLOBAL INT nSendThread;
void CComServer_SendThread(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)  
	nSendThread++;
    //if(pT->m_StatusWrite==0)
	if(pT->m_StatusOpen==1)
    {
	 #ifdef DEB_CComServer
	 //pT->TestMsg(pT);
     #endif
	 if(FGET(DEV_RSBUF_BOX_ID,&pT->m_sMsg))
	 {
	  //Info("\n(__)CRSSM::>TX:%M",&pT->m_sMsg);
	  if(pT->m_sMsg.m_swLen<=256)
	  {
	   nSND++;
       pT->SendMessage(pT,&pT->m_sMsg);
	  }//else
	    //Info("\n(__)CRSSM::>Wery Long Message!");
	 }
	}
}
_GLOBAL INT nGETL1;
BOOL CComServer_GetMessage(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)  
	BYTE i,*pBuff;
	BOOL res=FALSE;
	SMESSAGE csM;
	if(pT->m_StatusOpen==1)
	{
	FRM_read(&m_sRecc);                       
	pT->m_StatusRead       = m_sRecc.status; 
	if(pT->m_StatusRead==0)    
	{
	 pT->m_ReadBufferLength = m_sRecc.buflng;
	 pBuff                  = m_sRecc.buffer;
	 /*
	 csM.m_sbyInfo[0] = 0x7e;
	 csM.m_sbyInfo[1] = 'A';
	 csM.m_sbyInfo[2] = 'l';
	 csM.m_sbyInfo[3] = 'e';
	 csM.m_sbyInfo[4] = 'x';
	 csM.m_sbyInfo[5] = 'a';
	 csM.m_sbyInfo[6] = 'n';
	 csM.m_sbyInfo[7] = 'd';
	 csM.m_sbyInfo[8] = 'e';
	 csM.m_sbyInfo[9] = 'r';
	 csM.m_sbyInfo[10] = 0xe7;
	 */

	 //memcpy(&csM.m_sbyInfo[0],m_sRecc.buffer,pT->m_ReadBufferLength);
	 //csM.m_swLen = 9 + pT->m_ReadBufferLength;
	 //Info("\n(__)CRSSM::>MSG:%M",&csM);
	 
	 //m_sRBuff.buffer = m_sRecc.buffer;
	 //m_sRBuff.buflng = pT->m_ReadBufferLength;
	 //FRM_rbuf(&m_sRBuff); 
	 //res = TRUE;   
	 //nGETL1++;
	 //Info("\nMSG::>");
	 //csM.m_swLen = pT->m_ReadBufferLength+9;
	 for( i=0;i<pT->m_ReadBufferLength;i++)
	 {
	  pT->pb_mBoxCont[pT->w_mBoxWrite] = pBuff[i];
      //Info(" %b",&pT->pb_mBoxCont[pT->w_mBoxWrite]);
	  //printf(" %c",pT->pb_mBoxCont[pT->w_mBoxWrite]);
      pT->w_mBoxWrite = (pT->w_mBoxWrite + 1) & BUFF_SZ;
	 }
	 //FPUT(DEV_RSBUF_BOX_ID,(BYTE*)&csM);
	 pT->w_mBoxSize -= pT->m_ReadBufferLength;
	 pT->m_sSize     = pT->w_mBoxCSize-pT->w_mBoxSize;
	 //Info("\nRD::>%b PRD::>%w PWD::>%w FND::>%b",&pT->pb_mBoxCont[pT->w_mBoxRead],&pT->w_mBoxRead,&pT->w_mBoxWrite,&pT->m_blMsgFind);
	 //printf(" %c %c", pT->pb_mBoxCont[pT->w_mBoxRead],pT->pb_mBoxCont[pT->w_mBoxRead+1]);
	 //if ((pT->pb_mBoxCont[pT->w_mBoxRead]==0x3d)&&(pT->pb_mBoxCont[pT->w_mBoxRead+1]==0x30)) 
	 if ((pT->pb_mBoxCont[pT->w_mBoxRead]==0x3d)) 
	 {
	  pT->m_blMsgFind = TRUE;
	  if(res = pT->MakeMsgData(pT,pMsg))
	  {
	   pT->m_blMsgFind = FALSE;
	   res = TRUE;   
	  }
	 }else 
		 pT->SynBuff(pT);
	 //if (pT->m_blMsgFind==FALSE)
	 //{
	 //	pT->MakeTextMessage(pT);
 	 //}else /*if (pT->pb_mBoxCont[pT->w_mBoxRead]==0x41)*/ pT->SynBuff(pT);
	 m_sRBuff.buffer = m_sRecc.buffer;
	 m_sRBuff.buflng = pT->m_ReadBufferLength;
	 FRM_rbuf(&m_sRBuff); 
     }
	}
	return res;
}
BOOL CComServer_MakeMsgData(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	WORD lLen,i,nCM=0;
	BOOL res = FALSE;
	lLen = 1;
	pT->w_lMsgLen = pT->w_lMsgLen + pT->m_ReadBufferLength;
	if (pT->w_lMsgLen>BUFF_SZ) {pT->SynBuff(pT);return res;} 
    for (i=1;i<pT->w_lMsgLen-1;i++)
	{
	 lLen++;
	 if (pT->pb_mBoxCont[(pT->w_mBoxRead+i)& BUFF_SZ]==0x2e) nCM++;
	 if (nCM>1){pT->SynBuff(pT);return res;} 
	 if (lLen>300) {pT->SynBuff(pT);return res;} 
     if (pT->pb_mBoxCont[(pT->w_mBoxRead+i)& BUFF_SZ]==0x3d)
     {
	  pT->CopyMessage(pT,lLen,pMsg);
	  //pT->SynBuff(pT);
	  pT->w_lMsgLen = 0;
	  return TRUE;
	 }
	}
	return res;
}
BOOL CComServer_CopyMessage(This,WORD wLen,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
    INT i,j=0;BYTE byCRC;
	BOOL blCRC;
	for(i=0;i<wLen;i++)
	{
	 if ((i!=0)&&(i!=wLen-1)){pMsg->m_sbyInfo[j]=pT->pb_mBoxCont[pT->w_mBoxRead];j++;}
	 pT->w_mBoxSize =(pT->w_mBoxSize+1)& BUFF_SZ; ;
	 pT->w_mBoxRead=(pT->w_mBoxRead+1)& BUFF_SZ;
	 //Info(" %b",&pMsg->m_sbyInfo[i]);
	 //printf(" %x",pMsg->m_sbyInfo[i]);
	}
	pMsg->m_sbyInfo[j++] = 0x00;
	pT->w_mBoxRead=(pT->w_mBoxRead-1)& BUFF_SZ;
	pT->m_sSize = (pT->w_mBoxCSize-pT->w_mBoxSize) & BUFF_SZ;
	pMsg->m_swLen         = j+9;
	pMsg->m_sbyFrom       = DIR_PHMDL;
	pMsg->m_sbyFor        = DIR_PHTOMS;
	pMsg->m_sbyIntType    = 0;
	pMsg->m_sbyServerID   = 0;
	pMsg->m_sbyType       = PH_VS0_REQ;
	pMsg->m_sbyDirection  = 0;
	pMsg->m_sbySensor     = 0;
	//byCRC = pMsg->m_sbyInfo[pMsg->m_swLen-9-2];
    //if (pMsg->m_sbyInfo[0]==MSG_SHRT_CODE)
	//if (byCRC==pT->CreateCRC(pT,&pMsg->m_sbyInfo[1],2)) blCRC = TRUE;
	return TRUE;
}
_GLOBAL INT nReceiveThread;
void CComServer_ReceiveThread(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	nReceiveThread++;
	if(pT->GetMessage(pT,&pT->m_sMsg)==TRUE)
	{
	 //Info("\n(__)CRSSM::>RX:%M",&pT->m_sMsg);
	 //if ((pT->nWsCount++)%10==0)
	 FPUT(DEV_MSMDL_BOX_ID,(BYTE*)&pT->m_sMsg);
	 //FPUT(DEV_RSBUF_BOX_ID,(BYTE*)&pT->m_sMsg);
	}
}
void CComServer_MakeTextMessage(This)
{
	DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
    BYTE byInByte;
    while (pT->w_mBoxWrite!=pT->w_mBoxRead) 
	{
     byInByte = pT->pb_mBoxCont[pT->w_mBoxRead];
     pT->w_mBoxRead = (pT->w_mBoxRead+1) & BUFF_SZ;
     if (pT->w_mBoxSize>pT->w_mBoxCSize){pT->SynBuff(pT);return;};
     pT->w_mBoxSize++;
     if (byInByte==0x0d)
	 {
	   if (pT->InByteCount_DATA>1)
	   pT->ATHandler(pT,&pT->pb_mBoxDoTextRead[0],pT->InByteCount_DATA);
       pT->InByteCount_DATA = 0;
	 }else
	 {
       pT->pb_mBoxDoTextRead[pT->InByteCount_DATA] = byInByte;
       if (pT->InByteCount_DATA>100) {pT->InByteCount_DATA=0;pT->SynBuff(pT);}
       pT->InByteCount_DATA++;
	 }
	}
}
void CComServer_ATHandler(This,USINT *pComm,WORD wLen)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
    WORD i,i0,i1,j=0;
	//printf("\nAT_MSG::>");for (i=0;i<wLen;i++)printf(" %c",pComm[i]);
	if (wLen<100)
	{
	pComm[wLen] = 0;
	if(pT->FindText(pT,"CONNECT",pComm)>0)
	{
     #ifdef DEB_CComServer
	 Info("\n(__)CRSSM::>CONNECT 9600");
     #endif
	 pT->Connect(pT);
	 return;
	}
	if(pT->FindText(pT,"NO CAR",pComm)>0) 
	{
     #ifdef DEB_CComServer
	 Info("\n(__)CRSSM::>NO CARRIER");
     #endif
	 pT->Disconnect(pT);
	 return;
	}
	if(pT->FindText(pT,"+CLIP:",pComm)>0) 
	{
     #ifdef DEB_CComServer
	 Info("\n(__)CRSSM::>+CLIP");
     #endif
     m_wPhoneKey = 0;
	 i0 = pT->FindText(pT," ",pComm);i1 = pT->FindText(pT,",",pComm);
     //printf("\nAT_PHO::>");
	 for (i=i0+2;i<i1-1;i++) 
	 {
	  if (i>30) return;
	  m_wPhoneKey = m_wPhoneKey + ((pComm[i]&0x0f)+j);
	  //StrPhone[j]=pComm[i];
	  j++;
      //printf(" %c",pComm[i]); 
	 }
	 return;
	}
	}else pT->SynBuff(pT);
}
INT CComServer_FindText(This,SINT *pSrc,SINT *pChar)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	WORD i,wSrcSumm=0,wLen,wStrLen;
	wLen    = strlen(pSrc);
	wStrLen = strlen(pChar); 
	wSrcSumm = pT->CalckSumm(pT,(BYTE*)pSrc,wLen);
	for (i=0;i<wStrLen-wLen;i++)
	{
	 if (wSrcSumm==pT->CalckSumm(pT,(BYTE*)&pChar[i],wLen))
	 return i;
	}
	return -1;
}
WORD CComServer_CalckSumm(This,BYTE *pCH,WORD wLen)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	WORD i,wSrcSumm=0;
	for (i=0;i<wLen;i++)
	wSrcSumm += pCH[i];
    return wSrcSumm;
}
BYTE CComServer_CreateCRC(This,BYTE *pMsg,BYTE byLen)
{
	DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	BYTE i,sum = 0;
	for(i=0;i<=byLen-1;i++)sum += pMsg[i];
	return sum;
}
_GLOBAL INT nRSEventHandler,nCheckOpen,nWatchOpen;
BOOL CComServer_EventHandler(This,SMESSAGE *pMsg)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
	switch(pMsg->m_sbyFor)
	{
	  case DIR_101TOPH:
	       #ifdef DEB_CComServer
		   //Info("\n(__)CRSSM::>OUTP::%M",pMsg);
		   #endif
		   FPUT(DEV_RSBUF_BOX_ID,pMsg);
	  break;
	  case DIR_KPTO101:
	       nRSEventHandler++;
		   if(pMsg->m_sbyType==PH_CONN_REQ) 
		   {
            #ifndef IF_MODEM
		    pT->Connect(pT);
            #else
		    FPUT(DEV_RSBUF_BOX_ID,pMsg);
            #endif
		   }
		   if((pMsg->m_sbyType==PH_DISC_REQ)||(pMsg->m_sbyType==PH_DISC0_REQ)) 
		   {
			//pT->Disconnect(pT);
			FPUT(DEV_RSBUF_BOX_ID,pMsg);
		   }
		   if(pMsg->m_sbyType==PH_INIT_REQ)
		   FPUT(DEV_RSBUF_BOX_ID,pMsg);
	  break;
	  case DIR_PHTOPH:
	       if (pMsg->m_sbyType==EV_TMR_SRR_REQ)
		   {
		   	//if(pT->m_StatusOpen==0)
			{
			 nCheckOpen++;
 		     pT->Open(pT);
			}
			pT->m_nConnTMR.OnTimer(&pT->m_nConnTMR,30); 
		   }
	  break;
      case DIR_KPTOPH:
	       if (pMsg->m_sbyType==PH_CLOSE_PORT_REQ)
		   {
            //pT->Close(pT); 
		   }
		   if(pMsg->m_sbyType==PH_INIT_PORT_REQ)
		   {
             pT->SetPortSett(pT);
		   }
	  break;
	  default:
	  break;
	}
	return TRUE;
}
void CComServer_Connect(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
    SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = DIR_PHTO101P;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_CONN_IND;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(DEV_101MD_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CComServer
	Info("\n(__)CRSSM::>OUTT::%M",&m_sMsg);
    #endif
}
void CComServer_SendSMessage(This,BYTE byBox,BYTE byFor,BYTE byType)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
    SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = byFor;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = byType;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(byBox,(BYTE*)&m_sMsg);	
    #ifdef DEB_CComServer
	Info("\n(__)CRSSM::>OUTT::%M",&m_sMsg);
    #endif
}
void CComServer_Disconnect(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
    SHORTMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9;
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = DIR_PHTO101P;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_DISC_IND;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	FPUT(DEV_101MD_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CComServer
	Info("\n(__)CRSSM::>OUTT::%M",&m_sMsg);
    #endif
}
/*
12	12:58:38	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 30 30 3D 30 2E 30 30 30 30 30 3D 30 2E 30 	
13	12:58:38	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 30 30 30 30 3D 30 2E 30 30 30 30 30 3D 30 	
14	12:58:39	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 2E 30 30 30 30 30 3D 30 2E 30 30 30 30 30 	
15	12:58:39	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 3D 30 2E 30 30 30 30 30 3D 30 2E 30 30 30 	
16	12:58:39	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 30 30 3D 30 2E 30 30 30 30 30 3D 30 2E 30 	
17	12:58:39	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 30 30 30 30 3D 30 2E 30 30 30 30 30 3D 30 	
18	12:58:39	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 2E 30 30 30 30 30 3D 30 2E 30 30 30 30 30 	
19	12:58:39	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 3D 30 2E 30 30 30 30 30 3D 30 2E 30 30 30 	
20	12:58:40	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 30 30 3D 30 2E 30 30 30 30 30 3D 30 2E 30 	
21	12:58:40	hypertrm.exe	IRP_MJ_READ	Serial2	TIMEOUT	Length 14: 30 30 30 30 3D 30 2E 30 30 30 30 30 3D 30 	
*/
void CComServer_TestMsg(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem) 
	SMESSAGE m_sMsg;
	m_sMsg.m_swLen        = 9+strlen(chTest);
	m_sMsg.m_sbyFrom      = DIR_PHMDL;
	m_sMsg.m_sbyFor       = DIR_101TOPH;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = PH_DATA_RES;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	strcpy(&m_sMsg.m_sbyInfo[0],chTest);
	FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&m_sMsg);	
    #ifdef DEB_CComServer
	//Info("\n(__)CRSSM::>TEST::%M",&m_sMsg);
    #endif
}
void CComServer_CyclicProc(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)  
	pT->ReceiveThread(pT);
	#ifndef WIN32
	pT->SendThread(pT);
	#endif
}
void CComServer_CComServer(This)
{
    DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)  
	DECLARE_REGISTRATION(CComServer,Init)
	DECLARE_REGISTRATION(CComServer,InitSRV)
	DECLARE_REGISTRATION(CComServer,SendMessage)
	DECLARE_REGISTRATION(CComServer,GetMessage)
    DECLARE_REGISTRATION(CComServer,Close)
	DECLARE_REGISTRATION(CComServer,Disable)
	DECLARE_REGISTRATION(CComServer,Enable)
	DECLARE_REGISTRATION(CComServer,Open)
	DECLARE_REGISTRATION(CComServer,ReceiveThread)
	DECLARE_REGISTRATION(CComServer,SendThread)
	DECLARE_REGISTRATION(CComServer,SynBuff)
	DECLARE_REGISTRATION(CComServer,MakeMsgData)
	DECLARE_REGISTRATION(CComServer,MakeTextMessage)
	DECLARE_REGISTRATION(CComServer,ATHandler)
	DECLARE_REGISTRATION(CComServer,CopyMessage)
	DECLARE_REGISTRATION(CComServer,CreateCRC)
	DECLARE_REGISTRATION(CComServer,Connect)
	DECLARE_REGISTRATION(CComServer,Disconnect)
	DECLARE_REGISTRATION(CComServer,FindText)
	DECLARE_REGISTRATION(CComServer,CalckSumm)
	DECLARE_REGISTRATION(CComServer,SendSMessage)
	DECLARE_REGISTRATION(CComServer,SetPortSett)
	DECLARE_REGISTRATION(CComServer,TestMsg)
	DECLARE_VIRTUAL_FUNC(CComServer,EventHandler)
	DECLARE_VIRTUAL_FUNC(CComServer,CyclicProc)
}

void CComServer_DCComServer(This)
{
	DECLARE_MULTI_OPEN(CComServer,CCyclicSystem)
	//DESTROY
}

DECLARE_MULTI_CREATE(CComServer,CCyclicSystem)

