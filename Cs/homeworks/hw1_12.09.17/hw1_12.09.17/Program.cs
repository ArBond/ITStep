using System;

namespace hw1_12._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            ConsoleKeyInfo key;
            int spaceCount = 0;
            Console.WriteLine("Enter symbols('.' - end ofentering)");
            do
            {
                key = Console.ReadKey();
                if (key.KeyChar == ' ')
                    spaceCount++;
                Console.WriteLine();
            }
            while (key.KeyChar != '.');
            Console.WriteLine($"\nSpace count: {spaceCount}");


            Console.WriteLine("\n\nTASK 2 ####################\n");

            bool result;
            int number;
            Console.WriteLine("Enter the ticket number(6-digit number): ");
            do
            {
                result = Int32.TryParse(Console.ReadLine(), out number);
            }
            while (!result || number < 100000 || number > 999999);
            Console.WriteLine(number % 10 + number / 10 % 10 + number / 100 % 10 == number / 1000 % 10 + number / 10000 % 10 + number / 100000 ?
                "Happy ticket!" : "Not happy ticket.");


            Console.WriteLine("\n\nTASK 3 ####################\n");

            Console.WriteLine("Enter the string: ");
            string str = Console.ReadLine();
            var charStr = str.ToCharArray();
            for (int i = 0; i < charStr.Length; i++)
            {
                if (charStr[i] >= 'a' && charStr[i] <= 'z')
                    charStr[i] -= (char)32;
                else if (charStr[i] >= 'A' && charStr[i] <= 'Z')
                    charStr[i] += (char)32;
            }
            Console.WriteLine(charStr);


            Console.WriteLine("\n\nTASK 4 ####################\n");

            int a = 3;
            int b = 7;
            Console.WriteLine($"{a} - {b}");
            for (int i = a; i < b + 1; i++)
            {
                for (int j = 0; j < i; j++)
                    Console.Write(i + " ");
                Console.WriteLine();
            }


            Console.WriteLine("\n\nTASK 5 ####################\n");

            number = 4263702;
            Console.WriteLine($"Number: {number}");
            int newNumber = 0;
            int count = number.ToString().Length;
            for (int i = 0; i < count; i++)
            {
                newNumber = newNumber * 10 + number % 10;
                number /= 10;
            }
            Console.WriteLine($"Revers number: {newNumber}");
        }
    }
}
