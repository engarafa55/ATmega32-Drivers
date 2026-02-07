
---
# 📦 I2C_LCD Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
This driver controls a character LCD via an I2C I/O expander (e.g., PCF8574). It saves microcontroller pins by using only the two I2C lines to control the entire display.

## 🔌 Hardware Connection
| Pin Name | Value | Note |
| :--- | :--- | :--- |
| `I2C Address` | `0x27` | Default PCF8574 address |

## ⚙️ Configuration (`I2C_LCD.h`)
| Macro | Description | Options |
| :--- | :--- | :--- |
| `I2C_LCD_ADDRESS` | The I2C address of the expander module | `0x27` or `0x3F` typically |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `I2C_LCD_init` | Initializes the LCD in I2C mode. |
| `I2C_LCD_displayString` | Displays a text string. |
| `I2C_LCD_moveCursor` | Moves cursor to (Row, Col). |
| `I2C_LCD_clearScreen` | Clears the display. |

## 🚀 Usage Example
```c
#include "I2C_LCD.h"

void main() {
    I2C_LCD_init();
    I2C_LCD_displayStringRowColumn(0, 0, "I2C Mode!");
}
```
