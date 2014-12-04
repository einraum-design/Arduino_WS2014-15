import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

void setup() {
  size(800, 600);
  frameRate(60);

  println(Arduino.list());

  arduino = new Arduino(this, Arduino.list()[2], 57600);
  //arduino = new Arduino(this, "/dev/tty.usbmodem641", 57600);
  
  arduino.pinMode(13, arduino.OUTPUT);
}

void draw() {
  
  int motorSpeed = (int)map(mouseX, 0, width, 0, 255);
  arduino.analogWrite(5, motorSpeed);
  
  
  float sensorValue = arduino.analogRead(0);
  
  float colorValue = map(sensorValue, 190, 90, 0, 255);
  
  background(colorValue, 255, 255);
  
  fill(0);
  text(arduino.analogRead(0), 30, 30);
  
  
}

void mousePressed() {
  arduino.digitalWrite(13, arduino.HIGH);
}

void mouseReleased() {
  arduino.digitalWrite(13, arduino.LOW);
}

void mouseMoved() {
}

void keyPressed() {
}

void keyReleased() {
}
