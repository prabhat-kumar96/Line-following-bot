# Line-Following Robot with Obstacle Avoidance

This document provides detailed information about the circuit connections and the algorithm implemented for the line-following robot equipped with obstacle avoidance capabilities.

## Circuit Connections

### Components Required

- **Microcontroller:** Arduino Uno
- **Motor Driver:** L298N Motor Driver Module
- **Motors:** 2 DC Motors with Wheels
- **Sensors:**
  - **Line Detection:** 2 IR Sensors
  - **Obstacle Detection:** 1 Ultrasonic Sensor (HC-SR04)
- **Servo Motor:** 1 (for ultrasonic sensor rotation)
- **Power Supply:** Appropriate battery pack (e.g., 7.4V Li-ion batteries)
- **Chassis and Mounting Hardware**

### Wiring Details

#### 1. IR Sensors:

- **Left IR Sensor:**
  - **VCC:** Connect to 5V on Arduino
  - **GND:** Connect to GND on Arduino
  - **OUT:** Connect to digital pin 2 on Arduino

- **Right IR Sensor:**
  - **VCC:** Connect to 5V on Arduino
  - **GND:** Connect to GND on Arduino
  - **OUT:** Connect to digital pin 3 on Arduino

#### 2. Ultrasonic Sensor (HC-SR04):

- **VCC:** Connect to 5V on Arduino
- **GND:** Connect to GND on Arduino
- **TRIG:** Connect to digital pin 9 on Arduino
- **ECHO:** Connect to digital pin 10 on Arduino

## Algorithm Overview:

1. **Initialization:**
   - Set up all sensor and motor pins as inputs or outputs.
   - Initialize serial communication for debugging.
   - Center the servo motor to face forward.

2. **Line Following:**
   - Read values from the left and right IR sensors.
   - Determine the robot's position relative to the line:
     - Both Sensors on Line (LOW): Move forward.
     - Left Sensor Off Line (HIGH), Right Sensor on Line (LOW): Turn right.
     - Left Sensor on Line (LOW), Right Sensor Off Line (HIGH): Turn left.
     - Both Sensors Offline (HIGH): Stop or execute corrective action.

3. **Obstacle Detection and Avoidance:**
   - Use the ultrasonic sensor to measure distances.
   - If an obstacle is detected within 20 cm:
     - Stop the motors.
     - Reverse slightly.
     - Scan left and right for the best path.
     - Resume movement accordingly.

4. **Continuous Operation:**
   - The bot repeats the above steps to navigate autonomously.
