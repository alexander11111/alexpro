/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrmain.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "typedefs.h"
#include "bnrmysystem.h"
#include "bnrprocmanager.h"
#include "bnrdebug.h"
#include "bnrpob.h"
#ifndef WIN32
#include <bur/plctypes.h>
#else
#include "time.h"
#endif
void _INIT bnrmainINIT( void );
void _CYCLIC bnrmainCYCLIC( void );
void SetBoardTime(BYTE *byTime);
void SendSMessage(BYTE byBox,BYTE byFor,BYTE byType);
void SendCommand(BYTE byEvent,SINT *pchCommand);
void SendChar(BYTE byEvent,SINT *pchCommand);
#ifdef WIN32
  DWORD WINAPI CyclicProcess(PVOID);
  void CreateCyclicProc(void);
  void GetSysCommand(void);
  void heapdump( void );
#endif
  void GetCurTime(STIME *pTime);
  void _EXIT bnrmainEXIT( void );
  BOOL CreateSystem(SHARDCOMPUTERTABLE *plConfigTable);
  BOOL CreateProcManager(void/*CSystem *pSystem*/);
  void InitSystem(void);
  void DeleteSystem(void);
#ifndef WIN32
int main(void);
#endif




