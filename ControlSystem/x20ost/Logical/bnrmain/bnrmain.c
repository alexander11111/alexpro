/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrmain.c
 * Author: Abramenya
 * Created: January 19, 2009
 ********************************************************************
 * Implementation of program bnrmain
 ********************************************************************/
#include "bnrmain.h"
#include "bnrhconfig.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif 
#ifdef WIN32
//size_t szMem;
#endif
_GLOBAL SYSxinfo_typ SYSXInfo0,SYSXInfo1; 
_GLOBAL RTCtime_typ RTCGetTime, RTCSetTime; 
_GLOBAL BYTE  m_byObsSystemIntState;
_GLOBAL DWORD m_dwTicTime;
CProcManager *m_pProcManager;
_GLOBAL PVOID pProcManager;
_GLOBAL PVOID pSystem;
_GLOBAL PVOID pDebMsg;
_GLOBAL DWORD nMemSize;
_GLOBAL PVOID pvMEM;
typedef struct _tagMem
{
	WORD nSize;
	void *pvMem;
}PMEM;
//_GLOBAL PMEM *m_pMEM;
extern SLMESSAGE *m_pDebMsg;
extern SHARDCOMPUTERTABLE nConfigTable; 

void _INIT bnrmainINIT( void )
{
	SYSxinfo(&SYSXInfo0);
	InitSystem();
	SYSxinfo(&SYSXInfo1);
}
//Cyclic Section
_GLOBAL INT nCTT;
void _CYCLIC bnrmainCYCLIC( void )
{
	if(m_pProcManager!=0)
	m_pProcManager->Run(m_pProcManager);
	nCTT++;
	 //RTC_gettime(&RTCGetTime);
}
//Exit Section
void _EXIT bnrmainEXIT( void ){}
void InitSystem(void)
{
    InitHardValue();
    //printf("\nPre Mem");heapdump();
	
	m_dwTicTime = SYSTEM_QTIME;
	New(sizeof(SLMESSAGE),m_pDebMsg);
	
	////PMEM **m_pMEM;
	////New(sizeof(PMEM**),m_pMEM);
	////New(300*sizeof(PVOID),pvMEM);
	////pvMEM
	
	CreateProcManager();
	CreateSystem(&nConfigTable);
	m_pProcManager->Start(m_pProcManager);
		
	//pProcManager = m_pProcManager;
	//pSystem = m_pSystem;
	//pDebMsg = m_pDebMsg;
	//nMemSize = nMemSize;
	
	//printf("\n(__)Memory : %d",nMemSize);
	//Info("\n(__)Memory:&",&nMemSize);
	//printf("\nPost Mem");heapdump();
    //DeleteSystem();
	//nMemSize = nMemSize;
	//Status = SYSxinfo(&SYSXInfo2);
	//printf("\nPost Del Mem");heapdump();	
}
void DeleteSystem(void)
{
    /*
	m_pProcManager = pProcManager;
	m_pSystem = pSystem;
	m_pDebMsg = pDebMsg;
    m_pProcManager->Stop(m_pProcManager);
	DestroyObject(CSystem,m_pSystem);
	DestroyObject(CProcManager,m_pProcManager);
	Delete(sizeof(SMESSAGE),m_pDebMsg);
	m_pProcManager = 0;
	*/
}

