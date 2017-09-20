using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw3_14._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            Field field = new Field();
            field.Print();
            while (true)
            {
                var key = Console.ReadKey();
                switch(key.Key)
                {
                    case ConsoleKey.UpArrow:
                        cursor.ChangeY(cursor.GetY() - 1);
                        break;
                    case ConsoleKey.DownArrow:
                        cursor.ChangeY(cursor.GetY() + 1);
                        break;
                    case ConsoleKey.LeftArrow:
                        cursor.ChangeX(cursor.GetX() - 1);
                        break;
                    case ConsoleKey.RightArrow:
                        cursor.ChangeX(cursor.GetX() + 1);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}