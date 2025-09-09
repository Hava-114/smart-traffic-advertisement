🚦 Smart Traffic Signal Advertisement & Billboard Compliance System
📌 Project Overview

This project is a low-cost Arduino-based system that integrates with traffic signals to display advertisements on an LCD screen only during the red light. The goal is to ensure ads are shown safely without distracting drivers while moving, and to help authorities identify unauthorized or hazardous billboards near intersections.

🎯 Problem Statement

Billboards and hoardings often create safety and compliance issues:

Incorrect dimensions or poor placement at intersections.

Blocking traffic lights or road signs.

Structural hazards due to poor installation.

Non-compliance with government regulations.

Displaying obscene, misleading, or political misinformation.

💡 Proposed Solution

A Sender Arduino connects to traffic lights and signals the Receiver Arduino via a digital pin.

The Receiver controls an LCD screen:

🔴 Red Light → LCD displays rotating advertisements (discounts, sales, events).

🟡/🟢 Yellow/Green Light → LCD backlight turns on, but no ads are shown.

Future extension: Add sensors (LDR, ultrasonic, camera) to detect hazardous or unauthorized billboards and report them.

Possible integration with a mobile app/dashboard for government officers to view violations remotely.

🛠️ Hardware Requirements

Arduino UNO / Nano

LCD Display (I2C or Adafruit LiquidCrystal)

Traffic Light Simulation (LEDs or second Arduino as sender)

Jumper wires, resistors

(Optional) LDR, Ultrasonic Sensor, ESP8266/LoRa for advanced version

🖼️ System Workflow

Sender Arduino sets a pin HIGH during red light, LOW otherwise.

Receiver Arduino reads the pin:

If HIGH → rotates advertisements on LCD.

If LOW → shows “GO / YELLOW – No Ads”.

(Future) Detects unauthorized billboards via sensors.

(Future) Sends violation data to a cloud dashboard or mobile app.
