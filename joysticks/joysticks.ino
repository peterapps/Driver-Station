//#include "HID.h"  //uncomment for arduino due
//note that for the due the hid controller only works through the native port
#include "Joystick.h"

void setup() {
  //zero out the joystick state
  Joystick.clearState();
  //set pins as input (sparkfun joystick shield config)
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  //clear
  Joystick.clearState();
  //tweak the joystick state (see joystick.h for all possible fields)
  Joystick.state.x.axis = (analogRead(0) - 512) * 64;
  Joystick.state.y.axis = (analogRead(1) - 512) * 64;
  Joystick.state.y.axis = (analogRead(2) - 512) * 64;

  Joystick.state.buttons.b00 = !digitalRead(2);
  Joystick.state.buttons.b01 = !digitalRead(3);
  Joystick.state.hats.switch1 = HAT_LEFT;
  Joystick.state.hats.switch2 = HAT_UP;
  //call send state to pack and send the current state over usb
  Joystick.sendState();
  delay(50);
}
