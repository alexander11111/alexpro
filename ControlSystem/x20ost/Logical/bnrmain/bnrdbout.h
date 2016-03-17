/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnraninput.h
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#ifndef __DEBUGOUTPUT_H__
#define __DEBUGOUTPUT_H__
#ifdef WIN32
#define DEB_CSensor
#define DEB_CSmartSensor
#define DEB_CDigitalSensor
//#define DEB_CIdleSensor
//#define DEB_CProcManager
#define DEB_CDirectionModule
//#define DEB_CCyclicSystem 
#define DEB_CMain
#define DEB_CAdmin
#define DEB_CKpModule
//#define DEB_CMsModule
#define DEB_C101Module
#define DEB_CGsmModule
#define DEB_CTeleSensor
#define DEB_CComServer
#define DEB_CComVS0
#define DEB_CComVS1
#define DEB_CFreq
#define DEB_CStGate
#define DEB_CPunit
#define DEB_CLevel
#define DEB_CObsSys
#define DEB_CMsModule
//#define DEB_CTcpServer
#define DEB_CTeleSignal
#define DEB_CTeleControl
#define DEB_CTeleInd
//#define DEB_CProcManager
#define DEB_CSystem
//#define DEB_CAnIOSlot
//#define DEB_CDgIOSlot
//#define DEB_CAnalogPin
//#define DEB_CDigitalPin
#define DEB_CObserveModule
//#define DEB_CTcpDriver
//#define DEB_CComDriver
//#define DEB_CTcpServer
//#define DEB_CComServer
//#define DEB_CPin 
#else
//#define DEB_C101Module
//#define DEB_CComServer
#endif

#endif
