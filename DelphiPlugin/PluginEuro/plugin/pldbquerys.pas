unit pldbquerys;
interface
uses
     pldbQwery,utltype,Sysutils,classes;
type
     CDBQuerys = class
     private
       FDB : CDBQuery;
     private
       function GetVMetersTable(nAbon,nChannel:Integer;var pTable:SL3GROUPTAG):Boolean;
       function GetAbonVMetersTable(nAbon,nChannel:Integer;var pTable:SL3VMETERTAGS):Boolean;
       function GetVParamsTable(nChannel:Integer;var pTable:SL3VMETERTAG):Boolean;
       function GetCData(nIndex,nDataType:Integer;var pTable:CCDatas):Boolean;
     public
       function Connect:boolean;
       procedure Disconnect;
       constructor Create;
       destructor Destroy;
       function ping:boolean;
       function loadAbons(var pTable:SL3ABONS):boolean;
       function GetAbonsTable(var pTable:SL3ABONS):Boolean;
       function getValue(var pTable:TList):boolean;
     public
       property PDB : CDBQuery read FDB write FDB;
     end;
implementation
constructor CDBQuerys.Create;
begin
end;
destructor CDBQuerys.Destroy;
begin
end;
function CDBQuerys.Connect:boolean;
Begin
    result := FDB.Connect;
End;
function CDBQuerys.ping:boolean;
Var
    nC : Integer;
Begin
    try
      result := FDB.OpenQry('SELECT 0 FROM SUSERTAG',nC);
      FDB.CloseQry;
    except
      result := false;
      FDB.CloseQry;
    end;
End;
procedure CDBQuerys.Disconnect;
begin
    FDB.Disconnect;
end;
function CDBQuerys.GetAbonsTable(var pTable:SL3ABONS):Boolean;
Var
    i : Integer;
    strSQL   : String;
    res      : Boolean;
    nCount   : Integer;
Begin
    res := False;
    strSQL := 'SELECT * FROM SL3ABON';
    //if (m_dwSort and SRT_ABON)<>0 then strSQL := 'SELECT * FROM SL3ABON ORDER BY m_sName';
    pTable.Count := 0;
    if FDB.OpenQry(strSQL,nCount)=True then
    Begin
     i:=0;res := True;
     pTable.Count := nCount;
     SetLength(pTable.Items,nCount);
     while not FDB.FADOQuery.Eof do Begin
     with FDB.FADOQuery,pTable.Items[i] do  Begin
      m_swID      := FieldByName('m_swID').AsInteger;
      m_swABOID   := FieldByName('m_swABOID').AsInteger;
      m_swPortID  := FieldByName('m_swPortID').AsInteger;
      m_sdtRegDate:= FieldByName('m_sdtRegDate').AsDateTime;
      m_sName     := FieldByName('m_sName').AsString;
      m_sObject   := FieldByName('m_sObject').AsString;
      m_nRegionID := FieldByName('m_nRegionID').AsInteger;
      m_sKSP      := FieldByName('m_sKSP').AsString;
      m_sDogNum   := FieldByName('m_sDogNum').AsString;
      m_sPhone    := FieldByName('m_sPhone').AsString;
      m_sAddress  := FieldByName('m_sAddress').AsString;
      m_sEAddress := FieldByName('m_sEAddress').AsString;
      m_sShemaPath:= FieldByName('m_sShemaPath').AsString;
      m_sComment  := FieldByName('m_sComment').AsString;
      m_sTelRing  := FieldByName('m_sTelRing').AsString;
      m_sRevPhone := FieldByName('m_sRevPhone').AsString;
      m_sbyEnable := FieldByName('m_sbyEnable').AsInteger;
      m_sbyVisible:= FieldByName('m_sbyVisible').AsInteger;
      m_sReportVS := StrToInt64Def(FieldByName('m_sReportVS').AsString, 0);
      m_sLIC      := FieldByName('m_sLIC').AsString;
      m_strOBJCODE:= FieldByName('m_strOBJCODE').AsString;
      m_sMaxPower := FieldByName('m_sMaxPower').AsFloat;
      m_sTreeSettings := FieldByName('m_sTreeSettings').AsInteger;
      m_sAddrSettings := StrToInt64Def(FieldByName('m_sAddrSettings').AsString, 0);
      Next;
      Inc(i);
      End;
     End;
    End;
    FDB.CloseQry;
    Result := res;
End;
function CDBQuerys.GetVMetersTable(nAbon,nChannel:Integer;var pTable:SL3GROUPTAG):Boolean;
Var
    i : Integer;
    strSQL   : String;
    res      : Boolean;
    nCount   : Integer;
