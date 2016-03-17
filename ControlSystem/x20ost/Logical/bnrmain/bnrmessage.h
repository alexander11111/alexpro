/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include "typedefs.h"
typedef void (*CCPFN)(void);
//Message For My System
#ifdef WIN32
typedef struct _tagCANnode_typ
{
	BOOL enable;
	UINT node_nr;
	UINT status;
}CANnode_typ;

typedef struct _tagCANopen_typ
{
	BOOL enable;
	UINT baud_rate; 
	UINT cob_anz;
	UINT device;
}CANopen_typ;

typedef struct _tagFRM_xopen_typ
{
	BOOL   enable;
	UDINT	device;
	UDINT	mode;
	UDINT	config;
	UINT	status;
	UDINT	*ident;
	BYTE	internal[27];
}FRM_xopen_typ;
typedef struct _tagFRM_close_typ
{
	BOOL   enable;
	UDINT  *ident;
	UINT   status;
	BYTE   internal[27];
}FRM_close_typ;
typedef struct _tagXOPENCONFIG
{
	UINT   idle;
	UINT   delimc;
	USINT  delim[2];
	UINT   tx_cnt;
	UINT   rx_cnt;
	UINT   tx_len;
	UINT   rx_len;
	UINT   argc;
	UDINT  *argv;
}XOPENCONFIG;
typedef struct _tagFRM_gbuf_typ
{
	BOOL   enable;
	UDINT  *ident;
	UINT   status;
	UDINT  *buffer;
	UINT	buflng;
	BYTE	internal[27];
}FRM_gbuf_typ;
//Client
typedef struct _tagFRM_rbuf_typ
{
	BOOL   enable;
	UDINT	*ident;
	UDINT	*buffer;
	UINT	buflng;
	UINT	status;
	BYTE	internal[27];
}FRM_rbuf_typ;
typedef struct _tagFRM_robuf_typ
{ 
	BOOL   enable;
	UDINT	*ident;
	UDINT	*buffer;
	UINT	buflng;
	UINT	status;
	BYTE	internal[27];
}FRM_robuf_typ;
typedef struct _tagFRM_write_typ
{ 
	BOOL   enable;
	UDINT  *ident;
	UDINT  *buffer;
	UINT   buflng;
	UINT   status;
	BYTE   internal[27];
	
}FRM_write_typ;
typedef struct _tagFRM_read_typ
{ 
	BOOL   enable;
	UDINT  *ident;
	UINT   status;
	UDINT  *buffer;
	UINT   buflng;
	BYTE   internal[27];
}FRM_read_typ;
typedef struct _tagSysInfo
{
    BYTE byInfo; 
}SYSxinfo_typ;
typedef struct _tagRTCtime_typ
{
    WORD year; 
    BYTE month; 
    BYTE day; 
    BYTE hour; 
    BYTE minute; 
    BYTE second; 
    WORD millisec; 
}RTCtime_typ;
int SYSxinfo(SYSxinfo_typ*);
#endif
typedef struct _tagGetParam
{ 
    WORD wParam0; 
	WORD wParam1; 
	WORD wParam2; 
	WORD wParam3; 
}SGETPARAM;
typedef struct _msgPLCCommand
{
    WORD m_swLen; 
	BYTE m_sbyFor;  
	BYTE m_sbyType;
    BYTE m_sbyDevID;
	BYTE m_sbyInfo[70];
}SPLCCOMM;
typedef struct _msgSystem0
{
    WORD m_swLen; 
    BYTE m_sbyFrom;  
	BYTE m_sbyFor;  
	BYTE m_sbyIntType;  
	BYTE m_sbyServerID;  
	BYTE m_sbyType;
    BYTE m_sbyDirection;
    BYTE m_sbySensor;
	BYTE m_sbyInfo[350];
}SMESSAGE;
typedef struct _msgSystem00
{
    WORD m_swLen; 
    BYTE m_sbyFrom;  
	BYTE m_sbyFor;  
	BYTE m_sbyIntType;  
	BYTE m_sbyServerID;  
	BYTE m_sbyType;
    BYTE m_sbyDirection;
    BYTE m_sbySensor;
	BYTE m_sbyInfo[2000];
}SLMESSAGE;
typedef struct _msgShSystem0
{
    WORD m_swLen; 
    BYTE m_sbyFrom;  
	BYTE m_sbyFor;  
	BYTE m_sbyIntType;  
	BYTE m_sbyServerID;  
	BYTE m_sbyType;
    BYTE m_sbyDirection;
    BYTE m_sbySensor;
	BYTE m_sbyInfo[200];
}SHMESSAGE;
typedef struct _msgShSystem1
{
    WORD m_swLen; 
    BYTE m_sbyFrom;  
	BYTE m_sbyFor;  
	BYTE m_sbyIntType;  
	BYTE m_sbyServerID;  
	BYTE m_sbyType;
    BYTE m_sbyDirection;
    BYTE m_sbySensor;
	BYTE m_sbyInfo[30];
}SHORTMESSAGE;
typedef struct _tagJob
{
	CCPFN pfnProcAddres;
	BYTE  byPeriod;
	BYTE  byStateProc;
	SINT  chProcName[50];
}SJOBINFO;

