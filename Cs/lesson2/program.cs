using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson2
{
    class Program
    {
        static void Main(string[] args)
        {
            //byte b = 10;
            //Console.WriteLine(b.GetType().Namespace);

            //decimal dm = 1;
            //dm = dm / 3;
            //Console.WriteLine(dm * 3);

            //int? i = null;
            //decimal d = 0.1M;

            //string str = "123";
            //int num = Int32.Parse(str);
            //Console.WriteLine(num + 10);

            int x = 0;
            int y = 0;

            var random = new Random();

            var key = Console.ReadKey();
            int xK = random.Next(0, 50);
            int yK = random.Next(0, 20);

            while (key.Key != ConsoleKey.Escape)
            {
                Console.Clear();

                if (xK == x && yK == y)
                {
                    xK = random.Next(0, 50);
                    yK = random.Next(0, 20);
                }

                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 50; j++)
                    {
                        if (j == x && i == y)
                            Console.Write('@');
                        else if(j == xK && i == yK)
                            Console.Write('$');
                        else
                            Console.Write(' ');
                    }
                    Console.Write("|\n");
                }
                
                for (int i = 0; i < 50; i++)
                    Console.Write('-');

                key = Console.ReadKey();

                switch (key.Key)
                {
                    case ConsoleKey.UpArrow:
                        if (y != 0)
                            y--;
                        break;
                    case ConsoleKey.DownArrow:
                        if (y != 20 - 1)
                            y++;
                        break;
                    case ConsoleKey.LeftArrow:
                        if (x != 0)
                            x--;
                        break;
                    case ConsoleKey.RightArrow:
                        if (x != 50 - 1)
                            x++;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
