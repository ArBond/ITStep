from tkinter import*

class Buttons():

    def __init__(self):
        self.total = 0

    def click_number(self, number):
        print(number)

    def click0(self):
    



mainWindow = Tk()
mainWindow.minsize(width = 280, height = 345)
mainWindow.maxsize(width = 280, height = 345)
mainWindow.title("Kuvalator")

backPhoto = PhotoImage(file = "E:\start screen.gif")
background = Canvas(mainWindow, width = 280, height = 345)
background.create_image(1, 1, anchor = NW, image = backPhoto)
background.place(x = -2,y = -2)

text1 = " "
text2 = "0"

total = Buttons()

string1=Label(mainWindow, text = text1, width = 26, height = 1, bg = 'white', font = "arial 12", anchor = "e")
string1.place(x = 15, y = 40)

string2=Label(mainWindow, text = text2, width = 20, height = 1, bg = 'white', font = "arial 16", anchor = "e")
string2.place(x = 15, y = 62)

background.create_rectangle(15, 40 , 15+250, 40+55, outline = "gray", fill = "white")

numbers = "789456123"
i = 0
numbersButton = []

for j in range(1,4):
    for k in range(3):
        numbersButton.append(Button(mainWindow, text = numbers[i], width = 3, height = 1, font = "arial 14"))
        numbersButton[i].place(x = k * 50 + 15, y = j * 45 + 110)
#        numbersButton[i].bind("<ButtonPress-3", total.click_number(i))
        numbersButton[i]["command"] = lambda x=numbers[i]: total.click_number(x)
        i += 1

button_DeleteSymbol = Button(mainWindow, text = chr(27), width = 3, height = 1,  font = "arial 14")
button_DeleteSymbol.place(x = 15, y = 105)

button_Clear = Button(mainWindow, text = "c", width = 3, height = 1,  font = "arial 14")
button_Clear.place(x = 65, y = 105)

button_ClearAll = Button(mainWindow, text = "ce", width = 3, height = 1,  font = "arial 14")
button_ClearAll.place(x = 115, y = 105)

button_0 = Button(mainWindow, text = "0", width = 3, height = 1,  font = "arial 14")
button_0.place(x = 15, y = 290)

button_00 = Button(mainWindow, text = "00", width = 3, height = 1,  font = "arial 14")
button_00.place(x = 65, y = 290)

button_point = Button(mainWindow, text = ".", width = 3, height = 1,  font = "arial 14")
button_point.place(x = 115, y = 290)

button_changeValue = Button(mainWindow, text = "+/-", width = 3, height = 1,  font = "arial 14")
button_changeValue.place(x = 170, y = 105)

button_add = Button(mainWindow, text = "+", width = 3, height = 1,  font = "arial 14")
button_add.place(x = 170, y = 155)

button_minus = Button(mainWindow, text = "-", width = 3, height = 1,  font = "arial 14")
button_minus.place(x = 170, y = 200)

button_mult = Button(mainWindow, text = "*", width = 3, height = 1,  font = "arial 14")
button_mult.place(x = 170, y = 245)

button_div = Button(mainWindow, text = "/", width = 3, height = 1,  font = "arial 14")
button_div.place(x = 170, y = 290)

button_cqrt = Button(mainWindow, text = "cqrt", width = 3, height = 1,  font = "arial 14")
button_cqrt.place(x = 220, y = 105)

button_perc = Button(mainWindow, text = "%", width = 3, height = 1,  font = "arial 14")
button_perc.place(x = 220, y = 155)

button_revers = Button(mainWindow, text = "1/x", width = 3, height = 1,  font = "arial 14")
button_revers.place(x = 220, y = 200)

button_total = Button(mainWindow, text = "=", width = 3, height = 3,  font = "arial 14")
button_total.place(x = 220, y = 246)


mainWindow.mainloop()



'''
from tkinter import *

class Calc():
    def __init__(self):
        self.total = 0
        self.current = ""
        self.new_num = True
        self.op_pending = False
        self.op = ""
        self.eq = False

    def num_press(self, num):
        self.eq = False
        temp = text_box.get()
        temp2 = str(num)
        if self.new_num:
            self.current = temp2
            self.new_num = False
        else:
            if temp2 == '.':
                if temp2 in temp:
                    return
            self.current = temp + temp2
        self.display(self.current)

    def calc_total(self):
        self.eq = True
        self.current = float(self.current)
        if self.op_pending == True:
            self.do_sum()
        else:
            self.total = float(text_box.get())

    def display(self, value):
        text_box.delete(0, END)
        text_box.insert(0, value)

    def do_sum(self):
        if self.op == "add":
            self.total += self.current
        if self.op == "minus":
            self.total -= self.current
        if self.op == "times":
            self.total *= self.current
        if self.op == "divide":
            self.total /= self.current
        self.new_num = True
        self.op_pending = False
        self.display(self.total)

    def operation(self, op):
        self.current = float(self.current)
        if self.op_pending:
            self.do_sum()
        elif not self.eq:
            self.total = self.current
        self.new_num = True
        self.op_pending = True
        self.op = op
        self.eq = False

    def cancel(self):
        self.eq = False
        self.current = "0"
        self.display(0)
        self.new_num = True

    def all_cancel(self):
        self.cancel()
        self.total = 0

    def sign(self):
        self.eq = False
        self.current = -(float(text_box.get()))
        self.display(self.current)

sum1 = Calc()
root = Tk()
calc = Frame(root)
calc.grid()

root.title("Calculator")
text_box = Entry(calc, justify=RIGHT)
text_box.grid(row = 0, column = 0, columnspan = 3, pady = 5)
text_box.insert(0, "0")

numbers = "789456123"
i = 0
bttn = []

for j in range(1,4):
    for k in range(3):
        bttn.append(Button(calc, text = numbers[i]))
        bttn[i].grid(row = j, column = k, pady = 5)
        bttn[i]["command"] = lambda x = numbers[i]: sum1.num_press(x)
        i += 1

bttn_0 = Button(calc, text = "0")
bttn_0["command"] = lambda: sum1.num_press(0)
bttn_0.grid(row = 4, column = 1, pady = 5)

bttn_div = Button(calc, text = chr(247))
bttn_div["command"] = lambda: sum1.operation("divide")
bttn_div.grid(row = 1, column = 3, pady = 5)

bttn_mult = Button(calc, text = "x")
bttn_mult["command"] = lambda: sum1.operation("times")
bttn_mult.grid(row = 2, column = 3, pady = 5)

minus = Button(calc, text = "-")
minus["command"] = lambda: sum1.operation("minus")
minus.grid(row = 3, column = 3, pady = 5)

point = Button(calc, text = ".")
point["command"] = lambda: sum1.num_press(".")
point.grid(row = 4, column = 0, pady = 5)

add = Button(calc, text = "+")
add["command"] = lambda: sum1.operation("add")
add.grid(row = 4, column = 3, pady = 5)

neg= Button(calc, text = "+/-")
neg["command"] = sum1.sign
neg.grid(row = 5, column = 0, pady = 5)

clear = Button(calc, text = "C")
clear["command"] = sum1.cancel
clear.grid(row = 5, column = 1, pady = 5)

all_clear = Button(calc, text = "AC")
all_clear["command"] = sum1.all_cancel
all_clear.grid(row = 5, column = 2, pady = 5)

equals = Button(calc, text = "=")
equals["command"] = sum1.calc_total
equals.grid(row = 5, column = 3, pady = 5)

root.mainloop()
'''
