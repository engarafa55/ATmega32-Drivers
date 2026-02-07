/******************************************************************************
 * Module: WDT
 * File Name: WDT_interface.h
 * Description: Header file for the WDT driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum
{
    WDT_SLEEP_16_3_MS,
    WDT_SLEEP_32_5_MS,
    WDT_SLEEP_65_MS,
    WDT_SLEEP_0_13_S,
    WDT_SLEEP_0_26_S,
    WDT_SLEEP_0_52_S,
    WDT_SLEEP_1_0_S,
    WDT_SLEEP_2_1_S
} WDT_SleepTime_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Enables the Watchdog Timer.
 *        Once enabled, it must be reset periodically to prevent a system reset.
 */
void WDT_enable(void);

/**
 * @brief Sets the timeout period of the Watchdog Timer.
 * @param SleepTime The desired timeout period from the WDT_SleepTime_t enum.
 */
void WDT_setSleepTime(WDT_SleepTime_t SleepTime);

/**
 * @brief Disables the Watchdog Timer.
 * @note  This requires a specific timed sequence and should be used with caution.
 */
void WDT_disable(void);

#endif /* WDT_INTERFACE_H_ */