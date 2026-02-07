/******************************************************************************
 * Module: SERVO
 * File Name: SERVO_interface.h
 * Description: Header file for the SERVO driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes the Servo motor control.
 * @param void
 * @return void
 */
void SERVO_init(void);

/**
 * @brief Sets the angle of the servo motor.
 * @param Angle The desired angle (0 to 180 degrees).
 * @return Std_ReturnType Error Status
 */
Std_ReturnType SERVO_setAngle(uint8 Angle);

#endif /* SERVO_INTERFACE_H_ */
