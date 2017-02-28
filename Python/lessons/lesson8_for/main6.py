# По данному натуральном n вычислите сумму 13+23+33+...+n3.

number = int(input("Enter a number: "))
sum = 0
for number in range(number, 0, -1):
    sum += 10 * number + 3
print("sum =", sum)