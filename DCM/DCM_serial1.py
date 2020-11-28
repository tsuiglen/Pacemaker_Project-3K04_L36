#Use this instead of the other serial.py for quicker debugging for the various views.
#The other serial.py requires a serial connection to the pacemaker and is also slow.

def isConnect():
    return False

def getDeviceID():
    deviceID = "N/A"
    return deviceID #device ID to differentiate different pacemakers

def setMode(mode, param):
    return

def echoMode():
    return