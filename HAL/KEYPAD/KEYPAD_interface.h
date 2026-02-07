/******************************************************************************
 * Module: KEYPAD
 * File Name: KEYPAD_interface.h
 * Description: Header file for the KEYPAD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define NO_KEY_PRESSED 0xff

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the KEYPAD.
 * @param  void
 * @return void
 */
extern void KEYPAD_init(void);

/**
 * @brief  Scans the keypad and returns the currently pressed key.
 * @param  void
 * @return uint8 The character of the pressed key, or NO_KEY_PRESSED if no key is active.
 */
extern uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_INTERFACE_H_ */
