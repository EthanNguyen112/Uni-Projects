# Traffic Light Controller

A traffic light control system developed using the Tiva™ C Series TM4C123G LaunchPad and C programming in Keil µVision4. This project simulates a real-world intersection with North-South and East-West vehicle lanes, as well as pedestrian crossing functionality, controlled by a state machine design.

## Overview

This project demonstrates the use of GPIO, external hardware switches, and state machine logic to simulate traffic light behavior. Priority is given to pedestrians, followed by North-South and East-West traffic based on input from physical switches.

## Features

- Controls two one-way intersections: North–South and East–West
- Pedestrian crosswalk with distinct green and flashing red behavior
- Three physical switches for direction/pedestrian input
- Lights cycle automatically based on current input states
- Priority-based control: Pedestrian > North–South > East–West
- Uses a Moore finite state machine for traffic logic
- Delay implemented using SysTick Timer

## How It Works

1. **Switch-Based Control**  
   - Each switch represents a traffic direction or pedestrian request.
   - When pressed, the switch signals the system to grant a green light in a fixed priority order.
   
2. **State Machine Logic**  
   - The system uses a Moore FSM to manage transitions between states:
     - North–South Green
     - East–West Green
     - Pedestrian Green (with flashing red transition)
   - Inputs are polled and processed in real-time to determine the next state.

3. **Hardware Setup**
   - External resistors ensure safe voltage levels
   - GPIO Ports B, E, and F are used to control the LEDs
   - Input switches are debounced and monitored for state changes

4. **Timing Control**
   - SysTick Timer is used to introduce timing delays between state transitions (e.g. yellow to red, red to green)

## Technologies Used

- Tiva™ C Series TM4C123G LaunchPad
- Embedded C (Keil µVision4 IDE)
- GPIO registers
- SysTick Timer
- Moore Finite State Machine

## Hardware Design

- LEDs for traffic and pedestrian signals
- 3 Push-button switches for input control
- Pull-down resistors
- Breadboard and jumper wires

https://github.com/EthanNguyen112/Uni-Projects/issues/2#issue-3258030652

## Software Architecture

- GPIO Initialization via base register addresses
- Switch polling with priority resolution
- State transitions defined via `enum` and conditional logic
- Delay logic implemented using `SysTick_Wait()` calls

https://github.com/EthanNguyen112/Uni-Projects/issues/2#issuecomment-3111534234

## Challenges & Lessons Learned

- **Challenges:** GPIO misconfiguration, port initialization issues, and minor hardware wiring mistakes
- **Successes:** Proper implementation of the SysTick timer and successful FSM sequencing
- **Future Improvements:** Enhanced debouncing, improved error handling, support for left-turn signals and traffic sensors

## Getting Started

1. Flash the compiled binary to your TM4C123G LaunchPad using Keil µVision4.
2. Connect LEDs and switches to the appropriate GPIO ports.
3. Power the board via USB and observe the sequence based on switch inputs.



This project was created as part of an embedded systems curriculum to demonstrate hardware/software integration using state machines and timing control.
