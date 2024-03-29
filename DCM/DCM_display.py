import tkinter as tk
import DCM_serial
from DCM_homePage import homePage
import DCM_login
upperRateLimit = [] #0
lowerRateLimit = [] #1
atrialPulseAmplitude = []   #2
atrialPulseWidth = []   #3
ventricularPulseAmplitude = []#4
ventricularPulseWidth = []#5
atrialSensitivity = []#6
ventricularSensitivity = []#7
ARP = []#8
VRP = []#9
PVARP = []#10
rateSmoothing = []#11
maximumSensorRate = []#12
fixedAVDelay = []#13
activityThreshold = []#14
reactionTime = []#15
responseFactor = []#16
recoveryTime = []#17
connected = False

def setParamVals():
    #Lower Rate Limit
    for i in range(30, 55, 5):
        lowerRateLimit.append(i)
    for i in range(50, 90, 1):
        lowerRateLimit.append(i)
    for i in range(90, 180, 5):
        lowerRateLimit.append(i)

    #upperRateLimit
    for i in range(50, 180, 5):
        upperRateLimit.append(i)

    #maximumSensorRate
    for i in range(50, 180, 5):
        maximumSensorRate.append(i)

    #atrialPulseAmplitude and ventricularPulseAmplitude
    atrialPulseAmplitude.append("OFF")

    temp = 0
    while(temp < 50):
        temp = temp + 1
        atrialPulseAmplitude.append(temp/10)
    
    ventricularPulseAmplitude.extend(atrialPulseAmplitude)

    #atrialPulseWidth and ventricularPulseWidth
    atrialPulseWidth.append(0.05)
    temp = 0
    while(temp < 30):
        temp = temp + 1
        atrialPulseWidth.append(temp)
    ventricularPulseWidth.extend(atrialPulseWidth)

    #atrialSensitivity
    temp = 0
    while(temp < 50):
        temp = temp + 1
        atrialSensitivity.append(temp/10)
    ventricularSensitivity.extend(atrialSensitivity)

    #ARP, VRP, and PVARP
    temp = 140
    while(temp <= 490):
        temp = temp + 10
        ARP.append(temp)
    VRP.extend(ARP)
    PVARP.extend(ARP)

    #rateSmoothing
    rateSmoothing.append("OFF")
    rateSmoothing.append(25)
    temp = 0
    while(temp <= 21):
        temp = temp + 3
        rateSmoothing.append(temp)
    
    #fixedAVDelay
    for i in range(70, 310, 10):
        fixedAVDelay.append(i)

    
    #upperRateLimit
    lst = ["V-Low", "Low", "Med-Low", "Med", "Med-High", "High", "V-High"]
    for i in lst:
        activityThreshold.append(i)

    #reactionTime
    for i in range(10, 60, 10):
        reactionTime.append(i)

    #responseFactor
    for i in range(1, 17, 1):
        responseFactor.append(i)

    #recoveryTime
    for i in range(2, 17, 1):
        recoveryTime.append(i)

def switchMode(val):
    if(val == 'AOO'):
        return DCM_AOO
    elif(val == 'VOO'):
        return DCM_VOO
    elif(val == 'AAI'):
        return DCM_AAI
    elif(val == 'VVI'):
        return DCM_VVI
    elif(val == 'DOO'):
        return DCM_DOO
    elif(val == 'AOOR'):
        return DCM_AOOR
    elif(val == 'VOOR'):
        return DCM_VOOR
    elif(val == 'AAIR'):
        return DCM_AAIR
    elif(val == 'VVIR'):
        return DCM_VVIR
    elif(val == 'DOOR'):
        return DCM_DOOR

# def connectionIndicator(obj):
#     global connected
#     if(connected or DCM_serial.isConnect()):
#         obj.configure(fg="green")
#         obj.configure(text="Connected")
#         obj.master.update()
#         connected = True
#     else:
#         obj.configure(fg="red")
#         obj.configure(text="Not Connected")
#         obj.master.update()

# def connectionID(obj):
#     obj.configure(fg="red" if DCM_serial.getDeviceID() == "N/A" else "green")
#     obj.configure(text="ID: " + DCM_serial.getDeviceID())
#     obj.master.update()

def popupmsg(msg):
        popup = tk.Tk()
        popup.wm_title("ERROR!")
        for i in msg:
            tk.Label(popup, text=i).pack(side="top", fill="x", padx=10)
        B1 = tk.Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()

