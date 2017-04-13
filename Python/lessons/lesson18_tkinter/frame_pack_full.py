from tkinter import *

# Виджеты
root = Tk() # окно
root.title("Вставка строки")

f_1=Frame(root) # рамки
f_2=Frame(root)
f_11=Frame(f_1)
f_12=Frame(f_1)
f_13=Frame(f_1)

l_in=Label(f_11,text="Вставить --------------------") # метки
l_num=Label(f_12,text="Кол-во                         ")
l_pos=Label(f_13,text="Положение -----------------")

e_num=Entry(f_12, width=5, bg="White") # текстовое поле

pos = IntVar() # радиокнопки
pos.set(0)
r_pos1=Radiobutton(f_13,text="До ", variable=pos, value=0)
r_pos2=Radiobutton(f_13,text="После ", variable=pos, value=1)

b_ok=Button(f_2,text="OK", width=10) # Кнопки
b_canc=Button(f_2,text="Отмена", width=10)
b_help=Button(f_2,text="Справка", width=10)

# Размещение виджетов
f_1.pack(side=LEFT)
f_2.pack(side=LEFT,fill=Y)
f_11.pack()
f_12.pack()
f_13.pack()

l_in.pack()
l_num.pack(side=LEFT)
e_num.pack(side=LEFT)
l_pos.pack()
r_pos1.pack()
r_pos2.pack()

b_ok.pack()
b_canc.pack()
b_help.pack(side=BOTTOM)

root.mainloop()
