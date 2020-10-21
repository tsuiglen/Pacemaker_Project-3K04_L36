from tkinter import *

class loginWindow:

    def __init__(self, master):
        self.master = master
        master.title("Welcome")
        #master.geometry("500x500")
        Label(master, text="Username").grid(row=0)
        Label(master, text="Password").grid(row=1)

        self.username = Entry(master)
        self.username.grid(row=0, column=1)

        self.password = Entry(master)
        self.password.grid(row=1, column=1)

        self.printButton = Button(master, text="Login", command=self.validateLogin)
        self.printButton.grid(row=3, column=1)

    def validateLogin(self):
        print("Hello " + self.username.get())

#Testing
login = Tk()
loginWindow = loginWindow(login)
login.mainloop()
