 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/
#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPin * Port_Pins = NULL_PTR;
volatile boolean Port_Status = PORT_NOT_INITIALIZED;
/*put base addresses in an array to be fethced*/
STATIC const uint32 base_address[PORT_CONFIGURED_PORTS] = {
                                                          GPIO_PORTA_BASE_ADDRESS,
                                                          GPIO_PORTB_BASE_ADDRESS,
                                                          GPIO_PORTC_BASE_ADDRESS,
                                                          GPIO_PORTD_BASE_ADDRESS,
                                                          GPIO_PORTE_BASE_ADDRESS,
                                                          GPIO_PORTF_BASE_ADDRESS
                                                       };

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
*              - Setup the pin internal resistor
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                          PORT_INIT_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
        {
          Port_Pins = ConfigPtr->Pins; /*address of the first structure in the array pins - Pins[0]*/
          
          volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
          volatile uint32 delay = 0;

          
          /*loop through all the configured pins to initialize them
            skip PORT_C_PIN_0 through PORT_C_PIN_3*/
          for(Port_PinType Pin=0; Pin<PORT_CONFIGURED_PINS; Pin++)
          {
            if((Port_Pins[Pin].port_num==PORT_C)&&(Port_Pins[Pin].pin_num<=PIN_3))
            {
              /*Skip them and do nothing as these are the JTAG Pins*/
            }
            else
            {
              /*point to the required Port Registers base address */
              Port_Ptr = (volatile uint32 *)base_address[Port_Pins[Pin].port_num];
              
              /* Enable clock for PORT and allow time for clock to start*/
              SYSCTL_REGCGC2_REG |= (1<<Port_Pins[Pin].port_num);
              delay = SYSCTL_REGCGC2_REG;
              
              /*Unlock commit register for pins PD7 and PF0*/
              if((Pin == PORT_D_PIN_7)||(Pin == PORT_F_PIN_0))
              {
                *(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B; /* Unlock the GPIOCR register */ 
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_COMMIT_REG_OFFSET),Port_Pins[Pin].pin_num); /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
              }
              else
              {
                /*no action required...the other pins need no unlock or commit*/
              }
              
              /*Configure the pin mode*/
              if(Port_Pins[Pin].pin_mode==PORT_PIN_MODE_DIO)
              {
                /*Disable analog mode*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Clear alternative function*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*clear the PMCx bits in GPIOCTL*/
                (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(0x0000000F<<(Port_Pins[Pin].pin_num*4));
              }
              else if(Port_Pins[Pin].pin_mode==PORT_PIN_MODE_ANALOG)
              {
                /*clear digital enable*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Enable analog mode*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Clear alternative function*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Clear the pin corresponding control register*/
                (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(0x0000000F<<(Port_Pins[Pin].pin_num*4));
              }
              else //alternative function
              {
                /*Disable analog mode*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Set alternative function*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Clear the pin corresponding control register*/
                (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(0x0000000F<<(Port_Pins[Pin].pin_num*4));
                /*Set the PMCx bits in GPIOCTL to select the function*/
                (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) |= (Port_Pins[Pin].pin_mode<<(Port_Pins[Pin].pin_num*4));
              }
              
              /*Configure pin direction*/
              if(Port_Pins[Pin].pin_direction == PORT_PIN_OUT)
              {
                /*Set corresponding bit to make it output*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIR_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              else //set by default to input
              {
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIR_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
                          
              /*Configure initial level*/
              if(Port_Pins[Pin].pin_init_level == PORT_PIN_LEVEL_HIGH)
              {
                /*Set corresponding bit in data register to output HIGH*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DATA_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              else //Clear the corresponding bit in data register to output HIGH
              {
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DATA_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              
             /*Configure internal resistor*/
              if(Port_Pins[Pin].pin_resistor==PULL_UP)
              {
                /*set the corresponding bit to enable pull up resistor*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_PULL_UP_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              else if(Port_Pins[Pin].pin_resistor==PULL_DOWN)
              {
                /*set the corresponding bit to enable pull down resistor*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              else //disable internal resistor by default
              {
                /*Clear the corresponding bit to disable pull down register*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET),Port_Pins[Pin].pin_num);
                /*Clear the corresponding bit to disable pull up register*/
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_PULL_UP_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              
              /*Digital enable if it is not in the analog mode*/
              if (!(Port_Pins[Pin].pin_mode==PORT_PIN_MODE_ANALOG))
              {
                /*Set the corresponding bit in the GPIODEN to digital enable*/
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pins[Pin].pin_num);
              }
              else //the pin is in analog mode
              {
                /*no action required as it is already disabled in the analog mode case above*/
              }
            }
          }
          /*Now the port is completely initialized*/
          Port_Status = PORT_INITIALIZED;
        }
}


/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port Pin ID number, Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.:
*              - Set the pin direction
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin,
                           Port_PinDirectionType Direction )
{
  volatile uint32 * Port_Ptr = NULL_PTR;
  boolean error = FALSE;
  
  
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Check if the port is initialized*/
  if(Port_Status == PORT_NOT_INITIALIZED)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_DIRECTION_SID , PORT_E_UNINIT);
    error = TRUE;
  }
  else
  {
    /*No action required*/
  }
  
  /*Check if the passed pin ID is within the range of the configured pins*/
  if(Pin>=PORT_CONFIGURED_PINS)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_DIRECTION_SID , PORT_E_PARAM_PIN );
    error = TRUE;
  }
  else
  {
    /*No action required*/
  }
  
  /*Check if the pin is changeable*/
  if(Port_Pins[Pin].pin_direction_change == STD_OFF)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_DIRECTION_SID , PORT_E_DIRECTION_UNCHANGEABLE);
    error = TRUE;
  }
  else
  {
    /*No action required*/
  }
#endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
  if(error == FALSE)
  {
    /*point to the required Port Registers base address */
    Port_Ptr = (volatile uint32 *)base_address[Port_Pins[Pin].port_num];
    
    /*Configure pin direction*/
    if(Direction == PORT_PIN_OUT)
    {
      /*Set corresponding bit to make it output*/
      SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIR_REG_OFFSET),Port_Pins[Pin].pin_num);
    }
    else //set to input
    {
      CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIR_REG_OFFSET),Port_Pins[Pin].pin_num);
    }
  }
}
#endif /*(PORT_SET_PIN_DIRECTION_API == STD_ON)*/

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
void Port_RefreshPortDirection( void )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Check if the port is initialized*/
  if(Port_Status == PORT_NOT_INITIALIZED)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_REFRESH_PORT_DIRECTION_SID , PORT_E_UNINIT);
   }
  else
#endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
 { 
  volatile uint32 * Port_Ptr = NULL_PTR;
  for(Port_PinType Pin=0; Pin<PORT_CONFIGURED_PINS; Pin++)
  {
    /*check if the pin direction is changeable during run time*/
    if(Port_Pins[Pin].pin_direction_change == STD_ON)
    {
      /*do not refresh this pin
      * No action required*/
    }
    else //if the pin direction is not changeable during run time
    {
      /*point to the required Port Registers base address */
      Port_Ptr = (volatile uint32 *)base_address[Port_Pins[Pin].port_num];
      
      /*Refresh its direction*/
      if(Port_Pins[Pin].pin_direction == PORT_PIN_OUT)
      {
         /*Set corresponding bit to make it output*/
         SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIR_REG_OFFSET),Port_Pins[Pin].pin_num);
      }
      else //set to input
      {
        CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIR_REG_OFFSET),Port_Pins[Pin].pin_num);
      }
    }
  }
 }
}

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
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Check if the port is initialized*/
  if(Port_Status == PORT_NOT_INITIALIZED)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
    error = TRUE;
  }
  else
  {
    /*No action required*/
  }
  
  /*Check that API is not called with a NULL pointer*/
  if (NULL_PTR == versioninfo)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    error = TRUE;
  }
  else
  {
    /*No action required*/
  }
#endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
  if(error == FALSE)
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
  }
}
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
                      Port_PinModeType Mode )
{
    volatile uint32 * Port_Ptr = NULL_PTR;
    boolean error = FALSE;
  
  
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Check if the port is initialized*/
  if(Port_Status == PORT_NOT_INITIALIZED)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_MODE_SID , PORT_E_UNINIT);
    error = TRUE;
  }
  
  /*Check if the passed pin ID is within the range of the configured pins*/
  else if(Pin>=PORT_CONFIGURED_PINS)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_MODE_SID , PORT_E_PARAM_PIN );
    error = TRUE;
  }
  
  /*Check if the pin is changeable*/
  else if(Port_Pins[Pin].pin_mode_change == STD_OFF)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_MODE_SID , PORT_E_MODE_UNCHANGEABLE);
    error = TRUE;
  }  
  
  /*Check if the passed mode is available*/
  else if(Mode >= PORT_CONFIGURED_MODES)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_PIN_MODE_SID , PORT_E_PARAM_INVALID_MODE);
    error = TRUE;
  }
  else
  {
    /*No action required*/
  }
#endif /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
  
  if(error == FALSE)
  {
    /*point to the required Port Registers base address */
    Port_Ptr = (volatile uint32 *)base_address[Port_Pins[Pin].port_num];
    
    /*Configure the pin mode*/
    if(Mode==PORT_PIN_MODE_DIO)
    {
      /*Disable analog mode*/
      CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*Clear alternative function*/
      CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*clear the PMCx bits in GPIOCTL*/
      (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(0x0000000F<<(Port_Pins[Pin].pin_num*4));
      /*Enable digital mode*/
      /*Set the corresponding bit in the GPIODEN to digital enable*/
      SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pins[Pin].pin_num);
    }
    else if(Mode==PORT_PIN_MODE_ANALOG)
    {
      /*clear digital enable*/
      CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*Enable analog mode*/
      SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*Clear alternative function*/
      CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*Clear the pin corresponding control register*/
      (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(0x0000000F<<(Port_Pins[Pin].pin_num*4));
    }
    else //alternative function
    {
      /*Disable analog mode*/
      CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*Set alternative function*/
      SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET),Port_Pins[Pin].pin_num);
      /*Clear the pin corresponding control register*/
      (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) &= ~(0x0000000F<<(Port_Pins[Pin].pin_num*4));
      /*Set the PMCx bits in GPIOCTL to select the function*/
      (*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_CTL_REG_OFFSET)) |= (Port_Pins[Pin].pin_mode<<(Port_Pins[Pin].pin_num*4));
      /*Enable digital mode*/
      /*Set the corresponding bit in the GPIODEN to digital enable*/
      SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pins[Pin].pin_num);
    }
  }
}