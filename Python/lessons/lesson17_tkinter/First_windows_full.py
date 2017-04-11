from tkinter import *
 
def printer(event):
    print ("Как всегда очередной 'Hello World!'")
 
root = Tk()
root.title("Main Window")
root.geometry("250x250")

but = Button(root)
but["text"] = "Печать"
but.bind("<Button-2>",printer)
 
but.pack()
root.mainloop() 
