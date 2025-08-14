# Bluetooth Controlled Robot Car

## Summary
A wireless robot car built using the **TM4C123G microcontroller** and **HC-05 Bluetooth module**, controlled from a laptop or smartphone via UART communication. Demonstrates **embedded systems**, **Bluetooth configuration**, and **PWM-based motor control**.

## Highlights
- **Bluetooth control** using HC-05 module with secure pairing  
- Real-time movement commands (Forward, Backward, Left, Right, Stop)  
- Adjustable speed via PWM signal  
- Status LEDs for movement feedback  
- Configured device with custom name and password via AT commands  

## Tech Stack
- **Hardware**: TM4C123G LaunchPad, HC-05 Bluetooth, Motor Driver, DC Motors, Breadboard  
- **Software**: Embedded C, UART, PWM, Code Composer Studio  
- **Protocols**: Serial Port Profile (SPP) over Bluetooth  

## How It Works
1. Bluetooth module is configured with name `name` and password `password`.  
2. Paired device sends ASCII commands via Bluetooth Serial Terminal.  
3. TM4C123G parses commands and drives motors through PWM-controlled motor driver.  

**Command Examples:**
| Command | Action         |
|---------|---------------|
| W       | Forward        |
| S       | Backward       |
| A       | Left           |
| D       | Right          |
| T       | Stop           |
| U       | Speed Up       |
| L       | Slow Down      |



