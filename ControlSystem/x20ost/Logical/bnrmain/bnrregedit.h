/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __REGEDIT_H__
#define __REGEDIT_H__
#include "typedefs.h"
#include "bnrmessage.h"
#include "bnrpob.h"
Class CRegModule
{
	 void (*CCRegModule)(This);
	 void (*DCRegModule)(This);
Public
     void (*Init)(This);
     BYTE (*QueryParam)(This,SREGADDR *pA);
	 BYTE (*SaveParam)(This,SREGPARAM *pA);
	 BYTE (*CreateKpParam)(This,SREGADDR *pA);
	 BYTE (*CreatePortParam)(This,SREGADDR *pA);
	 BYTE (*CreateHardParam)(This,SREGADDR *pA);
	 BYTE (*CreateSoftTIParam)(This,SREGADDR *pA);
	 BYTE (*CreateSoftTSParam)(This,SREGADDR *pA);
	 BYTE (*CreateSoftTUParam)(This,SREGADDR *pA);
	 BYTE (*CreateSoftTRParam)(This,SREGADDR *pA);

	 BYTE (*SetKpParam)(This,SREGPARAM *pA);
	 BYTE (*SetPortParam)(This,SREGPARAM *pA);
	 BYTE (*SetHardParam)(This,SREGPARAM *pA);
	 BYTE (*SetSoftTIParam)(This,SREGPARAM *pA);
	 BYTE (*SetSoftTSParam)(This,SREGPARAM *pA);
	 BYTE (*SetSoftTUParam)(This,SREGPARAM *pA);
	 BYTE (*SetSoftTRParam)(This,SREGPARAM *pA);
	 void (*CopyW)(This,PVOID pvDst,PVOID pvSrc);
Private
     SSOFTSWITCHTABLE   *m_pSCT;
     SHARDCOMPUTERTABLE *m_pHCT;
	 DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CRegModule)
#endif
