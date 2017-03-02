# Дано положительное действительное число X. Выведите его первую цифру после десятичной точки.

number = float(input("Enter a number(>0): "))
while number < 0:
    number = float(input("Error!\nEnter a number(>0): "))
finalNumber = int((number - int(number))*10)
print("First number after point:", finalNumber)
