using System;

namespace Bank
{
    public class WithdrawHadler : ContractHandler
    {
        public WithdrawHadler(Contract contract) : base(contract)
        {
        }

        public override void Handle()
        {
            Console.WriteLine("Enter sum:");
            var sum = decimal.Parse(Console.ReadLine());
            Contract.Withdraw(sum);
        }
    }
}
