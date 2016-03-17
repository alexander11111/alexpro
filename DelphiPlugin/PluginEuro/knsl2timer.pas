unit knsl2timer;
interface
uses
     Windows, Classes, SysUtils,SyncObjs,stdctrls,plascues;

type
     CTimerThread = class(TThread)
     private
     { Private declarations }
      w_mEvent1 : THandle;
      sCS1    : TCriticalSection;
      dwCount : Dword;
     public
      pA      : CAscues;
     procedure OnHandler;
     procedure OnSpeedHandler;
     protected
     procedure Execute; override;
     end;
implementation
procedure CTimerThread.OnHandler;
Begin
     //TraceL(2,0,'(__)CTMMD::>Timer Empty 1 sec');
     if pA<>Nil then pA.Run;
End;
procedure CTimerThread.OnSpeedHandler;
Var
     i : Integer;
Begin
     //for i:=0 to m_nDIO.Count-1 do m_nDIO.Items[i].Run;
     //mL2Module.DoHalfSpeedTime(Nil);
End;
procedure CTimerThread.Execute;
Begin
     sCS1 := TCriticalSection.Create;
     w_mEvent1 := CreateEvent(nil, False, False, nil);
     while True do
     Begin
      WaitForSingleObject(w_mEvent1,1000);
      Synchronize(OnHandler);
      dwCount := dwCount + 1;
     End;
End;
end.