def programmableDataRange(modeParam):
    errors = []
    
    try:
        for i in modeParam:
            if i[0] == "upperRateLimit":
                if int(i[1]) not in upperRateLimit:
                    errors.append("Upper Rate Limit Invalid: (50 - 175, increment = 5)")

            elif i[0] == "lowerRateLimit":
                if int(i[1]) not in lowerRateLimit:
                    errors.append("Lower Rate Limit Invalid: \n- (30 - 50, increment = 5)\n- (50 - 90, increment = 1)\n- (90 - 175, increment = 5)")

            elif str(i[1]) != "OFF" and i[0] == "atrialPulseAmplitude":
                if float(i[1]) not in atrialPulseAmplitude:
                    errors.append("Atrial Pulse Amplitude Invalid:\n- (0.1 - 5.0, increment = 0.1) \n- OFF")

            elif i[0] == "atrialPulseWidth":
                if float(i[1]) not in atrialPulseWidth:
                    errors.append("Atrial Pulse Width Invalid:\n - (1 - 30, increment = 1)")

            elif i[0] == "ventricularPulseAmplitude":
                if str(i[1]) != "OFF" and float(i[1]) not in ventricularPulseAmplitude:
                    errors.append("Ventricular Pulse Amplitude Invalid:\n- (0.1 - 5.0, increment = 0.1) \n- OFF")

            elif i[0] == "ventricularPulseWidth":
                if float(i[1]) not in ventricularPulseWidth:
                    errors.append("Ventricular Pulse Width Invalid:\n - (1 - 30, increment = 1)")

            elif i[0] == "atrialSensitivity":
                if float(i[1]) not in atrialSensitivity:
                    errors.append("Atrial Sensitivity Invalid:\n - (0.0 - 5.0, increment = 0.1)")

            elif i[0] == "ventricularSensitivity":
                if float(i[1]) not in ventricularSensitivity:
                    errors.append("Ventricular Sensitivity Invalid:\n - (0.0 - 5.0, increment = 0.1)")

            elif i[0] == "ARP":
                if float(i[1]) not in ARP:
                    errors.append("ARP Invalid:\n - (150 - 500, increment = 10)")
            
            elif i[0] == "VRP":
                if float(i[1]) not in VRP:
                    errors.append("VRP Invalid:\n - (150 - 500, increment = 10)")
            
            elif i[0] == "ARP":
                if float(i[1]) not in ARP:
                    errors.append("ARP Invalid:\n - (150 - 500, increment = 10)")

            elif i[0] == "PVARP":
                if float(i[1]) not in PVARP:
                    errors.append("PVARP:\n - (150 - 500, increment = 10)")

            elif i[0] == "rateSmoothing":
                if str(i[1]) != "OFF" and int(i[1]) not in rateSmoothing:
                    errors.append("Rate Smoothing:\n - (OFF, 3, 6, 9, 12, 15, 18, 21, 25)")

            elif i[0] == "maximumSensorRate":
                if float(i[1]) not in maximumSensorRate:
                    errors.append("Rate Smoothing:\n - (50-175, increment = 5)")

            elif i[0] == "activityThreshold":
                if float(i[1]) not in activityThreshold:
                    errors.append("Rate Smoothing:\n - (V-Low, Low, Med-Low, Med, Med-High, High, V-High)")

            elif i[0] == "reactionTime":
                if float(i[1]) not in reactionTime:
                    errors.append("Rate Smoothing:\n - (10 - 50, increment = 10)")

            elif i[0] == "responseFactor":
                if float(i[1]) not in responseFactor:
                    errors.append("Rate Smoothing:\n - (1 - 16, increment = 1)")

            elif i[0] == "recoveryTime":
                if float(i[1]) not in recoveryTime:
                    errors.append("Rate Smoothing:\n - (2 - 16, increment = 1)")

    except Exception as e:
        print(e)
        errors.append("Text Field(s) are empty or invalid!")

    if errors:
        popupmsg(errors)
        return False
    return True


class DCMPage(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        # Drop down options:
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Pacing Modes: ").grid(row=0, column=0, pady=10)
       
        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)

        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=4, columnspan=4, pady=10, padx=20)
      
    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))


class DCM_AOO(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   AOO").grid(
            row=0, column=0, pady=10, padx=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Amplitude").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Pulse Width").grid(
            row=2, column=2, pady=10, padx=10)

        # fileName = DCM_login.userName + '.txt'
        # # print(fileName)
        # parametersFile = open(fileName, 'r')
        # parameters = parametersFile.readlines()
        # parametersFile.close()
     
        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()
        #TO DO:
        # add review of the current value to the textbox
        # upperRateLimit.insert(0,self.upperRateLimit)
        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0, defaultText[1])

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)
        atrialPulseAmplitude.insert(0, defaultText[2])

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)
        atrialPulseWidth.insert(0, defaultText[3])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, atrialPulseAmplitude, atrialPulseWidth)).grid(row=4, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=4, columnspan=2, column=2, pady=10, padx=20)

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

    def modifyParameters(self, upperRateLimit, lowerRateLimit, atrialPulseAmplitude, atrialPulseWidth):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.atrialPulseAmplitude = atrialPulseAmplitude.get()
        self.atrialPulseWidth = atrialPulseWidth.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 2):
                newFile.write(self.atrialPulseAmplitude+"\n")
            elif (i == 3):
                newFile.write(self.atrialPulseWidth+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        '''
        print("upperRateLimit ", self.upperRateLimit)
        print("lowerRateLimit ", self.lowerRateLimit)
        print("atrialPulseAmplitude ", self.atrialPulseAmplitude)
        print("atrialPulseWidth", self.atrialPulseWidth)
        '''
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
        #             ["atrialPulseAmplitude", self.atrialPulseAmplitude],["atrialPulseWidth", self.atrialPulseWidth]])):
        #     data = [int(self.lowerRateLimit), int(self.upperRateLimit), float(0 if self.atrialPulseAmplitude == "OFF" else self.atrialPulseAmplitude), float(self.atrialPulseWidth)]
        #     DCM_serial.setMode(2,data)
        #     DCM_serial.echoMode()

class DCM_VOO(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   VOO").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)
       
        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Amplitude").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Pulse Width").grid(
            row=2, column=2, pady=10, padx=10)

        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)
        ventricularPulseAmplitude.insert(0,defaultText[4])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)
        ventricularPulseWidth.insert(0,defaultText[5])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth)).grid(row=4, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=4, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 4):
                newFile.write(self.ventricularPulseAmplitude+"\n")
            elif (i == 5):
                newFile.write(self.ventricularPulseWidth+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
        #             ["ventricularPulseAmplitude", self.ventricularPulseAmplitude],["ventricularPulseWidth", self.ventricularPulseWidth]])):
        #     data = [int(self.lowerRateLimit), int(self.upperRateLimit), float(0 if self.ventricularPulseAmplitude == "OFF" else self.ventricularPulseAmplitude), float(self.ventricularPulseWidth)]
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))
    
    

