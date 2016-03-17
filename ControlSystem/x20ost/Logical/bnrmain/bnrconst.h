/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrconst.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/
#ifndef WIN32
#include <AsDefault.h>
#endif
#ifndef __CONST_H__
#define __CONST_H__
//#define IF_MODEM     0
#define MYSYSTEM_ID  5
#ifdef WIN32
//#define MY_MODEL     0  
#endif
//User Define
#ifndef NULL
 #define  NULL 0
#endif
#ifndef WIN32
#define TRUE 1
#define FALSE 0
#endif
//Define System QW
#define ACP_MIN                      6552
#define ACP_MAX                      32760
#define SYSTEM_QTIME                 50
//Event System

#define _DLESS_SHIFT                 0
#define _KPMOD_SHIFT                 0
#define _MSINP_SHIFT                 32
#define _ADMIN_SHIFT                 64
#define _SYSTM_SHIFT                 96
#define _OBSRV_SHIFT                 128
#define _ARMMD_SHIFT                 160
#define _DEBMS_SHIFT                 192
#define _DIRMD_SHIFT                 224
#define _SMSNS_SHIFT                 240

//Data Linc Message
#define EV_DLESS_ARM_RR_REQ	         _DLESS_SHIFT + 0 //Запрос подтверждения к устройству	00
#define EV_DLESS_ARM_RR_IND          _DLESS_SHIFT + 1 //Ответ от устройства на запрос подтверждения	01
#define EV_DLESS_BNR_RR_REQ	         _DLESS_SHIFT + 2 //Запрос подтверждения к АРМ	02
#define EV_DLESS_BNR_RR_IND	         _DLESS_SHIFT + 3 //Ответ от  АРМ на запрос подтверждения	03
#define EV_DLESS_TMRPUT_ARMIN        _DLESS_SHIFT + 4 //Таймер запросов подтверждений	04
#define EV_DLESS_TMRGET_ARMIN        _DLESS_SHIFT + 5 //Таймер на ответ на запрос подтверждения к устройству	05

#define EV_MCSET_IN00                _MSINP_SHIFT + 0
#define EV_MCSET_IN01                _MSINP_SHIFT + 1
#define EV_MCSET_IN02                _MSINP_SHIFT + 2
#define EV_MCSET_IN03                _MSINP_SHIFT + 3
#define EV_MCSET_IN04                _MSINP_SHIFT + 4
#define EV_MCSET_IN05                _MSINP_SHIFT + 5
#define EV_MCSET_IN06                _MSINP_SHIFT + 6
#define EV_MCSET_IN07                _MSINP_SHIFT + 7
#define EV_MCSET_IN08                _MSINP_SHIFT + 8
#define EV_MCSET_IN09                _MSINP_SHIFT + 9
#define EV_MCSET_IN10                _MSINP_SHIFT + 10
#define EV_MCSET_IN11                _MSINP_SHIFT + 11
#define EV_MCSET_IN12                _MSINP_SHIFT + 12
#define EV_MCSET_IN13                _MSINP_SHIFT + 13
#define EV_MCSET_IN14                _MSINP_SHIFT + 14
#define EV_MCSET_IN15                _MSINP_SHIFT + 15
#define EV_MCSET_IN16                _MSINP_SHIFT + 16
#define EV_MCSET_IN17                _MSINP_SHIFT + 17
#define EV_MCSET_IN18                _MSINP_SHIFT + 18
#define EV_MCSET_IN19                _MSINP_SHIFT + 19
#define EV_MCSET_IN20                _MSINP_SHIFT + 20
#define EV_MCSET_IN21                _MSINP_SHIFT + 21
#define EV_MCSET_IN22                _MSINP_SHIFT + 22
#define EV_MCSET_IN23                _MSINP_SHIFT + 23
#define EV_MCSET_IN24                _MSINP_SHIFT + 24
#define EV_MCSET_IN25                _MSINP_SHIFT + 25
#define EV_MCSET_IN26                _MSINP_SHIFT + 26
#define EV_MCSET_IN27                _MSINP_SHIFT + 27
#define EV_MCSET_IN28                _MSINP_SHIFT + 28
#define EV_MCSET_IN29                _MSINP_SHIFT + 29
#define EV_MCSET_IN30                _MSINP_SHIFT + 30
#define EV_MCSET_IN31                _MSINP_SHIFT + 31

//Admin Message
#define EV_ADMIN_ARM_CONFIG_REQ	     _ADMIN_SHIFT + 0 //Передать таблицу конфигурации для драйвера АРМ	64
#define EV_ADMIN_SYS_CONFIG_REQ	     _ADMIN_SHIFT + 1 //Передать таблицу конфигурации для драйвера системы	65
#define EV_ADMIN_SYS_CONFIG_IND	     _ADMIN_SHIFT + 2 //Запросить таблицу конфигурации для системы сенсоров
#define EV_ADMIN_SYS_READY_IND	     _ADMIN_SHIFT + 3 //Система готова к работе
#define EV_ADMIN_ARM_CONN_IND	     _ADMIN_SHIFT + 4 //АРМ подключен	66
#define EV_ADMIN_ARM_DISC_IND	     _ADMIN_SHIFT + 5 //АРМ отключен	67

