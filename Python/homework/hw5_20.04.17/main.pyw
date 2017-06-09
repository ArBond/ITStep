from tkinter import*

class Buttons():

    def __init__(self):
        self.total = 0
        self.text1 = ""
        self.text2 = ""
        self.point = False
        self.print_textWindow()

    def print_textWindow(self):
        string1 = Label(mainWindow, text=self.text1, width=26, height=1, bg='white', font="arial 12", anchor="e")
        string1.place(x=15, y=40)
        string2 = Label(mainWindow, text=self.text2, width=20, height=1, bg='white', font="arial 16", anchor="e")
        string2.place(x=15, y=62)

    def click_number(self, number):
        self.text2 += str(number)
        self.print_textWindow()

    def click_point(self):
        if len(self.text2) > 0:
            if self.point == False and round(float(self.text2)) == float(self.text2):
                self.text2 += str(".")
                self.point = True
                self.print_textWindow()

    def click_deleteSymbol(self):
        if len(self.text2) > 0:
            if self.text2[len(self.text2) - 1] == ".":
                self.point = False
            self.text2 = self.text2[:len(self.text2) - 1]
            self.print_textWindow()

    def click_clear(self):
        self.text2 = ""
        self.point = False
        self.print_textWindow()

    def click_clearAll(self):
        self.__init__()

    def click_longOperation(self, operation):
        if len(self.text2) > 0:
            if self.text1 == "":
                self.text1 = self.text2 + operation
            else:
                self.click_total()
                self.text1 = str(self.total) + operation
            self.text2 = ""
            self.point = False
            self.print_textWindow()

    def click_total(self):
        if len(self.text1) > 0 and len(self.text2) > 0 and self.total != float(self.text2):
            number1 = float(self.text1[:len(self.text1) - 1])
            number2 = float(self.text2)
            operation = self.text1[len(self.text1) - 1]
            self.text1 = self.text1 + self.text2

            if operation == "+":
                self.text2 = str(number1 + number2)
            elif operation == "-":
                self.text2 = str(number1 - number2)
            elif operation == "*":
                self.text2 = str(number1 * number2)
            elif operation == "/":
                self.text2 = str(number1 / number2)
            else:
                self.text2 = str(number1 / 100 * number2)

            self.total = float(self.text2)

            self.print_textWindow()

    def click_changeValue(self):
        if len(self.text2) > 0:
            if self.text2[0] == "-":
                self.text2 = self.text2[1:]
            else:
                self.text2 = "-" + self.text2
            self.print_textWindow()

    def click_cqrt(self):
        if len(self.text2) > 0 and float(self.text2) > 0:
            self.text1 = "√" + self.text2
            self.text2 = str(pow(float(self.text2), 0.5))
            self.print_textWindow()
            self.total = float(self.text2)

    def click_revers(self):
        if len(self.text2) > 0:
            self.text1 = "1/" + self.text2
            self.text2 = str(1/float(self.text2))
            self.print_textWindow()
            self.total = float(self.text2)

mainWindow = Tk()
mainWindow.minsize(width = 280, height = 345)
mainWindow.maxsize(width = 280, height = 345)
mainWindow.title("Kuvalator")

backPhoto = PhotoImage(file = "fon.gif")
background = Canvas(mainWindow, width = 280, height = 345)
background.create_image(1, 1, anchor = NW, image = backPhoto)
background.place(x = -1,y = -1)

total = Buttons()

background.create_rectangle(15, 40 , 15+250, 40+55, outline = "gray", fill = "white")

numbers = "789456123"
i = 0
numbersButton = []

for j in range(1,4):
    for k in range(3):
        numbersButton.append(Button(mainWindow, text = numbers[i], width = 3, height = 1, font = "arial 14"))
        numbersButton[i].place(x = k * 50 + 15, y = j * 45 + 110)
        numbersButton[i]["command"] = lambda x=numbers[i]: total.click_number(x)
        i += 1

button_0 = Button(mainWindow, text = "0", width = 3, height = 1,  font = "arial 14")
button_0.place(x = 15, y = 290)
button_0["command"] = lambda: total.click_number("0")

button_00 = Button(mainWindow, text = "00", width = 3, height = 1,  font = "arial 14")
button_00.place(x = 65, y = 290)
button_00["command"] = lambda: total.click_number("00")

button_point = Button(mainWindow, text = ".", width = 3, height = 1,  font = "arial 14")
button_point.place(x = 115, y = 290)
button_point["command"] = lambda: total.click_point()

button_deleteSymbol = Button(mainWindow, text = chr(27), width = 3, height = 1,  font = "arial 14")
button_deleteSymbol.place(x = 15, y = 105)
button_deleteSymbol["command"] = lambda: total.click_deleteSymbol()

button_clear = Button(mainWindow, text = "c", width = 3, height = 1,  font = "arial 14")
button_clear.place(x = 65, y = 105)
button_clear["command"] = lambda: total.click_clear()

button_clearAll = Button(mainWindow, text = "ce", width = 3, height = 1,  font = "arial 14")
button_clearAll.place(x = 115, y = 105)
button_clearAll["command"] = lambda: total.click_clearAll()

button_add = Button(mainWindow, text = "+", width = 3, height = 1,  font = "arial 14")
button_add.place(x = 170, y = 155)
button_add["command"] = lambda: total.click_longOperation("+")

button_minus = Button(mainWindow, text = "-", width = 3, height = 1,  font = "arial 14")
button_minus.place(x = 170, y = 200)
button_minus["command"] = lambda: total.click_longOperation("-")

button_mult = Button(mainWindow, text = "*", width = 3, height = 1,  font = "arial 14")
button_mult.place(x = 170, y = 245)
button_mult["command"] = lambda: total.click_longOperation("*")

button_div = Button(mainWindow, text = "/", width = 3, height = 1,  font = "arial 14")
button_div.place(x = 170, y = 290)
button_div["command"] = lambda: total.click_longOperation("/")

button_perc = Button(mainWindow, text = "%", width = 3, height = 1,  font = "arial 14")
button_perc.place(x = 220, y = 155)
button_perc["command"] = lambda: total.click_longOperation("%")

button_total = Button(mainWindow, text = "=", width = 3, height = 3,  font = "arial 14")
button_total.place(x = 220, y = 246)
button_total["command"] = lambda: total.click_total()

button_changeValue = Button(mainWindow, text = "+/-", width = 3, height = 1,  font = "arial 14")
button_changeValue.place(x = 170, y = 105)
button_changeValue["command"] = lambda: total.click_changeValue()

button_cqrt = Button(mainWindow, text = "√", width = 3, height = 1,  font = "arial 14")
button_cqrt.place(x = 220, y = 105)
button_cqrt["command"] = lambda: total.click_cqrt()

button_revers = Button(mainWindow, text = "1/x", width = 3, height = 1,  font = "arial 14")
button_revers.place(x = 220, y = 200)
button_revers["command"] = lambda: total.click_revers()

mainWindow.mainloop()