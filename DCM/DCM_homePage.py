import tkinter as tk
import DCM_livePlot
class homePage(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Home")
        
        # tk.Button(self, text="DCM",
                #   command=lambda: master.validateLogin(self.getUser(), self.getPass())).grid(row=1, columnspan=2, pady=2)
        tk.Button(self, text="DCM Settings",
                  command=lambda: master.goToDCM()).grid(row=2, columnspan=2,  pady=10, padx=20)
        
        # add Connect New Device here

        tk.Button(self, text="Log out",
                  command=lambda: master.logOut()).grid(row=3, columnspan=2, pady=10, padx=20)
    
        tk.Button(self, text="Plot",
                  command=lambda: DCM_livePlot.plot()).grid(row=4, columnspan=2, pady=10, padx=20)