using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson13
{
    public class Garbage: IDisposable
    {
        private int[] array = new int[100000];

        public void Dispose()
        {
            Console.WriteLine("Dispozed!");
        }
    }
}
