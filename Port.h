 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Ziad Abdallah's ID = 2000 :) */
#define PORT_VENDOR_ID    (2000U)

/* PORT Module Id */
#define PORT_MODULE_ID    (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"
   
/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C
   
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/*Service ID for Port Init*/
#define PORT_INIT_SID                           (uint8)0x00
   
/*Service ID for Port Set Pin Direction*/
#define PORT_SET_PIN_DIRECTION_SID              (uint8)0x01
   
/*Service ID for Port Refresh Port Direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID         (uint8)0x02
   
/*Service ID for Port Get Version Info*/
#define PORT_GET_VERSION_INFO_SID               (uint8)0x03
   
/*Service ID for Port Set Pin Mode*/
#define PORT_SET_PIN_MODE_SID                   (uint8)0x04
   
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/*DET code to report Invalid Port Pin ID*/
#define PORT_E_PARAM_PIN                (uint8)0x0A

/*DET code to report Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B
   
/*DET code to report Port Init service called with wrong parameter*/
#define PORT_E_PARAM_CONFIG             (uint8)0x0C
   
/*DET code to report Port Pin Mode passed not valid*/
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
   
/*DET code to report Port_SetPinMode service called when the mode is unchangeable*/
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E
   
/*DET code to report that API service called without module initialization*/
#define PORT_E_UNINIT                   (uint8)0x0F

/*DET code to report APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER            (uint8)0x10
   
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/*Data type for the symbolic name of a port pin.(e.g: PORT_A_PIN_0)*/
typedef uint8   Port_PinType;

/*Data type for the symbolic name of a port.(e.g: PORT_A)*/
typedef uint8   Port_PortType;

/*Data type for different port pin modes.*/
typedef uint8   Port_PinModeType;

/*Description: ENUM to hold possible directions of a port pin.*/
typedef enum
{
  PORT_PIN_IN,                  //Sets port pin as input.
  PORT_PIN_OUT                  //Sets port pin as output.
}Port_PinDirectionType;

/*Description: ENUM to hold possible levels of a port pin.*/
typedef enum
{
  PORT_PIN_LEVEL_LOW,           //Sets port pin level to low.
  PORT_PIN_LEVEL_HIGH           //Sets port pin level to high.
}Port_PinLevelType;

/*Description: Enum to hold internal resistor type for port pin */
typedef enum
{
    OFF,                        //Disable internal resistors
    PULL_UP,                    //Enable pull up resistor
    PULL_DOWN                   //Enable pull down resistor
}Port_PinInternalResistor;

/*Description: Structure containing the initialization data for each port
* 1) Port num (e.g: PORT_A)
* 2) Pin num (e.g: PIN_0)
* 3) Pin Mode (DIO, Analog, CAN, PWM,...)
* 4) Pin Mode Changeability (changeable, not changeable)
* 5) Pin Direction (Input,Output)
* 6) Pin Direction Changeability (changeable, not changeable)
* 7) Pin Initial Level (LOW,HIGH)
* 8) Pin Internal Resistor (OFF, PULL UP, PULL DOWN)
*/
typedef struct
{
  uint8                         port_num;
  uint8                         pin_num;
  Port_PinModeType              pin_mode;
  boolean                       pin_mode_change;
  Port_PinDirectionType         pin_direction;
  boolean                       pin_direction_change;
  Port_PinLevelType             pin_init_level;
  Port_PinInternalResistor      pin_resistor;
}Port_ConfigPin;

/* Data Structure required for initializing the Port Driver 
* Pin symbolic name = index to its corrosponding element structure*/
typedef struct
{
  Port_ConfigPin Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Service ID: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.:
*              - Setup the pin mode
*              - Setup the pin direction
*              - Setup the pin initial level 
*              - Setup the pin internal resistor
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr );

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port Pin ID number, Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set the pin direction
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin,
                           Port_PinDirectionType Direction );
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refresh the direction of all configured ports to the configured direction
*              except those port pins from refreshing that
*              are configured as ‘pin direction changeable during runtime'.
************************************************************************************/
void Port_RefreshPortDirection( void );

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): Version Info - Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port Pin ID number, New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode in runtime.
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin,
                      Port_PinModeType Mode );

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;
extern volatile boolean Port_Status; //this variable is external to check port initialization in DIO driver
#endif /*PORT_H*/