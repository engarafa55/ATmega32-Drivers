/******************************************************************************
 * Module: KEYPAD
 * File Name: KEYPAD_config.h
 * Description: Header file for the KEYPAD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../MCAL/DIO/DIO_interface.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define KEYPAD_PORT DIO_PORTD
#define KEYPAD_ROW0 DIO_PIN0
#define KEYPAD_ROW1 DIO_PIN1
#define KEYPAD_ROW2 DIO_PIN2
#define KEYPAD_ROW3 DIO_PIN3
#define KEYPAD_COL0 DIO_PIN4
#define KEYPAD_COL1 DIO_PIN5
#define KEYPAD_COL2 DIO_PIN6
#define KEYPAD_COL3 DIO_PIN7

#define KEYPAD_ARRAY {\
		      {'7', '8', '9', '/'},\
		      {'4', '5', '6', '*'},\
		      {'1', '2', '3', '-'},\
		      {'O', '0', '=', '+'}}

#endif /* KEYPAD_CONFIG_H_ */
