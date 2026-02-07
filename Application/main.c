/******************************************************************************
 * Module: Application
 * File Name: main.c
 * Description: Source file for the Application logic
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "AppConfig.h"
#include "../Includes/STD_LIBRARIES.h"

/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/
LED_t LED1 = { .Port = DIO_PORTA, .Pin = DIO_PIN5 };
LED_t LED2 = { .Port = DIO_PORTA, .Pin = DIO_PIN6 };
PB_t Button1 = { .Port = DIO_PORTD, .Pin = DIO_PIN3 };

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  The main function of the application.
 * @param  void
 * @return int
 */
int main(void)
{
    DIO_init();

    PB_State_t btn_state = PB_RELEASED;

    while(1)
    {
        PB_read(&Button1, &btn_state);

        if (btn_state == PB_PRESSED)
        {
            _delay_ms(50);

            PB_read(&Button1, &btn_state);
            if (btn_state == PB_PRESSED)
            {
                LED_toggle(&LED1);
                LED_toggle(&LED2);

                while(btn_state == PB_PRESSED)
                {
                    PB_read(&Button1, &btn_state);
                }
            }
        }
    }

    return 0;
}
