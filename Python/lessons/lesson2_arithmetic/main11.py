# N chelovek snimajut kvartiry na leto. 50% iz nih zhivet nedelju, 40 % - 15 dnej, a ostalnyje po 20 dnej.
#Oplata prozhivanija za 1 den' rava x ryb. Skolko nalogov zaplatjat hozjaeva,esli oni sostavljajut 13 proc vyrichki.

print("Poschitaem zakonoposlushnym grazhdaninam RB nalogi=)")
n = int(input("Skolko chelovek snimajut kvartiry na leto: "))
x = float(input("Skolko stoit 1 den' prozhivanija: "))
dohod = (round(n * 0.5) * 7 + round(n * 0.4) * 15 + (n - round(n * 0.5) - round(n * 0.4)) * 20) * x
print("Vash dohod za leto sostavit", dohod, "rub\nVam pridetsja zaplatit' %.2f" % (dohod * 0.13), "rub naloga")
input("Press Enter to continue...")