/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/
#include "bnrauto.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
DECLARE_TASKCHAIN(Skip)
{
    {EXIT_D}
};
DECLARE_STATE(BadState)
{
    {EV_UNKNOWN_REQ, Skip}
};
DECLARE_STATELIST(StateList)
{
    {S_BAD, BadState}
};
BOOL CAuto_SetState(This,TStateCode vNewState)
{
	DECLARE_SINGLE_OPEN(CAuto)
    TStateList * pvList = pT->GetStateList(pC);
    pT->m_pvState = pvList[(INT16)vNewState].m_pvState;
    pT->m_vState  = vNewState;
	pT->v[STATE] = vNewState;
    return TRUE;
}
BOOL CAuto_HandleEvent(This,TEvent vEvent)
{
	DECLARE_SINGLE_OPEN(CAuto)
	TState* pvState;
    for(pvState=pT->m_pvState; pvState->m_vEvent!=EV_UNKNOWN_REQ; pvState++)
    {
        if(pvState->m_vEvent==vEvent)
        {
            return pT->HandleTask(pC,pvState->m_pvTask);
        }
    }
    return FALSE;
}
BOOL CAuto_HandleTask(This,TTask* pvTask)
{   
	DECLARE_SINGLE_OPEN(CAuto)
    return (*pvTask==EXIT_D)?TRUE:FALSE;
}
TStateList* CAuto_GetStateList(This)
{   
	DECLARE_SINGLE_OPEN(CAuto)
    return (TStateList*)&StateList;
}
TStateCode CAuto_GetStateCode(This)
{   
	DECLARE_SINGLE_OPEN(CAuto)
	return pT->m_vState;
}
TState* CAuto_GetState(This)
{ 
	DECLARE_SINGLE_OPEN(CAuto)
	return pT->m_pvState;
}
void CAuto_CAuto(This)
{   
    DECLARE_SINGLE_OPEN(CAuto)
	DECLARE_REGISTRATION(CAuto,GetStateList)
	DECLARE_REGISTRATION(CAuto,HandleTask)
	DECLARE_REGISTRATION(CAuto,HandleEvent)
	DECLARE_REGISTRATION(CAuto,SetState)
	DECLARE_REGISTRATION(CAuto,GetStateCode)
	DECLARE_REGISTRATION(CAuto,GetState)
    pT->m_pvState = BadState;
    pT->m_vState  = S_BAD;
}
void CAuto_DCAuto(This)
{  
	DECLARE_SINGLE_OPEN(CAuto)
}
DECLARE_SINGLE_CREATE(CAuto)