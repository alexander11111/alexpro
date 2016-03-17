/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrchains.h
 * Author: Abramenya
 * Created: February 04, 2009
 *******************************************************************/
#ifndef WIN32
#include <bur/plctypes.h>
#endif
#include "typedefs.h"
#include "bnrconst.h"
//Обработчик событий датчика уровня(два выхода) для АС1-3
IMPORT_TASKCHAIN(Skip);
//пустое состояние
IMPORT_STATE(BadState);
/*
IMPORT_STATELIST(STL_LV00_SENS);//2-Out 
IMPORT_STATELIST(STL_PS00_SENS);//2-Out 
IMPORT_STATELIST(STL_TM00_SENS);//1-Out 
IMPORT_STATELIST(STL_LV04_SENS);//1-Out 
IMPORT_STATELIST(STL_LVN4_SENS);//0-Out 
IMPORT_STATELIST(STL_PS04_SENS);//1-Out 
*/
//Gate Logic///////////////////////////////////////
DECLARE_TASKCHAIN(Lv00LoOperGate)
{
	//CMD_OPENGATE,GT0,80,
	//CMD_OPENGATE,GT1,20,
	//CMD_SETVALUE,INC_INP,1,
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00HiOperGate)
{
	//CMD_OPENGATE,GT0,20,
	//CMD_OPENGATE,GT1,80,
	//CMD_SETVALUE,INC_INP,0,
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
//Alarm Logic///////////////////////////////////////
DECLARE_TASKCHAIN(Lv00SetAlmHilev)
{
	//CMD_TIMERON ,TMR_SET_ALM_HI,T5SEC,
	//CMD_TIMEROFF,TMR_REM_ALM_HI,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00RemAlmHiLev)
{
	//CMD_TIMERON ,TMR_REM_ALM_HI,T5SEC,
	//CMD_TIMEROFF,TMR_SET_ALM_HI,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00SetAlmLolev)
{
	//CMD_TIMERON ,TMR_SET_ALM_LO,T5SEC,
	//CMD_TIMEROFF,TMR_REM_ALM_LO,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00RemAlmLolev)
{
	//CMD_TIMERON ,TMR_REM_ALM_LO,T5SEC,
	//CMD_TIMEROFF,TMR_SET_ALM_LO,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
/////////////////////////////////////////
DECLARE_TASKCHAIN(Lv00TmrSetAlmHilev)
{
	CMD_SEND,MDL_ADMIN,EV_ADMIN_SET_ALM_HILEV_REQ,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00TmrRemAlmHiLev)
{
	CMD_SEND,MDL_ADMIN,EV_ADMIN_REM_ALM_HILEV_REQ,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00TmrSetAlmLolev)
{
    CMD_SEND,MDL_ADMIN,EV_ADMIN_SET_ALM_LOLEV_REQ,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv00TmrRemAlmLolev)
{
	CMD_SEND,MDL_ADMIN,EV_ADMIN_REM_ALM_LOLEV_REQ,
	//CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
/////////////////////////////////////////
DECLARE_STATE(Lv00StateFree)
{
    { EV_ADMIN_OPER_LO_REQ,            Lv00LoOperGate     },
    { EV_ADMIN_OPER_HI_REQ,            Lv00HiOperGate     },
    { EV_ADMIN_SET_ALM_HILEV_REQ,      Lv00SetAlmHilev    },
    { EV_ADMIN_REM_ALM_HILEV_REQ,      Lv00RemAlmHiLev    },
    { EV_ADMIN_SET_ALM_LOLEV_REQ,      Lv00SetAlmLolev    },
    { EV_ADMIN_REM_ALM_LOLEV_REQ,      Lv00RemAlmLolev    },
    { EV_SENSR_TMR_SAHI,               Lv00TmrSetAlmHilev },
    { EV_SENSR_TMR_RAHI,               Lv00TmrRemAlmHiLev },
    { EV_SENSR_TMR_SALO,               Lv00TmrSetAlmLolev },
    { EV_SENSR_TMR_RALO,               Lv00TmrRemAlmLolev },
    { EV_UNKNOWN_REQ,                  Skip               }
};
DECLARE_STATELIST(STL_LV00_SENS)
{
    { SNS_STATE_FREE,            Lv00StateFree   },
    { S_BAD,                     BadState        }
};
//Обработчик событий датчика давления(два выхода) для АС1-3
//Gate Logic///////////////////////////////////////
DECLARE_TASKCHAIN(Ps00LoOperGate)
{
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Ps00HiOperGate)
{
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_STATE(Ps00StateFree)
{
    { EV_ADMIN_OPER_LO_REQ,            Ps00LoOperGate     },
    { EV_ADMIN_OPER_HI_REQ,            Ps00HiOperGate     },
    { EV_ADMIN_SET_ALM_HILEV_REQ,      Lv00SetAlmHilev    },
    { EV_ADMIN_REM_ALM_HILEV_REQ,      Lv00RemAlmHiLev    },
    { EV_ADMIN_SET_ALM_LOLEV_REQ,      Lv00SetAlmLolev    },
    { EV_ADMIN_REM_ALM_LOLEV_REQ,      Lv00RemAlmLolev    },
    { EV_SENSR_TMR_SAHI,               Lv00TmrSetAlmHilev },
    { EV_SENSR_TMR_RAHI,               Lv00TmrRemAlmHiLev },
    { EV_SENSR_TMR_SALO,               Lv00TmrSetAlmLolev },
    { EV_SENSR_TMR_RALO,               Lv00TmrRemAlmLolev },
    { EV_UNKNOWN_REQ,                  Skip               }
};
DECLARE_STATELIST(STL_PS00_SENS)
{
    { SNS_STATE_FREE,                  Ps00StateFree      },
    { S_BAD,                           BadState           }
};
//Обработчик событий датчика температуры(один выход) для АС1-4
//Gate Logic///////////////////////////////////////
DECLARE_TASKCHAIN(Tm00LoOperGate)
{
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Tm00HiOperGate)
{
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_STATE(Tm00StateFree)
{
    { EV_ADMIN_OPER_LO_REQ,            Tm00LoOperGate     },
    { EV_ADMIN_OPER_HI_REQ,            Tm00HiOperGate     },
    { EV_ADMIN_SET_ALM_HILEV_REQ,      Lv00SetAlmHilev    },
    { EV_ADMIN_REM_ALM_HILEV_REQ,      Lv00RemAlmHiLev    },
    { EV_ADMIN_SET_ALM_LOLEV_REQ,      Lv00SetAlmLolev    },
    { EV_ADMIN_REM_ALM_LOLEV_REQ,      Lv00RemAlmLolev    },
    { EV_SENSR_TMR_SAHI,               Lv00TmrSetAlmHilev },
    { EV_SENSR_TMR_RAHI,               Lv00TmrRemAlmHiLev },
    { EV_SENSR_TMR_SALO,               Lv00TmrSetAlmLolev },
    { EV_SENSR_TMR_RALO,               Lv00TmrRemAlmLolev },
    { EV_UNKNOWN_REQ,                  Skip               }
};
DECLARE_STATELIST(STL_TM00_SENS)
{
    { SNS_STATE_FREE,                  Tm00StateFree      },
    { S_BAD,                           BadState           }
};
//Обработчик событий датчика уровня(два выхода) для АС4
//Gate Logic///////////////////////////////////////
DECLARE_TASKCHAIN(Lv04LoOperGate)
{
	CMD_OPENGATE,GT0,90,
	CMD_OPENGATE,GT1,30,
	CMD_SETVALUE,INC_INP,1,
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_TASKCHAIN(Lv04HiOperGate)
{
	CMD_OPENGATE,GT0,30,
	CMD_OPENGATE,GT1,90,
	CMD_SETVALUE,INC_INP,0,
	CMD_SETSTATE,SNS_STATE_FREE,
	EXIT_D,
};
DECLARE_STATE(Lv04StateFree)
{
    { EV_ADMIN_OPER_LO_REQ,            Lv04LoOperGate     },
    { EV_ADMIN_OPER_HI_REQ,            Lv04HiOperGate     },
    { EV_ADMIN_SET_ALM_HILEV_REQ,      Lv00SetAlmHilev    },
    { EV_ADMIN_REM_ALM_HILEV_REQ,      Lv00RemAlmHiLev    },
    { EV_ADMIN_SET_ALM_LOLEV_REQ,      Lv00SetAlmLolev    },
    { EV_ADMIN_REM_ALM_LOLEV_REQ,      Lv00RemAlmLolev    },
    { EV_SENSR_TMR_SAHI,               Lv00TmrSetAlmHilev },
    { EV_SENSR_TMR_RAHI,               Lv00TmrRemAlmHiLev },
    { EV_SENSR_TMR_SALO,               Lv00TmrSetAlmLolev },
    { EV_SENSR_TMR_RALO,               Lv00TmrRemAlmLolev },
    { EV_UNKNOWN_REQ,                  Skip               }
};
DECLARE_STATELIST(STL_LV04_SENS)
{
    { SNS_STATE_FREE,                  Lv04StateFree      },
    { S_BAD,                           BadState           }
};
//Обработчик событий датчика уровня(нет выхода) для АС4    
DECLARE_STATELIST(STL_LVN4_SENS)
{
    { SNS_STATE_FREE,                  Tm00StateFree      }, //Как для температуры
    { S_BAD,                           BadState           }  
};
//Обработчик событий датчика давления(один выход) для АС4
DECLARE_STATELIST(STL_PS04_SENS)
{
    { SNS_STATE_FREE,                  Tm00StateFree      }, //Как для температуры
    { S_BAD,                           BadState           }
};
