# Agro Rover

An IoT-enabled agricultural rover prototype designed for remote field movement, environmental monitoring, and smart-farming demonstrations.

![Agro Rover Prototype](agro-rover-prototype.jpeg)

## Overview

Agro Rover combines a mobile robotic platform with environmental sensors and cloud connectivity. The prototype was developed to explore how affordable electronics can assist with agricultural monitoring and reduce repeated manual field inspection.

The rover can be controlled wirelessly through Bluetooth, while its ESP8266-based monitoring unit collects temperature, humidity, and relative air-quality sensor readings for display through Arduino IoT Cloud.

> Agro Rover is an educational prototype. Its air-quality output is a relative sensor reading and should not be treated as a calibrated or certified AQI measurement.

## Key Features

- Bluetooth-based rover movement control
- Forward, backward, turning, diagonal movement, and speed control
- Temperature and humidity monitoring using a DHT11 sensor
- Relative air-quality monitoring using an MQ-series gas sensor
- Arduino IoT Cloud dashboard integration
- Modular Arduino and ESP8266 firmware
- Soil-condition monitoring concept
- Automated-irrigation demonstration

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
| Soil-moisture sensor | Soil-condition monitoring |
| Water pump | Irrigation demonstration |
| Battery supply | Portable power |
| Rover chassis and wheels | Mechanical platform |

## System Structure

The project uses two controllers:

1. **Arduino rover controller**  
   Receives commands through the HC-05 Bluetooth module and controls the motors using an L298N motor driver.

2. **ESP8266 monitoring controller**  
   Reads environmental sensor data and updates the Arduino IoT Cloud dashboard over Wi-Fi.

## Firmware Structure

```text
firmware/
├── bluetooth_rover_control/
│   └── bluetooth_rover_control.ino
├── environment_monitoring/
│   ├── environment_monitoring.ino
│   ├── thingProperties.h
│   └── arduino_secrets.example.h
└── README.md
```

### Bluetooth Rover Controller

The movement firmware supports the following commands:

| Command | Action |
|---|---|
| `F` | Move forward |
| `B` | Move backward |
| `L` | Turn left |
| `R` | Turn right |
| `G` | Move forward-left |
| `I` | Move forward-right |
| `H` | Move backward-left |
| `J` | Move backward-right |
| `S` | Stop |
| `0–9`, `q` | Adjust speed |

### Environmental Monitoring

The ESP8266 monitoring firmware reads:

- Temperature
- Relative humidity
- Raw gas-sensor value
- Relative air-quality percentage

These readings are sent to Arduino IoT Cloud and summarized through its dashboard.

## Arduino IoT Cloud Setup

1. Create a Thing in Arduino IoT Cloud.
2. Add variables named:
   - `message`
   - `airquality`
   - `humidity`
   - `temperature`
3. Use the data types declared in `thingProperties.h`.
4. Copy `arduino_secrets.example.h` and rename the copy to `arduino_secrets.h`.
5. Add your own Wi-Fi and Arduino Cloud credentials.
6. Replace `YOUR_DEVICE_LOGIN_NAME` in `thingProperties.h`.
7. Install the required Arduino libraries:
   - ArduinoIoTCloud
   - Arduino ConnectionHandler
   - DHT sensor library
8. Select the appropriate ESP8266 board and upload the firmware.

> Never commit your real `arduino_secrets.h` file.

## Project Gallery

### Team Demonstration

![Agro Rover Team Demonstration](team-demo-1.jpeg)

![Agro Rover Field Demonstration](team-demo-2.jpeg)

### Project Posters

![Technisium 2026 Poster](technisium-2026-poster.jpeg)

![Agro Rover Project Poster](agro-rover-project-poster.jpeg)

## Team

- Darshan L
- Gagan M
- Jayanth B S
- Purushotham K

Developed as a student agricultural-technology prototype and presented during Technisium 2026.

## Current Limitations

- The rover requires manual Bluetooth control.
- The DHT11 provides basic environmental readings with limited accuracy.
- The gas sensor has not been calibrated for certified AQI measurement.
- The prototype is not weather-resistant.
- Agricultural sensor readings require further field testing and validation.
- The system is intended for demonstration rather than unattended farm operation.

## Future Improvements

- GPS-based navigation
- Obstacle detection and autonomous movement
- Camera-based crop-health monitoring
- Calibrated environmental sensors
- Improved soil-moisture-based irrigation control
- Solar-assisted battery charging
- Weather-resistant mechanical enclosure
- Long-range LoRa communication
- Dedicated mobile or web dashboard

## Attribution and License

The original environmental-monitoring firmware and project documentation are provided under the repository’s MIT License.

The Bluetooth rover-control firmware is adapted from code published by Make DIY / CircuitBest and is not covered by the repository’s MIT License.

See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for its attribution and reuse restrictions.

## Disclaimer

Agro Rover is intended for learning, experimentation, and prototype demonstration. Its sensor readings must be properly calibrated and validated before being used for real agricultural decisions.
