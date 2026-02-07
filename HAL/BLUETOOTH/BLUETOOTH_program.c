/******************************************************************************
 * Module: BLUETOOTH
 * File Name: BLUETOOTH_program.c
 * Description: Source file for the BLUETOOTH driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "BLUETOOTH_interface.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initializes the Bluetooth module.
 * @param  void
 * @return void
 */
void BLUETOOTH_init(void)
{
    /* This function is a placeholder. The application is responsible for initializing the USART peripheral. */
}

/**
 * @brief  Sends a single byte over Bluetooth.
 * @param  Data The byte to be sent.
 * @return void
 */
void BLUETOOTH_sendByte(const uint8 Data)
{
    USART_send(Data);
}

/**
 * @brief  Receives a single byte from Bluetooth.
 * @param  void
 * @return uint8_t The received byte.
 */
uint8 BLUETOOTH_receiveByte(void)
{
    return USART_receive();
}

/**
 * @brief  Sends a null-terminated string over Bluetooth.
 * @param  Str Pointer to the string to be sent.
 * @return void
 */
void BLUETOOTH_sendString(const char *Str)
{
    USART_sendStream(Str);
}

/**
 * @brief  Receives a string from Bluetooth until a terminator character is found.
 * @param  Str Pointer to a buffer to store the received string.
 * @param  Terminator The character that indicates the end of the string.
 * @return void
 */
void BLUETOOTH_receiveString(char *Str, uint8 Terminator)
{
    uint8 i = 0;
    Str[i] = USART_receive();
    while(Str[i] != Terminator)
    {
        i++;
        Str[i] = USART_receive();
    }
    Str[i] = '\0';
}
