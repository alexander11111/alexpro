{$DEFINE GDEBUG}
{$DEFINE M_DEBUG}

unit plfrmascue;


interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
   syncobjs, GenaUtl,
{$IFDEF GDEBUG}DbugIntF, {$ENDIF}
  UExporter, UClassManager, KanList, 
  //TeEngine, Series, TeeProcs, Chart, DsLed;
  AdvGlowButton, AdvToolBar, AdvPanel, ExtCtrls, AdvOfficeStatusBar,
  AdvOfficeStatusBarStylers, AdvAppStyler, AdvToolBarStylers, Menus,
  AdvMenus, AdvMenuStylers, AdvOfficePager, AdvOfficePagerStylers, Grids,
  utltype,BaseGrid, AdvGrid, ComCtrls, AdvSplitter, StdCtrls,plascues,
  ImgList,plchanned,plchannbase,bnrscad,knsl2timer;

type
TTFrmAscue = class(TForm)
    AdvToolBarOfficeStyler1: TAdvToolBarOfficeStyler;
    AdvFormStyler1: TAdvFormStyler;
    AdvOfficeStatusBar1: TAdvOfficeStatusBar;
    AdvOfficeStatusBarOfficeStyler1: TAdvOfficeStatusBarOfficeStyler;
    AdvPanel1: TAdvPanel;
    AdvPanelStyler1: TAdvPanelStyler;
    AdvToolBar2: TAdvToolBar;
    AdvGlowMenuButton2: TAdvGlowMenuButton;
    AdvGlowMenuButton3: TAdvGlowMenuButton;
    AdvPopupMenuSys: TAdvPopupMenu;
    AdvPopupMenuCount: TAdvPopupMenu;
    AdvPopupMenuChan: TAdvPopupMenu;
    AdvPopupMenuOpc: TAdvPopupMenu;
    N1: TMenuItem;
    AdvMenuOfficeStyler1: TAdvMenuOfficeStyler;
    AdvPanel2: TAdvPanel;
    pgPager: TAdvOfficePager;
    tcConnect: TAdvOfficePage;
    tcChannelED: TAdvOfficePage;
    AdvOfficePagerOfficeStyler1: TAdvOfficePagerOfficeStyler;
    AdvPanel3: TAdvPanel;
    AdvSplitter1: TAdvSplitter;
    AdvPanel4: TAdvPanel;
    sgChannel: TAdvStringGrid;
    tvObjects: TTreeView;
    AdvPanel5: TAdvPanel;
    AdvToolBar1: TAdvToolBar;
    AdvGlowMenuButton6: TAdvGlowMenuButton;
    btRefreshTree: TAdvGlowMenuButton;
    AdvPopupMenuOper: TAdvPopupMenu;
    AdvPopupMenuSort: TAdvPopupMenu;
    sgConnectDB: TAdvStringGrid;
    imgEditPannel: TImageList;
    AdvPanel: TAdvPanel;
    Label36: TLabel;
    AdvToolBar: TAdvToolBar;
    AdvToolBarButton121: TAdvToolBarButton;
    AdvToolBarButton131: TAdvToolBarButton;
    AdvToolBarButton141: TAdvToolBarButton;
    AdvToolBarButton151: TAdvToolBarButton;
    AdvToolBarButton161: TAdvToolBarButton;
    AdvToolBarButton171: TAdvToolBarButton;
    AdvToolBarButton251: TAdvToolBarButton;
    cnlAdvButt: TAdvToolBarButton;
    AdvToolBarSeparator17: TAdvToolBarSeparator;
    AdvToolBarButton125: TAdvToolBarButton;
    AdvToolBarButton13: TAdvToolBarButton;
    AdvToolBarSeparator34: TAdvToolBarSeparator;
    btTehnoCN: TAdvToolBarButton;
    AdvPanel6: TAdvPanel;
    Label1: TLabel;
    AdvToolBar3: TAdvToolBar;
    btSaveChann: TAdvToolBarButton;
    AdvToolBarButton2: TAdvToolBarButton;
    btExec: TAdvToolBarButton;
    AdvToolBarSeparator1: TAdvToolBarSeparator;
    AdvToolBarButton9: TAdvToolBarButton;
    AdvToolBarSeparator2: TAdvToolBarSeparator;
    AdvToolBarSeparator3: TAdvToolBarSeparator;
    btChannelEd: TAdvToolBarButton;
    ImageListTree: TImageList;
    btOnClearChann: TAdvToolBarButton;
    btChannEd: TAdvToolBarButton;
    procedure OnCreateFrm(Sender: TObject);
    procedure OnDBCGetCellType(Sender: TObject; ACol, ARow: Integer;
      var AEditor: TEditorType);
    procedure cnlAdvButtClick(Sender: TObject);
    procedure AdvToolBarButton121Click(Sender: TObject);
    procedure AdvToolBarButton131Click(Sender: TObject);
    procedure AdvToolBarButton141Click(Sender: TObject);
    procedure AdvToolBarButton151Click(Sender: TObject);
    procedure AdvToolBarButton161Click(Sender: TObject);
    procedure OnClickGridConn(Sender: TObject; ARow, ACol: Integer);
    procedure AdvToolBarButton171Click(Sender: TObject);
    procedure sgConnectDBResize(Sender: TObject);
    procedure AdvToolBarButton251Click(Sender: TObject);
    procedure OnClickTree(Sender: TObject);
    procedure OnExpandTree(Sender: TObject; Node: TTreeNode);
    procedure OnCollapsedTree(Sender: TObject; Node: TTreeNode);
    procedure OnGridEdRZ(Sender: TObject);
    procedure OnChandgePG(Sender: TObject);
    procedure btChannEdClick(Sender: TObject);
    procedure btSaveChannClick(Sender: TObject);
    procedure btExecClick(Sender: TObject);
    procedure btOnClearChannClick(Sender: TObject);
    procedure sgChannelClickCell(Sender: TObject; ARow, ACol: Integer);
    procedure OnConnTblClick(Sender: TObject);
    procedure OnChannTblClick(Sender: TObject);
    procedure OnExitClick(Sender: TObject);
    procedure v_ReportListCheckBoxClick(Sender: TObject; ACol,
      ARow: Integer; State: Boolean);
    procedure btChannelEdClick(Sender: TObject);
    procedure sgConnectDBClickCell(Sender: TObject; ARow, ACol: Integer);
    procedure btRefreshTreeClick(Sender: TObject);
    procedure btTehnoCNClick(Sender: TObject);
  private
     m_nAscue : CAscues;
     m_pTmr : CTimerThread;
     m_blDBConnection : boolean;
     m_blChannEd : boolean;
     m_nChannEdit : CChannEdit;
     m_nCHB : CChannBase;
     mTI : CTreeIndex;
     mScada : CScadaDrv;
     OutArray : TData;
     CurAdapter : TAdapter;
     APort : string;

  public
     procedure Query(Sender : TObject; ARetry : Boolean);
     procedure MyOnTimeOut(Sender : TObject; ARetry : Boolean);
     procedure GetValues1(Sender : TObject; OutData : TTCPData; OutArray : array of Integer);
     procedure Display(Value : string; Enable : boolean);
  private
     procedure loadSystem;
     procedure SetEditGrid(var blState:Boolean;var btButt:TAdvToolBarButton;var sgGrid:TAdvStringGrid;blIsRow:Boolean);
    { Private declarations }
  public
    { Public declarations }
  end;

  TTAscueAdapter = class(TExporter)
  public
    frmAscue : TTFrmAscue;
    FormMenuItem0 : TMenuItem;
    FormMenuItem1 : TMenuItem;
    constructor Create;
    destructor Destroy; override;
    class function Name : string; override;
    class function PlType : TPlType; override;
    function RunPlugin(Sender : TObject) : TObject; override;
    function StopPlugin : boolean; override;
    procedure MenuClick(Sender : TObject);
  end;
  TProcess = record
    N : Integer;
    Tmr : Integer;
    Data : array[0..100] of Byte;
  end;

