unit pldbQwery;

interface
uses
     Db, ADODB,IdIcmpClient,DbugIntF,IniFiles,classes,Sysutils;
type
     TNotifyEvent = procedure(nID,nCause:Integer;strCause:String) of object;
     CDBQuery = class
     private
      strConnection : String;
      m_blIsConnect : boolean;
      m_nPing       : TIdIcmpClient;
      FPIngIP       : String;
      FNevent       : TNotifyEvent;
      FAscueID      : Integer;
      m_sBasePath   : String;
     public
      FADOQuery : TADOQuery;
     private
      procedure OnPingRes(ASender:TComponent;const AReplyStatus:TReplyStatus);
      function getBaseBath(strConn:String):String;
      function getSaveBasePropPath(stpPath:String): integer;
     public
      constructor Create(strConnection:String);
      destructor Destroy;
      function Connect:boolean;
      procedure Disconnect;
      function ExecQry(strSQL:String):Boolean;
      function OpenQry(strSQL:String;var nCount:Integer):Boolean;
      procedure CloseQry;
      function Ping:boolean;
     public
      property PPIngIP : String read FPIngIP write FPIngIP;
      property PAscueID: Integer read FAscueID write FAscueID;
      property PNevent : TNotifyEvent read FNevent write FNevent;
     end;
implementation
constructor CDBQuery.Create(strConnection:String);
begin
     FADOQuery := Nil;
     m_sBasePath := getBaseBath(strConnection)+'\Settings\USPD_Config.ini';
     m_blIsConnect := false;
     self.strConnection := strConnection;
     if m_nPing=Nil then m_nPing := TIdIcmpClient.Create(nil);
     m_nPing.OnReply := OnPingRes;
     Connect;
end;
destructor CDBQuery.Destroy;
begin
     Disconnect;
     m_nPing.Destroy;
end;
function CDBQuery.Connect:boolean;
Begin
    try
     //if Ping=false then Begin result:=false;Exit;End;
     if FADOQuery<>Nil then Disconnect;
     if FADOQuery=Nil then
     Begin
      FADOQuery := TADOQuery.Create(Nil);
      FADOQuery.ConnectionString := strConnection;
      //FADOQuery.Connection := FADOConnection;
      result := true;
      m_blIsConnect := true;
     End;
    except
      m_blIsConnect := false;
      result := false;
    end;
End;
procedure CDBQuery.Disconnect;
Begin
    m_blIsConnect := false;
    try
     if FADOQuery<>Nil then
     Begin
      FADOQuery.Destroy;
      FADOQuery := Nil;
     End;
    except

    end;
End;
function CDBQuery.Ping:boolean;
Var
     res : boolean;
Begin
     try
      res := true;
      //SendDebug('DB FPIngIP:'+FPIngIP);
      if (FPIngIP<>'0.0.0.0')or(m_nPing<>nil) then
      Begin
       {
       m_nPing.Host := FPIngIP;
       m_nPing.TTL:=128;
       m_nPing.ReceiveTimeout := 1000;
       m_nPing.Host := FPIngIP;
       m_nPing.Ping('32');
       if m_nPing.ReplyStatus.FromIpAddress<>FPIngIP then
          res := false;
       if m_nPing.ReplyStatus.ReplyStatusType<>rsEcho then
          res := false;
       if res=false then Begin Disconnect;end;
       if (res=true) then
       }
       if getSaveBasePropPath(m_sBasePath)=1 then
       Begin
          res := false;
          if Assigned(FNevent) then FNevent(FAscueID,1,'ERROR');
       End;
      End;
      result := res;
     except
       on e:exception do
       Begin
        SendDebug('CDBQuery.Ping: '+FPIngIP+' Error!:'+e.Message);
        if Assigned(FNevent) then FNevent(FAscueID,1,'ERROR');
        result := false;
        Disconnect;
       End;
     end;

End;
procedure CDBQuery.OnPingRes(ASender:TComponent;const AReplyStatus:TReplyStatus);
Begin
     if AReplyStatus.ReplyStatusType=rsEcho then
     Begin
      if Assigned(FNevent) then FNevent(FAscueID,0,'SUCCESS');
     End;
     if AReplyStatus.ReplyStatusType=rsTimeOut then
      if Assigned(FNevent) then FNevent(FAscueID,1,'ERROR');
