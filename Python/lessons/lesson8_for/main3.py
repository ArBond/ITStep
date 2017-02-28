# Даны два целых числа A и В, A>B. Выведите все нечётные числа от A до B включительно, в порядке убывания.
# В этой задаче можно обойтись без инструкции if.

a = int(input("Enter first number: "))
b = int(input("Enter second number(b < a): "))
while b > a:
    b = int(input("second number must be less then first: "))
for i in range(a + a % 2  - 1, b - 1, -2):
    print(i, end=" ")