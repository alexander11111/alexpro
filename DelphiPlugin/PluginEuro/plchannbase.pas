unit plchannbase;

interface
uses
     classes,utltype,inifiles,Sysutils,forms,pldbquerys;
type
     CChannBase = class
     private
      FCB : TList;
      FBD : CDBQuerys;
     private
      function LoadSettings(i:Integer):PSQWERYMDL;
      procedure saveSettings(pTbl:SQWERYMDL);
      procedure saveAmChann(ID,nCount:Integer);
      procedure saveDBChannels(i:Integer;m_lChann:TList);
      procedure loadDBChannels(i,nCount:Integer;m_lChann:TList);
     public
      constructor create;
      destructor destroy;
      procedure deleteSection(pTbl:SQWERYMDL);
      procedure delChannels(ID:Integer);
      procedure delChannel(ID,nCHID:Integer);
      procedure addChannels(nSID:Word;pC:PSCHANN);
      procedure loadFromFile(strFileName:String);
      function addTable(pTbl:SQWERYMDL):boolean;
      function getItem(i:Integer):SQWERYMDL;
      function getPItem(i:Integer):PSQWERYMDL;
      function getItemChann(nSID:Word;nAsID:Integer;var pLC:SCHANN):boolean;
      procedure delItem(i:Integer);
      function GetBuff:TList;
      procedure flushTable;
      function Count:Integer;
      function getValue(ID:Integer):boolean;
     public
      property PCB : TList     read FCB write FCB;
      property PBD : CDBQuerys read FBD write FBD;
     end;
implementation
constructor CChannBase.create;
Begin
     FCB := TList.create;
End;
destructor CChannBase.destroy;
Begin
End;
function CChannBase.Count:Integer;
Begin
     result := FCB.Count;
End;
procedure CChannBase.addChannels(nSID:Word;pC:PSCHANN);
Var
     pLC : PSCHANN;
     pTC : TList;
     i   : Integer;
Begin
     if nSID>(FCB.Count-1) then exit;
     if (pC^.m_nScID=-1)then exit;
     pTC := SQWERYMDL(FCB.Items[nSID]^).m_lChann;
     for i:=0 to pTC.Count-1 do
     Begin
      pLC := pTC.Items[i];
      if {(pLC^.m_nScID=pC^.m_nScID)and}(pLC^.m_nAsID=pC^.m_nAsID) then
      Begin
       move(pC^,pLC^,sizeof(SCHANN));
       exit;
      End;
     End;
     pTC.Add(pC);
     //SQWERYMDL(FCB.Items[nSID]^).m_nAmChannel := SQWERYMDL(FCB.Items[nSID]^).m_nAmChannel + 1;  
End;
function CChannBase.getItemChann(nSID:Word;nAsID:Integer;var pLC:SCHANN):boolean;
Var
     //pLC : SCHANN;
     pTC : TList;
     i   : Integer;
Begin
     result := false;
     if nSID>(FCB.Count-1) then exit;
     pTC := SQWERYMDL(FCB.Items[nSID]^).m_lChann;
     for i:=0 to pTC.Count-1 do
     Begin
      pLC := SCHANN(pTC.Items[i]^);
      //move(pTC.Items[i]^,pLC,sizeof(SCHANN));
      if (pLC.m_nAsID=nAsID) then
      Begin
       result := true;
       exit;
      End;
     End;
End;
function CChannBase.getItem(i:Integer):SQWERYMDL;
Begin
     result := SQWERYMDL(FCB.Items[i]^);
End;
function CChannBase.getPItem(i:Integer):PSQWERYMDL;
Begin
     result := PSQWERYMDL(FCB.Items[i]);
End;
procedure CChannBase.delItem(i:Integer);
Begin
     if (i>(count-1)) then exit;
     FCB.Delete(i);
End;
function CChannBase.GetBuff:TList;
Begin
    result := FCB;
End;
procedure CChannBase.loadFromFile(strFileName:String);
Var
     Fl : TINIFile;
     str : String;
     i,nMaxAscue:Integer;
Begin
     Fl := TINIFile.Create(strFileName);
     nMaxAscue := Fl.ReadInteger('SYSTEMSET','m_nMaxAscue',0);
     FCB.Clear;
     for i:=0 to nMaxAscue-1 do
     FCB.Add(LoadSettings(i));
     Fl.Destroy;
End;
function CChannBase.addTable(pTbl:SQWERYMDL):boolean;
Var
     res : boolean;
     pL  : TList;
     pT  : PSQWERYMDL;
