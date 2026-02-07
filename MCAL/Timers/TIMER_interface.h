/******************************************************************************
 * Module: TIMER
 * File Name: TIMER_interface.h
 * Description: Header file for the Timer driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum
{
    TIMER0,
    TIMER1,
    TIMER2
} TIMER_ID_t;

typedef enum
{
    TIMER_MODE_NORMAL,
    TIMER_MODE_CTC,
    TIMER_MODE_FAST_PWM,
    TIMER_MODE_PHASE_CORRECT_PWM
} TIMER_Mode_t;

typedef enum
{
    TIMER_PRESCALER_STOP,
    TIMER_PRESCALER_1,
    TIMER_PRESCALER_8,
    TIMER_PRESCALER_64,
    TIMER_PRESCALER_256,
    TIMER_PRESCALER_1024
} TIMER_Prescaler_t;

typedef enum
{
    TIMER_OC_DISCONNECTED,
    TIMER_OC_TOGGLE,
    TIMER_OC_CLEAR, // Non-inverting for PWM
    TIMER_OC_SET    // Inverting for PWM
} TIMER_OC_Mode_t;

typedef enum
{
    ICU_EDGE_FALLING,
    ICU_EDGE_RISING
} TIMER_ICU_Edge_t;

typedef struct
{
    TIMER_ID_t          TimerID;
    TIMER_Mode_t        Mode;
    TIMER_Prescaler_t   Prescaler;
    TIMER_OC_Mode_t     OC_Mode; // For OC0, OC1A, OC1B, OC2
    uint16              CompareValue; // Used for CTC and PWM duty cycle
    uint16              TopValue;     // Used for ICR1 or OCR1A top in PWM modes
} TIMER_Config_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes a timer with the given configuration.
 * @param  ConfigPtr Pointer to the timer configuration structure.
 * @return void
 */
void TIMER_init(const TIMER_Config_t *ConfigPtr);

/**
 * @brief  De-initializes a timer, stopping it and disabling its interrupts.
 * @param  TimerID The ID of the timer to de-initialize.
 * @return void
 */
void TIMER_deinit(TIMER_ID_t TimerID);

/**
 * @brief  Sets the compare value for a timer.
 * @param  TimerID The ID of the timer.
 * @param  Value The compare value to set.
 * @return void
 */
void TIMER_setCompareValue(TIMER_ID_t TimerID, uint16 Value);

/**
 * @brief  Sets the duty cycle for a timer in PWM mode.
 * @param  TimerID The ID of the timer.
 * @param  DutyCycle The duty cycle from 0.0 to 100.0.
 * @return void
 */
void TIMER_setDutyCycle(TIMER_ID_t TimerID, float32 DutyCycle);

/**
 * @brief  Sets the callback function for a timer interrupt.
 * @param  TimerID The ID of the timer.
 * @param  CallbackFunc Pointer to the callback function.
 * @return void
 */
void TIMER_setCallback(TIMER_ID_t TimerID, void (*CallbackFunc)(void));

/**
 * @brief  Initializes the Input Capture Unit (ICU) for Timer1.
 * @param  Edge The initial edge to trigger the ICU.
 * @return void
 */
void TIMER_icu_init(TIMER_ICU_Edge_t Edge);

/**
 * @brief  Sets the edge for the Input Capture Unit (ICU).
 * @param  Edge The edge to set (rising or falling).
 * @return void
 */
void TIMER_icu_setEdge(TIMER_ICU_Edge_t Edge);

/**
 * @brief  Reads the value of the Input Capture Register (ICR1).
 * @param  void
 * @return The value of ICR1.
 */
uint16 TIMER_icu_readInput(void);

/**
 * @brief  Sets the callback function for the ICU interrupt.
 * @param  CallbackFunc Pointer to the callback function.
 * @return void
 */
void TIMER_icu_setCallback(void (*CallbackFunc)(void));

#endif /* TIMER_INTERFACE_H_ */