class DCM_AAI(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   AAI").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Amplitude").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Pulse Width").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Sensitivity").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="ARP").grid(row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="PVARP").grid(row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="Hysteresis").grid(
            row=4, column=2, pady=10, padx=10)

        tk.Label(self, text="Rate Smoothing").grid(
            row=5, column=0, pady=10, padx=10)

        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[2])

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)
        atrialPulseWidth.insert(0,defaultText[3])

        atrialSensitivity = tk.Entry(self)
        atrialSensitivity.grid(row=3, column=1, pady=10, padx=10)
        atrialSensitivity.insert(0,defaultText[6])

        ARP = tk.Entry(self)
        ARP.grid(row=3, column=3, pady=10, padx=10)
        ARP.insert(0,defaultText[8])

        PVARP = tk.Entry(self)
        PVARP.grid(row=4, column=1, pady=10, padx=10)
        PVARP.insert(0,defaultText[10])

        hysteresis = tk.Entry(self)
        hysteresis.grid(row=4, column=3, pady=10, padx=10)
        hysteresis.insert(0,defaultText[18])

        rateSmoothing = tk.Entry(self)
        rateSmoothing.grid(row=5, column=1, pady=10, padx=10)
        rateSmoothing.insert(0,defaultText[11])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, atrialPulseAmplitude, atrialPulseWidth, atrialSensitivity, ARP, PVARP, hysteresis, rateSmoothing)).grid(row=6, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=6, columnspan=2, column=2, pady=10, padx=20)

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

    def modifyParameters(self, upperRateLimit, lowerRateLimit, atrialPulseAmplitude, atrialPulseWidth, atrialSensitivity, ARP, PVARP, hysteresis, rateSmoothing):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.atrialPulseAmplitude = atrialPulseAmplitude.get()
        self.atrialPulseWidth = atrialPulseWidth.get()
        self.atrialSensitivity = atrialSensitivity.get()
        self.ARP = ARP.get()
        self.PVARP = PVARP.get()
        self.hysteresis = hysteresis.get()
        self.rateSmoothing = rateSmoothing.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 2):
                newFile.write(self.atrialPulseAmplitude+"\n")
            elif (i == 3):
                newFile.write(self.atrialPulseWidth+"\n")
            elif (i == 6):
                newFile.write(self.atrialSensitivity+"\n")
            elif (i == 8):
                newFile.write(self.ARP+"\n")
            elif (i == 10):
                newFile.write(self.PVARP+"\n")
            elif (i == 18):
                newFile.write(self.hysteresis+"\n")
            elif (i == 11):
                newFile.write(self.rateSmoothing+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
        #             ["atrialPulseAmplitude", self.atrialPulseAmplitude],["atrialPulseWidth", self.atrialPulseWidth],
        #             ["atrialSensitivity",self.atrialSensitivity],["ARP", self.ARP], ["PVARP", self.PVARP], ["rateSmoothing", self.rateSmoothing]])):
        #     data = [int(self.lowerRateLimit), int(self.upperRateLimit), float(0 if self.atrialPulseAmplitude == "OFF" else self.atrialPulseAmplitude), float(self.atrialPulseWidth), int(self.ARP), float(self.atrialSensitivity),
        #            int(self.rateSmoothing), int(self.PVARP)]
        #     DCM_serial.setMode(3,data)
        #     DCM_serial.echoMode()
    

class DCM_VVI(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   VVI").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Amplitude").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Pulse Width").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Sensitivity").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="VRP").grid(row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="Hysteresis").grid(
            row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="Rate Smoothing").grid(
            row=4, column=2, pady=10, padx=10)

        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)
        ventricularPulseAmplitude.insert(0,defaultText[4])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[5])

        ventricularSensitivity = tk.Entry(self)
        ventricularSensitivity.grid(row=3, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[7])

        VRP = tk.Entry(self)
        VRP.grid(row=3, column=3, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[9])

        hysteresis = tk.Entry(self)
        hysteresis.grid(row=4, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[18])

        rateSmoothing = tk.Entry(self)
        rateSmoothing.grid(row=4, column=3, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[11])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth, ventricularSensitivity, VRP, hysteresis, rateSmoothing)).grid(row=5, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=5, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth, ventricularSensitivity, VRP, hysteresis, rateSmoothing):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()
        self.ventricularSensitivity = ventricularSensitivity.get()
        self.VRP = VRP.get()
        self.hysteresis = hysteresis.get()
        self.rateSmoothing = rateSmoothing.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 4):
                newFile.write(self.ventricularPulseAmplitude+"\n")
            elif (i == 5):
                newFile.write(self.ventricularPulseWidth+"\n")
            elif (i == 7):
                newFile.write(self.ventricularSensitivity+"\n")
            elif (i == 9):
                newFile.write(self.VRP+"\n")
            elif (i == 18):
                newFile.write(self.hysteresis+"\n")
            elif (i == 11):
                newFile.write(self.rateSmoothing+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
        #             ["ventricularPulseAmplitude", self.ventricularPulseAmplitude],["ventricularPulseWidth", self.ventricularPulseWidth],
        #             ["ventricularSensitivity",self.ventricularSensitivity],["VRP", self.VRP], ["rateSmoothing", self.rateSmoothing]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.ventricularPulseAmplitude, self.ventricularPulseWidth, self.VRP, self.ventricularSensitivity,
        #            self.rateSmoothing]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(1,data)
        #     DCM_serial.echoMode()

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

    
class DCM_DOO(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   DOO").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)
        
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Fixed AV Delay").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Amplitude").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Amplitude").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Pulse Width").grid(row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Pulse Width").grid(
            row=4, column=0, pady=10, padx=10)
        
        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        fixedAVDelay = tk.Entry(self)
        fixedAVDelay.grid(row=2, column=1, pady=10, padx=10)
        fixedAVDelay.insert(0,defaultText[13])

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=3, pady=10, padx=10)
        atrialPulseAmplitude.insert(0,defaultText[2])

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=3, column=1, pady=10, padx=10)
        ventricularPulseAmplitude.insert(0,defaultText[4])

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=3, column=3, pady=10, padx=10)
        atrialPulseWidth.insert(0,defaultText[3])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=4, column=1, pady=10, padx=10)
        ventricularPulseWidth.insert(0,defaultText[5])


        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, fixedAVDelay, atrialPulseAmplitude, ventricularPulseAmplitude, atrialPulseWidth, ventricularPulseWidth)).grid(row=4, columnspan=2 ,column=3, pady=10, padx=15)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=4, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, fixedAVDelay, atrialPulseAmplitude, ventricularPulseAmplitude, atrialPulseWidth, ventricularPulseWidth):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.fixedAVDelay = fixedAVDelay.get()
        self.atrialPulseAmplitude = atrialPulseAmplitude.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.atrialPulseWidth = atrialPulseWidth.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 13):
                newFile.write(self.fixedAVDelay+"\n")
            elif (i == 2):
                newFile.write(self.atrialPulseAmplitude+"\n")
            elif (i == 4):
                newFile.write(self.ventricularPulseAmplitude+"\n")
            elif (i == 3):
                newFile.write(self.atrialPulseWidth+"\n")
            elif (i == 5):
                newFile.write(self.ventricularPulseWidth+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],["fixedAVDelay", self.fixedAVDelay],["atrialPulseAmplitude", self.atrialPulseAmplitude]
        #             ["ventricularPulseAmplitude", self.ventricularPulseAmplitude],["atrialPulseWidth", self.atrialPulseWidth],["ventricularPulseWidth", self.ventricularPulseWidth]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.fixedAVDelay, self.atrialPulseAmplitude, self.ventricularPulseAmplitude, self.ventricularPulseAmplitude, self.ventricularPulseWidth]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

    
