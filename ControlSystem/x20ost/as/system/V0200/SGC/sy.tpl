Systemkonfiguration
RPS Name............................@1,33,%s,*@
Prozessortyp........................@1,11,%s,*@
RPSSW Version.......................@1,22,%s,*@
Paßwort.............................@1,0,%s,*@
@\MEMPAGE@
______________________________________________________
Speicher
        Globale Merker:
                analog..............@2,0,%ld Byte,long@
                digital.............@2,4,%ld Bit,long@
        Permanente Merker:
                analog..............@2,12,%ld Byte,long@
                digital.............@2,16,%ld Bit,long@
        Speicher:
                FIX-RAM.............@2,20,%ld kByte,long@
                Temporär............@2,24,%ld kByte,long@
                Alarmlisten.........@2,320,%ld Byte,long@
@\MEMPAGEEND@@\MODPAGE@
______________________________________________________
Module
        Logbucheinträge.............@3,0,%ld,long@
        Zyklische Tasks.............@3,4,%ld,long@
        Restzeittasks...............@3,8,%ld,long@
        System Tasks................@3,12,%ld,long@
        B&R Module..................@3,16,%ld,long@
@\MODPAGEEND@@\TKPAGE@
______________________________________________________
Taskklassen
        Anzahl der Taskklassen......@\TKCOUNT@
        Stackgröße:
                User................@4,4,%ld Byte,long@
                Interrupt...........@4,8,%ld Byte,long@
@\TKLOOP@
        Taskklasse @\TKLOOPINDEX@
        Zeitverhalten:
                Zyklusdauer.........@4,0,%f,float,a@
                Toleranz............@4,8,%f,float,a@
                Restzeit............@4,16,%f,float,a@
        Merker:
                analog..............@4,16,%ld,long,a@
                digital.............@4,20,%ld,long,a@        
@\TKLOOPEND@@\TKPAGEEND@@\SSPAGE@
______________________________________________________
HS Taskklassen
        Anzahl der HS Taskklassen...@\SSCOUNT@
@\LIST1:1=HW-Timer,2=RIO/PP-FUB@@\LIST0:1=nie,2=durch IRQ-TK@@\SSLOOP@
        HS Taskklasse @\SSLOOPINDEX@
        Zeitverhalten:
                Zeitbasis...........@5,8,%LIST1,int,a@
                Zyklusdauer.........@5,0,%3.1f ms,float,a@
                Unterbrechbar.......@5,12,%LIST0,int,a@
        Stack:
                User................@5,20,%ld Byte,long,a@
                Interrupt...........@5,16,%ld Byte,long,a@
@\SSLOOPEND@@\SSPAGEEND@@\EXCPAGE@
______________________________________________________
EXC Taskklasse@\SSLOOPINDEX=7@
        Anzahl der Module...........@5,0,%.0f,float,a@
        Unterbrechbar...............@5,12,%LIST0,int,a@
        Stack:
                User................@5,20,%ld Byte,long,a@
                Interrupt...........@5,16,%ld Byte,long,a@
@\EXCPAGEEND@@\IRQPAGE@
______________________________________________________
IRQ Taskklasse@\SSLOOPINDEX=8@
        Anzahl der Module...........@5,0,%.0f,float,a@
        Unterbrechbar...............@5,12,%LIST0,int,a@
        Stack:
                User................@5,20,%ld Byte,long,a@
                Interrupt...........@5,16,%ld Byte,long,a@
@\IRQPAGEEND@@\TIPAGE@
______________________________________________________
Time Outs
        Erlaubte Systemzeit Verletzung: @6,0,%.3f,float@
        Warten
                bei Kaltstart.......@6,8,%.3f,float@
                bei Warmstart.......@6,16,%.3f,float@
                auf POWERFAIL.......@6,24,%.3f,float@
