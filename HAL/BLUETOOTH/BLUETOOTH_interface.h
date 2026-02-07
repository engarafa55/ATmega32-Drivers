/******************************************************************************
 * Module: BLUETOOTH
 * File Name: BLUETOOTH_interface.h
 * Description: Header file for the BLUETOOTH driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../MCAL/USART/USART_interface.h"

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the Bluetooth module.
 * @param  void
 * @return void
 */
void BLUETOOTH_init(void);

/**
 * @brief  Sends a single byte over Bluetooth.
 * @param  Data The byte to be sent.
 * @return void
 */
void BLUETOOTH_sendByte(const uint8 Data);

/**
 * @brief  Receives a single byte from Bluetooth.
 * @param  void
 * @return uint8_t The received byte.
 */
uint8 BLUETOOTH_receiveByte(void);

/**
 * @brief  Sends a null-terminated string over Bluetooth.
 * @param  Str Pointer to the string to be sent.
 * @return void
 */
void BLUETOOTH_sendString(const char *Str);

/**
 * @brief  Receives a string from Bluetooth until a terminator character is found.
 * @param  Str Pointer to a buffer to store the received string.
 * @param  Terminator The character that indicates the end of the string.
 * @return void
 */
void BLUETOOTH_receiveString(char *Str, uint8 Terminator);

#endif /* BLUETOOTH_INTERFACE_H_ */
