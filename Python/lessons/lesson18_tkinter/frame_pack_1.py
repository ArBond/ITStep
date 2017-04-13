from tkinter import *

root = Tk()

f_1=Frame(root,width=70,height=100,bg="Green")
f_2=Frame(root,width=70,height=100,bg="White")
f_3=Frame(root,width=70,height=100,bg="Red")

# Размещение рамок горизонтально
# Возможные параметры side: LEFT, RIGHT, TOP, BOTTOM
f_1.pack(side=LEFT)
f_2.pack(side=LEFT)
f_3.pack(side=LEFT)

root.mainloop()
