#include "Gamepad.h"

Gamepad gamepad; // create gamepad object


int ledsPins[4] = {3, 5, 6, 9}; // declare leds pins: bottom, right, left, top

void setup() {
  gamepad.begin(); // start gamepad

  for (int pin : ledsPins) { // go through all led pins
    pinMode(pin, OUTPUT);    // set led pins as outputs
  }
}

void loop() {
  gamepad.fetchFromSerial(); // refresh gamepad to get new data

  int leftJoystickX = gamepad.readAxis(AXIS_LEFT_X) << 1; // get joystick value and map it to -255 to 255

  if (leftJoystickX < 0) {                         // if joystick towards the left
    analogWrite(ledsPins[2], abs(leftJoystickX));  // write left led with absolute value of joystick
    digitalWrite(ledsPins[1], 0);                  // turn off right led
  }

  else {                                     // if joystick positive
    analogWrite(ledsPins[1], leftJoystickX); // write right led with joystick value
    digitalWrite(ledsPins[2], 0);            // turn off left led
  }


  int leftJoystickY = gamepad.readAxis(AXIS_LEFT_Y) << 1; // get joystick value and map it to -255 to 255

  if (leftJoystickY < 0) {                         // if joystick towards the top (yes, negative value is up)
    analogWrite(ledsPins[3], abs(leftJoystickY));  // write top led with absolute value of joystick
    digitalWrite(ledsPins[0], 0);                  // turn off right led
  }

  else {                                     // if joystick positive (bottom)
    analogWrite(ledsPins[0], leftJoystickY); // write botoom led with joystick value
    digitalWrite(ledsPins[3], 0);            // turn off top led
  }
}
