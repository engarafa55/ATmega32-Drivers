
# 🧠 Application Layer (APP)

![Layer](https://img.shields.io/badge/Layer-Application-purple)

## 📝 System Overview
The main application logic coordinates the interaction between hardware inputs (Buttons) and outputs (LEDs). 
1.  **Initialization**: Sets up the DIO pins for buttons and LEDs.
2.  **Logic Loop**: Monitoring a specific button (`Button1`). When pressed, it enters a secondary check state with a debounce delay. If confirmed, it toggles two LEDs (`LED1`, `LED2`) and waits for the button to be released before resuming.

## ⚙️ Application Configuration (`AppConfig.h`)
This file aggregates the necessary driver interfaces required by the application.

| Macro | Description | Current Value |
| :--- | :--- | :--- |
| N/A | No specific application macros defined currently. | N/A |

## 🔄 System Flowchart (Text Description)
1. **Initialize:** `DIO_init()` triggers the pin configurations defined in `DIO_config.h`.
2. **Loop:**
    *   **Poll Button 1:** Continuously checks state of `PD3`.
    *   **Debounce:** If pressed, waits 50ms and checks again.
    *   **Action:** If confirmed pressed:
        *   Toggles `LED1` (PA5) and `LED2` (PA6).
        *   **Blocking Wait:** Loops until button is released to prevent rapid toggling.
    *   **Repeat.**
