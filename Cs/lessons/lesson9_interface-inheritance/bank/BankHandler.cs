using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_Menu
{
    public abstract class BankHandler : IMenuItemHandler
    {
        protected Bank Bank { get; set; }

        public BankHandler(Bank bank)
        {
            Bank = bank;
        }

        public abstract void Handle();

        protected decimal AsKAmount()
        {
            Console.WriteLine("Введите сумму:");
            var sum = decimal.Parse(Console.ReadLine());
            return sum;
        }
    }
}