Begin
     res := false;
     if pTbl.m_snID<0 then
     Begin
      Result := res;
      exit;
     End else
     if (pTbl.m_snID>(FCB.Count-1)) then
     Begin
      res := true;
      new(pT);
      pTbl.m_nAmChannel := 0;
      pTbl.m_lChann := nil;
      pT^ := pTbl;
      FCB.add(pT);
     End else
     Begin
      pL := SQWERYMDL(FCB.Items[pTbl.m_snID]^).m_lChann;
      move(pTbl,FCB.Items[pTbl.m_snID]^,sizeof(pTbl));
      SQWERYMDL(FCB.Items[pTbl.m_snID]^).m_lChann := pL;
     end;
     result := res;
End;
function CChannBase.LoadSettings(i:Integer):PSQWERYMDL;
Var
    strPath : String;
    Fl      : TINIFile;
    pC      : PSCHANN;
    j       : Integer;
    pTbl    : PSQWERYMDL;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascue.ini';
    try
    Fl := TINIFile.Create(strPath);
    new(pTbl);
    pTbl^.m_lChann := nil;
    with pTbl^ do
    Begin
     m_snID         := i;
     m_sbyPause     := 0;
     m_sdtBegin     := StrToTime(Fl.ReadString('ASCUE'+IntTostr(i),'m_sdtBegin',TimeToStr(Now)));
     m_sdtEnd       := StrToTime(Fl.ReadString('ASCUE'+IntTostr(i),'m_sdtEnd',TimeToStr(Now)));
     m_sdtPeriod    := StrToTime(Fl.ReadString('ASCUE'+IntTostr(i),'m_sdtPeriod',TimeToStr(Now)));
     m_swDayMask    := Fl.ReadInteger('ASCUE'+IntTostr(i),'m_swDayMask',0);
     m_sdwMonthMask := Fl.ReadInteger('ASCUE'+IntTostr(i),'m_sdwMonthMask',0);
     m_nAmChannel   := Fl.ReadInteger('ASCUE'+IntTostr(i),'m_nAmChannel',0);
     m_sbyEnable    := Fl.ReadInteger('ASCUE'+IntTostr(i),'m_sbyEnable',0);
     m_sAscueName   := Fl.ReadString('ASCUE'+IntTostr(i),'m_sAscueName','');
     m_sDBConnection:= Fl.ReadString('ASCUE'+IntTostr(i),'m_sDBConnection','');
     m_sbyState     := Fl.ReadInteger('ASCUE'+IntTostr(i),'m_sbyState',0);
     m_nPingIP      := Fl.ReadString('ASCUE'+IntTostr(i),'m_nPingIP','0.0.0.0');
     if (m_lChann=nil) then m_lChann := TList.Create else m_lChann.clear;
     loadDBChannels(i,m_nAmChannel,m_lChann);
    End;
    Fl.Destroy;
    except
     Fl.Destroy;
    end;
    Result := pTbl;
End;
procedure CChannBase.saveSettings(pTbl:SQWERYMDL);
Var
    strPath : String;
    Fl      : TINIFile;
    i     : Integer;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascue.ini';
    try
    Fl := TINIFile.Create(strPath);
    with pTbl do
    Begin
     i := m_snID;
     Fl.WriteString('ASCUE'+IntTostr(i),'m_sAscueName',m_sAscueName);
     Fl.WriteString('ASCUE'+IntTostr(i),'m_sDBConnection',m_sDBConnection);
     Fl.WriteString('ASCUE'+IntTostr(i),'m_sdtBegin',TimeToStr(m_sdtBegin));
     Fl.WriteString('ASCUE'+IntTostr(i),'m_sdtEnd',TimeToStr(m_sdtEnd));
     Fl.WriteString('ASCUE'+IntTostr(i),'m_sdtPeriod',TimeToStr(m_sdtPeriod));
     Fl.WriteInteger('ASCUE'+IntTostr(i),'m_swDayMask',m_swDayMask);
     Fl.WriteInteger('ASCUE'+IntTostr(i),'m_sdwMonthMask',m_sdwMonthMask);
     Fl.WriteInteger('ASCUE'+IntTostr(i),'m_sbyEnable',m_sbyEnable);
     Fl.WriteInteger('ASCUE'+IntTostr(i),'m_nAmChannel',m_nAmChannel);
     Fl.WriteInteger('ASCUE'+IntTostr(i),'m_sbyState',m_sbyState);
     Fl.WriteString('ASCUE'+IntTostr(i),'m_nPingIP',m_nPingIP);
     if (m_lChann<>nil) then
     Begin
      m_nAmChannel := m_lChann.Count;
      Fl.WriteInteger('ASCUE'+IntTostr(i),'m_nAmChannel',m_nAmChannel);
      saveDBChannels(i,m_lChann);
     End;
    End;
    Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
procedure CChannBase.saveAmChann(ID,nCount:Integer);
Var
    strPath : String;
    Fl      : TINIFile;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascue.ini';
    try
    Fl := TINIFile.Create(strPath);
    Fl.WriteInteger('ASCUE'+IntTostr(ID),'m_nAmChannel',nCount);
    Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
