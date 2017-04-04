class Animals():

    animalQuantity = 0

    def __init__(self, name):
        self.name = name
        Animals.animalQuantity += 1
        print(self.animalQuantity, ":", self.name, "вышел погулять:")

    def printName(self):
        print("I am", self.name + "!\n")

class Cats(Animals):

    def talk(self):
        print("Мяу!\n")

    def hiss(self):
        print("ш-ш-ш-ш!\n")

class Dogs(Animals):

    def talk(self):
        print("Гав!\n")

    def roal(self):
        print("р-р-р-р\n")

    def backTo(self, object):
        print("Гав!")
        object.hiss()


dog1Name = input("Как зовут вашу собаку: ")
dog1 = Dogs(dog1Name)
dog1.printName()

print("Собака споткнулась.")
dog1.roal()

cat1Name = input("Как зовут вашего кота: ")
cat1 = Cats(cat1Name)
cat1.printName()

print("Собака гавкнула на кота.")
dog1.backTo(cat1)
print("Кот споткнулся.")
cat1.talk()
print("Cобака отобрала сосиску у кота")
cat1.hiss()
dog1.backTo(cat1)

cat2Name = input("Вы ызяли еще 1 кота кота. Как вы его назовете: ")
cat2 = Cats(cat2Name)
cat2.printName()



#Напишите программу, запрашивающую у пользователя ввод числа. Если число принадлежит диапазону от -100 до 100,
#то создается объект одного класса, во всех остальных случаях создается объект другого класса. В обоих классах должен
#быть метод-конструктор __init__, который в первом классе возводит число в квадрат, а во-втором - умножает на два.

#Напишите программу, высчитывающую площадь оклейки обоями комнаты. Объектами являются: стены, потолки, окна и двери.
