
---
# 📦 USART Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Universal Synchronous/Asynchronous Receiver Transmitter (USART) driver facilitates serial communication. It allows configuring baud rates, character sizes, parity bits, and stop bits for flexible data exchange.

## ⚙️ Configuration (`USART_Config_t`)
This driver uses a configuration structure `USART_Config_t` passed to initialization.

| Field | Description | Options |
| :--- | :--- | :--- |
| `BaudRate` | Communication speed in bps | e.g. `9600`, `115200` |
| `CharSize` | Number of data bits | `USART_CHAR_SIZE_8_BIT`, etc. |
| `Parity` | Error checking bit | `USART_PARITY_DISABLED`, `USART_PARITY_EVEN`, `USART_PARITY_ODD` |
| `StopBits` | Number of stop bits | `USART_STOP_BITS_1`, `USART_STOP_BITS_2` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `USART_init` | Initializes the USART with the given configuration structure. |
| `USART_send` | Transmits a single byte of data. |
| `USART_receive` | Receives a single byte of data (Blocking). |
| `USART_sendStream` | Transmits a NULL-terminated string. |

## 🚀 Usage Example
```c
#include "USART_interface.h"

void main() {
    USART_Config_t usartConfig = {
        .BaudRate = 9600,
        .CharSize = USART_CHAR_SIZE_8_BIT,
        .Parity = USART_PARITY_DISABLED,
        .StopBits = USART_STOP_BITS_1
    };

    USART_init(&usartConfig);
    USART_sendStream("Hello World!");
}
```
