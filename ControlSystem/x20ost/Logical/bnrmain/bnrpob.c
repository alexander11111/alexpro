#include "bnrpob.h"
#include "bnrmessage.h"
#ifndef WIN32
_GLOBAL pBOX pBufferHiLev[MAXNAMEBUF];
_GLOBAL pBOX nMirrorBuffer;
_GLOBAL BOOL blSMB;
#else
pBOX pBufferHiLev[MAXNAMEBUF];
pBOX nMirrorBuffer;
BOOL blSMB;
#endif
void FFREE(BYTE b_lNmBox)
{
	pBOX *p;
	if(b_lNmBox>MAXNAMEBUF) return;
	nMirrorBuffer.pb_mBoxCont = 0;
	nMirrorBuffer.w_mBoxMesCt = 1;
	blSMB = FALSE;
	p = &pBufferHiLev[b_lNmBox];
	p->w_mBoxSize  = p->w_mBoxCSize;
    p->w_mBoxWrite = 0;
    p->w_mBoxRead  = 0;
    p->w_mBoxMesCt = 0;
}
void FINIT(void)
{
	//BYTE i;
	//for(i=0;i<MAXNAMEBUF-1;i++)pBufferHiLev[i].pb_mBoxCont = 1;
}
int FDEFINE(BYTE b_lNmBox,WORD w_lBoxSize)
{
	pBOX *p;
    if(b_lNmBox>MAXNAMEBUF) return NULL;
	p = &pBufferHiLev[b_lNmBox];
	//if(p->pb_mBoxCont!=1) return b_lNmBox;
	New(sizeof(BYTE)*(w_lBoxSize+BOX_TRANS_SIZE),p->pb_mBoxCont);
    if(p==NULL) return NULL;
	p->w_mBoxSize  = w_lBoxSize;
    p->w_mBoxCSize = w_lBoxSize;
    p->w_mBoxWrite = 0;
    p->w_mBoxRead  = 0;
    p->w_mBoxMesCt = 0;
    #ifdef DEF_CRT_BOX
	Info("\n(%b)CSBOX::>Create System Box.Size:%w",&b_lNmBox,&pBufferHiLev[b_lNmBox]->w_mBoxCSize);
    //Info("\n(%b)CRT:BOX:>:AD[%a]:WR[%w]:RD[%w]:SZ[%w]:CT[%w]",&b_lNmBox,&p,&p->w_mBoxWrite,&p->w_mBoxRead,&p->w_mBoxSize,&p->w_mBoxMesCt);
    #endif
    return 1;
}
void FDELETE(BYTE b_lNmBox)
{
	pBOX *p;
	p = &pBufferHiLev[b_lNmBox];
    Delete(p->w_mBoxCSize+BOX_TRANS_SIZE,p->pb_mBoxCont);
    p->pb_mBoxCont = 0;
    #ifdef DEF_CRT_BOX
    Info("\n(%b)DEL:BOX",&b_lNmBox);
    #endif
}
int FCHECK(BYTE b_lNmBox)
{
    return pBufferHiLev[b_lNmBox].w_mBoxMesCt;
}
int FCHECKM(BYTE b_lNmBox)
{
	if(!blSMB) 
	{
	 memcpy(&nMirrorBuffer,&pBufferHiLev[b_lNmBox],sizeof(pBOX));
	 blSMB = TRUE;
	}
    return nMirrorBuffer.w_mBoxMesCt;
}
int FPUT(BYTE b_lNmBox,BYTE *pb_lInBox)
{
	pBOX *p;
    WORD w_lLength;
	p = &pBufferHiLev[b_lNmBox];
    w_lLength = *(WORD*)pb_lInBox;
    if(!p->pb_mBoxCont)return 0;
    if((w_lLength>p->w_mBoxSize)||(w_lLength<2))return 0;
	memcpy(&p->pb_mBoxCont[p->w_mBoxWrite],pb_lInBox,w_lLength);
    p->w_mBoxWrite += w_lLength;
    p->w_mBoxSize  -= w_lLength;
    p->w_mBoxMesCt ++;
    if(p->w_mBoxWrite>p->w_mBoxCSize) p->w_mBoxWrite = 0;
    #ifdef DEF_INF_BOX
    Info("\n(%b)PUTB:>:LN[%w]:WR[%w]:RD[%w]:SZ[%w]:CT[%w]",&b_lNmBox,&w_lLength,&p->w_mBoxWrite,&p->w_mBoxRead,&p->w_mBoxSize,&p->w_mBoxMesCt);
    #endif
    #ifdef DEF_PUT_BOX
    Info("\n(%b)PUTB[%w]:>:%m",&b_lNmBox,&p->w_mBoxMesCt,pb_lInBox);
    #endif
    return 1;
}
int FPUT1(BYTE b_lNmBox,BYTE *pb_lInBox)
{
	if(FPUT(b_lNmBox,pb_lInBox)==0)
	{
     FFREEM(b_lNmBox);
	 if(FPUT(b_lNmBox,pb_lInBox)==0)
	 return 0;
	}
	return 1;
}
int FFREEM(BYTE b_lNmBox)
{
    pBOX *p;
	BYTE *pb_lLength;
	WORD  wLng;
    p = &pBufferHiLev[b_lNmBox];
	if(!p->pb_mBoxCont)return 0;
	if(!p->w_mBoxMesCt)return 0;
    pb_lLength = (BYTE*)&p->pb_mBoxCont[p->w_mBoxRead];
    #ifdef WIN32
	wLng = (((WORD)pb_lLength[1])<<8)|(WORD)pb_lLength[0];
    #else
	wLng = (((WORD)pb_lLength[0])<<8)|(WORD)pb_lLength[1];
    #endif
    //memcpy(pb_lInBox,pb_lLength,wLng);
    p->w_mBoxRead += wLng;
    p->w_mBoxSize += wLng;
    p->w_mBoxMesCt --;
    if(p->w_mBoxRead>p->w_mBoxCSize) p->w_mBoxRead = 0;
    return 1;
}
void FSMRB(BYTE b_lNmBox)
{
    memcpy(&nMirrorBuffer,&pBufferHiLev[b_lNmBox],sizeof(pBOX));
	blSMB = FALSE;
}
int FGET1(BYTE b_lNmBox,BYTE *pb_lInBox)
{
	pBOX *p;
	BYTE *pb_lLength;
	WORD  wLng;
	p = &nMirrorBuffer;
	if(!p->pb_mBoxCont)return 0;
	if(!p->w_mBoxMesCt)return 0;
    pb_lLength = (BYTE*)&p->pb_mBoxCont[p->w_mBoxRead];
    #ifdef WIN32
	wLng = (((WORD)pb_lLength[1])<<8)|(WORD)pb_lLength[0];
    #else
	wLng = (((WORD)pb_lLength[0])<<8)|(WORD)pb_lLength[1];
    #endif
    memcpy(pb_lInBox,pb_lLength,wLng);
    p->w_mBoxRead += wLng;
    p->w_mBoxSize += wLng;
    p->w_mBoxMesCt --;
    if(p->w_mBoxRead>p->w_mBoxCSize) p->w_mBoxRead = 0;
    return 1;
}
int FGET(BYTE b_lNmBox,BYTE *pb_lInBox)
{
    pBOX *p;
	BYTE *pb_lLength;
	WORD  wLng;
    p = &pBufferHiLev[b_lNmBox];
	if(!p->pb_mBoxCont)return 0;
	if(!p->w_mBoxMesCt)return 0;
    pb_lLength = (BYTE*)&p->pb_mBoxCont[p->w_mBoxRead];
    #ifdef WIN32
	wLng = (((WORD)pb_lLength[1])<<8)|(WORD)pb_lLength[0];
    #else
	wLng = (((WORD)pb_lLength[0])<<8)|(WORD)pb_lLength[1];
    #endif
    memcpy(pb_lInBox,pb_lLength,wLng);
    p->w_mBoxRead += wLng;
    p->w_mBoxSize += wLng;
    p->w_mBoxMesCt --;
    if(p->w_mBoxRead>p->w_mBoxCSize) p->w_mBoxRead = 0;
    #ifdef DEF_INF_BOX
    Info("\n(%b)GETB:>:LN[%w]:WR[%w]:RD[%w]:SZ[%w]:CT[%w]",&b_lNmBox,(WORD*)pb_lLength,&p->w_mBoxWrite,&p->w_mBoxRead,&p->w_mBoxSize,&p->w_mBoxMesCt);
    #endif
    #ifdef DEF_GET_BOX
    Info("\n(%b)GETB[%w]:>:%m",&b_lNmBox,&p->w_mBoxMesCt,pb_lInBox);
    #endif
    return 1;
}

  