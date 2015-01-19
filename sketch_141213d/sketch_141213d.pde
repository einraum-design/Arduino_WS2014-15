import processing.serial.*;

Serial myPort;

boolean firstContact = false;

int[] inputValue = new int[3];
int inputCounter = 0;


void setup() {

  myPort = new Serial(this, Serial.list()[5], 4800);
}

void draw() {
  background(255);

  if (firstContact) {
    fill(0);
    text("Arduino Connected", 20, 20);
  } else {
    fill(0);
    text("Waiting for Arduino", 20, 20);
  }
}

void mousePressed() {
  // ask Arduino to send new value
  myPort.write('A');
}

void serialEvent(Serial myPort) {

  // at beginning of sktecht - establish contact
  if (firstContact == false) {

    // read just on byte (number 0-255 or 1 character)
    int inByte = myPort.read();

    if (inByte == 'A') { // if(inByter == 65)
      println("got start message from Arduino");

      firstContact = true;

      myPort.clear();

      // send startmessage to arduino
      myPort.write('A');
      println("send startmessage to arduino");
    }
  } else {


    // we always want to get 3 value from arduino
    inputValue[inputCounter] = myPort.read();

    inputCounter ++;

    if (inputCounter > 2) {

      println(inputValue);
      inputCounter = 0;
    }
  }
}
