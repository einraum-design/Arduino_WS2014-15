//int ledPin = 2;
#define ledPin 2
#define fadeLedPin 3

int brightness = 0;
int delayVal = 5;
boolean countUp = true;

void setup() {

  Serial.begin(4800);
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(brightness);
  if (countUp) {
    brightness += 10;

  } else {
    brightness -= 10;
  }

  //  werte auf bereich 0 - 255 begrenzen
  brightness = constrain(brightness, 0, 255);

  if (brightness > 250  || brightness <  1) {
    countUp = !countUp;
  }

  // delay umschalten
  if (countUp) {
    delayVal = 5;
  } else {
    delayVal = 50;
  }

  analogWrite(fadeLedPin, brightness);

  // blink an
  digitalWrite(ledPin, HIGH);
  delay(delayVal);

  // blink aus
  digitalWrite(ledPin, LOW);
  delay(delayVal);

}
