# Факториалом числа n называется произведение 1 × 2 × ... × n. Обозначение: n!.
# По данному натуральному n вычислите значение n!.

number = int(input("Enter a number: "))
total = 1
if number == 0:
    total = 0
for i in range(number, 1, -1):
    total *= i
print(number, "! = ", total)