#define EV_ADMIN_SET_ALM_HILEV_REQ   _ADMIN_SHIFT + 6 //Авария превышения верхнего ав. предела 	68
#define EV_ADMIN_REM_ALM_HILEV_REQ	 _ADMIN_SHIFT + 7 //Устранение аварии превышения верхнего ав. предела 	69

#define EV_ADMIN_SET_ALM_LOLEV_REQ	 _ADMIN_SHIFT + 8 //Авария превышения нижнего ав. предела 	70
#define EV_ADMIN_REM_ALM_LOLEV_REQ	 _ADMIN_SHIFT + 9 //Устранение аварии превышения нижнего ав. предела 	71
#define EV_ADMIN_ASK_CONF_TIM_IND	 _ADMIN_SHIFT + 10 //Таймер запроса конфигурации
#define EV_ADMIN_ARM_STOP_REQ	     _ADMIN_SHIFT + 11 
#define EV_ADMIN_TMR_SSTATE_IND	     _ADMIN_SHIFT + 12 
#define EV_ADMIN_ARM_READY_REQ	     _ADMIN_SHIFT + 13 

#define EV_ADMIN_OPER_LO_REQ	     _ADMIN_SHIFT + 14 
#define EV_ADMIN_OPER_HI_REQ	     _ADMIN_SHIFT + 15 



//System Message
#define EV_SYSTM_CLOSE_INPOTRS_REQ	 _SYSTM_SHIFT + 0 //Закрыть все входные порты 	96
#define EV_SYSTM_OPEN_INPOTRS_REQ	 _SYSTM_SHIFT + 1 //Открыть все входные порты	97
#define EV_SYSTM_CLOSE_OUTPOTRS_REQ	 _SYSTM_SHIFT + 2 //Закрыть все выходные порты	98
#define EV_SYSTM_OPEN_OUTPOTRS_REQ	 _SYSTM_SHIFT + 3 //Открыть все выходные порты	99
#define EV_SYSTM_STOP_JOB_REQ	     _SYSTM_SHIFT + 4 //Остановить задачу	100
#define EV_SYSTM_START_JOB_REQ	     _SYSTM_SHIFT + 5 //Запустить задачу	101
#define EV_SYSTM_FREQ_JOB_REQ	     _SYSTM_SHIFT + 6 //Установить частоту вызова задачи	102
#define EV_SYSTM_INIT_OBS_REQ	     _SYSTM_SHIFT + 7 //Проинициализировать модуль наблюдения
#define EV_SYSTM_INIT_OBS_IND	     _SYSTM_SHIFT + 8 //Ответ на команду инициализации
#define EV_SYSTM_RESET_BOARD_IND	 _SYSTM_SHIFT + 9 //Запрос на сброс
#define EV_SYSTM_RESET_TIM_BRD_IND	 _SYSTM_SHIFT + 10 //Сброс по таймеру

//Observe System Message
#define EV_OBSRV_GET_INOUT_SDATA_IND _OBSRV_SHIFT + 0 //Вернуть входное и выходное значение сенсоров	148
#define EV_OBSRV_GET_OUT_DATA_IND    _OBSRV_SHIFT + 1
#define EV_OBSRV_START_DATA_PROC_REQ _OBSRV_SHIFT + 2 //Инициировать процесс передачиданных с частотой X
#define EV_OBSRV_STOP_DATA_PROC_REQ  _OBSRV_SHIFT + 3 //Остановить процесс передачиданных с частотой X
#define EV_OBSRV_REFR_TIM_PROC_IND   _OBSRV_SHIFT + 4 //Таймер обновления данных
#define EV_OBSRV_SET_MODE_REQ	     _OBSRV_SHIFT + 5 //Установить режим
#define EV_OBSRV_GET_MODE_REQ    	 _OBSRV_SHIFT + 6 //Запросить режим
#define EV_OBSRV_GET_MODE_IND    	 _OBSRV_SHIFT + 7 //Вернуть режим
#define EV_OBSRV_GET_DMC_DATA_IND    _OBSRV_SHIFT + 8 //Вернуть состояние лог модуля
#define EV_OBSRV_RFLASH_SAVE_REQ     _OBSRV_SHIFT + 9 //Сохранение контекста
#define EV_OBSRV_REMFLS_SAVE_REQ     _OBSRV_SHIFT + 10 //Сохранение контекста в другом процессе

