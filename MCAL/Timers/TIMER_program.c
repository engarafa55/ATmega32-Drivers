/******************************************************************************
 * Module: TIMER
 * File Name: TIMER_program.c
 * Description: Source file for the Timer driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/BIT_MACROS.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/
static void (* volatile g_Timer0_Callback)(void) = NULL;
static void (* volatile g_Timer1_Callback)(void) = NULL;
static void (* volatile g_Timer2_Callback)(void) = NULL;
static void (* volatile g_ICU_Callback)(void) = NULL;

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initializes a timer with the given configuration.
 * @param  ConfigPtr Pointer to the timer configuration structure.
 * @return void
 */
void TIMER_init(const TIMER_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    switch (ConfigPtr->TimerID)
    {
        case TIMER0:
            // Set Mode (Normal, CTC, PWM)
            TCCR0_REG = (TCCR0_REG & 0xB7) | ((ConfigPtr->Mode & 0x01) << WGM00_BIT) | (((ConfigPtr->Mode >> 1) & 0x01) << WGM01_BIT);
            // Set OC0 Mode
            TCCR0_REG = (TCCR0_REG & 0xCF) | (ConfigPtr->OC_Mode << COM00_BIT);
            // Set Prescaler
            TCCR0_REG = (TCCR0_REG & 0xF8) | (ConfigPtr->Prescaler);
            break;

        case TIMER1:
            // Set Mode (Normal, CTC, PWM)
            TCCR1A_REG = (TCCR1A_REG & 0xFC) | (ConfigPtr->Mode & 0x03);
            TCCR1B_REG = (TCCR1B_REG & 0xE7) | ((ConfigPtr->Mode >> 2) << WGM12_BIT);
            // Set OC1A/OC1B Mode
            TCCR1A_REG = (TCCR1A_REG & 0x0F) | (ConfigPtr->OC_Mode << COM1A0_BIT) | (ConfigPtr->OC_Mode << COM1B0_BIT);
            // Set Top Value for PWM if applicable
            if (ConfigPtr->Mode == TIMER_MODE_FAST_PWM || ConfigPtr->Mode == TIMER_MODE_PHASE_CORRECT_PWM)
            {
                ICR1_REG = ConfigPtr->TopValue;
            }
            // Set Prescaler
            TCCR1B_REG = (TCCR1B_REG & 0xF8) | (ConfigPtr->Prescaler);
            break;

        case TIMER2:
            // Set Mode (Normal, CTC, PWM)
            TCCR2_REG = (TCCR2_REG & 0xB7) | ((ConfigPtr->Mode & 0x01) << WGM20_BIT) | (((ConfigPtr->Mode >> 1) & 0x01) << WGM21_BIT);
            // Set OC2 Mode
            TCCR2_REG = (TCCR2_REG & 0xCF) | (ConfigPtr->OC_Mode << COM20_BIT);
            // Set Prescaler
            TCCR2_REG = (TCCR2_REG & 0xF8) | (ConfigPtr->Prescaler);
            break;
    }
}

/**
 * @brief  De-initializes a timer, stopping it and disabling its interrupts.
 * @param  TimerID The ID of the timer to de-initialize.
 * @return void
 */
void TIMER_deinit(TIMER_ID_t TimerID)
{
    switch (TimerID)
    {
        case TIMER0: TCCR0_REG = 0; TCNT0_REG = 0; OCR0_REG = 0; TIMSK_REG &= ~((1<<TOIE0_BIT) | (1<<OCIE0_BIT)); break;
        case TIMER1: TCCR1A_REG = 0; TCCR1B_REG = 0; TCNT1_REG = 0; OCR1A_REG = 0; OCR1B_REG = 0; ICR1_REG = 0; TIMSK_REG &= ~((1<<TOIE1_BIT) | (1<<OCIE1A_BIT) | (1<<OCIE1B_BIT) | (1<<TICIE1_BIT)); break;
        case TIMER2: TCCR2_REG = 0; TCNT2_REG = 0; OCR2_REG = 0; TIMSK_REG &= ~((1<<TOIE2_BIT) | (1<<OCIE2_BIT)); break;
    }
}

/**
 * @brief  Sets the compare value for a timer.
 * @param  TimerID The ID of the timer.
 * @param  Value The compare value to set.
 * @return void
 */
void TIMER_setCompareValue(TIMER_ID_t TimerID, uint16 Value)
{
    switch (TimerID)
    {
        case TIMER0: OCR0_REG = (uint8)Value; break;
        case TIMER1: OCR1A_REG = Value; break; // Default to channel A for simplicity
        case TIMER2: OCR2_REG = (uint8)Value; break;
    }
}

/**
 * @brief  Sets the duty cycle for a timer in PWM mode.
 * @param  TimerID The ID of the timer.
 * @param  DutyCycle The duty cycle from 0.0 to 100.0.
 * @return void
 */
