/******************************************************************************
 * Module: DIO
 * File Name: DIO_interface.h
 * Description: Header file for the DIO driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1
typedef uint8 DIO_PinDirection_t;

#define DIO_PIN_LOW    0
#define DIO_PIN_HIGH   1
typedef uint8 DIO_PinValue_t;

typedef enum
{
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} DIO_Port_t;

typedef enum
{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
} DIO_Pin_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes all DIO pins to the directions and initial values
 *         specified in the DIO_config.h file.
 * @param  void
 * @return void
 */
void DIO_init(void);

/**
 * @brief  Sets a specific pin to a high or low value.
 * @param  Port The port of the pin (DIO_PORTA, DIO_PORTB, etc.).
 * @param  Pin The pin number (DIO_PIN0, DIO_PIN1, etc.).
 * @param  Value The value to set (DIO_PIN_HIGH or DIO_PIN_LOW).
 * @return Std_ReturnType E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType DIO_writePin(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t Value);

/**
 * @brief  Reads the value of a specific pin.
 * @param  Port The port of the pin.
 * @param  Pin The pin number.
 * @param  Value Pointer to a variable to store the pin's value.
 * @return Std_ReturnType E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType DIO_readPin(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t *Value);

/**
 * @brief  Toggles the value of a specific pin (HIGH -> LOW, LOW -> HIGH).
 * @param  Port The port of the pin.
 * @param  Pin The pin number.
 * @return Std_ReturnType E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType DIO_togglePin(DIO_Port_t Port, DIO_Pin_t Pin);

/**
 * @brief  Sets the value of an entire port.
 * @param  Port The port to write to.
 * @param  Value The 8-bit value to write to the port.
 * @return Std_ReturnType E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType DIO_writePort(DIO_Port_t Port, uint8 Value);

/**
 * @brief  Reads the value of an entire port.
 * @param  Port The port to read from.
 * @param  Value Pointer to a variable to store the port's value.
 * @return Std_ReturnType E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType DIO_readPort(DIO_Port_t Port, uint8 *Value);

#endif /* DIO_INTERFACE_H_ */
