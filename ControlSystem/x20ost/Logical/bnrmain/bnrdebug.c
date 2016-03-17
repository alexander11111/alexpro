#include "bnrdebug.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "bnrmessage.h"
#define LenBuf  1500        
#define LenBuf2 50                        
BYTE    HEX[] = "0123456789ABCDEF";    
BYTE    st1[]={2,'^'};                 
BYTE    st2[]={3,'~','\n'};       
BYTE    Str[]="\nInfo: Error:";  
SLMESSAGE *m_pDebMsg;     
BYTE  *DebugBufO;
void Info (char * Format,...)

{
  int     a,l,i,j,m;
  va_list arg;
  BYTE    c, *cp;
  va_start (arg,Format);
  DebugBufO = &m_pDebMsg->m_sbyInfo[0];
  for(j=1,i=0;(c=Format[i]) !=0 ; i++)
  {
   if (c!='%')
   {
    if(j==LenBuf){
     j=OutFrame(j,DebugBufO);
    }
    DebugBufO[j++]=c;
   }
   else
    switch(Format[++i])
    {
     case 'a':  if(j+9 > LenBuf){
                 j=OutFrame(j,DebugBufO);
                }
                cp=va_arg(arg, BYTE *);
                c=*(cp+3);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                c=*(cp+2);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                DebugBufO[j++]=':';
                c=*(cp+1);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                c=*cp;
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                break;
     case 's':  cp=va_arg(arg, BYTE *);
                while((c=*(cp++))!=0)
                {
                 if(j == LenBuf){
                  j=OutFrame(j,DebugBufO);
                 }
                 DebugBufO[j++]=c;
                }
                break;
     case 'm':
                 cp=va_arg(arg, BYTE*);
                c=l=*(cp++); 
                if(j+3 > LenBuf){
                 j=OutFrame(j,DebugBufO);
                 DebugBufO[j++]='\n';
                }
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                DebugBufO[j++]='_';
                for (a=1,m=0; a<l; a++,m++)
                {
                 if(j+5 > LenBuf){
                  j=OutFrame(j,DebugBufO);    
                  DebugBufO[j++]='\n';
                 }
                 if (m==2){
                  DebugBufO[j++]='_';
                  m=0;
                 }
                 c=*(cp++);
                 DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                 DebugBufO[j++]=HEX[c & 0x0f];
                }
                break;
	  case 'M':
		        cp=va_arg(arg, BYTE*);
		        c=*cp; 
		        l=*(WORD*)(cp++);
		        if(j+3 > LenBuf){
			    j=OutFrame(j,DebugBufO);
			    DebugBufO[j++]='\n';
				}
				DebugBufO[j++]=HEX[(c>>4) & 0x0f];
				DebugBufO[j++]=HEX[c & 0x0f];
				DebugBufO[j++]='_';
				for (a=1,m=0; a<l; a++,m++)
				{
				if(j+5 > LenBuf){
				j=OutFrame(j,DebugBufO);    
				DebugBufO[j++]='\n';
				}
				if (m==2){
				 DebugBufO[j++]='_';
				 m=0;
				}
				c=*(cp++);
				DebugBufO[j++]=HEX[(c>>4) & 0x0f];
				DebugBufO[j++]=HEX[c & 0x0f];
				}
                break;
     case 'w':  if(j+4 > LenBuf){
                 j=OutFrame(j,DebugBufO);
                }
                cp=va_arg(arg, BYTE*);
                c=*(cp+1);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                c=*cp;
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                break;
     case 'b':  if(j+2 > LenBuf){
                 j=OutFrame(j,DebugBufO);
                }
                cp=va_arg(arg, BYTE *);
                c=*cp;
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                break;
     case 'd':  if(j+8 > LenBuf){
                 j=OutFrame(j,DebugBufO);
                }
                cp=va_arg(arg, BYTE *);
                c=*(cp+3);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                c=*(cp+2);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                c=*(cp+1);
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                c=*cp;
                DebugBufO[j++]=HEX[(c>>4) & 0x0f];
                DebugBufO[j++]=HEX[c & 0x0f];
                break;
     default :  j=1;
                for(i=0; Str[i]; i++)
                 DebugBufO[j++]=Str[i];
                DebugBufO[j++]='\"';
                for(i=0,a=1; Format[i]; i++){
                 if(Format[i]==0xa){
                  DebugBufO[j++]='\\';
                  DebugBufO[j++]='n';
                  a=0;
                 }
                 if(Format[i]==0xd){
                  DebugBufO[j++]='\\';
                  DebugBufO[j++]='r';
                  a=0;
                 }
                 if(a)
                  DebugBufO[j++]=Format[i];
                 else
                  a=1;
                }
                DebugBufO[j++]='\"';
                DebugBufO[0]=j;
                //FPUT(0x81,DebugBufO);
                return;
    }
  }
  OutFrame(j,DebugBufO);
  va_end(arg);
}
int OutFrame(int j, BYTE *DebugBufOf)
{
   m_pDebMsg->m_swLen        = j+9+1;
   m_pDebMsg->m_sbyFrom      = MDL_DEBMS;  
   m_pDebMsg->m_sbyFor       = MDL_DEBMS;  
   m_pDebMsg->m_sbyIntType   = 0;  
   m_pDebMsg->m_sbyServerID  = 0;  
   m_pDebMsg->m_sbyType      = EV_DEBMS_DEBOUT_IND;
   m_pDebMsg->m_sbyDirection = 0;
   m_pDebMsg->m_sbySensor    = 0;
   DebugBufO[0]   = 0x7e;
   DebugBufO[j]   = 0;
   #ifdef WIN32
   printf("%s",DebugBufO);
   #else
   DebugBufO[j] = 0x7e;
   FPUT(DEV_RSBUF_BOX_ID,(BYTE*)m_pDebMsg);  
   #endif
   return 1;
}







