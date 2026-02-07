
---
# 📦 MPU6050 Driver

![Type](https://img.shields.io/badge/Layer-HAL-blue)
![Status](https://img.shields.io/badge/Status-Tested-success)

## 📝 Overview
The MPU6050 driver enables communication with the 6-axis MotionTracking device (3-axis Gyroscope + 3-axis Accelerometer) via I2C. It supports reading raw sensor data and temperature.

## 🔌 Hardware Connection
| Pin Name | Port | Pin Number | Note |
| :--- | :--- | :--- | :--- |
| `SDA` | `PORTC` | `PIN1` | I2C Data |
| `SCL` | `PORTC` | `PIN0` | I2C Clock |

## ⚙️ Configuration (`MPU6050_Config_t`)
| Field | Description | Options |
| :--- | :--- | :--- |
| `AccelRange` | Accelerometer full-scale range | `2G`, `4G`, `8G`, `16G` |
| `GyroRange` | Gyroscope full-scale range | `250`, `500`, `1000`, `2000` DPS |

## 💻 API Reference
| Function | Description |
| :--- | :--- |
| `MPU6050_init` | Initializes the sensor with the specified ranges. |
| `MPU6050_readAll` | Reads ACCEL_X/Y/Z, GYRO_X/Y/Z, and Temperature data in one burst. |

## 🚀 Usage Example
```c
#include "MPU6050_interface.h"

void main() {
    MPU6050_Config_t config = {
        .AccelRange = MPU6050_ACCEL_RANGE_2G,
        .GyroRange = MPU6050_GYRO_RANGE_250_DPS
    };
    
    MPU6050_init(&config);
    
    MPU6050_Data_t accel, gyro;
    float32 temp;
    MPU6050_readAll(&accel, &gyro, &temp);
}
```
