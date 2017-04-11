from tkinter import *
 
class But_print:

    def __init__(self):
        self.but = Button(root)
        self.but["text"] = "Печать"
        self.but.bind("<Button-2>",self.printer)
        self.but.pack()
    def printer(self,event):
        print ("Как всегда очередной 'Hello World!'")
 
root = Tk()
root.title("Main Window")
root.geometry("250x250")
obj = But_print()
root.mainloop()
