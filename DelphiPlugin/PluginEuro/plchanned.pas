unit plchanned;

interface
uses
     utltype,classes,Grids,BaseGrid,AdvGrid,comctrls,pltreehandler,Dialogs,
     forms,Sysutils,plchannbase,controls;
type
     TEditEvent = procedure(pL:TList) of object;
     CChannEdit = class
     private
      FDT     : TList;
      FCT     : CChannBase;
      pGL     : TList;
      FTView  : TTreeView;
      FsgGrid : TAdvStringGrid;
      FSaveEV : TEditEvent;
      pTH     : CTreeHandler;
      m_blTreeOpen : boolean;
      m_nTehnoLen : Integer;
      m_sCmd : TStringList;
      mTI    : CTreeIndex;
      m_nRowIndex : Integer;
      m_nIndex : Integer;
      m_nMinGrid : Integer;
      m_nMaxGrid : Integer;
      procedure setAscues;
      procedure SetInAscue(nTI:CTI;pTbl:SL3ABONS;rtChild:TTreeNode);
      procedure SetInAbon(nTI:CTI;var pTbl:SL3VMETERTAGS;rtChild:TTreeNode);
      procedure SetInMeter(nTI:CTI;nLEV:Byte;var pTbl:SL3VMETERTAG;rtChild:TTreeNode);
      procedure loadTree;
      procedure loadGrid(PRID,PVID,PNID:Integer);
      procedure AddRecordToGrid(nIndex:Integer;pTbl:CCData);
      procedure prepareGrid;
      function getCData(PRID,PVID,PNID:Word;var pD:TList):boolean;
      function isTrueParam(nCMD,PNID:Word):boolean;
      procedure saveChannels;
      //procedure addChannels(nSID:Word;pC:PSCHANN);
     public
      constructor create;
      destructor destroy;
      procedure load;
      procedure save;
      function  OnClickTree:CTreeIndex;
      procedure OnExpandTree(Node: TTreeNode);
      procedure OnCollapsedTree(Node: TTreeNode);
      procedure OnFormResize;
      procedure OpenInfo;
      procedure CloseInfo;
      procedure OnPrepareEdit;
      procedure OnClearChann;
      procedure OnClickGrid(Sender: TObject; ARow, ACol: Integer);
     public
      property PDT     : TList          read FDT     write FDT;
      property PTView  : TTreeView      read FTView  write FTView;
      property PsgGrid : TAdvStringGrid read FsgGrid write FsgGrid;
      property PSaveEV : TEditEvent     read FSaveEV write FSaveEV;
      property PCT     : CChannBase     read FCT     write FCT;
     end;
implementation
constructor CChannEdit.create;
Begin
     m_sCmd := TStringList.Create;
     m_nRowIndex := -1;
     m_nIndex := -1;
     pGL    := TList.Create;
     m_sCmd.LoadFromFile(ExtractFilePath(Application.ExeName)+'\PLASCUE\CommandType.dat');
     m_blTreeOpen  := False;
End;
destructor CChannEdit.destroy;
Begin
     m_sCmd.Destroy;
     pGL.Clear;
     pGL.Destroy;
     m_sCmd.Clear;
     m_sCmd.Destroy;
End;
procedure CChannEdit.load;
Begin
     if pTH=nil then pTH := CTreeHandler.Create(FTView);
     loadTree;
     prepareGrid;
End;
procedure CChannEdit.save;
Begin
     //addToChannels(getChannels);
     //if assigned(FSaveEV) then FSaveEV(FCT);
     saveChannels;
     FCT.flushTable;
End;
procedure CChannEdit.saveChannels;
Var
     i : Integer;
     pC : PSCHANN;
Begin
     for i:=1 to FsgGrid.RowCount-1 do
     Begin
      if FsgGrid.Cells[1,i]='' then exit;
      new(pC);
      pC^.m_sfValue := 0;
      pC^.m_nAsID := StrToInt(FsgGrid.Cells[8,i]);
      pC^.m_nScID := StrToInt(FsgGrid.Cells[1,i]);
      FCT.addChannels(mTI.PRID,pC);
     End;
End;
procedure CChannEdit.loadTree;
Begin
     setAscues;
End;
procedure CChannEdit.setAscues;
Var
    i  : Integer;
    nI : CTI;
    strName : string;
    pD : PSL3USPDS;
