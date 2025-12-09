# ESP32 Smart Irrigation System 🌱💧

This project uses an **ESP32**, soil moisture sensor, and relay to control a water pump.  
A built-in **Web Dashboard** displays real-time soil moisture and allows pump control.

## 🚀 Features
- Real-time soil moisture monitoring (0–100%)
- WiFi-enabled Web Dashboard
- Pump ON/OFF control
- Responsive UI (HTML/CSS/JS)
- ESP32 WebServer backend

## 📡 Web Dashboard

## Components

1 × ESP32 Dev Board (DevKitC style)

1 × Resistive soil moisture sensor (LM393 module) — using A0 analog out

1 × Relay module (1-channel) — typical 5V relay module with IN, VCC, GND

1 × Water pump (external power: 5V or 12V depending on your pump)

1 × External power supply for pump (5V or 12V) with adequate current

Jumper wires, breadboard, common ground

## Pin mapping 

Soil Sensor

VCC → ESP32 3.3V

GND → ESP32 GND

A0 → ESP32 GPIO34 (ADC)

D0 → unused (digital threshold output)

Relay Module

IN → ESP32 GPIO5 (if you connected to D5)
(If your relay is LOW-active, you may invert logic in code.)

VCC → 5V (from USB 5V supply)
(Some relay modules accept 3.3V but most need 5V; check your relay board.)

GND → ESP32 GND

Pump wiring (use relay contacts)

External Power + → Pump +

External Power - → Relay NO (Normally Open)

Relay COM → Pump -
