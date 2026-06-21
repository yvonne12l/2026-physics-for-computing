// Pin definitions
const int sensorPin = A0;   // Soil moisture sensor analog output
const int ledPin = 12;       // LED connected to digital pin 8
const int buzzerPin = 6;    // Buzzer connected to digital pin 9

// Threshold for dryness (adjust if needed)
int threshold = 100;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(sensorValue);

  // If the soil is dry
  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);   // Turn on LED
    tone(buzzerPin, 1000);        // Activate buzzer
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED
    noTone(buzzerPin);            // Turn off buzzer
  }

  delay(1000); // Read every second
}
