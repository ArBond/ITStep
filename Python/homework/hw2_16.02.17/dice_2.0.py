#Кубики. Версия 2.0

import random

#Меню и выбор игры
print("Kubiki!\n")
print("Menu:\n  1 - igrat' odnomy\n  2 - igrat' s komp'juterom\n  3 - igrat' s drugom\n  0 - vyjti")
gameSelection = int(input("# "))
while gameSelection > 3 or gameSelection < 0:
    gameSelection = int(input("Takogo varianta netu!\n # "))


#Играть одному
if gameSelection == 1:

    gamerDeposit = int(input("Vvedite vash depozit($): "))
    while gamerDeposit <= 0:
        gamerDeposit = int(input("Nevozmozhno vzat' s soboj stol'ko deneg!\n"))
    startDeposit = gamerDeposit

    timeCredit = 0
    while gamerDeposit > 0:

        gamerNumber = int(input("Na kakoe chislo stavite(2-12): "))
        while gamerNumber > 12 or gamerNumber < 2:
            gamerNumber = int(input("Takoj summy ne mozhet vypast'\n"))

        gamerBet = int(input("Vasha stavka($):"))
        while gamerBet > gamerDeposit:
            gamerBet = int(input("Vy ne mozhete postavit' bolshe chem u vas est'\n"))
        while gamerBet < 1:
            gamerBet = int(input("Takaja stavka nevozmozhna!\n"))
        gamerDeposit -= gamerBet

        side1 = random.randint(1, 6)
        side2 = random.randint(1, 6)
        sum = side1 + side2
        print("\nVypalo: ", sum)

        if gamerNumber == sum:
            print("Pozdravljzju, vy ugadali!")
            gamerDeposit += gamerBet * 6
            print("Vash vyigrysh: ", gamerBet * 6, "$")
        else:
            print("Vy ne ugadali.")

        print("Vash ostatok:", gamerDeposit, "$")
        toContinue = int(input("\n 1 - prodolzhit'\n 0 - vyjti\n"))
        while toContinue > 1 or toContinue < 0:
            toContinue = int(input("Takogo varianta netu!\n# "))
        if toContinue == 0:
            break

        if gamerDeposit == 0 or timeCredit != 0:
            if timeCredit == 0:
                selection = int(input("Hotite vzjat' kredit(maksimal'no na 5 hodov)?\n 1 - da\n 0 - net"))
                while selection > 1 or selection < 0:
                    selection = int(input("Takogo varianta netu!\n# "))
                if selection == 1:
                    credit = int(input("Skolko hotite vzjat'(minmal'no 10 $): "))
                    while credit < 10:
                        credit = int(input("nevozmozhnyj kredit\n# "))
                    print("Vam nado budet vernut'", int(credit * 1.5), "$")
                    timeCredit = int(input("Na skolko berete hodov(1-5)"))
                    while timeCredit > 5 or timeCredit < 1:
                        timeCredit = int(input("Nevoznozhnoje vremja\n# "))
                gamerDeposit += credit
            else:
                timeCredit -= 1
                print("Ostalos do vyplany kredita")

    if gamerDeposit == 0:
        print("\nVy proigrali kazino vse den'gi")
    elif gamerDeposit >= startDeposit:
        print("\nVy vyigrali u kazino ", gamerDeposit - startDeposit, "$")
    else:
        print("\nVy proigrali kazino ", startDeposit - gamerDeposit, "$")
    print("Vsego horoshego!\n")


# Игра с компом
elif gameSelection == 2:

    computerDeposit = random.randint(500, 1000)
    print("Kompjuter vzjal s soboj", computerDeposit, "$")
    gamerDeposit = int(input("Vvedite vash depozit($): "))
    while gamerDeposit <= 0:
        gamerDeposit = int(input("Nevozmozhno vzat' s soboj stol'ko deneg!\n"))

    while gamerDeposit > 0 and computerDeposit > 0:

        gamerNumber = int(input("Na kakoe chislo stavite(2-12): "))
        while gamerNumber > 12 or gamerNumber < 2:
            gamerNumber = int(input("Takoj summy ne mozhet vypast'\n"))

        gamerBet = int(input("Vasha stavka($):"))
        while gamerBet > gamerDeposit:
            gamerBet = int(input("Vy ne mozhete postavit' bolshe chem u vas est'\n"))
        while gamerBet < 1:
            gamerBet = int(input("Takaja stavka nevozmozhna!\n"))
        gamerDeposit -= gamerBet

        computerNumber = random.randint(2, 12)
        computerBet = random.randint(10, 100)
        while computerBet > computerDeposit:
            if computerDeposit < 10:
                computerBet = computerDeposit
                break
            else:
                computerBet = random.randint(10, 100)
        computerDeposit -= computerBet

        print("Kompjuter postavil", computerBet, "$ na chislo", computerNumber)
        side1 = random.randint(1, 6)
        side2 = random.randint(1, 6)
        sum = side1 + side2
        print("\nVypalo: ", sum)

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
            print("Stavki ne sygrali...\n")
            gamerDeposit += int(gamerBet / 3)
            computerDeposit += int(computerBet / 3)
            print("Vam nachisleno", int(gamerBet / 3), "$ kompensacii")
            print("Comppjuteru - ", int(computerBet / 3), "$ kompensacii")

        print("Vash ostatok:", gamerDeposit,"$")
        print("Ostatok kompjutera:", computerDeposit, "$")
        toContinue = int(input("\n 1 - prodolzhit'\n 0 - vyjti\n"))
        while toContinue > 1 or toContinue < 0:
            toContinue = int(input("Takogo varianta netu!\n# "))
        if toContinue == 0:
            print("Vsego horoshego!\n")
            break

    if computerDeposit == 0:
        print("\nU kompjutera zakonchilis' dengi\nVy POBEDILI!!")
    if gamerDeposit == 0:
        print("\nU vas zakonchilis' dengi\nKompjuter pobedil")


