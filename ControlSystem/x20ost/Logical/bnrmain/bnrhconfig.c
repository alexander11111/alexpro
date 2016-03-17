#include "bnrhconfig.h"
#if MYSYSTEM_ID == 5 
//Признак аварийности
AI_ASVL(0)
AI_ASVL(1)
AI_ASVL(2)
AI_ASVL(3)

AI_ASVL(4)
AI_ASVL(5)

AO_ASVL(6)

DI_ASVL(7)
DI_ASVL(8)

/*
DI_ASVL(9)
DI_ASVL(10)
DI_ASVL(11)
DI_ASVL(12)
DI_ASVL(13)
DI_ASVL(14)
DI_ASVL(15)
DI_ASVL(16)
DI_ASVL(17)
*/
DO_ASVL(9)
DO_ASVL(10)

//Подключение переменных по авариям
AIP2_ALVL(4) /**/ AI2_ALSL(4) 
AIP2_ALVL(5) /**/ AI2_ALSL(5) 

AOP4_ALVL(6)  /**/ AO4_ALSL(6) 

DIP12_ALVL(7) /**/ DI12_ALSL(7)
DIP12_ALVL(8) /**/ DI12_ALSL(8)

//DIP2_ALVL(9)  /**/ DI2_ALSL(9)
//DIP2_ALVL(10) /**/ DI2_ALSL(10)
//DIP2_ALVL(11) /**/ DI2_ALSL(11)
//DIP2_ALVL(12) /**/ DI2_ALSL(12)
//DIP2_ALVL(13) /**/ DI2_ALSL(13)
//DIP2_ALVL(14) /**/ DI2_ALSL(14)
//DIP2_ALVL(15) /**/ DI2_ALSL(15)
//DIP2_ALVL(16) /**/ DI2_ALSL(16)
//DIP2_ALVL(17) /**/ DI2_ALSL(17)

DOP12_ALVL(9) /**/ DO12_ALSL(9)
DOP12_ALVL(10) /**/ DO12_ALSL(10)

//Инициализация информационных переменных 
//AI
AIP2_AVL(4)  /**/ AI2_SL(4)
AIP2_AVL(5)  /**/ AI2_SL(5)
AOP4_AVL(6)  /**/ AO4_SL(6)
//DI
DIP12_AVL(7) /**/ DI12_SL(7)
DIP12_AVL(8) /**/ DI12_SL(8)

//DIP2_AVL(9)  /**/ DIC2_SL(9)
//DIP2_AVL(10) /**/ DIC2_SL(10)
//DIP2_AVL(11) /**/ DIC2_SL(11)
//DIP2_AVL(12) /**/ DIC2_SL(12)
//DIP2_AVL(13) /**/ DIC2_SL(13)
//DIP2_AVL(14) /**/ DIC2_SL(14)
//DIP2_AVL(15) /**/ DIC2_SL(15)
//DIP2_AVL(16) /**/ DIC2_SL(16)
//DIP2_AVL(17) /**/ DIC2_SL(17)
//DO
DOP12_AVL(9)  /**/ DO12_SL(9)
DOP12_AVL(10) /**/ DO12_SL(10)
#endif
#if MYSYSTEM_ID == 5
SKPPARAM nKP = {0,0,1,20,"Password","+375291415925","+000000000000","+000000000000"};
/*
typedef struct _tagArmInterface
{
BYTE byNumber;
BYTE byType;
BYTE byPortRate;
BYTE byAmTCPPort;
DWORD dwpPortNumber[DEV_MAX_TCP_PORT];
STCPADDR stTcpAddr; 
}SARMINTERFACE;
*/
SARMINTERFACE nARM0   = {0,DEV_ARM_PORT_COM232,DEV_ARM_RATE_57600,0,{0    ,    0},{  EVEN,   D_8,  S_1,  0}};
SARMINTERFACE nARM1   = {1,DEV_ARM_PORT_COM232,DEV_ARM_RATE_9600,0 ,{0    ,    0},{  NOPAR,  D_8,  S_1,  0}};
SARMINTERFACE nARM2   = {2,DEV_ARM_PORT_COM232,DEV_ARM_RATE_9600,0 ,{0    ,    0},{  NOPAR,  D_8,  S_1,  0}};