//Arm Module Message 
#define EV_MCREM_IN00                _ARMMD_SHIFT + 0
#define EV_MCREM_IN01                _ARMMD_SHIFT + 1
#define EV_MCREM_IN02                _ARMMD_SHIFT + 2
#define EV_MCREM_IN03                _ARMMD_SHIFT + 3
#define EV_MCREM_IN04                _ARMMD_SHIFT + 4
#define EV_MCREM_IN05                _ARMMD_SHIFT + 5
#define EV_MCREM_IN06                _ARMMD_SHIFT + 6
#define EV_MCREM_IN07                _ARMMD_SHIFT + 7
#define EV_MCREM_IN08                _ARMMD_SHIFT + 8
#define EV_MCREM_IN09                _ARMMD_SHIFT + 9
#define EV_MCREM_IN10                _ARMMD_SHIFT + 10
#define EV_MCREM_IN11                _ARMMD_SHIFT + 11
#define EV_MCREM_IN12                _ARMMD_SHIFT + 12
#define EV_MCREM_IN13                _ARMMD_SHIFT + 13
#define EV_MCREM_IN14                _ARMMD_SHIFT + 14
#define EV_MCREM_IN15                _ARMMD_SHIFT + 15
#define EV_MCREM_IN16                _ARMMD_SHIFT + 16
#define EV_MCREM_IN17                _ARMMD_SHIFT + 17
#define EV_MCREM_IN18                _ARMMD_SHIFT + 18
#define EV_MCREM_IN19                _ARMMD_SHIFT + 19
#define EV_MCREM_IN20                _ARMMD_SHIFT + 20
#define EV_MCREM_IN21                _ARMMD_SHIFT + 21
#define EV_MCREM_IN22                _ARMMD_SHIFT + 22
#define EV_MCREM_IN23                _ARMMD_SHIFT + 23
#define EV_MCREM_IN24                _ARMMD_SHIFT + 24
#define EV_MCREM_IN25                _ARMMD_SHIFT + 25
#define EV_MCREM_IN26                _ARMMD_SHIFT + 26
#define EV_MCREM_IN27                _ARMMD_SHIFT + 27
#define EV_MCREM_IN28                _ARMMD_SHIFT + 28
#define EV_MCREM_IN29                _ARMMD_SHIFT + 29
#define EV_MCREM_IN30                _ARMMD_SHIFT + 30
#define EV_MCREM_IN31                _ARMMD_SHIFT + 31

//Debug Message
#define EV_DEBMS_DEBOUT_IND          _DEBMS_SHIFT + 0

//Dir Module
#define EV_DIRMD_CONN_STAT_SNS_IND   _DIRMD_SHIFT + 0 //Установить соединение с сенсором
#define EV_DIRMD_DISC_STAT_SNS_IND   _DIRMD_SHIFT + 1 //Разорвать соединение с сенсором
#define EV_DIRMD_CONN_STAT_START_IND _DIRMD_SHIFT + 2 //Запустить проседуру сбора данных с периодом в секундах
#define EV_DIRMD_CONN_STAT_STOP_IND  _DIRMD_SHIFT + 3 //Остановить проседуру сбора данных
#define EV_DIRMD_REFR_TIM_PROC_IND   _DIRMD_SHIFT + 4 //Таймер сбора статистических данных 
#define EV_DIRMD_STAT_DATA_IND       _DIRMD_SHIFT + 5 //Массив статистических данных за период
#define EV_DIRMD_GET_PARAM_REQ       _DIRMD_SHIFT + 6 //Запросить араметры сенсора
#define EV_DIRMD_SET_TANK_REQ        _DIRMD_SHIFT + 7 

#define EV_SENSR_GET_SNPARAM_REQ     _SMSNS_SHIFT + 0  //Запросить у датчика параметры
#define EV_SENSR_GET_SNPARAM_IND     _SMSNS_SHIFT + 1  //Вернуть параметры датчика
#define EV_SENSR_SET_SNPARAM_REQ     _SMSNS_SHIFT + 2  //Установить параметры датчика
#define EV_SENSR_SET_PDPARAM_REQ     _SMSNS_SHIFT + 3  //Установить параметры ПИД
#define EV_SENSR_GET_PDPARAM_IND     _SMSNS_SHIFT + 4  //Вернуть параметры ПИД
#define EV_SENSR_SET_DIGT_OUT_REQ    _SMSNS_SHIFT + 5  //Подать значение на выход 
#define EV_SENSR_SET_DIGT_PULCE_REQ  _SMSNS_SHIFT + 6  //Подать импульс 

#define EV_SENSR_TMR_SAHI            _SMSNS_SHIFT + 5  
#define EV_SENSR_TMR_RAHI            _SMSNS_SHIFT + 6  
#define EV_SENSR_TMR_SALO            _SMSNS_SHIFT + 7  
#define EV_SENSR_TMR_RALO            _SMSNS_SHIFT + 8  


