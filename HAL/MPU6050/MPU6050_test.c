/******************************************************************************
 * Module: MPU6050
 * File Name: MPU6050_test.c
 * Description: Test file for the MPU6050 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"
#include "../../MCAL/USART/USART_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "MPU6050_interface.h"
#include "MPU6050_config.h"
#include <stdio.h>
#include <util/delay.h>

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Main function to test the MPU6050 driver.
 * @param  void
 * @return int
 */
int main()
{
  DIO_SetPortDirection(DIO_PORTD, DIO_PORT_OUTPUT);
  USART_init();
  USART_redirect_stream_to_stdout();
  TWI_initMaster();
  MPU6050_init();
  while(1){
    MPU6050_Data_t accel_data, gyro_data;
    float32 temp;
    MPU6050_readAll(&accel_data, &gyro_data, &temp);
    printf("\n<<<<.............Testing the MPU6050.............>>>>\n");
    printf("ACCELEROMETER: ");
    printf("ax=%d, ay=%d, az=%d\n", accel_data.X, accel_data.Y, accel_data.Z);
    printf("GYROSCOPE    : ");
    printf("gx=%d, gy=%d, gz=%d\n", gyro_data.X, gyro_data.Y, gyro_data.Z);
    printf("Temperature  : %f degC\n", temp);
    _delay_ms(1000);
  }
  return 0;

}
