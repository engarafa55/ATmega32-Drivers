
---
# 📦 Timer Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Timer/Counter driver manages the microcontroller's internal timers (Timer0, Timer1, Timer2). It supports multiple modes including Normal, CTC (Clear Timer on Compare), and Fast/Phase-Correct PWM, as well as Input Capture for frequency measurements.

## ⚙️ Configuration (`TIMER_Config_t`)
This driver uses a configuration structure `TIMER_Config_t` passed to initialization.

| Field | Description | Options |
| :--- | :--- | :--- |
| `TimerID` | Selects the timer instance | `TIMER0`, `TIMER1`, `TIMER2` |
| `Mode` | Sets the operating mode | `TIMER_MODE_NORMAL`, `TIMER_MODE_CTC`, `TIMER_MODE_FAST_PWM`, etc. |
| `Prescaler` | Sets the clock prescaler | `TIMER_PRESCALER_64`, `TIMER_PRESCALER_256`, etc. |
| `OC_Mode` | Configures the Output Compare pin behavior | `TIMER_OC_DISCONNECTED`, `TIMER_OC_TOGGLE`, `TIMER_OC_CLEAR`, `TIMER_OC_SET` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `TIMER_init` | Initializes a specific timer with the provided config. |
| `TIMER_deinit` | Stops and disables a specific timer. |
| `TIMER_setCompareValue` | Sets the Output Compare Register (OCR) value. |
| `TIMER_setDutyCycle` | Sets the PWM duty cycle (0-100%). |
| `TIMER_setCallback` | Sets the callback function for Timer Interrupts. |
| `TIMER_icu_init` | Initializes the Input Capture Unit (Timer1). |
| `TIMER_icu_readInput` | Reads the current captured value (ICR1). |

## 🚀 Usage Example
```c
#include "TIMER_interface.h"

void main() {
    TIMER_Config_t timer0Config = {
        .TimerID = TIMER0,
        .Mode = TIMER_MODE_FAST_PWM,
        .Prescaler = TIMER_PRESCALER_64,
        .OC_Mode = TIMER_OC_CLEAR // Non-inverting PWM
    };

    TIMER_init(&timer0Config);
    TIMER_setDutyCycle(TIMER0, 50.0); // 50% Duty Cycle
}
```
