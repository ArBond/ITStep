# 4. Дано действительное положительное число a и целоe число n. Вычислите an.
# Решение оформите в виде функции power(a, n). Стандартной функцией возведения в степень пользоваться нельзя.

def power(a, n):
    rez = 1
    for i in range(n):
        rez *= a
    print(a, "^", n, ":", rez)

a = int(input("Vvedite chislo: "))
n = int(input("Vvedite stepen': "))
power(a, n)