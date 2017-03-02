#Пирожок в столовой стоит a рублей и b копеек. Определите, сколько рублей и копеек нужно заплатить за n пирожков.
#Программа получает на вход три числа: a, b, n, и должна вывести два числа: стоимость покупки в рублях и копейках.

rub = int(input("Сколько стоит пирожок(руб. коп)\nруб: "))
while rub < 0:
    rub = int(input("Ошибка!\nруб: "))
cop = int(input("коп: "))
while cop > 99 or cop < 0:
    cop = int(input("Ошибка!\nкоп: "))
quality = int(input("Сколько пирожков покупаете: "))
while quality < 0:
    quality = int(input("Ошибка!\nСколько пирожков покупаете: "))
totalCost = quality * cop * rub * 100
costInCop = totalCost - costInRub * 100
print(costInCop)