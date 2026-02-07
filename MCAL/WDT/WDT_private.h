/******************************************************************************
 * Module: WDT
 * File Name: WDT_private.h
 * Description: Header file for the WDT driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define WDTCR           (*((volatile uint8*) 0x41))      /* Watchdog Timer Control Register */

/* WDTCR Bits */
#define WDTOE_BIT       4   /* Watchdog Turn-off Enable */
#define WDE_BIT         3   /* Watchdog Enable */
#define WDP2_BIT        2   /* Watchdog Timer Prescaler 2 */
#define WDP1_BIT        1   /* Watchdog Timer Prescaler 1 */
#define WDP0_BIT        0   /* Watchdog Timer Prescaler 0 */

#endif /* WDT_PRIVATE_H_ */
