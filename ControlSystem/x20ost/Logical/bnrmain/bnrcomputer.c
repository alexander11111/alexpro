/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrcomputer.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
void CComputer_Init(This,SHARDCOMPUTERTABLE *pTable)
{
    DECLARE_SINGLE_OPEN(CComputer)
    #ifdef DEB_CComputer
	Info("\n(__)CCOMP::>Create Computer:%s:%s",pTable->chComputerName,pTable->chDateOfWrite);
    #endif
	pT->InitDevModule(pT,pTable);
}
void CComputer_InitDevModule(This,SHARDCOMPUTERTABLE *pTable)
{
	int i;
	CSlot *m_pSlot;
    DECLARE_SINGLE_OPEN(CComputer)
	New(sizeof(SHARDCOMPUTERTABLE),pT->m_pConfigTable);
	memcpy(pT->m_pConfigTable,pTable,sizeof(SHARDCOMPUTERTABLE));
	pT->m_byComputerType = pTable->byComputerType;
	pT->m_bySlotAmout = pTable->bySlotAmout;
	strcpy(pT->m_chProgrammVersion,pTable->chProgrammVersion);
	strcpy(pT->m_chComputerName,pTable->chComputerName);
	strcpy(pT->m_chDateOfWrite,pTable->chDateOfWrite);
	New(sizeof(CSlot*)*pTable->bySlotAmout,pT->m_pvSlot);
	for(i=0;i<pTable->bySlotAmout;i++)
	{
		m_pSlot = pT->CreateSlot(pT,&pTable->sSlot[i]);
		if(m_pSlot!=NULL)
			pT->Connect(pT,m_pSlot);
	}
}
CSlot* CComputer_CreateSlot(This,SHARDSLOT *psvSlot)
{
    DECLARE_SINGLE_OPEN(CComputer)
	switch(psvSlot->bySlotType)
	{
	   case DEV_PLC_CPU_260:
	   case DEV_PLC_CPU_X20:
            return pT->CreateSlotCPU_260(pT,psvSlot);
       case DEV_TCPCOM_IF_681:
            return pT->CreateSlotIF_681(pT,psvSlot);
	   case DEV_AI_3AI375_6:
		    return pT->CreateSlot3AI375_6(pT,psvSlot);
	   case DEV_DI_X20DI2377:
		    return pT->CreateSlotDI2377(pT,psvSlot);
       case DEV_AI_X20AI2622:
		    return pT->CreateSlot3AI375_6(pT,psvSlot);
	   case DEV_AT_X20AT2222:
		    return pT->CreateSlotAT2222(pT,psvSlot);
	   case DEV_AI_X20AI4622:
	   case DEV_AO_X20AO4622:
		    return pT->CreateSlot3AI4622(pT,psvSlot);
	   case DEV_AO_3AO775_6:
	    	return pT->CreateSlot3AO775_6(pT,psvSlot);
	   case DEV_DI_3DI477_6:
	   case DEV_DI_X20DI9371:
	   case DEV_DI_X20DM9371:
		    return pT->CreateSlot3DI477_6(pT,psvSlot);
	   case DEV_DO_3DO760_6:
	   case DEV_DO_X20DM9322:
	   case DEV_DO_X20DO9321:
		    return pT->CreateSlot3DO477_6(pT,psvSlot);
	   default:
	   break;
	}
    return NULL;
}
CSlot* CComputer_CreateSlotCPU_260(This,SHARDSLOT *psvSlot)
{
	 CDgIOSlot *pHSlot;
     DECLARE_SINGLE_OPEN(CComputer) 
	 New(sizeof(CDgIOSlot),pHSlot);
	 InitObject(CDgIOSlot,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
CSlot* CComputer_CreateSlotIF_681(This,SHARDSLOT *psvSlot)
{
	 CDgIOSlot *pHSlot;
	 DECLARE_SINGLE_OPEN(CComputer) 
	 New(sizeof(CDgIOSlot),pHSlot);
	 InitObject(CDgIOSlot,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
CSlot* CComputer_CreateSlot3DI477_6(This,SHARDSLOT *psvSlot)
{
	 CDgIOSlot *pHSlot;
	 DECLARE_SINGLE_OPEN(CComputer)
	 New(sizeof(CDgIOSlot),pHSlot);
	 InitObject(CDgIOSlot,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
CSlot* CComputer_CreateSlot3DO477_6(This,SHARDSLOT *psvSlot)
{
	 CDgIOSlot *pHSlot;
	 DECLARE_SINGLE_OPEN(CComputer) 
	 New(sizeof(CDgIOSlot),pHSlot);
	 InitObject(CDgIOSlot,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
CSlot* CComputer_CreateSlot3AI375_6(This,SHARDSLOT *psvSlot)
{
	 CAnIOSlot *pHSlot;
	 DECLARE_SINGLE_OPEN(CComputer) 
	 New(sizeof(CAnIOSlot),pHSlot);
	 InitObject(CAnIOSlot,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
CSlot* CComputer_CreateSlotAT2222(This,SHARDSLOT *psvSlot)
{
	CTemperatureSlot *pHSlot;
	DECLARE_SINGLE_OPEN(CComputer) 
	New(sizeof(CTemperatureSlot),pHSlot);
	InitObject(CTemperatureSlot,pHSlot);
	if (pHSlot!=NULL)
	{
	   pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	}else return NULL;
	return pHSlot->pBase;
}
CSlot* CComputer_CreateSlotDI2377(This,SHARDSLOT *psvSlot)
{
	CCountSlot *pHSlot;
	DECLARE_SINGLE_OPEN(CComputer) 
	New(sizeof(CCountSlot),pHSlot);
	InitObject(CCountSlot,pHSlot);
	if (pHSlot!=NULL)
	{
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	}else return NULL;
	return pHSlot->pBase;
}
CSlot* CComputer_CreateSlot3AI4622(This,SHARDSLOT *psvSlot)
{
	 CAnIOSlot4 *pHSlot;
	 DECLARE_SINGLE_OPEN(CComputer) 
	 New(sizeof(CAnIOSlot4),pHSlot);
	 InitObject(CAnIOSlot4,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
CSlot* CComputer_CreateSlot3AO775_6(This,SHARDSLOT *psvSlot)
{
	 CAnIOSlot *pHSlot;
	 DECLARE_SINGLE_OPEN(CComputer) 
	 New(sizeof(CAnIOSlot),pHSlot);
	 InitObject(CAnIOSlot,pHSlot);
	 if (pHSlot!=NULL)
	 {
		pHSlot->pBase->Init(pHSlot->pBase,psvSlot);
	 }else return NULL;
	 return pHSlot->pBase;
}
void CComputer_Connect(This,CSlot *pSlot)
{
     DECLARE_SINGLE_OPEN(CComputer);
     pT->m_pvSlot[pSlot->m_bySlotNumber] = pSlot->pThis; 
}
CSlot* CComputer_GetSlot(This,BYTE byNumber)
{
     DECLARE_SINGLE_OPEN(CComputer)
	 if(byNumber < pT->m_pConfigTable->bySlotAmout)
     return pT->m_pvSlot[byNumber];   
	 return NULL;
}
void CComputer_CComputer(This)
{
     DECLARE_SINGLE_OPEN(CComputer)
	 DECLARE_REGISTRATION(CComputer,Init)
	 DECLARE_REGISTRATION(CComputer,InitDevModule)
	 DECLARE_REGISTRATION(CComputer,Connect)
	 DECLARE_REGISTRATION(CComputer,CreateSlot)
	 DECLARE_REGISTRATION(CComputer,CreateSlotCPU_260)
	 DECLARE_REGISTRATION(CComputer,CreateSlotIF_681)
	 DECLARE_REGISTRATION(CComputer,CreateSlot3DI477_6)
	 DECLARE_REGISTRATION(CComputer,CreateSlot3DO477_6)
	 DECLARE_REGISTRATION(CComputer,CreateSlot3AI375_6)
	 DECLARE_REGISTRATION(CComputer,CreateSlot3AI4622)
	 DECLARE_REGISTRATION(CComputer,CreateSlotAT2222)
	 DECLARE_REGISTRATION(CComputer,CreateSlotDI2377)
	 DECLARE_REGISTRATION(CComputer,CreateSlot3AO775_6)
	 DECLARE_REGISTRATION(CComputer,GetSlot)
}
void CComputer_DCComputer(This)
{
	DECLARE_SINGLE_OPEN(CComputer)
	BYTE i;
	for(i=0;i<pT->m_bySlotAmout;i++)
	{
	 switch(pT->m_pvSlot[i]->m_bySlotType)
	 {
  	   case DEV_DI_3DI477_6:
	   case DEV_DO_3DO760_6:
	   case DEV_PLC_CPU_260:
       case DEV_TCPCOM_IF_681:
            DestroyObject(CDgIOSlot,pT->m_pvSlot[i]->pChld);
	   break;
	   case DEV_AI_3AI375_6:
	   case DEV_AO_3AO775_6:
		    DestroyObject(CAnIOSlot,pT->m_pvSlot[i]->pChld);
	   break;
	   default:
	   break;
	 };
	}
	Delete(sizeof(CSlot*)*pT->m_pConfigTable->bySlotAmout,pT->m_pvSlot);
    DeleteObject(pT->m_pConfigTable); 
}
DECLARE_SINGLE_CREATE(CComputer)

