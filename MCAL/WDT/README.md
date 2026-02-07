
---
# 📦 WDT Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Watchdog Timer (WDT) driver provides a safety mechanism to reset the microcontroller if the main program becomes unresponsive. It features configurable timeout periods.

## ⚙️ Configuration
The timeout period is set using the `WDT_SleepTime_t` enum during runtime configuration.

| Enum | Description |
| :--- | :--- |
| `WDT_SleepTime_t` | Options range from `WDT_SLEEP_16_3_MS` to `WDT_SLEEP_2_1_S` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `WDT_enable` | Enables the Watchdog Timer. |
| `WDT_disable` | Disables the Watchdog Timer (requires specific sequence). |
| `WDT_setSleepTime` | Sets the reset timeout duration. |

## 🚀 Usage Example
```c
#include "WDT_interface.h"

void main() {
    WDT_setSleepTime(WDT_SLEEP_1_0_S); // Reset if not refreshed within 1s
    WDT_enable();
    
    while(1) {
        // Main loop tasks
        
        // Refresh WDT within 1s to prevent reset? 
        // Note: AVR WDT usually resets system if it times out. 
        // To "refresh" usually involves specific assembly instructions (WDR) 
        // or disabling/re-enabling, depending on implementation.
    }
}
```
