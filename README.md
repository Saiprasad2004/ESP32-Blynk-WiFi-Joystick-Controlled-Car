# ESP32-Blynk-WiFi-Joystick-Controlled-Car
A Wi-Fi controlled robot car built using ESP32, L298N motor driver, and the Blynk IoT platform. The car can be controlled remotely using a smartphone joystick with adjustable speed control.

## Overview

This project presents a Wi-Fi controlled robot car built using the ESP32 microcontroller, L298N motor driver, and the Blynk IoT platform. The robot can be remotely controlled using a smartphone through a virtual joystick interface provided by the Blynk application.

The system enables real-time wireless control over Wi-Fi, allowing the robot to move in forward, backward, left, and right directions. The project also incorporates PWM-based speed control for smooth operation.

---

## Features

* Wi-Fi based remote control using ESP32.
* Smartphone control using the Blynk IoT platform.
* Real-time joystick-based navigation.
* Adjustable motor speed using a slider widget.
* Forward, backward, left, and right movement.
* PWM speed control using ESP32.

---

## Hardware Components

* ESP32 Development Board
* L298N Motor Driver Module
* 4 DC Geared Motors
* Robot Chassis
* 2S 18650 Battery Pack
* Wheels
* Jumper Wires
* Smartphone with Blynk App

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* Blynk IoT Platform
* Blynk Library for Arduino

---

## Hardware Connections

| ESP32 Pin | L298N Pin |
| --------- | --------- |
| GPIO 25   | IN1       |
| GPIO 26   | IN2       |
| GPIO 27   | IN3       |
| GPIO 14   | IN4       |
| GPIO 33   | ENA       |
| GPIO 32   | ENB       |
| GND       | GND       |

### Motor Connections

* Left Front and Left Rear Motors → OUT1 & OUT2
* Right Front and Right Rear Motors → OUT3 & OUT4

---

## Blynk Dashboard Configuration

### Datastreams

| Datastream | Function             |
| ---------- | -------------------- |
| V2         | Joystick X-axis      |
| V3         | Joystick Y-axis      |
| V4         | Speed Control Slider |

### Widget Configuration

* Joystick Widget

  * X-axis → V2
  * Y-axis → V3
* Slider Widget

  * Datastream → V4
  * Range → 0 to 255

---

## Working Principle

1. The smartphone sends control commands through the Blynk application.
2. Commands are transmitted over Wi-Fi to the ESP32.
3. ESP32 processes joystick values and determines the required movement.
4. The ESP32 controls the L298N motor driver accordingly.
5. PWM signals regulate motor speed.

---

## Project Workflow

Smartphone (Blynk App) → Wi-Fi → ESP32 → L298N Motor Driver → DC Motors

---

## Future Enhancements

* Obstacle avoidance mode.
* Line following mode.
* Live video streaming using ESP32-CAM.
* Voice control integration.
* Autonomous navigation.

---

## Demonstration

Add project images, circuit diagrams, and demonstration videos here.

---

## Author

**Pasupula Sai Prasad**

B.Tech Electronics and Communication Engineering (ECE)
