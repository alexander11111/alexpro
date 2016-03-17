(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG
 ********************************************************************
 * Library: DM_lib
 * File: DM_lib.fun
 * Created: 11.11.2003
 ********************************************************************
 * Functions and function blocks of library DM_lib
 ********************************************************************)
FUNCTION_BLOCK DMxstore				(*Saves a data object in a 64 KB block of the data memory.*)
	VAR_INPUT
		enable	:BOOL;				(*The function block instructions are only executed if enable = TRUE.*)
		block_no	:USINT;			(*block number in the Application Flash PROM: 1 ... last 64 KB block, ...*)
		name	:UDINT;				(*name of the data object generated (given as a pointer)*)
		data	:UDINT;				(*address of the data that is to be copied to the data section*)
		size	:UDINT;				(*determines size of the data section*)
		ident	:UDINT;				(*If a valid ID of a data object is given at this input, a copy of this reference module is generated.*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DMstore				(*Saves a data object in the last 64 KB block of the data memory.*)
	VAR_INPUT
		enable	:BOOL;				(*The function block instructions are only executed if enable = TRUE.*)
		name	:UDINT;				(*name of the data object generated (given as a pointer)*)
		data	:UDINT;				(*address of the data that is to be copied to the data section*)
		size	:UDINT;				(*determines size of the data section*)
		ident	:UDINT;				(*If a valid ID of a data object is given at this input, a copy of this reference module is generated.*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR		
END_FUNCTION_BLOCK

FUNCTION_BLOCK DMxfree				(*Returns the size of the free memory in the specified 64 KB block of the data memory.*)
	VAR_INPUT
		enable	:BOOL;				(*The function block instructions are only executed if enable = TRUE.*)
		block_no	:USINT;			(*block number in the Application Flash PROM: 1 ... last 64 KB block, ...*)
	END_VAR
	VAR_OUTPUT
		size	:UDINT;				(*Corresponds to the free memory in the last 64 KB block of the data memory (given in bytes).*)
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DMfree				(*Returns the size of the free memory in the last 64 KB block of the data memory.*)
	VAR_INPUT		
		enable	:BOOL;				(*The function block instructions are only executed if enable = TRUE.*)
	END_VAR		
	VAR_OUTPUT
		size	:UDINT;				(*Corresponds to the free memory in the last 64 KB block of the data memory (given in bytes).*)
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DMxclear				(*Clears the data memory in a 64 KB block of the Application Flash PROM.*)
	VAR_INPUT
		enable	:BOOL;				(*The function block instructions are only executed if enable = TRUE.*)
		block_no	:USINT;			(*block number in the Application Flash PROM: 1 ... last 64 KB block, ...*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DMclear				(*Clears the data memory in the last 64 KB block of the Application Flash PROM.*)
	VAR_INPUT
		enable	:BOOL;				(*The function block instructions are only executed if enable = TRUE.*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK
