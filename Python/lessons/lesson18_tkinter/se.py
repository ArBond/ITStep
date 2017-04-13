from tkinter import *

root = Tk() # окно
root.title("Вставка строки")

f_1 = Frame(root,width = 50, height = 50,bg = 'green')
f_2 = Frame(root,width = 50, height = 50, bg = 'blue')
f_3 = Frame(root,width = 50, height = 50, bg = 'red')
f_4 = Frame(root,width = 50, height = 50, bg = 'yellow')
f_5 = Frame(root,width = 50, height = 50, bg = 'gray')
f_6 = Frame(root,width = 50, height = 50, bg = 'orange')
f_7 = Frame(root,width = 50, height = 50, bg = 'black')
f_8 = Frame(root,width = 50, height = 50, bg = 'white')

f_1.grid(row=0,column=0)
f_2.grid(row=1,column=0)
f_3.grid(row=2,column=0)
f_4.grid(row=2,column=1)
f_5.grid(row=2,column=2)
f_6.grid(row=0,column=1,columnspan=1, rowspan=1)
f_7.grid(row=0,column=2)
f_8.grid(row=1,column=2)

root.mainloop()