SARMINTERFACE nARMTCP = {3,DEV_ARM_PORT_TCP,DEV_ARM_RATE_57600,0,{20001   ,20001},{  192,  168,  1,  4},"192.168.1.4"};
SARMINTERFACE nARMUDP = {4,DEV_ARM_PORT_UDP,DEV_ARM_RATE_100MB,0,{20003   ,20002},{  192,  168,  1,  5},"192.168.1.5"};

SHARDCOMPUTERTABLE nConfigTable = 
{
	DEV_CPU_TYPE_X20,MYSYSTEM_ID,"Motorola m68 PS794","Version: Wather St","Date:15.02.2013",11,5,
		&nKP,
	{
		{&nARM0},{&nARM1},{&nARM2},{&nARMTCP},{&nARMUDP},
	},
	{
		{0  ,DEV_PLC_CPU_X20  ,                       0,1,0,&blAsValueAI0, NULL         ,         NULL},
		{1  ,DEV_PWCOM_PS9500,                        0,1,0,&blAsValueAI1, NULL         ,         NULL},       //IF4.ST0
		{2  ,DEV_COM_CS1020,                          0,1,0,&blAsValueAI2, NULL         ,         NULL},       //IF4.ST1
		{3  ,DEV_COM_CS1020,                          0,1,0,&blAsValueAI3, NULL         ,         NULL},       //IF4.ST2

		{4  ,DEV_AI_X20AI2622 ,DEV_MAX_AI_X20AI2622_PIN,1,0,&blAsValueAI4, blpAlValueAI4,  uipValueAI4},       //IF4.ST3
		{5  ,DEV_AT_X20AT2222 ,DEV_MAX_AT_X20AT2222_PIN,1,0,&blAsValueAI5, blpAlValueAI5,  uipValueAI5},       //IF4.ST4

		{6  ,DEV_AO_X20AO4622 ,DEV_MAX_AI_X20AI4622_PIN,1,0,&blAsValueAO6, blpAlValueAO6,  uipValueAO6},       //IF4.ST5 

		{7  ,DEV_DI_X20DI9371 ,DEV_MAX_DI_X20DI9371_PIN,1,0,&blAsValueDI7,blpAlValueDI7 , blpValueDI7},        //IF4.ST6 
		{8  ,DEV_DI_X20DI9371 ,DEV_MAX_DI_X20DI9371_PIN,1,0,&blAsValueDI8,blpAlValueDI8 , blpValueDI8},        //IF4.ST7 
         
		//{9  ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI9,blpAlValueDI9 , uipValueDI9},
		//{10 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI10,blpAlValueDI10, uipValueDI10},
		//{11 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI11,blpAlValueDI11, uipValueDI11},
		//{12 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI12,blpAlValueDI12, uipValueDI12},
		//{13 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI13,blpAlValueDI13, uipValueDI13},
		//{14 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI14,blpAlValueDI14, uipValueDI14},
		//{15 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI15,blpAlValueDI15, uipValueDI15},
		//{16 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI16,blpAlValueDI16, uipValueDI16},
		//{17 ,DEV_DI_X20DI2377 ,DEV_MAX_DI_X20DI2377_PIN,1,0,&blAsValueDI17,blpAlValueDI17, uipValueDI17},
         
		{9  ,DEV_DO_X20DO9321 ,DEV_MAX_DO_X20DO9321_PIN,1,0,&blAsValueDO9 ,blpAlValueDO9 ,blpValueDO9},        //IF4.ST8  
		{10 ,DEV_DO_X20DO9321 ,DEV_MAX_DO_X20DO9321_PIN,1,0,&blAsValueDO10,blpAlValueDO10,blpValueDO10},       //IF4.ST9   
		}
};
#endif

