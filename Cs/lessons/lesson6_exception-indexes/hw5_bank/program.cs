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
            var card = new CreditCard("1234123123123", "1234");
            var isAuthorize = false;
            while (!isAuthorize)
            {
                Console.WriteLine($"Enter pin:");
                var pin = Console.ReadLine();
                try
                {
                    card.Authorize(pin);
                    Console.WriteLine("Welcome!");
                    isAuthorize = true;
                }
                catch (CreditCardPinException ex)
                {
                    Console.WriteLine(ex.Message);
                }
                catch (CreditCardLockException ex)
                {
                    Console.WriteLine(ex.Message);
                    break;
                }        
            }
        }
    }
}
