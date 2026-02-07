/******************************************************************************
 * Module: PB
 * File Name: PB_program.c
 * Description: Source file for the PB driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "PB_interface.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Initializes a push button.
 * @param Button Pointer to the button configuration.
 * @return void
 */
void PB_init(const PB_t *Button)
{
    // The application is responsible for configuring the button pin as an input
    // with a pull-up resistor via DIO_config.h and calling DIO_init().
    // This function is provided for API consistency.
}

/**
 * @brief Reads the state of a push button.
 * @param Button Pointer to the button configuration.
 * @param State Pointer to a variable to store the button state.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType PB_read(const PB_t *Button, PB_State_t *State)
{
    if (Button == NULL || State == NULL) return E_NOT_OK;

    DIO_PinValue_t pin_value;
    Std_ReturnType ret = DIO_readPin(Button->Port, Button->Pin, &pin_value);

    if (ret == E_OK)
    {
        // Assuming active-low configuration (internal pull-up)
        if (pin_value == DIO_PIN_LOW)
        {
            *State = PB_PRESSED;
        }
        else
        {
            *State = PB_RELEASED;
        }
    }

    return ret;
}
