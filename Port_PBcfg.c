/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Dio_Init API */
const Port_ConfigType Port_Configuration =
{{
    /***********************PORT_A_PIN_0***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_0,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
   },
    /***********************PORT_A_PIN_1***********************/
   { 
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_1,                       //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                        //pin_resistor
   },
    /***********************PORT_A_PIN_2***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_2,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_A_PIN_3***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_3,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_A_PIN_4***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_4,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_A_PIN_5***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_5,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_A_PIN_6***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_6,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_A_PIN_7***********************/
  {
    PORT_A,                     //port_num (A,B,C,D,E,F)
    PIN_7,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_0***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_0,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_ON,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_ON,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_1***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_1,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_2***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_2,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_3***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_3,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_4***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_4,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_5***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_5,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_6***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_6,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_B_PIN_7***********************/
  {
    PORT_B,                     //port_num (A,B,C,D,E,F)
    PIN_7,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_C_PIN_4***********************/
  {
    PORT_C,                     //port_num (A,B,C,D,E,F)
    PIN_4,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_C_PIN_5***********************/
  {
    PORT_C,                     //port_num (A,B,C,D,E,F)
    PIN_5,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_C_PIN_6***********************/
  {
    PORT_C,                     //port_num (A,B,C,D,E,F)
    PIN_6,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_C_PIN_7***********************/
  {
    PORT_C,                     //port_num (A,B,C,D,E,F)
    PIN_7,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_0***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_0,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_1***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_1,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_2***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_2,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_3***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_3,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_4**********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_4,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_5***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_5,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_6***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_6,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_D_PIN_7***********************/
  {
    PORT_D,                     //port_num (A,B,C,D,E,F)
    PIN_7,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_E_PIN_0***********************/
  {
    PORT_E,                     //port_num (A,B,C,D,E,F)
    PIN_0,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_E_PIN_1***********************/
  {
    PORT_E,                     //port_num (A,B,C,D,E,F)
    PIN_1,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_E_PIN_2***********************/
  {
    PORT_E,                     //port_num (A,B,C,D,E,F)
    PIN_2,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_E_PIN_3***********************/
  {
    PORT_E,                     //port_num (A,B,C,D,E,F)
    PIN_3,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_E_PIN_4***********************/
  {
    PORT_E,                     //port_num (A,B,C,D,E,F)
    PIN_4,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_E_PIN_5***********************/
  {
    PORT_E,                     //port_num (A,B,C,D,E,F)
    PIN_5,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_F_PIN_0***********************/
  {
    PORT_F,                     //port_num (A,B,C,D,E,F)
    PIN_0,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_F_PIN_1***********************/
  {
    PORT_F,                     //port_num (A,B,C,D,E,F)
    PIN_1,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_OUT,               //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,        //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_F_PIN_2***********************/
  {
    PORT_F,                     //port_num (A,B,C,D,E,F)
    PIN_2,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,               //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,        //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_F_PIN_3***********************/
  {
    PORT_F,                     //port_num (A,B,C,D,E,F)
    PIN_3,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    OFF                         //pin_resistor
  },
    /***********************PORT_F_PIN_4***********************/
  {//SW1
    PORT_F,                     //port_num (A,B,C,D,E,F)
    PIN_4,                      //pin_num (0,1,2,3,4,5,6,7)
    PORT_PIN_MODE_DIO,          //pin_mode
    STD_OFF,                    //configure mode change
    PORT_PIN_IN,                //pin_direction
    STD_OFF,                    //configure direction change
    PORT_PIN_LEVEL_LOW,         //pin_level
    PULL_UP                         //pin_resistor
  }
}};