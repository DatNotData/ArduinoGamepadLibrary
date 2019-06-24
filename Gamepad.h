#pragma once
#include "Arduino.h"

#define BUTTON_A 0
#define BUTTON_B 1
#define BUTTON_X 2
#define BUTTON_Y 3

#define BUTTON_LEFT_BUMPER 4
#define BUTTON_RIGHT_BUMPER 5

#define BUTTON_BACK 6
#define BUTTON_START 7

#define BUTTON_DPAD_UP 8
#define BUTTON_DPAD_RIGHT 9
#define BUTTON_DPAD_DOWN 10
#define BUTTON_DPAD_LEFT 11

#define BUTTON_LEFT_JOYSTICK 12
#define BUTTON_RIGHT_JOYSTICK 13


#define AXIS_LEFT_X 2
#define AXIS_LEFT_Y 3

#define AXIS_RIGHT_X 6
#define AXIS_RIGHT_Y 5

#define AXIS_TRIGGERS 4

class Gamepad {
  private:
    byte data[7] = {0,0,0,0,0,0,0}; // byte array that contains the 7 bytes sent from the Python script (check doc to see what byte does what)
    byte previousData[2] = {0,0}; // byte array that contains data from the previous fetch (only for buttons), used for pressed and released fuction

    static const int buttons[14][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};

  public:
    void begin(); // start gamepad by starting serial communication
    
    void fetchFromSerial(); // request new data from the Python script and store it in the variable data
    
    bool readButton(int button); // read values that either true or false (i.e. buttons) (values either 0 or 1)
    bool readButtonPressed(int button); // return true when button is pressed (once only and not continuously)
    bool readButtonReleased(int button); // return true when button is released

    int readAxis(int byteInData); // read values that are analog (i.e. joysticks axis) (values from -127 to 127)
};
