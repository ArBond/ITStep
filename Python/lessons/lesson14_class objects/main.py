'''

class Critter(object):

    quantity = 0

    def status(self):
        print("Total quantity", Critter.quantity)

    def __init__(self, name, mood):
        Critter.quantity += 1
        print("\n", Critter.quantity, "critter has been born!")
        self.name = name
        self.__mood = mood

    def talk(self):
        print("Hi!. I'm " + self.name)
        print("Now I feel", self.__mood)

    def __privat(self):
        print("This is a privat method")

    def public(self):
        print("This is a public method")
        self.__privat()

class Babies(object):

    def __init__(self, name, date):
        print("\nA new baby has been born!")
        self.name = name
        self.__date = date

    def __str__(self):
        return "Hi's name " + self.name

    def __date(self):
        print("He was born: " + self.__date)

    def talk(self):
        print("Hi!. I'm " + self.name)

print(Critter.quantity)

critter1 = Critter("Bobik", "happy")
critter1.talk()
critter1.public()

critter2 = Critter("Sharik", "happy")
critter2.talk()
critter2.public()

print(Critter.quantity)

baby1 = Babies("Bob", "23.03")
print(baby1)
baby1.talk()

baby2 = Babies("Garry", "24.03")
print(baby2)
baby2.talk()
'''

import time

class Critter(object):
    """A virtual pet"""

    def __init__(self, name, hunger=0, boredom=0):
        self.name = name
        self.hunger = hunger
        self.boredom = boredom

    def __pass_time(self):
        self.hunger += 1
        self.boredom += 1

    @property
    def mood(self):
        unhappiness = self.hunger + self.boredom
        if unhappiness < 5:
            m = "happy"
        elif 5 <= unhappiness <= 10:
            m = "okay"
        elif 11 <= unhappiness <= 15:
            m = "frustrated"
        else:
            m = "mad"
        return m

    def talk(self):
        print("I'm", self.name, "and I feel", self.mood, "now.\n")
        self.__pass_time()

    def eat(self, food_quantity):
        print("Feeding...")
        time.sleep(food_quantity)
        print("Brruppp.  Thank you.")
        self.hunger -= food_quantity * 3
        if self.hunger < 0:
            self.hunger = 0
        self.__pass_time()

    def play(self, fun_time):
        print("Playing...")
        time.sleep(fun_time)
        print("Wheee!")
        self.boredom -= fun_time * 3
        if self.boredom < 0:
            self.boredom = 0
        self.__pass_time()


def main():
    crit_name = input("What do you want to name your critter?: ")
    crit = Critter(crit_name)

    choice = None
    while choice != "0":
        print \
            ("""
        Critter Caretaker

        0 - Quit
        1 - Listen to your critter
        2 - Feed your critter
        3 - Play with your critter
        """)

        choice = input("Choice: ")
        print()

        # exit
        if choice == "0":
            print("Good-bye.")

        # listen to your critter
        elif choice == "1":
            crit.talk()

        # feed your critter
        elif choice == "2":
            food_quantity = input("How much you feed:\n1 - few   2 - moderately  3 - many\n")
            while food_quantity > '3' or food_quantity < '1':
                food_quantity = input("1 - few   2 - moderately  3 - many\n")
            crit.eat(int(food_quantity))

        # play with your critter
        elif choice == "3":
            fun_time = input("How long you played:1 - few   2 - moderately  3 - many\n")
            while fun_time > '3' or fun_time < '1':
                fun_time = input("1 - few   2 - moderately  3 - many\n")
            crit.play(int(fun_time))

        # some unknown choice
        else:
            print("\nSorry, but", choice, "isn't a valid choice.")


main()
input("\n\nPress the enter key to exit.")
