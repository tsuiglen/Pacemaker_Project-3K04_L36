from tkinter import *
# code for DCM GUI


class ConnectDevice:
    def __init__(self, master):
        top = self.top = Toplevel(master)
        top.title("Choose Connection Option")

        self.connectCurrButton = Button(
            top, text="Connect Current Device", command=self._connectCurrDevice)
        self.connectCurrButton.grid(
            row=2, column=0, pady=10, padx=10, columnspan=2)
        self.pairNewButton = Button(
            top, text="Pair New Device", command=self._pairNewDevice)
        self.pairNewButton.grid(
            row=3, column=0, pady=10, padx=10, columnspan=2)

    def _connectCurrDevice(self):
        self.popupmsg("Communicating...")

    def _pairNewDevice(self):
        # self.refresh()
        self.popupmsg("Finding New Device...")

    def popupmsg(self, msg):
        popup = Tk()
        popup.wm_title("!")
        label = Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = Button(popup, text="Okay", command=popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()

    # def refresh(self,master):
    #     self.top.destroy()
    #     top=self.top=Toplevel(master)
    #     top.title("Choose Connection Option")


class DCMWindow:
    def __init__(self, master):
        self.master = master
        master.title("DCM")

        self.DCMButton = Button(
            master, text="Connect My Device", command=self.connectOptions)
        self.DCMButton.grid(row=3, column=0, columnspan=2, pady=2, padx=10)

    def connectOptions(self):
        try:
            connect = ConnectDevice(self.master)
            self.DCMButton['state'] = 'disabled'
            self.master.wait_window(connect.top)
            self.DCMButton['state'] = 'normal'
            TRUE = FALSE
        except:
            self.popupmsg("connectOptions Error")

    def popupmsg(self, msg):
        popup = Tk()
        popup.wm_title("!")
        label = Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = Button(popup, text="Okay", command=popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()