typedef struct _tagTcpAddres
{
    BYTE byAddr0;
	BYTE byAddr1;
	BYTE byAddr2;
	BYTE byAddr3;
}STCPADDR;
typedef struct _tagArmInterface
{
	BYTE byNumber;
    BYTE byType;
	BYTE byPortRate;
	BYTE byAmTCPPort;
	DWORD dwpPortNumber[DEV_MAX_TCP_PORT];
	STCPADDR stTcpAddr; 
	SINT chTcpAddr[30]; 
}SARMINTERFACE;
typedef struct _tagHardPinConfig
{
	BYTE byPinNumber;
	BYTE byPinType;
	BYTE byPinState;
	PVOID pvValue;
}SHARDPIN;
typedef struct _tagHardSlotConfig
{
	BYTE bySlotNumber;
	BYTE bySlotType;
	BYTE byPinAmout;
	BYTE byState;
	BYTE byAlmState;
	PVOID pvAlmState;
	PVOID *pvAlmPin;
	PVOID *pvPin;
}SHARDSLOT;
typedef struct _tagKpParam
{
    BYTE byKpID;
	BYTE byStoreMode;
	BYTE byAmCall;
	BYTE byCallPeriod;
	//BYTE bySetChann;
	SINT byPassword[20];
	SINT byPhone0[20];
	SINT byPhone1[20];
	SINT byPhone2[20];
}SKPPARAM;
typedef struct _tagHardComputer
{
    BYTE byComputerType;
	BYTE bySystemID;
    SINT chComputerName[DEV_MAX_TEXT_NAME];
	SINT chProgrammVersion[DEV_MAX_TEXT_NAME];
    SINT chDateOfWrite[DEV_MAX_TEXT_NAME];
	BYTE bySlotAmout;
	BYTE byArmAmout;
	SKPPARAM *pKpParam;
	SARMINTERFACE *pArmInterface[DEV_MAX_ARM_PORT];
	SHARDSLOT sSlot[DEV_MAX_SLOTS_PS260];
}SHARDCOMPUTERTABLE;
typedef struct _tagSensorInitTable
{
    INT  iLoLimitValue;
	INT  iHiLimitValue;
}SENSORINITTABLE;
/*
pT->m_sSNSParam.dY_max    = 20.0;
pT->m_sSNSParam.Kp        = 0.4;
pT->m_sSNSParam.Tn        = 6000.0;
pT->m_sSNSParam.Tv        = 0.0;
pT->m_sSNSParam.Tf        = 1.0;
pT->m_sSNSParam.Kw        = 1.0;           
pT->m_sSNSParam.Kfbk      = 1.0;		
pT->m_sLCPid.A            = 0;//500;
pT->m_sLCPid.Y_man	      = 0;
*/
typedef struct _tagSensorParamTable
{
    REAL m_swResistance;
    REAL m_swHiLimit;
    REAL m_swLoLimit;
    REAL m_swHiAlLimit;
    REAL m_swLoAlLimit;
    REAL m_swHiOper;
    REAL m_swLoOper;
    REAL m_swInitValue;
	REAL m_rlDy;
	REAL m_rlKp;
	REAL m_rlTn;
	REAL m_rlKw;
	REAL m_rlKfbk;
	REAL m_rlTv;
	REAL m_rlTf;
	INT16 m_rlA;
	INT16 m_rlYman;
	BYTE m_byFilterOn;
	BYTE m_swPidDiffMode;
	WORD m_swMaxAcpInp;
	WORD m_swMaxAcpOut;
	BYTE m_byID;
    BYTE bySrcSlotNumber;  
	BYTE bySrcPinNumber;
    BYTE m_snType;
    BYTE m_sbyParamType;
    BYTE m_sbyInpState;
    BYTE m_sbyOutState;
    BYTE m_sbyMode; 
	BYTE m_sbyPmode;
	BYTE m_sbyOmode;
	REAL m_srOmin;
	REAL m_srOmax;
	WORD m_swOpenTime;
	SINT m_chSNname[10];
}SNSPARAMTABLE;