implementation
{$R *.DFM}
//var
//  eee, MsgCnt       : Word;
constructor TTAscueAdapter.Create;
begin
  inherited;
  SendDebug('TTAscueAdapter::>Create');
  frmAscue := nil;
end;
destructor TTAscueAdapter.Destroy;
begin
  inherited;
end;
class function TTAscueAdapter.Name : string;
begin
  Result := '������� �����';
end;
class function TTAscueAdapter.PlType : TPlType;
begin // type
  result := plMenu;
end;
procedure TTAscueAdapter.MenuClick(Sender : TObject);
begin
  if frmAscue <> nil then frmAscue.show;
end;
function TTAscueAdapter.RunPlugin(Sender : TObject) : TObject;
var
  J, N              : integer;
  s, s1             : string;
begin
  Result := nil;
  SendDebug('TTAscueAdapter::>RunPlugin');
  if frmAscue = nil then try
    if Sender is TmainMenu then begin
      frmAscue := TTFrmAscue.Create(Application);
      FormMenuItem1 := TmenuItem.Create(Sender as TmainMenu);
      FormmenuItem1.Caption := Name;
      FormmenuItem1.OnClick := MenuClick;
      FormmenuItem1.Name := 'mnASCUE';
      FormmenuItem0 := Nil;
      for J := 1 to (Sender as TmainMenu).Items.Count do begin
        S := (Sender as TmainMenu).Items[J - 1].Caption;
        if S = '&A�������' then begin
          FormmenuItem0 := (Sender as TmainMenu).Items[J - 1];
          break;
        end;
      end;
      if not Assigned(FormMenuItem0) then begin
        FormMenuItem0 := TmenuItem.Create(Sender as TmainMenu);
        FormmenuItem0.Caption := '&A�������';
        FormmenuItem0.Add(formMenuItem1);
        (Sender as TmainMenu).Items.Add(formMenuItem0)
      end;
      FormMenuItem0.Add(formMenuItem1);
      S := uppercase(PluginParams);
      N := Pos('PORT', S);
      if N > 0 then begin
        delete(S, 1, N + 4);
        S1 := extractWord(1, S, [' ', ';', '=']);
        frmAscue.APort := S1;
      end;
      S := uppercase(PluginParams);
      N := Pos('NODE', S);
      if N > 0 then begin
        delete(S, 1, N + 4);
        N := 1;
        repeat
          S1 := extractWord(N, S, [' ', ';', ',', '=']);
          if not IsInteger(S1) then break else begin
            J := StrToIntdef(S1, 0);
            SendDebug('Adapter='+IntTostr(J));
            Adapters.AddAdapter(J);
            frmAscue.CurAdapter := Adapters.AdapterByNode(J);
            frmAscue.CurAdapter.Name := '�� ASCUE � ' + IntToStr(J);
            frmAscue.CurAdapter.Timer := 0;
            frmAscue.CurAdapter.TimeOut := 300;
            //MessageDlg('AdapterInit', mtWarning, [mbOK], 0);
            //frmAscue.AdList.Add(Pointer(J));
            // SendDebug('FormCreate');
            frmAscue.loadSystem;
            frmAscue.Display(frmAscue.CurAdapter.Name, true);
          end;
          Inc(N);
        until True;
      end;
      Result := frmAscue;
    end else
      MessageDlg('not menu', mtWarning, [mbOK], 0);
  except
    on E : exception do
      MessageDlg('ASCUE adapter error' + #13#10 + E.Message, mtWarning, [mbOK], 0);
  end;
end;
function TTAscueAdapter.StopPlugin;
begin
  Result := false;
  Exit;
  if frmAscue <> nil then begin
    frmAscue.close;
    frmAscue.Free;
    frmAscue := nil;
  end;
end;




procedure TTFrmAscue.OnCreateFrm(Sender: TObject);
begin
     //loadSystem;
     SendDebug('TTFrmAscue::>OnCreateFrm');
end;
procedure TTFrmAscue.loadSystem;
Begin
     m_blDBConnection     := false;
     m_blChannEd := false;

     mScada := CScadaDrv.Create;
     mScada.Init(CurAdapter);

     m_nCHB := CChannBase.create;

     m_nChannEdit         := CChannEdit.create;
     m_nChannEdit.PTView  := tvObjects;
     m_nChannEdit.PsgGrid := sgChannel;
     m_nChannEdit.PCT     := m_nCHB;

     m_nAscue         := CAscues.Create;
     m_nAscue.PScada  := mScada;
     m_nAscue.PsgGrid := sgConnectDB;
     m_nAscue.PCE     := m_nChannEdit;
     m_nAscue.PCT     := m_nCHB;
     m_nAscue.init;
     
     m_pTmr := CTimerThread.Create(True);
     m_pTmr.Priority := tpNormal;
     m_pTmr.pA := m_nAscue;
     m_pTmr.Resume;
end;

procedure TTFrmAscue.OnDBCGetCellType(Sender: TObject; ACol, ARow: Integer;
  var AEditor: TEditorType);
begin
    m_nAscue.OnGetCellType(Sender,ACol, ARow,AEditor);
end;
procedure TTFrmAscue.SetEditGrid(var blState:Boolean;var btButt:TAdvToolBarButton;var sgGrid:TAdvStringGrid;blIsRow:Boolean);
begin
    if blState=true then //Open
    Begin
     //btButt.ImageIndex := 14;
     btButt.Hint       := '��������������';
     //blState           := True;
     sgGrid.Options    := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goRangeSelect,goDrawFocusSelected,goColSizing,goEditing];
    End else
    if blState=false then //Close
    Begin
     //btButt.ImageIndex := 15;
     btButt.Hint       := '�����������';
     //blState           := False;
     if blIsRow=True  then sgGrid.Options := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goRangeSelect,goDrawFocusSelected,goColSizing,goRowSelect{goEditing}] else
     if blIsRow=False then sgGrid.Options    := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goDrawFocusSelected,goColSizing];
    End;
