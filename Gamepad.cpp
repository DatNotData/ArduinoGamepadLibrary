#include "Gamepad.h"

void Gamepad::fetchFromSerial(){
  Serial.println("req");
  Serial.readBytes(data, 7);
}

bool Gamepad::readButton(int button){
  return data[buttons[button][0]] >> buttons[button][1] & 1; // get byte from array, isolate the specified bit and return it
}

int Gamepad::readAxis(int axis){
  byte raw = data[axis]; // get byte from array
  int value = raw & 0b01111111; // remove negative bit
  value *= (raw >> 7 & 1) ? -1 : 1; // apply negative
  return value;
}
