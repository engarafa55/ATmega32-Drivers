/******************************************************************************
 * Module: LDR
 * File Name: LDR_interface.h
 * Description: Header file for the LDR driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef struct
{
    ADC_Channel_t Channel;      // The ADC channel the LDR is connected to
    uint16       RawValue;     // The raw value from the ADC
    float32      Voltage;      // The calculated voltage
} LDR_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Reads the LDR sensor value.
 * @param  ldr Pointer to the LDR object which includes the channel to read from.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType LDR_Read(LDR_t *ldr);

#endif /* LDR_INTERFACE_H_ */