Begin
    nCount := 0;
    res := False;
    if (nAbon=-1)and(nChannel=-1) then
      strSQL := 'SELECT * FROM SL3VMETERTAG, L2TAG,SL3GROUPTAG WHERE SL3VMETERTAG.m_swmid = l2tag.m_swmid'+
                ' and SL3GROUPTAG.m_sbyGroupID=SL3VMETERTAG.m_sbyGroupID'+
                ' ORDER BY SL3GROUPTAG.m_swABOID,SL3VMETERTAG.m_swVMID';
      //strSQL := 'SELECT * FROM SL3VMETERTAG,L2TAG WHERE SL3VMETERTAG.m_swmid = l2tag.m_swmid ORDER BY SL3VMETERTAG.m_swVMID';
    if nChannel<>-1 then
      strSQL := 'SELECT * FROM SL3VMETERTAG, L2TAG,SL3GROUPTAG WHERE SL3VMETERTAG.m_swmid = l2tag.m_swmid'+
                ' and SL3GROUPTAG.m_sbyGroupID=SL3VMETERTAG.m_sbyGroupID'+
                ' and SL3GROUPTAG.m_swABOID=' + IntToStr(nAbon)+
                ' and SL3VMETERTAG.m_sbyGroupID='+IntToStr(nChannel)+
                ' ORDER BY SL3VMETERTAG.m_swVMID';
    if (nChannel=-1) and (nAbon<>-1)  then
      strSQL := 'SELECT * FROM SL3VMETERTAG,L2TAG,SL3GROUPTAG WHERE SL3VMETERTAG.m_swmid = l2tag.m_swmid'+
                ' and SL3GROUPTAG.m_sbyGroupID=SL3VMETERTAG.m_sbyGroupID'+
                ' and SL3GROUPTAG.m_swABOID=' + IntToStr(nAbon)+
                ' ORDER BY SL3VMETERTAG.m_swVMID';
    if FDB.OpenQry(strSQL,nCount)=True then
    Begin
     i:=0;res := True;
     pTable.m_swAmVMeter:= nCount;
     pTable.Item.Count  := nCount;
     SetLength(pTable.Item.Items,nCount);
    // SetLength(MeterPrecision, nCount);
     while not FDB.FADOQuery.Eof do Begin
     with FDB.FADOQuery,pTable.Item.Items[i] do  Begin
      m_swID                   := FieldByName('m_swID').AsInteger;
      m_swMID                  := FieldByName('m_swMID').AsInteger;
      m_sbyPortID              := FieldByName('m_sbyPortID').AsInteger;
      m_sbyType                := FieldByName('m_sbyType').AsInteger;
      m_sbyGroupID             := FieldByName('m_sbyGroupID').AsInteger;
      m_swVMID                 := FieldByName('m_swVMID').AsInteger;
      m_sddPHAddres            := FieldByName('m_sddPHAddres').AsString;
      m_sMeterName             := FieldByName('m_sMeterName').AsString;
      m_sVMeterName            := FieldByName('m_sVMeterName').AsString;
      m_sMeterCode             := FieldByName('m_sMeterCode').AsString;
      m_sbyEnable              := FieldByName('m_sbyEnable').AsInteger;
      //MeterPrecision[m_swVMID] := FieldByName('m_sbyPrecision').AsInteger;
      Next;
      Inc(i);
      End;
     End;
     //MaxPrecision := FindMax(MeterPrecision, nCount);
    End;
    FDB.CloseQry;
    Result := res;
End;
function CDBQuerys.GetAbonVMetersTable(nAbon,nChannel:Integer;var pTable:SL3VMETERTAGS):Boolean;
Var
    i : Integer;
    strSQL   : String;
    res      : Boolean;
    nCount   : Integer;
