#include "Gamepad.h"

void Gamepad::refresh(){
  Serial.println("req");
  Serial.readBytes(data, 7);
}

bool Gamepad::readButtonAndDpad(int byteInData, int bitInByte){
  return data[byteInData] >> bitInByte & 1; // get byte from array, isolate the specified bit and return it
}

int Gamepad::readJoystickAxis(int byteInData){
  byte raw = data[byteInData]; // get byte from array
  int value = raw & 0b01111111; // remove negative bit
  value *= (raw >> 7 & 1) ? -1 : 1; // apply negative
  return value;
}

// buttons A, B, X, Y

bool Gamepad::readButtonA() {
  return Gamepad::readButtonAndDpad(0, 0);
}

bool Gamepad::readButtonB() {
  return Gamepad::readButtonAndDpad(0, 1);
}

bool Gamepad::readButtonX() {
  return Gamepad::readButtonAndDpad(0, 2);
}

bool Gamepad::readButtonY() {
  return Gamepad::readButtonAndDpad(0, 3);
}

// bumpers

bool Gamepad::readLeftBumper() {
  return Gamepad::readButtonAndDpad(0, 4);
}

bool Gamepad::readRightBumper() {
  return Gamepad::readButtonAndDpad(0, 5);
}

// buttons back, start, joysticks button

bool Gamepad::readBackButton() {
  return Gamepad::readButtonAndDpad(0, 6);
}

bool Gamepad::readStartButton() {
  return Gamepad::readButtonAndDpad(0, 7);
}

bool Gamepad::readLeftJoystickButton() {
  return Gamepad::readButtonAndDpad(1, 4);
}

bool Gamepad::readRightJoystickButton() {
  return Gamepad::readButtonAndDpad(1, 5);
}


// d pad

bool Gamepad::readDpadUp() {
  return Gamepad::readButtonAndDpad(1, 0);
}

bool Gamepad::readDpadRight() {
  return Gamepad::readButtonAndDpad(1, 1);
}

bool Gamepad::readDpadDown() {
  return Gamepad::readButtonAndDpad(1, 2);
}

bool Gamepad::readDpadLeft() {
  return Gamepad::readButtonAndDpad(1, 3);
}

// joysticks

int Gamepad::readLeftJoystickX() {
  return Gamepad::readJoystickAxis(2);
}

int Gamepad::readLeftJoystickY() {
  return Gamepad::readJoystickAxis(3);
}


int Gamepad::readRightJoystickX() {
  return Gamepad::readJoystickAxis(6);
}

int Gamepad::readRightJoystickY() {
  return Gamepad::readJoystickAxis(5);
}


int Gamepad::readTriggers() {
  return Gamepad::readJoystickAxis(4);
}
