/******************************************************************************
 * Module: MPU6050
 * File Name: MPU6050_private.h
 * Description: Header file for the MPU6050 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef MPU6050_PRIVATE_H_
#define MPU6050_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define NEGATIVE_2G_TO_POSITIVE_2G       0 
#define NEGATIVE_4G_TO_POSITIVE_4G       1
#define NEGATIVE_8G_TO_POSITIVE_8G       2
#define NEGATIVE_16G_TO_POSITIVE_16G     3
#define NEGATIVE_250_TO_POSITIVE_250     4
#define NEGATIVE_500_TO_POSITIVE_500     5
#define NEGATIVE_1000_TO_POSITIVE_1000   6
#define NEGATIVE_2000_TO_POSITIVE_2000   7

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "MPU6050_config.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define SMPLRT_DIV      25
#define CONFIG          26
#define GYRO_CONFIG     27
#define ACCEL_CONFIG    28
#define INT_ENABLE      56
#define ACCEL_XOUT_H    59
#define ACCEL_XOUT_L    60
#define ACCEL_YOUT_H    61
#define ACCEL_YOUT_L    62
#define ACCEL_ZOUT_H    63
#define ACCEL_ZOUT_L    64
#define TEMP_OUT_H      65
#define TEMP_OUT_L      66
#define GYRO_XOUT_H     67
#define GYRO_XOUT_L     68
#define GYRO_YOUT_H     69
#define GYRO_YOUT_L     70
#define GYRO_ZOUT_H     71
#define GYRO_ZOUT_L     72
#define PWR_MGMT_1      107
#define WHO_AM_I        117

#if ACCEL_RANGE==NEGATIVE_2G_TO_POSITIVE_2G
#define ACCEL_CONFIG_VLAUE  0x00
#define ACCEL_SCALE 2*9.8/32678.0
#elif ACCEL_RANGE==NEGATIVE_4G_TO_POSITIVE_4G 
#define ACCEL_CONFIG_VLAUE  0x08
#define ACCEL_SCALE 4*9.8/32678.0
#elif ACCEL_RANGE==NEGATIVE_8G_TO_POSITIVE_8G 
#define ACCEL_CONFIG_VLAUE  0x10
#define ACCEL_SCALE 8*9.8/32678.0
#elif ACCEL_RANGE==NEGATIVE_16G_TO_POSITIVE_16G 
#define ACCEL_CONFIG_VLAUE  0x18
#define ACCEL_SCALE 16*9.8/32678.0
#else
#error "Wrong Option in ACCEL_RANGE"
#endif

#if GYRO_RANGE==NEGATIVE_250_TO_POSITIVE_250
#define GYRO_CONFIG_VLAUE  0x00
#elif GYRO_RANGE==NEGATIVE_500_TO_POSITIVE_500 
#define GYRO_CONFIG_VLAUE  0x08
#elif GYRO_RANGE==NEGATIVE_1000_TO_POSITIVE_1000 
#define GYRO_CONFIG_VLAUE  0x10
#elif GYRO_RANGE==NEGATIVE_2000_TO_POSITIVE_2000 
#define GYRO_CONFIG_VLAUE  0x18
#else
#error "Wrong Option in GYRO_RANGE"
#endif

#endif /* MPU6050_PRIVATE_H_ */
