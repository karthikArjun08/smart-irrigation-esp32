// MQ2 basic LPG alarm using analog output
const int mqPin = A0;       // MQ-2 analog output
const int ledPin = 13;      // LED pin
const int buzzerPin = 12;   // Buzzer pin
const int readInterval = 500; // ms between reads

// Start with a sensible default threshold; adjust after checking Serial Monitor
int alarmThreshold = 350;   // 0-1023, higher = more gas (tweak this)

unsigned long lastRead = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  Serial.println("MQ-2 LPG Alarm - serial monitor to calibrate threshold");
}

void loop() {
  if (millis() - lastRead < readInterval) return;
  lastRead = millis();

  int raw = analogRead(mqPin); // 0 - 1023
  Serial.print("MQ2 analog: ");
  Serial.println(raw);

  if (raw >= alarmThreshold) {
    // alarm state
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000); // uses tone for audible alert (works for active or passive buzzer)
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
