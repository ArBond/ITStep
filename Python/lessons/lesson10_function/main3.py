# 3. Даны четыре действительных числа: x1, y1, x2, y2.
# Напишите функцию distance(x1, y1, x2, y2), вычисляющая расстояние между точкой (x1,y1) и (x2,y2).
# Считайте четыре действительных числа и выведите результат работы этой функции. Используйте теорему Пифагора.

import math
def findDistance(x1, y1, x2, y2):
    distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    print("distance:", distance)

x1 = int(input("Najdem rasstojznije ot A do B.\nVvedite koordinaty tochki A.\n x: "))
y1 = int(input(" y: "))
x2 = int(input("A teper' tochki B.\n x: "))
y2 = int(input(" y: "))
findDistance(x1, y1, x2, y2)