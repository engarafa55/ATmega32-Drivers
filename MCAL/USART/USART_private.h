/******************************************************************************
 * Module: USART
 * File Name: USART_private.h
 * Description: Header file for the USART driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

/* USART Registers */
#define UDR         (*((volatile uint8*)0x2C))
#define UCSRA       (*((volatile uint8*)0x2B))
#define UCSRB       (*((volatile uint8*)0x2A))
#define UCSRC       (*((volatile uint8*)0x40))
#define UBRRH       (*((volatile uint8*)0x40))
#define UBRRL       (*((volatile uint8*)0x29))

/* UCSRA Bits */
#define RXC_BIT     7
#define TXC_BIT     6
#define UDRE_BIT    5
#define FE_BIT      4
#define DOR_BIT     3
#define PE_BIT      2
#define U2X_BIT     1
#define MPCM_BIT    0

/* UCSRB Bits */
#define RXCIE_BIT   7
#define TXCIE_BIT   6
#define UDRIE_BIT   5
#define RXEN_BIT    4
#define TXEN_BIT    3
#define UCSZ2_BIT   2
#define RXB8_BIT    1
#define TXB8_BIT    0

/* UCSRC Bits */
#define URSEL_BIT   7
#define UMSEL_BIT   6
#define UPM1_BIT    5
#define UPM0_BIT    4
#define USBS_BIT    3
#define UCSZ1_BIT   2
#define UCSZ0_BIT   1
#define UCPOL_BIT   0

#endif /* USART_PRIVATE_H_ */
