/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/
#if !defined(__PRI2AUT_H__)
#define __PRI2AUT_H__
#include "typedefs.h"
Class CAuto
{
Public
    void (*CCAuto)(This);
    void (*DCAuto)(This);
    BOOL (*SetState)(This,TStateCode vNewState);
    TStateCode (*GetStateCode)(This);
    BOOL (*HandleEvent)(This,TEvent vEvent);
Protected
    Virtual BOOL (*HandleTask)(This,TTask* pvTask);
    Virtual TStateList* (*GetStateList)(This);
    TState* (*GetState)(This);
Protected
    BYTE v[20];
    TState*  m_pvState; 
    TStateCode m_vState;   
    DECLARE_IMPLEMENT
}
DECLARE_DEFINITION(CAuto)
#endif //!defined(__AUTOMAT_H__)
