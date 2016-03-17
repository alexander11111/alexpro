/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrflash.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
#ifdef WIN32
SCONTENSTTABLE nMemory;
HANDLE hMFile; 
void DMstore(struct DMstore* inst)
{
	DWORD dwBytesWritten;
	inst->status = 1;
	if(WriteFile(hMFile, (BYTE*)inst->data, sizeof(SCONTENSTTABLE),&dwBytesWritten, NULL)) 
	{
	 SetFilePointer(hMFile,0,NULL,FILE_BEGIN);
	 inst->status = 0;
	}
};
void DMxfree(struct DMxfree* inst){};
void DMfree(struct DMfree* inst){};
void DMxclear(struct DMxclear* inst){};
void DMclear(struct DMclear* inst){};
void DatObjCreate(struct DatObjCreate* inst){};
void DatObjWrite(struct DatObjWrite* inst){};
void DatObjRead(struct DatObjRead* inst)
{
     DWORD dwBytesWritten;    
	 inst->status = 1;
	 if(ReadFile(hMFile, (BYTE*)inst->pDestination, inst->len,&dwBytesWritten, NULL))
	 {
      SetFilePointer(hMFile,0,NULL,FILE_BEGIN);
	  inst->status = 0;
	 }
};
void DatObjDelete(struct DatObjDelete* inst){};
void DatObjMove(struct DatObjMove* inst){};
void DatObjCopy(struct DatObjCopy* inst){};
void DatObjInfo(struct DatObjInfo* inst)
{
	inst->status = 0;
};
void DatObjChangeDate(struct DatObjChangeDate* inst){};
#endif
//DMstore_typ _GLOBAL DM_store_0;
BOOL CMFlash_WriteFlash(This,BYTE *pbyBuff,WORD wLen)
{
    DECLARE_SINGLE_OPEN(CMFlash) 
	pT->ClearFlash(pT);
    pT->DM_store.enable   = 1;
    pT->DM_store.name     = (UDINT)pT->m_chName;
    pT->DM_store.data     = (UDINT)pbyBuff;
    pT->DM_store.size     = wLen;
    DMstore(&pT->DM_store);
	//memcpy(&DM_store_0,&pT->DM_store,sizeof(DMstore_typ));
    if (pT->DM_store.status == 0)return TRUE; 
	else
	return FALSE;
}
BOOL CMFlash_WriteFlashRem(This,BYTE *pbyBuff,WORD wLen)
{
    DECLARE_SINGLE_OPEN(CMFlash) 
	SLMESSAGE *pMsg;
    New(sizeof(SLMESSAGE),pMsg);
	pMsg->m_swLen        = 9+wLen;
    pMsg->m_sbyFrom      = MDL_OBSRV;  
	pMsg->m_sbyFor       = MDL_ARMSY;  
	pMsg->m_sbyIntType   = DEV_ARM_PORT_TCP;  
	pMsg->m_sbyType      = EV_OBSRV_REMFLS_SAVE_REQ;
	pMsg->m_sbyServerID  = MYSYSTEM_ID;  
	pMsg->m_sbyDirection = 0xff;  
	pMsg->m_sbySensor    = 0xff;
	memcpy(pMsg->m_sbyInfo,pbyBuff,wLen);
	FPUT(DEV_ARMOT_BOX_ID,(BYTE*)pMsg);
    Delete(sizeof(SLMESSAGE),pMsg);
	return TRUE;
}
INT CMFlash_Free(This)
{
	DECLARE_SINGLE_OPEN(CMFlash) 
	pT->DM_free.enable = 1;
    DMfree(&pT->DM_free);
	return pT->DM_free.size;
}
//INT _GLOBAL nVL0,nVL1,nVL2,nVL3,nVL4;
//UDINT _GLOBAL pAddr,pAddr_0;
BOOL CMFlash_ReadFlash(This,BYTE *pbyBuff,WORD wLen)
{
    DECLARE_SINGLE_OPEN(CMFlash) 
	BOOL res = FALSE;
    pT->DOInfo.enable     = 1;
    pT->DOInfo.pName      = (UDINT)pT->m_chName;
    DatObjInfo(&pT->DOInfo);
	//memcpy(&DOInfo_0,&pT->DOInfo,sizeof(DatObjInfo_typ));
	//nVL3++;
    if (pT->DOInfo.status == 0)
	{
     pT->DORead.enable    = 1;
     pT->DORead.ident     = pT->DOInfo.ident;
     pT->DORead.Offset    = 0;
	 pT->DORead.pDestination = (UDINT)pbyBuff;
	 //pAddr = pT->DORead.pDestination;
     pT->DORead.len       = wLen;
     DatObjRead(&pT->DORead);
	 //memcpy(&DORead_0,&pT->DORead,sizeof(DatObjRead_typ));
	 //nVL4++;
     if (pT->DORead.status == 0)res = TRUE; else
	 res = FALSE;
	}
	return res;
}
//USINT _GLOBAL byGlBuff1[200],byGlBuff2[200];
//USINT *pbyBuff_1;
//UINT _GLOBAL status_m;
BOOL CMFlash_CompareMemory(This,BYTE *bySrc,WORD wLen)
{
    DECLARE_SINGLE_OPEN(CMFlash) 
	BOOL res=TRUE;
	WORD i;
	BYTE *pbyBuff;
	New(wLen,pbyBuff);
	//pAddr_0 = pbyBuff;
	if (pT->ReadFlash(pT,pbyBuff,wLen))
	{
	 //nVL0++;
	 for(i=0;i<wLen;i++) 
	 {
	  //if(i<200)
	  //{
	  // byGlBuff1[i] = bySrc[i];
	  // byGlBuff2[i] = pbyBuff[i];
	  //}
	 if(pbyBuff[i]!=bySrc[i])
	 {
	  //nVL1++;
	  res = FALSE;
	  break;
	  //Delete(wLen,pbyBuff);
	  //return FALSE;
	 }
	 }
	}else res = FALSE;
	Delete(wLen,pbyBuff);
    return res;
}
BOOL CMFlash_ClearFlash(This)
{
	DECLARE_SINGLE_OPEN(CMFlash) 
	BOOL res = TRUE;
	pT->DM_clear.enable = 1;
	DMclear(&pT->DM_clear);
	if (pT->DM_clear.status != 0) res = FALSE;
	return res;
}
void CMFlash_CMFlash(This)
{
    DECLARE_SINGLE_OPEN(CMFlash) 
	DECLARE_REGISTRATION(CMFlash,WriteFlash)
	DECLARE_REGISTRATION(CMFlash,WriteFlashRem)
	DECLARE_REGISTRATION(CMFlash,ReadFlash)
	DECLARE_REGISTRATION(CMFlash,CompareMemory)
	DECLARE_REGISTRATION(CMFlash,ClearFlash)
	DECLARE_REGISTRATION(CMFlash,Free)
	pT->m_byFirstBlock    = 1;
	pT->m_byAmBlock       = 1;
	strcpy(pT->m_chName,"FlashModule");
    #ifdef WIN32
	hMFile = CreateFile("mflash.fls", 
		GENERIC_READ|GENERIC_WRITE,  
		FILE_SHARE_READ|FILE_SHARE_WRITE,             
		NULL,                        
		OPEN_ALWAYS,                 
		FILE_ATTRIBUTE_NORMAL,       
		NULL);                       
    #endif
	memset(&pT->DM_free,0,sizeof(DMfree_typ));
	memset(&pT->DM_clear,0,sizeof(DMclear_typ));
	memset(&pT->DM_store,0,sizeof(DMstore_typ));
}
void CMFlash_DCMFlash(This)
{
	DECLARE_SINGLE_OPEN(CMFlash)
}
DECLARE_SINGLE_CREATE(CMFlash)

