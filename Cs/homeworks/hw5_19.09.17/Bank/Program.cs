using System;

namespace Bank
{
    class Program
    {
        static void Main(string[] args)
        {
            var bank = new Bank();
            var contract = new Contract("Artemi", "Minsk", "+375 29 111 11 11",  "MP1111111");
            bank.AddContract(contract);
            var card = new CreditCard("1111", "1111 1111 1111 1111");
            contract.AddCreditCard(card);

            Console.WriteLine("Enter card number(xxxx xxxx xxxx xxxx):");
            var cardNumber = Console.ReadLine();

            Contract userContract = null;
            bool isAuthorize = false;
            while (!isAuthorize)
            {
                try
                {
                    userContract = bank.Contract(cardNumber);
                    Console.WriteLine("Enter pin(xxxx):");
                    var pin = Console.ReadLine();
                    card.Authorize(pin);
                    isAuthorize = true;
                }
                catch (BankException ex)
                {
                    Console.WriteLine(ex.Message);
                    switch (ex.ErrorCode)
                    {  
                        case BankErrorCode.CreditCardNotValid:
                        case BankErrorCode.CreditCardLock:
                            return;
                        default:
                            break;
                    }
                }
            }

            var menu = new MenuItemCollection(null, new MenuItem[]
            {
                new MenuItemCollection("Print balance", new MenuItem[]
                        {
                            new ActionMenuItem("In check", new PrintBalanceHandler(userContract)),
                            new ActionMenuItem("In display", new PrintBalanceHandler(userContract)),
                            new MenuItem("Back")
                        }),
                new MenuItemCollection("Top up", new MenuItem[]
                        {
                            //new MenuItem("1"),
                            //new MenuItem("5"),
                            //new MenuItem("10"),
                            //new MenuItem("20"),
                            //new MenuItem("50"),
                            new ActionMenuItem("Other amount", new TopUpHandlers(userContract)),
                            new MenuItem("Back")
                        }),
                new MenuItemCollection("Withdraw", new MenuItem[]
                        {
                            //new MenuItem("1"),
                            //new MenuItem("5"),
                            //new MenuItem("10"),
                            //new MenuItem("20"),
                            //new MenuItem("50"),
                            new ActionMenuItem("Other amount", new WithdrawHadler(userContract)),
                            new MenuItem("Back")
                        }),
                new ActionMenuItem("Exit", new ExitHandler(userContract))
            });

            while (true)
            {
                try
                {
                    menu.SelectItem();
                }
                catch (BankException ex)
                {
                    Console.WriteLine(ex.Message);
                    switch (ex.ErrorCode)
                    {
                        case BankErrorCode.Exit:
                            return;
                        case BankErrorCode.NotEnoughMoney:
                            Console.ReadKey();
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}