end;

procedure TTFrmAscue.cnlAdvButtClick(Sender: TObject);
begin
    m_blDBConnection := cnlAdvButt.Down;
    SetEditGrid(m_blDBConnection,cnlAdvButt,sgConnectDB,True)
end;

procedure TTFrmAscue.AdvToolBarButton121Click(Sender: TObject);
begin
    m_nAscue.OnSaveGrid;
    m_nAscue.init;
end;

procedure TTFrmAscue.AdvToolBarButton131Click(Sender: TObject);
begin
    m_nAscue.OnLoadGrid;
end;

procedure TTFrmAscue.AdvToolBarButton141Click(Sender: TObject);
begin
    if m_blDBConnection=True then
    m_nAscue.OnAddRow;
end;

procedure TTFrmAscue.AdvToolBarButton151Click(Sender: TObject);
begin
    if m_blDBConnection=True then
    m_nAscue.OnCloneRow;
end;

procedure TTFrmAscue.AdvToolBarButton161Click(Sender: TObject);
begin
    if m_blDBConnection=True then
    m_nAscue.OnDelRow;
end;

procedure TTFrmAscue.OnClickGridConn(Sender: TObject; ARow, ACol: Integer);
begin
    m_nAscue.OnClickGrid(Sender,ARow,ACol);
