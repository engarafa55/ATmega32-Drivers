/******************************************************************************
 * Module: LED
 * File Name: LED_program.c
 * Description: Source file for the LED driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "LED_interface.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Turns on the specified LED.
 * @param  led Pointer to the LED object.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LED_turnOn(const LED_t *led)
{
    if (led == NULL) return E_NOT_OK;
    return DIO_writePin(led->Port, led->Pin, DIO_PIN_HIGH);
}

/**
 * @brief  Turns off the specified LED.
 * @param  led Pointer to the LED object.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LED_turnOff(const LED_t *led)
{
    if (led == NULL) return E_NOT_OK;
    return DIO_writePin(led->Port, led->Pin, DIO_PIN_LOW);
}

/**
 * @brief  Toggles the state of the specified LED.
 * @param  led Pointer to the LED object.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LED_toggle(const LED_t *led)
{
    if (led == NULL) return E_NOT_OK;
    return DIO_togglePin(led->Port, led->Pin);
}
