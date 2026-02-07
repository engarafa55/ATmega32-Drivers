
---
# 📦 BLUETOOTH Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Bluetooth driver creates an abstraction layer over the USART peripheral to enable wireless serial communication with HC-05 or HC-06 Bluetooth modules.

## 🔌 Hardware Connection
| Pin Name | Connection | Note |
| :--- | :--- | :--- |
| `TX` | `RX` of MCU | Connect Bluetooth TX to MCU RX |
| `RX` | `TX` of MCU | Connect Bluetooth RX to MCU TX (Divider may be needed) |

## ⚙️ Configuration
This driver relies on the underlying USART driver configuration (`USART_Config_t`).

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `BLUETOOTH_init` | Initializes the Bluetooth module (and USART). |
| `BLUETOOTH_sendByte` | Sends a single byte wirelessly. |
| `BLUETOOTH_receiveByte` | Receives a single byte wirelessly. |
| `BLUETOOTH_sendString` | Sends a full string. |
| `BLUETOOTH_receiveString` | Receives a string until the terminator character. |

## 🚀 Usage Example
```c
#include "BLUETOOTH_interface.h"

void main() {
    BLUETOOTH_init();
    BLUETOOTH_sendString("Bluetooth Ready!\r\n");
}
```
