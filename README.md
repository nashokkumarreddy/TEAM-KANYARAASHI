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
Code is available in the [Code/NeutralBreakage.ino](![Circuit Diagram](https://github.com/user-attachments/assets/d7b5c535-62d4-4c41-a928-63e6a7e20bd6)
) file.

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

