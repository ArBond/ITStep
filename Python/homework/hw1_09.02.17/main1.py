#1 Кредитование
#Создать прогшрамму которая посчитает кредит для потребителя по формуле
#Month = (Summ * Proc * (1 + Proc)Years) / (12 * ((1 + Proc)Years – 1))
#Где:
#Month - размер месячной выплаты;
#Summ - сумма займа (кредита);
#Proc - процент банка, выраженный в долях единицы (т. е. если 20%, то будет 0.2).
#Years - количество лет, на которые берется займ.
#All - сумма выплат за весь период кредитования.

print("Davajte poschitaem dlja vas kredit!")
summ = int(input("Skolko deneg hotite vzjat'(BUN): "))
proc = int(input("Pod kakoj procent vam ih dajut: "))
years = int(input("Na skolko berete: "))
month = (summ * proc / 100 * (1 + proc / 100) * years) / (12 * ((1 + proc / 100)* years - 1))
print("Vash mesjachnyj platezh coctavit: %.2f" % month, "(BUN)")
print("Za ves' period vy zaplatite: %.2f" % (month * 12 * years), "(BUN)")
input("Press Enter to continue...")