/******************************************************************************
 * Module: SERVO
 * File Name: SERVO_program.c
 * Description: Source file for the SERVO driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "SERVO_interface.h"
#include "../../MCAL/Timers/TIMER_interface.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

// These values are based on a 50Hz PWM frequency and a timer clock of 250kHz (16MHz / 64 prescaler)
#define SERVO_MIN_PULSE_TICKS 250  // 1ms pulse for 0 degrees
#define SERVO_MAX_PULSE_TICKS 500  // 2ms pulse for 180 degrees

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

// Helper function to map an angle (0-180) to a timer compare value
static uint16 map_angle_to_compare(uint8 angle)
{
    // Ensure angle is within bounds
    if (angle > 180) angle = 180;

    // Linearly map the angle to the pulse width in timer ticks
    return (uint16)((((angle - 0) * (SERVO_MAX_PULSE_TICKS - SERVO_MIN_PULSE_TICKS)) / (180 - 0)) + SERVO_MIN_PULSE_TICKS);
}

/**
 * @brief Initializes the Servo motor control.
 * @param void
 * @return void
 */
void SERVO_init(void)
{
    // This function is intentionally left empty.
    // The application is responsible for:
    // 1. Configuring the servo GPIO pin (e.g., PD5/OC1A) as an output in DIO_config.h.
    // 2. Calling DIO_init().
    // 3. Configuring Timer1 for Fast PWM mode with a 50Hz frequency.
    //    (e.g., Prescaler=64, Top=4999, OC1A=Clear on compare match).
    // 4. Calling TIMER_init() with the configuration.
}

/**
 * @brief Sets the angle of the servo motor.
 * @param Angle The desired angle (0 to 180 degrees).
 * @return Std_ReturnType Error Status
 */
Std_ReturnType SERVO_setAngle(uint8 Angle)
{
    // Calculate the required compare value for the given angle
    uint16 compare_value = map_angle_to_compare(Angle);

    // Set the compare value for Timer1 (assumes OC1A is used for the servo)
    TIMER_setCompareValue(TIMER1, compare_value);

    return E_OK;
}
