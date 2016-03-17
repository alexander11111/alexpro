unit pltreehandler;

interface
uses
  Windows, Classes, SysUtils,SyncObjs,stdctrls,Controls, Forms, Dialogs,comctrls,
  utltype;
type
    {
    CTreeIndex = packed record
     PTIM     : Word;    //Картинка
     PTSD     : Word;    //Узел Типа Структуры Данных
     PNID     : Word;    //Узел Типа Примитива Данных
     PAID     : Word;    //Абонент
     PGID     : Word;    //Группа
     PVID     : Word;    //Виртуальный Счетчик
     PCID     : Word;    //Команда
     PPID     : Word;    //Порт
     PMID     : Word;    //Физ счетчик
     PTID     : Word;    //Тариф
     PSID     : Word;    //Тип хранения
     PDID     : Word;    //Тип Отображения
     PKey     : Word;
     FKey     : Word;
    End;
    SA_LOCK                      = 00;
    SA_UNLK                      = 01;
    SA_ALOK                      = 02;
    SA_CVRY                      = 03;
    SA_ALRM                      = 04;
    SA_REDY                      = 05;
    }

    SIMID = packed record
     m_sbyLOCK : Byte;
     m_sbyUNLK : Byte;
     m_sbyALOK : Byte;
     m_sbyCVRY : Byte;
     m_sbyALRM : Byte;
     m_sbyREDY : Byte;
    End;

    CTI = class
    public
     constructor Create;overload;
     constructor Create(sNSTT:SIMID);overload;
     constructor Create(nCTreeIndex:CTreeIndex);overload;
     constructor Create(PTIN,PTSD,PNID,PRID,PSTT:Word);overload;
     constructor Create(PTIN,PTSD,PNID,PRID,PAID,PSTT:Word);overload;
     constructor Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PSTT:Word);overload;
     constructor Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PVID,PMID,PPID,PSTT:Word);overload;
     constructor Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PVID,PMID,PPID,PCID,PTID,PSID,PDID:Word);overload;
     constructor Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PVID,PMID,PPID,PCID,PTID,PSID,PDID,PSTT:Word);overload;
    public
     m_sNSTT    : SIMID;
     m_blPulce  : Byte;
     m_blPulceEn: Byte;
     m_nCTI     : CTreeIndex;
    public
     procedure Run;
     procedure SetPulceState;
     procedure RemPulceState;
     procedure ChandgeState(byState:Byte);
     procedure PulceNode;
    End;
    PCTI = ^CTI;

    CTreeHandler = class
    public
     m_blEnable : Boolean;
    protected
     FTree   : TTreeView;
     m_nPIID : Integer;
     m_sNI   : SIMID;
    public
     constructor Create(pTree : TTreeView);
     destructor Destroy;override;
     procedure FreeTree;
     procedure ExpandTree(strNode : String);
     function  SetInNode(nTI:CTI;rtChild:TTreeNode;strName:String):TTreeNode;
     function  GetImID(nCTI:CTreeIndex):Byte;//virtual;
     function  CreateCTI:PCTI;virtual;
     function  IsTrueNode(nCTI:CTreeIndex):Boolean;virtual;
    public
     property  PTreeModule :TTreeView      read FTree    write FTree;
    End;

implementation

constructor CTI.Create;
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),0);
    m_blPulceEn := 0;
End;
constructor CTI.Create(sNSTT:SIMID);
Begin
    Move(sNSTT,m_sNSTT,sizeof(SIMID));
End;
constructor CTI.Create(nCTreeIndex:CTreeIndex);
Begin
    Move(nCTreeIndex,m_nCTI,sizeof(m_nCTI));
End;
constructor CTI.Create(PTIN,PTSD,PNID,PRID,PSTT:Word);
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),$ff);
    m_nCTI.PTIM := PTIN;
    m_nCTI.PNID := PNID;
    m_nCTI.PTSD := PTSD;
    m_nCTI.PRID := PRID;
    m_nCTI.PSTT := PSTT;
