#include "Gamepad.h"

// create gamepad object
Gamepad gamepad;

// declare leds pins
int ledsPins[4] = {3, 5, 6, 9};

void setup() {
  Serial.begin(9600);

  for(int pin: ledsPins){
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  gamepad.fetchFromSerial(); // refresh gamepad to get new data

  // turn on led according to different buttons
  digitalWrite(ledsPins[0], gamepad.readButton(BUTTON_A));
  digitalWrite(ledsPins[1], gamepad.readButton(BUTTON_B));
  digitalWrite(ledsPins[2], gamepad.readButton(BUTTON_X));
  digitalWrite(ledsPins[3], gamepad.readButton(BUTTON_Y));
}