class DCM_AOOR(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   AOOR").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)
        
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Maximum Sensor Rate").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Amplitude").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Pulse Width").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="Activity Threshold").grid(
            row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="Reaction Time").grid(
            row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="Response Factor").grid(
            row=4, column=2, pady=10, padx=10)
        
        tk.Label(self, text="Recovery Time").grid(
            row=5, column=0, pady=10, padx=10)

        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()
    
    
        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        maximumSensorRate = tk.Entry(self)
        maximumSensorRate.grid(row=2, column=1, pady=10, padx=10)
        maximumSensorRate.insert(0,defaultText[12])

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=3, pady=10, padx=10)
        atrialPulseAmplitude.insert(0,defaultText[2])

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=3, column=1, pady=10, padx=10)
        atrialPulseWidth.insert(0,defaultText[3])

        activityThreshold = tk.Entry(self)
        activityThreshold.grid(row=3, column=3, pady=10, padx=10)
        activityThreshold.insert(0,defaultText[14])

        reactionTime = tk.Entry(self)
        reactionTime.grid(row=4, column=1, pady=10, padx=10)
        reactionTime.insert(0,defaultText[15])

        responseFactor = tk.Entry(self)
        responseFactor.grid(row=4, column=3, pady=10, padx=10)
        responseFactor.insert(0,defaultText[16])

        recoveryTime = tk.Entry(self)
        recoveryTime.grid(row=5, column=1, pady=10, padx=10)
        recoveryTime.insert(0,defaultText[17])
      

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, maximumSensorRate, atrialPulseAmplitude, atrialPulseWidth, activityThreshold, reactionTime, responseFactor, recoveryTime)).grid(row=5, columnspan=2 ,column=3, pady=10, padx=15)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=5, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, maximumSensorRate, atrialPulseAmplitude, atrialPulseWidth, activityThreshold, reactionTime, responseFactor, recoveryTime):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.maximumSensorRate = maximumSensorRate.get()
        self.atrialPulseAmplitude = atrialPulseAmplitude.get()
        self.atrialPulseWidth = atrialPulseWidth.get()
        self.activityThreshold = activityThreshold.get()
        self.reactionTime = reactionTime.get()
        self.responseFactor = responseFactor.get()
        self.recoveryTime = recoveryTime.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 12):
                newFile.write(self.maximumSensorRate+"\n")
            elif (i == 2):
                newFile.write(self.atrialPulseAmplitude+"\n")
            elif (i == 3):
                newFile.write(self.atrialPulseWidth+"\n")
            elif (i == 14):
                newFile.write(self.activityThreshold+"\n")
            elif (i == 15):
                newFile.write(self.reactionTime+"\n")
            elif (i == 16):
                newFile.write(self.responseFactor+"\n")
            elif (i == 17):
                newFile.write(self.recoveryTime+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],["maximumSensorRate", self.maximumSensorRate],["atrialPulseAmplitude", self.atrialPulseAmplitude]
        #            ["atrialPulseWidth", self.atrialPulseWidth],["activityThreshold", self.activityThreshold],["reactionTime", self.reactionTime],["responseFactor", self.responseFactor],["recoveryTime", self.recoveryTime]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.maximumSensorRate, self.atrialPulseAmplitude, self.atrialPulseWidth, self.activityThreshold, self.reactionTime, self.responseFactor, self.recoveryTime]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()
   
    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

