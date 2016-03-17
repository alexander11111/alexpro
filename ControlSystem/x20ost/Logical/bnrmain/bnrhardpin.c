/********************************************************************
 * COPYRIGHT -- Kontora
 ********************************************************************
 * Program: bnrmain
 * File: bnrlsens.c
 * Author: Abramenya
 * Created: January 19, 2009
 *******************************************************************/

#include "bnrhardpin.h"
#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif
//Analog Pin
void CAnalogPin_InitPin(This,PVOID pValue)
{
     DECLARE_MULTI_OPEN(CAnalogPin,CPin)
	 pT->m_vpHardPin = (UINT*)pValue; 
}
void CAnalogPin_SetPin(This,SPIN *pPin)
{
     DECLARE_MULTI_OPEN(CAnalogPin,CPin)
	 *pT->m_vpHardPin = pPin->iValue;
}
void CAnalogPin_GetPin(This,SPIN *pPin)
{
     DECLARE_MULTI_OPEN(CAnalogPin,CPin)
	 pPin->iValue = *pT->m_vpHardPin;
}
PVOID CAnalogPin_GetAddrPin(This)
{
	 DECLARE_MULTI_OPEN(CAnalogPin,CPin)
	 return (PVOID)pT->m_vpHardPin;
}
void CAnalogPin_CAnalogPin(This)
{
     DECLARE_MULTI_OPEN(CAnalogPin,CPin)
	 DECLARE_VIRTUAL_FUNC(CAnalogPin,InitPin)
	 DECLARE_VIRTUAL_FUNC(CAnalogPin,GetPin)
	 DECLARE_VIRTUAL_FUNC(CAnalogPin,SetPin)
	 DECLARE_VIRTUAL_FUNC(CAnalogPin,GetAddrPin)
}
void CAnalogPin_DCAnalogPin(This)
{
	 DECLARE_MULTI_OPEN(CAnalogPin,CPin)
}
DECLARE_MULTI_CREATE(CAnalogPin,CPin)
//Digital Pin
void CDigitalPin_InitPin(This,PVOID pValue)
{
	 DECLARE_MULTI_OPEN(CDigitalPin,CPin)
	 pT->m_vpHardPin = (BOOL*)pValue;
}
void CDigitalPin_SetPin(This,SPIN *pPin)
{
 	 DECLARE_MULTI_OPEN(CDigitalPin,CPin)
	 *pT->m_vpHardPin = pPin->blValue;
}
void CDigitalPin_GetPin(This,SPIN *pPin)
{
	 DECLARE_MULTI_OPEN(CDigitalPin,CPin)
	 pPin->blValue = *pT->m_vpHardPin;
}
PVOID CDigitalPin_GetAddrPin(This)
{
	 DECLARE_MULTI_OPEN(CDigitalPin,CPin)
	 return pT->m_vpHardPin;
}
void CDigitalPin_CDigitalPin(This)
{
     DECLARE_MULTI_OPEN(CDigitalPin,CPin)
	 DECLARE_VIRTUAL_FUNC(CDigitalPin,InitPin)
	 DECLARE_VIRTUAL_FUNC(CDigitalPin,GetPin)
	 DECLARE_VIRTUAL_FUNC(CDigitalPin,SetPin)
	 DECLARE_VIRTUAL_FUNC(CDigitalPin,GetAddrPin)
}
void CDigitalPin_DCDigitalPin(This)
{
	 DECLARE_MULTI_OPEN(CDigitalPin,CPin)
}
DECLARE_MULTI_CREATE(CDigitalPin,CPin)
//Counter Pin
void CDCounterPin_InitPin(This,PVOID pValue)
{
	 DECLARE_MULTI_OPEN(CDCounterPin,CPin)
		pT->m_vpHardPin = (UINT*)pValue;
}
void CDCounterPin_SetPin(This,SPIN *pPin)
{
	 DECLARE_MULTI_OPEN(CDCounterPin,CPin)
		*pT->m_vpHardPin = pPin->blValue;
}
void CDCounterPin_GetPin(This,SPIN *pPin)
{
	 DECLARE_MULTI_OPEN(CDCounterPin,CPin)
		pPin->blValue = *pT->m_vpHardPin;
}
PVOID CDCounterPin_GetAddrPin(This)
{
	 DECLARE_MULTI_OPEN(CDCounterPin,CPin)
		return pT->m_vpHardPin;
}
void CDCounterPin_CDCounterPin(This)
{
	 DECLARE_MULTI_OPEN(CDCounterPin,CPin)
	 DECLARE_VIRTUAL_FUNC(CDCounterPin,InitPin)
	 DECLARE_VIRTUAL_FUNC(CDCounterPin,GetPin)
	 DECLARE_VIRTUAL_FUNC(CDCounterPin,SetPin)
	 DECLARE_VIRTUAL_FUNC(CDCounterPin,GetAddrPin)
}
void CDCounterPin_DCDCounterPin(This)
{
	 DECLARE_MULTI_OPEN(CDCounterPin,CPin)
}
DECLARE_MULTI_CREATE(CDCounterPin,CPin)
//Temperature Pin
void CTemperaturePin_InitPin(This,PVOID pValue)
{
	DECLARE_MULTI_OPEN(CTemperaturePin,CPin)
	pT->m_vpHardPin = (UINT*)pValue;
}
void CTemperaturePin_SetPin(This,SPIN *pPin)
{
	DECLARE_MULTI_OPEN(CTemperaturePin,CPin)
	*pT->m_vpHardPin = pPin->blValue;
}
void CTemperaturePin_GetPin(This,SPIN *pPin)
{
	DECLARE_MULTI_OPEN(CTemperaturePin,CPin)
	pPin->blValue = *pT->m_vpHardPin;
}
PVOID CTemperaturePin_GetAddrPin(This)
{
	DECLARE_MULTI_OPEN(CTemperaturePin,CPin)
	return pT->m_vpHardPin;
}
void CTemperaturePin_CTemperaturePin(This)
{
	DECLARE_MULTI_OPEN(CTemperaturePin,CPin)
	DECLARE_VIRTUAL_FUNC(CTemperaturePin,InitPin)
	DECLARE_VIRTUAL_FUNC(CTemperaturePin,GetPin)
	DECLARE_VIRTUAL_FUNC(CTemperaturePin,SetPin)
	DECLARE_VIRTUAL_FUNC(CTemperaturePin,GetAddrPin)
}
void CTemperaturePin_DCTemperaturePin(This)
{
	DECLARE_MULTI_OPEN(CTemperaturePin,CPin)
}
DECLARE_MULTI_CREATE(CTemperaturePin,CPin)