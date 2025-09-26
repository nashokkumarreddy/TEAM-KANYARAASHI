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
- **ZMPT101B Voltage Sensors** (to measure phase voltages)  
- **Relay Module** (to disconnect load during neutral fault)  
- **Buzzer** (for audible alerts)  
- **SIM800L GSM Module** (for IoT/remote user alerts)  
- **12V Power Supply** (for relay & modules)  
- Breadboard, jumper wires, and connectors  

---

## 🔌 Circuit Diagram
Below is the implemented circuit:  

![Circuit Diagram](Circuit%20Diagram.jpg)
## 🖥️ Arduino Code

```cpp
// ---------------------------
// Pin Configuration
// ---------------------------
#define VOLTAGE_SENSOR_L1 A0
#define VOLTAGE_SENSOR_L2 A1
#define VOLTAGE_SENSOR_L3 A2
#define VOLTAGE_SENSOR_N  A3

#define CURRENT_SENSOR_L1 A4
#define CURRENT_SENSOR_L2 A5
#define CURRENT_SENSOR_L3 A6
#define CURRENT_SENSOR_N  A7

#define RELAY_PIN   8
#define BUZZER_PIN  9

// ---------------------------
// Calibration Factors (Change according to your sensors)
// ---------------------------
// Example for ZMPT101B voltage sensor
float voltage_factor = 0.1;  // Volts per ADC step (to be tuned)

// Example for ACS712 current sensor (30A version → 66mV/A)
// With 5V ADC → 1023 steps → ~4.9mV/step
float current_factor = 0.066 / 0.0049;   // ~13.5 A per ADC step
float current_offset = 512;              // Midpoint of ADC (no current)

// ---------------------------
// Setup
// ---------------------------
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay ON initially
  digitalWrite(BUZZER_PIN, LOW); // Buzzer OFF initially
}

// ---------------------------
// Read Voltage
// ---------------------------
float readVoltage(int pin) {
  int adc = analogRead(pin);
  return adc * voltage_factor;
}

// ---------------------------
// Read Current
// ---------------------------
float readCurrent(int pin) {
  int adc = analogRead(pin);
  float current = (adc - current_offset) * current_factor;
  return current;
}

// ---------------------------
// Loop
// ---------------------------
void loop() {
  float vL1 = readVoltage(VOLTAGE_SENSOR_L1);
  float vL2 = readVoltage(VOLTAGE_SENSOR_L2);
  float vL3 = readVoltage(VOLTAGE_SENSOR_L3);
  float vN  = readVoltage(VOLTAGE_SENSOR_N);

  float cL1 = readCurrent(CURRENT_SENSOR_L1);
  float cL2 = readCurrent(CURRENT_SENSOR_L2);
  float cL3 = readCurrent(CURRENT_SENSOR_L3);
  float cN  = readCurrent(CURRENT_SENSOR_N);

  // Print values for debugging
  Serial.print("Voltages: ");
  Serial.print(vL1); Serial.print("V, ");
  Serial.print(vL2); Serial.print("V, ");
  Serial.print(vL3); Serial.print("V, ");
  Serial.print("Neutral: "); Serial.print(vN); Serial.println("V");

  Serial.print("Currents: ");
  Serial.print(cL1); Serial.print("A, ");
  Serial.print(cL2); Serial.print("A, ");
  Serial.print(cL3); Serial.print("A, ");
  Serial.print("Neutral: "); Serial.print(cN); Serial.println("A");

  // Neutral breakage detection logic (simple imbalance check)
  if (abs((vL1 - vN)) > 50 || abs((vL2 - vN)) > 50 || abs((vL3 - vN)) > 50) {
    Serial.println("⚠️ Neutral Breakage Detected!");
    digitalWrite(RELAY_PIN, LOW);   // Cut off load
    digitalWrite(BUZZER_PIN, HIGH); // Turn buzzer ON
  } else {
    digitalWrite(RELAY_PIN, HIGH);  // Load connected
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
  }

  delay(1000); // 1 second delay
}


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

