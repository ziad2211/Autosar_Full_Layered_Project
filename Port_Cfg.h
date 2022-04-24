 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H
/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Port Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

/*Pre-compile option for Port Get Version Info API*/
#define PORT_VERSION_INFO_API                (STD_ON)
   
/* Number of the configured pins in the ports*/
#define PORT_CONFIGURED_PINS             (39U)
   
/* Number of the configured pins in the ports*/
#define PORT_CONFIGURED_PORTS           (7U)
   
/*Port pin symbolic name = index in the array of structures in the Port_PBcfg.h*/
/*PORT A Symbolic Name*/
#define PORT_A_PIN_0            (Port_PinType)0
#define PORT_A_PIN_1            (Port_PinType)1
#define PORT_A_PIN_2            (Port_PinType)2
#define PORT_A_PIN_3            (Port_PinType)3
#define PORT_A_PIN_4            (Port_PinType)4
#define PORT_A_PIN_5            (Port_PinType)5
#define PORT_A_PIN_6            (Port_PinType)6
#define PORT_A_PIN_7            (Port_PinType)7

/*PORT B Symbolic Name*/
#define PORT_B_PIN_0            (Port_PinType)8
#define PORT_B_PIN_1            (Port_PinType)9
#define PORT_B_PIN_2            (Port_PinType)10
#define PORT_B_PIN_3            (Port_PinType)11
#define PORT_B_PIN_4            (Port_PinType)12
#define PORT_B_PIN_5            (Port_PinType)13
#define PORT_B_PIN_6            (Port_PinType)14
#define PORT_B_PIN_7            (Port_PinType)15

/*PORT C Symbolic Name*/
#define PORT_C_PIN_4            (Port_PinType)16
#define PORT_C_PIN_5            (Port_PinType)17
#define PORT_C_PIN_6            (Port_PinType)18
#define PORT_C_PIN_7            (Port_PinType)19
   
/*PORT D Symbolic Name*/
#define PORT_D_PIN_0            (Port_PinType)20
#define PORT_D_PIN_1            (Port_PinType)21
#define PORT_D_PIN_2            (Port_PinType)22
#define PORT_D_PIN_3            (Port_PinType)23
#define PORT_D_PIN_4            (Port_PinType)24
#define PORT_D_PIN_5            (Port_PinType)25
#define PORT_D_PIN_6            (Port_PinType)26
#define PORT_D_PIN_7            (Port_PinType)27
   
/*PORT E Symbolic Name*/
#define PORT_E_PIN_0            (Port_PinType)28
#define PORT_E_PIN_1            (Port_PinType)29
#define PORT_E_PIN_2            (Port_PinType)30
#define PORT_E_PIN_3            (Port_PinType)31
#define PORT_E_PIN_4            (Port_PinType)32
#define PORT_E_PIN_5            (Port_PinType)33
   
/*PORT F Symbolic Name*/
#define PORT_F_PIN_0            (Port_PinType)34
#define PORT_F_PIN_1            (Port_PinType)35
#define PORT_F_PIN_2            (Port_PinType)36
#define PORT_F_PIN_3            (Port_PinType)37
#define PORT_F_PIN_4            (Port_PinType)38

/*************************************************/
/*Configured PORTS IDs*/
#define PORT_A                  (Port_PortType)0
#define PORT_B                  (Port_PortType)1
#define PORT_C                  (Port_PortType)2
#define PORT_D                  (Port_PortType)3
#define PORT_E                  (Port_PortType)4
#define PORT_F                  (Port_PortType)5
   
/*Configured PINs IDs*/
#define PIN_0                   (Port_PinType)0
#define PIN_1                   (Port_PinType)1
#define PIN_2                   (Port_PinType)2
#define PIN_3                   (Port_PinType)3
#define PIN_4                   (Port_PinType)4
#define PIN_5                   (Port_PinType)5
#define PIN_6                   (Port_PinType)6
#define PIN_7                   (Port_PinType)7

/*Pin Modes*/
/* In TM4C123GH6PM, each pin has different modes 0:9 and 14:15
* Refer to MCU datasheet to choose the pin's mode*/
#define PORT_CONFIGURED_MODES    (16u)  //Number of port configured modes
#define PORT_PIN_MODE_DIO        (Port_PinModeType)0
#define PORT_PIN_MODE_ALT1       (Port_PinModeType)1
#define PORT_PIN_MODE_ALT2       (Port_PinModeType)2
#define PORT_PIN_MODE_ALT3       (Port_PinModeType)3
#define PORT_PIN_MODE_ALT4       (Port_PinModeType)4
#define PORT_PIN_MODE_ALT5       (Port_PinModeType)5
#define PORT_PIN_MODE_ALT6       (Port_PinModeType)6
#define PORT_PIN_MODE_ALT7       (Port_PinModeType)7
#define PORT_PIN_MODE_ALT8       (Port_PinModeType)8
#define PORT_PIN_MODE_ALT9       (Port_PinModeType)9
#define PORT_PIN_MODE_ALT_14     (Port_PinModeType)14
#define PORT_PIN_MODE_ANALOG     (Port_PinModeType)15

#endif