/////////////////////////////////////////////////////////////////////////////
//BEGIN:                      Level Module 101                             //
/////////////////////////////////////////////////////////////////////////////
#define PL_DATA_IND                  _KPMOD_SHIFT + 17  
#define PL_DATA_REQ                  _KPMOD_SHIFT + 18  
//Primitives For Data Linc Level
#define DL_DATA_IND                  _KPMOD_SHIFT + 19  
#define DL_DATA_REQ                  _KPMOD_SHIFT + 20  
#define DL_DATA_RES                  _KPMOD_SHIFT + 21  
//Primitives For Data Physic Level
#define PH_DATA_IND                  _KPMOD_SHIFT + 22  
#define PH_DATA_REQ                  _KPMOD_SHIFT + 23  

#define PH_CONN_REQ                  _KPMOD_SHIFT + 24  
#define PH_DISC0_REQ                 _KPMOD_SHIFT + 25  
#define PH_DISC_REQ                  _KPMOD_SHIFT + 26  
#define PH_CONN_IND                  _KPMOD_SHIFT + 27  
#define PH_DISC_IND                  _KPMOD_SHIFT + 28  

#define PH_DATA_RES                  _KPMOD_SHIFT + 29  
#define PH_DATA1_RES                 _KPMOD_SHIFT + 30  

#define PH_DATA_CON                  _KPMOD_SHIFT + 31  
#define PH_DATA_NCON                 _KPMOD_SHIFT + 32  
#define PH_DATA_REP                  _KPMOD_SHIFT + 33  
#define PH_DATA_RD_CON               _KPMOD_SHIFT + 34  

#define PH_DATA_UP_REQ               _KPMOD_SHIFT + 35  
#define PH_INIT_REQ                  _KPMOD_SHIFT + 36  
#define PH_CALL_REQ                  _KPMOD_SHIFT + 37 
#define PH_TIME_ST_REQ               _KPMOD_SHIFT + 38  
#define PH_CLOSE_PORT_REQ            _KPMOD_SHIFT + 39 
#define PH_INIT_PORT_REQ             _KPMOD_SHIFT + 40 
#define PH_SETT_KPID_REQ             _KPMOD_SHIFT + 41 
#define PH_VS0_REQ                   _KPMOD_SHIFT + 42 
#define PH_VS1_REQ                   _KPMOD_SHIFT + 43 
#define PH_SCMD_REQ                  _KPMOD_SHIFT + 44 
 

#define PH_DATA_RD_REQ               _KPMOD_SHIFT + 65 
#define PH_DATA_WR_REQ               _KPMOD_SHIFT + 66 
#define EV_TMR_SRR_REQ               _KPMOD_SHIFT + 67 //Таймер SRR
#define EV_TMR_SSC_REQ               _KPMOD_SHIFT + 68 //Таймер SSC
#define EV_TMR_DISC_REQ              _KPMOD_SHIFT + 69 //Таймер DISC
#define EV_TMR_CNRP_REQ              _KPMOD_SHIFT + 70 //Таймер DISC
#define EV_TMR_PUCM_REQ              _KPMOD_SHIFT + 71 //Таймер DISC
#define EV_TMR_SDIS_REQ              _KPMOD_SHIFT + 72 //Таймер DISC
#define EV_TMR_RCAL_REQ              _KPMOD_SHIFT + 73 //Таймер DISC
#define EV_TMR_OUT_REQ               _KPMOD_SHIFT + 74 //Таймер DISC
#define EV_CHNG_PIN_REQ              _KPMOD_SHIFT + 75 //Таймер DISC
//Сообщения пролива
#define EV_START_WSY_REQ             _KPMOD_SHIFT + 76 //Запуск модуля
#define EV_HAND_STOP_WSY_REQ         _KPMOD_SHIFT + 77 //Ручной останов
#define EV_HAND_START_WSY_REQ        _KPMOD_SHIFT + 78 //Ручной старт
#define EV_TMR_WTOP_REQ              _KPMOD_SHIFT + 79 //Таймер Ожидания Операционного режима
#define EV_TMR_OPER_REQ              _KPMOD_SHIFT + 80 //Таймер Операционного режима
#define EV_TMR_WTST_REQ              _KPMOD_SHIFT + 81 //Таймер Ожидания Успокоения Жидкости
#define EV_CT_OFF_REQ                _KPMOD_SHIFT + 82 //Счет завершен




#define PL_ASDU_DC0_IND              46
#define PL_ASDU_NVA_IND              48


