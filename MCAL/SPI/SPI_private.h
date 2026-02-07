/******************************************************************************
 * Module: SPI
 * File Name: SPI_private.h
 * Description: Header file for the SPI driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

/* SPI Registers */
#define SPDR        (*((volatile uint8*)0x2F))
#define SPSR        (*((volatile uint8*)0x2E))
#define SPCR        (*((volatile uint8*)0x2D))

/* SPSR Bits */
#define SPIF_BIT    7
#define WCOL_BIT    6
#define SPI2X_BIT   0

/* SPCR Bits */
#define SPIE_BIT    7
#define SPE_BIT     6
#define DORD_BIT    5
#define MSTR_BIT    4
#define CPOL_BIT    3
#define CPHA_BIT    2
#define SPR1_BIT    1
#define SPR0_BIT    0

#endif /* SPI_PRIVATE_H_ */