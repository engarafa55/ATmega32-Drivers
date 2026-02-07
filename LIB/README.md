
---
# 📦 LIB Math Utilities

![Type](https://img.shields.io/badge/Layer-LIB-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The Math Library provides a collection of utility functions for common mathematical operations needed in embedded applications, such as mapping ranges and rounding values.

## ⚙️ Configuration
No configuration required.

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `map` | Re-maps a number from one range to another. |
| `floor` | Returns the largest integer not greater than x. |
| `ceil` | Returns the smallest integer not less than x. |

## 🚀 Usage Example
```c
#include "math.h"

void main() {
    int val = map(512, 0, 1023, 0, 255); // Map 10-bit ADC to 8-bit PWM
}
```
