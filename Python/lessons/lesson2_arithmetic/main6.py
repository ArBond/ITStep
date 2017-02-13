#Uznat' radius kruga i napechatat' diametr, ploshad' i dlinnu okr kruga
PI = 3.14
r = float(input("Vvedite radius kruga(sm): "))
print("diametr kruga = ", r * 2, "sm\nploshad' = %.2f" % (PI * r * r), "sm\ndlinna okr = %.2f" % (2 * PI * r), "sm")
input("Press Enter to continue...")