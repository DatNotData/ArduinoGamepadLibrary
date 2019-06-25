#include "Gamepad.h"

// create gamepad object
Gamepad gamepad;

// declare leds pins
int ledsPins[4] = {3, 5, 6, 9};

void setup() {
  gamepad.begin(); 

  for(int pin: ledsPins){ // scroll through all led pins
    pinMode(pin, OUTPUT); // set the led pins to OUTPUT
  }
}

void loop() {
  gamepad.fetchFromSerial(); // refresh gamepad to get new data

  // turn on led according to different buttons
  digitalWrite(ledsPins[0], gamepad.readButton(Gamepad::Button::A));
  digitalWrite(ledsPins[1], gamepad.readButton(Gamepad::Button::B));
  digitalWrite(ledsPins[2], gamepad.readButton(Gamepad::Button::X));
  digitalWrite(ledsPins[3], gamepad.readButton(Gamepad::Button::Y));
}
