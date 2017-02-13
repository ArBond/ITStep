#Vychislit' zarplatu rabochego za X dnej, esli on poluchaet fiksirovannyj zarobotok za 1 den'
ZAROBOTOK_V_DEN = int(input("Skolko poluchat rabochij v den'($)?\n"))
x = int(input("Skolko dnej rabotal?\n"))
print("Zarplata rabochego za ", x ,"dnej = ", ZAROBOTOK_V_DEN * x, "$")
input("Press Enter to continue...")