#ifdef WIN32
int main(void)
{
	bnrmainINIT();
	CreateCyclicProc();
	while (1)
	{
	  GetSysCommand();
	  Sleep(100);
	}
    return 0;
}
void GetSysCommand(void)
{
	int ch;
	int i=0;
	SMESSAGE sMsg;
	while((ch = getchar()) != 0x0a) 
	{
	 if (i<DEV_MAX_MSG_SIZE)
	 sMsg.m_sbyInfo[1+i] = (BYTE)ch;
	 i++;
	}
	if(i>0)
	{
	 sMsg.m_sbyInfo[0]   = i+1;
     sMsg.m_swLen        = 9+i+1;
	 sMsg.m_sbyFrom      = MDL_ARMMD;
	 sMsg.m_sbyFor       = MDL_HCOMM;
	 sMsg.m_sbyIntType   = DEV_ARM_PORT_TCP;
	 sMsg.m_sbyServerID  = 0;
	 sMsg.m_sbyType      = EV_DEBMS_DEBOUT_IND;
	 sMsg.m_sbyDirection = 0xff;
	 sMsg.m_sbySensor    = 0xff;
	 //Info("\n(##)CMAIN::>HHAND:%m",(BYTE*)&sMsg);
	 FPUT(DEV_ADMIN_BOX_ID,(BYTE*)&sMsg);
	}
}
#endif
BOOL CreateProcManager(void)
{
	m_pProcManager = NULL;
	New(sizeof(CProcManager),m_pProcManager);
	InitObject(CProcManager,m_pProcManager);
	if(m_pProcManager!=NULL)
	{
	 m_pProcManager->Init(m_pProcManager,m_dwTicTime,TRUE);
 	 return TRUE;
	}else return FALSE;
	
}
BOOL CreateSystem(SHARDCOMPUTERTABLE *plConfigTable)
{
	m_pSystem = NULL;
	New(sizeof(CSystem),m_pSystem);
	InitObject(CSystem,m_pSystem);
	if (m_pSystem!=NULL)
	{
	 m_pSystem->CreateSystem(m_pSystem,plConfigTable);
	 return TRUE;
	}else return FALSE;
}
void DeleteTimer(PVOID pV)
{
    CSystemTimer *p;
	p = (CSystemTimer*)pV;
	m_pProcManager->DisconnectTimer(m_pProcManager,p);
}
void CrateTimer(PVOID pV)
{
    CSystemTimer *p;
	p = (CSystemTimer*)pV;
	m_pProcManager->ConnectTimer(m_pProcManager,p);
}