class DCM_VOOR(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   VOOR").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)
        
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Maximum Sensor Rate").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Amplitude").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Pulse Width").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="Activity Threshold").grid(
            row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="Reaction Time").grid(
            row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="Response Factor").grid(
            row=4, column=2, pady=10, padx=10)
        
        tk.Label(self, text="Recovery Time").grid(
            row=5, column=0, pady=10, padx=10)

        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()
    
        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        maximumSensorRate = tk.Entry(self)
        maximumSensorRate.grid(row=2, column=1, pady=10, padx=10)
        maximumSensorRate.insert(0,defaultText[12])

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=2, column=3, pady=10, padx=10)
        ventricularPulseAmplitude.insert(0,defaultText[4])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=3, column=1, pady=10, padx=10)
        ventricularPulseWidth.insert(0,defaultText[5])

        activityThreshold = tk.Entry(self)
        activityThreshold.grid(row=3, column=3, pady=10, padx=10)
        activityThreshold.insert(0,defaultText[14])

        reactionTime = tk.Entry(self)
        reactionTime.grid(row=4, column=1, pady=10, padx=10)
        reactionTime.insert(0,defaultText[15])

        responseFactor = tk.Entry(self)
        responseFactor.grid(row=4, column=3, pady=10, padx=10)
        responseFactor.insert(0,defaultText[16])

        recoveryTime = tk.Entry(self)
        recoveryTime.grid(row=5, column=1, pady=10, padx=10)
        recoveryTime.insert(0,defaultText[17])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, maximumSensorRate, ventricularPulseAmplitude, ventricularPulseWidth, activityThreshold, reactionTime, responseFactor, recoveryTime)).grid(row=5, columnspan=2 ,column=3, pady=10, padx=15)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=5, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self,upperRateLimit, lowerRateLimit, maximumSensorRate, ventricularPulseAmplitude, ventricularPulseWidth, activityThreshold, reactionTime, responseFactor, recoveryTime):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.maximumSensorRate = maximumSensorRate.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()
        self.activityThreshold = activityThreshold.get()
        self.reactionTime = reactionTime.get()
        self.responseFactor = responseFactor.get()
        self.recoveryTime = recoveryTime.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 12):
                newFile.write(self.maximumSensorRate+"\n")
            elif (i == 4):
                newFile.write(self.ventricularPulseAmplitude+"\n")
            elif (i == 5):
                newFile.write(self.ventricularPulseWidth+"\n")
            elif (i == 14):
                newFile.write(self.activityThreshold+"\n")
            elif (i == 15):
                newFile.write(self.reactionTime+"\n")
            elif (i == 16):
                newFile.write(self.responseFactor+"\n")
            elif (i == 17):
                newFile.write(self.recoveryTime+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],["maximumSensorRate", self.maximumSensorRate],["ventricularPulseAmplitude", self.ventricularPulseAmplitude]
        #            ["ventricularPulseWidth", self.ventricularPulseWidth],["activityThreshold", self.activityThreshold],["reactionTime", self.reactionTime],["responseFactor", self.responseFactor],["recoveryTime", self.recoveryTime]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.maximumSensorRate, self.ventricularPulseAmplitude, self.ventricularPulseWidth, self.activityThreshold, self.reactionTime, self.responseFactor, self.recoveryTime]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()
     
    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))


