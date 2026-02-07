/******************************************************************************
 * Module: LIB
 * File Name: math.h
 * Description: Header file for math functions
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef LIB_MATH_H_
#define LIB_MATH_H_

/*******************************************************************************
 *                        Software Interfaces Declarations                     *
 *******************************************************************************/

/**
 * @brief Computes the largest integer value not greater than __x.
 * @param __x The value to floor.
 * @return The largest integer value not greater than __x.
 */
double floor(double __x);
/**
 * @brief Computes the smallest integer value not less than __x.
 * @param __x The value to ceil.
 * @return The smallest integer value not less than __x.
 */
double ceil(double __x);

/**
 * @brief Re-maps a number from one range to another.
 * @param valueA The number to map.
 * @param rangeA_min The lower bound of the value's current range.
 * @param rangeA_max The upper bound of the value's current range.
 * @param rangeB_min The lower bound of the value's target range.
 * @param rangeB_max The upper bound of the value's target range.
 * @return The mapped value.
 */
int map(int valueA, int rangeA_min, int rangeA_max, int rangeB_min, int rangeB_max);

#endif /* LIB_MATH_H_ */
