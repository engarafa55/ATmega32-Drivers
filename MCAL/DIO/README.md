
---
# 📦 DIO Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Digital Input/Output (DIO) driver provides an interface to control the microcontroller's genera purposel I/O pins. It allows setting pin directions, writing high/low values, reading pin states, and controlling internal pull-up resistors.

## ⚙️ Configuration (`DIO_config.h`)
| Macro | Description | Options |
| :--- | :--- | :--- |
| `DIO_PORTx_PINy_DIR` | Sets pin direction | `DIO_PIN_INPUT`, `DIO_PIN_OUTPUT` |
| `DIO_PORTx_PINy_INIT_VAL` | Sets initial pin value (or pull-up) | `DIO_PIN_LOW`, `DIO_PIN_HIGH` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `DIO_init` | Initializes all pins based on `DIO_config.h` settings. |
| `DIO_writePin` | Sets a specific pin to High or Low. |
| `DIO_readPin` | Reads the current logical state of a pin. |
| `DIO_togglePin` | Toggles the state of a pin. |
| `DIO_writePort` | Writes a byte value to an entire port. |
| `DIO_readPort` | Reads the value of an entire port. |

## 🚀 Usage Example
```c
#include "DIO_interface.h"

void main() {
    DIO_init(); // Initialize pins as configured
    
    // Toggle LED on Port A, Pin 0
    DIO_togglePin(DIO_PORTA, DIO_PIN0);
}
```
