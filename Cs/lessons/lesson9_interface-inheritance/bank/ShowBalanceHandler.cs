using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_Menu
{
    public class ShowBalanceHandler : BankHandler
    {
        public override void Handle()
        {
            Console.WriteLine($"Ваш баланс: {Bank.Deposite}");
        }

        public ShowBalanceHandler(Bank bank):base(bank)
        {
        }
    }
}
