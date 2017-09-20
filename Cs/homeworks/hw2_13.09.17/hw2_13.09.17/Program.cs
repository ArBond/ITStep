using System;
using System.Text;
using System.Threading;


//30 20    1,1 2,2 2,3 3,1 3,2    16,27 16,28 17,26 17,27 18,28

/* нужен маленький шрифт и большой буффер консоли
99 99    49,49    46,47 46,48 47,47 47,48  45,44 45,45 46,44 46,45  41,45 41,46 42,45 42,46  38,46 38,47 39,46 39,47  37,49 37,50 38,49 38,50  36,52 36,53 37,52 37,53  35,55 35,56 36,55 36,56    47,51 47,52 48,51 48,52  44,52 44,53 45,52 45,53  45,56 45,57 46,56 46,57  46,59 46,60 47,59 47,60  49,60 49,61 50,60 50,61  52,61 52,62 53,61 53,62  55,62 55,63 56,62 56,63    51,50 51,51 52,50 52,51  52,53 52,54 53,53 53,54  56,52 56,53 57,52 57,53  59,51 59,52 60,51 60,52  60,48 60,49 61,48 61,49  61,45 61,46 62,45 62,46  62,42 62,43 63,42 63,43    50,46 50,47 51,46 51,47  53,45 53,46 54,45 54,46  52,41 52,42 53,41 53,42  51,38 51,39 52,38 52,39  48,37 48,38 49,37 49,38  45,36 45,37 46,36 46,37  42,35 42,36 43,35 43,36
*/

namespace hw2_13._09._17
{
    class Program
    {
        static void PrintField(int height, int width, bool[,] field)
        {
            Console.Clear();
            StringBuilder fieldString = new StringBuilder();
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                    fieldString.Append(field[i, j] == true ? "*" : " ");
                fieldString.Append('\n');
            }
            Console.WriteLine(fieldString);
        }

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

            PrintField(fieldHeight, fieldWidth, field);

            var key = Console.ReadKey();
            int ctr = 0;
            while (true)
            {
                bool[,] prevField = new bool[fieldWidth, fieldHeight];
                Array.Copy(field, prevField, field.Length);

                for (int i = 0; i < fieldWidth; i++)
                {
                    for (int j = 0; j < fieldHeight; j++)
                    {
                        int countAliveCell = 0;

                        int x = i - 1;
                        int y = j - 1;
                        if (x == -1)
                            x = fieldWidth - 1;
                        if (y == -1)
                            y = fieldHeight - 1;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i + 1;
                        if (x == fieldWidth)
                            x = 0;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i - 1;
                        y = j;
                        if (x == -1)
                            x = fieldWidth - 1;

                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i + 1;
                        if (x == fieldWidth)
                            x = 0;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i - 1;
                        y = j + 1;
                        if (x == -1)
                            x = fieldWidth - 1;
                        if (y == fieldHeight)
                            y = 0;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        x = i + 1;
                        if (x == fieldWidth)
                            x = 0;
                        if (prevField[x, y] == true)
                            countAliveCell++;

                        if (field[i, j] == false && countAliveCell == 3)
                            field[i, j] = true;
                        else if (field[i, j] == true && (countAliveCell < 2 || countAliveCell > 3))
                            field[i, j] = false;
                    }
                }
                ctr++;
                Console.ForegroundColor = (ConsoleColor)(ctr % 16);
                PrintField(fieldHeight, fieldWidth, field);
                Thread.Sleep(100);
            }
            Console.ResetColor();
        }
    }
}