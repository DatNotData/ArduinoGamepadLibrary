#include "Gamepad.h"

// create gamepad object
Gamepad gamepad;

// declare leds pins
int ledsPins[4] = {3, 5, 6, 9}; // down, right, left up

void setup() {
  Serial.begin(9600);

  for (int pin : ledsPins) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  gamepad.fetchFromSerial(); // refresh gamepad to get new data

  int leftJoystickX = gamepad.readAxis(AXIS_LEFT_X) << 1; // get joystick value and map it to -255 to 255

  if (leftJoystickX < 0) { // if joystick towards the left
    analogWrite(ledsPins[2], abs(leftJoystickX));  // write left led with absolute value of joystick
    digitalWrite(ledsPins[1], 0); // turn off right led
  }

  else { // if joystick positive
    analogWrite(ledsPins[1], leftJoystickX); // write right led with joystick value
    digitalWrite(ledsPins[2], 0); // turn off left led
  }


  int leftJoystickY = gamepad.readAxis(AXIS_LEFT_Y) << 1; // get joystick value and map it to -255 to 255

  if (leftJoystickY <ard 0) { // if joystick towards the top (yes, negative value is up)
    analogWrite(ledsPins[3], abs(leftJoystickY));  // write top led with absolute value of joystick
    digitalWrite(ledsPins[0], 0); // turn off right led
  }

  else { // if joystick positive (bottom)
    analogWrite(ledsPins[0], leftJoystickY); // write botoom led with joystick value
    digitalWrite(ledsPins[3], 0); // turn off top led
  }
}
