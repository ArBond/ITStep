li = ["red","green"]
def color(event):
     fra.configure(bg=li[0])
     li[0],li[1] = li[1],li[0]
 
def outgo(event):
     root.destroy()
 
from tkinter import *
root = Tk()
 
fra = Frame(root,
            width=100,
            height=100)
but = Button(root,
             text="Выход")
 
fra.pack()
but.pack()
 
root.bind("<Return>",color)
but.bind("<Button-1>",outgo)
 
root.mainloop()
