/******************************************************************************
 * Module: LDR
 * File Name: LDR_program.c
 * Description: Source file for the LDR driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "LDR_interface.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Reads the LDR sensor value.
 * @param  ldr Pointer to the LDR object which includes the channel to read from.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LDR_Read(LDR_t *ldr)
{
    Std_ReturnType ret = E_OK;
    if (ldr == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // Read the raw ADC value from the specified channel
        ret = ADC_readChannel(ldr->Channel, &(ldr->RawValue));

        // Calculate the voltage
        ldr->Voltage = (ldr->RawValue * 5.0) / 1023.0;
    }
    return ret;
}
