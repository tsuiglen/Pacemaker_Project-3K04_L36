import tkinter as tk
import DCM_serial
from DCM_homePage import homePage

upperRateLimit = []
lowerRateLimit = []
atrialPulseAmplitude = []
atrialPulseWidth = []
ventricularPulseAmplitude = []
ventricularPulseWidth = []
atrialSensitivity = []
ventricularSensitivity = []
ARP = []
VRP = []
PVARP = []
rateSmoothing = []
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

    #atrialPulseAmplitude and ventricularPulseAmplitude
    atrialPulseAmplitude.append("OFF")

    temp = 4
    while(temp <= 31):
        temp = temp + 1
        atrialPulseAmplitude.append(temp/10)
    
    temp = 30
    while(temp <= 69):
        temp = temp + 5
        atrialPulseAmplitude.append(temp/10)
    ventricularPulseAmplitude.extend(atrialPulseAmplitude)

    #atrialPulseWidth and ventricularPulseWidth
    atrialPulseWidth.append(0.05)
    temp = 0
    while(temp <= 18):
        temp = temp + 1
        atrialPulseWidth.append(temp/10)
    ventricularPulseWidth.extend(atrialPulseWidth)

    #atrialSensitivity
    atrialSensitivity.append(0.25)
    atrialSensitivity.append(0.5)
    atrialSensitivity.append(0.75)
    temp = 5
    while(temp <= 100):
        temp = temp + 5
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

def switchMode(val):
    if(val == 'AOO'):
        return DCM_AOO
    elif(val == 'VOO'):
        return DCM_VOO
    elif(val == 'AAI'):
        return DCM_AAI
    elif(val == 'VVI'):
        return DCM_VVI

def connectionIndicator(obj):
    global connected
    if(connected or DCM_serial.isConnect()):
        obj.configure(fg="green")
        obj.configure(text="Connected")
        obj.master.update()
        connected = True
    else:
        obj.configure(fg="red")
        obj.configure(text="Not Connected")
        obj.master.update()

