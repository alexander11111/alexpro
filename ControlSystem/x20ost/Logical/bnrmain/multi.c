/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "multi.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
void CMulti_CMulti(This)
{
    DECLARE_MULTI_OPEN(CMulti,CSingle) 
}
void CMulti_DCMulti(This)
{
	DECLARE_MULTI_OPEN(CMulti,CSingle)
}
DECLARE_MULTI_CREATE(CMulti,CSingle)

