/******************************************************************************
 * Module: RTC
 * File Name: RTC_interface.h
 * Description: Header file for the RTC driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef RTC_INTERFACE_H_
#define RTC_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef struct
{
  uint8 seconds;
  uint8 minutes;
  uint8 hours;
} RTC_time_t;

typedef struct
{
  uint8 day;
  uint8 date;
  uint8 month;
  uint8 year;
} RTC_date_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes the RTC module.
 * @param void
 * @return void
 */
void RTC_init(void);
/**
 * @brief Sets the time on the RTC.
 * @param time Pointer to a structure containing the time to set.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_setTime(const RTC_time_t *time);
/**
 * @brief Gets the current time from the RTC.
 * @param time Pointer to a structure to store the current time.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_getTime(RTC_time_t *time);
/**
 * @brief Sets the date on the RTC.
 * @param date Pointer to a structure containing the date to set.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_setDate(const RTC_date_t *date);
/**
 * @brief Gets the current date from the RTC.
 * @param date Pointer to a structure to store the current date.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType RTC_getDate(RTC_date_t *date);

#endif /* RTC_INTERFACE_H_ */
