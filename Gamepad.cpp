#include "Gamepad.h"

void Gamepad::begin(){
  Serial.begin(9600); // start serial communication with baud rate of 9600, same as the one used in the Python script
}

void Gamepad::fetchFromSerial(){
  previousData[0] = data[0]; // copy data from current byte to previous byte for use in ...
  previousData[1] = data[1]; // ... pressed and released function (only on byte that conttains data for buttons)
  
  Serial.println("req");     // send request message, Python script will send data if this message is received
  Serial.readBytes(data, 7); // write all read bytes into data variable
}

bool Gamepad::readButton(int button){
  return data[buttons[button][0]] >> buttons[button][1] & 1; // get byte from array, isolate the specified bit and return it
}

bool Gamepad::readButtonPressed(int button){
  return (data[buttons[button][0]] >> buttons[button][1] & 1) && !(previousData[buttons[button][0]] >> buttons[button][1] & 1); // return true if byte from array is 1 but from previous array is 0
}

bool Gamepad::readButtonReleased(int button){
  return !(data[buttons[button][0]] >> buttons[button][1] & 1) && (previousData[buttons[button][0]] >> buttons[button][1] & 1); // return true if byte from array is 0 but from previous array is 1
}

int Gamepad::readAxis(int axis){
  byte raw = data[axis];            // get byte from array
  int value = raw & 0b01111111;     // remove negative bit
  value *= (raw >> 7 & 1) ? -1 : 1; // apply negative
  return value;
}
