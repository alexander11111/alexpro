/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _LIBRARIES_20130305193028_
#define _LIBRARIES_20130305193028_

__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CAN_Lib/CAN_Lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsTCP/AsTCP.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/dvframe/dvframe.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Convert/Convert.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DM_lib/dm_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/CAN_Lib/CAN_Lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsTCP/AsTCP.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/dvframe/dvframe.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsTCP/AsTCP.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/dvframe/dvframe.var\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */
#ifdef _CONVERT_EXPORT
	__asm__(".ascii\"plcexport \\\"swapUDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"swapDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"swapUINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"swapINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HDT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HTIME\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HUDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HUINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"N_TO_HINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NDT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NTIME\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NUDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NUINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"H_TO_NINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DT_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DT_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TIME_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TIME_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TIME_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SINT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_DT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_TIME\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"BOOL_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"INT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_DT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_TIME\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DINT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"USINT_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_DT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_TIME\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UDINT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UINT_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_LREAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_SINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"REAL_TO_BOOL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_REAL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_UDINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_UINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_USINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_DINT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_INT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LREAL_TO_SINT\\\"\\n\"");
#endif
#ifdef _RUNTIME_EXPORT
	__asm__(".ascii\"plcexport \\\"r_trig\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"f_trig\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"rf_trig\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"GetTime\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SFCActionControl\\\"\\n\"");
#endif
#ifdef _OPERATOR_EXPORT
	__asm__(".ascii\"plcexport \\\"SIZEOF\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ADR\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SHR\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ROR\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ROL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SHL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AND\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"XOR\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"OR\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"NOT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ADD\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MUL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SUB\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DIV\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MOD\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MOVE\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MAX\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MIN\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LIMIT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SEL\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MUX\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"GE\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"EQ\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"GT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LE\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"NE\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ABS\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SQRT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LN\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"LOG\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"EXP\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SIN\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"COS\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TAN\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ASIN\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ACOS\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ATAN\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"EXPT\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TRUNC\\\"\\n\"");
#endif
#ifdef _DATAOBJ_EXPORT
	__asm__(".ascii\"plcexport \\\"DatObjCreate\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjWrite\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjRead\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjDelete\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjMove\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjCopy\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjInfo\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DatObjChangeDate\\\"\\n\"");
#endif
#ifdef _DM_LIB_EXPORT
	__asm__(".ascii\"plcexport \\\"DMxstore\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DMstore\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DMxfree\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DMfree\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DMxclear\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DMclear\\\"\\n\"");
#endif
#ifdef _SYS_LIB_EXPORT
	__asm__(".ascii\"plcexport \\\"MO_ver\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ERRxfatal\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_xlist\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"Byte2Bit\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"Bit2Byte\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_ninfo\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_item\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_ident\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"KEY_read\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_sleep\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_exit\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_fix\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_info\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_copy\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_store\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_burn\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_delete\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_ident\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_read\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_write\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DA_create\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DIS_clr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DIS_chr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"DIS_str\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ERR_read\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ERRxread\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ERR_fatal\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ERR_warning\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ERRxwarning\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SM_release\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SM_attach\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SM_delete\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SM_ident\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SM_create\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TIM_ticks\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TIM_musec\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SW_settime\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SW_gettime\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"RTC_settime\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"RTC_gettime\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TMP_free\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TMP_alloc\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MEM_free\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MEM_alloc\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AVT_info\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AVT_release\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AVT_attach\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AVT_ident\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AVT_cancel\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"AVT_create\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_freemsg\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_recmsg\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_sendmsg\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_resume\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_suspend\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"UT_ident\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_name\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_info\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_allsuspend\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_tmp_resume\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_tmp_suspend\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_resume\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_suspend\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"ST_ident\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FORCE_info\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"KEY_enadis\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"MO_list\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SYS_battery\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SYSreset\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SYSxinfo\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SYS_info\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_list\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_info\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_xgetval\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_xsetval\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_xgetadr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_getadr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_getval\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"PV_setval\\\"\\n\"");
#endif
#ifdef _CAN_LIB_EXPORT
	__asm__(".ascii\"plcexport \\\"CANinfo\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANMulQueue\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANMulOpen\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANMulrd\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANTime\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANquwr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"SetNdNr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"GetNdNr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CMSmain\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CMSinit\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CMSdlreq\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CMSdlcon\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANxnode\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANwrite\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANupd\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANngp\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANrwtab\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANrtr\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANread\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANrd\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANqueue\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANopen\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANnode\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANgetid\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANexcep\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANdftab\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"CANbtreg\\\"\\n\"");
#endif
#ifdef _ASTCP_EXPORT
	__asm__(".ascii\"plcexport \\\"TcpOpen\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TcpServer\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TcpClient\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TcpClose\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TcpSend\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TcpRecv\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"TcpIoctl\\\"\\n\"");
#endif
#ifdef _DVFRAME_EXPORT
	__asm__(".ascii\"plcexport \\\"FRM_mode\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_ctrl\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_robuf\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_gbuf\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_rbuf\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_close\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_write\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_read\\\"\\n\"");
	__asm__(".ascii\"plcexport \\\"FRM_xopen\\\"\\n\"");
#endif

__asm__(".previous");


#endif /* _LIBRARIES_20130305193028_ */