end;

procedure TTFrmAscue.AdvToolBarButton171Click(Sender: TObject);
begin
    if m_blDBConnection=True then
    m_nAscue.OnDelAllRow;
end;

procedure TTFrmAscue.sgConnectDBResize(Sender: TObject);
begin
    m_nAscue.OnFormResize;
end;

procedure TTFrmAscue.AdvToolBarButton251Click(Sender: TObject);
begin
    m_nAscue.OnEditChannels;
end;

procedure TTFrmAscue.OnClickTree(Sender: TObject);
begin
   mTI := m_nChannEdit.OnClickTree;
end;

procedure TTFrmAscue.OnExpandTree(Sender: TObject; Node: TTreeNode);
begin
    m_nChannEdit.OnExpandTree(Node);
end;

procedure TTFrmAscue.OnCollapsedTree(Sender: TObject; Node: TTreeNode);
begin
    m_nChannEdit.OnCollapsedTree(Node);
end;

procedure TTFrmAscue.OnGridEdRZ(Sender: TObject);
begin
    m_nChannEdit.OnFormResize;
end;

procedure TTFrmAscue.OnChandgePG(Sender: TObject);
begin
    //if pgPager.ActivePage=tcConnect then OnEditReq(Sender);
    if pgPager.ActivePage=tcChannelED then
    Begin
     m_nAscue.OnEditChannels;
     m_nChannEdit.OnPrepareEdit;
    End;
end;

procedure TTFrmAscue.btChannEdClick(Sender: TObject);
begin
    m_blChannEd := btChannEd.Down;
    SetEditGrid(m_blChannEd,btChannEd,sgChannel,True)
end;

procedure TTFrmAscue.btSaveChannClick(Sender: TObject);
begin
    if m_blChannEd=false then exit;
    m_nChannEdit.save;
    m_nAscue.init;
    m_nChannEdit.OnClickTree;
end;

procedure TTFrmAscue.btExecClick(Sender: TObject);
begin
    SendDebug('TTFrmAscue.btExecClick_Do');
    if m_blChannEd=false then exit;
    SendDebug('TTFrmAscue.btExecClick_Post');
    m_nAscue.OnExecSql(mTI);
    m_nChannEdit.OnClickTree;
end;

procedure TTFrmAscue.btOnClearChannClick(Sender: TObject);
begin
    if m_blChannEd=false then exit;
    m_nChannEdit.OnClearChann;
    m_nAscue.init;
    m_nChannEdit.OnClickTree;
end;

procedure TTFrmAscue.sgChannelClickCell(Sender: TObject; ARow,
  ACol: Integer);
