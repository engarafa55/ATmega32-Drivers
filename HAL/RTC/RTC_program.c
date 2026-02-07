/******************************************************************************
 * Module: RTC
 * File Name: RTC_program.c
 * Description: Source file for the RTC driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "RTC_interface.h"
#include "RTC_private.h"
#include "../../MCAL/I2C/I2C_interface.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define RTC_ADDRESS 0x68 // DS1307 Address

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

static uint8 bcdToDec(uint8 val) { return (uint8)((val / 16 * 10) + (val % 16)); }
static uint8 decToBcd(uint8 val) { return (uint8)((val / 10 * 16) + (val % 10)); }

/**
 * @brief Initializes the RTC module.
 * @param void
 * @return void
 */
void RTC_init(void)
{
    I2C_start();
    I2C_writeByte((RTC_ADDRESS << 1) | 0);
    I2C_writeByte(0x07); // Control Register
    I2C_writeByte(0x00); // Disable SQW
    I2C_stop();
}

/**
 * @brief Sets the time on the RTC.
 * @param time Pointer to a structure containing the time to set.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_setTime(const RTC_time_t *time)
{
    if (time == NULL) return E_NOT_OK;
    I2C_start();
    I2C_writeByte((RTC_ADDRESS << 1) | 0);
    I2C_writeByte(0x00); // Start at seconds register
    I2C_writeByte(decToBcd(time->seconds));
    I2C_writeByte(decToBcd(time->minutes));
    I2C_writeByte(decToBcd(time->hours));
    I2C_stop();
    return E_OK;
}

/**
 * @brief Gets the current time from the RTC.
 * @param time Pointer to a structure to store the current time.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_getTime(RTC_time_t *time)
{
    if (time == NULL) return E_NOT_OK;
    I2C_start();
    I2C_writeByte((RTC_ADDRESS << 1) | 0);
    I2C_writeByte(0x00);
    I2C_start(); // Repeated start
    I2C_writeByte((RTC_ADDRESS << 1) | 1);
    I2C_readByteWithAck(&time->seconds);
    I2C_readByteWithAck(&time->minutes);
    I2C_readByteWithNack(&time->hours);
    I2C_stop();
    time->seconds = bcdToDec(time->seconds & 0x7F);
    time->minutes = bcdToDec(time->minutes);
    time->hours = bcdToDec(time->hours & 0x3F);
    return E_OK;
}

/**
 * @brief Sets the date on the RTC.
 * @param date Pointer to a structure containing the date to set.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_setDate(const RTC_date_t *date)
{
    if (date == NULL) return E_NOT_OK;
    I2C_start();
    I2C_writeByte((RTC_ADDRESS << 1) | 0);
    I2C_writeByte(0x03); // Start at day register
    I2C_writeByte(decToBcd(date->day));
    I2C_writeByte(decToBcd(date->date));
    I2C_writeByte(decToBcd(date->month));
    I2C_writeByte(decToBcd(date->year));
    I2C_stop();
    return E_OK;
}

/**
 * @brief Gets the current date from the RTC.
 * @param date Pointer to a structure to store the current date.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_getDate(RTC_date_t *date)
{
    if (date == NULL) return E_NOT_OK;
    I2C_start();
    I2C_writeByte((RTC_ADDRESS << 1) | 0);
    I2C_writeByte(0x03);
    I2C_start(); // Repeated start
    I2C_writeByte((RTC_ADDRESS << 1) | 1);
    I2C_readByteWithAck(&date->day);
    I2C_readByteWithAck(&date->date);
    I2C_readByteWithAck(&date->month);
    I2C_readByteWithNack(&date->year);
    I2C_stop();
    date->day = bcdToDec(date->day);
    date->date = bcdToDec(date->date);
    date->month = bcdToDec(date->month);
    date->year = bcdToDec(date->year);
    return E_OK;
}
