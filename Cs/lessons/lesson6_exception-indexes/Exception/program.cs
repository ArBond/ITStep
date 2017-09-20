using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson6_exceptions
{
    class Program
    {
        static void Main(string[] args)
        {
            //try
            //{
            //    throw new ITStepException("Hello");
            //}
            //catch(ITStepException ex)
            //{
            //    Console.WriteLine(ex);
            //}
            //catch
            //{
            //    Console.WriteLine("Error");
            //}

            try
            {
                checked
                {
                    byte b = 100;
                    b += 200;
                    Console.WriteLine(b);
                }
            }
            catch(Exception ex /*when(ex.Message.Contains("переполнение") */ )
            {
                Console.WriteLine(ex.Message);
            }


        }
    }
}
