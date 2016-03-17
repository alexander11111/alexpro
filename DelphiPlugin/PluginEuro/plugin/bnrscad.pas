unit bnrscad;
interface
uses
  Windows, Messages, SysUtils,Classes,Dialogs,
  DbugIntF, UExporter, UClassManager, KanList;
type
    CScadaDrv = class
    private
     m_nAdapter : TAdapter;
     m_nChannel : TKanal;
     m_byDirCodeID : Integer;
     FPeriod : Integer;
    public
     constructor Create;
     destructor Destroy; override;
     procedure Init(var nAdapter:TAdapter);
     procedure SetAlrHiLevel(addr : integer);
     procedure SetAlrLoLevel(addr : integer);
     procedure AddParamFL(var vChannel : TKanal;dt : TDateTime; addr : integer; val : Single; st : integer);
     procedure AddParamInt(var vChannel : TKanal;dt : TDateTime; addr : integer; val : Integer; st : integer);
     function PreChannelInit(byDir:Byte):boolean;
     procedure SendToScadaTS(byChannel:Integer;nParam:Integer);
     procedure SendToScadaFL(byChannel:Integer;fParam:Single);
     procedure SendToScadaInt(byChannel:Integer;nParam:Integer);
     procedure SendTU(byChannel:Integer;wParam:SmallInt);
     procedure SendTR(byChannel:Integer;fData:Single);
     procedure SendDParam(byFor : Byte;byBlock : Byte;byTParam : Byte;bySensor : Byte;Len : Byte;pwValue : Pointer);
    public
     property PPeriod : Integer read FPeriod write FPeriod;
    End;
implementation
constructor CScadaDrv.Create;
begin
     FPeriod := 200;
end;
destructor CScadaDrv.Destroy;
begin
    inherited;
end;
procedure CScadaDrv.Init(var nAdapter:TAdapter);
Begin
    m_nAdapter := nAdapter;
    m_byDirCodeID := 0;
End;
procedure CScadaDrv.SetAlrHiLevel(addr : integer);
Var
    TCPData : TTCPData;
begin
    if PreChannelInit(m_byDirCodeID) then begin
    TCPData.Napr    := m_nChannel.Cpps_kan * 1000 + addr;
    TCPData.DataLen := 0;
    TCPData.Param   := msgInfo1;
    TCPData.UserID  := 0;
    TCPData.TimeChange := Now;
    TCPData.FIntValue  := 21;
    TCPData.KS         := 0;
    //SendDebug('('+IntToStr(m_bySystemID)+')'+'EV_ADMIN_SET_ALM_HILEV_REQ');
    TKanal(m_nAdapter[0]).OnMessage(TCPData);
    end;
end;
procedure CScadaDrv.SetAlrLoLevel(addr : integer);
Var
    TCPData : TTCPData;
begin
    if PreChannelInit(m_byDirCodeID) then begin
    TCPData.Napr    := m_nChannel.Cpps_kan * 1000 + addr;
    TCPData.DataLen := 0;
    TCPData.Param   := msgInfo1;
    TCPData.UserID  := 0;
    TCPData.TimeChange := Now;
    TCPData.FIntValue  := 20;
    TCPData.KS         := 0;
    //SendDebug('('+IntToStr(m_bySystemID)+')'+'EV_ADMIN_SET_ALM_LOLEV_REQ');
    TKanal(m_nAdapter[0]).OnMessage(TCPData);
    end;
end;
procedure CScadaDrv.AddParamFL(var vChannel : TKanal;dt : TDateTime; addr : integer; val : Single; st : integer);
var
    buf : TTCPData;
