/******************************************************************************
 * Module: ADC
 * File Name: ADC_private.h
 * Description: Header file for the ADC driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

/* ADC Registers */
#define ADMUX           (*((volatile uint8*)0x27))
#define ADCSRA          (*((volatile uint8*)0x26))
#define ADC_DATA        (*((volatile uint16*)0x24)) // For ADCL and ADCH

/* ADMUX Bits */
#define REFS1_BIT       7
#define REFS0_BIT       6
#define ADLAR_BIT       5

/* ADCSRA Bits */
#define ADEN_BIT        7
#define ADSC_BIT        6
#define ADATE_BIT       5
#define ADIF_BIT        4
#define ADIE_BIT        3
#define ADPS2_BIT       2
#define ADPS1_BIT       1
#define ADPS0_BIT       0

/* Internal State */
#define ADC_STATE_IDLE 0
#define ADC_STATE_BUSY 1

#endif /* ADC_PRIVATE_H_ */
