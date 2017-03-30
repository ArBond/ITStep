'''

Нужно написать программу "Автомобиль". В программе может быть один или несколько классов, в каждом из которых прописаны
необходимые атрибуты и методы. Объект Автомобиль должен иметь необходимый функционал:
(Напрмиер)
1. Зажигание
2. Езда
3. Тормоз
4. Остановка двигателя
5. Включение фар
6. Открытие и закрытие дверей

Функциональность Автомобиля должна соответствовать логике, т.е. например, нельзя завести автомобиль два раза подрят.
Нельзя начать езду если нажат тормоз и так далее.

'''

class Car():

    inCar = False
    ignition = False
    go = False
    headLight = False
    doors = False
    handbrake = False


    def __init__(self):
        print("Im a cuvaldaCar! Please move me.")

    def GoToCar(self, action):
        if action == 'goIn':
            if self.inCar == True:
                print("Вы уже сидите")
            elif self.doors == False:
                print("Сначала откройте дверь")
            else:
                self.inCar = True
                print("Вы сели в машину")
        else:
            if self.inCar == False:
                print("Вы не в машине")
            elif self.go == True:
                print("Нужно остановиться и открвть двери")
            elif self.doors == False:
                print("Нужно окрыть двери")
            else:
                self.inCar = False
                print("Вы вышли")

    def ChangeIgnition(self, action):
        if action == 'on':
            if self.ignition == True:
                print("Двигатель уже заведен")
            elif self.inCar == False:
                print("Вы не в машине")
            else:
                self.ignition = True
                print("Двигатель заведен")
        else:
            if self.ignition == False:
                print("Двигатель уже заглушен")
            elif self.inCar == False:
                print("Вы не в машине")
            else:
                self.ignition = False
                print("Двигатель заглушен")

    def ChangeHandbrake(self, action):
        if action == 'on':
            if self.handbrake == True:
                print("Машина уже на ручнике")
            elif self.inCar == False:
                print("Вы не в машине")
            elif self.go == True:
                choice = int(input("Вы движетесь! Вы точно хотите это сделать?\n 1 - да   2 - нет\n"))
                if choice == 1:
                    self.handbrake = True
            else:
                self.handbrake = True
                print("Машина поставлена на ручник")
        else:
            if self.handbrake == False:
                print("Машина не на ручнике")
            elif self.inCar == False:
                print("Вы не в машине")
            else:
                self.handbrake = False
                print("Машина снята с ручника")





superCar = Car()
while True:
    selection = int(input(" 1 - сесть/выйти\n 2 - зажигание\n 3 - ручник\n 4 - движение\n 5 - фары\n 6 - двери\n 0 - закончить\n"))
    if selection == 1:
        action = int(input(" 1 - сесть\n 2 - выйти\n"))
        if action == 1:
            superCar.GoToCar('goIn')
        else:
            superCar.GoToCar('goOut')
    elif selection == 2:
        action = int(input(" 1 - завести двигатель\n 2 - заглушить двигатель\n"))
        if action == 1:
            superCar.ChangeIgnition('on')
        else:
            superCar.ChangeIgnition('off')
    elif selection == 3:
        action = int(input(" 1 - поставить на ручник\n 2 - снять с ручника\n"))
        if action == 1:
            superCar.GoToCar('on')
        else:
            superCar.GoToCar('off')
    else:
        break
    if superCar.handbrake == True and superCar.go == True:
        print("Вы попали в аварию")
        break

'''
    elif selection == 4:

    elif selection == 5:
        action = int(input(" 1 - включить фары\n 2 - выключить фары\n"))
    elif selection == 6:
'''
