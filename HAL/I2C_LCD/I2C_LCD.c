/******************************************************************************
 * Module: I2C_LCD
 * File Name: I2C_LCD.c
 * Description: Source file for the I2C_LCD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "I2C_LCD.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include "../../Includes/DEVICE_CONFIG.h"
#include <util/delay.h>
#include <stdlib.h>

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
#define LCD_RS (1 << 0)
#define LCD_RW (1 << 1)
#define LCD_EN (1 << 2)
#define LCD_BK_LIGHT (1 << 3)

static uint8_t g_expander_state = LCD_BK_LIGHT;

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

static void I2C_LCD_write(uint8_t data)
{
    I2C_start();
    I2C_writeByte((I2C_LCD_ADDRESS << 1) | 0);
    I2C_writeByte(data);
    I2C_stop();
}

static void I2C_LCD_sendNibble(uint8_t nibble, uint8_t is_data)
{
    uint8_t data = (nibble << 4) & 0xF0;
    data |= g_expander_state;
    if (is_data)
    {
        data |= LCD_RS;
    }

    I2C_LCD_write(data | LCD_EN);
    _delay_us(1);
    I2C_LCD_write(data);
    _delay_ms(2);
}

/**
 * @brief  Initializes the I2C LCD module.
 * @param  void
 * @return void
 */
void I2C_LCD_init(void)
{
    _delay_ms(50);
    I2C_LCD_sendNibble(0x03, 0);
    _delay_ms(5);
    I2C_LCD_sendNibble(0x03, 0);
    _delay_us(150);
    I2C_LCD_sendNibble(0x03, 0);
    I2C_LCD_sendNibble(0x02, 0);
    I2C_LCD_sendCommand(0x28);
    I2C_LCD_sendCommand(0x0C);
    I2C_LCD_sendCommand(0x06);
    I2C_LCD_sendCommand(0x01);
    _delay_ms(2);
}

/**
 * @brief  Sends a command to the LCD.
 * @param  command The command to be sent.
 * @return void
 */
void I2C_LCD_sendCommand(uint8_t command)
{
    I2C_LCD_sendNibble(command >> 4, 0);
    I2C_LCD_sendNibble(command & 0x0F, 0);
}

/**
 * @brief  Displays a single character on the LCD.
 * @param  data The character to be displayed.
 * @return void
 */
void I2C_LCD_displayCharacter(uint8_t data)
{
    I2C_LCD_sendNibble(data >> 4, 1);
    I2C_LCD_sendNibble(data & 0x0F, 1);
}

/**
 * @brief  Displays a string on the LCD.
 * @param  Str Pointer to the string to be displayed.
 * @return void
 */
void I2C_LCD_displayString(const char *Str)
{
    while (*Str)
    {
        I2C_LCD_displayCharacter(*Str++);
    }
}

/**
 * @brief  Moves the cursor to a specific row and column.
 * @param  row The row to move to (0 or 1).
 * @param  col The column to move to (0-15).
 * @return void
 */
void I2C_LCD_moveCursor(uint8_t row, uint8_t col)
{
    uint8_t address;
    switch (row)
    {
        case 0: address = col; break;
        case 1: address = col + 0x40; break;
        default: address = col; break;
    }
    I2C_LCD_sendCommand(address | 0x80);
}

/**
 * @brief  Displays a string at a specific row and column.
 * @param  row The row to display the string on.
 * @param  col The column to start displaying the string from.
 * @param  Str Pointer to the string to be displayed.
 * @return void
 */
void I2C_LCD_displayStringRowColumn(uint8_t row, uint8_t col, const char *Str)
{
    I2C_LCD_moveCursor(row, col);
    I2C_LCD_displayString(Str);
}

/**
 * @brief  Converts an integer to a string and displays it on the LCD.
 * @param  data The integer to be displayed.
 * @return void
 */
void I2C_LCD_intgerToString(int data)
{
    char buff[16];
    itoa(data, buff, 10);
    I2C_LCD_displayString(buff);
}

/**
 * @brief  Clears the LCD screen.
 * @param  void
 * @return void
 */
void I2C_LCD_clearScreen(void)
{
    I2C_LCD_sendCommand(0x01);
    _delay_ms(2);
}