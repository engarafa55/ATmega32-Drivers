
---
# 📦 SERVO Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Servo driver facilitates precise control of servo motors by generating PWM signals with specific duty cycles corresponding to the desired angle (0° to 180°).

## 🔌 Hardware Connection
| Pin Name | Connection | Note |
| :--- | :--- | :--- |
| `Signal` | `OC1A/B` | PWM Output Pin (Timer1) |
| `VCC` | `5V` | External Power Supply recommended |
| `GND` | `GND` | Shared Ground |

## ⚙️ Configuration
The driver typically assumes a specific timer configuration (e.g., Timer1 Fast PWM) hardcoded or configured in the initialization sequence.

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `SERVO_init` | Initializes the timer for servo control. |
| `SERVO_setAngle` | Sets the servo position (0-180 degrees). |

## 🚀 Usage Example
```c
#include "SERVO_interface.h"

void main() {
    SERVO_init();
    SERVO_setAngle(90); // Move to center position
}
```
