# FPGA Oscilloscope

## Overview
This project implements a digital oscilloscope using an FPGA. It captures, processes, and visualizes analog signals in real time by sampling input data and displaying the waveform on a VGA/monitor interface. The design demonstrates Verilog HDL, digital signal processing, and hardware interfacing concepts.

---

## Features
- Signal sampling with adjustable frequency.  
- Real-time waveform display on VGA.  
- Triggering support (edge detection).  
- Multiple voltage/time scale modes.  
- Modular Verilog design for readability and reuse.  

---

## Hardware
- FPGA Development Board (e.g., Xilinx / Altera / DE1 / Nexys board).  
- VGA output display.  
- ADC module for analog input.  
- Wires, connectors, and breadboard (if external circuits are used).  

---

## Usage
1. Load the Verilog design onto the FPGA.  
2. Connect the analog signal source to the ADC input.  
3. Connect the FPGA to a VGA monitor.  
4. Adjust sampling settings and trigger modes via switches/buttons.  
5. Observe the waveform displayed in real time.  

---

## Theory
The oscilloscope samples analog signals using an ADC and stores them in on-chip memory (FIFO or buffer). The FPGA processes the samples and generates VGA timing signals to draw the waveform. Trigger logic ensures stable signal capture, while adjustable parameters allow zooming and scaling.

---

## Future Improvements
- Add USB/serial data transfer for waveform logging.  
- Implement FFT mode for frequency analysis.  
- Enhance GUI with gridlines and measurement markers.  

---

## Conclusion
This project highlights FPGA capabilities for real-time signal processing and visualization. It combines Verilog design, ADC interfacing, and VGA display control to create a functional oscilloscope prototype.  
