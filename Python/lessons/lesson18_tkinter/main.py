from tkinter import*

mainWindow = Tk()
mainWindow.minsize(width = 400, height=460)
mainWindow.maxsize(width = 400, height=460)
mainWindow.title("Калькулятор")

backPhoto = PhotoImage(file="E:\start screen.gif")
background = Canvas(mainWindow, width=400, height=460)
background.create_image(1,1,anchor=NW,image=backPhoto)
background.place(x=-2,y=-2)

mainWindow.mainloop()
