/******************************************************************************
 * Module: MPU6050
 * File Name: MPU6050_interface.h
 * Description: Header file for the MPU6050 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef MPU6050_INTERFACE_H_
#define MPU6050_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum {
    MPU6050_ACCEL_RANGE_2G,
    MPU6050_ACCEL_RANGE_4G,
    MPU6050_ACCEL_RANGE_8G,
    MPU6050_ACCEL_RANGE_16G
} MPU6050_AccelRange_t;

typedef enum {
    MPU6050_GYRO_RANGE_250_DPS,
    MPU6050_GYRO_RANGE_500_DPS,
    MPU6050_GYRO_RANGE_1000_DPS,
    MPU6050_GYRO_RANGE_2000_DPS
} MPU6050_GyroRange_t;

typedef struct {
    MPU6050_AccelRange_t AccelRange;
    MPU6050_GyroRange_t  GyroRange;
} MPU6050_Config_t;

typedef struct {
    sint16 X;
    sint16 Y;
    sint16 Z;
} MPU6050_Data_t;


/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the MPU6050 sensor.
 * @param  ConfigPtr Pointer to the configuration structure.
 * @return void
 */
void MPU6050_init(const MPU6050_Config_t *ConfigPtr);

/**
 * @brief  Reads all sensor data from the MPU6050.
 * @param  AccelData Pointer to a structure to store accelerometer data.
 * @param  GyroData Pointer to a structure to store gyroscope data.
 * @param  Temperature Pointer to a variable to store the temperature.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType MPU6050_readAll(MPU6050_Data_t *AccelData, MPU6050_Data_t *GyroData, float32 *Temperature);

#endif /* MPU6050_INTERFACE_H_ */