@\TIPAGEEND@@\BSPAGE@@\LIST0:1=Diagnose,2=Kaltstart@
______________________________________________________
Betriebssystem
        Kommunikation
           Kommunikations Kanäle....@8,0,%ld,long@
           Parallele Verbindungen...@8,48,%ld,long@
           Gerätetreiber............@8,4,%ld,long@
           Force Aufträge...........@8,28,%ld,long@
           PV Tabellen..............@8,32,%ld,long@
           Log. Variablenlisten.....@8,36,%ld,long@
           Phy. Variablenlisten.....@8,40,%ld,long@@\LIST1:1=Nein,2=Ja@
           Turbomode................@8,27,%LIST1,byte@
        B&R OS
          Systembuskarten...........@8,44,%ld,long@
          AVT-Einträge..............@8,8,%ld,long@
          Semaphoren................@8,12,%ld,long@
          Queues....................@8,16,%ld,long@
          Daten/Stack...............@8,20,%#lx,long@
          Hochlauf nach Fehler     @8,24,%LIST0,byte@@\LIST1:1=Warmstart,2=Kaltstart@
          Hochlauf nach Reset      @8,25,%LIST1,byte@
          Hochlauf nach Powerfail  @8,26,%LIST1,byte@
@\BSPAGEEND@@\RBPAGE@
______________________________________________________
Remote I/O
Konfigurationen @\RBCOUNT@@\LIST0:1=Master,2=ISL@
@\RBLOOP@
Einstellungen für RIO @\RBLOOPINDEX@@\LIST2:1=2M,2=2M,3=500k,4=181k,5=100k@
        Steckplatz..................@9,32,%ld,long,a@@\LIST1:Nein,Ja@
        Betriebsart.................@9,0,%LIST0,int,a@
        Baudrate....................@9,4,%LIST2,int,a@
        Redundanz...................@9,8,%BOOL1,byte,a@
        TimeoutIO...................@9,9,%ld ms,long,a@
        SlaveTimeOut................@9,13,%ld sec,long,a@
        Max. Stationen..............@9,17,%ld,long,a@
        Repeat Count................@9,21,%ld,long,a@@\LIST1:Ja,Nein@
        Prioritäten.................@9,25,%ld,long,a@@\LIST2:0=Default,1=Enable,2=Disable@
        Hot Plug....................@9,36,%BOOL1,byte,a@
        Slaves......................@9,29,%RBSP2,byte,a@@\LIST2:0=-,1=Inaktiv,2=Aktiv,3=Exception@
           Ausfall quittieren.......@9,30,%LIST2,byte,a@
           Ready   quittieren.......@9,31,%LIST2,byte,a@
@\RBLOOPEND@@\RBPAGEEND@@\CAPAGE@
______________________________________________________
CAN I/O@\LIST1:255=Lokal,0=PS,1=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,10=10,11=11,12=12,13=13@
Konfigurationen @\CACOUNT@@\LIST2:Nein,Ja@
@\CALOOP@
Einstellungen für CAN @\CALOOPINDEX@@\LIST0:0=kein SS,1=SS1,2=SS2,3=SS3,4=SS4@
        Steckplatz..................@12,0,%LIST1,byte@
        Subslot.....................@12,1,%LIST0,long@@\LIST0:1=IF1,2=IF2,3=IF3,4=IF4,15=-@
        Interface...................@12,5,%LIST0,long@
        Baudrate....................@12,13,%ldkBIT/s,long@
        SlaveTimeOut................@12,17,%ld ms,long@
        TimeoutIO...................@12,21,%ld ms,long@
        Repeat Count................@12,29,%ld,long@@\LIST0:0=Ja,255=Nein@
        Unterbrechbar...............@12,33,%LIST0,long@
        Anzahl ANP Module...........@12,25,%ld,long@
        Anzahl Slaves...............@12,9,%ld,long@
        Slaves Exception bei@\LIST0:1=Ja,2=Nein@
           Ausfall..................@12,41,%LIST0,byte@
           Ready....................@12,42,%LIST0,byte@
           Alarm....................@12,43,%LIST0,byte@
           fehlendem Modul..........@12,44,%LIST0,byte@
@\CNLOOP@
        Knoten Parameter @\CNLOOPINDEX@
        Knoten Nummer: @14,0,%ld,long@
        Idlezeit
          Digital IN :@14,12,%ld ms,long@      Digital OUT:@14,4,%ld ms,long@
          Analog  IN :@14,16,%ld ms,long@      Analog  OUT:@14,8,%ld ms,long@
        Zykluszeit              Inhibitzeit
          Digital IN :@14,20,%ld ms,long@      Digital IN :@14,28,%ld ms,long@
          Analog  IN :@14,24,%ld ms,long@      Analog  IN :@14,32,%ld ms,long@
@\CNLOOPEND@
@\CALOOPEND@@\CAPAGEEND@@\23PAGE@
______________________________________________________
2003 I/O
        Anzahl der aktualisierten
        IO-Kanäle pro IO-Zyklus.....@11,0,%ld,long@ (0 -> Alle)
