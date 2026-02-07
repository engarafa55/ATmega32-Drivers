/******************************************************************************
 * Module: MPU6050
 * File Name: MPU6050_program.c
 * Description: Source file for the MPU6050 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "MPU6050_interface.h"
#include "MPU6050_private.h"
#include "../../MCAL/I2C/I2C_interface.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define MPU6050_ADDRESS 0x68

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

// Internal function to write a byte to a specific register
static void MPU6050_writeByte(uint8 reg, uint8 data)
{
    I2C_start();
    I2C_writeByte((MPU6050_ADDRESS << 1) | 0);
    I2C_writeByte(reg);
    I2C_writeByte(data);
    I2C_stop();
}

// Internal function to read a sequence of bytes from the MPU6050
static void MPU6050_readBytes(uint8 start_reg, uint8 *buffer, uint8 length)
{
    I2C_start();
    I2C_writeByte((MPU6050_ADDRESS << 1) | 0);
    I2C_writeByte(start_reg);
    I2C_start(); // Repeated start
    I2C_writeByte((MPU6050_ADDRESS << 1) | 1);

    for (uint8 i = 0; i < length - 1; i++)
    {
        I2C_readByteWithAck(&buffer[i]);
    }
    I2C_readByteWithNack(&buffer[length - 1]);
    I2C_stop();
}

/**
 * @brief  Initializes the MPU6050 sensor.
 * @param  ConfigPtr Pointer to the configuration structure.
 * @return void
 */
void MPU6050_init(const MPU6050_Config_t *ConfigPtr)
{
    if (ConfigPtr == NULL) return;

    // Wake up the MPU6050
    MPU6050_writeByte(PWR_MGMT_1, 0x00);

    // Set accelerometer and gyroscope full-scale range
    MPU6050_writeByte(ACCEL_CONFIG, (ConfigPtr->AccelRange << 3));
    MPU6050_writeByte(GYRO_CONFIG, (ConfigPtr->GyroRange << 3));
}

/**
 * @brief  Reads all sensor data from the MPU6050.
 * @param  AccelData Pointer to a structure to store accelerometer data.
 * @param  GyroData Pointer to a structure to store gyroscope data.
 * @param  Temperature Pointer to a variable to store the temperature.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType MPU6050_readAll(MPU6050_Data_t *AccelData, MPU6050_Data_t *GyroData, float32 *Temperature)
{
    if (AccelData == NULL || GyroData == NULL || Temperature == NULL) return E_NOT_OK;

    uint8 buffer[14];
    MPU6050_readBytes(ACCEL_XOUT_H, buffer, 14);

    // Combine high and low bytes for each sensor reading
    AccelData->X = (buffer[0] << 8) | buffer[1];
    AccelData->Y = (buffer[2] << 8) | buffer[3];
    AccelData->Z = (buffer[4] << 8) | buffer[5];

    sint16 temp_raw = (buffer[6] << 8) | buffer[7];

    GyroData->X = (buffer[8] << 8) | buffer[9];
    GyroData->Y = (buffer[10] << 8) | buffer[11];
    GyroData->Z = (buffer[12] << 8) | buffer[13];

    // Convert temperature to Celsius
    *Temperature = (temp_raw / 340.0) + 36.53;

    return E_OK;
}
