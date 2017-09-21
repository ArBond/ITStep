using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson8
{
    class Program
    {
        static void Main(string[] args)
        {
            //var p1 = new Point(10, 10);
            //while(p1)
            //    Console.WriteLine(p1--);
            //var p2 = new Point(10, 10);
            //while (p1 || p2)
            //    Console.WriteLine($"{p1--}  {p2--}");


            Square s1 = 10;
            Rectangle r1 = new Rectangle() { Height = 10, Width = 100 };
            s1 = (Square)r1;
        }
    }
}
