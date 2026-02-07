/******************************************************************************
 * Module: GIE
 * File Name: GIE_interface.h
 * Description: Header file for the GIE driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Enables the Global Interrupt (I-bit in SREG).
 * @param void
 * @return void
 */
void GIE_enable(void);

/**
 * @brief Disables the Global Interrupt (I-bit in SREG).
 * @param void
 * @return void
 */
void GIE_disable(void);

#endif /* GIE_INTERFACE_H_ */
