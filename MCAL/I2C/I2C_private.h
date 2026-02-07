/******************************************************************************
 * Module: I2C
 * File Name: I2C_private.h
 * Description: Header file for the I2C driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

/* I2C Registers */
#define TWBR_REG    (*((volatile uint8*)0x20))
#define TWSR_REG    (*((volatile uint8*)0x21))
#define TWAR_REG    (*((volatile uint8*)0x22))
#define TWDR_REG    (*((volatile uint8*)0x23))
#define TWCR_REG    (*((volatile uint8*)0x56))

/* TWCR Bits */
#define TWINT_BIT   7
#define TWEA_BIT    6
#define TWSTA_BIT   5
#define TWSTO_BIT   4
#define TWWC_BIT    3
#define TWEN_BIT    2
#define TWIE_BIT    0

/* TWAR Bits */
#define TWGCE_BIT   0

/* TWSR Bits */
#define TWPS1_BIT   1
#define TWPS0_BIT   0

/* I2C Status Codes */
#define I2C_START                        0x08
#define I2C_REP_START                    0x10
#define I2C_MT_SLA_W_ACK                 0x18
#define I2C_MT_SLA_W_NACK                0x20
#define I2C_MT_DATA_ACK                  0x28
#define I2C_MT_DATA_NACK                 0x30
#define I2C_MR_SLA_R_ACK                 0x40
#define I2C_MR_SLA_R_NACK                0x48
#define I2C_MR_DATA_ACK                  0x50
#define I2C_MR_DATA_NACK                 0x58

#endif /* I2C_PRIVATE_H_ */
