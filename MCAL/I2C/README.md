
---
# 📦 I2C Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Inter-Integrated Circuit (I2C) or Two-Wire Interface (TWI) driver supports both Master and Slave modes. It allows communication with slow peripheral devices like EEPROMs, RTCs, and sensors using just two wires (SDA and SCL).

## ⚙️ Configuration (`I2C_Config_t`)
This driver uses a configuration structure `I2C_Config_t` passed to initialization.

| Field | Description | Options |
| :--- | :--- | :--- |
| `Prescaler` | Sets the prescaler for Bit Rate generation | `I2C_PRESCALER_1`, `I2C_PRESCALER_4`, etc. |
| `BitRate` | SCL frequency (in Hz) | e.g., `100000`, `400000` |
| `SlaveAddress` | Address of this device (if Slave) | 7-bit address |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `I2C_init` | Initializes the I2C module with the given configuration. |
| `I2C_start` | Generates a START condition on the bus. |
| `I2C_stop` | Generates a STOP condition on the bus. |
| `I2C_writeByte` | Writes a single byte to the bus. |
| `I2C_readByteWithAck` | Reads a byte and sends an ACK. |
| `I2C_readByteWithNack` | Reads a byte and sends a NACK (used for last byte). |
| `I2C_getStatus` | Returns the current status code of the TWI hardware. |

## 🚀 Usage Example
```c
#include "I2C_interface.h"

void main() {
    I2C_Config_t i2cConfig = {
        .Prescaler = I2C_PRESCALER_1,
        .BitRate = 400000, // 400kHz
        .SlaveAddress = 0x01
    };
    
    I2C_init(&i2cConfig);
    I2C_start();
}
```
