# ⚡ Real-time Neutral Conductor Breakage Detection
**Smart India Hackathon 2025 – Team KANYARAASHI**

# Real-Time Neutral Conductor Breakage Detection

## 📌 Project Overview
This project is designed to **detect neutral conductor breakage in low-voltage distribution networks** in real-time.  
The system continuously monitors phase-to-neutral voltages and current, detects abnormal imbalance conditions, and immediately takes protective actions such as **alerting the user** or **disconnecting the supply** via a relay.

This solution is a **low-cost, scalable, and real-time protective system** aimed at enhancing safety in households, industries, and distribution networks.

---

## ⚡ Problem Statement
In low-voltage power distribution:
- The **neutral conductor** is critical for maintaining balanced voltages.
- A **neutral break** can cause:
  - Unbalanced voltages  
  - Equipment damage  
  - Fire hazards  
  - Serious safety risks  

Current protective devices (MCBs, RCCBs, fuses) **do not detect neutral breakage in real-time**, hence the need for this system.

---

## 🎯 Objectives
- Continuous monitoring of voltages across all three phases with respect to neutral.
- Detect unbalanced conditions that indicate a neutral conductor break.
- Take immediate action:
  - Trigger buzzer alerts.  
  - Disconnect supply via relay.  
  - Optionally send IoT-based alerts (using GSM/Internet).

---

## 🛠️ Hardware Components
- **Arduino Uno** (microcontroller for processing & control)  
- **ACS712 Current Sensors** (to measure phase currents)  
- **5SMU1B Voltage Sensor** (to measure phase voltages)  
- **Relay Module** (to disconnect load during neutral fault)  
- **Buzzer** (for audible alerts)  
- **SIM800L GSM Module** (for IoT/remote user alerts)  
- **12V Power Supply** (for relay & modules)  
- Breadboard, jumper wires, and connectors  

---

## 🔌 Circuit Diagram
Below is the implemented circuit:  

![Circuit Diagram](Circuit%20Diagram.jpg)

- **Voltage & current sensors** feed real-time data to Arduino.  
- **Relay & buzzer** are controlled by Arduino based on fault detection.  
- **SIM800L** provides communication for alerts.  

---

## 💻 Software & Tools
- **Arduino IDE** (for microcontroller programming in Embedded C++)  
- **SQLite** (local storage of voltage/current logs)  
- **MongoDB** (cloud storage for IoT-based monitoring)  
- **MATLAB/Simulink** (optional for simulation and testing)  
- **Security**: AES encryption & HTTPS for IoT communication  

---

## ⚙️ Working Principle
1. Measure **phase-to-neutral voltages** and **currents** in real-time.  
2. Compare readings with expected balanced conditions.  
3. If imbalance detected → conclude neutral breakage.  
4. Immediate system response:  
   - 🔔 Sound buzzer (local alert)  
   - ⚡ Cut-off supply using relay  
   - 📲 Send alert via GSM/IoT  

---

## 🚀 Features
- **Real-Time Safety** → Detects neutral failures instantly.  
- **Low-Cost** → Uses easily available sensors and Arduino.  
- **Automatic Protection** → Prevents costly equipment damage.  
- **IoT Ready** → Remote monitoring and alerts.  
- **Easy Integration** → Can be added to existing power systems.  

---

## 📊 Feasibility & Challenges
### ✔️ Feasibility:
- Technically feasible using Arduino & IoT tools.  
- Low-cost and scalable for homes and industries.  
- Easy installation without major system modifications.  

### ⚠️ Challenges:
- Differentiating **normal voltage fluctuation vs. neutral breakage**.  
- Sensor calibration for accuracy.  
- Ensuring **real-time response** under load.  
- Stable internet/power for IoT functionality.  

---

## 🌍 Impact & Benefits
- **Enhanced Safety** → Prevents accidents & fire hazards.  
- **Automatic Appliance Protection** → Prevents voltage imbalance damage.  
- **User Awareness** → Provides instant alerts.  
- **Scalable** → Can be used in households, industries, and smart grid applications.  

---

## 📚 References
- IEEE Xplore: *Detection and Mitigation of Neutral Conductor Failures in Low-Voltage Networks*  
- International Journal of Electrical Power & Energy Systems, 2021  
- Indian Standards: IS 732, IS 3043  
- Arduino IDE, MATLAB, MongoDB Documentation  
- National Smart Grid Mission (Govt. of India)  


