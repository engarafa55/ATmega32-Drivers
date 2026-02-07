/******************************************************************************
 * Module: RTC
 * File Name: RTC_private.h
 * Description: Header file for the RTC driver
 * Author: Abdelrahman Arafa
 * Email: engarafa55@gmail.com
 ******************************************************************************/

#ifndef RTC_PRIVATE_H_
#define RTC_PRIVATE_H_

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define PTR_SECONDS    0x00
#define PTR_MINUTES    0x01
#define PTR_HOURS      0x02
#define PTR_DAY        0x03
#define PTR_DATE       0x04
#define PTR_MONTH      0x05
#define PTR_YEAR       0x06
#define PTR_CONTORL    0x07

#define DS1307_ADDRESS 0b1101000

#endif /* RTC_PRIVATE_H_ */
