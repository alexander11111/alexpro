unit plascuegr;
interface
uses
     Grids,BaseGrid,AdvGrid,Sysutils,plindexgen,utltype,classes,Graphics;
type
     CConnIndex = class(CIndexGen)
     public
     constructor Create(pIndexBuff:PBooleanArray;nMaxIndex:Integer);
     Procedure Refresh;override;
     End;
     CAscuesGr = class
     private
      FsgGrid : TAdvStringGrid;
      m_nTehnoLen : Integer;
      m_nRowIndex : Integer;
      m_nIDIndex  : Integer;
      m_nAmRecords: Integer;
      m_nIndex    : Integer;
      m_blConID   : array[0..20] of boolean;
      pI          : CConnIndex;
      m_nActiveList : TStringList;
      m_nMinGrid : Integer;
      m_nMaxGrid : Integer;
     private
      function  FindFreeRow(nIndex:Integer):Integer;
      procedure ExecSetGrid;
      procedure SetDefaultRow(i:Integer);
      procedure GetGridRecord(var pTbl:SQWERYMDL);
      procedure AddRecordToGrid(nIndex:Integer;pTbl:SQWERYMDL);
     protected
      function addTable(pTbl:SQWERYMDL):boolean;virtual;
      function getTable(var pTbl:TList):boolean;virtual;
      procedure cloneTable(ID:Integer);virtual;
      procedure flushTable;virtual;
      procedure delRecord(ID:Integer);virtual;
      procedure SetAlarmColor(nY:Integer;cl:TColor);
     public
      procedure OpenInfo;
      procedure CloseInfo;
      procedure OnDelAllRow;
      procedure OnDelRow;
      procedure OnAddRow;
      procedure OnCloneRow;
      procedure OnSaveGrid;
      procedure OnLoadGrid;
      procedure InitGrid(nRowCount:Integer);
      procedure OnFormResize;
      procedure OnClickGrid(Sender: TObject; ARow, ACol: Integer);
      procedure OnGetCellType(Sender: TObject; ACol, ARow: Integer;var AEditor: TEditorType);
      procedure v_ReportListCheckBoxClick(Sender: TObject; ACol,ARow: Integer; State: Boolean);
     public
      property PsgGrid : TAdvStringGrid read FsgGrid write FsgGrid;
     end;
implementation

//��������� L1
constructor CConnIndex.Create(pIndexBuff:PBooleanArray;nMaxIndex:Integer);
Begin
     inherited Create(pIndexBuff,nMaxIndex);
end;
Procedure CConnIndex.Refresh;
Var
    pTbl : SQWERYMDLS;
    i    : Integer;
Begin
    FreeAllIndex;
    //if getTable(pTbl)=True then for i:=0 to pTbl.Count-1 do SetIndex(pTbl.Items[i].m_snID);
End;
function CAscuesGr.addTable(pTbl:SQWERYMDL):boolean;
Begin
    result := false;
end;
function CAscuesGr.getTable(var pTbl:TList):boolean;
Begin
    result := false;
end;
procedure CAscuesGr.flushTable;
Begin
End;
procedure CAscuesGr.cloneTable(ID:Integer);
Begin
End;
procedure CAscuesGr.delRecord(ID:Integer);
Begin

End;

procedure CAscuesGr.InitGrid(nRowCount:Integer);
Begin
    pI                  := CConnIndex.Create(@m_blConID,20);
    m_nActiveList       := TStringList.Create;
    m_nActiveList.add('���');
    m_nActiveList.add('��');
    m_nRowIndex         := -1;
    m_nIndex            := -1;
    m_nAmRecords        := nRowCount+2;
    m_nIDIndex          := 1;
    FsgGrid.ColCount    := 11;
    FsgGrid.RowCount    := nRowCount+2;
    FsgGrid.Cells[0,0]  := '�';
    FsgGrid.Cells[1,0]  := 'ID';
    FsgGrid.Cells[2,0]  := 'CH';
    FsgGrid.Cells[3,0]  := '�������� �����';
    FsgGrid.Cells[4,0]  := '������ �����������';
    FsgGrid.Cells[5,0]  := '���.���';
    FsgGrid.Cells[6,0]  := '���.���';
    FsgGrid.Cells[7,0]  := '������';
    FsgGrid.Cells[8,0]  := '����';
    FsgGrid.Cells[9,0]  := '����������';
    FsgGrid.Cells[10,0] := '���������';
    CloseInfo
End;
procedure CAscuesGr.OpenInfo;
Begin
    FsgGrid.ColWidths[0]:= 30;
    FsgGrid.ColWidths[1]:= 40;
    FsgGrid.ColWidths[2]:= 40;
    FsgGrid.ColWidths[3]:= 100;
    FsgGrid.ColWidths[4]:= 350;
    m_nTehnoLen         := 40+40+100+350;
    m_nMinGrid          := 5;
    m_nMaxGrid          := FsgGrid.ColCount-1;
    OnFormResize;
End;