//Events From PH Level 
#define EV_RESET_SC00_IND            _KPMOD_SHIFT + 0  //Перезапуск удаленной связи
#define EV_DATA_SC03_IND             _KPMOD_SHIFT + 3  //Данные пользователя с повтором
#define EV_DATAN_SC04_IND            _KPMOD_SHIFT + 4  //Данные пользователя без повтора 
#define EV_STJOIN_RR09_IND           _KPMOD_SHIFT + 9  //Запрос статуса связи   
#define EV_DATA1_RR10_IND            _KPMOD_SHIFT + 10 //Запрос данных пользователя класса 1
#define EV_DATA2_RR11_IND            _KPMOD_SHIFT + 11 //Запрос данных пользователя класса 2 
//Events For PH Level 
#define EV_ACK_SC00_CON              _KPMOD_SHIFT + 0  //ACK: положительное подтверждение
#define EV_NACK_SC01_CON             _KPMOD_SHIFT + 1  //NACK: сообщение не принято, линия занята
#define EV_ACK_RR08_RES              _KPMOD_SHIFT + 8  //Данные пользователя
#define EV_NACK_RR08_RES             _KPMOD_SHIFT + 9  //NACK: затребованные данные недоступны
#define EV_STJOIN_RR08_RES           _KPMOD_SHIFT + 11 //Статус связи или требование доступа 

//State For KP Machine
#define MKP_NULL_ST00                0    
#define MKP_CONN_ST01                1    
#define MKP_DISC_ST02                2    

//State For 101 Machine
#define M101_NULL_ST00               0    
#define M101_CONN_ST01               1    
#define M101_DISC_ST02               2    

//State For GSM Machine
#define MGSM_DISC_ST00               0 
#define MGSM_CONN_ST01               1 
#define MGSM_WCON_ST02               2 

#define MSG_LONG_CODE 0x68
#define MSG_SHRT_CODE 0x10

#define MSG_ASDU_DQ_CODE 46
#define MSG_ASDU_WR_CODE 48
#define MSG_ASDU_RD_CODE 102
#define MSG_TIME_ST_CODE 103

#define MSK_RES 0x80
#define MSK_PRM 0x40
#define MSK_FCB 0x20
#define MSK_FCV 0x10

/////////////////////////////////////////////////////////////////////////////
//END;                        Level Module 101                             //
/////////////////////////////////////////////////////////////////////////////




//Para Pid Init 
#define SNS_PARA_INI 0
#define SNS_PIDC_INI 1
#define SNS_SENS_INI 2
#define SNS_SENS_CTR 3
#define SNS_SENS_OUT 4
//Para Init
#define PR_Y_max    0
#define PR_Y_min    1
#define PR_dY_max   2
#define PR_Kp       3
#define PR_Tn       4
#define PR_Tv       5
#define PR_Tf       6
#define PR_Kw       7
#define PR_Kfbk     8
#define PR_PrEn     9
//Pid Init
#define PR_W        10
#define PR_X        11
#define PR_A        12
#define PR_Y_man    13
#define PR_out_mode 14
#define PR_PidEn    15
//Sensor Init
#define PR_LO       16
#define PR_HI       17
#define PR_ALO      18
#define PR_AHI      19
#define PR_PLO      20
#define PR_PHI      21
#define PR_ACO      22
#define PR_PDO      23
#define PR_RST      24
#define PR_INI      25
#define PR_INC_IN   26
#define PR_DEC_IN   27
#define PR_Out_En   28
#define PR_Inp_En   29
#define PR_Lay_En   30
#define PR_OPN_GT   31
#define PR_OMIN     32
#define PR_OMAX     33
#define PR_PMODE    34
#define PR_OMODE    35
#define PR_STOP_GT  36
#define PR_ACM      37
#define PR_OTIME    38
#define PR_EnFlt    39
#define PR_PRC_GT   40

#define EV_SMSNS_SET_PARAM_REQ       _SMSNS_SHIFT + 0 //Установить параметры   //Len Type LenParam Param

//Timer Message
#define EV_TMR000_ADMIN     26 
#define EV_TMRTIN_SYSTM     27 
#define EV_TMRTIN_ARMIN     28 

//Debug Flags
#define DEB_OUT_CYC_ADMIN 0x01  
#define DEB_OUT_CYC_SYSTM 0x02  
#define DEB_OUT_CYC_OBSRV 0x04  
#define DEB_OUT_PMAN_STAT 0x08  
#define DEB_OUT_OBSR_COMM 0x10  
#define DEB_OUT_DIRC_COMM 0x20  

#define DEB_OUT_BOX_ADMIN 0x40  
#define DEB_OUT_BOX_SYSTM 0x80  
#define DEB_OUT_BOX_OBSRV 0x100  

//Timer Constant 
enum _enTimeConst
{
	    /*
		T05SEC =  5*100/SYSTEM_QTIME,     
	    T1SEC  = 10*100/SYSTEM_QTIME,
		T2SEC  = 20*100/SYSTEM_QTIME,
		T3SEC  = 30*100/SYSTEM_QTIME,
        T4SEC  = 40*100/SYSTEM_QTIME,
		T5SEC  = 50*100/SYSTEM_QTIME,
		T6SEC  = 60*100/SYSTEM_QTIME,
        T7SEC  = 70*100/SYSTEM_QTIME,
		T8SEC  = 80*100/SYSTEM_QTIME,
        T9SEC  = 90*100/SYSTEM_QTIME,
		T10SEC =100*100/SYSTEM_QTIME,
		*/
  	    T05SEC =  5,     
		T1SEC  = 10,
		T2SEC  = 20,
		T3SEC  = 30,
        T4SEC  = 40,
		T5SEC  = 50,
		T6SEC  = 60,
        T7SEC  = 70,
		T8SEC  = 80,
        T9SEC  = 90,
		T10SEC =100,
};


