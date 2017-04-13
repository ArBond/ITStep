from tkinter import *
def b1(event):
     root.title("Левая кнопка мыши")
def b3(event):
     root.title("Правая кнопка мыши")
def move(event):
     root.title("Движение мышью")
 
root = Tk()
root.minsize(width = 500, height=400)
root.maxsize(width = 500, height=400)
 
root.bind('<Button-1>',b1)
root.bind('<Button-3>',b3)
root.bind('<Motion>',move)
 
root.mainloop() 
