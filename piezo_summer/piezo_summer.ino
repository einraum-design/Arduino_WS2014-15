#define speakerPin 11
#define sensorPinPressure 0
#define potiPin 1

void setup() {

  Serial.begin(4800);
  pinMode(speakerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int tone = analogRead(sensorPinPressure);
  int frequenz = (int)map(tone, 0, 1023, 550, 8000);
  
  int pulse = analogRead(potiPin);
  int pulseVal = (int) map(pulse, 0, 1023, 10, 200);

  Serial.println(frequenz);
  playTone(frequenz, pulseVal);

}


void playTone(int tone, int pulse) {


  for (int i = 0; i < pulse; i++) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
  
  delay(pulse);
}
