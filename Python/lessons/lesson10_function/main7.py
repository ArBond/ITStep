#7.Напишите функцию fib(n), которая по данному целому неотрицательному n возвращает n-e число Фибоначчи.
# В этой задаче нельзя использовать циклы — используйте рекурсию.

def fib(n):
    if n <= 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)

n = int(input("Kakoje chislo chislo: "))
print(n, "-e chislo Fibonacchi =", fib(n))