@\23PAGEEND@@\PBPAGE@
______________________________________________________
PB Indizes
                          von   bis
        Datentyp         $@10,0,%04lx,long@ $@10,4,%04lx,long@
        Struktur         $@10,8,%04lx,long@ $@10,12,%04lx,long@
        Variablenliste   $@10,16,%04lx,long@ $@10,20,%04lx,long@
        Program Invoc    $@10,24,%04lx,long@ $@10,28,%04lx,long@
        Domain           $@10,32,%04lx,long@ $@10,36,%04lx,long@
        Prozeßvariable   $@10,40,%04lx,long@ $@10,44,%04lx,long@
@\PBPAGEEND@@\KOPAGE@
______________________________________________________
Kommunikation@\LIST1:0=Lokal,1=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,10=10,11=11,12=12,13=13@
Konfigurationen @\KOCOUNT@
@\KOLOOP@
Konfiguration @\KOLOOPINDEX@@\LIST0:0=kein SS,1=SS1,2=SS2,3=SS3,4=SS4@
        Steckplatz.................@13,4,%LIST1,int@
        Subslot....................@13,8,%LIST0,int@@\LIST0:1=IF1,2=IF2,3=IF3,4=IF4,15=-@
        Interface..................@13,12,%LIST0,int@@\LIST0:0=Seriell,1=CAN,3=PB@
        Typ........................@13,0,%LIST0,int@
        Parameter
        @13,16,%s,**@
@\KOLOOPEND@@\KOPAGEEND@
Ende

@\LANG001@
System Configuration
PLC Name.............................@1,33,%s,*@
Processor Type.......................@1,11,%s,*@
PLC SW Version.......................@1,22,%s,*@
Password.............................@1,0,%s,*@
@\MEMPAGE@
______________________________________________________
Memory
        Global Variables:
                Analog..............@2,0,%ld bytes,long@
                Digital.............@2,4,%ld Bit,long@
        Permanent Variables:
                Analog..............@2,12,%ld bytes,long@
                Digital.............@2,16,%ld Bit,long@
        Memory:
                FIX RAM.............@2,20,%ld kBytes,long@
                Temporary...........@2,24,%ld kBytes,long@
                Alarm list..........@2,320,%ld Byte,long@
@\MEMPAGEEND@@\MODPAGE@
______________________________________________________
Modules
        Log Book Entries............@3,0,%ld,long@
        Cyclical Tasks..............@3,4,%ld,long@
        Idle Time Tasks.............@3,8,%ld,long@
        System Tasks................@3,12,%ld,long@
        B&R Modules.................@3,16,%ld,long@
@\MODPAGEEND@@\TKPAGE@
______________________________________________________
Task Classes
        Number of Task Classes......@\TKCOUNT@
        Stack Size:
                User................@4,4,%ld bytes,long@
                Interrupt...........@4,8,%ld bytes,long@
@\TKLOOP@
        Task Classes @\TKLOOPINDEX@
        Timing:
                Cycle Time.........@4,0,%f,float,a@
                Tolerance..........@4,8,%f,float,a@
                Idle Time..........@4,16,%f,float,a@
        Variable:
                Analog.............@4,16,%ld,long,a@
                Digital............@4,20,%ld,long,a@        
@\TKLOOPEND@@\TKPAGEEND@@\SSPAGE@
______________________________________________________
HS Task Classes
        Number of HS Task Classes...@\SSCOUNT@
@\LIST1:1=HW Timer,2=RIO/PP-FUB@@\LIST0:1=Never,2=By IRQ-TK@@\SSLOOP@
        HS Task Class @\SSLOOPINDEX@
        Timing:
                Time Base..........@5,8,%LIST1,int,a@
                Cycle Time.........@5,0,%3.1f ms,float,a@
                Interruptible......@5,12,%LIST0,int,a@
        Stack:
                User...............@5,20,%ld bytes,long,a@
                Interrupt..........@5,16,%ld bytes,long,a@
@\SSLOOPEND@@\SSPAGEEND@@\EXCPAGE@
______________________________________________________
EXC Task Class@\SSLOOPINDEX=7@
        Number of Modules..........@5,0,%.0f,float,a@
        Interruptible..............@5,12,%LIST0,int,a@
        Stack:
                User...............@5,20,%ld Byte,long,a@
                Interrupt..........@5,16,%ld Byte,long,a@
