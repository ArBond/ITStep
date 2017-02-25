#Кубики. Версия 1.0

import random

#Меню и выбор игры
print("Kubiki!\n")
print("Menu:\n 1 - igrat' odnomy\n 2 - igrat' s komp'juterom\n 3 - igrat' s drugom\n 0 -  vyjti")
gameSelection = int(input("Kak budete igrat'?\n# "))
while gameSelection > 3 or gameSelection < 0:
    gameSelection = int(input("Takogo varianta netu!\n# "))


#Игра с собой
if gameSelection == 1:
    gamerName = input("Vvedite vashe imja: ")


# Игра с компом
elif gameSelection == 2:

    # Сбор инфы для начала игры
    gamerName = input("Vvedite vashe imja: ")
    gamerDeposit = int(input("Vvedite vash depozit($): "))
    computerDeposit = random.randint(1000, 2000)
    print("Kompjuter vzjal s soboj", computerDeposit, "$")

    # Начинаем играть
    while gamerDeposit > 0 or computerDeposit > 0:
        gamerNumber = int(input("Na kakoe chislo stavite, %s?" % gamerName))
        while gamerNumber > 12 or gamerNumber < 2:
            gamerNumber = int(input("Takoj summy ne mozhet vypast'\n"))
        gamerBet = int(input("Vasha stavka($):"))
        while gamerBet > gamerDeposit:
            gamerBet = int(input("Vy ne mozhete postavit' bolshe chem u vas est'\n"))
        gamerDeposit -= gamerBet
        computerNumber = random.randint(2, 12)
        computerBet = random.randint(10, 200)
        while computerBet > computerDeposit:
            if computerDeposit < 20:
                computerBet = computerDeposit
                break
            else:
                computerBet = random.randint(10, 200)
        computerDeposit -= computerBet
        print("Kompjuter postavil", computerBet, "$ na chislo", computerNumber)
        side1 = random.randint(1, 6)
        side2 = random.randint(1, 6)
        sum = side1 + side2
        print("Vypalo: ", sum)
        if computerNumber == sum and gamerNumber == sum:
            print("Pozdravljzju, vy oba ugadali!")
            gamerDeposit += gamerBet * 3
            computerDeposit += computerBet * 3
            print("Vash vyigrysh: ", gamerBet * 3, "$\nvyigrysh compjutera: ", computerBet * 3, "$")
        elif computerNumber == sum:
            print("Compjuter ugadal.")
            computerDeposit += computerBet * 3
            print("Vyigrysh compjutera: ", computerBet * 3, "$")
        elif gamerNumber == sum:
            print("Pozdravljzju, vy ugadali!")
            gamerDeposit += gamerBet * 3
            print("Vash vyigrysh: ", gamerBet * 3, "$")
        else:
            print("Stavki ne sygrali\n")
            gamerDeposit += gamerBet / 2
            computerDeposit += computerBet / 2
        toContinue = int(input(" 1 - prodolzhit'\n 0 - vyjti"))
        while toContinue > 1 or toContinue < 0:
            toContinue = int(input("Takogo varianta netu!\n# "))
        if toContinue == 0:
            break
    if computerDeposit == 0:
        print("U kompjutera zakonchilis' dengi\nVy POBEDILI!!")
    else:
        print("U vas zakonchilis' dengi\nKompjuter pobedil")


# Игра с другом
elif gameSelection == 3:
    gamer1 = input("igrik 1.\nVvedite vashe imja: ")
    deposit1 = int(input("Vvedite vash depozit($): "))
    gamer2 = input("igrok 2.\nVvedite vashe imja: ")
    deposit2 = int(input("Vvedite vash depozit($): "))

# выход
else:
    print("Vsego horoshego!\n")
