# Дано положительное действительное число X. Выведите его дробную часть. Сделайте два вывода.

import math

number = float(input("Enter a number(>0): "))
while number < 0:
    number = float(input("Error!\nEnter a number(>0): "))
finalNumber = number - int(number)
qualityAll = (len(str(number)))
qualityEntire = (len(str(int(number))))
round(finalNumber, qualityAll - 2)
finalNumber *= 10 ** (qualityAll - qualityEntire - 1)
print("fraction:", int(finalNumber))