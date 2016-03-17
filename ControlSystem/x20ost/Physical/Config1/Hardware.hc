 
[hardwarekonfig]
wurzel: 4
[4.1]
spi: OBJEKTID=5
{4.3}
klasse: "HC_Moduluebersicht.Class"
name: _PRJ-Moduluebersicht
[3.1]
[3.100]
moduladr: 0
version: 1.0.0.0
[3.101]
[3.1824]
{3.1856}
klasse: "X20PS9500"
comparam: 
[2.1]
[2.100]
moduladr: 0
version: 1.0.0.0
steckplatzgrp: "cpubus"
steckplatzinfo: NUMMER=1, MODULID=1, FLAGS=1
steckplatzgrp: "x20ntbus"
steckplatzinfo: NUMMER=1, MODULID=3, FLAGS=1
anschlussgrp: "ser1"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
[2.101]
{2.109}
klasse: "X20BB22"
comparam_ser1: 57600,e,8,1, TYPE="RS232", RIT=10, FORCE
inaparam_ser1: FORCE,NODENUMBER=2, PORTNUMBER=11159
modemparam_ser1: 57600,e,8,1, RIT=255
modeminit_ser1: STRING=ATD6885271
modemescape_ser1: SEQUENCE=+++
modemdelay_ser1: RESPONSE=2500
[21.1]
[21.100]
moduladr: 0
verbunden: 1
station: 3
busart: 6
version: 1.0.1.0
[21.101]
[21.1824]
{21.1856}
klasse: "X20AI2622"
comparam: 
[22.1]
[22.100]
moduladr: 0
verbunden: 1
station: 4
busart: 6
version: 1.0.0.0
[22.101]
[22.1824]
{22.1856}
klasse: "X20AT2222"
comparam: 
[23.1]
[23.100]
moduladr: 0
verbunden: 1
station: 5
busart: 6
version: 1.0.0.0
[23.101]
[23.1824]
{23.1856}
klasse: "X20AO4622"
comparam: 
[24.1]
[24.100]
moduladr: 0
verbunden: 1
station: 6
busart: 6
version: 1.0.0.0
[24.101]
[24.1824]
{24.1856}
klasse: "X20DI9371"
comparam: 
[25.1]
[25.100]
moduladr: 0
verbunden: 1
station: 7
busart: 6
version: 1.0.0.0
[25.101]
[25.1824]
{25.1856}
klasse: "X20DI9371"
comparam: 
[26.1]
[26.100]
moduladr: 0
verbunden: 1
station: 8
busart: 6
version: 1.0.0.0
[26.101]
[26.1824]
{26.1856}
klasse: "X20DO9321"
comparam: 
[27.1]
[27.100]
moduladr: 0
verbunden: 1
station: 9
busart: 6
version: 1.0.0.0
[27.101]
[27.1824]
{27.1856}
klasse: "X20DO9321"
comparam: 
[5.1]
spi: OBJEKTID=2
spi: OBJEKTID=19
spi: OBJEKTID=20
spi: OBJEKTID=21
spi: OBJEKTID=22
spi: OBJEKTID=23
spi: OBJEKTID=24
spi: OBJEKTID=25
spi: OBJEKTID=26
spi: OBJEKTID=27
{5.2}
klasse: "HC_SPS.Class"
familie: 20
modulname: PLC1
[1.1]
[1.100]
moduladr: 1
modulname: CPU
version: 1.0.1.0
prescaler: 5
anschlussgrp: "eth2"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
anschlussgrp: "x2x4"
anschlussinfo: NUMMER=1, MODULID=19, FLAGS=1
anschlussinfo: NUMMER=2, MODULID=20, FLAGS=1
anschlussinfo: NUMMER=3, MODULID=21, FLAGS=1
anschlussinfo: NUMMER=4, MODULID=22, FLAGS=1
anschlussinfo: NUMMER=5, MODULID=23, FLAGS=1
anschlussinfo: NUMMER=6, MODULID=24, FLAGS=1
anschlussinfo: NUMMER=7, MODULID=25, FLAGS=1
anschlussinfo: NUMMER=8, MODULID=26, FLAGS=1
anschlussinfo: NUMMER=9, MODULID=27, FLAGS=1
anschlussinfo: NUMMER=10, MODULID=0, FLAGS=0
[1.101]
[1.1840]
comparam_x2x4: SYNCUSAGE=50, IOSIZE=8, RESPTIME=100, BUSLENGTH=1000, STATIONS=64, ASYNCPAYLOAD=80
timingparam_x2x4: CYCLETIME=2000, PRESCALE=1
[1.1632]
comparam_eth2: IP=192.168.1.5, MASK=255.255.255.0, GATEWAY=192.168.1.1, BROADCAST=255.255.255.255, FORCE
inaparam_eth2: PORTNO=11159
cfgparam_eth2: SOCKETCNT=16, DESCRCNT=16, MEMBUFCNT=453, ARPTBLENTRCNT=16, PAGECNT=16, ROUTINGENTRCNT=0, FBSERVERPORT=20111, FBTCPPRI=182, PNADAEMONPRI=184, LIBPRI=183, BROADCASTCNT=5
[1.1824]
{1.108}
klasse: "X20CP0292"
[19.1]
[19.100]
moduladr: 0
verbunden: 1
station: 1
busart: 6
version: 1.2.2.0
anschlussgrp: "ser1"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
[19.101]
[19.109]
comparam_ser1: 57600,e,8,1, TYPE="RS232", RIT=5
inaparam_ser1: NODENUMBER=2, PORTNUMBER=11159
modemparam_ser1: 57600,n,8,1, RIT=255
modeminit_ser1: STRING=ATS0=1
modemescape_ser1: SEQUENCE=+++
modemdelay_ser1: RESPONSE=2500
[19.1824]
{19.1856}
klasse: "X20CS1020"
comparam: 
[20.1]
[20.100]
moduladr: 0
verbunden: 1
station: 2
busart: 6
version: 1.2.2.0
anschlussgrp: "ser1"
anschlussinfo: NUMMER=1, MODULID=0, FLAGS=0
[20.101]
[20.109]
comparam_ser1: 57600,e,8,1, TYPE="RS232", RIT=5
inaparam_ser1: NODENUMBER=2, PORTNUMBER=11159
modemparam_ser1: 57600,n,8,1, RIT=255
modeminit_ser1: STRING=ATS0=1
modemescape_ser1: SEQUENCE=+++
modemdelay_ser1: RESPONSE=2500
[20.1824]
{20.1856}
klasse: "X20CS1020"
comparam: 
