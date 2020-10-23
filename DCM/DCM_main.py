import tkinter as tk
from DCM_login import welcomePage
from DCM_createAccount import CreateAccPage
from DCM_display import DCMPage
#from DCM_AOO_mode import DCM_AOO

class main(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self._frame = None
        self.switch_frame(DCMPage)

    def switch_frame(self, frame_class):
        new_frame = frame_class(self)
        if self._frame is not None:
            self._frame.destroy()
        self._frame = new_frame
        self._frame.pack()

    def validateLogin(self, username, password):
        try:
            accountInfo = open("accountInfo.txt", 'r')
            username = str(username)
            password = str(password)
            accounts = accountInfo.read().split("\n")
            accountInfo.close()
            accounts.pop()  #removes empty line

            for i in accounts:
                if(username == i.split("-")[0] and password == i.split("-")[1]):
                    print("Login Successful!")
                    self.switch_frame(DCMPage)
                    return
            print(username)
            self.popupmsg("Incorrect Login!")
        finally:
            print("FileI/O Error ValidateLogin")
    
    def accountCount(self):
        try:
            accountInfo = open("accountInfo.txt", 'r')
            accounts = accountInfo.readlines()
            if(len(accounts) > 9):
                return False
            else:
                return True
        except:
            print("FileI/O Error")

    def createAccount(self):
        if(self.accountCount()):
            self.switch_frame(CreateAccPage)
        else:
            self.popupmsg("Max amount of local Accounts!")
    
    def storeAccountInfo(self, username, password):
        try:
            accountInfo = open("accountInfo.txt", 'a')
            #print(self.userInfo.get())
            accountInfo.write(str(username)+"-"+str(password)+"\n")
        finally:
            accountInfo.close()
        self.switch_frame(welcomePage)

    
        


    def popupmsg(self, msg):
        popup = tk.Tk()
        popup.wm_title("!")
        label = tk.Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = tk.Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()


app = main()
app.mainloop()


#Notes

#Code for dynamically changing color a label
        #self.a.configure(fg="red")
        #self.master.update()

        #Make sure to change the label to the format below
        #self.a = tk.Label(self, text="Pacing Modes: ")
        #self.a.grid(row=0, column=0, pady=10)