typedef struct _tagOutGate
{ 
	WORD wLoLimit;
	WORD wHiLimit;
	WORD wCurrOpen;
	WORD wOpenTime;
	REAL rMinRamp;
	REAL rMaxRamp;
	BYTE byOType;
	BYTE byMode;
	BYTE byID;
	BYTE byType;
    BYTE byOutSlotNumber;      
	BYTE byOutPinNumber;
	SINT chName[10];
}SOUTGATE;
typedef struct _tagSensorInputGates
{
  BYTE byAmInGate;
  SNSPARAMTABLE mIn[12];
}SINPUTGATE;
typedef struct _tagSensorOutputGates
{
	BYTE byAmOutGate;
	SOUTGATE mOut[12];
}SOUTPUTGATE;
typedef struct _tagPinGate
{ 
	BYTE sbySlot;
	BYTE sbyPin;
}SPINGATE;
typedef struct _tagDigitalGate
{ 
    WORD swAmpin;
	SPINGATE sPinGate[32];
}SDIGGATE;
typedef struct _tagDigitalGates
{
    BYTE byAmGate;
	SDIGGATE sIoGate[10];
}SDIGGATES;
typedef struct _tagSwitchingTable
{
    #if MYSYSTEM_ID != 5
	 BYTE bySensorID;
	 PVOID sSensorParamTable;
	 TStateList *m_pStateList;
	 BYTE bySwitchCommand;
	 BOOL blEnable;
	 BYTE byAmOutGate;
	 PVOID sOutGate[DEV_AMT_GATE_SNS];
	#else
	 BYTE bySensorID;
     BYTE bySlot; 
	 BYTE byPin; 
	 BYTE byType;
    #endif
}SSWITCHTABLE;
typedef struct _tagDirectionTable
{
    BYTE byDirectionID;
	BYTE byDirectionCode;
	BYTE byAmSwitching;
	BYTE byAmTI;
	BYTE byAmTS;
	BYTE byAmTU;
	BYTE byAmTR;

	PVOID pvIn;
	PVOID pvOut;
	PVOID pSwitchTable[DEV_AMT_SWC_IDIR]; 
}SDIRTABLE;
typedef struct _tagSoftSwitchingConfig
{
	BYTE byTableVersion;
	SINT chTableVersionName[DEV_MAX_TEXT_NAME];
	BYTE byAmDirection;
	SDIRTABLE sDirectionTable[DEV_AMT_DIR_INST];
}SSOFTSWITCHTABLE;
//Kp Tag
typedef struct _tagTime
{
    BYTE tDay;  
	BYTE tMonth;  
	BYTE tYear;  
	BYTE tHour;  
	BYTE tMin;  
	BYTE tSec;  
	BYTE tMSecL;
	BYTE tMSecH;
}STIME;
typedef struct _tagKpEvent
{
	WORD wLen;
	BYTE byType;
    BYTE byAddr;
	BYTE byCause;
    WORD wValue;
    STIME sTime;
}SKPEVENT;
typedef struct _tagQueryReqAddr
{
	WORD wSize; 
	BYTE byA0;
	BYTE byA1;
	BYTE byA2;
}SREGADDR;
typedef struct _tagReqParam
{
	WORD wSize; 
	WORD wParam;
	BYTE byA0;
	BYTE byA1;
	BYTE byA2;
}SREGPARAM;
//Датчик температуры
typedef struct _tagTTMData
{
	WORD wJob;
	WORD wParam;
}STTMDATA;
/*
typedef struct _tagTTMDatas
{
	BYTE Count; 
	BYTE byType;
	STTMDATA sDT[2];
}STTMDATAS;
*/
typedef struct _tagTTMParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	STTMDATA sDT;
}STTMPARAM;
typedef struct _tagTTMParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STTMPARAM sTTM[4];
}STTMPARAMS;
//Датчик давления
typedef struct _tagTPRData
{
	WORD wJob;
	WORD wParam;
}SPRMDATA;
/*
typedef struct _tagTPRDatas
{
	BYTE Count; 
	BYTE byType;
	SPRMDATA sDT[2];
}SPRMDATAS;
*/
typedef struct _tagTPRParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	SPRMDATA sDT;
}STPRPARAM;
typedef struct _tagTPRParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STPRPARAM sTPR[4];
}STPRPARAMS;
//Счетчики
typedef struct _tagTCData
{
	REAL fKoeff;
	DWORD dwParam;
}STCDATA;
/*
typedef struct _tagTCDatas
{
	BYTE Count; 
	BYTE byType;
	STCDATA sDT[16];
}STCDATAS;
*/
typedef struct _tagTCParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	DWORD dwMaxFreq;
	STCDATA sDT;
}STCPARAM; 
typedef struct _tagTCParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STCPARAM sTC[18];
}STCPARAMS;
//Управляемые краны
typedef struct _tagTKData
{
	BYTE byStOP;
	BYTE byStCL;
	BYTE byStMD;
    WORD wMaxOpenTime;
    REAL fJobOpen;
    REAL fOpenState;
}STKDATA;
/*
typedef struct _tagTKDatas
{
	BYTE Count; 
	BYTE byType;
	STKDATA sDT[4];
}STKDATAS;
*/
typedef struct _tagTKParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE bySlot1; 
	BYTE byPin1; 
    STKDATA sDT;
}STKPARAM; 
typedef struct _tagTKParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STKPARAM sTK[5];
}STKPARAMS;
//Измеритель уровня
typedef struct _tagLVData
{
	WORD wSt0; 
	WORD wJob0;
	WORD wJob1;
	WORD wParam;
}SLVDATA;
/*
typedef struct _tagPUDatas
{
	BYTE Count; 
	BYTE byType;
	SPUDATA sDT[2];
}SPUDATAS;
*/
typedef struct _tagLVParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE bySlot1; 
	BYTE byPin1; 
    SLVDATA sDT;
}SLVPARAM; 
typedef struct _tagLVParams
{
	BYTE byAmSlot; 
	BYTE byType;
	SLVPARAM sLV[2];
}SLVPARAMS;
//Переключатель режима
typedef struct _tagPLData
{
	BYTE byParam;
}SPLDATA;
typedef struct _tagPLParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
    SPLDATA sDT;
}SPLPARAM; 
typedef struct _tagPLParams
{
	BYTE byAmSlot; 
	BYTE byType;
	SPLPARAM sPL[2];
}SPLPARAMS;
//Таймер операции
typedef struct _tagTMData
{
	WORD wJob;
	WORD wParam;
}STMDATA;
typedef struct _tagTMParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
    STMDATA sDT;
}STMPARAM; 
typedef struct _tagTMParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STMPARAM sTM[2];
}STMPARAMS;
//Перекидное устройство
typedef struct _tagPUData
{
	WORD wSt0;
	WORD dwTimeConst;
	WORD dwOpenTime;
}SPUDATA;
/*
typedef struct _tagPUDatas
{
	BYTE Count; 
	BYTE byType;
	SPUDATA sDT[2];
}SPUDATAS;
*/
typedef struct _tagPUParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE bySlot1; 
	BYTE byPin1; 
	BYTE bySlot2; 
	BYTE byPin2;
	BYTE bySlot3; 
	BYTE byPin3;
    SPUDATA sDT;
}SPUPARAM; 
typedef struct _tagPUParams
{
	BYTE byAmSlot; 
	BYTE byType;
	SPUPARAM sTPU[2];
}SPUPARAMS;
//Частотный привод
typedef struct _tagTFData
{
	//BYTE byStartST;
	//BYTE byStopST;
	//BYTE byAlST0;
	//BYTE byAlST1;
    WORD wSt0;
	WORD wTask;
	WORD wParam;
}STFDATA;
/*
typedef struct _tagTFDatas
{
	BYTE Count; 
	BYTE byType;
	STFDATA sDT[3];
}STFDATAS;
*/
typedef struct _tagTFParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; //Для задания
	BYTE byPin;  //Для задания

	BYTE bySlot1; //Запуск
	BYTE byPin1;  //Запуск

	BYTE bySlot2; //Останов
	BYTE byPin2;  //Останов

	BYTE bySlot3; //Авария1
	BYTE byPin3;  //Авария1

	BYTE bySlot4; //Авария2
	BYTE byPin4;  //Авария2
    STFDATA sDT;
}STFPARAM;
typedef struct _tagTFParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STFPARAM sTF[4];
}STFPARAMS;
//Телеиндикация
typedef struct _tagTIParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	BYTE byPriority;
	BYTE byDrTimer;
	WORD wHiLimit;
	WORD wHiGister;
	WORD wLoGister;
	WORD wLoLimit;
	WORD wLo;
	WORD wHi;
	WORD wEvPercent;
	WORD wParam;
}STIPARAM;
typedef struct _tagTIParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STIPARAM sTI[32];
}STIPARAMS;

