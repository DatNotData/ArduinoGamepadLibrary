Disclaimer:
- This library doesn't fully conform with the Arduino API style guide
- This was only tested on the Nano (and MAYBE other boards that support normal Arduino Serial)
- I did this myself in a few days
- This was not extensively tested yet


Arduino library to read a gamepad (Logitech G310)

This is performed by reading it with a Python script (with Pygame),
and then sending the information via serial (with PySerial) to the Arduino.

The Arduino code works by sending a request via serial by sending the string "req".
Once received, the python script will refresh all events of pygame,
and then, read all the wanted values, pack them, then send them.
A total of 7 bytes a sent.

data to send (logitech gamepad)
         |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
byte 0 : | Sta | Bck | RB  | LB  |  Y  |  X  |  B  |  A  |
byte 1 : |  7  |  6  | RJB | LJB | Lft | Dwn | Rig | Up  |

byte 2 : left joystick X
byte 3 : left joystick Y

byte 4 : bumper

byte 5 : right joystick Y
byte 6 : right joystick X


button map
A : 0
B : 1
X : 2
Y : 3

LB : 4
RB : 5

Back  : 6
Start : 7

Left joystick button  : 8
Right joystick button : 9

Joystick axis
Left X : 0
Left Y : 1

Right X : 4
Right Y : 3

Bumpers : 2