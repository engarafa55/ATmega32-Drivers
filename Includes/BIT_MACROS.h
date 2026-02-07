/******************************************************************************
 * Module: Common
 * File Name: BIT_MACROS.h
 * Description: Header file for common bit manipulation macros
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/
#ifndef BIT_MACROS_H_
#define BIT_MACROS_H_

/*******************************************************************************
 *                              Macro Declarations                             *
 *******************************************************************************/

#define BIT_MASK         (uint8)1
#define PORT_MASK        (uint8)0xFF
#define MAX_PORT_NUM     (uint8)4
#define MAX_PIN_NUM      (uint8)8
#define MAX_LOGIC_NUM    (uint8)1
#define MAX_STATE_NUM    (uint8)1

/*******************************************************************************
 *                         Macro Functions Declarations                        *
 *******************************************************************************/

/** @brief Sets a certain bit in any register. */
#define SET_BIT(REG,BIT)        (REG|=(BIT_MASK<<BIT))

/** @brief Clears a certain bit in any register. */
#define CLEAR_BIT(REG,BIT)      (REG&=(~(BIT_MASK<<BIT)))

/** @brief Toggles a certain bit in any register. */
#define TOGGLE_BIT(REG,BIT)     (REG^=(BIT_MASK<<BIT))

/** @brief Reads a certain bit in any register. */
#define READ_BIT(REG,BIT)       ((REG >> BIT) & BIT_MASK)

/** @brief Rotates right the register value with specific number of rotates. */
#define ROR(REG,num)            (REG= (REG>>num) | (REG<<(MAX_PIN_NUM - num)))

/** @brief Rotates left the register value with specific number of rotates. */
#define ROL(REG,num)            (REG= (REG<<num) | (REG>>(MAX_PIN_NUM - num)))

/** @brief Checks if a specific bit is set in any register and returns true if yes. */
#define BIT_IS_SET(REG,BIT)     (REG & (BIT_MASK<<BIT))

/** @brief Checks if a specific bit is cleared in any register and returns true if yes. */
#define BIT_IS_CLEAR(REG,BIT)   (!(REG & (BIT_MASK<<BIT)))

/* Access these special function registers of the AVR microcontroller */
#define SFR_IO8(io_addr) MMIO_BYTE((io_addr) + SFR_OFFSET)

/* Access these special function registers of the AVR microcontroller */
#define SFR_IO16(io_addr) MMIO_WORD((io_addr) + SFR_OFFSET)

/* Read or write a single byte of data from/to a memory-mapped I/O address */
#define MMIO_BYTE(mem_addr) (*(volatile uint8 *)(mem_addr))

/* Read or write a single byte of data from/to a memory-mapped I/O address */
#define MMIO_WORD(mem_addr) (*(volatile uint16 *)(mem_addr))

#ifndef SFR_OFFSET
#define SFR_OFFSET 0x20
#endif

#endif /* BIT_MACROS_H_ */