//Max Switching In Direction
#if MYSYSTEM_ID !=5 
#define DEV_AMT_SWC_IDIR      20
#else
#define DEV_AMT_SWC_IDIR      150
#endif

//Max Out Gate
#define DEV_AMT_GATE_SNS      5
//Max Base Gate
#define BASE_GTE              6683
#define MAX_GTE               5100
//Max Out Gate TYPE
enum _tagTypeGate
{
	IDLES_GTE=0,
	SMART_GTE,
};
enum _tagTeleSignal
{
	TS=0,
	TI,
	TU,
	TIS,
	TC,
	TPR,
	TTM,
	TF,
	TKP,
	TPU,
	TVS,
	TLV,
	TPL,
	TMR,
	TAL,
	TOS,
};
//Max Direction In System
#define DEV_AMT_DIR_INST      1
//Proc Manager State
enum _enManagerState
{
        DEV_PROC_STT_ONN = 0,
        DEV_PROC_STT_OFF,
};
//System Queue ID
#define DEV_ARMIN_BOX_ID      0
#define DEV_ARMOT_BOX_ID      1
#define DEV_ARMAD_BOX_ID      2
#define DEV_SYSTM_BOX_ID      3
#define DEV_ADMIN_BOX_ID      4
#define DEV_KPMDL_BOX_ID      5
#define DEV_101MD_BOX_ID      6
#define DEV_GSMMD_BOX_ID      7
#define DEV_RSMMD_BOX_ID      8
#define DEV_RSBUF_BOX_ID      9
#define BOX_L4                10  
#define BOX_REG               11
#define BOX_L4_1              12 

#define DEV_RSVBS0_BOX_ID     13
#define DEV_RSVS0MMD_BOX_ID   14

#define DEV_RSVBS1_BOX_ID     15
#define DEV_RSVS1MMD_BOX_ID   16

#define DEV_TCPRM_BOX_ID      17
#define DEV_TCPBF_BOX_ID      18
#define DEV_MSMDL_BOX_ID      19



//System Queue Size
#define DEV_SYSTM_BOX_SZ      512    // No
#define DEV_ADMIN_BOX_SZ      512    // No
#define DEV_ARMIN_BOX_SZ      512    // No 
#define DEV_ARMOT_BOX_SZ      512    // Yes 
#define DEV_ARMAD_BOX_SZ      1*512  // No
#define DEV_KPMDL_BOX_SZ      2*512  // Yes
#define DEV_101MD_BOX_SZ      2*512  // Yes
#define DEV_RSMMD_BOX_SZ      4*1024  // Yes
#define DEV_RSBUF_BOX_SZ      4*1024  // Yes
#define BOX_L4_SZ             10*1024 // Yes
#define BOX_REG_SZ            2*512  // Yes
#define BOX_L4_1_SZ           3*1024 // Yes