def connectionID(obj):
    obj.configure(fg="red" if DCM_serial.getDeviceID() == "N/A" else "green")
    obj.configure(text="ID: " + DCM_serial.getDeviceID())
    obj.master.update()

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
                    errors.append("Atrial Pulse Amplitude Invalid: \n- (0.5 - 3.2, increment = 0.1) \n- (3.5 - 7.0, increment = 0.5) \n- OFF")

            elif i[0] == "atrialPulseWidth":
                if float(i[1]) not in atrialPulseWidth:
                    errors.append("Atrial Pulse Width Invalid:\n - (0.1 - 1.9, increment = 0.1) \n - 0.05")

            elif i[0] == "ventricularPulseAmplitude":
                if str(i[1]) != "OFF" and float(i[1]) not in ventricularPulseAmplitude:
                    errors.append("Ventricular Pulse Amplitude Invalid:\n - (0.5 - 3.2, increment = 0.1) \n- (3.5 - 7.0, increment = 0.5) \n- OFF")

            elif i[0] == "ventricularPulseWidth":
                if float(i[1]) not in ventricularPulseWidth:
                    errors.append("Ventricular Pulse Width Invalid:\n - (0.1 - 1.9, increment = 0.1) \n - 0.05")

            elif i[0] == "atrialSensitivity":
                if float(i[1]) not in atrialSensitivity:
                    errors.append("Atrial Sensitivity Invalid:\n - (0.25, 0.5, 0.75) \n - (1.0 - 10.0, increment = 0.5)")

            elif i[0] == "ventricularSensitivity":
                if float(i[1]) not in ventricularSensitivity:
                    errors.append("Ventricular Sensitivity Invalid:\n - (0.25, 0.5, 0.75) \n - (1.0 - 10.0, increment = 0.5)")

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
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}

        pacingModeMenu = tk.OptionMenu(
            self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Pacing Modes: ").grid(row=0, column=0, pady=10)
       
        self.isConnected = tk.Label(self, text="") #connection indicator
        self.ID = tk.Label(self, text="") 
        self.isConnected.grid(row=0, column=2, pady=10)
        self.ID.grid(row=0, column=3, pady=10)
        connectionIndicator(self.isConnected)
        connectionID(self.ID)

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
        connectionIndicator(self.isConnected)
        connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}

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

        upperRateLimit = tk.Entry(self)
        #TO DO:
        # add review of the current value to the textbox
        # upperRateLimit.insert(0,self.upperRateLimit)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)

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
        '''
        print("upperRateLimit ", self.upperRateLimit)
        print("lowerRateLimit ", self.lowerRateLimit)
        print("atrialPulseAmplitude ", self.atrialPulseAmplitude)
        print("atrialPulseWidth", self.atrialPulseWidth)
        '''
        if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
                    ["atrialPulseAmplitude", self.atrialPulseAmplitude],["atrialPulseWidth", self.atrialPulseWidth]])):
            data = [self.lowerRateLimit, self.upperRateLimit, self.atrialPulseAmplitude, self.atrialPulseWidth]
            data = list(map(int, data))
            DCM_serial.setMode(2,data)
            DCM_serial.echoMode()

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
        connectionIndicator(self.isConnected)
        connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}

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

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth)).grid(row=4, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=4, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()

        if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
                    ["ventricularPulseAmplitude", self.ventricularPulseAmplitude],["ventricularPulseWidth", self.ventricularPulseWidth]])):
            data = [self.lowerRateLimit, self.upperRateLimit, self.ventricularPulseAmplitude, self.ventricularPulseWidth]
            data = list(map(int, data))
            DCM_serial.setMode(0,data)
            DCM_serial.echoMode()

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
        connectionIndicator(self.isConnected)
        connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}

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

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        atrialPulseAmplitude = tk.Entry(self)
        atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        atrialPulseWidth = tk.Entry(self)
        atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        atrialSensitivity = tk.Entry(self)
        atrialSensitivity.grid(row=3, column=1, pady=10, padx=10)

        ARP = tk.Entry(self)
        ARP.grid(row=3, column=3, pady=10, padx=10)

        PVARP = tk.Entry(self)
        PVARP.grid(row=4, column=1, pady=10, padx=10)

        hysteresis = tk.Entry(self)
        hysteresis.grid(row=4, column=3, pady=10, padx=10)

        rateSmoothing = tk.Entry(self)
        rateSmoothing.grid(row=5, column=1, pady=10, padx=10)

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

        if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
                    ["atrialPulseAmplitude", self.atrialPulseAmplitude],["atrialPulseWidth", self.atrialPulseWidth],
                    ["atrialSensitivity",self.atrialSensitivity],["ARP", self.ARP], ["PVARP", self.PVARP], ["rateSmoothing", self.rateSmoothing]])):
            data = [self.lowerRateLimit, self.upperRateLimit, self.atrialPulseAmplitude, self.atrialPulseWidth, self.ARP, self.atrialSensitivity,
                   self.rateSmoothing, self.PVARP]
            data = list(map(int, data))
            DCM_serial.setMode(3,data)
            DCM_serial.echoMode()
    


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
        connectionIndicator(self.isConnected)
        connectionID(self.ID)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}

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

        upperRateLimit = tk.Entry(self)
        upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        lowerRateLimit = tk.Entry(self)
        lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        ventricularPulseAmplitude = tk.Entry(self)
        ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        ventricularPulseWidth = tk.Entry(self)
        ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        ventricularSensitivity = tk.Entry(self)
        ventricularSensitivity.grid(row=3, column=1, pady=10, padx=10)

        VRP = tk.Entry(self)
        VRP.grid(row=3, column=3, pady=10, padx=10)

        hysteresis = tk.Entry(self)
        hysteresis.grid(row=4, column=1, pady=10, padx=10)

        rateSmoothing = tk.Entry(self)
        rateSmoothing.grid(row=4, column=3, pady=10, padx=10)

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

        if(programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
                    ["ventricularPulseAmplitude", self.ventricularPulseAmplitude],["ventricularPulseWidth", self.ventricularPulseWidth],
                    ["ventricularSensitivity",self.ventricularSensitivity],["VRP", self.VRP], ["rateSmoothing", self.rateSmoothing]])):
            data = [self.lowerRateLimit, self.upperRateLimit, self.ventricularPulseAmplitude, self.ventricularPulseWidth, self.VRP, self.ventricularSensitivity,
                   self.rateSmoothing]
            data = list(map(int, data))
            DCM_serial.setMode(1,data)
            DCM_serial.echoMode()

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

setParamVals()
print(rateSmoothing)