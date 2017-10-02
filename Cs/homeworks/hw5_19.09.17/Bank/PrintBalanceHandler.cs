using System;

namespace Bank
{
    public class PrintBalanceHandler : ContractHandler
    {
        public PrintBalanceHandler(Contract contract) : base(contract)
        {
        }

        public override void Handle()
        {
            Contract.PrintBalance();
        }
    }
}
