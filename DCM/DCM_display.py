import tkinter as tk
from DCM_login import welcomePage

class DCMPage(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Pacemaker DCM")

        #Drop down options:
        self.tkvar = tk.StringVar(self)
        pacingMode = {'AOO', 'VOO', 'AAI', 'VVI'}
        
        pacingModeMenu = tk.OptionMenu(self, self.tkvar, *pacingMode, command=self.getDropDown)
        pacingModeMenu.grid(row=0, column=1, pady=10, padx=5)

        tk.Label(self, text="Pacing Modes").grid(row=0, column=0, pady=10)
        tk.Label(self, text="Upper Rate Limit").grid(row=1, column=0, pady=10, padx=10)
        tk.Label(self, text="Lower Rate Limit").grid(row=1, column=2, pady=10, padx=10)
        tk.Label(self, text="Atrial Amplitude").grid(row=2, column=0, pady=10, padx=10)
        tk.Label(self, text="Atrial Pulse Width").grid(row=2, column=2, pady=10, padx=10)
        tk.Label(self, text="Atrial Refractory Period").grid(row=2, column=4, pady=10, padx=10)

        self.upperRateLimit = tk.Entry(self)
        self.upperRateLimit.grid(row=1, column=1, pady=10, padx=10)

        self.lowerRateLimit = tk.Entry(self)
        self.lowerRateLimit.grid(row=1, column=3, pady=10, padx=10)

        self.atrialPulseAmplitude = tk.Entry(self)
        self.atrialPulseAmplitude.grid(row=2, column=1, pady=10, padx=10)

        self.atrialPulseWidth = tk.Entry(self)
        self.atrialPulseWidth.grid(row=2, column=3, pady=10, padx=10)

        self.atrialRefractoryPeriod = tk.Entry(self)
        self.atrialRefractoryPeriod.grid(row=2, column=5, pady=10, padx=10)
    
    def getDropDown(self, val):
        print(val)
        if(val == 'AOO'):
            self.master.switch_frame(welcomePage)