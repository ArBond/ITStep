# Кости
# Демонстрируем рандомную генерацию чисел

import random

# генерируем числа рандомно 1 - 6
a = random.randint(1, 6)
b = random.randrange(6) + 1

total = a + b

print("Первая кость:", a, "Вторая кость:", b, "В сумме:", total)

input("\n\nPress the enter key to exit.")
