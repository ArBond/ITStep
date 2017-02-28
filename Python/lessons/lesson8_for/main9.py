# Дано N чисел: сначала вводится число N, затем вводится ровно N целых чисел.
# Подсчитайте количество нулей среди введенных чисел и выведите это количество.
# Вам нужно подсчитать количество чисел, равных нулю, а не количество цифр.

countNumbers = int(input("Enter a quantity of numbers: "))
while countNumbers < 0:
    countNumbers = int(input("Error!\nEnter a quantity of numbers: "))
nullCounter = 0
for i in range(countNumbers):
    i += 1
    number = int(input("#%i" %(i + 1), ": "))
    if(number == 0):
        nullCounter += 1
print(nullCounter)