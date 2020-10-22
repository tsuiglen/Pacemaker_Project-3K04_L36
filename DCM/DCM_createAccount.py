import tkinter as tk
from DCM_login import welcomePage

class CreateAccPage(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Create an Account")
        tk.Label(self, text="Enter Username").grid(row=0, pady=10, padx=10)
        tk.Label(self, text="Enter Password").grid(row=1, pady=10, padx=10)
        self.username = tk.Entry(self)
        self.username.grid(row=0, column=1, pady=10, padx=10)

        self.password = tk.Entry(self, show="*")
        self.password.grid(row=1, column=1, pady=10)
        
        tk.Button(self, text="Create Account",
                  command=lambda: master.storeAccountInfo(self.getUser(), self.getPass())).grid(row=2, columnspan=2, pady=2, padx=10)
        tk.Button(self, text="Back to Welcome",
                  command=lambda: master.switch_frame(welcomePage)).grid(row=3, columnspan=2, pady=5, padx=10)

    def getUser(self):
        return self.username.get()

    def getPass(self):
        return self.password.get()