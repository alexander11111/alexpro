/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _DM_LIB_
#define _DM_LIB_

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Datatypes and datatypes of function blocks */
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
	plcbit enable;
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
	plcbit enable;
} DMstore_typ;

typedef struct DMxfree
{
	/* VAR_INPUT (analog) */
	unsigned char block_no;
	/* VAR_OUTPUT (analog) */
	unsigned long size;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DMxfree_typ;

typedef struct DMfree
{
	/* VAR_OUTPUT (analog) */
	unsigned long size;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DMfree_typ;

typedef struct DMxclear
{
	/* VAR_INPUT (analog) */
	unsigned char block_no;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DMxclear_typ;

typedef struct DMclear
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DMclear_typ;



/* Prototyping of functions and function blocks */
void DMxstore(struct DMxstore* inst);
void DMstore(struct DMstore* inst);
void DMxfree(struct DMxfree* inst);
void DMfree(struct DMfree* inst);
void DMxclear(struct DMxclear* inst);
void DMclear(struct DMclear* inst);



#endif /* _DM_LIB_ */