# Игра с другом
elif gameSelection == 3:

    gamer1Name = input("igrok 1.\nVvedite vashe imja: ")
    gamer1Deposit = int(input("Vash depozit($): "))
    while gamer1Deposit <= 0:
        gamer1Deposit = int(input("Nevozmozhno vzat' s soboj stol'ko deneg!\n"))

    gamer2Name = input("igrok 2.\nVvedite vashe imja: ")
    gamer2Deposit = int(input("Vash depozit($): "))
    while gamer2Deposit <= 0:
       gamer2Deposit = int(input("Nevozmozhno vzat' s soboj stol'ko deneg!\n"))

    while gamer1Deposit > 0 and gamer2Deposit > 0:

        print(gamer1Name, ":")
        gamer1Number = int(input("Na kakoe chislo stavite(2-12): "))
        while gamer1Number > 12 or gamer1Number < 2:
            gamer1Number = int(input("Takoj summy ne mozhet vypast'\n"))
        gamer1Bet = int(input("Vasha stavka($):"))
        while gamer1Bet > gamer1Deposit:
            gamer1Bet = int(input("Vy ne mozhete postavit' bolshe chem u vas est'\n"))
        while gamer1Bet < 1:
            gamer1Bet = int(input("Takaja stavka nevozmozhna!\n"))
        gamer1Deposit -= gamer1Bet

        print(gamer2Name, ", teper' vasha ochered'")
        gamer2Number = int(input("Na kakoe chislo stavite(2-12): "))
        while gamer2Number > 12 or gamer2Number < 2:
            gamer2Number = int(input("Takoj summy ne mozhet vypast'\n"))
        gamer2Bet = int(input("Vasha stavka($):"))
        while gamer2Bet > gamer2Deposit:
            gamer2Bet = int(input("Vy ne mozhete postavit' bolshe chem u vas est'\n"))
        while gamer2Bet < 1:
            gamer2Bet = int(input("Takaja stavka nevozmozhna!\n"))
        gamer2Deposit -= gamer2Bet

        side1 = random.randint(1, 6)
        side2 = random.randint(1, 6)
        sum = side1 + side2
        print("\nVypalo: ", sum)

        if gamer1Number == sum and gamer2Number == sum:
            print("Pozdravljzju, vy oba ugadali!")
            gamer2Deposit += gamer2Bet * 3
            gamer1Deposit += gamer1Bet * 3
            print(gamer1Name, ", vash vyigrysh: ", gamer1Bet * 3, "$\n")
            print(gamer2Name, ", vash vyigrysh: ", gamer2Bet * 3, "$\n")
        elif gamer1Number == sum:
            print(gamer1Name, "ugadal.")
            gamer1Deposit += gamer1Bet * 3
            print("Vash vyigrysh: ", gamer1Bet * 3, "$")
        elif gamer2Number == sum:
            print(gamer2Name, "ugadal.")
            gamer2Deposit += gamer2Bet * 3
            print("Vash vyigrysh: ", gamer2Bet * 3, "$")
        else:
            print("Stavki ne sygrali...\n")
            gamer2Deposit += int(gamer2Bet / 3)
            gamer1Deposit += int(gamer1Bet / 3)
            print(gamer1Name, ", vam nachisleno", int(gamer1Bet / 3), "$ kompensacii")
            print(gamer2Name, ", vam nachisleno", int(gamer2Bet / 3), "$ kompensacii")

        print(gamer1Name, ", vash ostatok:", gamer1Deposit, "$")
        print(gamer2Name, ", vash ostatok:", gamer2Deposit, "$")

        toContinue = int(input("\n 1 - prodolzhit'\n 0 - vyjti\n"))
        while toContinue > 1 or toContinue < 0:
            toContinue = int(input("Takogo varianta netu!\n# "))
        if toContinue == 0:
            break

    if gamer1Deposit == 0 and gamer2Deposit == 0:
        print("Nichja.")
    elif gamer1Deposit == 0:
        print(gamer2Name, " vyigarl!")
    elif gamer2Deposit == 0:
        print(gamer1Name, " vyigarl!")
    print("Vsego horoshego!\n")


# выход
else:
    print("Vsego horoshego!\n")
