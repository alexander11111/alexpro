/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MULTI_H__
#define __MULTI_H__
#include "typedefs.h"
#include "single.h"
Class CMulti
{
	 void (*CCMulti)(This);
	 void (*DCMulti)(This);
Public
	 DECLARE_IMPLEMENT_BASE(CSingle)
}
DECLARE_DEFINITION(CMulti)
#endif
