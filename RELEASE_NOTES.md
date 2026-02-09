# 📦 Release Notes: v3.1.0 (GitHub Migration)

[![Release](https://img.shields.io/badge/Release-v3.1.0-blue.svg?style=for-the-badge&logo=github)](https://github.com/AbdelrahmanArafa)
[![Date](https://img.shields.io/badge/Date-2026--01--30-lightgrey.svg?style=for-the-badge&logo=calendar)](https://github.com/AbdelrahmanArafa)
[![Safety](https://img.shields.io/badge/Safety-Audited-success.svg?style=for-the-badge&logo=shield)](https://github.com/AbdelrahmanArafa)

> **The "Gold Master" release designates the ATmega32 Drivers as a fully stable, verified, and production-ready system.**

---

## � Overview

This milestone release prioritizes **Reliability**, **Safety**, and **System Stability**. We have eliminated critical "silent killers" in the driver stack, resolved hardware resource conflicts, and standardized the architecture for future scalability.

### 🎯 Key Highlights
*   **🛡️ Safety Audited:** Eliminated undefined behavior caused by missing ISRs and improper pointer handling.
*   **⚡ Logic Hardening:** Fixed blocking conditions in communication protocols.
*   **🧩 Conflict Resolution:** Resolved pin mapping collisions between display drivers.

---


## 📅 Version History

| Version | Date | Milestone | Description |
| :--- | :--- | :--- | :--- |
| **v3.1.0** | **Feb 2026** | **GitHub Migration** | Migration to GitHub, Refactoring, and Documentation Update. |
| **v3.0.0** | **Nov 2024** | **Stable Release** | Final System Integration & Application Logic. |
| **v2.0.0** | **Aug 2024** | **Peak Development** | HAL Layer Integration & Peak Development. |
| **v1.0.0** | **Mar 2024** | **Kickoff** | Project Kickoff & MCAL Layer Implementation. |

---
## � Bug Fixes

### � SPI Communication Logic
- **Issue:** The `SPI_transceive` function enforced a strict full-duplex protocol, returning an error if the receive buffer was `NULL`. This prevented write-only devices (e.g., Nokia 5110 LCD) from receiving commands.
- **Fix:** Refactored the logic to gracefully handle `NULL` receive pointers. The driver now transmits data regardless of the receiver buffer state and performs a dummy read to clear the interrupt flag.

### ⏱️ Timer2 Interrupt Handling
- **Issue:** Enabling Timer2 interrupts without defining the corresponding Interrupt Service Routines (ISRs) caused the CPU to jump to the Reset Vector (system restart) upon interrupt trigger.
- **Fix:** Implemented default `TIMER2_OVF_vect` and `TIMER2_COMP_vect` handlers to prevent unhandled vector resets.

### ⚡ Port A Resource Conflict
- **Issue:** Both the `CLCD` (Character LCD) and `NOKIA5110` drivers were physically mapped to drive **Port A, Pins 0-2**, leading to bus contention.
- **Fix:** Remapped the `NOKIA5110` control lines (RST, DC, CE) to **Port C** to ensure exclusive bus access for each peripheral.

---

## 🚀 Improvements & Enhancements

### 🧱 Architecture & Standards
- **🆕 ISR Standardization:** Replaced manual `__vector_N` definitions with the standard `ISR()` macros from `<avr/interrupt.h>`. This improves code readability and compiler compatibility.
- **⚙️ Configuration Limits:** Updated `DIO_config.h` defaults to ensure safety-critical pins (e.g., LEDs, Control Lines) are initialized as `OUTPUT` and Input pins (e.g., Buttons) have internal `PULL-UP` resistors enabled.
- **🏷️ Consistent Branding:** Unified file headers across all MCAL and HAL layers to maintain authorship tracking and licensing consistency.

### 📚 Documentation
- **📝 Code Comments:** Added comprehensive Doxygen-style comments to all public API functions, detailing parameters, return values, and usage warnings.

---

## 🏗️ Technical Deep Dive

A closer look at the most significant technical challenges resolved in this release.

### 1️⃣ The "Silent" SPI Blocker
The original SPI implementation assumed that every transmission requires a reception. This is valid for sensors but fails for display controllers.

**Before (Blocking):**
```c
if (DataToReceive == NULL) return E_NOT_OK; // ❌ Aborts if we only want to write
SPDR = DataToSend;
```

**After (Flexible):**
```c
SPDR = DataToSend;           // ✅ Send data unconditionally
while(CHECK_BIT(SPSR, SPIF) == 0); // Wait for transmission complete

if (DataToReceive != NULL) {
    *DataToReceive = SPDR;   // Store data if requested
} else {
    (void)SPDR;              // Dummy read to clear SPIF flag
}
```

### 2️⃣ The Port Conflict Resolution
We detected a collision where multiple drivers claimed the same GPIO resources.

**Conflict Map:**
| Pin | Driver 1 (CLCD) | Driver 2 (Nokia 5110) | Status |
| :--- | :--- | :--- | :--- |
| `PA0` | `RS` | `RST` | ❌ **Collision** |
| `PA1` | `RW` | `DC` | ❌ **Collision** |
| `PA2` | `EN` | `CE` | ❌ **Collision** |

**Resolution:**
The Nokia 5110 control lines were actively migrated to **Port C**, and `DIO_config.h` was updated to reflect this new physical topology.

---

## 👤 Author

**Abdelrahman Arafa**
*Mechatronics Engineer*

📧 [engarafa55@gmail.com](mailto:engarafa55@gmail.com)
