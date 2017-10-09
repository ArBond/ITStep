using System;

namespace attributes
{
    [Author("Artemi", "1")]
    class Program
    {
        [Author("Artemi", "9/oct.17")]
        static void Main(string[] args)
        {
            var type = typeof(Student);
            var attrs = type.GetCustomAttributes(false);
            Console.WriteLine($"{type.Name}(class) authors: ");
            PrintAttributes(attrs);
            foreach (var method in type.GetMethods())
            {
                Console.WriteLine($"{method.Name}(method) authors");
                PrintAttributes(method.GetCustomAttributes(false));
            }
        }

        private static void PrintAttributes(object[] attrs)
        {
            foreach (var attr in attrs)
            {
                if (attr is AuthorAttribute)
                {
                    var authorAttr = (AuthorAttribute)attr;
                    Console.WriteLine($"{authorAttr.Name}, {authorAttr.Date.ToShortDateString()}");
                }
                Console.WriteLine();
            }
        }
    }
}
