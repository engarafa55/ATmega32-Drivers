/******************************************************************************
 * Module: EXTI
 * File Name: EXTI_private.h
 * Description: Header file for the EXTI driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

/* EXTI Registers */
#define GICR        (*((volatile uint8_t*)0x5B))
#define GIFR        (*((volatile uint8_t*)0x5A))
#define MCUCR       (*((volatile uint8_t*)0x55))
#define MCUCSR      (*((volatile uint8_t*)0x54))

/* GICR Bits */
#define INT1_BIT    7
#define INT0_BIT    6
#define INT2_BIT    5

/* MCUCR Bits */
#define ISC11_BIT   3
#define ISC10_BIT   2
#define ISC01_BIT   1
#define ISC00_BIT   0

/* MCUCSR Bits */
#define ISC2_BIT    6

#endif /* EXTI_PRIVATE_H_ */