class DCM_AAIR(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   AAIR").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)
        
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Maximum Sensor Rate").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Amplitude").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Pulse Width").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Sensitivity").grid(row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="ARP").grid(
            row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="PVARP").grid(
            row=4, column=2, pady=10, padx=10)

        tk.Label(self, text="Hysteresis").grid(
            row=5, column=0, pady=10, padx=10)
        tk.Label(self, text="Rate Smoothing").grid(
            row=5, column=2, pady=10, padx=10)

        tk.Label(self, text="Activity Threshold").grid(
            row=6, column=0, pady=10, padx=10)
        tk.Label(self, text="Reaction Time").grid(
            row=6, column=2, pady=10, padx=10)

        tk.Label(self, text="Response Factor").grid(
            row=7, column=0, pady=10, padx=10)
        tk.Label(self, text="Recovery Time").grid(
            row=7, column=2, pady=10, padx=10)

        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        maximumSensorRate = tk.Entry(self)
        maximumSensorRate.grid(row=2, column=1, pady=10, padx=10)
        maximumSensorRate.insert(0,defaultText[12])

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=3, pady=10, padx=10)
        atrialPulseAmplitude.insert(0,defaultText[2])

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=3, column=1, pady=10, padx=10)
        atrialPulseWidth.insert(0,defaultText[3])

        atrialSensitivity = tk.Entry(self)
        atrialSensitivity.grid(row=3, column=3, pady=10, padx=10)
        atrialSensitivity.insert(0,defaultText[6])

        ARP = tk.Entry(self)
        ARP.grid(row=4, column=1, pady=10, padx=10)
        ARP.insert(0,defaultText[8])

        PVARP = tk.Entry(self)
        PVARP.grid(row=4, column=3, pady=10, padx=10)
        PVARP.insert(0,defaultText[10])

        hysteresis = tk.Entry(self)
        hysteresis.grid(row=5, column=1, pady=10, padx=10)
        hysteresis.insert(0,defaultText[18])

        rateSmoothing = tk.Entry(self)
        rateSmoothing.grid(row=5, column=3, pady=10, padx=10)
        rateSmoothing.insert(0,defaultText[11])

        activityThreshold = tk.Entry(self)
        activityThreshold.grid(row=6, column=1, pady=10, padx=10)
        activityThreshold.insert(0,defaultText[14])

        reactionTime = tk.Entry(self)
        reactionTime.grid(row=6, column=3, pady=10, padx=10)
        reactionTime.insert(0,defaultText[15])

        responseFactor = tk.Entry(self)
        responseFactor.grid(row=7, column=1, pady=10, padx=10)
        responseFactor.insert(0,defaultText[16])

        recoveryTime = tk.Entry(self)
        recoveryTime.grid(row=7, column=3, pady=10, padx=10)
        recoveryTime.insert(0,defaultText[17])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, maximumSensorRate, atrialPulseAmplitude, atrialPulseWidth, atrialSensitivity, ARP, PVARP, hysteresis, rateSmoothing, activityThreshold, reactionTime, responseFactor, recoveryTime)).grid(row=8, columnspan=2 ,column=3, pady=10, padx=15)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=8, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, maximumSensorRate, atrialPulseAmplitude, atrialPulseWidth, atrialSensitivity, ARP, PVARP, hysteresis, rateSmoothing, activityThreshold, reactionTime, responseFactor, recoveryTime):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.maximumSensorRate = maximumSensorRate.get()
        self.atrialPulseAmplitude = atrialPulseAmplitude.get()
        self.atrialPulseWidth = atrialPulseWidth.get()
        self.atrialSensitivity = atrialSensitivity.get()
        self.ARP = ARP.get()
        self.PVARP = PVARP.get()
        self.hysteresis = hysteresis.get()
        self.rateSmoothing = rateSmoothing.get()
        self.activityThreshold = activityThreshold.get()
        self.reactionTime = reactionTime.get()
        self.responseFactor = responseFactor.get()
        self.recoveryTime = recoveryTime.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 12):
                newFile.write(self.maximumSensorRate+"\n")
            elif (i == 2):
                newFile.write(self.atrialPulseAmplitude+"\n")
            elif (i == 3):
                newFile.write(self.atrialPulseWidth+"\n")
            elif (i == 6):
                newFile.write(self.atrialSensitivity+"\n")
            elif (i == 8):
                newFile.write(self.ARP+"\n")
            elif (i == 10):
                newFile.write(self.PVARP+"\n")
            elif (i == 18):
                newFile.write(self.hysteresis+"\n")
            elif (i == 11):
                newFile.write(self.rateSmoothing+"\n")
            elif (i == 14):
                newFile.write(self.activityThreshold+"\n")
            elif (i == 15):
                newFile.write(self.reactionTime+"\n")
            elif (i == 16):
                newFile.write(self.responseFactor+"\n")
            elif (i == 17):
                newFile.write(self.recoveryTime+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],["maximumSensorRate", self.maximumSensorRate],["atrialPulseAmplitude", self.atrialPulseAmplitude]
        #            ["atrialPulseWidth", self.atrialPulseWidth],["atrialSensitivity", self.atrialSensitivity],["ARP", self.ARP],["PVARP", self.PVARP],["hysteresis", self.hysteresis],["rateSmoothing", self.rateSmoothing],["activityThreshold", self.activityThreshold],["reactionTime", self.reactionTime],["responseFactor", self.responseFactor],["recoveryTime", self.recoveryTime]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.maximumSensorRate, self.atrialPulseAmplitude, self.atrialPulseWidth, self.atrialSensitivity, self.ARP, self.PVARP, self.hysteresis, self.rateSmoothing, self.activityThreshold, self.reactionTime, self.responseFactor, self.recoveryTime]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()
       

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

