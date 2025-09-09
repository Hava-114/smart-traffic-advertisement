🚦 Smart Traffic Signal Advertisement & Billboard Compliance System

📌 Project Overview:
    This project is a low-cost Arduino-based system that integrates with traffic signals to display advertisements on an LCD screen only during the red light. The goal is to ensure ads are shown safely without distracting drivers while moving, and to help authorities identify unauthorized or hazardous billboards near intersections.

🎯 Problem Statement:
  1. Billboards and hoardings often create safety and compliance issues.
  2. Incorrect dimensions or poor placement at intersections.
  3. Blocking traffic lights or road signs.
  4. Structural hazards due to poor installation.
  5. Non-compliance with government regulations.
  6. Displaying obscene, misleading, or political misinformation.

💡 Proposed Solution:
  1. A Sender Arduino connects to traffic lights and signals the Receiver Arduino via a digital pin.
  2. The Receiver controls an LCD screen:
  3. 🔴 Red Light → LCD displays rotating advertisements (discounts, sales, events).
  4. 🟡/🟢 Yellow/Green Light → LCD backlight turns on, but no ads are shown.
  5. Future extension: Add sensors (LDR, ultrasonic, camera) to detect hazardous or unauthorized billboards and report them.
  6. Possible integration with a mobile app/dashboard for government officers to view violations remotely.

🛠️ Hardware Requirements:
  1. Arduino UNO / Nano
  2. LCD Display (I2C or Adafruit LiquidCrystal)
  3. Traffic Light Simulation (LEDs or second Arduino as sender)
  4. Jumper wires, resistors
  5. (Optional) LDR, Ultrasonic Sensor, ESP8266/LoRa for advanced version

🖼️ System Workflow:
  1. Sender Arduino sets a pin HIGH during red light, LOW otherwise.
  2. Receiver Arduino reads the pin:
  3. If HIGH → rotates advertisements on LCD.
  4. If LOW → shows “GO / YELLOW – No Ads”.
  5. (Future) Detects unauthorized billboards via sensors.

(Future) Sends violation data to a cloud dashboard or mobile app.
