TYPE
	_msgSystem0 : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"138" #3"16" *)
		m_swLen : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"140" #3"10" *)
		m_sbyFrom : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"141" #3"10" *)
		m_sbyFor : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"142" #3"7" *)
		m_sbyIntType : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"143" #3"7" *)
		m_sbyServerID : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"144" #3"7" *)
		m_sbyType : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"145" #3"7" *)
		m_sbyDirection : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"146" #3"10" *)
		m_sbySensor : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"147" #3"10" *)
		m_sbyInfo : ARRAY[0..349] OF USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"148" #3"7" *)
	END_STRUCT;
	CMTimer : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"16" #3"7" *)
		CCMTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"18" #3"8" *)
		DCMTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"19" #3"8" *)
		SetTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"21" #3"8" *)
		Restart : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"22" #3"11" *)
		OnTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"23" #3"11" *)
		OfTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"24" #3"8" *)
		GetTime : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"25" #3"9" *)
		DoAction : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"26" #3"16" *)
		sMsg : _msgShSystem1;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"28" #3"19" *)
		m_dwSTime : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"29" #3"12" *)
		m_byFor : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"30" #3"11" *)
		m_byFrom : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"31" #3"8" *)
		m_byEvent : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"32" #3"8" *)
		m_byDir : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"33" #3"8" *)
		m_bySens : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"34" #3"8" *)
		m_byBox : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"35" #3"8" *)
		m_nCSystemTimer : CSystemTimer;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"36" #3"3" *)
		pBase : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"36" #3"3" *)
		pThis : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"36" #3"3" *)
		pChld : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmytimer.h" #2"36" #3"3" *)
	END_STRUCT;
	pBufferHiLev : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"12" #3"16" *)
		pb_mBoxCont : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"14" #3"11" *)
		w_mBoxWrite : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"15" #3"11" *)
		w_mBoxRead : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"16" #3"11" *)
		w_mBoxSize : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"17" #3"11" *)
		w_mBoxCSize : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"18" #3"11" *)
		w_mBoxMesCt : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrpob.h" #2"19" #3"11" *)
	END_STRUCT;
	CSystemTimer : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"13" #3"7" *)
		CCSystemTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"15" #3"8" *)
		DCSystemTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"16" #3"8" *)
		RunTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"17" #3"8" *)
		OnTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"18" #3"8" *)
		OfTimer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"19" #3"8" *)
		SetTimerID : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"20" #3"8" *)
		DoAction : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"21" #3"19" *)
		pBase : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"23" #3"3" *)
		pThis : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"23" #3"3" *)
		pChld : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"23" #3"3" *)
		m_blTimerState : BOOL;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"24" #3"11" *)
		m_dwTime : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"25" #3"9" *)
		m_byTimerID : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrsystemtimer.h" #2"26" #3"8" *)
	END_STRUCT;
	_msgShSystem1 : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"174" #3"16" *)
		m_swLen : UINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"176" #3"10" *)
		m_sbyFrom : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"177" #3"10" *)
		m_sbyFor : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"178" #3"7" *)
		m_sbyIntType : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"179" #3"7" *)
		m_sbyServerID : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"180" #3"7" *)
		m_sbyType : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"181" #3"7" *)
		m_sbyDirection : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"182" #3"10" *)
		m_sbySensor : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"183" #3"10" *)
		m_sbyInfo : ARRAY[0..29] OF USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmessage.h" #2"184" #3"7" *)
	END_STRUCT;
	CSystem : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"31" #3"7" *)
		CCSystem : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"33" #3"8" *)
		DCSystem : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"34" #3"8" *)
		CreateSystem : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"36" #3"8" *)
		CreateAdmin : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"37" #3"11" *)
		CreateComputer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"38" #3"11" *)
		CreateSysBox : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"39" #3"8" *)
		CreateObserveModule : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"40" #3"8" *)
		CreateProc : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"41" #3"8" *)
		SwitchSystem : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"42" #3"8" *)
		SendMessage : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"43" #3"8" *)
		SendMsg : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"44" #3"8" *)
		EventHandler : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"45" #3"17" *)
		m_pAdmin : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"48" #3"13" *)
		m_pComputer : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"49" #3"16" *)
		m_pObsModule : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"53" #3"14" *)
		m_p101 : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"55" #3"14" *)
		m_nCom : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"56" #3"14" *)
		m_nCVS0 : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"57" #3"14" *)
		m_nCVS1 : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"58" #3"14" *)
		m_nTCP : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"59" #3"14" *)
		m_nMS : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"60" #3"14" *)
		m_pResetTimer : CMTimer;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"61" #3"11" *)
		m_blSystemInitState : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"62" #3"8" *)
		m_byTcpConn : BOOL;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"63" #3"8" *)
		m_byArmAmout : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"64" #3"8" *)
		m_bySystemID : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"65" #3"8" *)
		m_nCCyclicSystem : CCyclicSystem;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"66" #3"3" *)
		pBase : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"66" #3"3" *)
		pThis : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"66" #3"3" *)
		pChld : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrmysystem.h" #2"66" #3"3" *)
	END_STRUCT;
	CCyclicSystem : STRUCT	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"17" #3"7" *)
		CCCyclicSystem : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"19" #3"8" *)
		DCCyclicSystem : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"20" #3"8" *)
		Create : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"22" #3"11" *)
		CreateSuspend : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"23" #3"11" *)
		Start : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"24" #3"11" *)
		Stop : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"25" #3"8" *)
		SetStateProc : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"26" #3"8" *)
		SetBoxID : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"27" #3"8" *)
		SetPeriod : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"28" #3"8" *)
		SetName : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"29" #3"8" *)
		SendMessageData : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"30" #3"8" *)
		SendMessageData1 : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"31" #3"8" *)
		GetStateProc : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"32" #3"8" *)
		GetWordParam : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"33" #3"8" *)
		CyclicProc : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"34" #3"19" *)
		GetMessage : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"35" #3"16" *)
		EventHandler : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"36" #3"16" *)
		SetMsgAuto : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"38" #3"8" *)
		SetState : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"39" #3"8" *)
		GetStateCode : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"40" #3"14" *)
		HandleEvent : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"41" #3"8" *)
		HandleTask : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"43" #3"16" *)
		GetStateList : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"44" #3"21" *)
		GetState : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"45" #3"9" *)
		v : ARRAY[0..19] OF USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"47" #3"8" *)
		m_pvState : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"48" #3"9" *)
		m_vState : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"49" #3"17" *)
		m_pStateList : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"50" #3"14" *)
		m_byPeriod : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"52" #3"9" *)
		m_byStateProc : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"53" #3"9" *)
		m_byBoxID : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"54" #3"9" *)
		m_chProcName : ARRAY[0..49] OF SINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"55" #3"9" *)
		m_nsMessage : _msgSystem0;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"56" #3"12" *)
		m_dwAmoutQuant : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"57" #3"9" *)
		m_nATmr : ARRAY[0..3] OF CMTimer;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"58" #3"11" *)
		m_dwTM : ARRAY[0..3] OF UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"59" #3"9" *)
		m_byAutoState : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"60" #3"8" *)
		V0 : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"61" #3"8" *)
		V1 : USINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"61" #3"11" *)
		m_dwAutoTime : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"62" #3"9" *)
		pBase : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"63" #3"3" *)
		pThis : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"63" #3"3" *)
		pChld : UDINT;	(* #1"D:/Vagez/x20ost/Logical/bnrmain/bnrcyclicsystem.h" #2"63" #3"3" *)
	END_STRUCT;
END_TYPE