begin
    buf.UserID     := 0;
    buf.KS         := 0;
    buf.DataLen    := 0;
    buf.Reserv1    := 0;
    buf.Reserv2    := st;
    buf.TimeChange := dt;
    //SendDebug('CScadaDrv.AddParamFL:DIR:'+IntToStr(vChannel.Cpps_kan)+' ADDR: '+IntToStr(addr)+' VAL: '+FloatToStr(val));
    if Assigned(vChannel) then try
    if addr > 0 then
    begin
     buf.Param    := msgTICode;
     buf.FFlValue := val;
    end;
     //buf.Napr := vChannel.Cpps_kan * 1000 + addr;
     buf.Napr := m_byDirCodeID * 1000 + addr;
     m_nAdapter.NewUTMData(buf);
  except
   on E : exception do
   MessageDlg('PlTCP AddData' + #13#10 + E.Message, mtWarning, [mbOK], 0);
  end;
end;
procedure CScadaDrv.AddParamInt(var vChannel : TKanal;dt : TDateTime; addr : integer; val : Integer; st : integer);
var
    buf : TTCPData;
begin
    buf.UserID     := 0;
    buf.KS         := 0;
    buf.DataLen    := 0;
    buf.Reserv1    := 0;
    buf.Reserv2    := st;
    buf.TimeChange := dt;
    if Assigned(vChannel) then try
    if addr < 0 then
    begin
     buf.Param := msgTSCode;
     addr := -addr - 1;
     buf.FIntValue := val;
    end else
    begin
     buf.Param     := msgTICode;
     buf.FFlValue := val;
    end;
     buf.Napr := vChannel.Cpps_kan * 1000 + addr;
     m_nAdapter.NewUTMData(buf);
  except
   //on E : exception do
   //MessageDlg('PlTCP AddData' + #13#10 + E.Message, mtWarning, [mbOK], 0);
  end;
end;
function CScadaDrv.PreChannelInit(byDir:Byte):boolean;
Var
    I : Integer;
begin
    if m_nAdapter <> Nil then
    begin
     //if m_nAdapter[0]=Nil then
     //Begin
     // SendDebug('m_nAdapter[byDir]=Nil'+IntToStr(byDir));
     // exit;
     //End;
     //SendDebug(' WaitKA:'+IntToStr(FPeriod)+' Napr:'+IntToStr(byDir));
     m_nAdapter.WaitKA    := FPeriod;
     m_nAdapter.State     := 1;
     m_nAdapter.Timer     := 0;
     //m_nChannel           := m_nAdapter[m_byDirCodeID];

//     m_nChannel           := m_nAdapter[0];
     //SendDebug('CIN:'+IntToStr(m_nChannel.ReadCount));


     For I := 1 To m_nAdapter.Count Do
     Begin
      m_nChannel := m_nAdapter[I - 1];
      //m_nChannel.Empty     := true;
      //m_nChannel.Ready     := True;
      //m_nChannel.Repeats   := 0;
      //m_nChannel.TSLoaded  := 3;
      //m_nChannel.ReadCount := m_nChannel.ReadCount + 1;
      m_nChannel.State     := 1;
      m_nChannel.OutTimer  := 0;
      m_nChannel.Timer     := 0;
      m_nChannel.Empty     := true;
      m_nChannel.Repeats   := 0;
      m_nChannel.Retry     := false;
      m_nChannel.Ready     := true;
      m_nChannel.Wait      := 0;
      m_nChannel.ReadCount := m_nChannel.ReadCount + 1;
      m_nChannel.TSLoaded  := m_nChannel.MaxRepeats;
     End;

     result := True;
    end else
    Begin
     //SendDebug('m_nAdapter=Nil');
     result := False;
    End;
end;
procedure CScadaDrv.SendDParam(byFor : Byte;byBlock : Byte;byTParam : Byte;bySensor : Byte;Len : Byte;pwValue : Pointer);
Var
    byBuff : array[0..20] of Byte;
begin
    byBuff[1] := byBlock;
    byBuff[2] := byTParam;
    byBuff[3] := Len;
    byBuff[0] := 4 + byBuff[3];
    Move(pwValue^,byBuff[4],byBuff[3]);
    //m_nDle^.SendByCmd(byFor,EV_SMSNS_SET_PARAM_REQ,m_byDirectionID,bySensor,byBuff);
end;
procedure CScadaDrv.SendToScadaTS(byChannel:Integer;nParam:Integer);
Var
    nChannel : Integer;
Begin
    m_byDirCodeID := byChannel div 1000;
    nChannel      := byChannel mod 1000;
    if PreChannelInit(m_byDirCodeID) then AddParamInt(m_nChannel, Now, nChannel, nParam, $C0);
End;
procedure CScadaDrv.SendToScadaFL(byChannel:Integer;fParam:Single);
Var
    nChannel : Integer;
Begin
    m_byDirCodeID := byChannel div 1000;
    nChannel      := byChannel mod 1000;
    //SendDebug('CScadaDrv.SendToScadaFL:DIR: '+IntToStr(m_byDirCodeID)+' CHN: '+IntToStr(nChannel)+' VAL: '+FloatToStr(fParam));
    if PreChannelInit(m_byDirCodeID) then AddParamFl(m_nChannel, Now, nChannel, fParam, $C0);
End;
procedure CScadaDrv.SendToScadaInt(byChannel:Integer;nParam:Integer);
Var
    nChannel : Integer;
Begin
    m_byDirCodeID := byChannel div 1000;
    nChannel      := byChannel mod 1000;
    if PreChannelInit(m_byDirCodeID) then AddParamInt(m_nChannel, Now, nChannel, nParam, $C0);
End;

procedure CScadaDrv.SendTR(byChannel:Integer;fData:Single);
Begin

End;
procedure CScadaDrv.SendTU(byChannel:Integer;wParam:SmallInt);
Begin

End;
end.
