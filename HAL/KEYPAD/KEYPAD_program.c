/******************************************************************************
 * Module: KEYPAD
 * File Name: KEYPAD_program.c
 * Description: Source file for the KEYPAD driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initializes the KEYPAD.
 * @param  void
 * @return void
 */
void KEYPAD_init(void)
{
    // Pin directions are now set globally in DIO_config.h and applied by DIO_init().
    // This function only needs to ensure the initial state is correct.

    // Set row pins to HIGH initially (deactivated state)
    DIO_writePin(KEYPAD_PORT, KEYPAD_ROW0, DIO_PIN_HIGH);
    DIO_writePin(KEYPAD_PORT, KEYPAD_ROW1, DIO_PIN_HIGH);
    DIO_writePin(KEYPAD_PORT, KEYPAD_ROW2, DIO_PIN_HIGH);
    DIO_writePin(KEYPAD_PORT, KEYPAD_ROW3, DIO_PIN_HIGH);

    // The pull-up resistors for column pins are enabled via their initial value
    // in DIO_config.h, so no further action is needed here.
}

/**
 * @brief  Scans the keypad and returns the currently pressed key.
 * @param  void
 * @return uint8 The character of the pressed key, or NO_KEY_PRESSED if no key is active.
 */
uint8 KEYPAD_getPressedKey(void)
{
    uint8 col_idx, row_idx;
    uint8 keypad_arr[4][4] = KEYPAD_ARRAY;

    uint8 keypad_rows[ROW_NUM] = {KEYPAD_ROW0, KEYPAD_ROW1, KEYPAD_ROW2, KEYPAD_ROW3};
    uint8 keypad_cols[COL_NUM] = {KEYPAD_COL0, KEYPAD_COL1, KEYPAD_COL2, KEYPAD_COL3};

    for (row_idx = 0; row_idx < ROW_NUM; ++row_idx)
    {
        // Activate the current row by setting its value to low
        DIO_writePin(KEYPAD_PORT, keypad_rows[row_idx], DIO_PIN_LOW);

        // Iterate through each column
        for (col_idx = 0; col_idx < COL_NUM; ++col_idx)
        {
            DIO_PinValue_t curr_state;

            // Read the value of each column
            DIO_readPin(KEYPAD_PORT, keypad_cols[col_idx], &curr_state);

            // If the value of the current column is low, then it's the pressed key
            if (DIO_PIN_LOW == curr_state)
            {
                // Busy Waiting until the pressed key is released
                while (DIO_PIN_LOW == curr_state)
                {
                    DIO_readPin(KEYPAD_PORT, keypad_cols[col_idx], &curr_state);
                }
                // Return the pressed key value associated in the configuration file
                return keypad_arr[row_idx][col_idx];
            }
        }
        // Deactivate the current row by setting it to high
        DIO_writePin(KEYPAD_PORT, keypad_rows[row_idx], DIO_PIN_HIGH);
    }

    return NO_KEY_PRESSED;
}
