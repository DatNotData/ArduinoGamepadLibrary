#pragma once
#include "Arduino.h"

class Gamepad{
private:
    byte data[7]; // byte array that contains the 7 bytes sent from the Python script

public:
    void refresh(); // request new data from the Python script and store it in the variable data
    bool readButtonAndDpad(int byteInData, int bitInByte); // read values that either true or false (i.e. buttons) (values either 0 or 1)
    int readJoystickAxis(int byteInData); // read values that are analog (i.e. joysticks axis) (values from -127 to 127)
    
    bool readButtonA();
    bool readButtonB();
    bool readButtonX();
    bool readButtonY();

    bool readLeftBumper();
    bool readRightBumper();

    bool readBackButton();
    bool readStartButton();

    bool readLeftJoystickButton();
    bool readRightJoystickButton();

    bool readDpadUp();
    bool readDpadRight();
    bool readDpadDown();
    bool readDpadLeft();

    int readLeftJoystickX();
    int readLeftJoystickY();

    int readRightJoystickX();
    int readRightJoystickY();

    int readTriggers();
};
