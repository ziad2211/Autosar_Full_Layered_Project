/******************************************************************************
 *
 * Module: Testing
 *
 * File Name: Test.h
 *
 * Description: Header file for Testing module
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/
#ifndef TEST_H
#define TEST_H

#include "Std_Types.h"
#include <assert.h>
#include "Dio.h"
#include "Det.h"
#include "Port.h"
#include "Det.h"

boolean Det_TestLastReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

#define INVALID_PIN_ID                  (50u)
#define INVALID_PIN_MODE                (50u)

/************************************************************************************
* Test ID :TestCase1
* Description: Test for Port_SetPinDirection, Port_RefreshPortDirection, Port_SetPinMode APIs, Port_GetVersionInfo, Dio_Init
*              report a PORT_E_UNINT DET error in case the Port_Init is not called yet.
* Pre-requisits: Port Module is not initialized before Run this test case.
* Test Procedure : 1. Call Port_SetPinDirection DET error PORT_E_UNINIT should be reported.
*                  2. Call Port_RefreshPortDirection DET error PORT_E_UNINIT should be reported.
*                  3. Call Port_SetPinMode DET error PORT_E_UNINIT should be reported.
*                  4. Call Port_GetVersionInfo DET error PORT_E_UNINIT should be reported.
*                  5. Call Dio_Init DEt error PORT_E_UNINIT should be reported.
*************************************************************************************/
void TestCase1(void);

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Port_Init and Port_GetVersionInfo report a PORT_E_PARAM_POINTER
*              DET error in case the API is called with NULL pointer.
* Pre-requisits: None.
* Test Procedure : 1. Call Port_Init with NULL pointer DET error PORT_E_PARAM_POINTER should be reported.
*                  2. Call Port_GetVersionInfo with NULL pointer DET error PORT_E_PARAM_POINTER should be reported.
*************************************************************************************/
void TestCase2(void);

/************************************************************************************
* Test ID :TestCase3
* Description: Test for Port_SetPinDirection and Port_SetPinMode report a PORT_E_PARAM_PIN
*              DET error in case the API is called with invalid pin id.
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : 1. Call Port_SetPinDirection with invalid pin id DET error PORT_E_PARAM_PIN should be reported.
*                  2. Call Port_SetPinMode with invalid pin id DET error PORT_E_PARAM_PIN should be reported.
*************************************************************************************/
void TestCase3(void);

/************************************************************************************
* Test ID :TestCase4
* Description: Test for Port_SetPinMode report a PORT_E_MODE_UNCHANGEABLE
*              DET error in case the API is called with a pin that
*              its mode is configured unchangable
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : Call Port_SetPinMode with a pin that its mode is configured unchangable
*************************************************************************************/
void TestCase4(void);

/************************************************************************************
* Test ID :TestCase5
* Description: Test for Port_SetPinMode report a PORT_E_PARAM_INVALID_MODE
*              DET error in case the API is called with an invalid pin mode
* Pre-requisits: 1. Port is initialized before running this test case.
*                2. Configure PORT_B_PIN_0 mode as changeable
* Test Procedure : Call Port_SetPinMode with an invalid pin mode
*************************************************************************************/
void TestCase5(void);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/************************************************************************************
* Test ID :TestCase6
* Description: Test for Port_SetPinDirection report a PORT_E_DIRECTION_UNCHANGEABLE
*              DET error in case the API is called with a pin that
*              its direction is configured unchangable
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : Call Port_SetPinDirection with a pin that its direction is configured unchangable
*************************************************************************************/
void TestCase6(void);
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

#if (PORT_VERSION_INFO_API == STD_ON)
/************************************************************************************
* Test ID :TestCase7
* Description: Test for Port_GetVersionInfo API functionality
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : Call Port_GetVersionInfo and get the required information
*************************************************************************************/
void TestCase7(void);
#endif /* (PORT_VERSION_INFO_API == STD_ON) */


#endif /* TEST_H */