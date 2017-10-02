/*
Send an n to turn on, a f to turn off
*/



#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int inbyte = 0;   // for incoming serial data


void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);

  // Optional set pulse length.
   mySwitch.setPulseLength(242);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}

void loop() {

  /* Same switch as above, but using binary code */
  if (Serial.available() > 0) {
    inbyte = Serial.read();
    switch (inbyte) {
      case 102:
        mySwitch.send("000011110000000000000000");
      case 110:
        mySwitch.send("000011110000000011000000");
    }
  }

}
