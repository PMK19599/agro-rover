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

The demonstrated prototype used three controllers, with each handling a separate subsystem:

1. **Arduino Uno — Rover movement**  
   Receives commands from the HC-05 Bluetooth module and controls the motors through an L298N motor driver.

2. **Arduino Uno — Soil monitoring and irrigation**  
   Reads the soil-moisture sensor and controls the water-pump subsystem. The original firmware and exact pin assignments for this controller are no longer available.

3. **NodeMCU ESP8266 — Environmental monitoring**  
   Reads temperature, humidity, and relative air-quality data using the DHT11 and MQ-series sensors, then sends the readings to Arduino IoT Cloud over Wi-Fi.

This modular architecture simplified the initial prototype development. During the project evaluation, the judges recommended consolidating the subsystems onto a single capable microcontroller to reduce wiring, size, power requirements, and debugging complexity in a future version.

## Reference Wiring

> **Important:** This wiring was reconstructed from the preserved firmware and project records. The irrigation connections are proposed and may not exactly match the original lost circuit. Verify voltage, current, polarity, and module specifications before rebuilding.

### Rover Movement — Confirmed from Firmware

| Arduino Uno connection | Connected component |
|---|---|
| Pin `5` | L298N `IN1` |
| Pin `6` | L298N `IN2` |
| Pin `10` | L298N `IN3` |
| Pin `11` | L298N `IN4` |
| Pin `0 / RX` | HC-05 `TXD` |
| Pin `1 / TX` | HC-05 `RXD` through a suitable voltage divider |
| `5V` | HC-05 `VCC` |
| `GND` | HC-05 and L298N common ground |
| L298N `OUT1 / OUT2` | Left-side motor or motor pair |
| L298N `OUT3 / OUT4` | Right-side motor or motor pair |
| External motor supply | L298N motor-power input |

The motors must not be powered from the Arduino Uno’s `5V` pin. Disconnecting the HC-05 from pins `0` and `1` may be necessary while uploading firmware.

### Environmental Monitoring — Confirmed from Firmware

| NodeMCU ESP8266 connection | Connected component |
|---|---|
| `D2 / GPIO4` | DHT11 data |
| `3.3V` | DHT11 VCC |
| `GND` | DHT11 ground |
| `A0` | MQ-series sensor analogue output |
| `GND` | MQ-series sensor ground |
| USB or regulated input | NodeMCU power |

The MQ module’s analogue output must remain within the supported input range of the specific NodeMCU board. Use appropriate signal conditioning or a voltage divider when required.

### Soil Monitoring and Irrigation — Reconstructed Reference

| Arduino Uno connection | Connected component |
|---|---|
| `A0` | Soil-moisture sensor analogue output |
| `5V` | Soil-moisture sensor and relay-module VCC |
| `GND` | Soil-moisture sensor and relay-module ground |
| Pin `7` | Relay-module control input |
| Relay `COM` | External pump-supply positive |
| Relay `NO` | Pump positive |
| External supply negative | Pump negative |

Pin `7` is a proposed relay-control pin because the original irrigation firmware and wiring are unavailable. The pump must use a suitable external supply and must never be powered directly from an Arduino pin. Use a proper relay or driver module with the required protection.

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
