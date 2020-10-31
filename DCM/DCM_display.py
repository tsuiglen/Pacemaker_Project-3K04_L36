import tkinter as tk
from DCM_serial import *
from DCM_homePage import homePage

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
    if(isConnect()):
        obj.configure(fg="green")
        obj.configure(text="Connected")
        obj.master.update()
    else:
        obj.configure(fg="red")
        obj.configure(text="Not Connected")
        obj.master.update()

def connectionID(obj):
    obj.configure(fg="red" if getDeviceID() == "N/A" else "green")
    obj.configure(text="ID: " +getDeviceID())
    obj.master.update()

def popupmsg(msg):
        popup = tk.Tk()
        popup.wm_title("ERROR!")
        for i in msg:
            tk.Label(popup, text=i).pack(side="top", fill="x", padx=10)
        B1 = tk.Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()

#TODO create a function that limits the upper and lower ranges for each parameter. 
def programmableDataRange(modeParam):
    errors = []
    for i in modeParam:
        if i[0] == "upperRateLimit":
            if i[1] == "" or float(i[1]) > 175.0 or float(i[1]) < 50.0:
                errors.append("Upper Rate Limit Invalid: (50 - 175)")
        elif i[0] == "lowerRateLimit":
            if i[1] == "" or float(i[1]) > 50.0 or float(i[1]) < 30.0:
                errors.append("Lower Rate Limit Invalid: \n-    (30 - 50, increment = 5)\n- (50 - 90, increment = 1)\n- (90 - 175, increment = 5)")
        elif i[0] == "atrialPulseAmplitude":
            if i[1] == "" or i[1] != "OFF" and (float(i[1]) > 3.2 or float(i[1]) < 0.5):
                errors.append("Atrial Pulse Amplitude Invalid: \n- (0.5 - 3.2, increment = 0.1) \n- (3.5 - 7.0, increment = 0.5) \n- OFF")
        elif i[0] == "atrialPulseWidth":
            if i[1] == "" or float(i[1]) > 1.9 or float(i[1]) < 0.1:
                errors.append("Atrial Pulse Width Upper Rate Limit Invalid:\n - (0.1 - 1.9, increment = 0.1) \n - 0.05")
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

        programmableDataRange([["upperRateLimit", self.upperRateLimit],["lowerRateLimit", self.lowerRateLimit],
                    ["atrialPulseAmplitude", self.atrialPulseAmplitude],["atrialPulseWidth", self.atrialPulseWidth]])

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

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.ventricularPulseAmplitude = tk.Entry(self)
        self.ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.ventricularPulseWidth = tk.Entry(self)
        self.ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth)).grid(row=4, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=4, columnspan=2, column=2, pady=10, padx=20)

    def modifyParameters(self, upperRateLimit, lowerRateLimit, ventricularPulseAmplitude, ventricularPulseWidth):
        self.upperRateLimit = upperRateLimit.get()
        self.lowerRateLimit = lowerRateLimit.get()
        self.ventricularPulseAmplitude = ventricularPulseAmplitude.get()
        self.ventricularPulseWidth = ventricularPulseWidth.get()

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

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.atrialPulseAmplitude = tk.Entry(self)
        self.atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.atrialPulseWidth = tk.Entry(self)
        self.atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        self.atrialSensitivity = tk.Entry(self)
        self.atrialSensitivity.grid(row=3, column=1, pady=10, padx=10)

        self.ARP = tk.Entry(self)
        self.ARP.grid(row=3, column=3, pady=10, padx=10)

        self.PVARP = tk.Entry(self)
        self.PVARP.grid(row=4, column=1, pady=10, padx=10)

        self.hysteresis = tk.Entry(self)
        self.hysteresis.grid(row=4, column=3, pady=10, padx=10)

        self.rateSmoothing = tk.Entry(self)
        self.rateSmoothing.grid(row=5, column=1, pady=10, padx=10)

        tk.Button(self, text="Modify",
                  command=lambda: self.modifyParameters(upperRateLimit, lowerRateLimit, atrialPulseAmplitude, atrialPulseWidth, atrialSensitivity, ARP, PVARP, hysteresis, rateSmoothing)).grid(row=6, columnspan=2 ,column=0, pady=10, padx=5)

        tk.Button(self, text="Back",
                  command=lambda: self.master.switch_frame(homePage)).grid(row=6, columnspan=2, column=2, pady=10, padx=20)

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

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))


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

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.ventricularPulseAmplitude = tk.Entry(self)
        self.ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.ventricularPulseWidth = tk.Entry(self)
        self.ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        self.ventricularSensitivity = tk.Entry(self)
        self.ventricularSensitivity.grid(row=3, column=1, pady=10, padx=10)

        self.VRP = tk.Entry(self)
        self.VRP.grid(row=3, column=3, pady=10, padx=10)

        self.hysteresis = tk.Entry(self)
        self.hysteresis.grid(row=4, column=1, pady=10, padx=10)

        self.rateSmoothing = tk.Entry(self)
        self.rateSmoothing.grid(row=4, column=3, pady=10, padx=10)

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

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))
