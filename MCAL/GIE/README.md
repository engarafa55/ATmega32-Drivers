
---
# 📦 GIE Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Global Interrupt Enable (GIE) driver controls the global interrupt bit (I-bit) in the Status Register (SREG). This master switch is required to enable or disable all maskable interrupts on the microcontroller.

## ⚙️ Configuration
This driver requires no compile-time configuration.

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `GIE_enable` | Sets the I-bit in SREG, enabling global interrupts. |
| `GIE_disable` | Clears the I-bit in SREG, disabling global interrupts. |

## 🚀 Usage Example
```c
#include "GIE_interface.h"

void main() {
    // Critical Section Start
    GIE_disable(); 
    
    // Perform atomic operation
    
    // Critical Section End
    GIE_enable();
}
```
