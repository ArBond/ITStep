using System;

namespace Bank
{
    public class Contract
    {
        private const int maxCardQuantity = 5;
        public int CardCount { get; private set; }
        private CreditCard[] cards = new CreditCard[maxCardQuantity];
        public CreditCard[] Cards { get { return cards; } }
        public int Number { get; set; }

        public string Name { get; set; }
        public string PassportNumber { get; set; }
        public string Address { get; set; }
        public string Phone { get; set; }
        public decimal Balance { get; set; }

        public void PrintBalance()
        {
            Console.WriteLine($"Your balance: {Balance}");
        }

        public void TopUp(decimal sum)
        {
            Balance += sum;
        }

        public void Withdraw(decimal sum)
        {
            if (sum > Balance)
                throw new BankException(BankErrorCode.NotEnoughMoney, "Not Enough money.");
            Balance -= sum;
        }

        public Contract(string name, string address, string phone, string passportNumber)
        {
            Name = name;
            Address = address;
            Phone = phone;
            PassportNumber = passportNumber;
        }

        public void AddCreditCard(CreditCard card)
        {
            if (CardCount >= maxCardQuantity)
                throw new BankException(BankErrorCode.MaxContractCardQuantity, "Max card quantity for account.");
            cards[CardCount++] = card;
        }
    }
}
