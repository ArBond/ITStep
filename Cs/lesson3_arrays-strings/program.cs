using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson3
{
    class Program
    {
        static void Main(string[] args)
        {
            //int[,] array1 = new int[5,5];
            //Console.Write(array1.GetType().Name);
            //foreach (var it in array1)
            //    Console.Write(it);

            //int[][] array2 = new int[5][];
            //for(int i = 0; i < array2.Length; i++)
            //    array2[i] = new int[i + 1];

            //Console.WriteLine();
            //foreach (var it in array2)
            //{
            //    Console.Write(it + " ");
            //    foreach (var it2 in it)
            //        Console.Write(it2);
            //    Console.WriteLine();
            //}

            //int[] array3 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            //Console.Write(array3.Sum() + '\n' + array3.Average() + '\n' + array3.Max());


            //            string str = @"Hello,
            //Vova!";
            //            str = str.ToUpper();

            //            var age = 50;
            //            var str2 = String.Format("{1}\nIm {0:N2} years old.", age, str);
            //            Console.WriteLine(str2);
            //            Console.WriteLine($"{str}\nIm {age} years old.");

            //            var name = "Artemi";
            //            name += "Bondarenko";

            //            StringBuilder name2 = new StringBuilder("Artemi");
            //            name2.Append(" Bondarenko");
            //            name2.ToString();
            //            Console.WriteLine(name2);

            //Console.WriteLine(args[0]);



            int width = Int32.Parse(args[0]);
            int heigth = Int32.Parse(args[1]);

            bool[ , ] array = new bool[width, heigth];

            int[,] cellArray = new int[args.Length - 2, 2];
            for(int i = 2; i < args.Length; i++)
            {
                var cell = args[i].Split(',');
                array[Int32.Parse(cell[0]), Int32.Parse(cell[1])] = true;
            }


            var key = Console.ReadKey();
            while (key.Key != ConsoleKey.Escape)
            {

                //рисуем
                Console.Clear();
                for (int i = 0; i < width; i++)
                {
                    for (int j = 0; j < heigth; j++)
                    {
                        if (array[i, j])
                            Console.Write('*');
                        else
                            Console.Write('-');
                    }
                    Console.WriteLine();
                }


                for(int i = 0; i < width; i++)
                {
                    for(int j = 0; j < heigth; j++)
                    {
                        int count = 0;

                        if(i != 0 && i != width - 1 && j != 0 && j != heigth - 1)
                        {
                            if (array[i + 1, j] == true)
                                count++;
                            else if(array[i - 1, j] == true)
                                count++;
                            else if (array[i, j + 1] == true)
                                count++;
                            else if (array[i, j - 1] == true)
                                count++;
                        }
                        else if(i != 0 && i != width - 1)
                        {

                        }
                        else if(j != 0 && j != heigth - 1)
                        {
                            if (array[i + 1, j] == true)
                                count++;
                            else if (array[i - 1, j] == true)
                                count++;
                        }
                        else
                        {

                        }

                        if(array[i, j] == true && count == 0 || count == 4)
                            array[i, j] = false;
                        else if (array[i, j] == false && count == 3)
                        {
                            array[i, j] = true;
                        }
                    }
                }

                key = Console.ReadKey();
            }
        }
    }
}