Begin
    FTView.FullCollapse;
    pTH.FreeTree;
    for i:=0 to FDT.Count-1 do
    Begin
     with SL3USPDS(FDT.Items[i]^) do
     Begin
      nI := CTI.Create(1,SD_REGIN,PD_UNKNW,m_nSID,1);
        SetInAscue(nI,m_nAbons,pTH.SetInNode(nI,Nil,m_sName));
     End;
    End;
End;
procedure CChannEdit.SetInAscue(nTI:CTI;pTbl:SL3ABONS;rtChild:TTreeNode);
Var
    i  : Integer;
    nI : CTI;
    strName : String;
Begin
    for i:=0 to pTbl.Count-1 do
    Begin
     with pTbl.Items[i],nTI.m_nCTI do
     Begin
      nI      := CTI.Create(1,SD_ABONT,PD_UNKNW,PRID,m_swABOID,m_sbyEnable);
      strName := m_sName+':'+m_sObject;
      if (m_sbyVisible=1) then
      SetInAbon(nI,ItemVM,pTH.SetInNode(nI,rtChild,strName));
      nI.Destroy;
     End;
    End;
End;
procedure CChannEdit.SetInAbon(nTI:CTI;var pTbl:SL3VMETERTAGS;rtChild:TTreeNode);
Var
    i,m_sbyType : Integer;
    nI          : CTI;
    rtRep       : TTreeNode;
Begin
    for i:=0 to pTbl.Count-1 do
    Begin //PMID<=>Level
     with nTI.m_nCTI,pTbl.Items[i] do
     Begin
      //m_sbyPortID := GetRealPort(m_sbyPortID);
      nI := CTI.Create(PTIM,SD_VMETR,PD_VMETR,PRID,PAID,PGID,m_swVMID,m_swMID,m_sbyPortID,m_sbyEnable);
      SetInMeter(nI,PVID,pTbl.Items[i],pTH.SetInNode(nI,rtChild,m_sVMeterName));
      nI.Destroy;
     End;
    End;
End;
procedure CChannEdit.SetInMeter(nTI:CTI;nLEV:Byte;var pTbl:SL3VMETERTAG;rtChild:TTreeNode);
Var
    nI : CTI;
Begin
    with nTI.m_nCTI do
    Begin
      nI := CTI.Create(2,SD_PRIMT,PD_ARCHV,PRID,PAID,PGID,PVID,PMID,PPID,PSTT);
      pTH.SetInNode(nI,rtChild,'Архивы Энергии');
      nI.Destroy;
      nI := CTI.Create(1,SD_PRIMT,PD_CURRT,PRID,PAID,PGID,PVID,PMID,PPID,PSTT);
      pTH.SetInNode(nI,rtChild,'Текущие');
      nI.Destroy;
    End;
End;
{
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
}
function CChannEdit.OnClickTree:CTreeIndex;
var
    nNode : TTreeNode;
    pIND  : PCTI;
    strSel : String;
Begin
    if m_blTreeOpen=False then Begin m_blTreeOpen := True;exit; End;
    nNode := FTView.Selected;
    if (nNode<>Nil) then
    Begin
     if nNode.Data<>Nil then
     Begin
      pIND := nNode.Data;
      strSel := nNode.Text;
      move(pIND.m_nCTI,mTI,sizeof(CTreeIndex));
      with pIND.m_nCTI do Begin
      case PNID of
           PD_UNKNW:
           Begin
            if PTSD=SD_REGIN then
            Begin
               //MessageDlg('Аскуэ '+strSel,mtWarning,[mbOk,mbCancel],0);
            End;
            if PTSD=SD_ABONT then
            Begin
               //MessageDlg('Abon '+strSel,mtWarning,[mbOk,mbCancel],0);
            End;
           End;
           PD_VMETR: if PTSD=SD_VMETR then
           Begin
              //MessageDlg('Meter '+strSel,mtWarning,[mbOk,mbCancel],0);
           End;
           PD_CURRT: if (PTSD=SD_PRIMT) then
           Begin
              //MessageDlg('Current '+strSel,mtWarning,[mbOk,mbCancel],0);
              loadGrid(PRID,PVID,PNID);
           End;
           PD_ARCHV: if PTSD=SD_PRIMT then
           Begin
              //MessageDlg('Archiv '+strSel,mtWarning,[mbOk,mbCancel],0);
              loadGrid(PRID,PVID,PNID);
           End;
      End;
      End;
     End;
    End;
    result := mTI;