procedure CAscuesGr.CloseInfo;
Begin
    FsgGrid.ColWidths[0]:= 30;
    FsgGrid.ColWidths[1]:= 0;
    FsgGrid.ColWidths[2]:= 0;
    FsgGrid.ColWidths[3]:= 100;
    FsgGrid.ColWidths[4]:= 350;
    m_nTehnoLen         := 0+0+100+350;
    m_nMinGrid          := 5;
    m_nMaxGrid          := FsgGrid.ColCount-1;
    OnFormResize;
End;
procedure CAscuesGr.OnFormResize;
Var
    i : Integer;
Begin
    for i:=m_nMinGrid to m_nMaxGrid  do FsgGrid.ColWidths[i]  := trunc((FsgGrid.Width-m_nTehnoLen-2*FsgGrid.ColWidths[0])/(1+m_nMaxGrid-m_nMinGrid));
End;
procedure CAscuesGr.SetAlarmColor(nY:Integer;cl:TColor);
Begin
    if nY<=FsgGrid.RowCount then
    FsgGrid.Colors[10,nY] := cl;
End;
{
 v_ReportList.GetCheckBoxState(2,i+1, l_State);
    if l_State then
      Result := Result OR (sh shl i);

v_ReportList.Cells[2,i+1] := ' �����';
      v_ReportList.AddCheckBox(2, i+1, True, false);
}
procedure CAscuesGr.OnGetCellType(Sender: TObject; ACol, ARow: Integer;var AEditor: TEditorType);
begin
    with FsgGrid do
    case ACol of
    10:AEditor := edCheckBox;
    9:Begin
        combobox.items.clear;
        AEditor := edComboList;
        combobox.items.Add('���');
        combobox.items.Add('��');
       End;
    5,6,7: AEditor := edTimeEdit;
    end;
end;
procedure CAscuesGr.OnSaveGrid;
Var
    i : Integer;
    pTbl:SQWERYMDL;
Begin
    for i:=1 to FsgGrid.RowCount do
    Begin
     if FsgGrid.Cells[m_nIDIndex,i]='' then break;
     pTbl.m_snID := i;
     GetGridRecord(pTbl);
     if AddTable(pTbl)=true then pI.SetIndex(pTbl.m_snID);
    End;
    flushTable;
    ExecSetGrid;
End;
procedure CAscuesGr.OnLoadGrid;
Begin
    ExecSetGrid;
End;
//Grid Routine
procedure CAscuesGr.ExecSetGrid;
Var
    pTbl : TList;
    i : Integer;
Begin
    FsgGrid.ClearNormalCells;
    pI.FreeAllIndex;
    if getTable(pTbl)=True then
    Begin
     m_nAmRecords := pTbl.Count;
     for i:=0 to pTbl.Count-1 do
     Begin
      pI.SetIndex(SQWERYMDL(pTbl.Items[i]^).m_snID);
      AddRecordToGrid(i,SQWERYMDL(pTbl.Items[i]^));
     End;
     //ViewChild(StrToInt(pTbl.Items[0].m_sbyPortID));
    End;
End;
procedure CAscuesGr.OnAddRow;
Var
    nIndex : Integer;

Begin
    if m_nRowIndex<>-1 then
    Begin
     SetDefaultRow(m_nRowIndex);
     pI.SetIndex(StrToInt(FsgGrid.Cells[m_nIDIndex,m_nRowIndex]));
    End else
    Begin
     nIndex := FindFreeRow(m_nIDIndex);
     SetDefaultRow(nIndex);
     pI.SetIndex(StrToInt(FsgGrid.Cells[m_nIDIndex,nIndex]));
     FsgGrid.RowCount := FsgGrid.RowCount + 1;
    End;
End;
procedure CAscuesGr.SetDefaultRow(i:Integer);
Var
    nIndex : Integer;
Begin
    if FsgGrid.Cells[1,i]='' then FsgGrid.Cells[1,i] := IntToStr(pI.GenIndex);
    if FsgGrid.Cells[2,i]='' then FsgGrid.Cells[2,i] := '0';
    if FsgGrid.Cells[3,i]='' then FsgGrid.Cells[3,i] := '����� '+FsgGrid.Cells[1,i];
    if FsgGrid.Cells[4,i]='' then FsgGrid.Cells[4,i] := '������ �����������';
    if FsgGrid.Cells[5,i]='' then FsgGrid.Cells[5,i] := '23:59:00';
    if FsgGrid.Cells[6,i]='' then FsgGrid.Cells[6,i] := '00:00:00';
    if FsgGrid.Cells[7,i]='' then FsgGrid.Cells[7,i] := '00:30:00';
    if FsgGrid.Cells[8,i]='' then FsgGrid.Cells[8,i] := '127.0.0.1';
    if FsgGrid.Cells[9,i]='' then FsgGrid.Cells[9,i] := m_nActiveList.Strings[0];
    if FsgGrid.Cells[10,i]='' then
    Begin
     FsgGrid.Cells[10,i] := '��������';
     FsgGrid.AddCheckBox(10,i,True,false);
    End;
