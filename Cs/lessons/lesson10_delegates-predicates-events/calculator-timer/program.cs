using System;
using System.Timers;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson10_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var calc = new Calculator();
            calc.ResultCalculated += (s, e) => Console.WriteLine(e.Result);
            calc.Start();

            //Timer timer= new Timer(1000);
            //timer.Elapsed += (o, e) => { Console.Clear(); Console.WriteLine(e.SignalTime); };
            //timer.Start();

            Console.ReadLine();
        }
    }
}
