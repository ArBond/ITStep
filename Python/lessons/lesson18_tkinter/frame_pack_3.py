from tkinter import *

root = Tk()

f_1=Frame(root,width=50,height=50,bg="Yellow")
f_2=Frame(root,width=50,height=50,bg="Blue")
f_3=Frame(root,width=50,height=50,bg="Green")
f_4=Frame(root,width=50,height=50,bg="Red")

# Сложный вариант
 	
f_1.pack(side=LEFT)
f_2.pack(side=RIGHT)
f_3.pack(side=TOP)
f_4.pack(side=BOTTOM)

root.mainloop()
