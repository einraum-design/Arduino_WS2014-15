#define fadeLedPin 3


float brightness = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
}

void loop() {
  
  brightness ++;
  
  
  brightness = constraint(brightness, 0, 255);
  analogWrite(fadeLedPin, brightness);
  
  
  delay(10);
}