@\EXCPAGEEND@@\IRQPAGE@
______________________________________________________
IRQ Task Class@\SSLOOPINDEX=8@
        Number of Modules..........@5,0,%.0f,float,a@
        Interruptible..............@5,12,%LIST0,int,a@
        Stack:
                User...............@5,20,%ld bytes,long,a@
                Interrupt..........@5,16,%ld bytes,long,a@
@\IRQPAGEEND@@\TIPAGE@
______________________________________________________
Time Outs
        Permitted System Time Violation: @6,0,%.3f,float@
        Delays
                With Cold Restart.......@6,8,%.3f,float@
                With Warm Restart.......@6,16,%.3f,float@
                With Power Failure......@6,24,%.3f,float@
@\TIPAGEEND@@\BSPAGE@@\LIST0:1=Diagnostics,2=Cold Restart@
______________________________________________________
Operating System
        Communication
           Communication Channels....@8,0,%ld,long@
           Parallel Connections......@8,48,%ld,long@
           Device Driver.............@8,4,%ld,long@
           Force Instructions........@8,28,%ld,long@
           PV Tables.................@8,32,%ld,long@
           Log. Variable Lists.......@8,36,%ld,long@
           Phy. Variable Lists.......@8,40,%ld,long@@\LIST1:1=No,2=Yes@
           Turbo Mode................@8,27,%LIST1,byte@
        B&R OS
          System Bus Cards...........@8,44,%ld,long@
          AVT Entries................@8,8,%ld,long@
          Semaphores.................@8,12,%ld,long@
          Queues.....................@8,16,%ld,long@
          Data/Stack.................@8,20,%#lx,long@
          Booting after Error     @8,24,%LIST0,byte@@\LIST1:1=Warm Restart,2=Cold Restart@
          Booting after Reset      @8,25,%LIST1,byte@
          Booting after Power Failure  @8,26,%LIST1,byte@
@\BSPAGEEND@@\RBPAGE@
______________________________________________________
Remote I/O
Configurations @\RBCOUNT@@\LIST0:1=Master,2=ISL@
@\RBLOOP@
Settings for RIO @\RBLOOPINDEX@@\LIST2:1=2M,2=2M,3=500k,4=181k,5=100k@
        Slot.........................@9,32,%ld,long,a@@\LIST1:No,Yes@
        Operating Mode...............@9,0,%LIST0,int,a@
        Baud Rate....................@9,4,%LIST2,int,a@
        Redundancy...................@9,8,%BOOL1,byte,a@
        Timeout IO...................@9,9,%ld ms,long,a@
        Slave TimeOut................@9,13,%ld sec,long,a@
        Max. Stations................@9,17,%ld,long,a@
        Repeat Count.................@9,21,%ld,long,a@@\LIST1:Yes,No@
        Priorities...................@9,25,%ld,long,a@@\LIST2:0=Default,1=Enable,2=Disable@
        Hot Plug.....................@9,36,%BOOL1,byte,a@
        Slaves.......................@9,29,%RBSP2,byte,a@@\LIST2:0=-,1=Inactive,2=Aktive,3=Exception@
           Acknowledge Failure.......@9,30,%LIST2,byte,a@
           Acknowledge Ready  .......@9,31,%LIST2,byte,a@
@\RBLOOPEND@@\RBPAGEEND@@\CAPAGE@
______________________________________________________
CAN I/O@\LIST1:255=Lokal,0=PS,1=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,10=10,11=11,12=12,13=13@
Configurations @\CACOUNT@@\LIST2:No,Yes@
@\CALOOP@
Settings for CAN @\CALOOPINDEX@@\LIST0:0=None SS,1=SS1,2=SS2,3=SS3,4=SS4@
        Slot........................@12,0,%LIST1,byte@
        Subslot.....................@12,1,%LIST0,long@@\LIST0:1=IF1,2=IF2,3=IF3,4=IF4,15=-@
        Interface...................@12,5,%LIST0,long@
        Baudrate....................@12,13,%ldkBIT/s,long@
        Slave TimeOut...............@12,17,%ld ms,long@
        Timeout IO..................@12,21,%ld ms,long@
        Repeat Count................@12,29,%ld,long@@\LIST0:0=Yes,255=No@
        Interruptible...............@12,33,%LIST0,long@
        Number of ANP Modules.......@12,25,%ld,long@
        Number of Slaves............@12,9,%ld,long@
        Slaves Exception at@\LIST0:1=Yes,2=No@
           Failure..................@12,41,%LIST0,byte@
           Ready....................@12,42,%LIST0,byte@
           Alarm....................@12,43,%LIST0,byte@
           Missing Module...........@12,44,%LIST0,byte@
