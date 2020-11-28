#IMPORTANT: Look at the other serial.py file for an important explaination

import serial
import struct
from time import sleep
COM = "COM3"
#TODO
#Work on this for assignment 2

def isConnect():
    connection = False
    try:
        ser = serial.Serial(COM, 115200, timeout=3)
        sleep(2)
        ser.write(b"\x16\x22" + b"\x00"*31)
        while ser.read():
            print("Connected!")
            ser.close()
            return True
        ser.close()
    except serial.serialutil.SerialException:
        print("No serial connection!")
        return False
    
def getDeviceID():
    deviceID = "N/A"
    return deviceID #device ID to differentiate different pacemakers

def setMode(mode, param):
    ser = serial.Serial(COM, 115200, timeout=10)
    sleep(2)
    #print(mode)
    setting = struct.pack("B", mode)
    if(mode==0):
        LRL = struct.pack("B", param[0])
        URL = struct.pack("B", param[1]) 
        AA = struct.pack("H", 0*1000)
        APW = struct.pack("B", 0)
        VA = struct.pack("H", param[2]*1000)
        VPW = struct.pack("B", param[3])
        ARP = struct.pack("H", 0)
        VRP = struct.pack("H", 0)
        A_Sens = struct.pack("f", 0*1000)
        V_Sens = struct.pack("f", 0*1000)
        RateSM = struct.pack("B", 0)
        PVARP = struct.pack("H", 0)
        fixAVDelay = struct.pack("H", 0)
        maxSensRate = struct.pack("B", 0)
        actThres = struct.pack("B", 0)
        reactTime = struct.pack("B", 0)
        respFact = struct.pack("B", 0)
        recovTime = struct.pack("B", 0)
    elif(mode==1):
        print(param)
        LRL = struct.pack("B", param[0])
        URL = struct.pack("B", param[1]) 
        AA = struct.pack("H", 0*1000)
        APW = struct.pack("B", 0)
        VA = struct.pack("H", param[2]*1000)
        VPW = struct.pack("B", param[3])
        ARP = struct.pack("H", 0)
        VRP = struct.pack("H", param[4])
        A_Sens = struct.pack("f", 0*1000)
        V_Sens = struct.pack("f", param[5])
        RateSM = struct.pack("B", param[6])
        PVARP = struct.pack("H", 0)
        fixAVDelay = struct.pack("H", 0)
        maxSensRate = struct.pack("B", 0)
        actThres = struct.pack("B", 0)
        reactTime = struct.pack("B", 0)
        respFact = struct.pack("B", 0)
        recovTime = struct.pack("B", 0)
    elif(mode==2):
        LRL = struct.pack("B", param[0])
        URL = struct.pack("B", param[1]) 
        AA = struct.pack("H", param[2]*1000)
        APW = struct.pack("B", param[3])
        VA = struct.pack("H", 0*1000)
        VPW = struct.pack("B", 0)
        ARP = struct.pack("H", 0)
        VRP = struct.pack("H", 0)
        A_Sens = struct.pack("f", 0*1000)
        V_Sens = struct.pack("f", 0*1000)
        RateSM = struct.pack("B", 0)
        PVARP = struct.pack("H", 0)
        fixAVDelay = struct.pack("H", 0)
        maxSensRate = struct.pack("B", 0)
        actThres = struct.pack("B", 0)
        reactTime = struct.pack("B", 0)
        respFact = struct.pack("B", 0)
        recovTime = struct.pack("B", 0)
    elif(mode==3): 
        LRL = struct.pack("B", param[0])
        URL = struct.pack("B", param[1]) 
        AA = struct.pack("H", param[2]*1000)
        APW = struct.pack("B", param[3])
        VA = struct.pack("H", 0*1000)
        VPW = struct.pack("B", 0)
        ARP = struct.pack("H", param[4])
        VRP = struct.pack("H", 0)
        A_Sens = struct.pack("f", param[5])
        V_Sens = struct.pack("f", 0*1000)
        RateSM = struct.pack("B", param[6])
        PVARP = struct.pack("H", param[7])
        fixAVDelay = struct.pack("H", 0)
        maxSensRate = struct.pack("B", 0)
        actThres = struct.pack("B", 0)
        reactTime = struct.pack("B", 0)
        respFact = struct.pack("B", 0)
        recovTime = struct.pack("B", 0)

    data = b"\x16\x55"+setting+LRL+URL+AA+APW+VA+VPW+ARP+VRP+A_Sens+V_Sens+RateSM+PVARP+fixAVDelay+maxSensRate+actThres+reactTime+respFact+recovTime
    ser.write(data)
    #print(data)
    print(data)
    print("Parameters updated!")
    #x = ser.read(33)
    #print("Correct: " +str(data))
    #print("Read: ", x)
    #ser.close()

def echoMode():
    ser = serial.Serial(COM, 115200, timeout=10)
    sleep(2)
    ser.write(b"\x16\x22" + b"\x00"*31)
    readIn = ser.read(33)
    print(readIn)

    print("Mode: "+ str(struct.unpack("B", readIn[0:1])[0]))
    print("LRL: "+ str(struct.unpack("B", readIn[1:2])[0]))
    print("URL: "+ str(struct.unpack("B", readIn[2:3])[0]))
    print("AA: "+ str(struct.unpack("H", readIn[3:5])[0]))
    print("AWP: "+ str(struct.unpack("B", readIn[5:6])[0]))
    print("VA: "+ str(struct.unpack("H", readIn[6:8])[0]))
    print("VPW: "+ str(struct.unpack("B", readIn[8:9])[0]))
    print("ARP: "+ str(struct.unpack("H", readIn[9:11])[0]))
    print("VRP: "+ str(struct.unpack("H", readIn[11:13])[0]))
    print("A_Sens: "+ str(struct.unpack("f", readIn[13:17])[0]))
    print("V_Sens: "+ str(struct.unpack("f", readIn[17:21])[0]))
    print("RateSM: "+ str(struct.unpack("B", readIn[21:22])[0]))
    print("PVARP: "+ str(struct.unpack("H", readIn[22:24])[0]))
    print("fixAVDelay: "+ str(struct.unpack("H", readIn[24:26])[0]))
    print("maxSenRate: "+ str(struct.unpack("B", readIn[26:27])[0]))
    print("actThres: "+ str(struct.unpack("B", readIn[27:28])[0]))
    print("reactTime: "+ str(struct.unpack("B", readIn[28:29])[0]))
    print("respFact: "+ str(struct.unpack("B", readIn[29:30])[0]))
    print("recovTime: "+ str(struct.unpack("B", readIn[30:31])[0]))
    
    ser.close()

#TESTING
#isConnect()
#param = [50, 50, 1, 1, 150, 1, 3]
#[50, 50, 1, 1, 150, 1, 3]
#param = [50,50,1,1]
#echoMode()
#setMode(0, param)
#echoMode()
#print("done")
