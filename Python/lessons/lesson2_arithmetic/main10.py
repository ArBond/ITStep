#Avtobus provozit 50 passazhirov. Iz nih 10 edut do pervoj ostanovki, 20 - do vtoroj,a ostal'nyje do konecnoj.
#Stoimost' biletov do kazhdoj stancii sootvetstvenno ravno a, b, c. Skolko rejsov dolzhen sdelat' avtobus,
#chtoby vyruchka sostavila k rub.
a = float(input("Skol'ko stoit bilet do pervij stancii(BUN): "))
b = float(input("Do vtoroj(BUN): "))
c = float(input("Do konechnoj(BUN): "))
k = float(input("Kakaja dolzhna but' vyrucka(BUN): "))
n = k / (10 * a + 20 * b + 20 * c)
print("Avtobusu nado sdelat", round(n + 0.5) , "rejsa(ov) chtopy vyrucka sostavila", k, "BUN")
print("Press Enter to continue...")