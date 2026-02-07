/******************************************************************************
 * Module: GIE
 * File Name: GIE_program.c
 * Description: Source file for the GIE driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "../../Includes/STD_TYPES.h"
#include "../../Includes/BIT_MACROS.h"

#include "GIE_interface.h"
#include "GIE_private.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Enables the Global Interrupt (I-bit in SREG).
 * @param void
 * @return void
 */
void GIE_enable(void)
{
  SET_BIT(SREG, I_BIT);
}

/**
 * @brief Disables the Global Interrupt (I-bit in SREG).
 * @param void
 * @return void
 */
void GIE_disable(void)
{  
  CLEAR_BIT(SREG, I_BIT);
}
