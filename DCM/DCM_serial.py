import serial
import struct
from time import sleep

ser = serial

#TODO
#Work on this for assignment 2

def isConnect():
    connection = False
    try:
        ser = serial.Serial("COM3", 115200, timeout=10)

        while ser.read():
            return True
        ser.close()
    except serial.serialutil.SerialException:
        print("No serial connection!")
        return False
    
def getDeviceID():
    deviceID = "N/A"
    return deviceID #device ID to differentiate different pacemakers

def setMode(mode, param):
    ser = serial.Serial("COM3", 115200, timeout=10)

    modeNum = 0 #Pacing mode 1,2,3,4,5,6,7

    if(mode == "AOO"):
        data = b"\x16\x55"
        URL_b = struct.pack("I", param[0]) 
        LRL_b = struct.pack("I", param[1])
        AA_b = struct.pack("f", param[2])
        APW_b = struct.pack("f", param[3])
   
        data = data + URL_b + LRL_b + AA_b + APW_b

        ser.write(data)
        ser.close()