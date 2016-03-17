unit pldatabase;

interface
uses
     Db, ADODB;
type
     CDataBase = class
     private
      strConnection : String;
      FADOConnection : TADOConnection;
     public
      constructor Create(strConnection:String);
      destructor Destroy;
      function Connect:TADOConnection;
      procedure Disconnect;
     public
      property PConn : TADOConnection   read FADOConnection write FADOConnection;
     end;
implementation
constructor CDataBase.Create(strConnection:String);
begin
     self.strConnection := strConnection;
end;
destructor CDataBase.Destroy;
begin
     Disconnect;
end;
function CDataBase.Connect:TADOConnection;
Begin
    try
     if FADOConnection=Nil then
     Begin
      FADOConnection := TADOConnection.Create(Nil);
      FADOConnection.ConnectionString := strConnection;
      FADOConnection.LoginPrompt      := False;
      FADOConnection.Connected        := true;
      result := FADOConnection;
     End;
    except
      result := nil;
    end;
End;
procedure CDataBase.Disconnect;
Begin
    try
     if FADOConnection<>Nil then
     Begin
      FADOConnection.Destroy;
      FADOConnection := Nil;
     End;
    except

    end;
End;
end.
