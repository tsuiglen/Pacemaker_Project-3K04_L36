import tkinter as tk
userName = ""
class welcomePage(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        master.title("Welcome")
        tk.Label(self, text="Username").grid(row=0, pady=10, padx=10)
        tk.Label(self, text="Password").grid(row=1, pady=10)
        self.username = tk.Entry(self)
        self.username.grid(row=0, column=1, pady=10, padx=10)

        self.password = tk.Entry(self, show="*")
        self.password.grid(row=1, column=1, pady=10)


        tk.Button(self, text="Login",
                  command=lambda: master.validateLogin(self.getUser(), self.getPass())).grid(row=2, columnspan=2, pady=2)
        tk.Button(self, text="Create an Account",
                  command=lambda: master.createAccount()).grid(row=3, columnspan=2, pady=5)
    
    def getUser(self):
        global userName
        userName = self.username.get()
        return userName

    def getPass(self):
        return self.password.get()
