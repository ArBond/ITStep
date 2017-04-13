from tkinter import *

root = Tk()

f_1=Frame(root,width=50,height=50,bg="Yellow")
f_2=Frame(root,width=50,height=50,bg="Blue")
f_3=Frame(root,width=50,height=50,bg="Green")
f_4=Frame(root,width=50,height=50,bg="Red")

# Размещение рамок

f_1.pack()
f_2.pack()
f_3.pack()
f_4.pack()

root.mainloop()
