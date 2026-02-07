
---
# 📦 LDR Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Light Dependent Resistor (LDR) driver reads ambient light levels by interfacing with an LDR voltage divider circuit connected to an ADC channel. It converts raw analog readings into voltage values.

## 🔌 Hardware Connection
| Pin Name | Connection | Note |
| :--- | :--- | :--- |
| `Signal` | `ADC Pin` | Output of voltage divider |
| `VCC/GND` | `Power` | Divider reference (usually 5V) |

## ⚙️ Configuration
The driver is configured at runtime using the `LDR_t` structure.

| Field | Description |
| :--- | :--- |
| `Channel` | The ADC channel connected to the LDR |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `LDR_Read` | Reads the raw value and calculates the voltage. |

## 🚀 Usage Example
```c
#include "LDR_interface.h"

void main() {
    LDR_t myLDR = { .Channel = ADC_CHANNEL_0 };
    
    LDR_Read(&myLDR);
    float32 volts = myLDR.Voltage;
}
```
