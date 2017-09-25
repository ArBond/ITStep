using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_Menu
{
    public class DepositHandler: BankHandler
    {
        public DepositHandler(Bank bank):base(bank)
        {
        }

        public override void Handle()
        {
            Bank.SetDeposite(AsKAmount());
        }
    }
}
