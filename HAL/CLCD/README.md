
---
# 📦 CLCD Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Character LCD (CLCD) driver provides an interface for standard 16x2 or 20x4 LCD modules based on the HD44780 controller. It supports displaying text, cursor control, and custom characters.

## 🔌 Hardware Connection
| Pin Name | Port | Pin Number | Note |
| :--- | :--- | :--- | :--- |
| `RS` | `PORTA` | `PIN0` | Register Select |
| `RW` | `PORTA` | `PIN1` | Read/Write |
| `EN` | `PORTA` | `PIN2` | Enable |
| `DATA` | `PORTB` | `PIN0-7` | Data Bus (if 8-bit mode) |

## ⚙️ Configuration (`CLCD_config.h`)
| Macro | Description | Options |
| :--- | :--- | :--- |
| `CLCD_DATA_PORT` | Port connected to data lines | `DIO_PORTB` |
| `CLCD_CTRL_PORT` | Port connected to control lines | `DIO_PORTA` |
| `CLCD_MODE` | 4-bit or 8-bit operation | `MODE_4_BIT`, `MODE_8_BIT` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `CLCD_init` | Initializes the LCD display. |
| `CLCD_SendString` | Displays a string at the current cursor position. |
| `CLCD_GoTOXY` | Moves cursor to specified (X, Y) coordinates. |
| `CLCD_Clear` | Clears the display content. |

## 🚀 Usage Example
```c
#include "CLCD_interface.h"

void main() {
    CLCD_init();
    CLCD_GoTOXY(0, 0); // Row 0, Col 0
    CLCD_SendString("Hello embedded!");
}
```
