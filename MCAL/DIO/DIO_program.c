/******************************************************************************
 * Module: DIO
 * File Name: DIO_program.c
 * Description: Source file for the DIO driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/BIT_MACROS.h"
#include "../../Includes/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*******************************************************************************
 *                         Macro Functions Declarations                        *
 *******************************************************************************/
// Helper macro to concatenate pin configurations
#define CONCAT_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)         CONCAT_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief  Initializes all DIO pins to the directions and initial values
 *         specified in the DIO_config.h file.
 * @param  void
 * @return void
 */
void DIO_init(void)
{
    // Set Port A Direction and Initial Value
    DDRA_REG = CONCAT(DIO_PORTA_PIN7_DIR, DIO_PORTA_PIN6_DIR, DIO_PORTA_PIN5_DIR, DIO_PORTA_PIN4_DIR, 
                      DIO_PORTA_PIN3_DIR, DIO_PORTA_PIN2_DIR, DIO_PORTA_PIN1_DIR, DIO_PORTA_PIN0_DIR);
    PORTA_REG = CONCAT(DIO_PORTA_PIN7_INIT_VAL, DIO_PORTA_PIN6_INIT_VAL, DIO_PORTA_PIN5_INIT_VAL, DIO_PORTA_PIN4_INIT_VAL, 
                       DIO_PORTA_PIN3_INIT_VAL, DIO_PORTA_PIN2_INIT_VAL, DIO_PORTA_PIN1_INIT_VAL, DIO_PORTA_PIN0_INIT_VAL);

    // Set Port B Direction and Initial Value
    DDRB_REG = CONCAT(DIO_PORTB_PIN7_DIR, DIO_PORTB_PIN6_DIR, DIO_PORTB_PIN5_DIR, DIO_PORTB_PIN4_DIR, 
                      DIO_PORTB_PIN3_DIR, DIO_PORTB_PIN2_DIR, DIO_PORTB_PIN1_DIR, DIO_PORTB_PIN0_DIR);
    PORTB_REG = CONCAT(DIO_PORTB_PIN7_INIT_VAL, DIO_PORTB_PIN6_INIT_VAL, DIO_PORTB_PIN5_INIT_VAL, DIO_PORTB_PIN4_INIT_VAL, 
                       DIO_PORTB_PIN3_INIT_VAL, DIO_PORTB_PIN2_INIT_VAL, DIO_PORTB_PIN1_INIT_VAL, DIO_PORTB_PIN0_INIT_VAL);

    // Set Port C Direction and Initial Value
    DDRC_REG = CONCAT(DIO_PORTC_PIN7_DIR, DIO_PORTC_PIN6_DIR, DIO_PORTC_PIN5_DIR, DIO_PORTC_PIN4_DIR, 
                      DIO_PORTC_PIN3_DIR, DIO_PORTC_PIN2_DIR, DIO_PORTC_PIN1_DIR, DIO_PORTC_PIN0_DIR);
    PORTC_REG = CONCAT(DIO_PORTC_PIN7_INIT_VAL, DIO_PORTC_PIN6_INIT_VAL, DIO_PORTC_PIN5_INIT_VAL, DIO_PORTC_PIN4_INIT_VAL, 
                       DIO_PORTC_PIN3_INIT_VAL, DIO_PORTC_PIN2_INIT_VAL, DIO_PORTC_PIN1_INIT_VAL, DIO_PORTC_PIN0_INIT_VAL);

    // Set Port D Direction and Initial Value
    DDRD_REG = CONCAT(DIO_PORTD_PIN7_DIR, DIO_PORTD_PIN6_DIR, DIO_PORTD_PIN5_DIR, DIO_PORTD_PIN4_DIR, 
                      DIO_PORTD_PIN3_DIR, DIO_PORTD_PIN2_DIR, DIO_PORTD_PIN1_DIR, DIO_PORTD_PIN0_DIR);
    PORTD_REG = CONCAT(DIO_PORTD_PIN7_INIT_VAL, DIO_PORTD_PIN6_INIT_VAL, DIO_PORTD_PIN5_INIT_VAL, DIO_PORTD_PIN4_INIT_VAL, 
                       DIO_PORTD_PIN3_INIT_VAL, DIO_PORTD_PIN2_INIT_VAL, DIO_PORTD_PIN1_INIT_VAL, DIO_PORTD_PIN0_INIT_VAL);
}

