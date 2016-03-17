unit pluspd;

interface
uses
     plqwery,pldbquerys,utltype,classes,plabon,bnrscad,stdctrls,Sysutils;
type
     CUspd = class(CTimeMDL)
     private
       FDB    : CDBQuerys;
       //mlAbon : TList;
       pSTbl  : PSQWERYMDL;
       FScada : CScadaDrv;
     public
       Memo   : TMemo;
     private
      procedure createAbons;
      procedure loadAbons;
      procedure SendToScada;
     public
      constructor Create(pSTbl:PSQWERYMDL);
      destructor Destroy;
      procedure OnExpired; override;
      procedure Init;
      procedure Start;
      procedure Stop;
      procedure Run;
      //procedure HandQuery;
     public
      property PDB : CDBQuerys read FDB write FDB;
      property PScada : CScadaDrv read FScada write FScada;
     end;
     PCUspd = ^CUspd;
implementation
constructor CUspd.Create(pSTbl:PSQWERYMDL);
Begin
     self.pSTbl := pSTbl;
     //mlAbon     := Tlist.Create;
End;
destructor CUspd.Destroy;
Begin
    //mlAbon.Clear;
    //mlAbon.Destroy;
End;
procedure CUspd.createAbons;
Begin
End;
procedure CUspd.loadAbons;
Begin
     //if FDB.loadAbons(pTbl)=true then
End;
procedure CUspd.Init;
Begin
     inherited Init(pSTbl^);
End;
procedure CUspd.Start;
Begin
End;
procedure CUspd.Stop;
Begin
End;
procedure CUspd.OnExpired;
Begin
     //SendDebug('('+IntToStr(pSTbl^.m_snID)+')CAscues.OnExpired.');
     //Memo.Lines.Add('('+IntToStr(pSTbl^.m_snID)+')CAscues.OnExpired.');
     PDB.getValue(pSTbl^.m_lChann);
     SendToScada;
End;
procedure CUspd.SendToScada;
Var
     i  : Integer;
     pC : PSCHANN;
Begin
     for i:=0 to pSTbl^.m_lChann.Count-1 do
     Begin
      pC := pSTbl^.m_lChann.Items[i];
      FScada.SendToScadaFL(pC^.m_nScID,pC^.m_sfValue);
     End;
End;
procedure CUspd.Run;
Begin
     inherited run;
End;
end.
