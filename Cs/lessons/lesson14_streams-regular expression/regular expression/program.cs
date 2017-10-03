using System;
using System.Text.RegularExpressions;

namespace regular_expression
{
    class Program
    {
        static void Main(string[] args)
        {
            var text = " Hello    beautiful world , I'am lucky.";
            foreach (var str in Regex.Split(text, @"\s*[,!.:\s]+\s*"))
                Console.WriteLine(str);

            var exp1 = @"(0[1-9]|[1-2][0-9]|[3][0-1])\.0[1-9]|1[0-2]\.\d{4}";
            Console.WriteLine(Regex.IsMatch("03.12.2017", exp1));

            var exp2 = @"(public|private|pritected)?\s+(static\s+)?\w+\s+[A-Z]\w*\(\)";
            foreach (var match in Regex.Matches("public static void Method(){}", exp2))
                Console.WriteLine(match);
        }
    }
}
