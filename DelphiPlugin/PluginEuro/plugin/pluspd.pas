unit pluspd;

interface
uses
     plqwery,Sysutils,pldbquerys,utltype,classes,plabon,bnrscad,DbugIntF;
type
     CUspd = class(CTimeMDL)
     private
       FDB    : CDBQuerys;
       //mlAbon : TList;
       pSTbl   : PSQWERYMDL;
       FScada  : CScadaDrv;
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
     PDB.getValue(pSTbl^.m_lChann);
     SendToScada;
End;
procedure CUspd.SendToScada;
Var
     i  : Integer;
     pC : PSCHANN;
     nH,nM,nS,nMS : Word;
Begin
     try
     for i:=0 to pSTbl^.m_lChann.Count-1 do
     Begin
      pC := pSTbl^.m_lChann.Items[i];
      if FScada<>Nil then
      Begin
        DecodeTime(pSTbl.m_sdtPeriod,nH,nM,nS,nMS);
        FScada.PPeriod := 2*((3600*nH+60*nM+nS)*10);
        //SendDebug('Ref Time:'+IntToStr(FScada.PPeriod));
        FScada.SendToScadaFL(pC^.m_nScID,pC^.m_sfValue);
      End;
     End;
     except

     end
End;
procedure CUspd.Run;
Begin
     inherited run;
End;
end.
