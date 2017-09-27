using System;
using System.Threading;

namespace hw3_14._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to SEA BATTLE!");
            Thread.Sleep(2000);
            bool game = true;
            while (game)
            {
                Cursor cursor = new Cursor();
                Field playerField = new Field(cursor);
                Ship playerShip = new Ship();

                Console.WriteLine("Choose how to set ships:\n<a> - automatically\t<h> - by hand");
                ConsoleKeyInfo input;
                do
                {
                    input = Console.ReadKey();
                    if (input.Key == ConsoleKey.A)
                    {
                        playerShip.RandomSet(playerField);
                    }
                }
                while (input.Key != ConsoleKey.A && input.Key != ConsoleKey.H);

                Console.Clear();
                Console.WriteLine("Your field");
                playerField.Print(cursor, true);
                while (true)
                {
                    if (playerShip.ShipCount == 10)
                    {
                        Console.WriteLine("Okay. Let's go!\n Press any key");
                        Console.ReadKey();
                        break;
                    }

                    var key = Console.ReadKey();
                    cursor.ChangePos(key);
                    switch (key.Key)
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
                    playerField.Print(cursor, true);
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
                        playerField.Print(null, true);
                        Console.WriteLine("\nComputer field");
                        computerField.Print(cursor, false);

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
                        if (playerShip.ShipCount == 0)
                            @continue = false;
                    }
                    while (@continue == true);

                    do
                    {
                        Thread.Sleep(300);
                        @continue = playerShip.RandomShot(playerField);
                        Console.Clear();
                        Console.WriteLine("Your field");
                        playerField.Print(null, true);
                        Console.WriteLine("\nComputer field");
                        computerField.Print(cursor, false);

                        if (computerShip.ShipCount == 0 || playerShip.ShipCount == 0)
                            @continue = false;
                    }
                    while (@continue == true);
                    if (computerShip.ShipCount == 0 || playerShip.ShipCount == 0)
                    {
                        if (computerShip.ShipCount == 0 && playerShip.ShipCount == 0)
                            Console.WriteLine("Draw");
                        else if (computerShip.ShipCount == 0)
                            Console.WriteLine("You Win!");
                        else
                            Console.WriteLine("You Lose.");
                        Console.WriteLine("Press any key...");
                        Console.ReadKey();
                        break;
                    }
                }
                Console.Clear();
                Console.WriteLine("<enter> - new game\t<esc> - exit");
                do
                {
                    input = Console.ReadKey();
                    if (input.Key == ConsoleKey.Escape)
                        game = false;
                }
                while (input.Key != ConsoleKey.Escape && input.Key != ConsoleKey.Enter);
                Thread.Sleep(1000);
                Console.Clear();
            }
        }
    }
}