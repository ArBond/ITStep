# Дано несколько чисел. Вычислите их сумму. Сначала вводите количество чисел N, затем вводится ровно N целых чисел.
# Какое наименьшее число переменных нужно для решения этой задачи?

# 2 переменные

countNumbers = int(input("Enter a quantity of numbers: "))
while countNumbers < 0:
    countNumbers = int(input("Error!\nEnter a quantity of numbers: "))
sum = 0
for countNumbers in range(countNumbers):
    countNumbers -= 1
    sum += int(input("#: "))
print("sum =", sum)