void InitHardValue(void)
{
	BYTE i;
	//BOOL blV;
	#if MYSYSTEM_ID == 5
	blAsValueAI0  = TRUE; 
    blAsValueAI1  = TRUE;
   	blAsValueAI2  = TRUE; 
    blAsValueAI3  = TRUE;
    blAsValueAI4  = TRUE;
    blAsValueAI5  = TRUE;
    blAsValueAO6  = TRUE;

    blAsValueDI7  = TRUE;
    blAsValueDI8  = TRUE;

    //blAsValueDI9  = TRUE;
	//blAsValueDI10 = TRUE;
    //blAsValueDI11 = TRUE;
    //blAsValueDI12 = TRUE;
    //blAsValueDI13 = TRUE;
    //blAsValueDI14 = TRUE;
    //blAsValueDI16 = TRUE;
    //blAsValueDI17 = TRUE;

	blAsValueDO9 = TRUE;
    blAsValueDO10 = TRUE;

	AI2_ALCSL(4)   AI_ALIN2(4,FALSE)
	AI2_ALCSL(5)   AI_ALIN2(5,FALSE)
	AO4_ALCSL(6)   AO_ALOT4(6,FALSE)	

    DI12_ALCSL(7) DI_ALIN12(7,FALSE)
	DI12_ALCSL(8) DI_ALIN12(8,FALSE)

	
	//DI2_ALCSL(9)  DI_ALIN2(9,FALSE)
	//DI2_ALCSL(10) DI_ALIN2(10,FALSE)
	//DI2_ALCSL(11) DI_ALIN2(11,FALSE)
	//DI2_ALCSL(12) DI_ALIN2(12,FALSE)
	//DI2_ALCSL(13) DI_ALIN2(13,FALSE)
	//DI2_ALCSL(14) DI_ALIN2(14,FALSE)
	//DI2_ALCSL(15) DI_ALIN2(15,FALSE)
	//DI2_ALCSL(16) DI_ALIN2(16,FALSE)
	//DI2_ALCSL(17) DI_ALIN2(17,FALSE)
     
	DO12_ALCSL(9)  DO_ALIN12(9,FALSE)
	DO12_ALCSL(10) DO_ALIN12(10,FALSE)

	//*blpAlValueAI2[0] = 1;
	//*blpAlValueAI2[byParam0] = byParam1;

	//blValueDO17_1 = 0;
	AI2_CSL(4)  /*Init*/ 
	AI2_CSL(5)  /*Init*/ 
	AO4_CSL(6)  /*Init*/ 

    DI12_CSL(7) /*Init*/DI_INI12(7,FALSE) 
	DI12_CSL(8) /*Init*/DI_INI12(8,FALSE)  
    
	//DIC2_CSL(9)  /*Init*/DIC_INI2(9,FALSE)  
	//DIC2_CSL(10) /*Init*/DIC_INI2(10,FALSE)  
	//DIC2_CSL(11) /*Init*/DIC_INI2(11,FALSE)  
	//DIC2_CSL(12) /*Init*/DIC_INI2(12,FALSE)  
	//DIC2_CSL(13) /*Init*/DIC_INI2(13,FALSE)  
	//DIC2_CSL(14) /*Init*/DIC_INI2(14,FALSE)  
	//DIC2_CSL(15) /*Init*/DIC_INI2(15,FALSE)  
	//DIC2_CSL(16) /*Init*/DIC_INI2(16,FALSE)  
	//DIC2_CSL(17) /*Init*/DIC_INI2(17,FALSE)  

	DO12_CSL(9) /*Init*/ 
	DO12_CSL(10) /*Init*/ 
    #endif	
}