begin
    m_nChannEdit.OnClickGrid(Sender,ARow,ACol);
end;

procedure TTFrmAscue.OnConnTblClick(Sender: TObject);
begin
    pgPager.ActivePageIndex := 0;
end;

procedure TTFrmAscue.OnChannTblClick(Sender: TObject);
begin
   pgPager.ActivePageIndex := 1;
end;

procedure TTFrmAscue.OnExitClick(Sender: TObject);
begin
   close;
end;

procedure TTFrmAscue.v_ReportListCheckBoxClick(Sender: TObject; ACol,
  ARow: Integer; State: Boolean);
begin
   m_nAscue.v_ReportListCheckBoxClick(Sender,ACol,ARow,State);
end;




















procedure TTFrmAscue.Display;
begin
  //if MsgCnt < 10000 then inc(MsgCnt) else MsgCnt := 0;
  //Label20.Caption := IntToStr(MsgCnt);
  //if Enable then Memo1.Lines.Add(Value);
  //while Memo1.lines.Count > 400 do Memo1.lines.delete(0);
end;
procedure TTFrmAscue.MyOnTimeOut(Sender : TObject; ARetry : Boolean);
begin
  //MessageDlg('TimeOut', mtWarning, [mbOK], 0);
end;
procedure TTFrmAscue.GetValues1(Sender : TObject; OutData : TTCPData; OutArray : array of Integer);
var
  S                 : string;
  I, Kanal, Vtype, Int1 : integer;
  Fl1               : Single absolute Int1;
//  AAdapter          : TAdapter;
begin
  //SendDebug('Message::>');
  if Sender is TAdapter then begin
    //AAdapter := TAdapter(Sender);
    // ����� �������� �� ������ �������� ������ ������,
    // ����� �� ���������� � ���� ������ �������
    exit;
  end;
  VType := OutData.Param;
  if OutData.DataLen = 0 then begin
    case OutData.Param of
      msgUTM : S := 'UTM ' + OutData.FStrValue;
      msgTSr : S := 'TSr ' + OutData.FStrValue;
      msgTIr : S := 'TIr ' + OutData.FStrValue;
     //msgShit = 3;
      msgTScode : S := 'TScode ' + IntToStr(OutData.FIntValue);
      msgTIcode : S := 'TICode ' + FloatToStr(OutData.FFlValue);
      msgTII : S := 'TII ' + FloatToStr(OutData.FFlValue);
      msgTU : begin
          S := 'TU ';
          for i := 0 to 7 do
            S := S + IntToHex(OutData.ByteArr[I], 2) + ' ';
        end;
      msgQuery : ;
      msgTSRetro : S := 'TSRetro ' + IntToStr(OutData.FIntValue);
      msgTSv : S := 'TSv ' + IntToStr(OutData.FIntValue);
      msgTIv : S := 'TIv ' + FloatToStr(OutData.FFlValue);
      msgPlakat : S := 'Plakat ' + OutData.FStrValue;
      msgPass : S := 'Pass ' + OutData.FStrValue + ' user ' + IntTostr(OutData.UserID);
      msgNone : S := 'None ' + OutData.FStrValue;
      msgLocal : S := 'Local ' + FloatToStr(OutData.FFlValue);
      msgTIreg : S := 'TI reg ' + FloatToStr(OutData.FFlValue);
      msgInfo : S := 'Info ' + FloatToStr(OutData.FIntValue);
    else S := '�� ��������� ������� : ' + IntToStr(OutData.Param);
    end;
    //Display(IntToStr(OutData.Napr) + ' ' + S, CMonitor.Checked and CIn.Checked);
  end else if VType = msgUTM then begin
    I := 0;
    while I < OutData.DataLen div 4 do begin
      Int1 := OutArray[I];
      Kanal := (Int1 and $FFFFF);
      VType := (Int1 shr 26) and $3F;
      Int1 := OutArray[I + 1];
      {
      if VType = msgTIcode then
        Display('SCADA TIcode ' + IntToStr(Kanal) + ' ' + FloatToStr(Fl1), CMonitor.Checked and CIn.Checked)
      else if VType = msgTScode then
        Display('SCADA TScode ' + IntToStr(Kanal) + ' ' + IntToStr(Int1), CMonitor.Checked and CIn.Checked)
      else
        Display('SCADA Message ' + IntToStr(VType), CMonitor.Checked and CIn.Checked);
      Inc(I, 2);
      }
    end;
  end;
