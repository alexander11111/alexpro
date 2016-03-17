unit plindexgen;
interface
uses
Windows, Classes, SysUtils,SyncObjs,stdctrls,comctrls,utltype;
type
    CIndexGen = class
    protected
     m_pIndexBuff : PBooleanArray;
     m_nMaxIndex  : Integer;
     function SetIndex(nIndex : Integer):Integer;
     Procedure FreeIndex(nIndex : Integer);
     Procedure FreeAllIndex;
    public
     constructor Create(pIndexBuff:PBooleanArray;nMaxIndex:Integer);
     destructor  Destroy;override;
     Procedure Refresh;virtual;
     function GenIndex:Integer;
     function GenIndexSv:Integer;
    End;
implementation
constructor CIndexGen.Create(pIndexBuff:PBooleanArray;nMaxIndex:Integer);
Begin
    m_pIndexBuff := pIndexBuff;
    m_nMaxIndex  := nMaxIndex;
    FreeAllIndex;
End;
destructor  CIndexGen.Destroy;
Begin
    Inherited;
End;
Procedure CIndexGen.Refresh;
Begin
End;
//Index Generator
function  CIndexGen.GenIndex:Integer;
Var
    i : Integer;
Begin
    for i:=0 to m_nMaxIndex do
    if m_pIndexBuff[i]=True then
    Begin
     Result := i;
     exit;
    End;
    Result := -1;
End;
function CIndexGen.GenIndexSv:Integer;
Begin
    Result := SetIndex(GenIndex);
End;
function CIndexGen.SetIndex(nIndex : Integer):Integer;
Begin
    m_pIndexBuff[nIndex] := False;
    Result := nIndex;
End;
Procedure CIndexGen.FreeIndex(nIndex : Integer);
Begin
    m_pIndexBuff[nIndex] := True;
End;
Procedure CIndexGen.FreeAllIndex;
Var
    i : Integer;
Begin
    for i:=0 to m_nMaxIndex do FreeIndex(i);
End;
end.
