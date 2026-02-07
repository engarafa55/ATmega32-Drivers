/******************************************************************************
 * Module: ADC
 * File Name: ADC_interface.h
 * Description: Header file for the ADC driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum {
    ADC_VOLTAGE_REF_AREF,
    ADC_VOLTAGE_REF_AVCC,
    ADC_VOLTAGE_REF_INTERNAL_2_56V
} ADC_VoltageRef_t;

typedef enum {
    ADC_PRESCALER_2 = 1,
    ADC_PRESCALER_4,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128
} ADC_Prescaler_t;

typedef enum {
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7
} ADC_Channel_t;

typedef struct {
    ADC_VoltageRef_t VoltageReference;
    ADC_Prescaler_t  Prescaler;
    boolean          AutoTriggerEnable;
    // Add other configuration options as needed (e.g., trigger source)
} ADC_Config_t;


/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes the ADC with the given configuration.
 * @param ConfigPtr Pointer to the ADC configuration structure.
 * @return void
 */
void ADC_init(const ADC_Config_t *ConfigPtr);

/**
 * @brief Reads the digital value from a specific ADC channel.
 * @param Channel The ADC channel to read from.
 * @param Data Pointer to a variable to store the ADC result.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType ADC_readChannel(ADC_Channel_t Channel, uint16 *Data);

#endif /* ADC_INTERFACE_H_ */
