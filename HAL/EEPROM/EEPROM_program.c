/******************************************************************************
 * Module: EEPROM
 * File Name: EEPROM_program.c
 * Description: Source file for the EEPROM driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "EEPROM_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include "../../Includes/DEVICE_CONFIG.h"
#include <util/delay.h>

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

// The 24C08 EEPROM has a fixed device address part of 1010.
// The A2 pin is assumed to be grounded, making the full device address 0x50.
#define EEPROM_FIXED_ADDRESS 0x50

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Initializes the EEPROM module.
 * @param void
 * @return void
 */
void EEPROM_init(void)
{
    // This function is intentionally left empty.
    // The application is responsible for initializing the I2C peripheral.
}

/**
 * @brief Writes a single byte to a specified address in the EEPROM.
 * @param Address The 16-bit memory address to write to.
 * @param Data The byte of data to write.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType EEPROM_writeByte(uint16 Address, uint8 Data)
{
    // Start I2C communication
    if (I2C_start() != E_OK) return E_NOT_OK;

    // Send the device address with the high bits of the memory address and the write bit
    if (I2C_writeByte((uint8)(EEPROM_FIXED_ADDRESS | ((Address & 0x0700) >> 7))) != E_OK) return E_NOT_OK;

    // Send the low bits of the memory address
    if (I2C_writeByte((uint8)Address) != E_OK) return E_NOT_OK;

    // Send the data byte
    if (I2C_writeByte(Data) != E_OK) return E_NOT_OK;

    // Stop I2C communication
    I2C_stop();

    // Wait for the write cycle to complete
    _delay_ms(5);

    return E_OK;
}

/**
 * @brief Reads a single byte from a specified address in the EEPROM.
 * @param Address The 16-bit memory address to read from.
 * @param Data Pointer to a variable to store the read data.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType EEPROM_readByte(uint16 Address, uint8 *Data)
{
    if (Data == NULL) return E_NOT_OK;

    // Start I2C communication
    if (I2C_start() != E_OK) return E_NOT_OK;

    // Send the device address for writing to set the memory pointer
    if (I2C_writeByte((uint8)(EEPROM_FIXED_ADDRESS | ((Address & 0x0700) >> 7))) != E_OK) return E_NOT_OK;

    // Send the memory address to read from
    if (I2C_writeByte((uint8)Address) != E_OK) return E_NOT_OK;

    // Send a repeated start for reading
    if (I2C_start() != E_OK) return E_NOT_OK;

    // Send the device address with the read bit
    if (I2C_writeByte((uint8)(EEPROM_FIXED_ADDRESS | ((Address & 0x0700) >> 7) | 1)) != E_OK) return E_NOT_OK;

    // Read the data byte with NACK
    if (I2C_readByteWithNack(Data) != E_OK) return E_NOT_OK;

    // Stop I2C communication
    I2C_stop();

    return E_OK;
}
