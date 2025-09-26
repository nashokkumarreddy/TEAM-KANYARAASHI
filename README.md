# ⚡ Real-time Neutral Conductor Breakage Detection
**Smart India Hackathon 2025 – Team KANYARAASHI**

## 🔹 Introduction
In low-voltage power distribution, the **neutral conductor** plays a vital role in balancing voltages.  
If the neutral breaks, it can cause:
- Unbalanced voltages  
- Damage to electrical equipment  
- Fire hazards and safety risks  

This project provides **real-time detection of neutral breakage** using Arduino, ACS712 sensors, and automatic relay disconnection.

---

## 🔹 Features
- ✅ Continuous monitoring of phase currents  
- ✅ Real-time fault detection  
- ✅ Relay-based disconnection to protect appliances  
- ✅ Audible buzzer alerts  
- ✅ Low-cost, scalable, IoT-ready solution  

---

## 🔹 Components Used
- Arduino UNO  
- ACS712 Current Sensors (3x)  
- LCD Display  
- Relay Module  
- Buzzer  
- Breadboard, wires, power supply  

---

## 🔹 Circuit Diagram
![Circuit Diagram](![Circuit Diagram](https://github.com/user-attachments/assets/6b58a4d8-0def-4e75-a846-940a4937667d)
)

---

## 🔹 Working Principle
- The ACS712 sensors measure current on each phase.  
- If the **neutral current imbalance** exceeds the threshold, the system detects a fault.  
- Relay disconnects supply, and the buzzer alerts the user.  
- Data can be extended to IoT dashboards for remote monitoring.  

---

## 🔹 Code
Code is available in the [Code/NeutralBreakage.ino](// ---------------------------
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
float current_offset = 512;              // Midpoint of ACS712 (no current)

// ---------------------------
// Thresholds (tune experimentally)
// ---------------------------
float NEUTRAL_CURRENT_THRESHOLD = 0.2;   // Amps
float VOLTAGE_DIFF_THRESHOLD    = 15.0;  // Volts imbalance

// ---------------------------
// Variables
// ---------------------------
float voltageL1, voltageL2, voltageL3, voltageN;
float currentL1, currentL2, currentL3, currentN;
float neutralCurrent;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

// ---------------------------
// Helper Functions
// ---------------------------

// Convert raw ADC to voltage (RMS needs extra calculation, simplified here)
float readVoltage(int pin) {
  int raw = analogRead(pin);
  return raw * voltage_factor;
}

// Convert raw ADC to current (centered around 512 for ACS712)
float readCurrent(int pin) {
  int raw = analogRead(pin);
  return (raw - current_offset) * current_factor;
}

void loop() {
  // Read and convert voltage sensors
  voltageL1 = readVoltage(VOLTAGE_SENSOR_L1);
  voltageL2 = readVoltage(VOLTAGE_SENSOR_L2);
  voltageL3 = readVoltage(VOLTAGE_SENSOR_L3);
  voltageN  = readVoltage(VOLTAGE_SENSOR_N);

  // Read and convert current sensors
  currentL1 = readCurrent(CURRENT_SENSOR_L1);
  currentL2 = readCurrent(CURRENT_SENSOR_L2);
  currentL3 = readCurrent(CURRENT_SENSOR_L3);
  currentN  = readCurrent(CURRENT_SENSOR_N);

  // Compute Neutral Current Imbalance
  neutralCurrent = abs((currentL1 + currentL2 + currentL3) - currentN);

  // ---------------------------
  // Fault Detection
  // ---------------------------
  bool neutralBreak = false;

  // Condition 1: Neutral current is too low (open neutral condition)
  if (neutralCurrent < NEUTRAL_CURRENT_THRESHOLD) {
    neutralBreak = true;
  }

  // Condition 2: Voltage imbalance (Zero-sequence voltage abnormal)
  float avgVoltage = (voltageL1 + voltageL2 + voltageL3) / 3.0;
  if (abs(voltageL1 - avgVoltage) > VOLTAGE_DIFF_THRESHOLD ||
      abs(voltageL2 - avgVoltage) > VOLTAGE_DIFF_THRESHOLD ||
      abs(voltageL3 - avgVoltage) > VOLTAGE_DIFF_THRESHOLD) {
    neutralBreak = true;
  }

  // ---------------------------
  // Trip Signal
  // ---------------------------
  if (neutralBreak) {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("⚠ NEUTRAL BREAKAGE DETECTED → TRIP!");
    // Optional: Send SMS via GSM module here
  } else {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("System Normal");
  }

  // Print Debug Info
  Serial.print("Neutral Current: ");
  Serial.print(neutralCurrent);
  Serial.print(" A | Voltages: ");
  Serial.print(voltageL1); Serial.print(" ");
  Serial.print(voltageL2); Serial.print(" ");
  Serial.print(voltageL3); Serial.print(" ");
  Serial.print(voltageN);
  Serial.println();

  delay(500);  // 0.5s delay
}) file.

---

## 🔹 Future Scope
- IoT integration with cloud (MongoDB, dashboards)  
- Predictive algorithms for better fault detection  
- Scalable for industrial applications  

---

## 📌 Team
**Team KANYARAASHI** – Smart India Hackathon 2025  
Problem ID: **SIH25063**  
Theme: **Disaster Management**  

