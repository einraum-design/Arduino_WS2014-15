#define buttonPin 2


void setup() {
  Serial.begin(4800);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  // put your setup code here, to run once:

}

void loop() {
  
  boolean buttonState = doubleCheck(buttonPin);
  
  if(buttonState == true){
    Serial.println("button Releasd");
  } else{
    Serial.println("button Pressed");
  }
  
  // put your main code here, to run repeatedly:

}

boolean doubleCheck(int buttonPin){
  boolean buttonState = digitalRead(buttonPin);
  delay(5);
  boolean buttonStateProof = digitalRead(buttonPin);
  
  if(buttonState == HIGH && buttonState == buttonStateProof){
    return true;
  }
  return false;
}
