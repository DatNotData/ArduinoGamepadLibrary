import pygame
import serial
import serial.tools.list_ports

pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)
joystick.init()

pygame.display.init()


def getByte0():
    byte = 0
    for i in range(8):
        byte |= joystick.get_button(i) << i
    return byte

def getByte1():
    byte = 0

    val = joystick.get_hat(0)
    x = val[0]
    y = val[1]

    if x == 1: # right
        byte |= 1 << 1
    if x == -1: # left
        byte |= 1 << 3

    if y == 1: # up
        byte |= 1 << 0
    if y == -1: # down
        byte |= 1 << 2

    if joystick.get_button(8): # LJB
        byte |= 1 << 4
    if joystick.get_button(9): # RJB
        byte |= 1 << 5

    return byte

def getBytes2to6():
    bytes2to6 = [0, 0, 0, 0, 0]

    for i in range(5):
        raw = joystick.get_axis(i)
        bytes2to6[i] = abs(int(raw * 127)) # binary number from 0 to 127
        bytes2to6[i] |= (1 << 7 if raw < 0 else 0) # added 7th bit if negative

    return bytes2to6

while True:
    while True:

        ports = list(serial.tools.list_ports.comports())

        if len(ports) == 1:
            print('One port detected')
            print(ports[0])
            comPort = ports[0][0]

        elif len(ports) > 1:
            print('Enter choice number of COM port that you want to connect to.\nHere is list of available ones.')
            for i in range(len(ports)):
                print('Choice %s : ' %(i), end = '')
                print(ports[i])

            portNum = input()
            if portNum.isdigit():
                portNum = int(portNum)
                if portNum < len(ports):
                    comPort = ports[portNum][0]
                else:
                    print('INPUT ERROR - Number too big')
                    continue
            else:
                print('INPUT ERROR - Please enter an INTEGER')
                continue

        else:
            print("No COM ports")
            continue

        try:
            ser = serial.Serial(comPort, 9600)
        except serial.serialutil.SerialException:
            print('Serial start failed, trying again')
            continue

        if ser.isOpen():
            print('COM secured')
            print('Connection done')
            break

    while True:
        try:
            pygame.event.get()

            allBytes = [getByte0()] + [getByte1()] + getBytes2to6()

            if ser.isOpen():
                message = ser.readline().strip()
                message = str(message).strip("b''")
                if message == 'req':
                    print('sending...')
                    ser.write(allBytes)

        except serial.serialutil.SerialException:
            print("Lost COM")
            ser.close()
            break

