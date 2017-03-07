import random

lowLow = 0
low = 0
mid = 0
high = 0
highHigh = 0

for i in range(100):
    num = random.randint(0, 100)
    if num < 20:
        lowLow += 1
    elif num < 40:
        low += 1
    elif num < 60:
        mid += 1
    elif num < 80:
        high += 1
    else:
        highHigh += 1

print("(1-19)   ", lowLow, "    (20-39)    ", low, "    (40-59)   ", mid, "   (60-79)   ", high, "   (80-100)   ", highHigh)