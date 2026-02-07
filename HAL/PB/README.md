
---
# 📦 PB Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Push Button (PB) driver handles input from mechanical switches. It abstracts the GPIO reading process and provides simple Pressed/Released states.

## 🔌 Hardware Connection
| Pin Name | Connection | Note |
| :--- | :--- | :--- |
| `Switch` | `GPIO Pin` | Pull-up/down dependent on circuit |

## ⚙️ Configuration
The driver uses the `PB_t` structure for runtime configuration.

| Field | Description |
| :--- | :--- |
| `Port` | Port where the button is connected |
| `Pin` | Pin number of the button |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `PB_init` | Initializes the button pin direction. |
| `PB_read` | Reads the current state (`PB_PRESSED` or `PB_RELEASED`). |

## 🚀 Usage Example
```c
#include "PB_interface.h"

void main() {
    PB_t myButton = { .Port = DIO_PORTD, .Pin = DIO_PIN2 };
    PB_init(&myButton);
    
    PB_State_t state;
    PB_read(&myButton, &state);
}
```
