unit plabon;

interface
uses 
     pldbQwery,utltype;
type
     CAbon = class
     private
      FDB  : CDBQuery;
      nUSPDID : Integer;
      pTbl : SL3ABON;
     public
      constructor Create(nUSPDID:Integer;pTbl:SL3ABON);
      destructor Destroy;
      procedure OnExpired;
      procedure Init;
      property PDB : CDBQuery read FDB write FDB;
      procedure Start;
      procedure Stop;
      procedure Run;
      procedure HandQuery;
     end;
     PCAbon =^ CAbon;
implementation
constructor CAbon.Create(nUSPDID:Integer;pTbl:SL3ABON);
Begin
    self.nUSPDID := nUSPDID;
    self.pTbl := pTbl;
End;
destructor CAbon.Destroy;
Begin

End;
procedure CAbon.Init;
Begin

End;
procedure CAbon.Start;
Begin

End;
procedure CAbon.Stop;
Begin

End;
procedure CAbon.HandQuery;
Begin

End;
procedure CAbon.OnExpired;
Begin

End;
procedure CAbon.Run;
Begin

End;
end.