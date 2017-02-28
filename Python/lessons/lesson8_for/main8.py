# По данному натуральном n вычислите сумму 1!+2!+3!+...+n!. В решении этой задачи можно использовать только один цикл.

number = int(input("Enter a number: "))
total = 1
if number == 0:
    total = 0
for i in range(number, 1, -1):
    total *= total * i
print(number, "! = ", total)