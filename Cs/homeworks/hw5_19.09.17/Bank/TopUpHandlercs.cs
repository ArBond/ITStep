using System;

namespace Bank
{
    public class TopUpHandlers : ContractHandler
    {
        public TopUpHandlers(Contract contract) : base(contract)
        {
        }

        public override void Handle()
        {
            Console.WriteLine("Enter sum:");
            var sum = decimal.Parse(Console.ReadLine());
            Contract.TopUp(sum);
        }
    }
}