End;
procedure CAscuesGr.GetGridRecord(var pTbl:SQWERYMDL);
Var
    i : Integer;
    l_State : Boolean;
Begin
    try
    i := pTbl.m_snID;
    with pTbl do Begin
     m_snID          := StrToInt(FsgGrid.Cells[1,i]);
     m_nAmChannel    := StrToInt(FsgGrid.Cells[2,i]);
     m_sAscueName    := FsgGrid.Cells[3,i];
     m_sDBConnection := FsgGrid.Cells[4,i];
     m_sdtBegin      := StrToTime(FsgGrid.Cells[5,i]);
     m_sdtEnd        := StrToTime(FsgGrid.Cells[6,i]);
     m_sdtPeriod     := StrToTime(FsgGrid.Cells[7,i]);
     m_nPingIP       := FsgGrid.Cells[8,i];
     m_sbyEnable     := m_nActiveList.IndexOf(FsgGrid.Cells[9,i]);
     m_swDayMask     := 0;
     m_sdwMonthMask  := 0;
     FsgGrid.GetCheckBoxState(10,i, l_State);
     m_sbyState      := Byte(l_State);
    End;
    except

    end;
End;
procedure CAscuesGr.AddRecordToGrid(nIndex:Integer;pTbl:SQWERYMDL);
Var
   nY : Integer;
Begin
    nY := nIndex+1;
    with pTbl do Begin
     FsgGrid.Cells[0,nY] := IntToStr(nY);
     FsgGrid.Cells[1,nY] := IntToStr(m_snID);
     FsgGrid.Cells[2,nY] := IntToStr(m_nAmChannel);
     FsgGrid.Cells[3,nY] := m_sAscueName;
     FsgGrid.Cells[4,nY] := m_sDBConnection;
     FsgGrid.Cells[5,nY] := TimeToStr(m_sdtBegin);
     FsgGrid.Cells[6,nY] := TimeToStr(m_sdtEnd);
     FsgGrid.Cells[7,nY] := TimeToStr(m_sdtPeriod);
     FsgGrid.Cells[8,nY] := m_nPingIP;
     FsgGrid.Cells[9,nY] := m_nActiveList.Strings[m_sbyEnable];
     if m_sbyState=1 then
     Begin
      FsgGrid.Cells[10,nY] := ' ��������';
      FsgGrid.AddCheckBox(10,nY, True, false);
     End else
     Begin
      FsgGrid.Cells[10,nY] := ' ���������';
      FsgGrid.AddCheckBox(10,nY, false, false);
     End;
    End;
End;
procedure CAscuesGr.v_ReportListCheckBoxClick(Sender: TObject; ACol,
  ARow: Integer; State: Boolean);
begin
    if State = true then
      FsgGrid.Cells[ACol,ARow] := ' ��������'
    else
      FsgGrid.Cells[ACol,ARow] := ' ���������';
end;
function CAscuesGr.FindFreeRow(nIndex:Integer):Integer;
Var
    i : Integer;
Begin
    for i:=1 to FsgGrid.RowCount-1 do if FsgGrid.Cells[nIndex,i]='' then
    Begin
     Result := i;
     exit;
    End;
    Result := 1;
End;
procedure CAscuesGr.OnCloneRow;
Var
    nIndex : Integer;
    pTbl   : SQWERYMDL;
Begin
    if m_nRowIndex<>-1 then
    if m_nRowIndex<=FindFreeRow(m_nIDIndex)-1 then
    Begin
     pTbl.m_snID   := m_nRowIndex;
     GetGridRecord(pTbl);
     pTbl.m_snID := pI.GenIndexSv;
     FsgGrid.RowCount := FsgGrid.RowCount + 1;
     AddRecordToGrid(FindFreeRow(m_nIDIndex)-1,pTbl);
    End;
End;
procedure CAscuesGr.OnDelRow;
Var
    nFind : Integer;
Begin
    if m_nAmRecords=FindFreeRow(m_nIDIndex)-1 then
    Begin
     if m_nIndex<>-1 then
     Begin
      pI.FreeAllIndex;
      delRecord(m_nIndex);
      ExecSetGrid;
     End;
    End else
    Begin
     if m_nRowIndex<>-1 then
     Begin
      if FsgGrid.Cells[1,m_nRowIndex]<>'' then
      pI.FreeIndex(StrToInt(FsgGrid.Cells[m_nIDIndex,m_nRowIndex]));
      FsgGrid.ClearRows(m_nRowIndex,1);
     End;
    End;
End;
procedure CAscuesGr.OnDelAllRow;
Begin

end;
procedure CAscuesGr.OnClickGrid(Sender: TObject; ARow, ACol: Integer);
Begin
    m_nRowIndex := -1;
    if ARow>0 then Begin
     if FsgGrid.Cells[m_nIDIndex,ARow]<>'' then
     Begin
      m_nIndex := StrToInt(FsgGrid.Cells[m_nIDIndex,ARow]);
     End else m_nIndex := -1;
     m_nRowIndex := ARow;
    End;
End;
end.
