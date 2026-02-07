/******************************************************************************
 * Module: NOKIA5110
 * File Name: NOKIA5110_interface.h
 * Description: Header file for the NOKIA5110 driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef NOKIA5110_INTERFACE_H_
#define NOKIA5110_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief  Initializes the NOKIA5110 LCD.
 * @param  void
 * @return void
 */
void NOKIA5110_init(void);

/**
 * @brief  Sends a command to the NOKIA5110 LCD.
 * @param  command The command to be sent.
 * @return void
 */
void NOKIA5110_sendCommand(const uint8 command);

/**
 * @brief  Sends data to the NOKIA5110 LCD.
 * @param  data The data to be sent.
 * @return void
 */
void NOKIA5110_sendData(const uint8 data);

/**
 * @brief  Resets the NOKIA5110 LCD.
 * @param  void
 * @return void
 */
void NOKIA5110_reset(void);

/**
 * @brief  Sets the cursor position on the NOKIA5110 LCD.
 * @param  x The x-coordinate (0-83).
 * @param  y The y-coordinate (0-5).
 * @return void
 */
void NOKIA5110_setXY(const uint8 x, const uint8 y);

/**
 * @brief  Sets the display to normal mode.
 * @param  void
 * @return void
 */
void NOKIA5110_setNormalMode(void);

/**
 * @brief  Sets the display to inverse video mode.
 * @param  void
 * @return void
 */
void NOKIA5110_setInverseVideoMode(void);

/**
 * @brief  Sets the display to blank mode.
 * @param  void
 * @return void
 */
void NOKIA5110_setBlankMode(void);

/**
 * @brief  Turns on all segments of the display.
 * @param  void
 * @return void
 */
void NOKIA5110_setAllSegmentsON(void);

/**
 * @brief  Clears the NOKIA5110 display.
 * @param  void
 * @return void
 */
void NOKIA5110_clearDisplay(void);
 
/**
 * @brief  Sends a single character to the display.
 * @param  character The character to be sent.
 * @return void
 */
void NOKIA5110_sendChar(const char character);

 /**
 * @brief  Sends a string to the display.
 * @param  string Pointer to the string to be sent.
 * @return void
 */
void NOKIA5110_sendString(const char *string);

 /**
 * @brief  Draws a full image on the display.
 * @param  image Pointer to the image data array.
 * @return void
 */
void NOKIA5110_drawFullImage(const uint8 *image);

/**
 * @brief  Sets the contrast of the display.
 * @param  contrast The contrast value (0-127).
 * @return void
 */
void NOKIA5110_setContrast(uint8 contrast);

#endif /* NOKIA5110_INTERFACE_H_ */
