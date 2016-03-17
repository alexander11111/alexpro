# Microsoft Developer Studio Project File - Name="BSCPP" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=BSCPP - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BSCPP.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BSCPP.mak" CFG="BSCPP - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BSCPP - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "BSCPP - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BSCPP - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "BSCPP - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib WS2_32.Lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "BSCPP - Win32 Release"
# Name "BSCPP - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "SensorMode"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bnrdigsensor.c
# End Source File
# Begin Source File

SOURCE=.\bnrdigsensor.h
# End Source File
# Begin Source File

SOURCE=.\bnrdirmodule.c
# End Source File
# Begin Source File

SOURCE=.\bnrdirmodule.h
# End Source File
# Begin Source File

SOURCE=.\bnridlesensor.c
# End Source File
# Begin Source File

SOURCE=.\bnridlesensor.h
# End Source File
# Begin Source File

SOURCE=.\bnringate.c
# End Source File
# Begin Source File

SOURCE=.\bnringate.h
# End Source File
# Begin Source File

SOURCE=.\bnrobserve.c
# End Source File
# Begin Source File

SOURCE=.\bnrobserve.h
# End Source File
# Begin Source File

SOURCE=.\bnroutgate.c
# End Source File
# Begin Source File

SOURCE=.\bnroutgate.h
# End Source File
# Begin Source File

SOURCE=.\bnrsensr.c
# End Source File
# Begin Source File

SOURCE=.\bnrsensr.h
# End Source File
# Begin Source File

SOURCE=.\bnrsmartsensor.c
# End Source File
# Begin Source File

SOURCE=.\bnrsmartsensor.h
# End Source File
# End Group
# Begin Group "KpMode"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bnrcomserver.c
# End Source File
# Begin Source File

SOURCE=.\bnrcomserver.h
# End Source File
# Begin Source File

SOURCE=.\bnrkp.c
# End Source File
# Begin Source File

SOURCE=.\bnrkp.h
# End Source File
# Begin Source File

SOURCE=.\bnrmodule101.c
# End Source File
# Begin Source File

SOURCE=.\bnrmodule101.h
# End Source File
# Begin Source File

SOURCE=.\bnrregedit.c
# End Source File
# Begin Source File

SOURCE=.\bnrregedit.h
# End Source File
# Begin Source File

SOURCE=.\bnrtelecontrol.c
# End Source File
# Begin Source File

SOURCE=.\bnrtelecontrol.h
# End Source File
# Begin Source File

SOURCE=.\bnrteleind.c
# End Source File
# Begin Source File

SOURCE=.\bnrteleind.h
# End Source File
# Begin Source File

SOURCE=.\bnrtelesensor.c
# End Source File
# Begin Source File

SOURCE=.\bnrtelesensor.h
# End Source File
# Begin Source File

SOURCE=.\bnrtelesignal.c
# End Source File
# Begin Source File

SOURCE=.\bnrtelesignal.h
# End Source File
# End Group
# Begin Group "System"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bnradmin.c
# End Source File
# Begin Source File

SOURCE=.\bnradmin.h
# End Source File
# Begin Source File

SOURCE=.\bnrauto.c
# End Source File
# Begin Source File

SOURCE=.\bnrauto.h
# End Source File
# Begin Source File

SOURCE=.\bnrconfig.c
# End Source File
# Begin Source File

SOURCE=.\bnrconst.h
# End Source File
# Begin Source File

SOURCE=.\bnrcyclicsystem.c
# End Source File
# Begin Source File

SOURCE=.\bnrcyclicsystem.h
# End Source File
# Begin Source File

SOURCE=.\bnrdbout.h
# End Source File
# Begin Source File

SOURCE=.\bnrdebug.c
# End Source File
# Begin Source File

SOURCE=.\bnrdebug.h
# End Source File
# Begin Source File

SOURCE=.\bnrflash.c
# End Source File
# Begin Source File

SOURCE=.\bnrflash.h
# End Source File
# Begin Source File

SOURCE=.\bnrhconfig.c
# End Source File
# Begin Source File

SOURCE=.\bnrmain.c
# End Source File
# Begin Source File

SOURCE=.\bnrmain.h
# End Source File
# Begin Source File

SOURCE=.\bnrmysystem.c
# End Source File
# Begin Source File

SOURCE=.\bnrmysystem.h
# End Source File
# Begin Source File

SOURCE=.\bnrmytimer.c
# End Source File
# Begin Source File

SOURCE=.\bnrmytimer.h
# End Source File
# Begin Source File

SOURCE=.\bnrpob.c
# End Source File
# Begin Source File