class DCM_VVIR(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   VVIR").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)
        
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Maximum Sensor Rate").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Amplitude").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Pulse Width").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Sensitivity").grid(
            row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="VRP").grid(
            row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="Hysteresis").grid(
            row=4, column=2, pady=10, padx=10)
        
        tk.Label(self, text="Rate Smoothing").grid(
            row=5, column=0, pady=10, padx=10)
        tk.Label(self, text="Activity Threshold").grid(
            row=5, column=2, pady=10, padx=10)
        
        tk.Label(self, text="Reaction Time").grid(
            row=6, column=0, pady=10, padx=10)
        tk.Label(self, text="Response Factor").grid(
            row=6, column=2, pady=10, padx=10)

        tk.Label(self, text="Recovery Time").grid(
            row=7, column=0, pady=10, padx=10)
      
        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()
    
        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        maximumSensorRate = tk.Entry(self)
        maximumSensorRate.grid(row=2, column=1, pady=10, padx=10)
        maximumSensorRate.insert(0,defaultText[12])

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=2, column=3, pady=10, padx=10)
        ventricularPulseAmplitude.insert(0,defaultText[4])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=3, column=1, pady=10, padx=10)
        ventricularPulseWidth.insert(0,defaultText[5])

        ventricularSensitivity = tk.Entry(self)
        ventricularSensitivity.grid(row=3, column=3, pady=10, padx=10)
        ventricularSensitivity.insert(0,defaultText[7])

        VPR = tk.Entry(self)
        VPR.grid(row=4, column=1, pady=10, padx=10)
        VPR.insert(0,defaultText[9])

        hysteresis = tk.Entry(self)
        hysteresis.grid(row=4, column=3, pady=10, padx=10)
        hysteresis.insert(0,defaultText[18])

        rateSmoothing = tk.Entry(self)
        rateSmoothing.grid(row=5, column=1, pady=10, padx=10)
        rateSmoothing.insert(0,defaultText[11])

        activityThreshold = tk.Entry(self)
        activityThreshold.grid(row=5, column=3, pady=10, padx=10)
        activityThreshold.insert(0,defaultText[14])

        reactionTime = tk.Entry(self)
        reactionTime.grid(row=6, column=1, pady=10, padx=10)
        reactionTime.insert(0,defaultText[15])

        responseFactor = tk.Entry(self)
        responseFactor.grid(row=6, column=3, pady=10, padx=10)
        responseFactor.insert(0,defaultText[16])

        recoveryTime = tk.Entry(self)
        recoveryTime.grid(row=7, column=1, pady=10, padx=10)
        recoveryTime.insert(0,defaultText[17])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, maximumSensorRate, ventricularPulseAmplitude, ventricularPulseWidth,ventricularSensitivity,VPR,hysteresis, rateSmoothing, activityThreshold, reactionTime, responseFactor, recoveryTime)).grid(row=7, columnspan=2 ,column=3, pady=10, padx=15)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=7, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, maximumSensorRate, ventricularPulseAmplitude, ventricularPulseWidth,ventricularSensitivity,VPR,hysteresis, rateSmoothing, activityThreshold, reactionTime, responseFactor, recoveryTime):

        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.maximumSensorRate = maximumSensorRate.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()
        self.ventricularSensitivity = ventricularSensitivity.get()
        self.VPR = VPR.get()
        self.hysteresis = hysteresis.get()
        self.rateSmoothing = rateSmoothing.get()
        self.activityThreshold = activityThreshold.get()
        self.reactionTime = reactionTime.get()
        self.responseFactor = responseFactor.get()
        self.recoveryTime = recoveryTime.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 12):
                newFile.write(self.maximumSensorRate+"\n")
            elif (i == 4):
                newFile.write(self.ventricularPulseAmplitude+"\n")
            elif (i == 5):
                newFile.write(self.ventricularPulseWidth+"\n")
            elif (i == 7):
                newFile.write(self.ventricularSensitivity+"\n")
            elif (i == 9):
                newFile.write(self.VPR+"\n")
            elif (i == 18):
                newFile.write(self.hysteresis+"\n")
            elif (i == 11):
                newFile.write(self.rateSmoothing+"\n")
            elif (i == 14):
                newFile.write(self.activityThreshold+"\n")
            elif (i == 15):
                newFile.write(self.reactionTime+"\n")
            elif (i == 16):
                newFile.write(self.responseFactor+"\n")
            elif (i == 17):
                newFile.write(self.recoveryTime+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],["maximumSensorRate", self.maximumSensorRate],["ventricularPulseAmplitude", self.ventricularPulseAmplitude]
        #            ["ventricularPulseWidth", self.ventricularPulseWidth],["ventricularSensitivity", self.ventricularSensitivity],["VPR", self.VPR],["hysteresis", self.hysteresis],["rateSmoothing", self.rateSmoothing],["activityThreshold", self.activityThreshold],["reactionTime", self.reactionTime],["responseFactor", self.responseFactor],["recoveryTime", self.recoveryTime]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.maximumSensorRate, self.ventricularPulseAmplitude, self.ventricularPulseWidth, self.ventricularSensitivity, self.VRP, self.hysteresis, self.rateSmoothing, self.activityThreshold, self.reactionTime, self.responseFactor, self.recoveryTime]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()
   

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

