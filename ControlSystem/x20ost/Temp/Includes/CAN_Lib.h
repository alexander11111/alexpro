/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _CAN_LIB_
#define _CAN_LIB_

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Datatypes and datatypes of function blocks */
typedef struct INFO_typ
{
	unsigned long received;
	unsigned long transmit;
	unsigned long error;
	unsigned long busoff;
	unsigned long warning;
	unsigned long other;
	unsigned long lost;
	unsigned long stufferror;
	unsigned long formerror;
	unsigned long ackerror;
	unsigned long bit1error;
	unsigned long bit0error;
	unsigned long crcerror;
	unsigned long lec0;
	unsigned long rxirq;
	unsigned long txirq;
} INFO_typ;

typedef struct DevParam
{
	unsigned char baudrate;
	unsigned short cob_nr;
	unsigned long pError;
	unsigned long pDevice;
	unsigned short info;
} DevParam;

typedef struct CANinfo
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long info_adr;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANinfo_typ;

typedef struct CANMulQueue
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long pCAN_id;
	unsigned char ID_nr;
	unsigned short size;
	/* VAR_OUTPUT (analog) */
	unsigned long q_ident;
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANMulQueue_typ;

typedef struct CANMulOpen
{
	/* VAR_INPUT (analog) */
	unsigned long pDevParam;
	unsigned char dev_nr;
	/* VAR_OUTPUT (analog) */
	unsigned long us_ident;
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANMulOpen_typ;

typedef struct CANMulrd
{
	/* VAR_INPUT (analog) */
	unsigned long q_ident;
	unsigned long data_adr;
	/* VAR_OUTPUT (analog) */
	unsigned short size;
	unsigned long ID;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANMulrd_typ;

typedef struct CANTime
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned long pSystemTick;
	unsigned long pSystemStamp;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long old_id;
	unsigned long cob_handle;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANTime_typ;

typedef struct CANquwr
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned long data_adr;
	unsigned char data_lng;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANquwr_typ;

typedef struct SetNdNr
{
	/* VAR_INPUT (analog) */
	unsigned long device;
	unsigned char nodenr;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SetNdNr_typ;

typedef struct GetNdNr
{
	/* VAR_INPUT (analog) */
	unsigned long dev_adr;
	/* VAR_OUTPUT (analog) */
	unsigned char nodenr;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} GetNdNr_typ;

typedef struct CMSmain
{
	/* VAR_INPUT (analog) */
	unsigned long cms_ident;
	unsigned long cms_mode;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CMSmain_typ;

typedef struct CMSinit
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned char user_type;
	unsigned short queue_cnt;
	unsigned long modul_name;
	/* VAR_OUTPUT (analog) */
	unsigned short cms_entry;
	unsigned long cms_ident;
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CMSinit_typ;

typedef struct CMSdlreq
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long client_id;
	unsigned long server_id;
	unsigned long mult;
	unsigned long data_adr;
	unsigned long data_len;
	/* VAR_OUTPUT (analog) */
	unsigned short add_code;
	unsigned char err_class;
	unsigned char err_code;
	unsigned long dl_len;
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit initiate;
	/* VAR (digital) */
	plcbit old_enable;
} CMSdlreq_typ;

typedef struct CMSdlcon
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long client_id;
	unsigned long server_id;
	unsigned long data_adr;
	unsigned long data_len;
	/* VAR_OUTPUT (analog) */
	unsigned short add_code;
	unsigned char err_class;
	unsigned char err_code;
	unsigned long mult;
	unsigned long dl_len;
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit initiate;
	/* VAR (digital) */
	plcbit old_enable;
} CMSdlcon_typ;

typedef struct CANxnode
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	/* VAR_OUTPUT (analog) */
	unsigned char node_nr;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANxnode_typ;

typedef struct CANwrite
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned long data_adr;
	unsigned char data_lng;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long old_id;
	unsigned long cob_handle;
	unsigned long init_cnt;
	unsigned char wr_order;
	unsigned char align_byte;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANwrite_typ;

typedef struct CANupd
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned long data_adr;
	unsigned char data_lng;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long old_id;
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANupd_typ;

typedef struct CANngp
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned char nd_state;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long old_id;
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANngp_typ;

typedef struct CANrwtab
{
	/* VAR_INPUT (analog) */
	unsigned long tab_ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANrwtab_typ;

typedef struct CANrtr
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned long data_adr;
	/* VAR_OUTPUT (analog) */
	unsigned char data_lng;
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit request;
	/* VAR (digital) */
	plcbit old_enable;
} CANrtr_typ;

typedef struct CANread
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned long data_adr;
	/* VAR_OUTPUT (analog) */
	unsigned char data_lng;
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANread_typ;

typedef struct CANrd
{
	/* VAR_INPUT (analog) */
	unsigned long q_ident;
	unsigned long data_adr;
	/* VAR_OUTPUT (analog) */
	unsigned short size;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANrd_typ;

typedef struct CANqueue
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned short size;
	/* VAR_OUTPUT (analog) */
	unsigned long q_ident;
	unsigned short status;
	/* VAR (analog) */
	unsigned long cob_handle;
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANqueue_typ;

typedef struct CANopen
{
	/* VAR_INPUT (analog) */
	unsigned char baud_rate;
	unsigned short cob_anz;
	unsigned long error_adr;
	unsigned long device;
	unsigned short info;
	/* VAR_OUTPUT (analog) */
	unsigned long us_ident;
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANopen_typ;

typedef struct CANnode
{
	/* VAR_OUTPUT (analog) */
	unsigned char node_nr;
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANnode_typ;

typedef struct CANgetid
{
	/* VAR_INPUT (analog) */
	unsigned long data_adr;
	/* VAR_OUTPUT (analog) */
	unsigned char data_lng;
	unsigned long can_id;
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANgetid_typ;

typedef struct CANexcep
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long can_id;
	unsigned char exc_nr;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	unsigned long cob_handle;
	unsigned long ex_p;
	unsigned long ex_maxtask;
	unsigned long ss_irqvw_p;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANexcep_typ;

typedef struct CANdftab
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long table_adr;
	unsigned short tab_num;
	/* VAR_OUTPUT (analog) */
	unsigned long tab_ident;
	unsigned short status;
	/* VAR (analog) */
	unsigned long init_cnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit old_enable;
} CANdftab_typ;

typedef struct CANbtreg
{
	/* VAR_INPUT (analog) */
	unsigned long us_ident;
	unsigned long treg0;
	unsigned long treg1;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CANbtreg_typ;



/* Prototyping of functions and function blocks */
void CANinfo(struct CANinfo* inst);
void CANMulQueue(struct CANMulQueue* inst);
void CANMulOpen(struct CANMulOpen* inst);
void CANMulrd(struct CANMulrd* inst);
void CANTime(struct CANTime* inst);
void CANquwr(struct CANquwr* inst);
void SetNdNr(struct SetNdNr* inst);
void GetNdNr(struct GetNdNr* inst);
void CMSmain(struct CMSmain* inst);
void CMSinit(struct CMSinit* inst);
void CMSdlreq(struct CMSdlreq* inst);
void CMSdlcon(struct CMSdlcon* inst);
void CANxnode(struct CANxnode* inst);
void CANwrite(struct CANwrite* inst);
void CANupd(struct CANupd* inst);
void CANngp(struct CANngp* inst);
void CANrwtab(struct CANrwtab* inst);
void CANrtr(struct CANrtr* inst);
void CANread(struct CANread* inst);
void CANrd(struct CANrd* inst);
void CANqueue(struct CANqueue* inst);
void CANopen(struct CANopen* inst);
void CANnode(struct CANnode* inst);
void CANgetid(struct CANgetid* inst);
void CANexcep(struct CANexcep* inst);
void CANdftab(struct CANdftab* inst);
void CANbtreg(struct CANbtreg* inst);



#endif /* _CAN_LIB_ */

