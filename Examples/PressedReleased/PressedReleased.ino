#include "Gamepad.h"

// create gamepad object
Gamepad gamepad;

// declare leds pins
int ledsPins[4] = {3, 5, 6, 9}; // top, right, bottom, left

void setup() {
  gamepad.begin();

  for (int pin : ledsPins) {
    pinMode(pin, OUTPUT);
  }

  
  digitalWrite(ledsPins[0], HIGH); // start with bottom led on ...
  digitalWrite(ledsPins[3], LOW);  // ... and top led off
}

void loop() {
  gamepad.fetchFromSerial(); // refresh gamepad to get new data

  bool pressed = gamepad.readButtonPressed(BUTTON_DPAD_LEFT); // check if button was pressed
  if (pressed) {                                              // if it was pressed
    digitalWrite(ledsPins[3], HIGH);                          // turn on top led
    digitalWrite(ledsPins[0], LOW);                           // turn off bottom led
  }

  bool released = gamepad.readButtonReleased(BUTTON_DPAD_LEFT); // check if button was released
  if (released) {                                               // if it was released
    digitalWrite(ledsPins[0], HIGH);                            // turn on bottom led
    digitalWrite(ledsPins[3], LOW);                             // turn off top led
  }
}
