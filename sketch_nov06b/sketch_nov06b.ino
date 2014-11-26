#include <Servo.h>

#define potiPin 0
#define ledPin 2
#define ledFadePin 3

// Servomotor Objekt erstellen
Servo myServo;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  
  // Servo an pin 9 definieren
  myServo.attach(9);
  
  Serial.begin(4800);
}

void loop() {
  
  // servo auf 90 grad stellen
  myServo.write(90);
  
  //analogRead -> int 0 - 1023
  float potiVal = analogRead(potiPin); 
  
  Serial.print("potiVal = ");
  Serial.println(potiVal);
  
  // blink - speed -> potiValue
  delay(potiVal); // frameRate 60 fps
  digitalWrite(ledPin, HIGH);
  
  delay(potiVal);
  digitalWrite(ledPin, LOW);
  
  // map wertebereich potival: von 0 - 1023 auf 0 - 255
  float fadeVal = map(potiVal, 0, 1023, 0, 255);
  analogWrite(ledFadePin, fadeVal);
  
}