End;
function CDBQuery.ExecQry(strSQL:String):Boolean;
Var
    res : Boolean;
Begin
    res := True;
    if Ping=false then Begin result:=false;Exit;End;
    if m_blIsConnect=False then Begin Result := False;exit;End;
    try
     FADOQuery.Close;
     FADOQuery.SQL.Clear;
     FADOQuery.SQL.Add(strSQL);
     FADOQuery.ExecSQL;
     FADOQuery.Close;
   except
    res := False;
      //FADOQuery := TADOQuery.Create(Nil);
      //FADOQuery.ConnectionString := strConnection;
      //Disconnect;
      //Connect;
      FADOQuery := TADOQuery.Create(Nil);
      FADOQuery.ConnectionString := strConnection;
   end;
   Result := res;
End;
function CDBQuery.OpenQry(strSQL:String;var nCount:Integer):Boolean;
Var
    res : Boolean;
Begin
    res    := False;
    nCount := 0;
    if Ping=false then Begin result:=false;Exit;End;
    //SendDebug('SendSL:'+strSQL);
    if m_blIsConnect=False then Begin Result := False;exit;End;
    try
     //FADOQuery.Active := True;
     FADOQuery.SQL.Clear;
     FADOQuery.SQL.Add(strSQL);
     FADOQuery.Open;
     if FADOQuery.RecordCount>0 then  Begin nCount := FADOQuery.RecordCount; res := True;End;
    except
     res := False;
     //Disconnect;
     //Connect;
     //if FADOQuery<>Nil then FADOQuery.Destroy;
     FADOQuery := TADOQuery.Create(Nil);
     FADOQuery.ConnectionString := strConnection;
    end;
    Result := res;
End;
procedure CDBQuery.CloseQry;
Begin
    if m_blIsConnect=False then exit;
    //FADOQuery.Active := False;
    FADOQuery.Close;
End;
function CDBQuery.getSaveBasePropPath(stpPath:String): integer;
Var
    Fl : TIniFile;
Begin
    result := 0;
    try
     Fl  := TINIFile.Create(stpPath);
     //Fl  := TINIFile.Create(ExtractFilePath(Application.ExeName)+'\\Settings\\USPD_Config.ini');
     if Fl.ValueExists('DBCONFIG','m_nDBSave')=true then
     result := Fl.ReadInteger('DBCONFIG','m_nDBSave', 0);
     Fl.Destroy;
    except
     Fl.Destroy;
     result := 0;
    end;
End;
function CDBQuery.getBaseBath(strConn:String):String;
Var
    nIndex : Integer;
    strB   : String;
Begin
    try
     if (strConn='') then Begin result := 'c:\a2000\ascue\';exit;End;
     nIndex := pos('DbName=',strConn);
     strB   := Copy(strConn,nIndex+7,Length(strConn)-(nIndex-7));
     strB   := StringReplace(strB,'\SYSINFOAUTO.FDB','',[rfReplaceAll]);
     nIndex := pos('c:',strB);
     if (nIndex<>0) then
     Begin
      if nIndex<>1 then strB := '\\'+StringReplace(strB,':c:','\',[rfReplaceAll]);
      result := strB;
      exit;
     End;
     nIndex := pos('d:',strB);
     if (nIndex<>0) then
     Begin
      if nIndex<>1 then strB := '\\'+StringReplace(strB,':d:','\',[rfReplaceAll]);
      result := strB;
      exit;
     End;
     nIndex := pos('e:',strB);
     if (nIndex<>0) then
     Begin
      if nIndex<>1 then strB := '\\'+StringReplace(strB,':e:','\',[rfReplaceAll]);
      result := strB;
      exit;
     End;
     nIndex := pos('f:',strB);
     if (nIndex<>0) then
     Begin
      if nIndex<>1 then strB := '\\'+StringReplace(strB,':f:','\',[rfReplaceAll]);
      result := strB;
      exit;
     End;
    except
     result := 'c:\a2000\ascue\';
    end;
End;

end.
