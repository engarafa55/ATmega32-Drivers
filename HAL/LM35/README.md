
---
# 📦 LM35 Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The LM35 driver interfaces with the LM35 precision analog temperature sensor. It converts the ADC voltage reading directly into degrees Celsius (10mV/°C scale factor).

## 🔌 Hardware Connection
| Pin Name | Connection | Note |
| :--- | :--- | :--- |
| `VOUT` | `ADC Pin` | Analog output (10mV/°C) |
| `Vs` | `5V` | Supply Voltage |
| `GND` | `GND` | Ground |

## ⚙️ Configuration
Configuration involves selecting the ADC channel at runtime.

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `LM35_init` | Initializes the driver (placeholder for ADC setup). |
| `LM35_getTemperature` | Reads the ADC channel and calculates temperature in Celsius. |

## 🚀 Usage Example
```c
#include "LM35_interface.h"

void main() {
    float32 temp;
    LM35_getTemperature(ADC_CHANNEL_1, &temp);
}
```
