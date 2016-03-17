#ifndef __BNRPOB_H__
#define __BNRPOB_H__
#define MAXNAMEBUF 20
#include "typedefs.h"
#include "bnrdebug.h"

//#define  DEF_PUT_BOX 
//#define  DEF_GET_BOX 
//#define  DEF_INF_BOX
//#define  DEF_CRT_BOX
#define BOX_TRANS_SIZE 256
typedef struct pBufferHiLev
{
     BYTE *pb_mBoxCont;
     WORD w_mBoxWrite;
     WORD w_mBoxRead;
     WORD w_mBoxSize;
     WORD w_mBoxCSize;
     WORD w_mBoxMesCt;
}pBOX;
int  FDEFINE(BYTE b_lNmBox,WORD w_lBoxSize);
int  FPUT(BYTE b_lNmBox,BYTE *pb_lInBox);
int  FGET(BYTE b_lNmBox,BYTE *pb_lInBox);
int  FCHECK(BYTE b_lNmBox);
void FDELETE(BYTE b_lNmBox);
void FFREE(BYTE b_lNmBox);
void FINIT(void);
int  FGET1(BYTE b_lNmBox,BYTE *pb_lInBox);
int  FPUT1(BYTE b_lNmBox,BYTE *pb_lInBox);
int  FCHECKM(BYTE b_lNmBox);
void FSMRB(BYTE b_lNmBox);
int  FFREEM(BYTE b_lNmBox);
#endif
