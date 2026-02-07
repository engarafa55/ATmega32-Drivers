/******************************************************************************
 * Module: CLCD
 * File Name: CLCD_config.h
 * Description: Header file for the CLCD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define CLCD_DATA_PORT DIO_PORTB

#define CLCD_CTRL_PORT DIO_PORTA

#define CLCD_RS_PIN    DIO_PIN0
#define CLCD_RW_PIN    DIO_PIN1
#define CLCD_EN_PIN    DIO_PIN2

#define CLCD_MODE MODE_4_BIT

#endif /* CLCD_CONFIG_H_ */
