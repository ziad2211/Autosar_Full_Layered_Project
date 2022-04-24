/******************************************************************************
 *
 * Module: Testing
 *
 * File Name: Test.c
 *
 * Description: Source file for Testing module
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/
#include "Test.h"

boolean Det_TestLastReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) 
{
    boolean result = (Det_ModuleId == ModuleId) && (Det_InstanceId == InstanceId) && 
                     (Det_ApiId == ApiId) && (Det_ErrorId == ErrorId);
    Det_ModuleId = 0;
    Det_InstanceId = 0;
    Det_ApiId = 0;
    Det_ErrorId = 0;
    
    return result;
}

#if (PORT_VERSION_INFO_API == STD_ON)
STATIC Std_VersionInfoType Version_Info;
#endif /* (PORT_VERSION_INFO_API == STD_ON) */

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
void TestCase1(void)
{
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  Port_SetPinDirection(PORT_A_PIN_0, PORT_PIN_OUT);
  assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                 PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT));
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

  Port_RefreshPortDirection();
  assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                 PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT));  
  
  Port_SetPinMode(PORT_A_PIN_0, PORT_PIN_MODE_ALT1);
    assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                   PORT_SET_PIN_MODE_SID, PORT_E_UNINIT));
#if (PORT_VERSION_INFO_API == STD_ON)
    Port_GetVersionInfo(&Version_Info);
    assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                   PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT));    
#endif /* (PORT_VERSION_INFO_API == STD_ON) */
    
    Dio_Init(&Dio_Configuration);
    assert(Det_TestLastReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                   DIO_INIT_SID, PORT_E_UNINIT));
}

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Port_Init and Port_GetVersionInfo report a PORT_E_PARAM_POINTER
*              DET error in case the API is called with NULL pointer.
* Pre-requisits: None.
* Test Procedure : 1. Call Port_Init with NULL pointer DET error PORT_E_PARAM_POINTER should be reported.
*                  2. Call Port_GetVersionInfo with NULL pointer DET error PORT_E_PARAM_POINTER should be reported.
*************************************************************************************/
void TestCase2(void)
{
  Port_Init(NULL_PTR);
    assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                   PORT_INIT_SID, PORT_E_PARAM_POINTER));
    
#if (PORT_VERSION_INFO_API == STD_ON)
    Port_GetVersionInfo(NULL_PTR);
    assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                   PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER));    
#endif /* (PORT_VERSION_INFO_API == STD_ON) */
}

/************************************************************************************
* Test ID :TestCase3
* Description: Test for Port_SetPinDirection and Port_SetPinMode report a PORT_E_PARAM_PIN
*              DET error in case the API is called with invalid pin id.
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : 1. Call Port_SetPinDirection with invalid pin id DET error PORT_E_PARAM_PIN should be reported.
*                  2. Call Port_SetPinMode with invalid pin id DET error PORT_E_PARAM_PIN should be reported.
*************************************************************************************/
void TestCase3(void)
{
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  Port_SetPinDirection(INVALID_PIN_ID, PORT_PIN_IN);
    assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                   PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN));  
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */
  Port_SetPinMode(INVALID_PIN_ID, PORT_PIN_MODE_DIO);
  assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                 PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN));   
}

/************************************************************************************
* Test ID :TestCase4
* Description: Test for Port_SetPinMode report a PORT_E_MODE_UNCHANGEABLE
*              DET error in case the API is called with a pin that
*              its mode is configured unchangable
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : Call Port_SetPinMode with a pin that its mode is configured unchangable
*************************************************************************************/
void TestCase4(void)
{
  Port_SetPinMode(PORT_A_PIN_0, PORT_PIN_MODE_ALT1);
  assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                 PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE));  
}

/************************************************************************************
* Test ID :TestCase5
* Description: Test for Port_SetPinMode report a PORT_E_PARAM_INVALID_MODE
*              DET error in case the API is called with an invalid pin mode
* Pre-requisits: 1. Port is initialized before running this test case.
*                2. Configure PORT_B_PIN_0 mode as changeable
* Test Procedure : Call Port_SetPinMode with an invalid pin mode
*************************************************************************************/
void TestCase5(void)
{
  Port_SetPinMode(PORT_B_PIN_0, INVALID_PIN_MODE);
  assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                 PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE));  
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/************************************************************************************
* Test ID :TestCase6
* Description: Test for Port_SetPinDirection report a PORT_E_DIRECTION_UNCHANGEABLE
*              DET error in case the API is called with a pin that
*              its direction is configured unchangable
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : Call Port_SetPinDirection with a pin that its direction is configured unchangable
*************************************************************************************/
void TestCase6(void)
{
  Port_SetPinDirection(PORT_A_PIN_0, PORT_PIN_OUT);
  assert(Det_TestLastReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                 PORT_SET_PIN_DIRECTION_API, PORT_E_DIRECTION_UNCHANGEABLE)); 
}
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

#if (PORT_VERSION_INFO_API == STD_ON)
/************************************************************************************
* Test ID :TestCase7
* Description: Test for Port_GetVersionInfo API functionality
* Pre-requisits: Port is initialized before running this test case.
* Test Procedure : Call Port_GetVersionInfo and get the required information
*************************************************************************************/
void TestCase7(void)
{
  Port_GetVersionInfo(&Version_Info);
  assert(Version_Info.vendorID == PORT_VENDOR_ID);
  assert(Version_Info.moduleID == PORT_MODULE_ID);
  assert(Version_Info.sw_major_version == PORT_SW_MAJOR_VERSION);
  assert(Version_Info.sw_minor_version == PORT_SW_MINOR_VERSION);
  assert(Version_Info.sw_patch_version == PORT_SW_PATCH_VERSION);
}
#endif /* (PORT_VERSION_INFO_API == STD_ON) */