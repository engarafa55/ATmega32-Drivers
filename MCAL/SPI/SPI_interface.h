/******************************************************************************
 * Module: SPI
 * File Name: SPI_interface.h
 * Description: Header file for the SPI driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum {
    SPI_MODE_SLAVE,
    SPI_MODE_MASTER
} SPI_Mode_t;

typedef enum {
    SPI_CLOCK_RATE_F_CPU_4,
    SPI_CLOCK_RATE_F_CPU_16,
    SPI_CLOCK_RATE_F_CPU_64,
    SPI_CLOCK_RATE_F_CPU_128
} SPI_ClockRate_t;

typedef enum {
    SPI_DATA_ORDER_MSB_FIRST,
    SPI_DATA_ORDER_LSB_FIRST
} SPI_DataOrder_t;

typedef struct {
    SPI_Mode_t      Mode;
    SPI_ClockRate_t ClockRate;
    SPI_DataOrder_t DataOrder;
    // Add other options like clock polarity and phase if needed
} SPI_Config_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initialize the SPI with the given configuration
 * @param  ConfigPtr Pointer to the SPI configuration structure
 * @return void
 */
void SPI_init(const SPI_Config_t *ConfigPtr);

/**
 * @brief  Send or receive data
 * @param  DataToSend Data to be sent
 * @param  DataToReceive Pointer to store the received data
 * @return Std_ReturnType Status of the operation
 */
Std_ReturnType SPI_transceive(uint8 DataToSend, uint8 *DataToReceive);

#endif /* SPI_INTERFACE_H_ */