using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson10_3
{
    class Program
    {
        static void Main(string[] args)
        {
            var array = new SmartArray();
            array.Add(2);
            array.Add(0);
            array.Add(-10);
            array.Add(15);
            array = array.Where(x => x >= 0);
            array = array.Select(x => x * x);
            array.Print();
            Console.WriteLine(array.Where(x => x > 0).Select(x => x / 10).Count(x => x > 0));
        }
    }
}