void TIMER_setDutyCycle(TIMER_ID_t TimerID, float32 DutyCycle)
{
    if (DutyCycle < 0.0) DutyCycle = 0.0;
    if (DutyCycle > 100.0) DutyCycle = 100.0;

    uint16 top_value = 0;
    uint16 compare_value = 0;

    switch (TimerID)
    {
        case TIMER0:
            top_value = 255;
            compare_value = (uint16)(((DutyCycle / 100.0) * top_value));
            OCR0_REG = (uint8)compare_value;
            break;
        case TIMER1:
            top_value = ICR1_REG; // Assumes ICR1 is used as TOP
            if (top_value > 0)
            {
                compare_value = (uint16)(((DutyCycle / 100.0) * top_value));
                OCR1A_REG = compare_value; // Default to channel A
            }
            break;
        case TIMER2:
            top_value = 255;
            compare_value = (uint16)(((DutyCycle / 100.0) * top_value));
            OCR2_REG = (uint8)compare_value;
            break;
    }
}

/**
 * @brief  Sets the callback function for a timer interrupt.
 * @param  TimerID The ID of the timer.
 * @param  CallbackFunc Pointer to the callback function.
 * @return void
 */
void TIMER_setCallback(TIMER_ID_t TimerID, void (*CallbackFunc)(void))
{
    if (CallbackFunc == NULL) return;

    switch (TimerID)
    {
        case TIMER0: 
            g_Timer0_Callback = CallbackFunc;
            // Enable interrupt based on mode
            if ((TCCR0_REG & (1 << WGM01_BIT)) && !(TCCR0_REG & (1 << WGM00_BIT))) // CTC Mode
            {
                TIMSK_REG |= (1 << OCIE0_BIT);
            }
            else // Normal or other modes, default to overflow
            {
                TIMSK_REG |= (1 << TOIE0_BIT);
            }
            break;
        case TIMER1: 
            g_Timer1_Callback = CallbackFunc; 
            // Enable interrupt based on mode (simplified for OVF and COMPA)
            if (TCCR1B_REG & (1 << WGM12_BIT)) // CTC or PWM modes
            {
                TIMSK_REG |= (1 << OCIE1A_BIT);
            }
            else // Normal mode
            {
                TIMSK_REG |= (1 << TOIE1_BIT);
            }
            break;
        case TIMER2: 
            g_Timer2_Callback = CallbackFunc; 
            if ((TCCR2_REG & (1 << WGM21_BIT)) && !(TCCR2_REG & (1 << WGM20_BIT))) // CTC Mode
            {
                TIMSK_REG |= (1 << OCIE2_BIT);
            }
            else // Normal or other modes, default to overflow
            {
                TIMSK_REG |= (1 << TOIE2_BIT);
            }
            break;
    }
}

// ICU Specific Functions
/**
 * @brief  Initializes the Input Capture Unit (ICU) for Timer1.
 * @param  Edge The initial edge to trigger the ICU.
 * @return void
 */
void TIMER_icu_init(TIMER_ICU_Edge_t Edge)
{
    TCCR1A_REG = 0; // Normal mode for ICU
    TCCR1B_REG = (TCCR1B_REG & 0xBF) | (Edge << ICES1_BIT);
    SET_BIT(TIMSK_REG, TICIE1_BIT); // Enable ICU interrupt
}

/**
 * @brief  Sets the edge for the Input Capture Unit (ICU).
 * @param  Edge The edge to set (rising or falling).
 * @return void
 */
void TIMER_icu_setEdge(TIMER_ICU_Edge_t Edge)
{
    TCCR1B_REG = (TCCR1B_REG & 0xBF) | (Edge << ICES1_BIT);
}

/**
 * @brief  Reads the value of the Input Capture Register (ICR1).
 * @param  void
 * @return The value of ICR1.
 */
uint16 TIMER_icu_readInput(void)
{
    return ICR1_REG;
}

/**
 * @brief  Sets the callback function for the ICU interrupt.
 * @param  CallbackFunc Pointer to the callback function.
 * @return void
 */
void TIMER_icu_setCallback(void (*CallbackFunc)(void))
{
    if (CallbackFunc != NULL)
    {
        g_ICU_Callback = CallbackFunc;
    }
}

// ISRs
// ISRs for TIMER0
ISR(TIMER0_OVF_vect)
{
    if (g_Timer0_Callback != NULL) g_Timer0_Callback();
}

ISR(TIMER0_COMP_vect)
{
    if (g_Timer0_Callback != NULL) g_Timer0_Callback();
}

// ISRs for TIMER1
ISR(TIMER1_OVF_vect)
{
    if (g_Timer1_Callback != NULL) g_Timer1_Callback();
}

ISR(TIMER1_COMPA_vect)
{
    if (g_Timer1_Callback != NULL) g_Timer1_Callback();
}

ISR(TIMER1_CAPT_vect)
{
    if (g_ICU_Callback != NULL) g_ICU_Callback();
}

// ISRs for TIMER2
ISR(TIMER2_OVF_vect)
{
    if (g_Timer2_Callback != NULL) g_Timer2_Callback();
}

ISR(TIMER2_COMP_vect)
{
    if (g_Timer2_Callback != NULL) g_Timer2_Callback();
}
