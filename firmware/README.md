# Agro Rover Firmware

This directory contains the firmware used in the Agro Rover prototype.

## Programs

- `bluetooth_rover_control/` — Controls rover movement through an HC-05 Bluetooth module and L298N motor driver.
- `environment_monitoring/` — Reads temperature, humidity, and air-quality sensor values and sends them to the Arduino IoT Cloud.

## Hardware Platforms

- Arduino board — rover movement and Bluetooth control
- NodeMCU ESP8266 — environmental monitoring and cloud connectivity

> Sensitive Wi-Fi credentials and Arduino IoT Cloud secrets are not included in this repository.
