# 1. Напишите функции уравнений:
#    - x в степени 4 + 4 в степени x,
#    - y в степени 4 + 4 в степени x

def ur1(x):
    return x ** 4 + 4 ** x

def ur2(x, y):
    return y ** 4 + 4 ** x

x = int(input("Vvedite 2 chisla:\n #1: "))
y = int(input(" #2: "))
print("Rezultat 1 uravnenija =", ur1(x))
print("Rezultat 2 uravnenija =", ur2(x, y))