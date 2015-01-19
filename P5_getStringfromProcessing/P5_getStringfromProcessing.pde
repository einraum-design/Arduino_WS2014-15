import processing.serial.*;

Serial myPort;

void setup() {

  println(Serial.list());
  myPort = new Serial(this, Serial.list()[5], 4800);
}

void draw() {
  if (myPort.available() > 0) {
    String message = myPort.readStringUntil(10);
    if (message != null) {
      println(message);

      // trims whitespace tabs, linefeed ...
      message.trim();

      String[] parts = split(message, '=');
      println(parts);
      if (parts.length == 2) {
        String val = parts[1];
        println(val);
        val.trim();
        val = val.substring(0, val.length()-3);
        println(val);
        int intValue = int(val);
        println(intValue);
      }
    }    
    /*int val = myPort.read();
     println(val);*/
  }
}
