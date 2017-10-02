using System;

namespace Bank
{
    public class Bank
    {
        private const int maxContractQuantity = 1000;
        private int contractCount = 0;
        private Contract[] contracts = new Contract[maxContractQuantity];

        public void AddContract(Contract contract)
        {
            if (contractCount >= maxContractQuantity)
                throw new BankException(BankErrorCode.MaxContractQuantity, "Max contract quantity.");
            contracts[contractCount++] = contract;
            contract.Number = contractCount;
        }

        public Contract Contract(string cardNumber)
        {
            for (int i = 0; i < contractCount; i++)
            {
                for (int j = 0; j < contracts[i].CardCount; j++)
                {
                    if (contracts[i].Cards[j].UniqueNumber == cardNumber)
                        return contracts[i];
                }
            }
            throw new BankException(BankErrorCode.CreditCardNotValid, "Credit card not valid");
        }
    }
}
