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

  bool pressed = gamepad.readButtonPressed(Gamepad::Button::DPAD_LEFT); // check if button was pressed
  if (pressed) {                       // if it was pressed
    for (int i = 0; i < 3; i++) {      // do it 3 times
      digitalWrite(ledsPins[3], HIGH); // turn on top led
      delay(50);                       // wait 50 milliseconds
      digitalWrite(ledsPins[3], LOW);  // turn off top led
      delay(50);                       // wait 50 milliseconds
    }
  }

  bool released = gamepad.readButtonReleased(Gamepad::Button::DPAD_LEFT); // check if button was released
  if (released) {                      // if it was released
    for (int i = 0; i < 3; i++) {      // do it 3 times
      digitalWrite(ledsPins[0], HIGH); // turn on top led
      delay(50);                       // wait 50 milliseconds
      digitalWrite(ledsPins[0], LOW);  // turn off bottom led
      delay(50);                       // wait 50 milliseconds
    }
  }
}
