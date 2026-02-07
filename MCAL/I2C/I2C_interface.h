/******************************************************************************
 * Module: I2C
 * File Name: I2C_interface.h
 * Description: Header file for the I2C driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum
{
    I2C_PRESCALER_1,
    I2C_PRESCALER_4,
    I2C_PRESCALER_16,
    I2C_PRESCALER_64
} I2C_Prescaler_t;

typedef struct
{
    I2C_Prescaler_t Prescaler;
    uint32          BitRate;      // SCL frequency
    uint8           SlaveAddress; // This device's address (if configured as a slave)
} I2C_Config_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes the I2C module with the given configuration.
 * @param ConfigPtr Pointer to the I2C configuration structure.
 * @return void
 */
void I2C_init(const I2C_Config_t *ConfigPtr);

/**
 * @brief Sends a START condition on the I2C bus.
 * @param void
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_start(void);
/**
 * @brief Sends a STOP condition on the I2C bus.
 * @param void
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_stop(void);

/**
 * @brief Writes a byte of data to the I2C bus.
 * @param Data The byte to be written.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_writeByte(uint8 Data);
/**
 * @brief Reads a byte of data from the I2C bus with an ACK.
 * @param Data Pointer to a variable to store the read data.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_readByteWithAck(uint8 *Data);
/**
 * @brief Reads a byte of data from the I2C bus with a NACK.
 * @param Data Pointer to a variable to store the read data.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_readByteWithNack(uint8 *Data);

/**
 * @brief Gets the current status of the I2C module.
 * @param Status Pointer to a variable to store the status code.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_getStatus(uint8 *Status);

#endif /* I2C_INTERFACE_H_ */