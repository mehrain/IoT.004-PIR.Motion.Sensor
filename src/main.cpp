#include <Arduino.h>

const int pirPin = 4; // GPIO4 for PIR sensor output
const int ledPinGreen = 23; // GPIO22 for LED output
const int ledPinRed = 22; // GPIO23 for LED output  

void setup() {
    Serial.begin(115200);
    pinMode(pirPin, INPUT);
    pinMode(ledPinGreen, OUTPUT);
    pinMode(ledPinRed, OUTPUT);
    Serial.println("PIR Sensor Test");
}
  
void loop() {
    int pirState = digitalRead(pirPin);
    if (pirState == HIGH) {
        Serial.println("Motion detected!");
        digitalWrite(ledPinGreen, LOW);
        digitalWrite(ledPinRed, HIGH);
        delay(8000); // Delay for 5 seconds
    } else {
        Serial.println("No motion.");
        digitalWrite(ledPinGreen, HIGH);
        digitalWrite(ledPinRed, LOW);

    }
    delay(500); // Check every ten second
}