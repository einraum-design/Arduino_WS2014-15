#define ledPin 2
#define fadeLedPin 3

// brightness value of led
int brightness = 0;

// delay in void loop
int delayVal = 5;

// count brightness up or down?
boolean countUp = true;


void setup() {
  // start serial connection with baudRate of 4800
  Serial.begin(4800);
  
  // define ledPin as OUTPUT pin
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println(brightness);
  
  // alter brightness value every frame
  if (countUp) {
    brightness += 10;
  } else {
    brightness -= 10;
  }

  //  werte auf bereich 0 - 255 begrenzen
  brightness = constrain(brightness, 0, 255);

  // wenn ober oder untergrenze von brightness 
  // über-/unterschritten wird, countUp invertieren
  if (brightness > 250  || brightness <  1) {
    countUp = !countUp;
  }

  // delay ist unterschiedlich, je nachdem, ob die led ein- oder ausfaded
  if (countUp) {
    delayVal = 5;
  } else {
    delayVal = 50;
  }


  // analogen Helligkeits Wert auf den fadeLedPin schreiben -> Licht faded an und aus
  analogWrite(fadeLedPin, brightness);

  // digitalen Wert "An" oder "Aus" auf den ledPin schreiben
  // blink an
  digitalWrite(ledPin, HIGH);
  delay(delayVal);

  // blink aus
  digitalWrite(ledPin, LOW);
  delay(delayVal);

}
