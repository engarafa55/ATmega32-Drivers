
---
# 📦 EXTI Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The External Interrupt (EXTI) driver manages the external hardware interrupts (INT0, INT1, INT2). It allows configuring the trigger mechanism (rising edge, falling edge, low level, or any logical change) and registering callback functions for event handling.

## ⚙️ Configuration (`EXTI_Config_t`)
This driver uses a configuration structure `EXTI_Config_t` passed to initialization and runtime functions.

| Field | Description | Options |
| :--- | :--- | :--- |
| `Interrupt` | Selects which interrupt to configure | `EXTI_INT0`, `EXTI_INT1`, `EXTI_INT2` |
| `SenseControl` | Sets the trigger condition | `EXTI_SENSE_LOW_LEVEL`, `EXTI_SENSE_ANY_CHANGE`, `EXTI_SENSE_FALLING_EDGE`, `EXTI_SENSE_RISING_EDGE` |
| `Callback` | Pointer to the function to execute on interrupt | Valid function pointer |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `EXTI_init` | Initializes a specific interrupt with configuration. |
| `EXTI_enable` | Enables a specific external interrupt. |
| `EXTI_disable` | Disables a specific external interrupt. |
| `EXTI_setCallback` | Registers a user function to be called when the interrupt occurs. |

## 🚀 Usage Example
```c
#include "EXTI_interface.h"
#include "GIE_interface.h"

void my_isr(void) {
    // Handle interrupt
}

void main() {
    EXTI_Config_t extiConfig = {
        .Interrupt = EXTI_INT0,
        .SenseControl = EXTI_SENSE_FALLING_EDGE,
        .Callback = my_isr
    };

    EXTI_init(&extiConfig);
    GIE_enable();
    
    while(1);
}
```
