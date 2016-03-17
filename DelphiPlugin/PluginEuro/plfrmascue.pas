unit plfrmascue;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  AdvGlowButton, AdvToolBar, AdvPanel, ExtCtrls, AdvOfficeStatusBar,
  AdvOfficeStatusBarStylers, AdvAppStyler, AdvToolBarStylers, Menus,
  AdvMenus, AdvMenuStylers, AdvOfficePager, AdvOfficePagerStylers, Grids,
  utltype,BaseGrid, AdvGrid, ComCtrls, AdvSplitter, StdCtrls,plascues,
  ImgList,plchanned,plchannbase,bnrscad,knsl2timer, Db, DBTables, ADODB;

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
    btChannEd: TAdvToolBarButton;
    AdvToolBarSeparator1: TAdvToolBarSeparator;
    AdvToolBarButton9: TAdvToolBarButton;
    AdvToolBarSeparator2: TAdvToolBarSeparator;
    AdvToolBarSeparator3: TAdvToolBarSeparator;
    ImageListTree: TImageList;
    btOnClearChann: TAdvToolBarButton;
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
    procedure sgConnectDBClickCell(Sender: TObject; ARow, ACol: Integer);
    procedure btRefreshTreeClick(Sender: TObject);
  private
     m_nAscue : CAscues;
     m_pTmr : CTimerThread;
     m_blDBConnection : boolean;
     m_blChannEd : boolean;
     m_nChannEdit : CChannEdit;
     m_nCHB : CChannBase;
     mTI : CTreeIndex;
     mScada : CScadaDrv;
  private
     function getBaseBath(strConn:String):String;
     procedure loadSystem;
     procedure SetEditGrid(var blState:Boolean;var btButt:TAdvToolBarButton;var sgGrid:TAdvStringGrid;blIsRow:Boolean);
    { Private declarations }
  public
    { Public declarations }
  end;

var
  TFrmAscue: TTFrmAscue;

implementation

{$R *.DFM}

procedure TTFrmAscue.OnCreateFrm(Sender: TObject);
begin
     loadSystem;
end;
function TTFrmAscue.getBaseBath(strConn:String):String;
Var
    nIndex : Integer;
    strB   : String;
Begin
    try
     if (strConn='') then Begin result := 'c:\a2000\ascue\';exit;End;
     nIndex := pos('DbName=',strConn);
     strB   := Copy(strConn,nIndex+7,Length(strConn)-(nIndex-7));
     strB   := StringReplace(strB,'SYSINFOAUTO.FDB','',[rfReplaceAll]);
     result := strB;
    except
     result := 'c:\a2000\ascue\';
    end;
End;

procedure TTFrmAscue.loadSystem;
Var
    strPath : String;
Begin
     m_blDBConnection     := false;
     m_blChannEd := false;

     //strPath := getBaseBath('Driver=Firebird/InterBase(r) driver;Uid=SYSDBA;Pwd=masterkey;DbName=c:\a2000\ascue\SYSINFOAUTO.FDB');
     mScada := CScadaDrv.Create;
     mScada.Init;

     m_nCHB := CChannBase.create;

     m_nChannEdit         := CChannEdit.create;
     m_nChannEdit.PTView  := tvObjects;
     m_nChannEdit.PsgGrid := sgChannel;
     m_nChannEdit.PCT     := m_nCHB;

     m_nAscue         := CAscues.Create;
     m_nAscue.PScada  := mScada;
     //m_nAscue.Memo    := Memo1;
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
    if blState=False then //Open
    Begin
     btButt.ImageIndex := 14;
     btButt.Hint       := 'Редактирование';
     blState           := True;
     sgGrid.Options    := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goRangeSelect,goDrawFocusSelected,goColSizing,goEditing];
    End else
    if blState=True then //Close
    Begin
     btButt.ImageIndex := 15;
     btButt.Hint       := 'Отображение';
     blState           := False;
     if blIsRow=True  then sgGrid.Options := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goRangeSelect,goDrawFocusSelected,goColSizing,goRowSelect{goEditing}] else
     if blIsRow=False then sgGrid.Options    := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goDrawFocusSelected,goColSizing];
    End;
end;

procedure TTFrmAscue.cnlAdvButtClick(Sender: TObject);
begin
    SetEditGrid(m_blDBConnection,cnlAdvButt,sgConnectDB,True);
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
    SetEditGrid(m_blChannEd,btChannEd,sgChannel,True);
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
    if m_blChannEd=false then exit;
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

procedure TTFrmAscue.sgConnectDBClickCell(Sender: TObject; ARow,
  ACol: Integer);
begin
   m_nAscue.OnClickGrid(Sender,ARow,ACol);
end;

procedure TTFrmAscue.btRefreshTreeClick(Sender: TObject);
begin
   m_nAscue.OnRefreshTree;

end;

end.
