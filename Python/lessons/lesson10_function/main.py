def findFactorial(nubmer):
   if nubmer > 1:
        return nubmer * findFactorial(nubmer - 1)
   else:
       return 1

print(findFactorial(int(input("Vvedite chislo: "))))
