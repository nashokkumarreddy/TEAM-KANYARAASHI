// --------------------
// Pin definitions
// --------------------
#define ACS712_PHASE1 A0
#define ACS712_PHASE2 A1
#define ACS712_PHASE3 A2
#define RELAY_PIN 8
#define BUZZER_PIN 9

// --------------------
// Sensor Calibration
// --------------------
float sensitivity = 0.185;   // ACS712 5A version (change for 20A: 0.1, 30A: 0.066)
float threshold_current = 0.5;   // Minimum load to be considered active (Amps)
float neutral_difference = 1.0;  // Current imbalance limit (Amps)

// --------------------
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);   // Relay OFF
  digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
}

// --------------------
// Function: Read current from ACS712
// --------------------
float readCurrent(int pin) {
  int adc = analogRead(pin);
  float voltage = adc * (5.0 / 1023.0);   // Convert ADC → voltage
  float current = (voltage - 2.5) / sensitivity; // Convert voltage → current
  return current;
}

// --------------------
// Main Loop
// --------------------
void loop() {
  float current1 = abs(readCurrent(ACS712_PHASE1));
  float current2 = abs(readCurrent(ACS712_PHASE2));
  float current3 = abs(readCurrent(ACS712_PHASE3));

  // Neutral current should be ideally zero in a balanced system
  float neutral_current = abs(current1 + current2 + current3);

  Serial.print("I1 = "); Serial.print(current1);
  Serial.print(" A, I2 = "); Serial.print(current2);
  Serial.print(" A, I3 = "); Serial.print(current3);
  Serial.print(" A, Neutral = "); Serial.println(neutral_current);

  // Fault condition: Neutral imbalance OR very low current on any phase
  if (neutral_current > neutral_difference ||
      current1 < threshold_current ||
      current2 < threshold_current ||
      current3 < threshold_current) {
    digitalWrite(RELAY_PIN, HIGH);   // Relay ON → Cut supply
    digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON
    Serial.println("⚠ Neutral break / fault detected! Relay ON, Buzzer ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Relay OFF → Normal supply
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
    Serial.println("✅ Normal operation. Relay OFF, Buzzer OFF");
  }

  delay(500);
}