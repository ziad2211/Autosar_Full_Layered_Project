 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: Header file for LED module
 *
 * Date: 11 April 2022
 * Author: Ziad Abdallah
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "STD_Types.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW

/* Description: Set the LED state to ON */
void LED_setOn(void);

/* Description: Set the LED state to OFF */
void LED_setOff(void);

/*Description: Toggle the LED state */
void LED_toggle(void);

/* Description: Refresh the LED state */
void LED_refreshOutput(void);

#endif /*LED_H*/