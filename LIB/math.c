/******************************************************************************
 * Module: LIB
 * File Name: math.c
 * Description: Source file for math functions
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/
#include "math.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/**
 * @brief Re-maps a number from one range to another.
 * @param valueA The number to map.
 * @param rangeA_min The lower bound of the value's current range.
 * @param rangeA_max The upper bound of the value's current range.
 * @param rangeB_min The lower bound of the value's target range.
 * @param rangeB_max The upper bound of the value's target range.
 * @return The mapped value.
 */
int map(int valueA, int rangeA_min, int rangeA_max, int rangeB_min, int rangeB_max)
{
  return (rangeB_max-rangeB_min)*(valueA-rangeA_min)/(rangeA_max-rangeA_min)+rangeB_min;
}
