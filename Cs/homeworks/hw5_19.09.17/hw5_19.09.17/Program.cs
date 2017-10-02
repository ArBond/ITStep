using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw5_19._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            var arr1 = new RangeOfArray(1, -2);
            arr1[1] = 1;
            arr1[0] = 2;
            arr1[-1] = 3;
            arr1[-2] = 4;
            foreach (var element in arr1)
                Console.WriteLine(element);

            var arr2 = new RangeOfArray(-1, 2);
            arr2[-1] = 1;
            arr2[0] = 2;
            arr2[1] = 3;
            arr2[2] = 4;
            for (int i = arr2.Begin; i <= arr2.End; i++)
                Console.WriteLine(arr2[i]);
        }
    }
}