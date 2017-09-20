using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw6_20._09._17
{
    class ProgramComplex
    {
        static void Main(string[] args)
        {
            var complex1 = new Complex(1, -1);
            Console.WriteLine(complex1);
            var complex2 = new Complex(-4, 7);
            Console.WriteLine(complex2);
            Console.WriteLine(complex1 / complex2);
        }
    }
}
