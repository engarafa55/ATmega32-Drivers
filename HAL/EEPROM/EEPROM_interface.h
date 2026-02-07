/******************************************************************************
 * Module: EEPROM
 * File Name: EEPROM_interface.h
 * Description: Header file for the EEPROM driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes the EEPROM module.
 * @param void
 * @return void
 */
void EEPROM_init(void);

/**
 * @brief Writes a single byte to a specified address in the EEPROM.
 * @param Address The 16-bit memory address to write to.
 * @param Data The byte of data to write.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType EEPROM_writeByte(uint16 Address, uint8 Data);

/**
 * @brief Reads a single byte from a specified address in the EEPROM.
 * @param Address The 16-bit memory address to read from.
 * @param Data Pointer to a variable to store the read data.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType EEPROM_readByte(uint16 Address, uint8 *Data);

#endif /* EEPROM_INTERFACE_H_ */
