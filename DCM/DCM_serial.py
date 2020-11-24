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
        LRL = struct.pack("I", param[0])
        URL = struct.pack("I", param[1]) 
        AA = struct.pack("Q", param[2])
        APW = struct.pack("I", param[3])
        VA = struct.pack("I", param[4])
        VPW = struct.pack("I", param[5])
        ARP = struct.pack("I", param[5])
        VRP = struct.pack("I", param[5])
        A_Sens = struct.pack("I", param[5])
        V_Sens = struct.pack("I", param[5])
        RateSM = struct.pack("I", param[5])
        PVARP = struct.pack("I", param[5])
        fixAVDelay = struct.pack("I", param[5])
        maxSensRate = struct.pack("I", param[5])
        actThres = struct.pack("I", param[5])
        reactTime = struct.pack("I", param[5])
        recovTime = struct.pack("I", param[5])

    data = b"\x16\x55"+LRL+URL+AA+APW+VA+VPW+ARP+VRP+A_Sens+V_Sens+RateSM+PVARP+fixAVDelay+maxSensRate+actThres+reactTime+reactTime

    ser.write(data)
    ser.close()