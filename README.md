# Agro Rover

An IoT-enabled agricultural rover prototype designed for remote field movement, environmental monitoring, and smart-farming demonstrations.

![Agro Rover Prototype](agro-rover-prototype.jpeg)

## Overview

Agro Rover combines a mobile robotic platform with environmental sensors and cloud connectivity. The prototype was developed to explore how affordable electronics can assist with agricultural monitoring and reduce the need for repeated manual field inspection.

The rover can be controlled wirelessly through Bluetooth, while its ESP8266-based monitoring unit collects temperature, humidity, and relative air-quality sensor readings for display through Arduino IoT Cloud.

> This is an educational prototype. Its air-quality output is a relative sensor reading and should not be treated as a calibrated or certified AQI measurement.

## Key Features

- Bluetooth-based rover movement control
- Forward, reverse, turning, diagonal movement, and speed control
- Temperature and humidity monitoring using a DHT11 sensor
- Relative air-quality monitoring using an MQ-series gas sensor
- Arduino IoT Cloud dashboard integration
- Modular Arduino and ESP8266 firmware
- Agricultural monitoring and automated-irrigation concept demonstration

## Hardware Used

| Component | Purpose |
|---|---|
| Arduino-compatible board | Rover movement control |
| NodeMCU ESP8266 | Sensor processing and cloud connectivity |
| HC-05 Bluetooth module | Wireless manual control |
| L298N motor driver | DC motor control |
| DC geared motors | Rover movement |
| DHT11 sensor | Temperature and humidity monitoring |
| MQ-series gas sensor | Relative air-quality sensing |
| Soil-moisture sensor | Soil-condition monitoring concept |
| Water pump | Irrigation demonstration |
| Battery supply | Portable power |
| Rover chassis and wheels | Mechanical platform |

## System Structure

The project uses two controllers:

1. **Arduino rover controller**  
   Receives commands through the HC-05 Bluetooth module and controls the motors using an L298N motor driver.

2. **ESP8266 monitoring controller**  
   Reads environmental sensor data and updates the Arduino IoT Cloud dashboard over Wi-Fi.

## Firmware

```text
firmware/
├── bluetooth_rover_control/
│   └── bluetooth_rover_control.ino
├── environment_monitoring/
│   ├── environment_monitoring.ino
│   ├── thingProperties.h
│   └── arduino_secrets.example.h
└── README.md
