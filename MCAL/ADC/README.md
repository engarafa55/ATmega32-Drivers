
---
# 📦 ADC Driver

![Type](https://img.shields.io/badge/Layer-MCAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Analog-to-Digital Converter (ADC) driver enables converting analog voltage signals into digital values. It supports configurable voltage references, prescalers for clock adjustment, and auto-triggering capabilities.

## ⚙️ Configuration (`ADC_Config_t`)
This driver uses a configuration structure `ADC_Config_t` passed to the initialization function.

| Field | Description | Options |
| :--- | :--- | :--- |
| `VoltageReference` | Selects reference voltage source | `ADC_VOLTAGE_REF_AREF`, `ADC_VOLTAGE_REF_AVCC`, `ADC_VOLTAGE_REF_INTERNAL_2_56V` |
| `Prescaler` | Sets the ADC clock prescaler | `ADC_PRESCALER_2` to `ADC_PRESCALER_128` |
| `AutoTriggerEnable` | Enables auto-triggering mode | `TRUE`, `FALSE` |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `ADC_init` | Initializes the ADC with the given configuration structure. |
| `ADC_readChannel` | Reads the 10-bit digital value from a specific ADC channel (Blocking). |

## 🚀 Usage Example
```c
#include "ADC_interface.h"

void main() {
    ADC_Config_t adcConfig = {
        .VoltageReference = ADC_VOLTAGE_REF_AVCC,
        .Prescaler = ADC_PRESCALER_64,
        .AutoTriggerEnable = FALSE
    };

    ADC_init(&adcConfig);
    
    uint16 adcValue;
    ADC_readChannel(ADC_CHANNEL_0, &adcValue);
}
```