SOURCE=.\bnrpob.h
# End Source File
# Begin Source File

SOURCE=.\bnrprocmanager.c
# End Source File
# Begin Source File

SOURCE=.\bnrprocmanager.h
# End Source File
# Begin Source File

SOURCE=.\bnrsystemtimer.c
# End Source File
# Begin Source File

SOURCE=.\bnrsystemtimer.h
# End Source File
# End Group
# Begin Group "Computer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bnraninput.c
# End Source File
# Begin Source File

SOURCE=.\bnraninput.h
# End Source File
# Begin Source File

SOURCE=.\bnrcomputer.c
# End Source File
# Begin Source File

SOURCE=.\bnrcomputer.h
# End Source File
# Begin Source File

SOURCE=.\bnrhardpin.c
# End Source File
# Begin Source File

SOURCE=.\bnrhardpin.h
# End Source File
# Begin Source File

SOURCE=.\bnrpin.c
# End Source File
# Begin Source File

SOURCE=.\bnrpin.h
# End Source File
# Begin Source File

SOURCE=.\bnrslide.c
# End Source File
# Begin Source File

SOURCE=.\bnrslide.h
# End Source File
# End Group
# Begin Group "Measure"

# PROP Default_Filter ""
# Begin Group "Device"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bnrcount.c
# End Source File
# Begin Source File

SOURCE=.\bnrcount.h
# End Source File
# Begin Source File

SOURCE=.\bnrdevice.c
# End Source File
# Begin Source File

SOURCE=.\bnrdevice.h
# End Source File
# Begin Source File

SOURCE=.\bnrdevts.c
# End Source File
# Begin Source File

SOURCE=.\bnrdevts.h
# End Source File
# Begin Source File

SOURCE=.\bnrdevtu.c
# End Source File
# Begin Source File

SOURCE=.\bnrdevtu.h
# End Source File
# Begin Source File

SOURCE=.\bnrdvs.c
# End Source File
# Begin Source File

SOURCE=.\bnrdvs.h
# End Source File
# Begin Source File

SOURCE=.\bnrfreq.c
# End Source File
# Begin Source File

SOURCE=.\bnrfreq.h
# End Source File
# Begin Source File

SOURCE=.\bnrlevel.c
# End Source File
# Begin Source File

SOURCE=.\bnrlevel.h
# End Source File
# Begin Source File

SOURCE=.\bnrobsys.c
# End Source File
# Begin Source File

SOURCE=.\bnrobsys.h
# End Source File
# Begin Source File

SOURCE=.\bnrpress.c
# End Source File
# Begin Source File

SOURCE=.\bnrpress.h
# End Source File
# Begin Source File

SOURCE=.\bnrpunit.c
# End Source File
# Begin Source File

SOURCE=.\bnrpunit.h
# End Source File
# Begin Source File

SOURCE=.\bnrstgate.c
# End Source File
# Begin Source File

SOURCE=.\bnrstgate.h
# End Source File
# Begin Source File

SOURCE=.\bnrtemper.c
# End Source File
# Begin Source File

SOURCE=.\bnrtemper.h
# End Source File
# Begin Source File

SOURCE=.\bnrts.c
# End Source File
# Begin Source File

SOURCE=.\bnrts.h
# End Source File
# Begin Source File

SOURCE=.\bnrtu.c
# End Source File
# Begin Source File

SOURCE=.\bnrtu.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\bnrcomvs0.c
# End Source File
# Begin Source File

SOURCE=.\bnrcomvs0.h
# End Source File
# Begin Source File

SOURCE=.\bnrcomvs1.c
# End Source File
# Begin Source File

SOURCE=.\bnrcomvs1.h
# End Source File
# Begin Source File

SOURCE=.\bnrmeasur.c
# End Source File
# Begin Source File

SOURCE=.\bnrmeasur.h
# End Source File
# Begin Source File

SOURCE=.\bnrtcpserver.c
# End Source File
# Begin Source File

SOURCE=.\bnrtcpserver.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\AsTCP1.h
# End Source File
# Begin Source File

SOURCE=.\bnrchains.c
# End Source File
# Begin Source File

SOURCE=.\bnrhconfig.h
# End Source File
# Begin Source File

SOURCE=.\bnrmessage.h
# End Source File
# Begin Source File

SOURCE=.\multi.c
# End Source File
# Begin Source File

SOURCE=.\multi.h
# End Source File
# Begin Source File

SOURCE=.\single.c
# End Source File
# Begin Source File

SOURCE=.\single.h
# End Source File
# Begin Source File

SOURCE=.\typedefs.h
# End Source File
# Begin Source File

SOURCE=.\WinSock2.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
