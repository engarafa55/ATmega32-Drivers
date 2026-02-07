/******************************************************************************
 * Module: Common
 * File Name: STD_TYPES.h
 * Description: Header file for standard data types
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*******************************************************************************
 *                              Macro Declarations                             *
 *******************************************************************************/

#ifndef FALSE
#define FALSE                 (0u)
#endif

#ifndef TRUE
#define TRUE                  (1u)
#endif

#ifndef NULL
#define NULL                  ((void*)0)
#endif

/** @brief Function return value for success. */
#define E_OK                  (Std_ReturnType)0x01
/** @brief Function return value for failure. */
#define E_NOT_OK              (Std_ReturnType)0x00

/** @brief Value for initializing a variable to zero. */
#define ZERO_INIT             0x00

/*******************************************************************************
 *                            Data Types Declaration                           *
 *******************************************************************************/

/** @brief Boolean data type. */
typedef unsigned char         boolean;
/** @brief Unsigned 8-bit integer. */
typedef unsigned char         uint8;
/** @brief Signed 8-bit integer. */
typedef signed char           sint8;
/** @brief Unsigned 16-bit integer. */
typedef unsigned short        uint16;
/** @brief Signed 16-bit integer. */
typedef signed short          sint16;
/** @brief Unsigned 32-bit integer. */
typedef unsigned long         uint32;
/** @brief Signed 32-bit integer. */
typedef signed long           sint32;
/** @brief Unsigned 64-bit integer. */
typedef unsigned long long    uint64;
/** @brief Signed 64-bit integer. */
typedef signed long long      sint64;
/** @brief 32-bit floating point number. */
typedef float                 float32;
/** @brief 64-bit floating point number. */
typedef double                float64;
/** @brief Standard return type for functions. */
typedef uint8                 Std_ReturnType;

#endif /* STD_TYPES_H_ */
