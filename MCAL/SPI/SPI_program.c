/******************************************************************************
 * Module: SPI
 * File Name: SPI_program.c
 * Description: Source file for the SPI driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "SPI_interface.h"
#include "SPI_private.h"
#include "../../Includes/BIT_MACROS.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initialize the SPI with the given configuration
 * @param  ConfigPtr Pointer to the SPI configuration structure
 * @return void
 */
void SPI_init(const SPI_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    // Set SPI Mode (Master/Slave)
    if (ConfigPtr->Mode == SPI_MODE_MASTER)
    {
        // The application is responsible for setting MOSI, SCK, and SS pins as outputs.
        SET_BIT(SPCR, MSTR_BIT);
    }
    else
    {
        // The application is responsible for setting the MISO pin as an output.
        CLEAR_BIT(SPCR, MSTR_BIT);
    }

    // Set Data Order
    if (ConfigPtr->DataOrder == SPI_DATA_ORDER_LSB_FIRST)
    {
        SET_BIT(SPCR, DORD_BIT);
    }
    else
    {
        CLEAR_BIT(SPCR, DORD_BIT);
    }

    // Set Clock Rate (only affects Master mode)
    SPCR = (SPCR & 0xFC) | (ConfigPtr->ClockRate & 0x03);
    SPSR = (SPSR & 0xFE) | ((ConfigPtr->ClockRate >> 2) & 0x01);

    // Enable SPI
    SET_BIT(SPCR, SPE_BIT);
}

/**
 * @brief  Send or receive data
 * @param  DataToSend Data to be sent
 * @param  DataToReceive Pointer to store the received data
 * @return Std_ReturnType Status of the operation
 */
Std_ReturnType SPI_transceive(uint8 DataToSend, uint8 *DataToReceive)
{
    // Start transmission
    SPDR = DataToSend;

    // Wait for transmission to complete
    while(BIT_IS_CLEAR(SPSR, SPIF_BIT));

    // Read the received data if the pointer is valid
    if (DataToReceive != NULL)
    {
        *DataToReceive = SPDR;
    }
    else
    {
        // Dummy read to clear the SPIF flag (though accessing SPDR does that automatically)
        // This variable is volatile to ensure the read actually happens
        volatile uint8 dummy = SPDR;
        (void)dummy; // Suppress unused variable warning
    }

    return E_OK;
}
