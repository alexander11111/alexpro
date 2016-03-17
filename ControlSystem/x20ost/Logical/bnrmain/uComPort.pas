{***************************************************************
 *
 * Unit Name: uComPort
 * Purpose  : Serial port control
 * Author   : ŒŒŒ "¿¬“ŒÃ¿“»«¿÷»ﬂ 2000"
 * History  :
 *
 ****************************************************************}

unit uComPort;

interface

uses
  Windows, Classes, SysUtils,bnrbox,SyncObjs,DbugIntF;

type
  {Basic types}
  TStBaudRates = (brManual, br50, br110, br300, br600, br1200, br2400, br4800,
                  br9600, br14400, br19200, br28800, br38400, br56000, br57600,
                  br115200, br128000, br230400, br256000, br460800, br921600);
  TDatabits = (db5, db6, db7, db8);
  TStopbits = (sb1, sb1half, sb2);
  //TParity = (pNone, pOdd, pEven, pMark, pSpace);
  TStDCBFlag = (flBinary, flParity, flOutxCTSFlow, flOutxDSRFlow, flDTRControlEnable,
                 flDTRControlHandshake, flDSRSensivity, flTXContinueOnXoff, flOutX, flInX,
                 flErrorChar, flNil, flRTSControlEnable, flRTSControlHandshake, flAbortOnError);
  TStDCBFlags = Set of TStDCBFlag;
  TStByteSize = (bs_5_Bits, bs_6_Bits, bs_7_Bits, bs_8_Bits);
  TStParity   = (pNone, pOdd, pEven, pMark, pSpace);
  TStStopBits = (sbOne, sbOneHalf, sbTwo);

const
  {Errors}
  BufferFull    = $01;
  BufferEmpty   = $02;
  OutOfRange    = $03;
  LineStatusErr = $04;
  Error         = $05;
  //BaudValues: array[TBaudRate] of Dword = (110, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200);
  EVENT_MASK = EV_BREAK	or EV_CTS	or EV_DSR or EV_ERR or EV_RING or EV_RLSD or EV_RXCHAR or EV_RXFLAG or EV_TXEMPTY;

