/******************************************************************************
 * Module: WDT
 * File Name: WDT_program.c
 * Description: Source file for the WDT driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "WDT_interface.h"
#include "WDT_private.h"
#include "../../Includes/BIT_MACROS.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

void WDT_enable(void)
{
    // Set the WDE bit to enable the watchdog timer.
    SET_BIT(WDTCR, WDE_BIT);
}

void WDT_setSleepTime(WDT_SleepTime_t SleepTime)
{
    // Set the prescaler bits according to the selected sleep time.
    WDTCR = (WDTCR & 0xF8) | SleepTime;
}

void WDT_disable(void)
{
    /* 
     * To disable the WDT, the following sequence must be followed:
     * 1. In the same operation, write a logic one to WDTOE and WDE.
     * 2. Within the next four clock cycles, write a logic 0 to WDE.
     */
    WDTCR = (1 << WDTOE_BIT) | (1 << WDE_BIT);
    WDTCR = 0x00;
}
