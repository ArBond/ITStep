using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw2_13._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            int fieldHeight = Int32.Parse(args[0]);
            int fieldWidth = Int32.Parse(args[1]);

            bool[,] field = new bool[fieldWidth, fieldHeight];

            for (int i = 2; i < args.Length; i++)
            {
                var aliveCell = args[i].Split(',');
                field[Int32.Parse(aliveCell[0]), Int32.Parse(aliveCell[1])] = true;
            }

            for (int i = 1; i < fieldWidth; i++)
            {
                for (int j = 1; j < fieldHeight; j++)
                    Console.Write(field[i, j] == true ? '*' : ' ');
                Console.WriteLine();
            }

            var key = Console.ReadKey();
            while (key.Key != ConsoleKey.Escape)
            {
                Console.Clear();

                for(int i = 1; i < fieldWidth; i++)
                {
                    for(int j = 1; j < fieldHeight; j++)
                        Console.Write(field[i, j] == true ? '*' : ' ');
                    Console.WriteLine();
                }

                bool[,] prevField = new bool[fieldWidth, fieldHeight];
                Array.Copy(field, prevField, field.Length);

                for (int i = 0; i < fieldWidth; i++)
                {
                    for (int j = 0; j < fieldHeight; j++)
                    {

                        int countAliveCell = 0;

                        int x = i - 1;
                        int y = j - 1;
                        if (x <= 0)
                            x = fieldHeight - 1;
                        if (y <= 0)
                            y = fieldWidth - 1;
                        
                        if(prevField[x, y] == true)
                            countAliveCell++;

                        x = i;
                        y = j - 1;
                        if (y <= 0)
                            y = fieldWidth - 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i + 1;
                        y = j - 1;
                        if (x >= fieldHeight)
                            x = 1;
                        if (y <= 0)
                            y = fieldWidth - 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i - 1;
                        y = j;
                        if (x <= 0)
                            x = fieldHeight - 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i + 1;
                        y = j;
                        if (x >= fieldHeight)
                            x = 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i - 1;
                        y = j + 1;
                        if (x <= 0)
                            x = fieldHeight - 1;
                        if (y >= fieldWidth)
                            y = 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i;
                        y = j + 1;
                        if (y >= fieldWidth)
                            y = 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i + 1;
                        y = j + 1;
                        if (x >= fieldHeight)
                            x = 1;
                        if (y >= fieldWidth)
                            y = 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;
                        
                        if (field[i, j] == false && countAliveCell == 3)
                            field[i, j] = true;
                        else if(field[i, j] == true && (countAliveCell < 2 || countAliveCell > 3))
                            field[i, j] = false;
                    }
                }
                System.Threading.Thread.Sleep(100);
            }
        }
    }
}


//10,5 10,6 10,7 9,6   10,10 10,11 10,12 9,11   10,15 10,16 10,17 9,16   10,20 10,21 10,22 9,21

//1,1 2,2 2,3 3,1 3,2
//1,1 1,2 2,1 2,3 3,1

/*
13,13 13,14 13,12 12,13 14,13   10,11 10,12 11,11 11,12  9,8 9,9 10,8 10,9  12,8 13,8 14,8 12,9    11,15 11,16 12,15 12,16  8,16 8,17 9,16 9,17  8,12 8,13 8,14 9,14    15,14 15,15 16,14 16,15  16,17 16,18 17,17 17,18  12,18 13,18 14,18 14,17    14,10 14,11 15,10 15,11  17,9 17,10 18,9 18,10  18,12 18,13 18,14 17,12
*/
