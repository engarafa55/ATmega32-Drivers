/******************************************************************************
 * Module: EXTI
 * File Name: EXTI_interface.h
 * Description: Header file for the EXTI driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum {
    EXTI_INT0,
    EXTI_INT1,
    EXTI_INT2
} EXTI_Interrupt_t;

typedef enum {
    EXTI_SENSE_LOW_LEVEL,
    EXTI_SENSE_ANY_CHANGE,
    EXTI_SENSE_FALLING_EDGE,
    EXTI_SENSE_RISING_EDGE
} EXTI_SenseControl_t;

typedef struct {
    EXTI_Interrupt_t    Interrupt;
    EXTI_SenseControl_t SenseControl;
    void (*Callback)(void); // Pointer to the callback function
} EXTI_Config_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the EXTI with the given configuration.
 * @param  ConfigPtr Pointer to the EXTI configuration structure.
 * @return void
 */
void EXTI_init(const EXTI_Config_t *ConfigPtr);

/**
 * @brief  Enables a specific external interrupt.
 * @param  Interrupt The interrupt to enable (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @return void
 */
void EXTI_enable(EXTI_Interrupt_t Interrupt);

/**
 * @brief  Disables a specific external interrupt.
 * @param  Interrupt The interrupt to disable (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @return void
 */
void EXTI_disable(EXTI_Interrupt_t Interrupt);

/**
 * @brief  Sets the callback function for a specific external interrupt.
 * @param  Interrupt The interrupt to which the callback is assigned.
 * @param  Callback Pointer to the callback function.
 * @return void
 */
void EXTI_setCallback(EXTI_Interrupt_t Interrupt, void (*Callback)(void));

#endif /* EXTI_INTERFACE_H_ */