@\CNLOOP@
        Node Parameters @\CNLOOPINDEX@
        Node Number: @14,0,%ld,long@
        Idle Time
          Digital IN :@14,12,%ld ms,long@      Digital OUT:@14,4,%ld ms,long@
          Analog  IN :@14,16,%ld ms,long@      Analog  OUT:@14,8,%ld ms,long@
        Cycle Time              Inhibit Time
          Digital IN :@14,20,%ld ms,long@      Digital IN :@14,28,%ld ms,long@
          Analog  IN :@14,24,%ld ms,long@      Analog  IN :@14,32,%ld ms,long@
@\CNLOOPEND@
@\CALOOPEND@@\CAPAGEEND@@\23PAGE@
______________________________________________________
2003 I/O
        Number of Updated 
        IO Channels per IO Cycle.....@11,0,%ld,long@ (0 -> Alle)
@\23PAGEEND@@\PBPAGE@
______________________________________________________
PB Indices
                          From   To
        Data Type         $@10,0,%04lx,long@ $@10,4,%04lx,long@
        Structure         $@10,8,%04lx,long@ $@10,12,%04lx,long@
        Variable Lists   $@10,16,%04lx,long@ $@10,20,%04lx,long@
        Program Invoc    $@10,24,%04lx,long@ $@10,28,%04lx,long@
        Domain           $@10,32,%04lx,long@ $@10,36,%04lx,long@
        Process Variable   $@10,40,%04lx,long@ $@10,44,%04lx,long@
@\PBPAGEEND@@\KOPAGE@
______________________________________________________
Communication@\LIST1:0=Lokal,1=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,10=10,11=11,12=12,13=13@
Configurations @\KOCOUNT@
@\KOLOOP@
configuration @\KOLOOPINDEX@@\LIST0:0=None SS,1=SS1,2=SS2,3=SS3,4=SS4@
        Slot.......................@13,4,%LIST1,int@
        Subslot....................@13,8,%LIST0,int@@\LIST0:1=IF1,2=IF2,3=IF3,4=IF4,15=-@
        Interface..................@13,12,%LIST0,int@@\LIST0:0=Serial,1=CAN,3=PB@
        Type.......................@13,0,%LIST0,int@
        Parameter
        @13,16,%s,**@
@\KOLOOPEND@@\KOPAGEEND@
End

@\LANG033@
Configuration système
Nom d'API............................@1,33,%s,*@
Type de processeur...................@1,11,%s,*@
Version de SE d'API..................@1,22,%s,*@
Mot de passe.........................@1,0,%s,*@
@\MEMPAGE@
______________________________________________________
Mémoire
        Variables globales:
                Analogique..........@2,0,%ld octets,long@
                Digital.............@2,4,%ld bits,long@
        Variables permanentes:
                Analogique..........@2,12,%ld octets,long@
                Digital.............@2,16,%ld bits,long@
        Mémoire:
                FIX RAM.............@2,20,%ld koctets,long@
                Temporaire..........@2,24,%ld koctets,long@
                Alarm list..........@2,320,%ld Byte,long@
@\MEMPAGEEND@@\MODPAGE@
______________________________________________________
Modules
        Entrées du journal d'erreurs.@3,0,%ld,long@
        Tâches cycliques.............@3,4,%ld,long@
        Tâches de temps d'inactivité.@3,8,%ld,long@
        Tâches système...............@3,12,%ld,long@
        Modules B&R..................@3,16,%ld,long@
@\MODPAGEEND@@\TKPAGE@
______________________________________________________
Classes de tâches
        Nombre de classes de tâches.@\TKCOUNT@
        Taille de pile:
                Utilisateur.........@4,4,%ld bytes,long@
                Interruption........@4,8,%ld bytes,long@
@\TKLOOP@
        Classes de tâches@\TKLOOPINDEX@
        Comportement temporel:
                Temps de cycle.....@4,0,%f,float,a@
                Tolérance..........@4,8,%f,float,a@
                Temps d'inactivité.@4,16,%f,float,a@
        Variables:
                Analogique.........@4,16,%ld,long,a@
                Digital............@4,20,%ld,long,a@        
