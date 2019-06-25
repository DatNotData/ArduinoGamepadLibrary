#pragma once
#include "Arduino.h"

class Gamepad {
  private:
    byte data[7] = {0,0,0,0,0,0,0}; // byte array that contains the 7 bytes sent from the Python script (check doc to see what byte does what)
    byte previousData[2] = {0,0}; // byte array that contains data from the previous fetch (only for buttons), used for pressed and released fuction

    const int buttons[14][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};

public:

    enum Button{
      A,
      B,
      X,
      Y,
      LEFT_BUMPER,
      RIGHT_BUMPER,
      BACK,
      START,
      DPAD_UP,
      DPAD_RIGHT,
      DPAD_DOWN,
      DPAD_LEFT,
      LEFT_JOYSTICK,
      RIGHT_JOYSTICK
    };

    enum Axis{
      LEFT_X = 2,
      LEFT_Y = 3,
      RIGHT_X = 6,
      RIGHT_Y = 5,
      TRIGGERS = 4
    };

    /*
      Starts the gamepad and the gamepad's communication with the Python script
    */
    void begin();
    
    /*
      Request new data from the Python script and store it in the variable data
    */
    void fetchFromSerial();
    
    /*
      Reads the current state of a button

      @param button button from which to read value
      @return true if the button is currently being pressed and false if the button is no being pressed
    */
    bool readButton(Button button);

    /*
      Check if the button was just pressed

      @param button button from which to read value
      @return true if the button was not pressed but is now pressed, otherwise false 
    */
    bool readButtonPressed(Button button);

    /*
      Check if the button was just released

      @param button button from which to read value
      @return true if the button was pressed but is now released, otherwise false 
    */
    bool readButtonReleased(Button button);

    /*
      Read axis value (from joystick or triggers)

      @param axis axis from which to read value
      @return axis current value from -127 to 127
    */
    int readAxis(Axis axis);
};
