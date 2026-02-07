
---
# 📦 KEYPAD Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Keypad driver scans a matrix keypad (e.g., 4x3 or 4x4) to detect key presses. It uses a row-scanning algorithm to identify which button is pressed.

## 🔌 Hardware Connection
| Pin Name | Port | Pin Number | Note |
| :--- | :--- | :--- | :--- |
| `ROWS` | `PORTD` | `PIN0-3` | Output (Scan lines) |
| `COLS` | `PORTD` | `PIN4-7` | Input (Read lines) |

## ⚙️ Configuration (`KEYPAD_config.h`)
| Macro | Description | Options |
| :--- | :--- | :--- |
| `KEYPAD_PORT` | Port connected to keypad | `DIO_PORTD` |
| `KEYPAD_ARRAY` | 2D array defining key mapping | `{{'7','8','9','/'}, ...}` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `KEYPAD_init` | Initializes keypad port directions. |
| `KEYPAD_getPressedKey` | Scans and returns the pressed key character. Returns `NO_KEY_PRESSED` if idle. |

## 🚀 Usage Example
```c
#include "KEYPAD_interface.h"

void main() {
    KEYPAD_init();
    
    while(1) {
        uint8 key = KEYPAD_getPressedKey();
        if(key != NO_KEY_PRESSED) {
            // Act on key press
        }
    }
}
```
