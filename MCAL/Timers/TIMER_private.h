/******************************************************************************
 * Module: TIMER
 * File Name: TIMER_private.h
 * Description: Header file for the Timer driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*******************************************************************************
 *                                  Timer Registers                              *
 *******************************************************************************/

/* Timer 0 Registers */
#define TCCR0_REG   (*((volatile uint8*)0x53))
#define TCNT0_REG   (*((volatile uint8*)0x52))
#define OCR0_REG    (*((volatile uint8*)0x5C))

/* Timer 1 Registers */
#define TCCR1A_REG  (*((volatile uint8*)0x4F))
#define TCCR1B_REG  (*((volatile uint8*)0x4E))
#define TCNT1_REG   (*((volatile uint16*)0x4C))
#define OCR1A_REG   (*((volatile uint16*)0x4A))
#define OCR1B_REG   (*((volatile uint16*)0x48))
#define ICR1_REG    (*((volatile uint16*)0x46))

/* Timer 2 Registers */
#define TCCR2_REG   (*((volatile uint8*)0x45))
#define TCNT2_REG   (*((volatile uint8*)0x44))
#define OCR2_REG    (*((volatile uint8*)0x43))

/* General Timer Registers */
#define TIMSK_REG   (*((volatile uint8*)0x59))
#define TIFR_REG    (*((volatile uint8*)0x58))

/*******************************************************************************
 *                                  Register Bits                                *
 *******************************************************************************/

/* TCCR0 Bits */
#define FOC0_BIT    7
#define WGM00_BIT   6
#define COM01_BIT   5
#define COM00_BIT   4
#define WGM01_BIT   3
#define CS02_BIT    2
#define CS01_BIT    1
#define CS00_BIT    0

/* TCCR1A Bits */
#define COM1A1_BIT  7
#define COM1A0_BIT  6
#define COM1B1_BIT  5
#define COM1B0_BIT  4
#define FOC1A_BIT   3
#define FOC1B_BIT   2
#define WGM11_BIT   1
#define WGM10_BIT   0

/* TCCR1B Bits */
#define ICNC1_BIT   7
#define ICES1_BIT   6
#define WGM13_BIT   4
#define WGM12_BIT   3
#define CS12_BIT    2
#define CS11_BIT    1
#define CS10_BIT    0

/* TCCR2 Bits */
#define FOC2_BIT    7
#define WGM20_BIT   6
#define COM21_BIT   5
#define COM20_BIT   4
#define WGM21_BIT   3
#define CS22_BIT    2
#define CS21_BIT    1
#define CS20_BIT    0

/* TIMSK Bits */
#define OCIE2_BIT   7
#define TOIE2_BIT   6
#define TICIE1_BIT  5
#define OCIE1A_BIT  4
#define OCIE1B_BIT  3
#define TOIE1_BIT   2
#define OCIE0_BIT   1
#define TOIE0_BIT   0

#endif /* TIMER_PRIVATE_H_ */