//Max Message Size
#define DEV_MAX_MSG_SIZE      256
//Max Cyclic Proc 
#define DEV_MAX_CYC_PROC      10
//Max System Timers
#define DEV_MAX_SYS_TIMR      30
//State Of Thread
#define DEV_CJOB_ST_SUSP      0
#define DEV_CJOB_ST_RESM      1
#define DEV_JOB_MAX_PROD      10
#define DEV_JOB_MAX_PNME      50
//Max TCP Port 
#define DEV_MAX_TCP_PORT      5
#define DEV_MAX_ARM_PORT      5
//Driver State
#define DRV_ST_DISC           0x00
#define DRV_ST_CONN           0x01
#define DRV_ST_NULL           0x02 
#define DRV_ST_OPEN           0x03 
//Port Type
enum _enType
{
   	    DEV_ARM_PORT_TCP=0,
        DEV_ARM_PORT_UDP,
        DEV_ARM_PORT_COM232,
        DEV_ARM_PORT_COM458,
        DEV_ARM_PORT_USB,
        DEV_SYS_INTERFACE,
};
//Port Rate
enum _enRate
{
        DEV_ARM_RATE_9600=0,
        DEV_ARM_RATE_14400,
        DEV_ARM_RATE_38400,
        DEV_ARM_RATE_57600,
        DEV_ARM_RATE_115200,
        DEV_ARM_RATE_10MBS,
        DEV_ARM_RATE_100MB,
};
//Computer Type
#define DEV_CPU_TYPE_PS260    0
#define DEV_CPU_TYPE_X20      0
#define DEV_MAX_TEXT_NAME     50
//Maximum amount slot in device
#define DEV_MAX_SLOTS_PS260   20
#define DEV_CUR_SLOTS_PS260   4
#define DEV_MAX_DEFAULT_PIN   32
//Max Pin In Device
#define DEV_MAX_AI_3AI375_PIN 8
#define DEV_MAX_AO_3AO775_PIN 8
#define DEV_MAX_DI_3DI477_PIN 32
#define DEV_MAX_DO_3DO760_PIN 8
//Max Pin In Device
#define DEV_MAX_DI_X20DM9371_PIN 12
#define DEV_MAX_DI_X20DI9371_PIN 12
#define DEV_MAX_DI_X20DI2377_PIN 2
#define DEV_MAX_DO_X20DM9322_PIN 12
#define DEV_MAX_DO_X20DO9322_PIN 12
#define DEV_MAX_DO_X20DO9321_PIN 12
#define DEV_MAX_AI_X20AI4622_PIN 4
#define DEV_MAX_AI_X20AI2622_PIN 2
#define DEV_MAX_AO_X20AO4622_PIN 4
#define DEV_MAX_AT_X20AT2222_PIN 2
#define DEV_MAX_DI_X20DI2377_PIN 2
//Type Of Device
enum _tagDeviceType
{
        DEV_DEFAULT_PORT=0,
        DEV_PLC_CPU_260,
		DEV_PLC_CPU_X20,
		DEV_TCPCOM_IF_681,
		DEV_PWCOM_PS9500,
		DEV_COM_CS1020,
		DEV_AI_3AI375_6,
		DEV_AI_X20AI4622,
		DEV_AI_X20AI2622,
		DEV_AO_3AO775_6,
		DEV_AO_X20AO4622,
		DEV_DI_3DI477_6,
		DEV_DI_X20DM9371,
		DEV_DI_X20DI9371,
		DEV_DI_X20DI2377,
		DEV_DO_3DO760_6,
		DEV_DO_X20DM9322,
		DEV_DO_X20DO9321,
		DEV_AT_X20AT2222
};
//Hard Pin State
enum _tagPinState
{
		PIN_STATE_DEF=0,
		PIN_STATE_ONN,
		PIN_STATE_OFF,
		PIN_STATE_TRI,
};
//Out State 
enum _tagInOutState
{
	    ST_INIT =0,
		ST_OPEN =1,
		ST_CLOS=2,
		ST_NULL =3,
};
//Type Of Hard Pin
enum _tagPinType
{
		PIN_DEFAULT_PIN=0,
		PIN_AN_INOT_INT,
		PIN_DG_INOT_BOL,
		PIN_ST_INPT_USI,
		PIN_ST_OUTP_USI,
};
#define MAX_POINTER 20
#define BNR_MAX_DIRECTION 16
#define BNR_MAX_CHANNELS  32
//Sensor State
#define ST00_SNS_NULL     0x00
#define ST01_SNS_OPEN     0x01
#define ST02_SNS_CLOS     0x02
//Alarm State
#define ALM_ST_ONN        0x00
#define ALM_ST_OFF        0x01

 //Determination of the modules
enum _enDirection
{
		MDL_ADMIN = 0,
		MDL_HCOMM,
		MDL_ARMMD,
		MDL_SYSTM,
		MDL_DIRMD,
		MDL_CHANN,
		MDL_SENSR,
		MDL_PSENS,
		MDL_TSENS,
		MDL_LSENS,
		MDL_SSENS,
		MDL_COMPT,
		MDL_WRDIN,
		MDL_DINPT,
		MDL_DOUTP,
		MDL_ANINP,
		MDL_ANOUT,
		MDL_CMMIN,
		MDL_TCPDR,
		MDL_COMDR,
		MDL_DEBMS,
		MDL_DLESS,
		MDL_OBSRV,
		MDL_TRSIT,
		MDL_ARMSY,
		MDL_TPIDT,
		DIR_KPMOD,
		DIR_101MD,
		DIR_GSMDL,
		DIR_PHMDL,
        
