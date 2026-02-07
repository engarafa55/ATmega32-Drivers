/******************************************************************************
 * Module: EXTI
 * File Name: EXTI_program.c
 * Description: Source file for the EXTI driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "../../Includes/BIT_MACROS.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/
// Array of function pointers to hold the callback functions for each interrupt.
static void (* volatile g_CallbackPtr[3])(void) = {NULL, NULL, NULL};

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initializes the EXTI with the given configuration.
 * @param  ConfigPtr Pointer to the EXTI configuration structure.
 * @return void
 */
void EXTI_init(const EXTI_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    switch (ConfigPtr->Interrupt)
    {
        case EXTI_INT0:
            // Set sense control for INT0
            MCUCR = (MCUCR & 0xFC) | (ConfigPtr->SenseControl);
            // Enable INT0
            SET_BIT(GICR, INT0_BIT);
            break;
        case EXTI_INT1:
            // Set sense control for INT1
            MCUCR = (MCUCR & 0xF3) | (ConfigPtr->SenseControl << ISC10_BIT);
            // Enable INT1
            SET_BIT(GICR, INT1_BIT);
            break;
        case EXTI_INT2:
            // Set sense control for INT2
            if (ConfigPtr->SenseControl == EXTI_SENSE_FALLING_EDGE)
            {
                CLEAR_BIT(MCUCSR, ISC2_BIT);
            }
            else if (ConfigPtr->SenseControl == EXTI_SENSE_RISING_EDGE)
            {
                SET_BIT(MCUCSR, ISC2_BIT);
            }
            // Enable INT2
            SET_BIT(GICR, INT2_BIT);
            break;
    }

    // Set the callback function if provided
    if (ConfigPtr->Callback != NULL)
    {
        g_CallbackPtr[ConfigPtr->Interrupt] = ConfigPtr->Callback;
    }
}

/**
 * @brief  Enables a specific external interrupt.
 * @param  Interrupt The interrupt to enable (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @return void
 */
void EXTI_enable(EXTI_Interrupt_t Interrupt)
{
    switch (Interrupt)
    {
        case EXTI_INT0: SET_BIT(GICR, INT0_BIT); break;
        case EXTI_INT1: SET_BIT(GICR, INT1_BIT); break;
        case EXTI_INT2: SET_BIT(GICR, INT2_BIT); break;
    }
}

/**
 * @brief  Disables a specific external interrupt.
 * @param  Interrupt The interrupt to disable (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @return void
 */
void EXTI_disable(EXTI_Interrupt_t Interrupt)
{
    switch (Interrupt)
    {
        case EXTI_INT0: CLEAR_BIT(GICR, INT0_BIT); break;
        case EXTI_INT1: CLEAR_BIT(GICR, INT1_BIT); break;
        case EXTI_INT2: CLEAR_BIT(GICR, INT2_BIT); break;
    }
}

/**
 * @brief  Sets the callback function for a specific external interrupt.
 * @param  Interrupt The interrupt to which the callback is assigned.
 * @param  Callback Pointer to the callback function.
 * @return void
 */
void EXTI_setCallback(EXTI_Interrupt_t Interrupt, void (*Callback)(void))
{
    if (Callback != NULL)
    {
        g_CallbackPtr[Interrupt] = Callback;
    }
}

// ISR for INT0
ISR(INT0_vect)
{
    if (g_CallbackPtr[EXTI_INT0] != NULL)
    {
        g_CallbackPtr[EXTI_INT0]();
    }
}

// ISR for INT1
ISR(INT1_vect)
{
    if (g_CallbackPtr[EXTI_INT1] != NULL)
    {
        g_CallbackPtr[EXTI_INT1]();
    }
}

// ISR for INT2
ISR(INT2_vect)
{
    if (g_CallbackPtr[EXTI_INT2] != NULL)
    {
        g_CallbackPtr[EXTI_INT2]();
    }
}