End;
procedure CChannEdit.OnExpandTree(Node: TTreeNode);
Begin
    m_blTreeOpen  := False;
End;
procedure CChannEdit.OnCollapsedTree(Node: TTreeNode);
Begin
    m_blTreeOpen  := False;
End;
procedure CChannEdit.OnPrepareEdit;
Begin
    //prepareGrid;
End;
procedure CChannEdit.prepareGrid;
Begin
    FsgGrid.ColCount    := 9;
    FsgGrid.RowCount    := 2;
    FsgGrid.Cells[0,0]  := '№';
    FsgGrid.Cells[1,0]  := 'Канал';
    FsgGrid.Cells[2,0]  := 'Название параметра';
    FsgGrid.Cells[3,0]  := 'Тар.';
    FsgGrid.Cells[4,0]  := 'Значение 1';
    FsgGrid.Cells[5,0]  := 'Значение 2';
    FsgGrid.Cells[6,0]  := 'Время 1';
    FsgGrid.Cells[7,0]  := 'Время 2';
    FsgGrid.Cells[8,0]  := 'DBID';
    CloseInfo;
End;
procedure CChannEdit.OpenInfo;
Begin
    FsgGrid.ColWidths[0]:= 35;
    FsgGrid.ColWidths[1]:= 60;
    FsgGrid.ColWidths[2]:= 150;
    FsgGrid.ColWidths[3]:= 40;
    FsgGrid.ColWidths[4]:= 70;
    FsgGrid.ColWidths[5]:= 70;
    FsgGrid.ColWidths[6]:= 60;
    m_nTehnoLen         := 60+150+40+70+70+60;
    m_nMinGrid          := 7;
    m_nMaxGrid          := FsgGrid.ColCount-1;
    OnFormResize;
End;

procedure CChannEdit.CloseInfo;
Begin
    m_nMaxGrid          := 6;
    FsgGrid.ColWidths[0]:= 35;
    FsgGrid.ColWidths[1]:= 60;
    FsgGrid.ColWidths[2]:= 150;
    FsgGrid.ColWidths[3]:= 40;
    FsgGrid.ColWidths[4]:= 70;
    FsgGrid.ColWidths[5]:= 0;
    FsgGrid.ColWidths[6]:= 60;
    FsgGrid.ColWidths[7]:= 0;
    FsgGrid.ColWidths[8]:= 0;
    m_nTehnoLen         := 60+150+40+70;
    m_nMinGrid          := 6;
    m_nMaxGrid          := 6;
    OnFormResize;
End;
procedure CChannEdit.OnFormResize;
Var
    i : Integer;
Begin
    for i:=m_nMinGrid to m_nMaxGrid  do FsgGrid.ColWidths[i]  := trunc((FsgGrid.Width-m_nTehnoLen-2*FsgGrid.ColWidths[0])/(1+m_nMaxGrid-m_nMinGrid));
End;
procedure CChannEdit.loadGrid(PRID,PVID,PNID:Integer);
Var
    i,j,k  : Integer;
Begin
    k := 0;
    FsgGrid.ClearNormalCells;
    FsgGrid.RowCount := 2;
    if getCData(PRID,PVID,PNID,pGL)=true then
    Begin
     for i:=0 to pGL.Count-1 do
     for j:=0 to CCDatas(pGL.Items[i]^).Count-1 do
     Begin
      if isTrueParam(CCDatas(pGL.Items[i]^).Items[j].m_swCMDID,PNID)=true then
      Begin
       AddRecordToGrid(k,CCDatas(pGL.Items[i]^).Items[j]);
       k := k + 1;
      End;
     End;
    End;
    pGL.Clear;
End;
function CChannEdit.getCData(PRID,PVID,PNID:Word;var pD:TList):boolean;
Var
    pU : SL3USPDS;
    i,j,k : Integer;
    pCD : PCData;
