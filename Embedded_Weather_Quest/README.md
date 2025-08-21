# Embedded Weather Quest (IoT Weather Application)

## Introduction
This project demonstrates how to build an **IoT-enabled embedded weather application** using the **TM4C123GXL LaunchPad**, the **CC3100 Wi-Fi Module**, and the **ST7735R Color LCD**. The system connects to the internet, retrieves weather data from the **OpenWeatherMap API**, and displays results both on a **serial terminal** and the **LCD screen**.  

The goal of the project was to integrate multiple embedded concepts learned throughout the semester:
- Wi-Fi connectivity
- UART communication
- API integration
- LCD graphics & animations
- User query selection  

---

## Operation
1. The system connects to a configured Wi-Fi access point. Without internet access, no weather data can be retrieved or displayed.  
2. Using a serial terminal (baud rate **115200**), load the program onto the TM4C123.  
3. A prompt appears allowing the user to choose between **four query modes**:  
   - **Mode 1**: City Name  
   - **Mode 2**: City ID  
   - **Mode 3**: Geographic Coordinates  
   - **Mode 4**: Zip Code  
4. Once a location is entered, the system requests data from **OpenWeatherMap.org** and displays:  
   - Minimum temperature  
   - Maximum temperature  
   - Humidity  
   - Current weather condition  
5. Weather details are displayed on both the **serial terminal (via UART)** and the **ST7735 LCD**.  
6. The LCD also shows **animated weather icons** based on keywords in the weather response.  

---

## Theory
- **OpenWeatherMap API**: An API key is generated to authenticate requests. The embedded system builds a URL query string based on user input and sends a request.  
- **UART**: Handles user input from the terminal and displays results.  
- **LCD (ST7735R)**: Displays formatted weather data and animations. Two concurrent drawing designs simulate movement by redrawing or covering frames with delays.  
- **Sockets & Networking**: API requests are sent through the CC3100 Wi-Fi module, which encapsulates IP addresses, transport protocol, and port numbers.  

---

## Software Design
Key functions and libraries:  
- **CC3100ModBoost** – Wi-Fi connectivity and API requests  
- **ST7735 Functions** – Display weather information and animations  
  - `ST7735_DrawString(x, y, "String", Color)` – Prints strings at LCD coordinates  
  - `ST7735_DrawCircle(x, y, radius, Color)` – Used for drawing animation frames  
- **UART** – Serial terminal interface for user queries  

---

## Hardware Design
**Components Used**:
- TM4C123GXL LaunchPad  
- CC3100ModBoost Wi-Fi module  
- ST7735R Color LCD  
- Wires & Breadboard for connections  

The CC3100ModBoost sits directly on top of the TM4C123 pins for alignment and communication.  

---

## Conclusion
This project demonstrated how embedded systems can interface with web APIs to deliver IoT functionality. I learned how to:  
- Work with API keys and HTTP requests  
- Parse JSON responses into usable data  
- Use UART for user interaction  
- Apply LCD drawing functions for animations  