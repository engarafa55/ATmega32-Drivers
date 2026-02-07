/******************************************************************************
 * Module: LED
 * File Name: LED_interface.h
 * Description: Header file for the LED driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../MCAL/DIO/DIO_interface.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef struct {
  DIO_Port_t Port;
  DIO_Pin_t  Pin;
} LED_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Turns on the specified LED.
 * @param  led Pointer to the LED object.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LED_turnOn(const LED_t *led);

/**
 * @brief  Turns off the specified LED.
 * @param  led Pointer to the LED object.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LED_turnOff(const LED_t *led);

/**
 * @brief  Toggles the state of the specified LED.
 * @param  led Pointer to the LED object.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LED_toggle(const LED_t *led);

#endif /* LED_INTERFACE_H_ */
