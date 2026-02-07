
---
# 📦 SPI Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Serial Peripheral Interface (SPI) driver enables high-speed full-duplex synchronous communication methods. It can be configured in Master or Slave mode and supports various clock rates and data orders.

## ⚙️ Configuration (`SPI_Config_t`)
This driver uses a configuration structure `SPI_Config_t` passed to initialization.

| Field | Description | Options |
| :--- | :--- | :--- |
| `Mode` | Selects Master or Slave operation | `SPI_MODE_MASTER`, `SPI_MODE_SLAVE` |
| `ClockRate` | Sets the SCK frequency (Master only) | `SPI_CLOCK_RATE_F_CPU_4` to `SPI_CLOCK_RATE_F_CPU_128` |
| `DataOrder` | Selects which bit is transmitted first | `SPI_DATA_ORDER_MSB_FIRST`, `SPI_DATA_ORDER_LSB_FIRST` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `SPI_init` | Initializes the SPI module with the given configuration. |
| `SPI_transceive` | Sends a byte and receives a byte simultaneously. |

## 🚀 Usage Example
```c
#include "SPI_interface.h"

void main() {
    SPI_Config_t spiConfig = {
        .Mode = SPI_MODE_MASTER,
        .ClockRate = SPI_CLOCK_RATE_F_CPU_16,
        .DataOrder = SPI_DATA_ORDER_MSB_FIRST
    };

    SPI_init(&spiConfig);
    
    uint8 receivedData;
    SPI_transceive('A', &receivedData);
}
```
