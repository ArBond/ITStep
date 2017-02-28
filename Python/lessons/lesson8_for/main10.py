# По данному натуральному n ≤ 9 выведите лесенку из n ступенек, i-я ступенька состоит из чисел от 1 до i без пробелов.

number = int(input("Enter a number(<10 and > 0): "))
while number > 9 or number < 1:
    number = int(input("Error!\nEnter a number(<10): "))

for i in range(1, number + 1, 1):
    for j in range(i):
        print("*", end="")
    print("\n", end="")