end;
procedure TTFrmAscue.Query(Sender : TObject; ARetry : Boolean);
var
  AKanal      : TKanal;
  fValue      : Single;
  I,wParam    : Smallint;
  byChannel   : Byte;
  byDevID     : Byte;
  byNChannel  : Byte;
begin
  try
    if CurAdapter = nil then Exit;
    AKanal := CurAdapter.GetOutData(OutArray);
    if OutArray.Len > 266 then OutArray.Len := 0;
    if (OutArray.Len > 0) then
    try
    wParam     := 0;
    byNChannel := AKanal.Kanal;
    byDevID    := OutArray.DataArr[2];
    byChannel  := OutArray.DataArr[3];
    //****************************************Ti Section******************************************//
    //if OutArray.DataType=msgTR then
    if OutArray.DataType=16 then
    begin

     SendDebug(' KA:'+IntToStr(AKanal.Kanal)+
               ' B0:'+IntToStr(OutArray.DataArr[0])+
               ' B1:'+IntToStr(OutArray.DataArr[1])+
               ' B2:'+IntToStr(OutArray.DataArr[2])+
               ' B3:'+IntToStr(OutArray.DataArr[3])+
               ' B4:'+IntToStr(OutArray.DataArr[4]));

     Move(OutArray.DataArr[5], fValue, 4);

     //pL1Module.m_nSCD.SendTR(byGroup,fValue);

     //if byCommand = 1 then m_nSys[bySystem].SendHiLimit(bySensor,byDir,fValue);
     //if byCommand = 2 then m_nSys[bySystem].SendLoLimit(bySensor,byDir,fValue);
      //if byCommand = 3 then
      //Begin
      // byGate := 0;
      // if fValue<>0 then fValue := fValue + 0.5;
      //End;
     end;
     //****************************************Tc Section******************************************//
     //if OutArray.DataType=msgTU then
     if OutArray.DataType = 7 then
     begin
     //SendDebug('('+IntToStr(byChannel)+')'+':TC::>'+IntToStr(OutArray.DataArr[0]));
     if OutArray.DataArr[0] = 3 then wParam := 1;
     if OutArray.DataArr[0] = 4 then wParam := 0;
     //if byCommand=0 then m_nSys[bySystem].SendSnMode(bySensor,byDir,Byte(wParam));
     //if byCommand=1 then m_nSys[bySystem].SendLayerMode(bySensor,byDir,Byte(wParam));
     //if byCommand=2 then m_nSys[4].SendDigitalPulce(byDir,bySensor,byDOut,wParam,3000);
     //pL1Module.m_nSCD.SendTU(byChannel,wParam);

      //SendDebug('('+IntToStr(bySensor)+')'+':SN::>Out::>'+IntToStr(byDOut));
      {MessageDlg('TC('+IntToStr(OutArray.DataArr[2])+')'+
      'Adapt::'+IntToStr(AKanal.Adapt)+'::'+
      'KN::'+IntToStr(byChannel)+'::'+
      'Type::'+IntToStr(OutArray.DataType)+'::'+
      'Dir::'+IntToStr(byDir)+'::'+
      'Sens::'+IntToStr(bySensor)+'::'+
      'Comm::'+IntToStr(byCommand)+'::'+
      'OUT::'+IntToStr(byDOut)+'::',mtInformation, [mbOK], 0);}
     End;
     //****************************************Tc Section******************************************//
    AKanal.CurQuery.Data.Len := 0;
    except
    end;
  except
    on E : Exception do begin
      SendDebug('��� Adapter Query ' + E.Message);
    end;
  end;
end;









procedure TTFrmAscue.btChannelEdClick(Sender: TObject);
begin
  if btChannelEd.Down=True then
   m_nChannEdit.OpenInfo else
  if btChannelEd.Down=False then
   m_nChannEdit.CloseInfo else
end;

procedure TTFrmAscue.sgConnectDBClickCell(Sender: TObject; ARow,
  ACol: Integer);
begin
  m_nAscue.OnClickGrid(Sender,ARow,ACol);
end;

procedure TTFrmAscue.btRefreshTreeClick(Sender: TObject);
begin
    m_nAscue.OnRefreshTree;
end;

procedure TTFrmAscue.btTehnoCNClick(Sender: TObject);
begin
  if btTehnoCN.Down=True then
   m_nAscue.OpenInfo else
  if btTehnoCN.Down=False then
   m_nAscue.CloseInfo else
end;



initialization
  //Manager.Add(TautMIM);
  Manager.Add(TTAscueAdapter);

{ ============================================= }
finalization

end.