//Весы
typedef struct _tagTVSData 
{
	BYTE byData[11];
}STVSDATA;
typedef struct _tagTVSParam 
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	STVSDATA sDT;
}STVSPARAM;
typedef struct _tagTVSarams
{
	BYTE byAmSlot; 
	BYTE byType;
	STIPARAM sTVS[2];
}STVSPARAMS;
//Телесигнализация(дискретное)
typedef struct _tagTSParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin;
	BYTE byAlmState;
	BYTE byState;
	BYTE byPriority;
	BYTE byCRemPulce;
    BYTE byCSetPulce;
	BYTE byAlarmMode;
    BYTE byParam;
}STSPARAM; 
typedef struct _tagTSParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STSPARAM sTS[20];
}STSPARAMS;

//Телесигнализация1(дискретное)
typedef struct _tagTSMData
{
	BYTE byParam;
}STSMDATA;
/*
typedef struct _tagTSMDatas
{
	BYTE Count; 
	BYTE byType;
	STSMDATA sDT[19];
}STSMDATAS;
*/
typedef struct _tagTSMParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin;
	BYTE byAlmState;
	BYTE byState;
	BYTE byPriority;
	BYTE byCRemPulce;
    BYTE byCSetPulce;
	BYTE byAlarmMode;
    STSMDATA sDT;
}STSMPARAM; 
typedef struct _tagTSMParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STSPARAM sTS[20];
}STSMPARAMS;


