
---
# 📦 EEPROM Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The EEPROM driver enables reading and writing data to external I2C-based EEPLOM chips (e.g., AT24C16). It handles page boundaries and device addressing transparently.

## 🔌 Hardware Connection
| Pin Name | Port | Pin Number | Note |
| :--- | :--- | :--- | :--- |
| `SDA` | `PORTC` | `PIN1` | I2C Data Line (ATmega32) |
| `SCL` | `PORTC` | `PIN0` | I2C Clock Line (ATmega32) |

## ⚙️ Configuration
Configuration is primarily handled through the I2C driver settings and device address definitions within the driver source.

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `EEPROM_init` | Initializes the underlying I2C interface. |
| `EEPROM_writeByte` | Writes a byte to a specific memory address. |
| `EEPROM_readByte` | Reads a byte from a specific memory address. |

## 🚀 Usage Example
```c
#include "EEPROM_interface.h"

void main() {
    EEPROM_init();
    EEPROM_writeByte(0x0010, 0x55);
    
    uint8 data;
    EEPROM_readByte(0x0010, &data);
}
```
