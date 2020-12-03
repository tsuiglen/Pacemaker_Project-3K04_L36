import tkinter as tk
import DCM_login
from DCM_login import welcomePage
from DCM_createAccount import CreateAccPage
from DCM_display import DCMPage
from DCM_homePage import homePage

#from DCM_AOO_mode import DCM_AOO

class main(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self._frame = None
        self.switch_frame(welcomePage)

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
                    print("Login Successful! Username: "  + username)
                    # fileName = DCM_login.userName + '.txt'
                    # parameters = open(fileName, 'a')
                    self.switch_frame(homePage)
                    return
            print(username)
            self.popupmsg("Incorrect Login!")
        except Exception as e:
            print(e)
    
    def accountCount(self):
        try:
            accountInfo = open("accountInfo.txt", 'r')
            accounts = accountInfo.readlines()
            if(len(accounts) > 9):
                print(len(accounts))
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
            fileName = username + '.txt'
            parameters = open(fileName, 'w')
            for i in range (19):
                parameters.write('20' + '\n')
        finally:
            accountInfo.close()
            parameters.close()
        self.switch_frame(welcomePage)
    
    def logOut(self):

        self.switch_frame(welcomePage)

    def goToDCM(self):
        self.switch_frame(DCMPage)

    def popupmsg(self, msg):
        popup = tk.Tk()
        popup.wm_title("Attention!")
        label = tk.Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = tk.Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()


app = main()
app.mainloop()

