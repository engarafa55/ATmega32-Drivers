/******************************************************************************
 * Module: I2C_LCD
 * File Name: I2C_LCD.h
 * Description: Header file for the I2C_LCD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef I2C_LCD_H_
#define I2C_LCD_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
#define I2C_LCD_ADDRESS 0x27

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the I2C LCD module.
 * @param  void
 * @return void
 */
void I2C_LCD_init(void);

/**
 * @brief  Sends a command to the LCD.
 * @param  command The command to be sent.
 * @return void
 */
void I2C_LCD_sendCommand(uint8 command);

/**
 * @brief  Displays a single character on the LCD.
 * @param  data The character to be displayed.
 * @return void
 */
void I2C_LCD_displayCharacter(uint8 data);

/**
 * @brief  Displays a string on the LCD.
 * @param  Str Pointer to the string to be displayed.
 * @return void
 */
void I2C_LCD_displayString(const char *Str);

/**
 * @brief  Moves the cursor to a specific row and column.
 * @param  row The row to move to (0 or 1).
 * @param  col The column to move to (0-15).
 * @return void
 */
void I2C_LCD_moveCursor(uint8 row, uint8 col);

/**
 * @brief  Displays a string at a specific row and column.
 * @param  row The row to display the string on.
 * @param  col The column to start displaying the string from.
 * @param  Str Pointer to the string to be displayed.
 * @return void
 */
void I2C_LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str);

/**
 * @brief  Converts an integer to a string and displays it on the LCD.
 * @param  data The integer to be displayed.
 * @return void
 */
void I2C_LCD_intgerToString(int data);

/**
 * @brief  Clears the LCD screen.
 * @param  void
 * @return void
 */
void I2C_LCD_clearScreen(void);

#endif /* I2C_LCD_H_ */