void CrateProcess(PVOID pV,SINT* chProcName,BYTE byStateProc,BYTE byPeriod)
{
	 CCyclicSystem *p;
	 p = (CCyclicSystem*)pV;
	 p->Create(p,chProcName,byStateProc,byPeriod);
	 m_pProcManager->ConnectProc(m_pProcManager,p);
}
_GLOBAL BYTE nYear;
void GetCurTime(STIME *pTime)
{
    #ifdef WIN32
    SYSTEMTIME nTM; WORD mSec;
	GetLocalTime(&nTM);
	pTime->tYear  = (BYTE)nTM.wYear-2000;
	pTime->tMonth = (BYTE)nTM.wMonth;
	pTime->tDay   = (BYTE)nTM.wDay;
	pTime->tHour  = (BYTE)nTM.wHour;
	pTime->tMin   = (BYTE)nTM.wMinute;

	pTime->tSec   = (BYTE)nTM.wSecond;
	mSec          = nTM.wMilliseconds + nTM.wSecond*1000;
	pTime->tMSecL = (BYTE)mSec;
	pTime->tMSecH = mSec>>8;
    #else
 	/*
      RTCSetTime.year = 2000;
      RTCSetTime.month = RTCGetTime.month;
      RTCSetTime.day = RTCGetTime.day;
      RTCSetTime.hour = RTCGetTime.hour;
      RTCSetTime.minute = RTCGetTime.minute;
      RTCSetTime.second = RTCGetTime.second;
      RTCSetTime.millisec = RTCGetTime.millisec;
      RTCSetTime.microsec = RTCGetTime.microsec;
	*/
    RTC_gettime(&RTCGetTime);        
	pTime->tYear  = (RTCGetTime.year-2000);
	nYear = pTime->tYear;
	pTime->tMonth = RTCGetTime.month;
	pTime->tDay   = RTCGetTime.day;
	pTime->tHour  = RTCGetTime.hour;
	pTime->tMin   = RTCGetTime.minute;
	pTime->tSec   = RTCGetTime.second;
	RTCGetTime.millisec = RTCGetTime.millisec + ((UINT)RTCGetTime.second)*1000;
	pTime->tMSecL = (BYTE)RTCGetTime.millisec;
	pTime->tMSecH = (BYTE)(RTCGetTime.millisec>>8);
    #endif
}
void SetBoardTime(BYTE *byTime)
{
	RTCtime_typ RTCSetTime; 
	BYTE nSec;
	WORD nMsec;
	RTCSetTime.year     = 2000+byTime[6];
	RTCSetTime.month    = byTime[5];
	RTCSetTime.day      = byTime[4];
	RTCSetTime.hour     = byTime[3];
	RTCSetTime.minute   = byTime[2];
	
	nMsec = ((WORD)byTime[0])|((WORD)byTime[1])<<8;
	nSec  = nMsec/1000;
    nMsec = nMsec - nSec*1000; 

	RTCSetTime.second   = nSec;
	RTCSetTime.millisec = nMsec;
	//Info("\nYR:%w MN:%b DY:%b HR:%b MI:%b SC:%b MS:%w",&RTCSetTime.year,&RTCSetTime.month,&RTCSetTime.day,&RTCSetTime.hour,&RTCSetTime.minute,&nSec,&nMsec);
    #ifndef WIN32
	RTC_settime(&RTCSetTime);   
    #endif
}
void SendSMessage(BYTE byBox,BYTE byFor,BYTE byType)
{
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
    #ifdef DEB_CMain
	Info("\n(__)CMAIN::>OUTT::%M",&m_sMsg);
    #endif
}
void SendCommand(BYTE byEvent,SINT *pchCommand)
{
	SHORTMESSAGE m_sMsg;
	BYTE byNbLen;
	m_sMsg.m_sbyFrom      = DIR_KPMOD;
	m_sMsg.m_sbyFor       = DIR_KPTO101;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = byEvent;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	byNbLen = strlen(pchCommand);
    memcpy(m_sMsg.m_sbyInfo,pchCommand,byNbLen);
	m_sMsg.m_sbyInfo[byNbLen] = 13;
	m_sMsg.m_sbyInfo[byNbLen+1] = 10;
	m_sMsg.m_swLen            = 9+byNbLen+2;
	#ifdef DEB_CMain
    Info("\n(__)CMAIN::>Command:%s",pchCommand);
    #endif
	FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&m_sMsg);		 
}
void SendChar(BYTE byEvent,SINT *pchCommand)
{
	SHORTMESSAGE m_sMsg;
	BYTE byNbLen;
	m_sMsg.m_sbyFrom      = DIR_KPMOD;
	m_sMsg.m_sbyFor       = DIR_KPTO101;
	m_sMsg.m_sbyIntType   = 0;
	m_sMsg.m_sbyServerID  = 0;
	m_sMsg.m_sbyType      = byEvent;
	m_sMsg.m_sbyDirection = 0;
	m_sMsg.m_sbySensor    = 0;
	byNbLen = strlen(pchCommand);
    memcpy(m_sMsg.m_sbyInfo,pchCommand,byNbLen);
	//m_sMsg.m_sbyInfo[byNbLen] = 13;
	//m_sMsg.m_sbyInfo[byNbLen+1] = 10;
	m_sMsg.m_swLen            = 9+byNbLen;
	//#ifdef DEB_CMain
    //Info("\n(__)CMAIN::>Command:%s",pchCommand);
    //#endif
	FPUT(DEV_RSMMD_BOX_ID,(BYTE*)&m_sMsg);		 
}
_GLOBAL INT nQMem;
void NEW(int nSize,void **pVoid)
{ 
     #ifdef WIN32
	 MEM_alloc(nSize,*pVoid);
     #else
	 MEM_alloc(nSize,pVoid);
     #endif
	 nQMem++;
	 nMemSize += nSize;
};
void FREE(int nSize,void **pVoid)
{
	 if(nSize!=0)
     MEM_free(nSize,pVoid);  
	 nMemSize -= nSize;
}
#ifdef WIN32
DWORD WINAPI CyclicProcess( PVOID pVoid)
{
	HANDLE hEvent = CreateEvent(NULL,FALSE,TRUE,NULL);
	int nTime;
	while (1)
	{
	 bnrmainCYCLIC();
	 WaitForSingleObject(hEvent,m_dwTicTime);
	 //if (nTime%50==0) Info("\nTMR_________");
	 //nTime++;
	 //Sleep(20);
	 //Sleep(m_dwTicTime);
	}
	return 0;	
}
void CreateCyclicProc(void)
{
	DWORD dwThreadId, dwThrdParam = 1; 
	HANDLE hThread; 
	hThread = CreateThread(NULL,0,CyclicProcess,&dwThrdParam,0,&dwThreadId);
}
void heapdump( void )
{
	_HEAPINFO hinfo;
	int heapstatus;
	hinfo._pentry = NULL;
	while( ( heapstatus = _heapwalk( &hinfo ) ) == _HEAPOK )
	{ printf( "%6s block at %Fp of size %4.4X\n",
	( hinfo._useflag == _USEDENTRY ? "USED" : "FREE" ),
	hinfo._pentry, hinfo._size );
	}
	
	switch( heapstatus )
	{
	case _HEAPEMPTY:
		printf( "OK - empty heap\n" );
		break;
	case _HEAPEND:
		printf( "OK - end of heap\n" );
		break;
	case _HEAPBADPTR:
		printf( "ERROR - bad pointer to heap\n" );
		break;
	case _HEAPBADBEGIN:
		printf( "ERROR - bad start of heap\n" );
		break;
	case _HEAPBADNODE:
		printf( "ERROR - bad node in heap\n" );
		break;
	}
}
#endif


