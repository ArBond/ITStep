using System;

namespace Bank
{
    public abstract class ContractHandler : IMenuItemHandler
    {
        protected Contract Contract { get; set; }

        public ContractHandler(Contract contract)
        {
            Contract = contract;
        }

        public abstract void Handle();
    }
}
