/******************************************************************************
 * Module: LM35
 * File Name: LM35_program.c
 * Description: Source file for the LM35 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "LM35_interface.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initializes the LM35 sensor driver.
 * @param  void
 * @return void
 */
void LM35_init(void)
{
    // This function is intentionally left empty.
    // The application is responsible for initializing the ADC peripheral.
}

/**
 * @brief  Reads the temperature from the LM35 sensor.
 * @param  Channel The ADC channel the sensor is connected to.
 * @param  Temperature Pointer to a float32 variable to store the temperature in Celsius.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LM35_getTemperature(ADC_Channel_t Channel, float32 *Temperature)
{
    if (Temperature == NULL) return E_NOT_OK;

    uint16 adc_value = 0;
    Std_ReturnType ret = ADC_readChannel(Channel, &adc_value);

    if (ret == E_OK)
    {
        // The sensor has a sensitivity of 10mV/degree Celsius.
        // Assuming ADC Vref is 5V and resolution is 10-bit (1024 steps).
        // Temperature = (ADC_Value * Vref * 100) / (Resolution * Sensitivity_in_V)
        // Temperature = (adc_value * 5.0 * 100) / 1024 = adc_value * (500 / 1024)
        *Temperature = (adc_value * 500.0) / 1024.0;
    }

    return ret;
}