//Аварии
typedef struct _tagTALData
{
	WORD wParam;
}STALDATA;
typedef struct _tagTALaram
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin;
	BYTE byAlmState;
	BYTE byState;
    STALDATA sDT;
}STALPARAM; 
typedef struct _tagTALParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STALPARAM sTA[2];
}STALPARAMS;

//Телеуправление(дискретное)
typedef struct _tagTUParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	BYTE byPulceType;
    BYTE byCSetPulce;
	BYTE byParam;
}STUPARAM; 
typedef struct _tagTUParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STUPARAM sTU[64];
}STUPARAMS;

//Телеуправление1(дискретное)
typedef struct _tagTUMData
{
	BYTE byParam;
}STUMDATA;
typedef struct _tagTUMParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	BYTE byPulceType;
    DWORD byCSetPulce;
	STUMDATA sDT;
}STUMPARAM; 
typedef struct _tagTUMParams
{
	BYTE byAmSlot; 
	BYTE byType;
	STUMPARAM sTU[16];
}STUMPARAMS;

//Модуль слежения
typedef struct _tagODSData
{
	//BYTE byAutoStart;
	//BYTE byPreStart;
	//BYTE byStart;
	//BYTE byStop;
	//BYTE byFinish;
    //BYTE byMode;
    DWORD wSt0;
	WORD wJTMPreStart;
	WORD wTMPreStart;
	WORD wJTMStart;
	WORD wTMStart;
	WORD wJTMWait;
	WORD wTMWait;
}SOBSMDATA;
typedef struct _tagOBSParam
{
	BYTE byID;
	BYTE byAmParam; 
	BYTE byType;
	BYTE bySlot; 
	BYTE byPin; 
	BYTE byAlmState;
	BYTE byState;
	SOBSMDATA sDT;
}SOBSPARAM; 
typedef struct _tagOBSParams
{
	BYTE byAmSlot; 
	BYTE byType;
	SOBSPARAM sOS[1];
}SOBSPARAMS;