type

  TErrorEvent = procedure(Sender : TObject; ErrorCode : Byte) of object;
  //TNotifyReceiveEvent = procedure(DataBuf: array of Byte; Count : DWord;wRD:Word;wWR:Word;wSZ:Word;b0:Byte;b1:Byte) of object;
  TNotifyReceiveEvent = procedure(DataBuf: array of Byte; Count : DWord) of object;
  TComPort = class;

  {Basic thread that's created on opening port. It fulfils continuous reading of port}
  TComThread = class(TThread)
  private
    FComPort: TComPort;
  protected
    procedure Execute; override;
  end;
  TReadThread = class(TThread)
  private
    FComPort: TComPort;
  protected
    procedure Execute; override;
  end;
  TComPort = class(TPersistent)
  private
    { Public declarations }
    CriticalSection : TCriticalSection;
    FEventThread: TComThread;
    FReadThread : TReadThread;
    FHandle: THandle;
    FPortNum: Byte;

    FBaudRate   : TStBaudRates;
    FManualRate : DWord;
    FDCBFlag    : TStDCBFlags;
    FXonLim     : Word;
    FXoffLim    : Word;
    FByteSize   : TStByteSize;
    FParity     : TStParity;
    FStopBits   : TStStopBits;
    FXonChar    : Char;
    FXoffChar   : Char;
    FErrorChar  : Char;
    FEofChar    : Char;
    FEvtChar    : Char;

    FReadIntervalTimeout         : DWord;
    FReadTotalTimeoutMultiplier  : DWord;
    FReadTotalTimeoutConstant    : DWord;
    FWriteTotalTimeoutMultiplier : DWord;
    FWriteTotalTimeoutConstant   : DWord;


    FActive: Boolean;
    FInBuffer: array of Byte;
    FSndBuffer: array[0..1000] of Byte;
    FData: array[0..1000] of Byte;
    FNextPosToWrite : Word;
    FNextPosToRead : Word;
    FMask: DWORD;
    FHandleEvents: Integer;
    FBufferUsed: Boolean;
    FBufferFull: Boolean;
    FBlTxEmpty : Boolean;
    FRTS: Boolean;
    FDTR: Boolean;
    FDSR: Boolean;
    FCTS: Boolean;
    FRLSD: Boolean;
    FRING: Boolean;
    FRTUInterval: DWORD;
    FOnRTUPacket: TNotifyReceiveEvent;
    FOnOpen : TNotifyEvent;
    FOnClose : TNotifyEvent;
    FOnTxEmpty : TNotifyEvent;
    FOnRing : TNotifyEvent;
    FOnRxFlag : TNotifyEvent;
    FOnError : TErrorEvent;
    FOnChangeCTS: TNotifyEvent;
    FOnChangeDSR: TNotifyEvent;
    FOnChangeRLSD: TNotifyEvent;
    FOnChangeRING: TNotifyEvent;
    FOnBreak: TNotifyEvent;
    FOnReceive: TNotifyReceiveEvent;
    pB:CTBox;
    mCurLen:Word;
    //Buffer Section
    procedure CallRxChar;
    procedure CallTxEmpty;
    procedure CallBreak;
    procedure CallRxFlag;
    procedure CallRing;
    procedure CallModemStatusChange;

    procedure DoRTUPacket;
    procedure DoEvents;
    procedure DoOnError(Error: Byte);
    procedure DoOnByteReceived(Data : Byte);

    function GetInBufferSize: Word;
    function GetBufferUsed : Word;
    procedure SetInBufferSize(Value : Word);
    //procedure SetComPortSettings;
    //procedure GetComPortSettings;
    procedure SetPort(Value : Byte);
    procedure SetFDTR(const Value: Boolean);
    procedure SetFRTS(const Value: Boolean);

    function ImportDCB : TDCB;
    procedure ExportDCB(const PortDCB: TDCB);
    function GetPortDCB(PortHandle: THandle): Boolean;
    function SetPortDCB(PortHandle: THandle): Boolean;



    {
    procedure SetBaudRate(Value : TBaudRate);
    procedure SetManualRate(Value: Integer);
    procedure SetParity(Value : TParity);
    procedure SetDatabits(Value : TDatabits);
    procedure SetStopbits(Value : TStopbits);
    }

    procedure SetBaudRate(const Value: TStBaudRates);
    procedure SetManualRate(const Value: DWord);
    procedure SetDCBFlags(const Value: TStDCBFlags);
    procedure SetByteSize(const Value: TStByteSize);
    procedure SetParity(const Value: TStParity);
    procedure SetStopBits(const Value: TStStopBits);
    procedure AssignTo(Dest: TPersistent); override;

    //procedure AssignTo(Dest: TPersistent); override;
    function ImportCommTimeOuts : TCommTimeOuts;
    procedure ExportCommTimeOuts(const PortTimeOuts: TCommTimeOuts);
    function GetPortTimeOuts(PortHandle: THandle): Boolean;
    function SetPortTimeOuts(PortHandle: THandle): Boolean;


    function  GetRTUInterval: DWORD;
    procedure SetRTUInterval(const Value: DWORD);
    procedure SetActive(const Value: Boolean);
    procedure MakeMessage;
    procedure MakeTextMessage;
    procedure CopyMessage(wLen:Word);
    function  CalckKS(Buffer: PByteArray;wLen: Integer): Byte;
    procedure TextHandler(var pbyText : array of Byte;lLen : Word);
    procedure ATHandler(var pbyText : array of Byte;lLen : Word);
    procedure SetUpBuffer;
    procedure SendToL2(byType : Byte);
    //Buffer Sectin
    function SendMesage:Boolean;
  public
    //Red Buffer Section
     SndBuffer         : array[0..1000] of Byte;
     pb_mBoxDoRead     : array[0..5000] of Byte;
     pb_mBoxDoTextRead : array[0..5000] of Byte;
     pb_mBoxCont       : array[0..17000] of Byte;
     m_sMsg            : CMessage;
     InByteCount_DATA  : Word;
     FoundSTART_DATA   : Word;
     SaveRead          : Word;
     w_nTextLen        : Word;
     SB0,SB1           : byte;
     w_mBoxWrite       : Integer;
     w_mBoxRead        : Integer;
     w_mBoxSize        : Integer;
     w_mBoxCSize       : Integer;
     w_mBoxMesCt       : Integer;
     w_mBoxSEnd        : Integer;
     m_sSize           : Integer;
     m_byMType         : Byte;
    //Red Buffer Section

    constructor Create;
    destructor Destroy; override;
    {Port handle}
    procedure ResetCom;
    property Handle : THandle read FHandle;
    {Clears the input buffer}
    procedure ResetBuffer;
    {Opens serial port. Returns True on success}
    function OpenPort: Boolean;
    {Closes serial port}
    procedure Close;
    {Number of serial port}
    property PortNum : Byte read FPortNum write SetPort default 1;
     {Shows serial port settigs dialog}
    function PortSettingsDialog(WinHandle : THandle): Boolean;
    {Send byte to serial port. Returns True on success}
    function SendByte(B : Byte) : Boolean;
    {Sends array of bytes to serial port}
    function SendArray(A : Pointer; Count : Word) : Boolean;
    {Sends string to serial port}
    function SendStr(S : String) : Boolean;
    {True if port is open}
//    property IsOpened: Boolean read FIsOpened;
    property Active: Boolean read FActive write SetActive;
    {Size of input buffer}
    property InBufferSize : Word read GetInBufferSize write SetInBufferSize default 4096;
    {Contains current buffer size, that means how many bytes in input buffer}
    property BufferUsed: Word read GetBufferUsed;
    {Port settings}
    {
    property ManualRate:Integer read FManualRate write SetManualRate default 9600;
    property BaudRate : TBaudRate read FBaudrate write SetBaudRate default br9600;
    property Parity : TParity read FParity write SetParity default pNone;
    property Databits : TDatabits read FDatabits write SetDatabits default db8;
    property Stopbits : TStopbits read FStopbits write SetStopbits default sb1;
    }
    property BaudRate    : TStBaudRates read FBaudRate   write SetBaudRate;
    property ManualRate  : DWord        read FManualRate write SetManualRate;
    property DCBFlag     : TStDCBFlags  read FDCBFlag    write SetDCBFlags;
    property XonLim      : Word         read FXonLim     write FXonLim;
    property XoffLim     : Word         read FXoffLim    write FXoffLim;
    property ByteSize    : TStByteSize  read FByteSize   write SetByteSize;
    property Parity      : TStParity    read FParity     write SetParity;
    property StopBits    : TStStopBits  read FStopBits   write SetStopBits;
    property XonChar     : Char         read FXonChar    write FXonChar;
    property XoffChar    : Char         read FXoffChar   write FXoffChar;
    property ErrorChar   : Char         read FErrorChar  write FErrorChar;
    property EofChar     : Char         read FEofChar    write FEofChar;
    property EvtChar     : Char         read FEvtChar    write FEvtChar;

    property ReadIntervalTimeout         : DWord read FReadIntervalTimeout         write FReadIntervalTimeout;
    property ReadTotalTimeoutMultiplier  : DWord read FReadTotalTimeoutMultiplier  write FReadTotalTimeoutMultiplier;
    property ReadTotalTimeoutConstant    : DWord read FReadTotalTimeoutConstant    write FReadTotalTimeoutConstant;
    property WriteTotalTimeoutMultiplier : DWord read FWriteTotalTimeoutMultiplier write FWriteTotalTimeoutMultiplier;
    property WriteTotalTimeoutConstant   : DWord read FWriteTotalTimeoutConstant   write FWriteTotalTimeoutConstant;

    {Reads byte from serial port and removes it from buffer}
    function GetByte : Byte;
    function GetBytes(var OutBuf : array of Byte; Count : Word): Word;
     {Gte byte from the buffer at specified position. That byte remains in buffer}
    function Peekbyte(No: Word): Byte;

   {When True that means to use RTS signal on transmition}
    property RTS : Boolean read FRTS write SetFRTS default False;
   {When True that means to use DTR signal on transmition}
    property DTR : Boolean read FDTR write SetFDTR default False;
    property CTS : Boolean read FCTS;
    property DSR : Boolean read FDSR;
    property RLSD: Boolean read FRLSD;
    { RTU properties }
    property RTUInterval: DWORD read GetRTUInterval write SetRTUInterval;
    property OnRTUPacket: TNotifyReceiveEvent read FOnRTUPacket write FOnRTUPacket;

    { Notifications }
    property OnChangeCTS : TNotifyEvent read FOnChangeCTS write FOnChangeCTS;
    property OnChangeDSR : TNotifyEvent read FOnChangeDSR write FOnChangeDSR;
    property OnChangeRLSD : TNotifyEvent read FOnChangeRLSD write FOnChangeRLSD;
    property OnChangeRING : TNotifyEvent read FOnChangeRING write FOnChangeRING;
    property OnBreak : TNotifyEvent read FOnBreak write FOnBreak;
    property OnTxEmpty : TNotifyEvent read FOnTxEmpty write FOnTxEmpty;
    property OnRxFlag : TNotifyEvent read FOnRxFlag write FOnRxFlag;
    property OnReceive : TNotifyReceiveEvent read FOnReceive write FOnReceive;
    property OnError : TErrorEvent read FOnError write FOnError;
  end;


implementation
Var
   hRxEvent:THandle;
const
   StBaudRate : Array[TStBaudRates] of DWord =
               (0, 50, CBR_110, CBR_300, CBR_600, CBR_1200, CBR_2400, CBR_4800,
                CBR_9600, CBR_14400, CBR_19200, 28800, CBR_38400, CBR_56000, CBR_57600,
                CBR_115200, CBR_128000, 230400, CBR_256000, 460800, 921600);

   StByteSize : Array[TStByteSize] of Byte = (5, 6, 7, 8);
   StParity   : Array[TStParity]   of Byte = (NOPARITY, ODDPARITY, EVENPARITY, MARKPARITY, SPACEPARITY);
   StStopBits : Array[TStStopBits] of Byte = (ONESTOPBIT, ONE5STOPBITS, TWOSTOPBITS);
   BSZ = $7ff;
{ TComPort }
procedure TComPort.CallBreak;
begin
  if assigned(FOnBreak) then FOnBreak(Self);
end;


procedure TComPort.CallModemStatusChange;
var
  b: Boolean;
  w: DWORD;
begin
  GetCommModemStatus(FHandle, w);
  b := (w and MS_CTS_ON) <> 0;
  if FCTS <> b then begin
    FCTS := b;
    if Assigned(FOnChangeCTS) then FOnChangeCTS(Self);
    end;

  b := (w and MS_DSR_ON) <> 0;
  if FDSR <> b then begin
    FDSR := b;
    if Assigned(FOnChangeDSR) then FOnChangeDSR(Self);
    end;

  b := (w and MS_RLSD_ON) <> 0;
  if FRLSD <> b then begin
    FRLSD := b;
    if Assigned(FOnChangeRLSD) then FOnChangeRLSD(Self);
    end;

  b := (w and MS_RING_ON) <> 0;
  if FRING <> b then begin
    FRING := b;
    if Assigned(FOnChangeRING) then FOnChangeRING(Self);
    end;
end;


procedure TComPort.CallRing;
begin
  if Assigned(FOnRing) then FOnRing(Self);
end;

constructor TComPort.Create;
begin
  inherited;

  FHandle   := INVALID_HANDLE_VALUE;
  FPortNum  := 2;
  FRTS      := False;
  FDTR      := False;
  FActive   := False;

  FBaudRate    := br57600;
  FManualRate  := CBR_57600;
  FDCBFlag     := [flBinary];
  FXonLim      := 2048;
  FXoffLim     := 512;
  FByteSize    := bs_8_Bits;
  FParity      := pEven;
  FStopBits    := sbOne;
  FXonChar     := #17;
  FXoffChar    := #19;
  FErrorChar   := #0;
  FEofChar     := #0;
  FEvtChar     := #0;

  FReadIntervalTimeout         := MaxDWord;
  FReadTotalTimeoutMultiplier  := 0;
  FReadTotalTimeoutConstant    := 0;
  FWriteTotalTimeoutMultiplier := 0;
  FWriteTotalTimeoutConstant   := 0;

  InBufferSize := 4096;
  ResetBuffer;
  FHandleEvents := CreateEvent(nil, True, True, nil);
  FRTUInterval  := INFINITE;
  FBlTxEmpty    := True;
  SetUpBuffer;
  FDEFINE(BOX_L1,BSZ,False);
  ResetEvent(hRxEvent);
end;
procedure TComPort.SetUpBuffer;
Begin
  w_mBoxSize  := BSZ;
  w_mBoxCSize := BSZ;
  w_mBoxWrite := 0;
  w_mBoxRead  := 0;
  w_mBoxMesCt := 0;
  m_sSize     := 0;
  SaveRead    := 0;
End;
procedure TComPort.ResetCom;
Begin
  w_mBoxSize  := BSZ;
  w_mBoxCSize := BSZ;
  w_mBoxWrite := 0;
  w_mBoxRead  := 0;
  w_mBoxMesCt := 0;
  m_sSize:=0;
  FBlTxEmpty := True;
  ResetEvent(hRxEvent);
End;
destructor TComPort.Destroy;
begin
  CloseHandle(FHandleEvents);
  Close;
  InBufferSize := 0;
  inherited;
end;
procedure TComPort.CallRxChar;
var
  w_lLength,i: Integer;
  n,BytesTrans: DWORD;
  CS: ComStat;
  Success: Boolean;
  Ov: TOverlapped;
  byBuff : CMessage;
begin
  ClearCommError(FHandle, n, @CS);
  w_lLength := CS.cbInQue;
  if w_lLength <= 0 then Exit;
  Ov.hEvent := FHandleEvents;
  Success := ReadFile(FHandle, pb_mBoxDoRead, w_lLength, BytesTrans, @Ov);
  //SendDebug('(__)MSG::>');
  for i:=0 to w_lLength-1 do
  Begin
   pb_mBoxCont[w_mBoxWrite]:=pb_mBoxDoRead[i];
   w_mBoxWrite := (w_mBoxWrite + 1) and BSZ;
   //SendDebug(IntToHex(pb_mBoxDoRead[i],2));
   //SendDebug(Char(pb_mBoxDoRead[i]));
  End;
  w_mBoxSize  := w_mBoxSize   - w_lLength;
  m_sSize     := w_mBoxCSize  - w_mBoxSize;
  if ((pb_mBoxCont[w_mBoxRead]=$68)or(pb_mBoxCont[w_mBoxRead]=$10)) then
  Begin
   //SendDebug('(__)Data Message.');
   m_byMType := 0;
   SetEvent(hRxEvent);
  End else
  if((pb_mBoxCont[w_mBoxRead]=$0d){and(pb_mBoxCont[w_mBoxRead+1]=$0a)}) then
  Begin
   SendDebug('(__)AT Command.');
   m_byMType := 1;
   SB0 := $0d; SB1 := $0a;
   SetEvent(hRxEvent);
  End else
  if(pb_mBoxCont[w_mBoxRead]=$7e) then
  Begin
   SendDebug('(__)Text Info.');
   SB0 := $7e; SB1 := $e7;
   m_byMType := 2;
   SetEvent(hRxEvent);
  End else
  Begin
     SetUpBuffer;
     SendDebug('(__)Synchronization.');
  End;
End;
procedure TComPort.MakeTextMessage;
Var
   byInByte  : Byte;
   byInByte1 : Byte;
   wLen,wRD : Word;
   //w_lLength,i:integer;
   strText : String;
Begin
  //SendDebug('(__)Text::>WR:'+IntToStr(w_mBoxWrite)+':RD:'+IntToStr(w_mBoxRead));
  wRD        := w_mBoxRead + SaveRead;
  while (w_mBoxWrite<>wRD)  do
  begin
   byInByte := pb_mBoxCont[wRD];
   //SendDebug('(__)Text::>WR:'+IntToStr(w_nTextLen)+':I:'+IntToStr(wRD)+':C:'+Char(byInByte));
   wRD      := (wRD+1) and BSZ;
   byInByte1:= pb_mBoxCont[wRD];
   SaveRead := (SaveRead+1) and BSZ;
   Inc(w_mBoxSize);
   if  FoundSTART_DATA=0 then
   begin
    if (byInByte=SB0){and(byInByte1=SB1)} then
    begin
     SendDebug('(__)Start');
     FoundSTART_DATA  := 1;
     InByteCount_DATA := 0;
    end;
   end
  else
  begin
   if (byInByte=SB0){and(byInByte1=SB1)} then
   Begin
     FoundSTART_DATA  := 0;
     if (m_byMType=1) then ATHandler(pb_mBoxDoTextRead,InByteCount_DATA-1);
     if (m_byMType=2) then TextHandler(pb_mBoxDoTextRead,InByteCount_DATA-1);
     SendDebug('(__)Found Command! '+IntToStr(InByteCount_DATA));
     InByteCount_DATA := 0;
     SetUpBuffer;
     //w_mBoxRead := wRD;
     exit;
   End
   else
   Begin
    pb_mBoxDoTextRead[InByteCount_DATA] := byInByte;
    if InByteCount_DATA>300 then Begin InByteCount_DATA := 0;SetUpBuffer; End;
    Inc(InByteCount_DATA);
   End;
  end;
 end;
End;
procedure TComPort.ATHandler(var pbyText : array of Byte;lLen : Word);
Var
   strText : String;
   i       : Integer;
Begin
   strText := '';
   for i:=0 to lLen-1 do strText := strText + Char(pbyText[i+1]);
   SendDebug('(__)CLML1::>At Command::>'+strText);
   if Pos('CONNECT',strText)>0    then Begin SendToL2(PH_CONN_IND);SetUpBuffer End;
   if Pos('RING',strText)>0       then Begin SendToL2(PH_RING_IND);SetUpBuffer End;
   if Pos('NO CARRIER',strText)>0 then Begin SendToL2(PH_DISC_IND);SetUpBuffer End;
   if Pos('NO ANSWER',strText)>0  then Begin SendToL2(PH_NANS_IND);SetUpBuffer End;
End;
procedure TComPort.SendToL2(byType : Byte);
Begin
   //SendDebug('(__)CLML1::>Text');
   with m_sMsg do begin
   w_swLen        := 9;
   m_sbyFrom      := FROM_L1;
   m_sbyFor       := FOR_L1TOAT;
   m_sbyIntType   := 0;
   m_sbyServerID  := 0;
   m_sbyDirection := 0;
   m_sbySensor    := 0;
   m_sbyType      := byType;
   FPUT(BOX_L2,@m_sMsg);
   End;
End;
procedure TComPort.TextHandler(var pbyText : array of Byte;lLen : Word);
Begin
   //SendDebug('(__)CLML1::>Text');
   Move(pbyText[1],m_sMsg.m_sbyInfo,lLen);
   with m_sMsg do begin
   w_swLen        := 9+lLen;
   m_sbyFrom      := FROM_L1;
   m_sbyFor       := FOR_L1TOTXT;
   m_sbyIntType   := 0;
   m_sbyServerID  := 0;
   m_sbyDirection := 0;
   m_sbySensor    := 0;
   m_sbyType      := PH_TEXT_IND;
   FPUT(BOX_L2,@m_sMsg);
   End;
End;
procedure TComPort.MakeMessage;
Var
   lLen : Byte;
Begin
   lLen := pb_mBoxCont[(w_mBoxRead+1) and BSZ]+6;
   while((m_sSize>=lLen)and(pb_mBoxCont[w_mBoxRead]=$68)) do CopyMessage(lLen);
   lLen := 5;
   while((m_sSize>=lLen)and(pb_mBoxCont[w_mBoxRead]=$10)) do CopyMessage(lLen);
End;
procedure TComPort.CopyMessage(wLen:Word);
Var
   i:Integer;
   byCRC,byLen:Byte;
   blCRC : Boolean;
Begin
   with m_sMsg do begin
   for i:=0 to wLen-1 do
   Begin
    m_sbyInfo[i]:=pb_mBoxCont[w_mBoxRead];
    Inc(w_mBoxSize);
    w_mBoxRead:=(w_mBoxRead+1)and BSZ;
   End;
   m_sSize := (w_mBoxCSize-w_mBoxSize) and BSZ;
   w_swLen        := 9+i;
   m_sbyFrom      := FROM_L1;
   m_sbyFor       := FOR_L1TOL2;
   m_sbyIntType   := 0;
   m_sbyServerID  := 0;
   m_sbyDirection := 0;
   m_sbySensor    := 0;
   m_sbyType      := PH_DATA_IND;

   byCRC := m_sbyInfo[w_swLen-9-2];
   //SendDebug('(__)COM::>CRC::>'+IntToHex(byCRC,2));

   blCRC := False;
   if (m_sbyInfo[0]=MSG_LONG_CODE)then
   Begin
    byLen := m_sbyInfo[1];
    if (byCRC=CalckKS(@m_sbyInfo[4],byLen)) then blCRC := True
   End;
   if (m_sbyInfo[0]=MSG_SHRT_CODE) then
   if (byCRC=CalckKS(@m_sbyInfo[1],2)) then blCRC := True;

   if blCRC then
   FPUT(BOX_L2,@m_sMsg) else
   SendDebug('(__)COM::>CRC Error!');
   //if assigned(FOnReceive) then FOnReceive(m_sbyInfo,i);
   End;
End;
function TComPort.CalckKS(Buffer: PByteArray;wLen: Integer): Byte;
var
  i: Integer;
begin
  Result := 0;
  //SendDebug('CRC:>');
  for i:= 0 to wLen-1 do
  Begin
  Result := Result + Buffer^[i];
  //SendDebug(' '+IntToHex(Buffer^[i],2));
  End;
  //SendDebug('CC'+IntToHex(Result,2));
end;
procedure TReadThread.Execute;
Begin
   hRxEvent:=CreateEvent(nil, False, False, nil);
   while not Terminated do
   Begin
   WaitForSingleObject(hRxEvent,INFINITE);
   if FComPort.m_byMType=0 then Synchronize(FComPort.MakeMessage);
   if (FComPort.m_byMType=1) or (FComPort.m_byMType=2)  then Synchronize(FComPort.MakeTextMessage);
   End;
End;
procedure TComPort.CallRxFlag;
begin
 if Assigned(FOnRxFlag) then FOnRxFlag(Self);
end;
procedure TComPort.CallTxEmpty;
begin
  //if Assigned(FOnTxEmpty) then FOnTxEmpty(Self);
  //FBlTxEmpty := True;
  //SendDebug('SendMessage! TxEmpty.');
  //Sleep(5);
  SendMesage;
end;
procedure TComPort.Close;
begin
  if not FActive then Exit;
  try
    SetCommMask(Fhandle, 0);
    ResetBuffer;
    FEventThread.Terminate;
    FReadThread.Terminate;
    if not CloseHandle(FHandle) then DoOnError(Error);
    FHandle := INVALID_HANDLE_VALUE;
    FActive := False;
    if Assigned(FOnClose) then FOnClose(Self);
  except
  end;
end;
procedure TComPort.DoEvents;
begin
  if (EV_ERR and FMask) <> 0 then DoOnError(LineStatusErr);
  if (EV_RXCHAR and FMask) <> 0 then CallRxChar;
  if (EV_TXEMPTY and FMask) <> 0 then CallTxEmpty;
  if (EV_BREAK and FMask) <> 0 then CallBreak;
  if ((EV_CTS and FMask) <> 0) or ((EV_DSR and FMask) <> 0) or ((EV_RLSD and FMask) <> 0) or ((EV_RING and FMask) <> 0) then CallModemStatusChange;
  if (EV_RXFLAG and FMask) <> 0 then CallRxFlag;
  if (EV_RING and FMask) <> 0 then CallRing;
end;
procedure TComPort.DoOnByteReceived(Data: Byte);
begin
  if FBufferFull then Exit;
  FBufferUsed := True;
  FInBuffer[FNextPosToWrite] := Data;
  Inc(FNextPosToWrite);
  if FNextPosToWrite>=InBufferSize then FNextPosToWrite := 0;
  if FNextPosToWrite=FNextPosToRead then begin
    FBufferFull := True;
    DoOnError(BufferFull);
    end;
end;
procedure TComPort.DoOnError(Error: Byte);
begin
 if Assigned(FOnError) then FOnError(Self, Error);
end;
procedure TComPort.DoRTUPacket;
var
  FData: array of Byte;
begin
  SetLength(FData, BufferUsed);
  move(FInBuffer[FNextPosToRead], FData[0], BufferUsed);
  //if assigned(FOnRTUPacket) then FOnRTUPacket(FData, BufferUsed);
end;
function TComPort.GetBufferUsed: Word;
var
 psize: Integer;
begin
 psize := FNextPosToWrite - FNextPosToRead;
 if psize < 0
  then Result := InBufferSize + psize
  else Result := psize;
end;
function TComPort.GetByte: Byte;
begin
  Result:=0;
  if not FBufferUsed then begin
    DoOnError(BufferEmpty);
    Exit;
    end;

  Result := FInBuffer[FNextPosToRead];
  Inc(FNextPosToRead);
  if FNextPosToRead > InBufferSize then FNextPosToRead:=0;
  if (FNextPosToWrite=FNextPosToRead) then FBufferUsed:=False;
end;
function TComPort.GetBytes(var OutBuf: array of Byte; Count: Word): Word;
var
  i: Word;
begin
  if Count > BufferUsed
    then Result := BufferUsed
    else Result := Count;
  for i := 0 to Result - 1 do
    OutBuf[i] := GetByte;
end;
{
procedure TComPort.GetComPortSettings;
var
 ComConfig: TCommConfig;
 BufSize: Cardinal;
begin
  BufSize := SizeOf(TCommConfig);
  //ComConfig.dwProviderSubType := PST_RS232;
  GetCommConfig(Handle, ComConfig, BufSize);
  with comconfig.dcb do begin
   FBaudRate := br110;
   while ((BaudValues[FBaudRate] <> BaudRate) and (FBaudRate < br115200)) do inc(FBaudRate);
   FParity := TParity(Parity);
   FDatabits := TDatabits(ByteSize - 5);
   FStopbits := TStopbits(Stopbits);
  end;
end;
}

function TComPort.GetInBufferSize: Word;
begin
  Result := length(FInBuffer);
end;


function TComPort.GetRTUInterval: DWORD;
begin
  if FRTUInterval = INFINITE
    then Result := 0
    else Result := FRTUInterval;
end;
{
function TComPort.OpenPort: Boolean;
var
  SetErr: Boolean;
begin
 SetErr:=false;
 if Not Active then begin
    FHandle:=CreateFile(PChar('\\.\Com'+IntToStr(FPortNum)),GENERIC_READ or GENERIC_WRITE, FILE_SHARE_READ or FILE_SHARE_WRITE,nil,OPEN_EXISTING,FILE_FLAG_OVERLAPPED,0);
    SendDebug('Open COM:'+IntToStr(FPortNum));
 end;
 if Active then begin
  if Not SetPortDCB(FHandle) then begin
    //DoSetDCBError;
    SendDebug('Error DCB!');
    SetErr:=true;
  end;
  if Not SetPortTimeOuts(FHandle) then begin
     SendDebug('Error TMR!');
    //DoSetTimeOutsError;
    SetErr:=true;
  end;
  if SetErr then begin
    SendDebug('Close HAND!');
    CloseHandle(FHandle);
    FHandle:=INVALID_HANDLE_VALUE;
  end;
  //FCommUART.Handle := FHandle;

    FEventThread := TComThread.Create(True);
    FEventThread.FComPort := Self;
    FEventThread.FreeOnTerminate := True;
    SetCommMask(Fhandle, EVENT_MASK);
    FEventThread.Resume;

    FReadThread := TReadThread.Create(True);
    FReadThread.FComPort := Self;
    FReadThread.FreeOnTerminate := True;
    FReadThread.Resume;
    ResetBuffer;
    CallModemStatusChange;
 //end;
 //Result:=Active;
 Result:=True;
end;
}
function TComPort.OpenPort: Boolean;
var
  TimeOuts: CommTimeOuts;
begin
  Result:=True;
  CriticalSection:=TCriticalSection.Create;
  if FActive then Exit;
  try
    FHandle := CreateFile(PChar('\\.\Com' + IntToStr(PortNum)), GENERIC_READ or GENERIC_WRITE, 0 , nil, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);
    if (FHandle = INVALID_HANDLE_VALUE) then begin
    Result := False;
    Exit;
    end;
    FActive := True;
    {Set system timeouts to zero}
    if not GetPortTimeOuts(FHandle) then SendDebug('(__)ERR::>GetPortTimeOuts!');
    if not SetPortTimeOuts(FHandle) then SendDebug('(__)ERR::>SetPortTimeOuts!');
    if not SetPortDCB(FHandle) then SendDebug('(__)ERR::>SetPortDCB!');
    FEventThread := TComThread.Create(True);
    FEventThread.FComPort := Self;
    FEventThread.FreeOnTerminate := True;
    SetCommMask(Fhandle, EVENT_MASK);
    FEventThread.Resume;
    FReadThread := TReadThread.Create(True);
    FReadThread.FComPort := Self;
    FReadThread.FreeOnTerminate := True;
    FReadThread.Resume;
    {flush input buffer}
    ResetBuffer;
    //DTR := False;
    //Sleep(500);
    //DTR := True;

    CallModemStatusChange;
    if Assigned(FOnOpen) then FOnOpen(Self);
  except
  end;
end;
function TComPort.Peekbyte(No: Word): Byte;
begin
  Result := 0;
  if No + 1 > BufferUsed
    then DoOnError(OutOfRange)
    else Result := FInBuffer[(FNextPosToRead + No) mod InBufferSize];
end;
function TComPort.PortSettingsDialog(WinHandle: THandle): Boolean;
var
  ComConfig : TCommConfig;
  BufSize : cardinal;
begin
  Result := False;
  if not FActive then Exit;
  BufSize := SizeOf(TCommConfig);
  //ComConfig.dwProviderSubType := PST_RS232;
  GetCommConfig(FHandle, ComConfig, BufSize);
  if CommConfigDialog(PChar('COM' + IntToStr(PortNum)), WinHandle, ComConfig) then
    SetCommConfig(Handle, ComConfig, BufSize);
  //GetComPortSettings;
  Result := True;
end;
procedure TComPort.ResetBuffer;
begin
  FNextPosToWrite := 0;
  FNextPosToRead := 0;
  FBufferUsed := False;
  FBufferFull := False;
  PurgeComm(FHandle, PURGE_RXCLEAR or PURGE_TXCLEAR);
end;
function TComPort.SendMesage:Boolean;
var
  BytesTrans: DWORD;
  Ov : TOverlapped;
  wL : Word;
Begin
  if not FActive then Exit;
  wL :=FGET(BOX_L1,@SndBuffer[0]);
  if wL<>0 then
  Begin
  //Sleep(5);

  //SndBuffer[9+0] := 0;
  //SndBuffer[9+1] := 1;
  //SndBuffer[9+2] := 2;
  //SndBuffer[9+3] := 3;
  //SndBuffer[9+4] := 0;

  //wL := 9+5;
  //SendDebug('Send With Buffer.'+IntToStr(wL));

  FBlTxEmpty := False;
  FillChar(Ov, SizeOf(TOverlapped), 0);
  Ov.hEvent := FHandleEvents;
  Result := WriteFile(FHandle, SndBuffer[9], wL-9, BytesTrans, @Ov) or (GetLastError = ERROR_IO_PENDING);
  //Result := WriteFile(FHandle, FSndBuffer[0], 16, BytesTrans, @Ov) or (GetLastError = ERROR_IO_PENDING);
  WaitForSingleObject(Ov.hEvent, INFINITE);
  Result := Result and GetOverlappedResult(FHandle, Ov, BytesTrans, False);
  FillChar(Ov, SizeOf(TOverlapped), 0);
  End else FBlTxEmpty := True;
End;
function TComPort.SendArray(A: Pointer; Count: Word): Boolean;
begin
  FPUT(BOX_L1,A);
  if FBlTxEmpty then CallTxEmpty;
  Result := True;
end;
function TComPort.SendByte(B: Byte): Boolean;
begin
  //Result := SendArray(B, 1);
end;
function TComPort.SendStr(S: String): Boolean;
var
  StrArr: array of Byte;
begin
  SetLength(StrArr, length(S));
  Move(S[1], StrArr[0], length(S));
  Result := SendArray(StrArr, length(S));
end;
procedure TComPort.SetActive(const Value: Boolean);
begin
  if Value = FActive then Exit;
  if Value
    then OpenPort
    else Close;
end;
procedure TComPort.AssignTo(Dest: TPersistent);
begin
  if Dest is TComPort then with TComPort(Dest) do begin
    FBaudRate    := self.FBaudRate;
    FManualRate  := self.FManualRate;
    FDCBFlag     := self.FDCBFlag;
    FXonLim      := self.FXonLim;
    FXoffLim     := self.FXoffLim;
    FByteSize    := self.FByteSize;
    FParity      := self.FParity;
    FStopBits    := self.FStopBits;
    FXonChar     := self.FXonChar;
    FXoffChar    := self.FXoffChar;
    FErrorChar   := self.FErrorChar;
    FEofChar     := self.FEofChar;
    FEvtChar     := self.FEvtChar;

    FReadIntervalTimeout         := self.FReadIntervalTimeout;
    FReadTotalTimeoutMultiplier  := self.FReadTotalTimeoutMultiplier;
    FReadTotalTimeoutConstant    := self.FReadTotalTimeoutConstant;
    FWriteTotalTimeoutMultiplier := self.FWriteTotalTimeoutMultiplier;
    FWriteTotalTimeoutConstant   := self.FWriteTotalTimeoutConstant;
  end else inherited AssignTo(Dest);
end;
procedure TComPort.SetBaudRate(const Value: TStBaudRates);
begin
  if Value <> brManual then FManualRate := StBaudRate[Value];
  FBaudRate:=Value;
end;
procedure TComPort.SetManualRate(const Value: DWord);
var
  i: Byte;
begin
  FManualRate:=Value;
  FBaudRate:=brManual;
  try
    for i:=1 to 20 do begin
       if StBaudRate[TStBaudRates(i)] = Value then begin
          FBaudRate:=TStBaudRates(i);
          Break;
       end;
    end;
  except
  end;
end;
procedure TComPort.SetDCBFlags(const Value: TStDCBFlags);
begin
  if (flDTRControlHandshake in Value) and (flDTRControlEnable in Value) then begin
     if (flDTRControlEnable in FDCBFlag) then FDCBFlag := Value - [flDTRControlEnable]
     else FDCBFlag := Value - [flDTRControlHandshake];
  end else FDCBFlag := Value;
  if FParity <> pNone then begin
    if Not (flParity in Value) then FDCBFlag := FDCBFlag + [flParity];
  end;
end;
procedure TComPort.SetByteSize(const Value: TStByteSize);
begin
  FByteSize := Value;
  if Value = bs_5_Bits then begin
    if FStopBits = sbTwo then FStopBits := sbOneHalf;
  end else begin
    if FStopBits = sbOneHalf then FStopBits := sbOne;
  end;
end;
procedure TComPort.SetParity(const Value: TStParity);
begin
  FParity := Value;
  if Value <> pNone then begin
    if Not (flParity in FDCBFlag) then FDCBFlag := FDCBFlag + [flParity];
  end else if (flParity in FDCBFlag) then FDCBFlag := FDCBFlag - [flParity];;
end;
procedure TComPort.SetStopBits(const Value: TStStopBits);
begin
  FStopBits := Value;
  if Value = sbOneHalf then FByteSize := bs_5_Bits;
  if Value = sbTwo then if FByteSize = bs_5_Bits then FByteSize := bs_8_Bits;
end;
function TComPort.ImportDCB : TDCB;
begin
  BuildCommDCB('', Result);
  Result.BaudRate  := FManualRate;
  Result.Flags     := Word(FDCBFlag);
  Result.XonLim    := FXonLim;
  Result.XoffLim   := FXoffLim;
  Result.ByteSize  := StByteSize[FByteSize];
  Result.Parity    := StParity[FParity];
  Result.StopBits  := StStopBits[FStopBits];
  Result.XonChar   := FXonChar;
  Result.XoffChar  := FXoffChar;
  Result.ErrorChar := FErrorChar;
  Result.EofChar   := FEofChar;
  Result.EvtChar   := FEvtChar;
end;
procedure TComPort.ExportDCB(const PortDCB: TDCB);
begin
  ManualRate := PortDCB.BaudRate;
  DCBFlag    := TStDCBFlags(Word(PortDCB.Flags));
  XonLim     := PortDCB.XonLim;
  XoffLim    := PortDCB.XoffLim;
  FByteSize  := TStByteSize(PortDCB.ByteSize-5);
  FParity    := TStParity(PortDCB.Parity);
  FStopBits  := TStStopBits(PortDCB.StopBits);
  XonChar    := PortDCB.XonChar;
  XoffChar   := PortDCB.XoffChar;
  ErrorChar  := PortDCB.ErrorChar;
  EofChar    := PortDCB.EofChar;
  EvtChar    := PortDCB.EvtChar;
end;
function TComPort.GetPortDCB(PortHandle: THandle): Boolean;
var
  CurDCB: TDCB;
begin
  if PortHandle <> INVALID_HANDLE_VALUE then begin
    Result := GetCommState(PortHandle, CurDCB);
    if Result then ExportDCB(CurDCB);
  end else Result := false;
end;
function TComPort.SetPortDCB(PortHandle: THandle): Boolean;
var
  CurDCB: TDCB;
begin
  if PortHandle <> INVALID_HANDLE_VALUE then begin
    CurDCB := ImportDCB;
    Result := SetCommState(PortHandle, CurDCB);
    if Not Result then GetPortDCB(PortHandle);
  end else Result := false;
end;


function TComPort.ImportCommTimeOuts : TCommTimeOuts;
begin
  Result.ReadIntervalTimeout         := FReadIntervalTimeout;
  Result.ReadTotalTimeoutMultiplier  := FReadTotalTimeoutMultiplier;
  Result.ReadTotalTimeoutConstant    := FReadTotalTimeoutConstant;
  Result.WriteTotalTimeoutMultiplier := FWriteTotalTimeoutMultiplier;
  Result.WriteTotalTimeoutConstant   := FWriteTotalTimeoutConstant;
end;

procedure TComPort.ExportCommTimeOuts(const PortTimeOuts: TCommTimeOuts);
begin
  FReadIntervalTimeout         := PortTimeOuts.ReadIntervalTimeout;
  FReadTotalTimeoutMultiplier  := PortTimeOuts.ReadTotalTimeoutMultiplier;
  FReadTotalTimeoutConstant    := PortTimeOuts.ReadTotalTimeoutConstant;
  FWriteTotalTimeoutMultiplier := PortTimeOuts.WriteTotalTimeoutMultiplier;
  FWriteTotalTimeoutConstant   := PortTimeOuts.WriteTotalTimeoutConstant;
end;

function TComPort.GetPortTimeOuts(PortHandle: THandle): Boolean;
var
  CurTimeOuts: TCommTimeOuts;
begin
  if PortHandle <> INVALID_HANDLE_VALUE then begin
    Result := GetCommTimeOuts(PortHandle, CurTimeOuts);
    if Result then ExportCommTimeOuts(CurTimeOuts);
  end else Result := false;
end;

function TComPort.SetPortTimeOuts(PortHandle: THandle): Boolean;
var
  CurTimeOuts: TCommTimeOuts;
begin
  if PortHandle <> INVALID_HANDLE_VALUE then begin
    CurTimeOuts := ImportCommTimeOuts;
    Result := SetCommTimeOuts(PortHandle, CurTimeOuts);
    if Not Result then GetPortTimeOuts(PortHandle);
  end else Result := false;
end;

procedure TComPort.SetFDTR(const Value: Boolean);
begin
  EscapeCommFunction(Handle,SETDTR*ord(Value)+CLRDTR*ord(not Value));
  FDTR := Value;
end;
procedure TComPort.SetFRTS(const Value: Boolean);
begin
  EscapeCommFunction(Handle,SETRTS*ord(Value)+CLRRTS*ord(not Value));
  FRTS := Value;
end;
procedure TComPort.SetInBufferSize(Value: Word);
begin
  if GetInBufferSize = Value then Exit;
  SetLength(FInBuffer, Value);
  ResetBuffer;
end;
procedure TComPort.SetPort(Value: Byte);
var
  temp: Boolean;
begin
  if FPortNum = Value then Exit;
  temp := FActive;
  if temp then Close;
  FPortNum := Value;
  if temp then OpenPort;
end;
procedure TComPort.SetRTUInterval(const Value: DWORD);
begin
  if Value = 0
    then FRTUInterval := INFINITE
    else FRTUInterval := Value;
end;
{ TComThread }

procedure TComThread.Execute;
var
  Overlapped: TOverlapped;
  BytesTrans: DWORD;

  RxCharTicks: DWORD;
  RTU_TO: DWord;
begin
  FillChar(Overlapped, SizeOf(Overlapped), 0);
  Overlapped.hEvent := CreateEvent(nil, True, True, nil);
  RTU_TO := INFINITE;
  RxCharTicks := 0;

  while not Terminated do begin
    WaitCommEvent(FComPort.Handle, FComPort.FMask, @Overlapped);
    case WaitForSingleObject(Overlapped.hEvent, RTU_TO) of
      WAIT_OBJECT_0: begin
        if GetOverlappedResult(FComPort.Handle, Overlapped, BytesTrans, False) then Synchronize(FComPort.DoEvents);

        { RTU mode }
        if FComPort.FRTUInterval <> INFINITE then begin
          if (EV_RXCHAR and FComPort.FMask) <> 0 then begin
            RxCharTicks := GetTickCount;
            RTU_TO := FComPort.FRTUInterval;
            end else
          if (RTU_TO <> INFINITE) and (GetTickCount - RxCharTicks > FComPort.FRTUInterval) then begin
            RTU_TO := INFINITE;
            Synchronize(FComPort.DoRTUPacket);
            end;
          end;

        end;
      WAIT_TIMEOUT: begin
        RTU_TO := INFINITE;
        Synchronize(FComPort.DoRTUPacket);
        end;
      end;
    end;
  CloseHandle(Overlapped.hEvent);
end;


end.  *
