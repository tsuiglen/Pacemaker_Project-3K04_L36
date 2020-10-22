from tkinter import *
import DCM_login 
import DCM_display

#Login Window
login = Tk()
loginWindow = DCM_login.loginWindow(login)
login.mainloop()

#DCM Display
#DCM = Tk()
#DCMWindow = DCM_display.DCMWindow(login)
#DCM.mainloop()
