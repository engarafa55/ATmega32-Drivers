/******************************************************************************
 * Module: CLCD
 * File Name: CLCD_interface.h
 * Description: Header file for the CLCD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the CLCD.
 * @param  void
 * @return void
 */
void CLCD_init(void);

/**
 * @brief  Sends a string to be displayed on the CLCD.
 * @param  string Pointer to the string.
 * @return void
 */
void CLCD_SendString(const char *string);

/**
 * @brief  Sets the cursor position on the CLCD.
 * @param  XPos The X position.
 * @param  YPos The Y position.
 * @return void
 */
void CLCD_GoTOXY(const uint8 XPos, const uint8 YPos);

/**
 * @brief  Sends a special character to be displayed on the CLCD.
 * @param  charArray Pointer to the character array.
 * @param  charIndex The index of the character in CGRAM.
 * @param  XPos The X position.
 * @param  YPos The Y position.
 * @return void
 */
void CLCD_SendSpecialChar(const uint8 *charArray, const uint8 charIndex, const uint8 XPos, const uint8 YPos);

/**
 * @brief  Clears the CLCD display.
 * @param  void
 * @return void
 */
void CLCD_Clear(void);

/**
 * @brief  Makes the cursor blink on the CLCD.
 * @param  void
 * @return void
 */
void CLCD_Blink(void);

/**
 * @brief  Sends data to the CLCD.
 * @param  Data The data to be sent.
 * @return void
 */
void CLCD_SendData(const uint8 Data);

#endif /* CLCD_INTERFACE_H_ */
