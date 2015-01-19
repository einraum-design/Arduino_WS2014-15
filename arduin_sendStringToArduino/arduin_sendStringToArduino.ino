void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
  
  while(Serial.available() <= 0){
    Serial.print('A');
    delay(300);
  }
  
  int inByte = Serial.read();
  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  
  int sensorVal = analogRead(0); // 0 - 1023
  
  int sendVal = sensorVal / 4; // 0 - 255
  
  if(Serial.available() > 0){
    int inByte = Serial.read();
    // write ist for sending bytes (value 0 - 255 or characters)
    Serial.write(sendVal);
    Serial.write(sendVal + 10);
    Serial.write(sendVal + 20);
    
  }
  
}
