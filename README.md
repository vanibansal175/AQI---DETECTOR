# Air Quality Monitoring System (AQI Detector)

This is a simple air quality monitoring system built using an ESP32.

The system continuously checks the air around it and displays how clean or polluted it is.  
It reads data from multiple sensors and gives real-time feedback using a display and alerts.

---

## How it works

The working of the system is straightforward but very useful.

The MQ135 sensor detects harmful gases in the air.  
The BME280 sensor measures temperature, humidity, and pressure.  
The PMS sensor detects fine dust particles like PM2.5 and PM10.

The ESP32 reads all this data continuously and processes it.  
Based on the readings, it calculates the air quality level (AQI).

The results are shown on the OLED display.  
If the air quality becomes poor, the system can trigger a buzzer or LED as an alert.

All of this runs continuously, so the system keeps monitoring the air in real time.

---

## Components used

- ESP32  
- MQ135 Air Quality Sensor  
- BME280 (temperature, humidity, pressure)  
- PMS5003 / PMS7003 (dust sensor)  
- OLED Display (0.96", I2C)  
- Buzzer  
- LED  
- Resistor  
- Power supply (battery or USB)  

---

## Features

- Real-time air quality monitoring  
- Detection of gases and dust particles  
- Temperature and humidity tracking  
- OLED display output  
- Alert system using LED and buzzer  
- Continuous data processing  

---

## Why I made it

I chose this project because air pollution is a real-world problem that affects everyone.

I wanted to build something practical that can actually be used to monitor the environment around us.  
This project also helped me understand how multiple sensors can work together in one system.

Since I hadn’t built an AQI monitoring system before, it gave me a chance to explore new sensors and improve my skills in electronics and programming.

Through this project, I learned more about sensor integration, data processing, and system design.

---

## Photos

![CAD Design](image)

This image shows the CAD design I created to visualize how the final device will look.  
It helped me estimate the size of the enclosure and plan the placement of all components.

---

![Circuit Diagram](image)

I created this circuit diagram to understand how all the components will connect and work together.  
It also helps in organizing the design before building the actual hardware.

---

![Code Structure](image)

I wrote the code in a structured way to simulate how the system will function.  
This makes it easier to debug and ensures smooth interaction between all components.

---

## Components List

| Component | Quantity | Min Price (INR) | Purchase Link |
|----------|---------|----------------|--------------|
| ESP32 Dev Board | 1 | 300 | Buy |
| MQ135 Sensor | 1 | 150 | Buy |
| BME280 Sensor | 1 | 250 | Buy |
| PMS5003 Sensor | 1 | 1200 | Buy |
| OLED Display (0.96") | 1 | 150 | Buy |
| Buzzer | 1 | 50 | Buy |
| LED | 1 | 10 | Buy |
| Resistor (220Ω) | 1 | 5 | Buy |
| Jumper Wires | As needed | 80 | Buy |
| Breadboard/PCB | 1 | 100 | Buy |
| Power Supply | 1 | 150 | Buy |

**Estimated Total Cost: ~₹2,445**
