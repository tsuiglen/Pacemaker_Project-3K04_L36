from tkinter import *

class signup:
    def __init__(self, master):
        top=self.top=Toplevel(master)
        top.title("Create an Account")
        Label(top, text="Enter Username").grid(row=0, pady=10, padx=10)
        Label(top, text="Enter Password").grid(row=1, pady=10, padx=10)

        self.userInfo = Entry(top)
        self.userInfo.grid(row=0, column=1, pady=10, padx=10)

        self.pwdInfo = Entry(top, show="*")
        self.pwdInfo.grid(row=1, column=1, pady=10, padx=10)
        

        self.comfirmAccButton = Button(top, text="Create", command=self._createAcc)
        self.comfirmAccButton.grid(row=2, column=0, pady=10, padx=10, columnspan=2)

    def _createAcc(self):
        try:
            accountInfo = open("accountInfo.txt", 'a')
            #print(self.userInfo.get())
            accountInfo.write(str(self.userInfo.get())+"-"+str(self.pwdInfo.get())+"\n")
        finally:
            accountInfo.close()
        self.top.destroy()
   

class loginWindow:
    def __init__(self, master):
        self.master = master
        master.title("Welcome")
        Label(master, text="Username").grid(row=0, pady=10, padx=10)
        Label(master, text="Password").grid(row=1, pady=10)

        self.username = Entry(master)
        self.username.grid(row=0, column=1, pady=10, padx=10)

        self.password = Entry(master, show="*")
        self.password.grid(row=1, column=1, pady=10)

        self.loginButton = Button(master, text="Login", command=self.validateLogin)
        self.loginButton.grid(row=3, column=0, columnspan = 2, pady=2, padx=10)

        self.createAccButton = Button(master, text="Create an Account", command=self.createAccount)
        self.createAccButton.grid(row=4, column=0, columnspan = 2, pady=5, padx=10)

    def validateLogin(self):
        try:
            accountInfo = open("accountInfo.txt", 'r')
            username = str(self.username.get())
            password = str(self.password.get())
            accounts = accountInfo.read().split("\n")
            accountInfo.close()
            accounts.pop()  #removes empty line

            for i in accounts:
                if(username == i.split("-")[0] and password == i.split("-")[1]):
                    print("Login Successful!")
                    self.master.destroy()
                    return
            self.popupmsg("Incorrect Login!")
        except:
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
            newAcc = signup(self.master)
            self.createAccButton['state'] = 'disabled'
            self.master.wait_window(newAcc.top)
            self.createAccButton['state'] = 'normal'
        else:
            self.popupmsg("Max amount of local Accounts!")
    
    def popupmsg(self, msg):
        popup = Tk()
        popup.wm_title("!")
        label = Label(popup, text=msg)
        label.pack(side="top", fill="x", pady=10)
        B1 = Button(popup, text="Okay", command = popup.destroy)
        B1.pack(pady=5, padx=10)
        popup.mainloop()