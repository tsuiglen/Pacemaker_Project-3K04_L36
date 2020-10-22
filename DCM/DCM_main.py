from tkinter import *
import DCM_login 
import DCM_display

#Login Window
login = Tk()
loginWindow = DCM_login.loginWindow(login)
login.mainloop()


#DCM Display
#this should not be called when login window is closed, needs be fixed
DCM = Tk()
DCMWindow = DCM_display.DCMWindow(DCM)
DCM.mainloop()