@\TKLOOPEND@@\TKPAGEEND@@\SSPAGE@
______________________________________________________
Classes de tâches HS
        Nombre de classes de tâches HS...@\SSCOUNT@
@\LIST1:1=Timer matériel,2=Bloc de fonction RIO/PP@@\LIST0:1=Jamais,2=Par tâche IRQ@@\SSLOOP@
        Classe de tâches HS @\SSLOOPINDEX@
        Comportement temporel:
                Base de temps......@5,8,%LIST1,int,a@
                Temps de cycle.....@5,0,%3.1f ms,float,a@
                Interruptible......@5,12,%LIST0,int,a@
        Pile:
                Utilisateur........@5,20,%ld octets,long,a@
                Interruption.......@5,16,%ld octets,long,a@
@\SSLOOPEND@@\SSPAGEEND@@\EXCPAGE@
______________________________________________________
Classe de tâches EXC@\SSLOOPINDEX=7@
        Nombre de modules..........@5,0,%.0f,float,a@
        Interruptible..............@5,12,%LIST0,int,a@
        Pile:
                Utilisateur........@5,20,%ld octets,long,a@
                Interruption.......@5,16,%ld octets,long,a@
@\EXCPAGEEND@@\IRQPAGE@
______________________________________________________
Classe de tâches IRQ@\SSLOOPINDEX=8@
        Nombre de modules..........@5,0,%.0f,float,a@
        Interruptible..............@5,12,%LIST0,int,a@
        Pile:
                Utilisateur........@5,20,%ld octets,long,a@
                Interruption.......@5,16,%ld octets,long,a@
@\IRQPAGEEND@@\TIPAGE@
______________________________________________________
Time-outs
        Violation du temps système autorisée: @6,0,%.3f,float@
        Attente
                si initialisation totale.@6,8,%.3f,float@
                si initialisation........@6,16,%.3f,float@
                si panne secteur.........@6,24,%.3f,float@
@\TIPAGEEND@@\BSPAGE@@\LIST0:1=Diagnostic,2=Initialisation totale@
______________________________________________________
Système d'exploitation
        Communication
           Voies de communication.....@8,0,%ld,long@
           Liaisons parallèles........@8,48,%ld,long@
           Pilote d'interface.........@8,4,%ld,long@
           Instructions de forçage....@8,28,%ld,long@
           Tables var. de processus...@8,32,%ld,long@
           Listes variables logiques..@8,36,%ld,long@
           Listes variables physiques.@8,40,%ld,long@@\LIST1:1=Non,2=Oui@
           Mode Turbo.................@8,27,%LIST1,byte@
        SE B&R
          Cartes bus système.........@8,44,%ld,long@
          Entrées AVT................@8,8,%ld,long@
          Sémaphores.................@8,12,%ld,long@
          Files d'attente............@8,16,%ld,long@
          Données/Pile...............@8,20,%#lx,long@
          Démarrage après erreur         @8,24,%LIST0,byte@@\LIST1:1=Initialisation,2=Initialisation totale@
          Démarrage après reset          @8,25,%LIST1,byte@
          Démarrage après panne secteur  @8,26,%LIST1,byte@
@\BSPAGEEND@@\RBPAGE@
______________________________________________________
E/S B&R RIO
Configurations @\RBCOUNT@@\LIST0:1=Maître,2=Esclave intelligent@
@\RBLOOP@
Paramétrages pour E/S B&R RIO @\RBLOOPINDEX@@\LIST2:1=2M,2=2M,3=500k,4=181k,5=100k@
        Emplacement..................@9,32,%ld,long,a@@\LIST1:Non,Oui@
        Mode d'exploitation..........@9,0,%LIST0,int,a@
        Débit de transmission........@9,4,%LIST2,int,a@
        Redondance...................@9,8,%BOOL1,byte,a@
        Timeout E/S..................@9,9,%ld ms,long,a@
        Timeout d'esclave............@9,13,%ld sec,long,a@
        Max. stations................@9,17,%ld,long,a@
        Comptage des répétitions.....@9,21,%ld,long,a@@\LIST1:Oui,Non@
        Priorités....................@9,25,%ld,long,a@@\LIST2:0=Par défaut,1=Activer,2=Désactiver@
        Remplacement à chaud.........@9,36,%BOOL1,byte,a@
        Esclaves.....................@9,29,%RBSP2,byte,a@@\LIST2:0=-,1=Inactif,2=Actif,3=Exception@
           Acquittement Panne........@9,30,%LIST2,byte,a@
           Acquittement Prêt.........@9,31,%LIST2,byte,a@
