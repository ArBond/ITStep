using System;

namespace Bank
{
    public class ExitHandler : ContractHandler
    {
        public ExitHandler(Contract contract) : base(contract)
        {
        }

        public override void Handle()
        {
            throw new BankException(BankErrorCode.Exit, "Good day)");
        }
    }
}
