# рандом (от 1 до 100 как пример)

import time

def myRandom(leftBorder, rightBorder):
    time.sleep(0.001)
    a = time.time()
    b = id(a)
    a = int(a * 10 ** 6) % 10 ** 6
    number = (a + b) % (rightBorder - leftBorder) + leftBorder
    return number

for i in range(10):
    number = myRandom(1, 100)
    print(number)
