
---
# 📦 RTC Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Real-Time Clock (RTC) driver interfaces with external modules like the DS1307. It allows setting and retrieving precise time (Hours, Minutes, Seconds) and date (Day, Month, Year).

## 🔌 Hardware Connection
| Pin Name | Port | Pin Number | Note |
| :--- | :--- | :--- | :--- |
| `SDA` | `PORTC` | `PIN1` | I2C Data |
| `SCL` | `PORTC` | `PIN0` | I2C Clock |

## ⚙️ Configuration
Configuration is handled internally via I2C.

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `RTC_init` | Initializes the RTC communication. |
| `RTC_setTime` | Sets the current time. |
| `RTC_getTime` | Reads the current time. |
| `RTC_setDate` | Sets the current date. |
| `RTC_getDate` | Reads the current date. |

## 🚀 Usage Example
```c
#include "RTC_interface.h"

void main() {
    RTC_init();
    
    RTC_time_t now;
    RTC_getTime(&now);
}
```
