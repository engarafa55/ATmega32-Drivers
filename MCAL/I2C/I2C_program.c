/******************************************************************************
 * Module: I2C
 * File Name: I2C_program.c
 * Description: Source file for the I2C driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "I2C_interface.h"
#include "I2C_private.h"
#include "../../Includes/BIT_MACROS.h"
#include "../../Includes/DEVICE_CONFIG.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Initializes the I2C module with the given configuration.
 * @param ConfigPtr Pointer to the I2C configuration structure.
 * @return void
 */
void I2C_init(const I2C_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    // Set Prescaler
    TWSR_REG = (TWSR_REG & 0xFC) | (ConfigPtr->Prescaler);

    // Calculate and set Bit Rate
    // TWBR = ((F_CPU / SCL_freq) - 16) / (2 * 4^TWPS)
    uint32 prescaler_val = 1;
    if(ConfigPtr->Prescaler == I2C_PRESCALER_4) prescaler_val = 4;
    else if(ConfigPtr->Prescaler == I2C_PRESCALER_16) prescaler_val = 16;
    else if(ConfigPtr->Prescaler == I2C_PRESCALER_64) prescaler_val = 64;
    
    TWBR_REG = (uint8)((((F_CPU / ConfigPtr->BitRate) - 16) / (2 * prescaler_val)));

    // Set Slave Address if specified
    if (ConfigPtr->SlaveAddress != 0)
    {
        TWAR_REG = (ConfigPtr->SlaveAddress << 1);
    }

    // Enable TWI
    SET_BIT(TWCR_REG, TWEN_BIT);
}

/**
 * @brief Sends a START condition on the I2C bus.
 * @param void
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_start(void)
{
    uint8 status = 0;
    TWCR_REG = (1 << TWINT_BIT) | (1 << TWSTA_BIT) | (1 << TWEN_BIT);
    while(BIT_IS_CLEAR(TWCR_REG, TWINT_BIT));
    I2C_getStatus(&status);
    if (status != I2C_START) return E_NOT_OK;
    return E_OK;
}

/**
 * @brief Sends a STOP condition on the I2C bus.
 * @param void
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_stop(void)
{
    TWCR_REG = (1 << TWINT_BIT) | (1 << TWSTO_BIT) | (1 << TWEN_BIT);
    return E_OK;
}

/**
 * @brief Writes a byte of data to the I2C bus.
 * @param Data The byte to be written.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_writeByte(uint8 Data)
{
    TWDR_REG = Data;
    TWCR_REG = (1 << TWINT_BIT) | (1 << TWEN_BIT);
    while(BIT_IS_CLEAR(TWCR_REG, TWINT_BIT));
    // Status check is omitted here for brevity, but should be done in application
    return E_OK;
}

/**
 * @brief Reads a byte of data from the I2C bus with an ACK.
 * @param Data Pointer to a variable to store the read data.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_readByteWithAck(uint8 *Data)
{
    if (Data == NULL) return E_NOT_OK;
    TWCR_REG = (1 << TWINT_BIT) | (1 << TWEN_BIT) | (1 << TWEA_BIT);
    while(BIT_IS_CLEAR(TWCR_REG, TWINT_BIT));
    *Data = TWDR_REG;
    return E_OK;
}

/**
 * @brief Reads a byte of data from the I2C bus with a NACK.
 * @param Data Pointer to a variable to store the read data.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_readByteWithNack(uint8 *Data)
{
    if (Data == NULL) return E_NOT_OK;
    TWCR_REG = (1 << TWINT_BIT) | (1 << TWEN_BIT);
    while(BIT_IS_CLEAR(TWCR_REG, TWINT_BIT));
    *Data = TWDR_REG;
    return E_OK;
}

/**
 * @brief Gets the current status of the I2C module.
 * @param Status Pointer to a variable to store the status code.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType I2C_getStatus(uint8 *Status)
{
    uint8 status_val = TWSR_REG & 0xF8;
    if (Status != NULL)
    {
        *Status = status_val;
    }
    return E_OK;
}