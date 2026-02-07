
---
# 📦 LED Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The LED driver provides a simple abstraction for controlling Light Emitting Diodes. It supports turning LEDs on, off, and toggling their state using GPIO pins.

## 🔌 Hardware Connection
| Pin Name | Connection | Note |
| :--- | :--- | :--- |
| `Anode` | `GPIO Pin` | With current limiting resistor |
| `Cathode` | `GND` | Common ground |

## ⚙️ Configuration
The driver uses the `LED_t` structure for runtime configuration.

| Field | Description |
| :--- | :--- |
| `Port` | Port where the LED is connected |
| `Pin` | Pin number of the LED |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `LED_turnOn` | Sets the LED pin High. |
| `LED_turnOff` | Sets the LED pin Low. |
| `LED_toggle` | Inverts the current state of the LED pin. |

## 🚀 Usage Example
```c
#include "LED_interface.h"

void main() {
    LED_t powerLed = { .Port = DIO_PORTB, .Pin = DIO_PIN0 };
    
    LED_turnOn(&powerLed);
}
```
