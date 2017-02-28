# Дано 10 целых чисел. Вычислите их сумму. Напишите программу, использующую наименьшее число переменных.

print("Enter 10 numbers:")
sum = 0
for i in range (10):
    i += 1
    sum += int(input("#%i" % i+ ": "))
print("sum =", sum)