#Zaprosit' u polzovatelja 3 chisla. Najti summu 1 i 3 chisla. Najti proizvedenie summy iz punkta 'a' na 2 chislo
#Najti srednee arifmeticheskoe 3 chisel
a = int(input("Vvedite 3 celyh chisla.\nchislo #1: "))
b = int(input("chislo #2: "))
c = int(input("chislo #3: "))
print("Summa 1 i 3 chilsa = ", a + c, "\nProizvedenije summy 1 i 3 chisla s 2 chislom = ", (a + c) * b,
      "\nSrednee arifmeticheskoe treh chisel = %.2f" % ((a + b + c) / 3))
input("Press Enter to continue...")