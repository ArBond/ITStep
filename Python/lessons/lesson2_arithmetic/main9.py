#Na koncerte pevicy bylo A % otdyhajushih v sanatorii, na vystuplenii hora d 1.5 raz bolshe.
#Skolko zritelej pobyvalo na etih koncertah v obshem, esli v sanatorii otdyhalo x chelovek.
x = int(input("Skolko chelovek otdyhalo v sanatorii?\n"))
a = int(input("kakoj procent zritele prishel na koncert pevicy?\n"))
print("Na koncert pevicy prislo ", int(x * a / 100) ,"zritelej\nNa koncert hora ", int(1.5 * x * a / 100), "zritelej\nVsego: ",
      int(x * a / 100 ) + int(1.5 * x * a / 100), "zritelej")
input("Press Enter to continue...")