/**
 * @brief  Sets a specific pin to a high or low value.
 * @param  Port The port of the pin (DIO_PORTA, DIO_PORTB, etc.).
 * @param  Pin The pin number (DIO_PIN0, DIO_PIN1, etc.).
 * @param  Value The value to set (DIO_PIN_HIGH or DIO_PIN_LOW).
 * @return Std_ReturnType Error Status
 */
Std_ReturnType DIO_writePin(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t Value)
{
    Std_ReturnType ret = E_OK;
    if ((Pin > DIO_PIN7) || (Port > DIO_PORTD))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (Port)
        {
            case DIO_PORTA: (Value == DIO_PIN_HIGH) ? SET_BIT(PORTA_REG, Pin) : CLEAR_BIT(PORTA_REG, Pin); break;
            case DIO_PORTB: (Value == DIO_PIN_HIGH) ? SET_BIT(PORTB_REG, Pin) : CLEAR_BIT(PORTB_REG, Pin); break;
            case DIO_PORTC: (Value == DIO_PIN_HIGH) ? SET_BIT(PORTC_REG, Pin) : CLEAR_BIT(PORTC_REG, Pin); break;
            case DIO_PORTD: (Value == DIO_PIN_HIGH) ? SET_BIT(PORTD_REG, Pin) : CLEAR_BIT(PORTD_REG, Pin); break;
            default: ret = E_NOT_OK; break;
        }
    }
    return ret;
}

/**
 * @brief  Reads the value of a specific pin.
 * @param  Port The port of the pin.
 * @param  Pin The pin number.
 * @param  Value Pointer to a variable to store the pin's value.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType DIO_readPin(DIO_Port_t Port, DIO_Pin_t Pin, DIO_PinValue_t *Value)
{
    Std_ReturnType ret = E_OK;
    if ((Value == NULL) || (Pin > DIO_PIN7) || (Port > DIO_PORTD))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (Port)
        {
            case DIO_PORTA: *Value = READ_BIT(PINA_REG, Pin); break;
            case DIO_PORTB: *Value = READ_BIT(PINB_REG, Pin); break;
            case DIO_PORTC: *Value = READ_BIT(PINC_REG, Pin); break;
            case DIO_PORTD: *Value = READ_BIT(PIND_REG, Pin); break;
            default: ret = E_NOT_OK; break;
        }
    }
    return ret;
}

/**
 * @brief  Toggles the value of a specific pin (HIGH -> LOW, LOW -> HIGH).
 * @param  Port The port of the pin.
 * @param  Pin The pin number.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType DIO_togglePin(DIO_Port_t Port, DIO_Pin_t Pin)
{
    Std_ReturnType ret = E_OK;
    if ((Pin > DIO_PIN7) || (Port > DIO_PORTD))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (Port)
        {
            case DIO_PORTA: TOGGLE_BIT(PORTA_REG, Pin); break;
            case DIO_PORTB: TOGGLE_BIT(PORTB_REG, Pin); break;
            case DIO_PORTC: TOGGLE_BIT(PORTC_REG, Pin); break;
            case DIO_PORTD: TOGGLE_BIT(PORTD_REG, Pin); break;
            default: ret = E_NOT_OK; break;
        }
    }
    return ret;
}

/**
 * @brief  Sets the value of an entire port.
 * @param  Port The port to write to.
 * @param  Value The 8-bit value to write to the port.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType DIO_writePort(DIO_Port_t Port, uint8 Value)
{
    Std_ReturnType ret = E_OK;
    if (Port > DIO_PORTD)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (Port)
        {
            case DIO_PORTA: PORTA_REG = Value; break;
            case DIO_PORTB: PORTB_REG = Value; break;
            case DIO_PORTC: PORTC_REG = Value; break;
            case DIO_PORTD: PORTD_REG = Value; break;
        }
    }
    return ret;
}

/**
 * @brief  Reads the value of an entire port.
 * @param  Port The port to read from.
 * @param  Value Pointer to a variable to store the port's value.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType DIO_readPort(DIO_Port_t Port, uint8 *Value)
{
    Std_ReturnType ret = E_OK;
    if ((Value == NULL) || (Port > DIO_PORTD))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (Port)
        {
            case DIO_PORTA: *Value = PINA_REG; break;
            case DIO_PORTB: *Value = PINB_REG; break;
            case DIO_PORTC: *Value = PINC_REG; break;
            case DIO_PORTD: *Value = PIND_REG; break;
        }
    }
    return ret;
}