@\RBLOOPEND@@\RBPAGEEND@@\CAPAGE@
______________________________________________________
E/S CAN@\LIST1:255=Local,0=PS,1=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,10=10,11=11,12=12,13=13@
Configurations @\CACOUNT@@\LIST2:Non,Oui@
@\CALOOP@
Paramétrages pour CAN @\CALOOPINDEX@@\LIST0:0=Aucun SS,1=SS1,2=SS2,3=SS3,4=SS4@
        Emplacement...................@12,0,%LIST1,byte@
        Sous-emplacement..............@12,1,%LIST0,long@@\LIST0:1=IF1,2=IF2,3=IF3,4=IF4,15=-@
        Interface.....................@12,5,%LIST0,long@
        Débit de transmission.........@12,13,%ldkBIT/s,long@
        Timeout d'esclave.............@12,17,%ld ms,long@
        Timeout E/S...................@12,21,%ld ms,long@
        Comptage des répétitions......@12,29,%ld,long@@\LIST0:0=Oui,255=Non@
        Interruptible.................@12,33,%LIST0,long@
        Nombre de modules enfichables.@12,25,%ld,long@
        Nombres d'esclaves............@12,9,%ld,long@
        Exception d'esclave si@\LIST0:1=Oui,2=Non@
           Panne......................@12,41,%LIST0,byte@
           Prêt.......................@12,42,%LIST0,byte@
           Alarme.....................@12,43,%LIST0,byte@
           Module manquant............@12,44,%LIST0,byte@
@\CNLOOP@
        Paramètres de noeud@\CNLOOPINDEX@
        Numéro de noeud: @14,0,%ld,long@
        Temps d'inactivité
          Entrée digitale  :@14,12,%ld ms,long@      Sortie   digitale:@14,4,%ld ms,long@
          Entrée analogique:@14,16,%ld ms,long@      Sortie analogique:@14,8,%ld ms,long@
        Temps de cycle              Temps d'inhibition
          Entrée digitale  :@14,20,%ld ms,long@      Entrée   digitale:@14,28,%ld ms,long@
          Entrée analogique:@14,24,%ld ms,long@      Entrée analogique:@14,32,%ld ms,long@
@\CNLOOPEND@
@\CALOOPEND@@\CAPAGEEND@@\23PAGE@
______________________________________________________
E/S 2003
        Nombre de voies d'E/S 
        actualisées par cycle d'E/S.....@11,0,%ld,long@ (0 -> Tous)
@\23PAGEEND@@\PBPAGE@
______________________________________________________
Indices PB
                               de    à
        Type de données       $@10,0,%04lx,long@ $@10,4,%04lx,long@
        Structure             $@10,8,%04lx,long@ $@10,12,%04lx,long@
        Listes de variables   $@10,16,%04lx,long@ $@10,20,%04lx,long@
        Appel de programme    $@10,24,%04lx,long@ $@10,28,%04lx,long@
        Domaine               $@10,32,%04lx,long@ $@10,36,%04lx,long@
        Variable de processus $@10,40,%04lx,long@ $@10,44,%04lx,long@
@\PBPAGEEND@@\KOPAGE@
______________________________________________________
Communication@\LIST1:0=Lokal,1=1,2=2,3=3,4=4,5=5,6=6,7=7,8=8,9=9,10=10,11=11,12=12,13=13@
Configurations @\KOCOUNT@
@\KOLOOP@
configuration @\KOLOOPINDEX@@\LIST0:0=None SS,1=SS1,2=SS2,3=SS3,4=SS4@
        Emplacement................@13,4,%LIST1,int@
        Sous-emplacement...........@13,8,%LIST0,int@@\LIST0:1=IF1,2=IF2,3=IF3,4=IF4,15=-@
        Interface..................@13,12,%LIST0,int@@\LIST0:0=Série,1=CAN,3=PB@
        Type.......................@13,0,%LIST0,int@
        Paramètre
        @13,16,%s,**@
@\KOLOOPEND@@\KOPAGEEND@
Fin