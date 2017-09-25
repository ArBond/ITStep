using System;

namespace lesson9_Menu
{
    class Program
    {
        static void Main(string[] args)
        {
            var bank = new Bank();
            var menu = new MenuItemCollection(null, new MenuItem[]
            {
                new MenuItemCollection("Баланс", new MenuItem[]
                {
                    new ActionMenuItem("На экран", new ShowBalanceHandler(bank)),
                    new ActionMenuItem("На чек", new ShowBalanceHandler(bank))
                }),
                new MenuItemCollection("Снять", new MenuItem[]
                {
                    new ActionMenuItem("BUN", new WithdrawHadler(bank)),
                    new ActionMenuItem("USD", new WithdrawHadler(bank))
                }),
                new MenuItemCollection("Пополнить", new MenuItem[]
                {
                    new ActionMenuItem("BUN", new DepositHandler(bank)),
                    new ActionMenuItem("USD", new DepositHandler(bank))
                })
            });
            menu.SelectItem();
        }
    }
}
