#Длина Московской кольцевой автомобильной дороги —109 километров.
#Байкер Вася стартует с нулевого километра МКАД и едет со скоростью v километров в час.
#На какой отметке он остановится через t часов?

import math

LENGTH = 109
speed = int(input("Enter a Vasya's speed: "))
time = int(input("Enter a Vasya's time: "))
while time < 0:
    time = int(input("Error!\nEnter a Vasya's time: "))
distance = time * speed - math.floor(time * speed / LENGTH) * LENGTH
print("Vasya will be stayted at", distance, "km.")