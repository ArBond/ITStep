﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

/*
    Осталось доделать:
        -доделать ручную расстановку кораблей
*/

namespace hw3_14._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            Cursor cursor = new Cursor();
            Field playerField = new Field(cursor);
            Ship playerShip = new Ship();

            //playerShip.RandomSet(playerField);

            Console.WriteLine("Your field");
            playerField.Print(cursor);
            while(true)
            {
                if (playerShip.ShipCount == 10)
                {
                    Console.WriteLine("Okey. Let's go!\n Press any key");
                    Console.ReadKey();
                    break;
                }

                var key = Console.ReadKey();
                cursor.ChangePos(key);
                switch(key.Key)
                {
                    case ConsoleKey.Enter:
                        playerShip.Set(cursor, playerField);
                        break;
                    case ConsoleKey.Delete:
                        playerShip.Delete(cursor, playerField);
                        break;
                    default:
                        break;
                }
                Console.Clear();
                Console.WriteLine("Your field");
                playerField.Print(cursor);
            }

            Field computerField = new Field(cursor);
            Ship computerShip = new Ship();
            computerShip.RandomSet(computerField);

            while (true)
            {
                bool @continue = true;
                do
                {
                    Console.Clear();
                    Console.WriteLine("Your field");
                    playerField.Print(null);
                    Console.WriteLine("\nComputer field");
                    computerField.Print(cursor);

                    var key = Console.ReadKey();
                    cursor.ChangePos(key);
                    switch (key.Key)
                    {
                        case ConsoleKey.Enter:
                            @continue = computerShip.Shot(cursor, computerField);
                            break;
                        default:
                            break;
                    }
                    
                }
                while (@continue == true);

                do
                {
                    Thread.Sleep(1000);
                    @continue = playerShip.RandomShot(playerField);
                    Console.Clear();
                    Console.WriteLine("Your field");
                    playerField.Print(null);
                    Console.WriteLine("\nComputer field");
                    computerField.Print(cursor);
                }
                while (@continue == true);

                if (computerShip.ShipCount == 0 || playerShip.ShipCount == 0)
                {
                    if(computerShip.ShipCount == 0 && playerShip.ShipCount == 0)
                        Console.WriteLine("Draw");
                    else if (computerShip.ShipCount == 0)
                        Console.WriteLine("You Win!");
                    else
                        Console.WriteLine("You Lose.");
                    break;
                }
            }
        }
    }
}