Begin
    result := false;
    if(PRID<>$ffff)and(PVID<>$ffff)and(PNID<>$ffff) then
    Begin
     if (PRID>(FDT.Count-1))then exit;
     pU := SL3USPDS(FDT.Items[PRID]^);
     for i:=0 to pU.m_nAbons.Count-1 do   //Abons
     Begin
      for j:=0 to pU.m_nAbons.Items[i].ItemVM.Count-1 do   //Abons
      Begin
       if (PVID=pU.m_nAbons.Items[i].ItemVM.Items[j].m_swVMID) then
       Begin
        pD.Add(@pU.m_nAbons.Items[i].ItemVM.Items[j].ItemCD);
        result := true;
        exit;
       End;
      End;
     End;
    End;
End;
function CChannEdit.isTrueParam(nCMD,PNID:Word):boolean;
Begin
    result := false;
    case PNID of
         PD_CURRT:
         Begin
           if (((nCMD>=1)and(nCMD<=1))or((nCMD>=37)and(nCMD<=56))or(nCMD=129)or(nCMD=133)) then result := true;
           //if (((nCMD>=37)and(nCMD<=56))) then result := true;
         End;
         PD_ARCHV:                                      
         Begin
           if ((nCMD>=5)and(nCMD<=36))or((nCMD>=130)and(nCMD<=132))  then result := true;
         End;
    End;
End;

{
    FsgGrid.Cells[0,0]  := '№';
    FsgGrid.Cells[1,0]  := 'SCID';
    FsgGrid.Cells[2,0]  := 'Название параметра';
    FsgGrid.Cells[3,0]  := 'Тар.';
    FsgGrid.Cells[4,0]  := 'Значение';
    FsgGrid.Cells[5,0]  := 'Знач.PL';
    FsgGrid.Cells[6,0]  := 'Время';
    FsgGrid.Cells[7,0]  := 'Вр.PL';
    FsgGrid.Cells[8,0]  := 'DBID';
 SCHANN = packed record
     m_nScID : Integer;
     m_nAsID : Integer;
     m_sfValue : double;
    End;
 }
procedure CChannEdit.AddRecordToGrid(nIndex:Integer;pTbl:CCData);
Var
   nY : Integer;
   pC : SCHANN;
   res : Boolean;
Begin
    nY := nIndex+1;
    with pTbl do Begin
     res := FCT.getItemChann(mTI.PRID,m_swID,pC);
     FsgGrid.Cells[0,nY] := IntToStr(nY);
     if res=true then FsgGrid.Cells[1,nY] := IntToStr(pC.m_nScID) else FsgGrid.Cells[1,nY] := '-1';
     FsgGrid.Cells[2,nY] := m_sCmd.Strings[m_swCMDID];
     FsgGrid.Cells[3,nY] := IntToStr(m_swTID);
     FsgGrid.Cells[4,nY] := FloatToStrF(m_sfValue,ffNumber,10,3);
     if res=true then FsgGrid.Cells[5,nY] := FloatToStrF(pC.m_sfValue,ffNumber,10,3) else FsgGrid.Cells[5,nY] := '-1';
     FsgGrid.Cells[6,nY] := DateTimeToStr(m_sTime);
     if res=true then  FsgGrid.Cells[7,nY] := {Date}TimeToStr(Now) else FsgGrid.Cells[7,nY] := '-1';
     FsgGrid.Cells[8,nY] := IntToStr(m_swID);
     FsgGrid.RowCount    := FsgGrid.RowCount + 1;
    End;
End;
procedure CChannEdit.OnClearChann;
Begin
    if m_nRowIndex=-1  then
    Begin
     if MessageDlg('Удалить все каналы устройства '+IntToStr(mTI.PRID)+' ?',mtWarning,[mbOk,mbCancel],0)=mrOk then
      FCT.delChannels(mTI.PRID)
    End else
    if m_nRowIndex<>-1 then
    Begin
     if MessageDlg('Удалить канал ID='+IntToStr(m_nIndex)+' устройства '+IntToStr(mTI.PRID)+' ?',mtWarning,[mbOk,mbCancel],0)=mrOk then
      FCT.delChannel(mTI.PRID,m_nIndex);
    End
End;
procedure CChannEdit.OnClickGrid(Sender: TObject; ARow, ACol: Integer);
Begin
    m_nRowIndex := -1;
    if ARow>0 then Begin
     if FsgGrid.Cells[8,ARow]<>'' then
     Begin
      m_nIndex := StrToInt(FsgGrid.Cells[8,ARow]);
     End else m_nIndex := -1;
     m_nRowIndex := ARow;
    End;
End;
end.
