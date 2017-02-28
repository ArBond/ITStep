# Даны два целых числа A и B (при этом A ≤ B). Выведите все числа от A до B включительно.

a = int(input("Enter first number:"))
b = int(input("Enter second number:"))
if a > b:
    a, b = b, a
for i in range(a, b + 1, 1):
    print(i, end=" ")