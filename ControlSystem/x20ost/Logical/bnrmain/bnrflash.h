/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MFLASH_H__
#define __MFLASH_H__
#include "typedefs.h"
#include "bnrmessage.h"
#ifndef WIN32
 #include <DM_Lib.h>
 #include <dataobj.h>
#else
/* Datatypes and datatypes of function blocks */
#define doERR_MODULNOTFOUND 0
typedef struct DatObjInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	unsigned long pDatObjMem;
	unsigned long len;
	unsigned char MemType;
	unsigned long Option;
	BOOL ChangeDate;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DatObjInfo_typ;
typedef struct DatObjRead
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long Offset;
	unsigned long pDestination;
	unsigned long len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DatObjRead_typ;  
typedef struct DMxstore
{
	/* VAR_INPUT (analog) */
	unsigned char block_no;
	unsigned long name;
	unsigned long data;
	unsigned long size;
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DMxstore_typ;

typedef struct DMstore
{
	/* VAR_INPUT (analog) */
	unsigned long name;
	unsigned long data;
	unsigned long size;
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DMstore_typ;

typedef struct DMxfree
{
	/* VAR_INPUT (analog) */
	unsigned char block_no;
	/* VAR_OUTPUT (analog) */
	unsigned long size;
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DMxfree_typ;

typedef struct DMfree
{
	/* VAR_OUTPUT (analog) */
	unsigned long size;
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DMfree_typ;

typedef struct DMxclear
{
	/* VAR_INPUT (analog) */
	unsigned char block_no;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DMxclear_typ;

typedef struct DMclear
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	BOOL enable;
} DMclear_typ;
/* Prototyping of functions and function blocks */
void DMxstore(struct DMxstore* inst);
void DMstore(struct DMstore* inst);
void DMxfree(struct DMxfree* inst);
void DMfree(struct DMfree* inst);
void DMxclear(struct DMxclear* inst);
void DMclear(struct DMclear* inst);
#endif
Class CMFlash
{
	 void (*CCMFlash)(This);
	 void (*DCMFlash)(This);
Public
     BOOL (*WriteFlash)(This,BYTE *pbyBuff,WORD wLen);
     BOOL (*WriteFlashRem)(This,BYTE *pbyBuff,WORD wLen);
     BOOL (*ReadFlash)(This,BYTE *pbyBuff,WORD wLen);
	 BOOL (*CompareMemory)(This,BYTE *bySrc,WORD wLen);
	 INT  (*Free)(This);
	 BOOL (*ClearFlash)(This);
Private
     char m_chName[30];
     BYTE m_byFirstBlock;
     BYTE m_byAmBlock;
	 DMfree_typ  DM_free;
     DMstore_typ DM_store;
     DMclear_typ DM_clear;
	 DatObjRead_typ DORead;
     DatObjInfo_typ DOInfo;
  	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CMFlash)
#endif