End;
constructor CTI.Create(PTIN,PTSD,PNID,PRID,PAID,PSTT:Word);
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),$ff);
    m_nCTI.PTIM := PTIN;
    m_nCTI.PNID := PNID;
    m_nCTI.PTSD := PTSD;
    m_nCTI.PRID := PRID;
    m_nCTI.PAID := PAID;
    m_nCTI.PSTT := PSTT;
End;
constructor CTI.Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PSTT:Word);
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),$ff);
    m_nCTI.PTIM := PTIN;
    m_nCTI.PNID := PNID;
    m_nCTI.PTSD := PTSD;
    m_nCTI.PRID := PRID;
    m_nCTI.PAID := PAID;
    m_nCTI.PGID := PGID;
    m_nCTI.PSTT := PSTT;
End;
constructor CTI.Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PVID,PMID,PPID,PSTT:Word);
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),$ff);
    m_nCTI.PTIM := PTIN;
    m_nCTI.PNID := PNID;
    m_nCTI.PTSD := PTSD;
    m_nCTI.PRID := PRID;
    m_nCTI.PAID := PAID;
    m_nCTI.PGID := PGID;
    m_nCTI.PVID := PVID;
    m_nCTI.PMID := PMID;
    m_nCTI.PPID := PPID;
    m_nCTI.PSTT := PSTT;
End;
constructor CTI.Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PVID,PMID,PPID,PCID,PTID,PSID,PDID:Word);
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),$ff);
    m_nCTI.PTIM := PTIN;
    m_nCTI.PNID := PNID;
    m_nCTI.PTSD := PTSD;
    m_nCTI.PRID := PRID;
    m_nCTI.PAID := PAID;
    m_nCTI.PGID := PGID;
    m_nCTI.PVID := PVID;
    m_nCTI.PMID := PMID;
    m_nCTI.PPID := PPID;
    m_nCTI.PCID := PCID;
    m_nCTI.PTID := PTID;
    m_nCTI.PSID := PSID;
    m_nCTI.PDID := PDID;
End;
constructor CTI.Create(PTIN,PTSD,PNID,PRID,PAID,PGID,PVID,PMID,PPID,PCID,PTID,PSID,PDID,PSTT:Word);
Begin
    FillChar(m_nCTI,sizeof(m_nCTI),$ff);
    m_nCTI.PTIM := PTIN;
    m_nCTI.PNID := PNID;
    m_nCTI.PTSD := PTSD;
    m_nCTI.PRID := PRID;
    m_nCTI.PAID := PAID;
    m_nCTI.PGID := PGID;
    m_nCTI.PVID := PVID;
    m_nCTI.PMID := PMID;
    m_nCTI.PPID := PPID;
    m_nCTI.PCID := PCID;
    m_nCTI.PTID := PTID;
    m_nCTI.PSID := PSID;
    m_nCTI.PSTT := PSTT;
End;
procedure CTI.PulceNode;
Begin
    with m_nCTI do
    if m_blPulce=1 then
    Begin
     ChandgeState(SA_UNLK);
     m_blPulce := 0;
    End else
    if m_blPulce=0 then
    Begin
     ChandgeState(SA_CVRY);
     m_blPulce := 1;
    End;
End;
procedure CTI.SetPulceState;
Begin
    m_blPulceEn := 1;
End;
procedure CTI.RemPulceState;
Begin
    m_blPulceEn := 0;
End;
procedure CTI.ChandgeState(byState:Byte);
Begin
    m_nCTI.PSTT := byState;
    with m_nCTI.PTND.Items.Item[m_nCTI.PIID],m_sNSTT do
    Begin
     case byState of
          SA_LOCK: Begin ImageIndex:=m_sbyLOCK;SelectedIndex:=m_sbyLOCK;End;
          SA_UNLK: Begin ImageIndex:=m_sbyUNLK;SelectedIndex:=m_sbyUNLK;End;
          SA_ALOK: Begin ImageIndex:=m_sbyALOK;SelectedIndex:=m_sbyALOK;End;
          SA_CVRY: Begin ImageIndex:=m_sbyCVRY;SelectedIndex:=m_sbyCVRY;End;
          SA_ALRM: Begin ImageIndex:=m_sbyALRM;SelectedIndex:=m_sbyALRM;End;
          SA_REDY: Begin ImageIndex:=m_sbyREDY;SelectedIndex:=m_sbyREDY;End;
     End;
    End;