Begin
    res := False;
    if (nAbon<>-1)and(nChannel<>-1) then strSQL := 'SELECT SL3VMETERTAG.*,m_sGroupName FROM SL3VMETERTAG,SL3GROUPTAG WHERE SL3VMETERTAG.m_sbyGroupID=SL3GROUPTAG.m_sbyGroupID'+
                                   ' and SL3GROUPTAG.m_swABOID='+IntToStr(nAbon)+
                                   ' and SL3GROUPTAG.m_sbyGroupID='+IntToStr(nChannel)+
                                   ' ORDER BY m_swVMID' else
    if (nAbon<>-1)and(nChannel=-1)  then strSQL := 'SELECT SL3VMETERTAG.*,m_sGroupName FROM SL3VMETERTAG,SL3GROUPTAG WHERE SL3VMETERTAG.m_sbyGroupID=SL3GROUPTAG.m_sbyGroupID'+
                                   ' and SL3GROUPTAG.m_swABOID='+IntToStr(nAbon)+
                                   ' ORDER BY m_swVMID' else
    if (nAbon=-1)and(nChannel=-1)  then strSQL := 'SELECT SL3VMETERTAG.*,m_sGroupName FROM SL3VMETERTAG,SL3GROUPTAG WHERE SL3VMETERTAG.m_sbyGroupID=SL3GROUPTAG.m_sbyGroupID'+
                                   ' ORDER BY m_swVMID';
    pTable.Count   := 0;
    if FDB.OpenQry(strSQL,nCount)=True then
    Begin
     i:=0;res := True;
     pTable.Count := nCount;
     SetLength(pTable.Items,nCount);
     while not FDB.FADOQuery.Eof do Begin
     with FDB.FADOQuery,pTable.Items[i] do  Begin
      m_swID        := FieldByName('m_swID').AsInteger;
      m_swMID       := FieldByName('m_swMID').AsInteger;
      m_sbyPortID   := FieldByName('m_sbyPortID').AsInteger;
      m_sbyType     := FieldByName('m_sbyType').AsInteger;
      m_sbyGroupID  := FieldByName('m_sbyGroupID').AsInteger;
      m_swVMID      := FieldByName('m_swVMID').AsInteger;
      m_sddPHAddres := FieldByName('m_sddPHAddres').AsString;
      m_sMeterName  := FieldByName('m_sGroupName').AsString;
      m_sVMeterName := FieldByName('m_sVMeterName').AsString;
      m_sbyExport   := FieldByName('m_sbyExport').AsInteger;
      m_swPLID      := FieldByName('m_swPLID').AsInteger;
      m_sbyEnable   := FieldByName('m_sbyEnable').AsInteger;
      M_SMETERCODE  := FieldByName('M_SMETERCODE').AsString;
      Next;
      Inc(i);
      End;
     End;
    End;
    FDB.CloseQry;
    Result := res;
End;
function CDBQuerys.GetVParamsTable(nChannel:Integer;var pTable:SL3VMETERTAG):Boolean;
Var
    i : Integer;
    strSQL,strSRT : String;
    res      : Boolean;
    nCount   : Integer;
Begin
    res := False;
    //strSRT := '';
    //if (m_dwSort and SRT_PARM)<>0 then strSRT := ' ORDER BY m_swParamID';
    strSRT := ' ORDER BY m_swParamID';
    if nChannel<>-1 then strSQL := 'SELECT * FROM SL3PARAMS WHERE m_swVMID='+IntToStr(nChannel)+strSRT;
    if nChannel=-1  then strSQL := 'SELECT * FROM SL3PARAMS'+strSRT;
    pTable.m_swAmParams := 0; pTable.Item.Count := 0;
    if FDB.OpenQry(strSQL,nCount)=True then
    Begin
     i:=0;res := True;
     pTable.m_swAmParams := nCount;
     pTable.Item.Count   := nCount;
     SetLength(pTable.Item.Items,nCount);
     while not FDB.FADOQuery.Eof do Begin
     with FDB.FADOQuery,pTable.Item.Items[i] do  Begin
      m_swID          := FieldByName('m_swID').AsInteger;
      m_swVMID        := FieldByName('m_swVMID').AsInteger;
      m_swParamID     := FieldByName('m_swParamID').AsInteger;
      m_sParamExpress := FieldByName('m_sParamExpress').AsString;
      m_sParam        := FieldByName('m_sParam').AsString;
      //m_fValue        := FieldByName('m_fValue').AsFloat;
      m_fMin          := FieldByName('m_fMin').AsFloat;
      m_fMax          := FieldByName('m_fMax').AsFloat;
      m_fDiffer       := FieldByName('m_fDiffer').AsFloat;
      m_dtLastTime    := FieldByName('m_dtLastTime').AsDateTime;
      m_stSvPeriod    := FieldByName('m_stSvPeriod').AsInteger;
      m_sblTarif      := FieldByName('m_sblTarif').AsInteger;
      m_sblCalculate  := FieldByName('m_sblCalculate').AsInteger;
      m_sblSaved      := FieldByName('m_sblSaved').AsInteger;
      m_swStatus      := FieldByName('m_swStatus').AsInteger;
      m_sblEnable     := FieldByName('m_sblEnable').AsInteger;
      m_sbyDataGroup  := FieldByName('m_sbyDataGroup').AsInteger;
      m_sbyLockState  := FieldByName('m_sbyLockState').AsInteger;
      m_snDataType    := FieldByName('m_snDataType').AsInteger;
      Next;
      Inc(i);
      End;
     End;
    End;
    FDB.CloseQry;
    Result := res;
