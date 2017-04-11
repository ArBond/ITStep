from tkinter import *
 
root = Tk()

#Полоса прокрутки
text = Text(root, height=5, width=60)
text.pack(side='left')
scrollbar = Scrollbar(root)
scrollbar.pack(side='left')
# первая привязка
scrollbar['command'] = text.yview
# вторая привязка
text['yscrollcommand'] = scrollbar.set
root.mainloop()

#Окно верхнего уровня

win = Toplevel(root,
               relief = SUNKEN,
               bd = 10,
               bg = "lightblue")
win.title("Дочернее окно")
win.minsize(width = 400, height = 200) 

root.mainloop() 
