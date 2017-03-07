# 6. Дано действительное положительное число a и целое неотрицательное число n.
# Вычислите an не используя циклы, возведение в степень через ** и функцию math.pow(),
# а используя рекуррентное соотношение a в степени n = a * a в степени n-1. Решение оформите в виде функции power(a, n).

def power(a, n):
    if n <= 1:
        return a
    else:
        return a * power(a, n - 1)

a = int(input("Vvedite chislo:"))
n = int(input("Vvedite stepen':"))
print(a, "^", n, "=", power(a, n))