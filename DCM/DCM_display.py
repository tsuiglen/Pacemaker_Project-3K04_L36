import tkinter as tk

def switchMode(val):
    if(val == 'AOO'):
        return DCM_AOO
    elif(val == 'VOO'):
        return DCM_VOO
    elif(val == 'AAI'):
        return DCM_AAI
    elif(val == 'VVI'):
        return DCM_VVI


class DCMPage(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        #Drop down options:
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}
        
        pacingModeMenu = tk.OptionMenu(self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Pacing Modes: ").grid(row=0, column=0, pady=10)
        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)
 
    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))


class DCM_AOO(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   AOO").grid(row=0, column=0, pady=10, padx= 10)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}
        
        pacingModeMenu = tk.OptionMenu(self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Atrial Amplitude").grid(row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Pulse Width").grid(row=2, column=2, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.atrialPulseAmplitude = tk.Entry(self)
        self.atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.atrialPulseWidth = tk.Entry(self)
        self.atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))


class DCM_VOO(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   VOO").grid(row=0, column=0, pady=10)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}
        
        pacingModeMenu = tk.OptionMenu(self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Amplitude").grid(row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Pulse Width").grid(row=2, column=2, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.ventricularPulseAmplitude = tk.Entry(self)
        self.ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.ventricularPulseWidth = tk.Entry(self)
        self.ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

#TODO 
#Change the Parameter for AAI Mode
class DCM_AAI(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   AAI").grid(row=0, column=0, pady=10)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}
        
        pacingModeMenu = tk.OptionMenu(self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Amplitude").grid(row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Pulse Width").grid(row=2, column=2, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.ventricularPulseAmplitude = tk.Entry(self)
        self.ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.ventricularPulseWidth = tk.Entry(self)
        self.ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))

#TODO 
#Change the Parameter for AAI Mode
class DCM_VVI(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        tk.Label(self, text="Pacing Mode:   VVI").grid(row=0, column=0, pady=10)

        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}
        
        pacingModeMenu = tk.OptionMenu(self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)

        tk.Label(self, text="Ventricular Amplitude").grid(row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Ventricular Pulse Width").grid(row=2, column=2, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.ventricularPulseAmplitude = tk.Entry(self)
        self.ventricularPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.ventricularPulseWidth = tk.Entry(self)
        self.ventricularPulseWidth.grid(row=2, column=3, pady=10, padx=10)

    def getDropDown(self, val):
        self.master.switch_frame(switchMode(val))