End;
function CDBQuerys.GetCData(nIndex,nDataType:Integer;var pTable:CCDatas):Boolean;
Var
    strSQL   : AnsiString;
    strEQ    : String;
    res      : Boolean;
    nCount,i : Integer;
Begin
    strEQ := '';
    if (nDataType=0) then strEQ := ' and (m_swCMDID>=1  and m_swCMDID<=36)' else
    if (nDataType=1) then strEQ := ' and (m_swCMDID>=37 and m_swCMDID<=56)';
    strSQL := 'SELECT distinct m_swID,m_swCMDID,m_swVMID,M_SWTID,m_sTime,m_sfValue'+
    ' FROM L3CURRENTDATA'+
    ' WHERE m_swVMID='+IntToStr(nIndex)+strEQ+
    ' and m_swTID<=4' +
    ' ORDER BY m_swVMID,M_SWCMDID,M_SWTID';
    res := False;
    if FDB.OpenQry(strSQL,nCount)=True then
    Begin
    i := 0;
    res := True;
    pTable.Count := nCount;
    SetLength(pTable.Items,nCount);
    while not FDB.FADOQuery.Eof do Begin
     with FDB.FADOQuery,pTable.Items[i] do  Begin
      m_swID    := FieldByName('m_swID').AsInteger;
      m_sTime   := FieldByName('m_sTime').AsDateTime;
      m_swVMID  := FieldByName('m_swVMID').AsInteger;
      m_swTID   := FieldByName('m_swTID').AsInteger;
      m_swCMDID := FieldByName('m_swCMDID').AsInteger;
      m_sfValue := FieldByName('m_sfValue').AsFloat;
      Next;
      Inc(i);
     End;
    End;
    End;
    FDB.CloseQry;
    Result := res;
End;
function CDBQuerys.loadAbons(var pTable:SL3ABONS):boolean;
Var
    i,j : Integer;
    res : boolean;
Begin
    res := false;
    if (GetAbonsTable(pTable)=true) then
    Begin
     for i:=0 to pTable.Count-1 do
     Begin
      GetAbonVMetersTable(pTable.Items[i].m_swABOID,-1,pTable.Items[i].ItemVM);
      //with pTable.Items[i].ItemVM do
      Begin
       for j:=0 to pTable.Items[i].ItemVM.Count-1 do
       Begin
        GetCData(pTable.Items[i].ItemVM.Items[j].m_swVMID,-1,pTable.Items[i].ItemVM.Items[j].ItemCD);
        res := True;
       End
      End;
     End;
    End;
End;
{
SCHANN = packed record
     m_nScID : Integer;
     m_nAsID : Integer;
     m_dbVal : double;
    End;
    PSCHANN
}
//function CDBQuerys.getValue(var pTable:SCHANNS):boolean;
function CDBQuerys.getValue(var pTable:TList):boolean;
Var
    i,j,nCount : Integer;
    strSQL,sP : String;
    res : boolean;
    pT : SCHANN;
Begin
    try
    sP := '';
    if pTable.count=0 then Begin result:=false;exit;End;
    for i:=0 to pTable.count-1 do
    Begin
     if i=0  then sP := sP + ' WHERE m_swID='+ IntToStr(SCHANN(pTable.items[i]^).m_nAsID) else
     if i<>0 then sP := sP + ' or m_swID='+ IntToStr(SCHANN(pTable.items[i]^).m_nAsID);
    End;
    strSQL := 'SELECT distinct m_swID,m_sfValue FROM L3CURRENTDATA '+sP+' ORDER BY m_swID';
    res := False;
    if FDB.OpenQry(strSQL,nCount)=True then
    Begin
    i := 0;
    res := True;
    while not FDB.FADOQuery.Eof do Begin
      with FDB.FADOQuery,pT do  Begin
      m_nAsID   := FieldByName('m_swID').AsInteger;
      m_sfValue := FieldByName('m_sfValue').AsFloat;
      for j:=0 to pTable.count-1 do
       if SCHANN(pTable.items[j]^).m_nAsID=m_nAsID then
          SCHANN(pTable.items[j]^).m_sfValue := m_sfValue;
      Next;
      Inc(i);
     End;
    End;
    End;
    FDB.CloseQry;
    Result := res;
    except
      FDB.Disconnect;
      FDB.Connect;
    end;
End;
end.