/*
&nTPR,
&nTTM,
&nTC,
&nTF,
&nTKP,
&nTPU,
&nTS,
&nTU,
*/
typedef struct _tagObserveTable 
{
    SPRMDATA nTPR[2];  	 
    STTMDATA nTTM[2];  	 
	STCDATA  nTC[16];
	STFDATA  nTF[3];
	STKDATA  nTKP[4];
	SPUDATA  nPU[2];
	STSMDATA nTS[15];
	STUMDATA nTU[10];
	STVSDATA nTVS[2];
	SLVDATA  nLV[1];
	SPLDATA  nPL[1];
	STMDATA  nTM[1];
	STALDATA nTAL[2];
}STOUTTBL;
typedef struct _tagCDataCommand
{
     WORD wDeviceID;
     BYTE byParam0;
     BYTE byParam1;
     BYTE byParam2;
     WORD wParam0;
     WORD wParam1;
     WORD wParam2;
     REAL fParam0;
     REAL fParam1;
     REAL fParam2;
}CDataCommand;
typedef struct _tagContenstTable
{
	BYTE byKpID;
	BYTE byDefSett;
	//#if (MYSYSTEM_ID == 0)||(MYSYSTEM_ID == 1)||(MYSYSTEM_ID == 2)||(MYSYSTEM_ID == 3) 
	//REAL mInResistance[16];
    //SINPUTGATE  sInGate;
    ///SOUTPUTGATE sOutGate;
	//WORD m_wLayerMode;
    //#elif MYSYSTEM_ID == 4 
	//DWORD m_dwOutState[32];
    //#elif MYSYSTEM_ID == 5
	SKPPARAM  sKP;
	SARMINTERFACE sARM;
	STIPARAMS sTI;
	STSPARAMS sTS;
	STUPARAMS sTU;
    //#endif
}SCONTENSTTABLE;
#endif
