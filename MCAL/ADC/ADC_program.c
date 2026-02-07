/******************************************************************************
 * Module: ADC
 * File Name: ADC_program.c
 * Description: Source file for the ADC driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../Includes/BIT_MACROS.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Initializes the ADC with the given configuration.
 * @param ConfigPtr Pointer to the ADC configuration structure.
 * @return void
 */
void ADC_init(const ADC_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    // Set Voltage Reference
    ADMUX = (ADMUX & 0x3F) | (ConfigPtr->VoltageReference << REFS0_BIT);

    // Set Prescaler
    ADCSRA = (ADCSRA & 0xF8) | (ConfigPtr->Prescaler);

    // Set Auto Trigger
    if (ConfigPtr->AutoTriggerEnable == TRUE)
    {
        SET_BIT(ADCSRA, ADATE_BIT);
    }
    else
    {
        CLEAR_BIT(ADCSRA, ADATE_BIT);
    }

    // Enable ADC
    SET_BIT(ADCSRA, ADEN_BIT);
}

/**
 * @brief Reads the digital value from a specific ADC channel.
 * @param Channel The ADC channel to read from.
 * @param Data Pointer to a variable to store the ADC result.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType ADC_readChannel(ADC_Channel_t Channel, uint16 *Data)
{
    if (Data == NULL) return E_NOT_OK;

    // Select Channel
    ADMUX = (ADMUX & 0xE0) | (Channel & 0x1F);

    // Start Conversion
    SET_BIT(ADCSRA, ADSC_BIT);

    // Wait for conversion to complete
    while(BIT_IS_CLEAR(ADCSRA, ADIF_BIT));

    // Clear the flag
    SET_BIT(ADCSRA, ADIF_BIT);

    // Read the data
    *Data = ADC_DATA;

    return E_OK;
}
