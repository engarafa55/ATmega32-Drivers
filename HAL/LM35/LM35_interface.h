/******************************************************************************
 * Module: LM35
 * File Name: LM35_interface.h
 * Description: Header file for the LM35 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_interface.h"

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the LM35 sensor driver.
 * @param  void
 * @return void
 */
void LM35_init(void);

/**
 * @brief  Reads the temperature from the LM35 sensor.
 * @param  Channel The ADC channel the sensor is connected to.
 * @param  Temperature Pointer to a float32 variable to store the temperature in Celsius.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LM35_getTemperature(ADC_Channel_t Channel, float32 *Temperature);

#endif /* LM35_INTERFACE_H_ */
