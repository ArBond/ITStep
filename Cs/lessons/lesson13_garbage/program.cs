using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson13
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GC.GetTotalMemory(false));
            var garbage = new Garbage();
            Console.WriteLine(GC.GetTotalMemory(false));
            var garbage2 = new Garbage();
            Console.WriteLine(GC.GetGeneration(garbage2));
            Console.WriteLine(GC.GetTotalMemory(false));

            garbage = null;
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
            Console.WriteLine(GC.GetGeneration(garbage2));
            Console.WriteLine(GC.GetTotalMemory(false));

            var reference = new WeakReference(garbage2);
            Console.WriteLine(reference.Target);

            garbage2 = null;
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
            Console.WriteLine(GC.GetTotalMemory(false));
            Console.WriteLine(reference.IsAlive);


            Garbage garbage3 = null;
            try
            {
                garbage3 = new Garbage();
            }
            finally
            {
                if (garbage3 != null)
                    garbage3.Dispose();
            }
            // или
            using (var garbage4 = new Garbage())
            {

            }
        }
    }
}
