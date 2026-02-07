/******************************************************************************
 * Module: CLCD
 * File Name: CLCD_program.c
 * Description: Source file for the CLCD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"
#include "../../Includes/BIT_MACROS.h"
#include "../../Includes/STD_LIBRARIES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/* --- Private Helper Functions --- */
static void setEnableForSomeTime(void)
{
    DIO_writePin(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_writePin(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_PIN_LOW);
}

/* --- Function Definitions --- */

/**
 * @brief  Sends a command to the LCD.
 * @param  Command The command byte to send.
 */
void CLCD_SendCommand(uint8 Command)
{
    /* Set RS to Low for Command */
    DIO_writePin(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_LOW);
    /* Set RW to Low for Write */
    DIO_writePin(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);

    /* Send Command */
    DIO_writePort(CLCD_DATA_PORT, Command);

    /* Trigger Enable Pulse */
    setEnableForSomeTime();
}

/**
 * @brief  Sends data (character) to the LCD.
 * @param  Data The character byte to display.
 */
void CLCD_SendData(uint8 Data)
{
    /* Set RS to High for Data */
    DIO_writePin(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_HIGH);
    /* Set RW to Low for Write */
    DIO_writePin(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);

    /* Send Data */
    DIO_writePort(CLCD_DATA_PORT, Data);

    /* Trigger Enable Pulse */
    setEnableForSomeTime();
}

/**
 * @brief  Clears the LCD display.
 */
void CLCD_Clear(void)
{
    CLCD_SendCommand(0x01); /* Clear display command */
    _delay_ms(2);           /* Wait for clear operation */
}

/**
 * @brief  Blinks the cursor on the LCD.
 */
void CLCD_Blink(void)
{
    CLCD_SendCommand(0x0F); /* Display on, Cursor on, Blink on */
    _delay_ms(2);
}

/**
 * @brief  Initializes the LCD based on configuration.
 */
void CLCD_init(void)
{
    _delay_ms(40); /* Wait for LCD power up */

    /* Function Set: 8-bit mode, 2 lines, 5x8 font */
    CLCD_SendCommand(0x38);

    /* Display On/Off Control: Display on, Cursor off, Blink off */
    CLCD_SendCommand(0x0C);

    /* Clear Display */
    CLCD_Clear();
}

/**
 * @brief  Sends a string to be displayed on the LCD.
 * @param  String Pointer to the null-terminated string.
 */
void CLCD_SendString(const char *String)
{
    uint8 i = 0;
    while (String[i] != '\0')
    {
        CLCD_SendData(String[i]);
        i++;
    }
}

/**
 * @brief  Moves the cursor to a specific X, Y position.
 * @param  X The column index (0-15).
 * @param  Y The row index (0-1).
 */
void CLCD_GoTOXY(uint8 X, uint8 Y)
{
    uint8 Address;
    if (Y == 0)
    {
        Address = 0x80 + X;
    }
    else
    {
        Address = 0xC0 + X;
    }
    CLCD_SendCommand(Address);
}

/**
 * @brief  Displays a custom special character.
 * @param  Pattern Pointer to the 8-byte pattern array.
 * @param  BlockNum The CGRAM block number (0-7).
 * @param  X The column index to display at.
 * @param  Y The row index to display at.
 */
void CLCD_SendSpecialChar(const uint8 *Pattern, const uint8 BlockNum, const uint8 X, const uint8 Y)
{
    uint8 Address = 0, i;
    /* Calculate CGRAM address */
    Address = BlockNum * 8;
    
    /* Set CGRAM Address */
    CLCD_SendCommand(0x40 + Address);

    /* Write Pattern to CGRAM */
    for (i = 0; i < 8; i++)
    {
        CLCD_SendData(Pattern[i]);
    }

    /* Return to DDRAM to display */
    CLCD_GoTOXY(X, Y);
    CLCD_SendData(BlockNum);
}