class DCM_DOOR(tk.Frame):
    print("foor")
    def __init__(self, master):
        
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   DOOR").grid(
            row=0, column=0, pady=10)

        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        # connectionIndicator(self.isConnected)
        # connectionID(self.ID)
        
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI','DOO','AOOR','VOOR','AAIR','VVIR','DOOR'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(
            row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(
            row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Maximum Sensor Rate").grid(
            row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Fixed AV Delay").grid(
            row=2, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Amplitude").grid(
            row=3, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Amplitude").grid(
            row=3, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Pulse Width").grid(
            row=4, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Pulse Width").grid(
            row=4, column=2, pady=10, padx=10)
        
        tk.Label(self, text="Activity Threshold").grid(
            row=5, column=0, pady=10, padx=10)
        tk.Label(self, text="Reaction Time").grid(
            row=5, column=2, pady=10, padx=10)
        
        tk.Label(self, text="Response Factor").grid(
            row=6, column=0, pady=10, padx=10)
        tk.Label(self, text="Recovery Time").grid(
            row=6, column=2, pady=10, padx=10)
      
        fileName = DCM_login.userName + '.txt'
        defaultFile = open(fileName, 'r')
        defaultText = defaultFile.read().split("\n")
        defaultFile.close()
    
        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)
        upperRateLimit.insert(0,defaultText[0])

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
        lowerRateLimit.insert(0,defaultText[1])

        maximumSensorRate = tk.Entry(self)
        maximumSensorRate.grid(row=2, column=1, pady=10, padx=10)
        maximumSensorRate.insert(0,defaultText[12])

        fixedAVDelay = tk.Entry(self)
        fixedAVDelay.grid(row=2, column=3, pady=10, padx=10)
        fixedAVDelay.insert(0,defaultText[13])

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=3, column=1, pady=10, padx=10)
        atrialPulseAmplitude.insert(0,defaultText[2])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=3, column=3, pady=10, padx=10)
        ventricularPulseWidth.insert(0,defaultText[4])

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=4, column=1, pady=10, padx=10)
        atrialPulseWidth.insert(0,defaultText[3])

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=4, column=3, pady=10, padx=10)
        ventricularPulseWidth.insert(0,defaultText[5])

        activityThreshold = tk.Entry(self)
        activityThreshold.grid(row=5, column=1, pady=10, padx=10)
        activityThreshold.insert(0,defaultText[14])

        reactionTime = tk.Entry(self)
        reactionTime.grid(row=5, column=3, pady=10, padx=10)
        reactionTime.insert(0,defaultText[15])

        responseFactor = tk.Entry(self)
        responseFactor.grid(row=6, column=1, pady=10, padx=10)
        responseFactor.insert(0,defaultText[16])

        recoveryTime = tk.Entry(self)
        recoveryTime.grid(row=6, column=3, pady=10, padx=10)
        recoveryTime.insert(0,defaultText[17])

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, maximumSensorRate, fixedAVDelay, atrialPulseAmplitude, ventricularPulseAmplitude, atrialPulseWidth, ventricularPulseWidth, activityThreshold, reactionTime, responseFactor, recoveryTime)).grid(row=7, columnspan=2 ,column=3, pady=10, padx=15)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=7, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, maximumSensorRate, fixedAVDelay, atrialPulseAmplitude, ventricularPulseAmplitude, atrialPulseWidth, ventricularPulseWidth, activityThreshold, reactionTime, responseFactor, recoveryTime):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.maximumSensorRate = maximumSensorRate.get()
        self.fixedAVDelay = fixedAVDelay.get()
        self.atrialPulseAmplitude = atrialPulseAmplitude.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.atrialPulseWidth = atrialPulseWidth.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()
        self.activityThreshold = activityThreshold.get()
        self.reactionTime = reactionTime.get()
        self.responseFactor = responseFactor.get()
        self.recoveryTime = recoveryTime.get()
        fileName = DCM_login.userName + '.txt'
        parametersFile = open(fileName, 'r')
        parameters = parametersFile.read().split("\n")
        parametersFile.close()
        for line in parameters:
            print(line)
        newFile = open(fileName, 'w')  
        for i in range(19):
            if (i == 0):
                newFile.write(self.upperRateLimit+"\n")
            elif (i == 1):
                newFile.write(self.lowerRateLimit+"\n")
            elif (i == 12):
                newFile.write(self.maximumSensorRate+"\n")
            elif (i == 13):
                newFile.write(self.fixedAVDelay+"\n")
            elif (i == 2):
                newFile.write(self.atrialPulseAmplitude+"\n")
            elif (i == 4):
                newFile.write(self.ventricularPulseAmplitude+"\n")
            elif (i == 3):
                newFile.write(self.atrialPulseWidth+"\n")
            elif (i == 5):
                newFile.write(self.ventricularPulseWidth+"\n")
            elif (i == 14):
                newFile.write(self.activityThreshold+"\n")
            elif (i == 15):
                newFile.write(self.reactionTime+"\n")
            elif (i == 16):
                newFile.write(self.responseFactor+"\n")
            elif (i == 17):
                newFile.write(self.recoveryTime+"\n")
            else:
                newFile.write(parameters[i]+"\n")
        newFile.close()
        # if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],["maximumSensorRate", self.maximumSensorRate],["fixedAVDelay", self.fixedAVDelay],["atrialPulseAmplitude", self.atrialPulseAmplitude],["ventricularPulseAmplitude", self.ventricularPulseAmplitude]
        #            ["atrialPulseWidth", self.atrialPulseWidth],["ventricularPulseWidth", self.ventricularPulseWidth],["activityThreshold", self.activityThreshold],["reactionTime", self.reactionTime],["responseFactor", self.responseFactor],["recoveryTime", self.recoveryTime]])):
        #     data = [self.lowerRateLimit, self.upperRateLimit, self.maximumSensorRate, self.fixedAVDelay, self.ventricularPulseAmplitude, self.ventricularPulseWidth, self.activityThreshold, self.reactionTime, self.responseFactor, self.recoveryTime]
        #     data = list(map(int, data))
        #     DCM_serial.setMode(0,data)
        #     DCM_serial.echoMode()
     

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))


setParamVals()
#print(atrialPulseWidth)
#print(atrialSensitivity)