procedure CChannBase.loadDBChannels(i,nCount:Integer;m_lChann:TList);
Var
    pC : PSCHANN;
    j  : Integer;
    strPath : String;
    Fl : TINIFile;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascuedb'+IntToStr(i)+'.ini';
    try
     Fl := TINIFile.Create(strPath);
      for j:=0 to nCount-1 do
      Begin
       New(pC);
       pC^.m_sfValue := 0;
       pC^.m_nScID := Fl.ReadInteger('AS'+IntTostr(i)+'CH'+IntTostr(j),'m_nScID',0);
       pC^.m_nAsID := Fl.ReadInteger('AS'+IntTostr(i)+'CH'+IntTostr(j),'m_nAsID',0);
       m_lChann.add(pC);
      End;
     Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
procedure CChannBase.saveDBChannels(i:Integer;m_lChann:TList);
Var
    pC : PSCHANN;
    j  : Integer;
    strPath : String;
    Fl : TINIFile;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascuedb'+IntToStr(i)+'.ini';
    try
     Fl := TINIFile.Create(strPath);
     for j:=0 to m_lChann.Count-1 do
     Begin
      pC := m_lChann.Items[j];
      Fl.WriteInteger('AS'+IntTostr(i)+'CH'+IntTostr(j),'m_nScID',pC^.m_nScID);
      Fl.WriteInteger('AS'+IntTostr(i)+'CH'+IntTostr(j),'m_nAsID',pC^.m_nAsID);
     End;
     Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
procedure CChannBase.flushTable;
Var
    Fl : TINIFile;
    strFileName,str : String;
    i:Integer;
Begin
    strFileName := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascue.ini';
    Fl := TINIFile.Create(strFileName);
    Fl.WriteInteger('SYSTEMSET','m_nMaxAscue',FCB.count);
    Fl.Destroy;
    for i:=0 to FCB.count-1 do
    saveSettings(SQWERYMDL(FCB.Items[i]^));
    //loadDBConnection;
End;
procedure CChannBase.deleteSection(pTbl:SQWERYMDL);
Var
    strPath : String;
    Fl      : TINIFile;
    pC      : PSCHANN;
    j,i     : Integer;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascue.ini';
    try
    Fl := TINIFile.Create(strPath);
    with pTbl do
    Begin
     i := m_snID;
     Fl.EraseSection('ASCUE'+IntTostr(i));
     delChannels(i);
    End;
    Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
procedure CChannBase.delChannels(ID:Integer);
Var
    pC : PSCHANN;
    j,nAmChann  : Integer;
    strPath : String;
    Fl : TINIFile;
    m_lChann : TList;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascuedb'+IntToStr(ID)+'.ini';
    try
     Fl := TINIFile.Create(strPath);
     m_lChann := SQWERYMDL(FCB.items[ID]^).m_lChann;
     if (m_lChann<>nil) then
     Begin
      nAmChann := SQWERYMDL(FCB.items[ID]^).m_nAmChannel-m_lChann.Count;
      if (nAmChann<0) then nAmChann:=0;
      saveAmChann(ID,nAmChann);
      for j:=0 to m_lChann.Count-1 do
      Begin
       pC := m_lChann.Items[j];
       Fl.EraseSection('AS'+IntTostr(ID)+'CH'+IntTostr(j));
      End;
      m_lChann.clear;
     End;
     Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
procedure CChannBase.delChannel(ID,nCHID:Integer);
Var
    pC : PSCHANN;
    j,k,nAmChann  : Integer;
    strPath : String;
    Fl : TINIFile;
    m_lChann : TList;
Begin
    strPath := ExtractFilePath(Application.ExeName)+'\PLASCUE\ascuedb'+IntToStr(ID)+'.ini';
    try
     Fl := TINIFile.Create(strPath);
     m_lChann := SQWERYMDL(FCB.items[ID]^).m_lChann;
     if (m_lChann<>nil) then
     Begin
      for j:=0 to m_lChann.Count-1 do
      Begin
       pC := m_lChann.Items[j];
       if pC.m_nAsID=nCHID then
       Begin
        for k:=0 to m_lChann.Count-1 do Fl.EraseSection('AS'+IntTostr(ID)+'CH'+IntTostr(k));
        m_lChann.Delete(j);
        Fl.Destroy;
        saveSettings(SQWERYMDL(FCB.Items[ID]^));
        exit;
       End;
      End;
     End;
     Fl.Destroy;
    except
     Fl.Destroy;
    end;
End;
function CChannBase.getValue(ID:Integer):boolean;
Var
    pL : TList;
Begin
    if ID>(FCB.count-1) then
    Begin
     result:=false;
     exit;
    End;
    pL := SQWERYMDL(FCB.items[ID]^).m_lChann;
    result := PBD.getValue(pL);
End;

end.
