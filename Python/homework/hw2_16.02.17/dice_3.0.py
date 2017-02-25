#Кубики. Версия 3.0

import random

#Возможности игры и меню
print("Kubiki 3.0!\n")

selection = int(input("Pokazat' vozmozhnosti versii?\n 1 - da\n 0 - net\n"))
while selection > 1 or selection < 0:
    selection = int(input("Takogo varianta netu!\n # "))
if selection == 1:
    print("-Proverka vseh uslovij dla vvoda dannyh pol'zovatelrem\n-Proverki na vozmozhnist' dejstvij polzovatela\n"
          "-Popolnenije scheta\n-Vvod depozitov, stavok\n")
    print('Delee: dostupno tolko v "Igrat odnomu!":')
    print("-Vozmozhnost' vzjat' kredit na kolichestvo do 5 hodov\n-Vozmozhnost' dosrochnogo pogashenije kredita\n"
          "-Vozmozhnost' sbezhat'\n -Pozvat' Kuvaldina!\n")

gameSelection = int(input("Menu:\n  1 - igrat' odnomu\n  2 - igrat' s komp'juterom\n  3 - igrat' s drugom\n  0 - vyjti\n"))
while gameSelection > 3 or gameSelection < 0:
    gameSelection = int(input("Takogo varianta netu!\n # "))


#Играть одному

if gameSelection == 1:

    gamerDeposit = int(input("Vvedite vash depozit($): "))
    while gamerDeposit <= 0:
        gamerDeposit = int(input("Nevozmozhno vzat' s soboj stol'ko deneg!\n"))
    startDeposit = gamerDeposit
    timeKredit = 0


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

        if timeKredit > 1:
            timeKredit -= 1
            print("Ostalos' hodov dlja oplaty kredita: ", timeKredit - 1)
            if gamerDeposit >= needToPay:
                selection = int(input("Hotite pogasit' sejchas?\n 1 - da\n 0 - net\n"))
                while selection > 1 or selection < 0:
                    selection = int(input("Takogo varianta netu!\n# "))
                if selection == 1:
                    gamerDeposit -= needToPay
                    timeKredit = 0
                    print("Dolg pogashen.")
                    print("Vash ostatok:", gamerDeposit, "$")

        if timeKredit == 1:
            selection = int(input("\nPora pogasit' dolg:\n 1 - pogasit'\n 2 - pozvat' Kuvaldina\n 0 - sbezhat'\n"))
            while selection > 2 or selection < 0:
                selection = int(input("Takogo varianta netu!\n# "))
            if selection == 0:
                print("Budte ostorozhny! U vyhoda vas mogut podzhidat' bratki hozjaina kazino")
                break
            elif selection == 2:
                print("Pri vide Kuvaldina bratki nervno rashodjatsja v storony a hozjain kazino proshaet vam vse dolgi")
                print("Vy spokojno uhodide")
                break
            else:
                if gamerDeposit >= needToPay:
                    gamerDeposit -= needToPay
                    timeKredit = 0
                    print("Vash ostatok:", gamerDeposit, "$")
                else:
                    selection = int(input("U vas ne hvataet deneg chtiby oplatit' dolg\n 1 - sbezhat'\n 2 - pozvat' Kuvaldina\n"))
                    while selection > 2 or selection < 1:
                        selection = int(input("U vas tol'ko 2 vyhoda\n 1 - sbezhat'\n 2 - pozvat' Kuvaldina\n"))
                    if selection == 1:
                        print("Budte ostorozhny! U vyhoda vas mogut podzhidat' bratki hozjaina kazino")
                    else:
                        print("Pri vide Kuvaldina bratki nervno rashodjatsja v storony a hozjain kazino proshaet vam vse dolgi")
                        print("Vy spokojno uhodide")
                    break

        if timeKredit > 1 and gamerDeposit == 0:
            selection = int(input("\nU vas zakonchilis' den'gi. Bolee togo, vam nuzhno oplatit' dolg.\n"
                                  " 1 - sbezhat'\n 2 - pozvat' Kuvaldina\n"))
            while selection > 2 or selection < 1:
                selection = int(input("Takogo varianta netu!\n# "))
            if selection == 1:
                print("Budte ostorozhny! U vyhoda vas mogut podzhidat' bratki hozjaina kazino")
                break
            else:
                print("Pri vide Kuvaldina bratki nervno rashodjatsja v storony a hozjain kazino proshaet vam vse dolgi")
                print("Vy spokojno uhodide")
                break

        toContinue = int(input("\n 1 - prodolzhit'\n 0 - vyjti\n"))
        while toContinue > 1 or toContinue < 0:
            toContinue = int(input("Takogo varianta netu!\n# "))
        if toContinue == 0:
            if timeKredit != 0:
                selection = int(input("Vy ne mozhete ujti t k vy ne pogasili dolg\n 1 - prodolzhit'\n 2 - pozvat' Kuvaldina\n"))
                while selection > 2 or selection < 1:
                    selection = int(input("Takogo varianta netu!\n# "))
                if selection == 2:
                    print("Pri vide Kuvaldina bratki nervno rashodjatsja v storony a hozjain kazino proshaet vam vse dolgi")
                    print("Vy spokojno uhodide")
                    break
            else:
                break

        if gamerDeposit == 0 and timeKredit == 0:
            selection = int(input("U vas zakonchilis' den'gi:\n 1 - dobavit' deneg\n"
                                  " 2 - vzjat' v dolg pod procenty(maksimum na 5 hodov)\n 0 - vyjti\n"))
            while selection > 2 or selection < 0:
                selection = int(input("Takogo varianta netu!\n "))

            if selection == 1:
                add = int(input("Kakuju summu dobavljaete($): "))
                while add < 1:
                    add = int(input("Nevozmozhno stolko dobavit'\n "))
                gamerDeposit += add
                startDeposit += add
                print("Den'gi dobavleny.")
                print("Vash ostatok:", gamerDeposit, "$")
            elif selection == 2:
                kredit = int(input("Skol'ko hotite vzjat' v dolg($): "))
                while kredit < 1:
                    kredit = int(input("Nevozmozhno stolkko vzjat' v dolg: "))
                needToPay = int(kredit * 1.5)
                print("Vam nuzhno budet vyplatit'", needToPay, "$")
                selection = int(input(" 1 - soglasen\n 0 - vyjti\n"))
                while selection > 1 or selection < 0:
                    selection = int(input("Takogo varianta netu!\n "))
                if selection == 1:
                    gamerDeposit += kredit
                    print("Den'gi dobavlrny.")
                    print("Vash ostatok:", gamerDeposit, "$")
                    timeKredit = 6

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

input("Press Enter to continue")