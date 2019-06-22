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
  gamepad.refresh(); // refresh gamepad to get new data

  // turn on led according to different buttons
  digitalWrite(ledsPins[0], gamepad.readButtonA());
  digitalWrite(ledsPins[1], gamepad.readButtonB());
  digitalWrite(ledsPins[2], gamepad.readButtonX());
  digitalWrite(ledsPins[3], gamepad.readButtonY());
}
