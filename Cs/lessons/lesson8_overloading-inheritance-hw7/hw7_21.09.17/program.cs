using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw7_21._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            Fraction f = new Fraction(3, 4);
            int a = 10;
            Fraction f1 = f * a;
            Fraction f2 = a * f;
            double d = 1.5;
            Fraction f3 = f + d;
        }
    }
}
