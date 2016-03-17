unit plascues;

interface
uses
     classes,Sysutils,forms,utltype,pluspd,plascuegr,pldbQwery,pldbquerys,
     plchannbase,plchanned,bnrscad,Graphics;
type
     CAscues = class(CAscuesGr)
     private
      mlAscue : TList;
      //pA    : TList;
      pAbon : TList;
      FCE   : CChannEdit;
      FCT   : CChannBase;
      FScada : CScadaDrv;
     private
      function addTable(pTbl:SQWERYMDL):boolean;override;
      function getTable(var pTbl:TList):boolean;override;

      procedure cloneTable(ID:Integer);override;
      procedure delRecord(ID:Integer);override;
      //function :TList;
      procedure loadTree;
      function getAbon(pTbl:SQWERYMDL):PSL3USPDS;
      procedure OnEditSave(pL:TList);
      procedure DBEvent(nID,nCause:Integer;strCause:String);
     public
      procedure run;
      procedure OnEditChannels;
      procedure OnRefreshTree;
      constructor Create;
      destructor Destroy;
      procedure init;
      procedure loadChannels;
      procedure createSystem;
      function getAbons:TList;
      procedure OnExecSql(pTI:CTreeIndex);
      procedure flushTable;override;
     public
      property PCE : CChannEdit read FCE write FCE;
      property PCT : CChannBase read FCT write FCT;
      property PScada : CScadaDrv read FScada write FScada;
      //property PCB : TList      read pA  write pA;
     end;
implementation
constructor CAscues.Create;
Begin
     mlAscue := TList.Create;
     //pA := TList.Create;
     pAbon := TList.Create;
End;
destructor CAscues.Destroy;
Begin
     mlAscue.Clear;
     mlAscue.Destroy;
End;
procedure CAscues.init;
Var
     i : Integer;
Begin
     for i:=0 to mlAscue.Count-1 do CUspd(mlAscue.Items[i]^).destroy;
     mlAscue.clear;
     loadChannels;
     createSystem;
end;
procedure CAscues.loadChannels;
Begin
     FCT.loadFromFile(ExtractFilePath(Application.ExeName)+'\PLASCUE\ascue.ini');
     InitGrid(FCT.Count);
     OnLoadGrid;
End;
procedure CAscues.cloneTable(ID:Integer);
Begin
End;
procedure CAscues.OnEditChannels;
Begin
     if Assigned(FCE.PSaveEV)=true then exit;
     OnRefreshTree;
End;
procedure CAscues.OnRefreshTree;
Begin
     pAbon.clear; //?
     FCE.PSaveEV := OnEditSave;
     FCE.PDT     := getAbons;
     FCE.load;
End;
procedure CAscues.OnEditSave(pL:TList);
Begin
     //
End;
function CAscues.getAbons:TList;
Var
     i:Integer;
     pTbl : SQWERYMDL;
Begin
     for i:=0 to FCT.Count-1 do
     Begin
      pAbon.Add(getAbon(FCT.getItem(i)));
       result := pAbon;
     End;
End;
procedure CAscues.loadTree;
Begin

End;
function CAscues.getAbon(pTbl:SQWERYMDL):PSL3USPDS;
Var
     pC : CDBQuery;
     pD : CDBQuerys;
     pT : PSL3USPDS;
Begin
     result := nil;
     if pTbl.m_sbyState=0 then
     Begin
      new(pT);
      pT^.m_nAbons.Count := 1;
      SetLength(pT^.m_nAbons.Items,1);
      pT^.m_sName := 'УСПД отключено';
      pT^.m_nAbons.Items[0].m_sName := 'Объект';
      pT^.m_nAbons.Items[0].m_sObject := 'Отключен';
      pT^.m_nAbons.Items[0].m_sbyVisible := 1;
      result := pT;
      exit;
     End;
     pC := CDBQuery.Create(pTbl.m_sDBConnection);
     pC.PPIngIP := pTbl.m_nPingIP;
     pC.PNevent := DBEvent;
     pC.PAscueID:= pTbl.m_snID;
     pD := CDBQuerys.Create;
     pD.PDB := pC;
     //SendDebug('IP-ADDr0:'+pC.PPIngIP+' ID:'+IntToStr(pTbl.m_snID)+' CN:'+pTbl.m_sDBConnection);
     if pC.ping=true then
     Begin
      //SendDebug('IP-ADDr3:'+pC.PPIngIP+' ID:'+IntToStr(pTbl.m_snID));
      new(pT);
      pT^.m_nSID  := pTbl.m_snID;
      pT^.m_sName := pTbl.m_sAscueName;
      pD.loadAbons(pT^.m_nAbons);
      result := pT;
     End else
     Begin
      new(pT);
      pT^.m_nAbons.Count := 1;
      SetLength(pT^.m_nAbons.Items,1);
      pT^.m_sName := 'УСПД отключено';
      pT^.m_nAbons.Items[0].m_sName := 'Объект';
      pT^.m_nAbons.Items[0].m_sObject := 'Отключен';
      pT^.m_nAbons.Items[0].m_sbyVisible := 1;
      result := pT;
      exit;
     End;
     pD.Destroy;
     pC.Destroy; 
End;
function CAscues.addTable(pTbl:SQWERYMDL):boolean;
Begin
     result := FCT.addTable(pTbl);
End;
procedure CAscues.flushTable;
Begin
     FCT.flushTable;
End;
procedure CAscues.delRecord(ID:Integer);    //erwe
Begin
      FCT.deleteSection(FCT.getItem(ID));
      FCT.delItem(ID);
      flushTable;
End;
function CAscues.getTable(var pTbl:TList):boolean;
Begin
     pTbl   := FCT.GetBuff;
     result := true;
End;
procedure CAscues.createSystem;
Var
     i  : Integer;
     pU : PCUspd;
Begin
     for i:=0 to FCT.Count-1 do
     Begin
      new(pU);
      pU^         := CUspd.Create(FCT.getPItem(i));
      pU^.PDB     := CDBQuerys.Create;
      pU^.PDB.PDB := CDBQuery.Create(FCT.getItem(i).m_sDBConnection);
      pU^.PDB.PDB.PPIngIP := FCT.getItem(i).m_nPingIP;
      pU^.PDB.PDB.PNevent := DBEvent;
      pU^.PDB.PDB.PAscueID:= FCT.getItem(i).m_snID;
      pU^.Init;
      pU^.PScada  := FScada;
      mlAscue.Add(pU);
     End;
End;
procedure CAscues.DBEvent(nID,nCause:Integer;strCause:String);
Begin
     if nCause=0 then SetAlarmColor(nID+1,clLime) else
     if nCause=1 then SetAlarmColor(nID+1,clRed);
End;
procedure CAscues.OnExecSql(pTI:CTreeIndex);
Var
     i : Integer;
     pU : PCUspd;
Begin
     //SendDebug('('+IntToStr(pTI.PRID)+')CAscues :'+IntToStr(mlAscue.count));
     if (pTI.PRID<=(mlAscue.count-1)) then
     Begin
      pU := mlAscue.Items[pTI.PRID];
      pU^.OnExpired;
     End;
End;
procedure CAscues.run;
Var
     i:Integer;
     pU : PCUspd;
Begin
     for i:=0 to FCT.Count-1 do
     Begin
      //SendDebug('('+IntToStr(i)+')CAscues.run.');
      pU := mlAscue.Items[i];
      pU^.run;
     End;
End;
end.
