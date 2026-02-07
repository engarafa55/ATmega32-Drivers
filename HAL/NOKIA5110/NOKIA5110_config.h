/******************************************************************************
 * Module: NOKIA5110
 * File Name: NOKIA5110_config.h
 * Description: Header file for the NOKIA5110 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef NOKIA5110_CONFIG_H_
#define NOKIA5110_CONFIG_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../MCAL/DIO/DIO_interface.h"

/*******************************************************************************
 *                              Macro Declarations                             *
 *******************************************************************************/

#define CTRL_PORT DIO_PORTC
#define SCE       DIO_PIN0
#define D_C       DIO_PIN1
#define RST       DIO_PIN2

#endif /* NOKIA5110_CONFIG_H_ */
