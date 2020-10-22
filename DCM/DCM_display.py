from tkinter import *
#code for DCM GUI

# class DCMWindow:
#     def __init__(self, master):
#         self.master = master
#         master.title("DCM")
class ConnectDevice:
    def __init__(self, master):
        # self.master = master
        # master.title("Choose Connection Option")
        top=self.top=Toplevel(master)
        top.title("Choose Connection Option")
        

        self.comfirmAccButton = Button(top, text="Connect Current Device", command=self._connectCurrDevice)
        self.comfirmAccButton.grid(row=2, column=0, pady=10, padx=10, columnspan=2)
    
    def _connectCurrDevice(self):
        # self.refresh()
        self.master.destroy()
        # Label(top, text="Connect Communicating to Device...").grid(row=0, pady=10, padx=10)
    
    def popupmsg(self, msg):
        popup = Tk()
        popup.wm_title("!")
        label = Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()

    def refresh(self,master):
        self.top.destroy()
        top=self.top=Toplevel(master)
        top.title("Choose Connection Option")
       
class DCMWindow:
    def __init__(self, master):
        self.master = master
        master.title("DCM")

        self.loginButton = Button(master, text="Connect My Device", command=self.connectOptions)
        self.loginButton.grid(row=3, column=0, columnspan = 2, pady=2, padx=10)

    def connectOptions(self):
        try:
            newAcc = ConnectDevice(self.master)
            self.createAccButton['state'] = 'disabled'
            self.master.wait_window(newAcc.top)
            self.createAccButton['state'] = 'normal'
        except:
            self.popupmsg("connectOptions Error")
    
    def popupmsg(self, msg):
        popup = Tk()
        popup.wm_title("!")
        label = Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()

#Testin
#login = Tk()
#oginWindow = loginWindow(login)
#login.mainloop()
