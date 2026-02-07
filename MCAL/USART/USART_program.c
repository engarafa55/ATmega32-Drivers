/******************************************************************************
 * Module: USART
 * File Name: USART_program.c
 * Description: Source file for the USART driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "USART_interface.h"
#include "USART_private.h"
#include "../../Includes/BIT_MACROS.h"
#include "../../Includes/DEVICE_CONFIG.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Initializes the USART with the given configuration.
 * @param ConfigPtr Pointer to the USART configuration structure.
 * @return void
 */
void USART_init(const USART_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    uint8 ucsrc_val = (1 << URSEL_BIT);
    uint16 ubrr_val = 0;

    // Set Character Size
    ucsrc_val |= (ConfigPtr->CharSize << UCSZ0_BIT);

    // Set Parity
    ucsrc_val |= (ConfigPtr->Parity << UPM0_BIT);

    // Set Stop Bits
    ucsrc_val |= (ConfigPtr->StopBits << USBS_BIT);

    UCSRC = ucsrc_val;

    // Set Baud Rate
    ubrr_val = (F_CPU / (16UL * ConfigPtr->BaudRate)) - 1;
    UBRRH = (ubrr_val >> 8);
    UBRRL = ubrr_val;

    // Enable Transmitter and Receiver
    SET_BIT(UCSRB, TXEN_BIT);
    SET_BIT(UCSRB, RXEN_BIT);
}

/**
 * @brief Sends a single byte of data.
 * @param Data The data to be sent.
 * @return void
 */
void USART_send(uint8 Data)
{
    // Wait for empty transmit buffer
    while (BIT_IS_CLEAR(UCSRA, UDRE_BIT));
    // Put data into buffer, sends the data
    UDR = Data;
}

/**
 * @brief Receives a single byte of data.
 * @param void
 * @return The received data.
 * @return void
 */
uint8 USART_receive(void)
{
    // Wait for data to be received
    while (BIT_IS_CLEAR(UCSRA, RXC_BIT));
    // Get and return received data from buffer
    return UDR;
}

/**
 * @brief Sends a null-terminated string.
 * @param Str Pointer to the string to be sent.
 * @return void
 */
void USART_sendStream(const char *Str)
{
    uint8 i = 0;
    while (Str[i] != '\0')
    {
        USART_send(Str[i]);
        i++;
    }
}
