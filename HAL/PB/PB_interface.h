/******************************************************************************
 * Module: PB
 * File Name: PB_interface.h
 * Description: Header file for the PB driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef PB_INTERFACE_H_
#define PB_INTERFACE_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

typedef enum {
    PB_RELEASED,
    PB_PRESSED
} PB_State_t;

typedef struct {
    DIO_Port_t Port;
    DIO_Pin_t  Pin;
} PB_t;

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Initializes a push button.
 * @param Button Pointer to the button configuration.
 * @return void
 */
void PB_init(const PB_t *Button);
/**
 * @brief Reads the state of a push button.
 * @param Button Pointer to the button configuration.
 * @param State Pointer to a variable to store the button state.
 * @return Std_ReturnType Error Status
 */
Std_ReturnType PB_read(const PB_t *Button, PB_State_t *State);

#endif /* PB_INTERFACE_H_ */
