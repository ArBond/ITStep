'''

class yourFigures:

    color = 'red'
    form = 'circle'
    size = 'big'
    quantity = '3'

    def changeColor(self, newColor):
        self.color = newColor
    def changeForm(self, newForm):
        self.form = newForm
    def changeSize(self, newSize):
        self.size = newSize
    def changeQuantity(self, newQuantity):
        self.quantity = newQuantity

class figuresOfFriends:

    quantity = '0'

    def changeQuantity(self, newQuantity):
        self.quantity = newQuantity

you = yourFigures()
friend = figuresOfFriends()

print("You have " + you.quantity, you.size, you.color, you.form)
selection = int(input("1 - yes    0 - no\n"))
while selection > 1 or selection < 0:
    selection = int(input("1 - yes    0 - no\n"))

while (selection == 0):

    quantity = input("Enter quantity: ")
    you.changeQuantity(quantity)
    size = input("Enter size: ")
    you.changeSize(size)
    color = input("Enter color: ")
    you.changeColor(color)
    form = input("Enter form: ")
    you.changeForm(form)

    print("You have " + you.quantity, you.size, you.color, you.form)
    selection = int(input("1 - yes    0 - no\n"))
    while selection > 1 or selection < 0:
        selection = int(input("1 - yes    0 - no\n"))

print("You friend have " + friend.quantity + " figures. You gave your friend all figures")

friend.changeQuantity(you.quantity)
print("Now you friend have " + friend.quantity + " figures")

'''


class Critter(object):

    def __init__(self, name):
        print("A new critter has been born!")
        self.name = name

    def __str__(self):
        return "Hi's name " + self.name

    def talk(self):
        print("Hi!. I'm " + self.name + "!\n")

class Babies(object):

    def __init__(self, name, date):
        print("A new baby has been born!")
        self.name = name
        self.date = str(date)

    def __str__(self):
        return "Hi's name " + self.name + ". He was born: " + self.date

    def talk(self):
        print("Hi!. I'm " + self.name + "!\n")


crit1 = Critter("ABC")
print(crit1)
crit1.talk()

crit1 = Critter("Topchik")
print(crit1)
crit1.talk()

baby1 = Babies("Bob", 18.03)
print(baby1)
baby1.talk()

baby2 = Babies("Mark", 19.03)
print(baby2)
baby2.talk()