End;
procedure CTI.Run;
Begin
    if m_blPulceEn=1 then PulceNode;
End;
constructor CTreeHandler.Create(pTree : TTreeView);
Begin
    FTree      := pTree;
    m_blEnable := True;
End;
destructor CTreeHandler.Destroy;
Begin
    FreeTree;
End;
function  CTreeHandler.GetImID(nCTI:CTreeIndex):Byte;
Begin
    Result := nCTI.PTIM;
    if IsTrueNode(nCTI)=True then
    case nCTI.PSTT of
         SA_LOCK: Result := m_sNI.m_sbyLOCK;
         SA_UNLK: Result := m_sNI.m_sbyUNLK;
         SA_ALOK: Result := m_sNI.m_sbyALOK;
         SA_CVRY: Result := m_sNI.m_sbyCVRY;
         SA_ALRM: Result := m_sNI.m_sbyALRM;
         SA_REDY: Result := m_sNI.m_sbyREDY;
    End;
End;
function  CTreeHandler.IsTrueNode(nCTI:CTreeIndex):Boolean;
Begin
    Result := (nCTI.PTSD=SD_ABONT)or(nCTI.PTSD=SD_VMETR);
End;
procedure CTreeHandler.ExpandTree(strNode : String);
Var
    i : Integer;
    nNode : TTreeNode;
Begin
     for i:=0 to FTree.Items.Count-1 do
     Begin
      if FTree.Items[i].Text=strNode then
      Begin
       if FTree.Items[i].Count<>0 then
       FTree.Items[i+1].Selected := True;
       //FTree.Items[i+1].StateIndex := 1;
       break;
      End
     End;
End;
function CTreeHandler.CreateCTI:PCTI;
Var
    pTI : PCTI;
Begin
    m_sNI.m_sbyLOCK := 11;
    m_sNI.m_sbyUNLK := 10;
    m_sNI.m_sbyALOK := 9;
    m_sNI.m_sbyCVRY := 9;
    m_sNI.m_sbyALRM := 12;
    m_sNI.m_sbyREDY := 9;
    New(pTI);
    pTI^ := CTI.Create(m_sNI);
    Result := pTI;
End;
function CTreeHandler.SetInNode(nTI:CTI;rtChild:TTreeNode;strName:String):TTreeNode;
Var
    pSL      : PCTI;
    rtChild1 : TTreeNode;
Begin
    nTI.m_nCTI.PIID := m_nPIID;
    pSL := CreateCTI;
    Move(nTI.m_nCTI,pSL.m_nCTI,sizeof(CTreeIndex));
    rtChild1 := FTree.Items.AddChild(rtChild,strName);
    with nTI.m_nCTI do PTIM :=GetImID(nTI.m_nCTI);
    rtChild1.ImageIndex    := nTI.m_nCTI.PTIM;
    rtChild1.SelectedIndex := nTI.m_nCTI.PTIM;
    pSL.m_nCTI.PTND        := FTree;
    rtChild1.Data          := pSL;
    m_nPIID  := m_nPIID + 1;
    Result   := rtChild1;
End;
procedure CTreeHandler.FreeTree;
Var
    i   : Integer;
    pTI : PCTI;
Begin
    for i:=0 to FTree.Items.Count-1 do
    Begin
     if FTree.Items[i]<>Nil then
     Begin
      pTI := FTree.Items[i].Data;
      if pTI<>Nil then
      Begin
       pTI.Free;
       //pTI.Destroy;
       Dispose(pTI);
      End;
     End;
    End;
    FTree.Items.Clear;
    m_nPIID := 0;
End;
end.
