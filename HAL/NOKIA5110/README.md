
---
# 📦 NOKIA5110 Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The NOKIA5110 (PCD8544) driver provides an interface for the classic monochrome graphic LCD. It supports text rendering, custom bitmaps, and contrast control used in various embedded projects.

## 🔌 Hardware Connection
| Pin Name | Port | Pin Number | Note |
| :--- | :--- | :--- | :--- |
| `SCE` | `PORTC` | `PIN0` | Chip Enable |
| `D/C` | `PORTC` | `PIN1` | Data/Command Select |
| `RST` | `PORTC` | `PIN2` | Reset |
| `DN(MOSI)` | `PORTB` | `PIN5` | SPI Data |
| `SCLK` | `PORTB` | `PIN7` | SPI Clock |

## ⚙️ Configuration (`NOKIA5110_config.h`)
| Macro | Description | Options |
| :--- | :--- | :--- |
| `CTRL_PORT` | Control signals port | `DIO_PORTC` |
| `SCE`, `D_C`, `RST` | Control pin definitions | `DIO_PIN0`, etc. |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `NOKIA5110_init` | Initializes the display. |
| `NOKIA5110_sendString` | Draws a text string. |
| `NOKIA5110_drawFullImage` | Renders a 84x48 bitmap. |
| `NOKIA5110_setContrast` | Adjusts display contrast. |
| `NOKIA5110_setXY` | Moves the cursor. |

## 🚀 Usage Example
```c
#include "NOKIA5110_interface.h"

void main() {
    NOKIA5110_init();
    NOKIA5110_sendString("Nokia 5110");
}
```
