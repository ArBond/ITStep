using System;
using static System.Math;

namespace lesson7
{
    class Program
    {
        static void Main(string[] args)
        {
            //Min(1, 10); // System.Math

            var p1 = new Point() { X = 10, Y = 15};
            //Console.WriteLine($"p1++: {p1++}");
            //Console.WriteLine($"++p1: {++p1}");
            //Console.WriteLine($"p1--: {p1--}");
            //Console.WriteLine($" -p1: {-p1}");
            var p2 = new Point() { X = 5, Y = -5 };
            var v1 = new Vector(p1, p2);
            var v2 = new Vector(new Point(0, 0), new Point(-5, -5));

            //Console.WriteLine($"v1: {v1}");
            //Console.WriteLine($"v2: {v2}");
            //Console.WriteLine($"v1 * 10: {v1 * 10}");
            //Console.WriteLine($"10 * v1: {10 * v1}");
            //Console.WriteLine($"v1 + v2: {v1 + v2}");


            var p3 = new Point(1, 1);
            var p4 = new Point(1, 1);
            //p3 = p4;
            Console.WriteLine(p3.Equals(p4));
            Console.WriteLine(ReferenceEquals(p3, p4));

            var p5 = new StrPoint(1, 1);
            var p6 = new StrPoint(1, 1);
            Console.WriteLine(p5.Equals(p6));
            Console.WriteLine(ReferenceEquals(p5, p6));

            var v3 = new Vector(p3, p4);
            var v4 = new Vector(new Point(0, 0), new Point(1, 1));

            Console.WriteLine(v3 == v4);
            Console.WriteLine(v3.Equals(v4));
            Console.WriteLine(v3 > v4);

        }
    }
}