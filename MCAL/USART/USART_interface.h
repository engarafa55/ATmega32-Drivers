/******************************************************************************
 * Module: USART
 * File Name: USART_interface.h
 * Description: Header file for the USART driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum {
    USART_CHAR_SIZE_5_BIT,
    USART_CHAR_SIZE_6_BIT,
    USART_CHAR_SIZE_7_BIT,
    USART_CHAR_SIZE_8_BIT,
    USART_CHAR_SIZE_9_BIT
} USART_CharSize_t;

typedef enum {
    USART_PARITY_DISABLED,
    USART_PARITY_EVEN = 2,
    USART_PARITY_ODD
} USART_Parity_t;

typedef enum {
    USART_STOP_BITS_1,
    USART_STOP_BITS_2
} USART_StopBits_t;

typedef struct {
    uint32           BaudRate;
    USART_CharSize_t   CharSize;
    USART_Parity_t     Parity;
    USART_StopBits_t   StopBits;
} USART_Config_t;


/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes the USART with the given configuration.
 * @param ConfigPtr Pointer to the USART configuration structure.
 * @return void
 */
void USART_init(const USART_Config_t *ConfigPtr);

/**
 * @brief Sends a single byte of data.
 * @param Data The data to be sent.
 * @return void
 */
void USART_send(uint8 Data);

/**
 * @brief Receives a single byte of data.
 * @param void
 * @return The received data.
 * @return void
 */
uint8 USART_receive(void);

/**
 * @brief Sends a null-terminated string.
 * @param Str Pointer to the string to be sent.
 * @return void
 */
void USART_sendStream(const char *Str);

#endif /* USART_INTERFACE_H_ */
