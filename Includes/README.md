
# 🛠️ Common Includes & Libraries

![Type](https://img.shields.io/badge/Type-Helper%20Libraries-grey)

## 📂 File Description
* **`DEVICE_CONFIG.h`**: Global hardware settings, primarily the CPU frequency definition.
* **`STD_TYPES.h`**: Portable, fixed-width integer typedefs (e.g., `uint8`, `float32`) to ensure consistency across platforms.
* **`BIT_MACROS.h`**: Classic bit manipulation macros (`SET_BIT`, `CLEAR_BIT`, `TOGGLE_BIT`, `READ_BIT`).
* **`STD_LIBRARIES.h`**: Central hub for standard AVR libraries like `<avr/interrupt.h>` and `<util/delay.h>`.

## ⚙️ Global Configuration (`DEVICE_CONFIG.h`)
| Macro | Description | Default |
| :--- | :--- | :--- |
| `F_CPU` | System Clock Frequency | `16000000UL` (16 MHz) |

## 📏 Standard Types Reference
| Type | Definition | Usage |
| :--- | :--- | :--- |
| `u8` / `uint8` | `unsigned char` | 8-bit unsigned integer (0..255) |
| `u16` / `uint16` | `unsigned short int` | 16-bit unsigned integer |
| `u32` / `uint32` | `unsigned long` | 32-bit unsigned integer |
| `float32` | `float` | 32-bit floating point number |
| `Std_ReturnType` | `uint8` | Standard error status (`E_OK`, `E_NOT_OK`) |