		DIR_PHTOGSM,
		DIR_PHTOPH,
		DIR_PHTO101,
		DIR_PHTO101P,
		DIR_GSMTO101P,
		DIR_GSMTO101M,
		DIR_101TOGSM,
		DIR_101TOPH,
		DIR_101TOKP,
		DIR_101TO101,
		DIR_KPTO101,
		DIR_KPTOKP,
		DIR_GSMTOPH,
		DIR_PHTOKP,
		DIR_KPTOPH,
		DIR_TCPTOTCP,
		DIR_MSTOTCP,
		DIR_MSTOPH,
		DIR_PHTOMS,
		DIR_MSTOMS,
		DIR_MSTODV,
		DIR_OSYTOOSY,
};
enum _tagSensorOutMode
{
	    NO=0,
        NZ,   
};
//Sensor Proc Mode
enum _tagSensorProcMode
{
	    SDIR = 0,
	    SINV,
};
//Sensor Mode
enum _tagSensorMode
{
        SNS_MD_LOOP = 0,
        SNS_MD_AUTO,
        SNS_MD_MANU,
};
//Sensor Type
enum _tagSensorType
{
	    SNS_SMART = 0,
	    SNS_IDLES,   
	    SNS_EMPTY,   
};
enum _tagParamType
{
	    P_LEVEL=0,   
	    P_TEMPR,   
        P_PRESS,   
};
//SlotNumber
enum _enSlotNumber
{
	    SL00 = 0,
		SL01,
		SL02,
		SL03,
		SL04,
		SL05,
		SL06,
		SL07,
		SL08,
		SL09,
		SL10,
		SL11,
		SL12,
		SL13,
		SL14,
		SL15,
		SLDF,
};
//Pin Number
enum _enPinNumber
{
	    PN00 = 0,
		PN01,
		PN02,
		PN03,
		PN04,
		PN05,
		PN06,
		PN07,
		PN08,
		PN09,
		PN10,
		PN11,
		PN12,
		PN13,
		PN14,
		PN15,
		PN16,
		PN17,
		PN18,
		PN19,
		PN20,
		PN21,
		PN22,
		PN23,
		PN24,
		PN25,
		PN26,
		PN27,
		PN28,
		PN29,
		PN30,
		PN31,
		PNDF,
};
//Soft Switching Command
enum _enSwitchCommand
{
	    SWC_CMD_INP_OUT=0,
        SWC_CMD_INP_INP,
		SWC_CMD_SMR_CON,
		SWC_CMD_IDL_CON,
		SWC_CMD_EMT_CON,
		SWC_CMD_LOG_CON,
};
//Automat 
//
enum _enGateId
{
	GT0=0,
	GT1,
	GT2,
};
//Sensor State 
#define SNS_STATE_FREE 0
#define SNS_STATE_PROC 1
//Sensor Command
#define TMR_SET_ALM_HI 0
#define TMR_REM_ALM_HI 1
#define TMR_SET_ALM_LO 2
#define TMR_REM_ALM_LO 3
enum _enSensorCommand
{
	CMD_OPENGATE=0,
    CMD_SETSTATE,
	CMD_SEND,
	CMD_SETVALUE,
	CMD_TIMERON,
	CMD_TIMEROFF,
	CMD_MOV,
	CMD_CMP,
	CMD_REPMSG,
	CMD_PUTMSG,
	CMD_INCC,
	CMD_CHKBUF,
	CMD_CHECKTI,
	CMD_CODE,
	CMD_START_FC,
	CMD_STOP_FC,
	CMD_START_PU,
	CMD_STOP_PU,
	CMD_START_CT,
	CMD_STOP_CT,
};
//Sensor Value
enum _tagAutoValue
{
	INC_INP=0,
	STATE,
};
enum _enCompareValue 
{
 	JE=0,
	JNE,
	JA,
	JBE,
};
//Reg Keys
enum _enRegParamAddres
{
	REG_KPPAR_ADDR=0,
    REG_PORTT_ADDR,
    REG_HARDT_ADDR,
    REG_SOFTI_ADDR,
    REG_SOFTS_ADDR,
    REG_SOFTU_ADDR,
    REG_SOFTR_ADDR,
};
enum _enKpCommand
{
	CKP_SETT_KPID=4,
	CKP_SETT_TIME=9,
	CKP_CLSE_PORT,
	CKP_SAVE_SETT,
	CKP_REST_BORD,
	CKP_REST_12BR,
	CKP_STOP_REST,
	CKP_FREE_BXL4,
	CKP_SETT_BL41,
	CKP_AUTO_PSWR,
	CKP_REMT_DISC,
	CKP_SVAL_PINS,
	CKP_SVAL_SLOT,
	CKP_STRT_CHTM,
	CKP_STOP_CHTM,
	CKP_INIT_PORT,
};
//Store Buffers Mode
enum _enStoreMode
{
	SBM_TIUNLOAD = 0x01,
	SBM_TSUNLOAD = 0x02,
	SBM_TUUNLOAD = 0x04,
	SBM_TRUNLOAD = 0x08,
};
//Store Buffers Mode
enum _enTParity
{
	NOPAR=0,
	EVEN,
	ODD,
};
enum _enTData
{
	D_7=0,
	D_8,
};
enum _enTStop
{
	S_1=0,
	S_1_5,
	S_2,
};
enum _enTSPtiority
{
	PRI_LO=0,
	PRI_HI,
};
enum _enTeleObjectState
{
	EN_CLOSE=0,
	EN_OPEN,
	EN_LOCK,
	EN_UNLOCK,
};
enum _enTSAlarmMode
{
	EN_LO_TO_HI=0,
	EN_HI_TO_LO,
	EN_AL_TO_AL,
};
enum _enTUType
{
	EN_INVERT=0,
	EN_DIRECT,
};
#endif