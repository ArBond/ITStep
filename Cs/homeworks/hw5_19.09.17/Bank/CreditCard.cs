using System;

namespace Bank
{
    public class CreditCard
    {
        private string pin;
        private string uniqueNumber;
        private int failsCount = 0;
        private const int maxAttempts = 3;

        public string UniqueNumber { get { return uniqueNumber; } }

        public CreditCard(string pin, string uniqueNumber)
        {
            this.pin = pin;
            this.uniqueNumber = uniqueNumber;
        }

        public void Authorize(string pin)
        {
            if (this.pin != pin)
            {
                failsCount++;
                if (failsCount == maxAttempts)
                    throw new BankException(BankErrorCode.CreditCardLock, "Card Blocked");
                throw new BankException(BankErrorCode.CreditCardWrongPin, $"Pin error! Trys: {maxAttempts - failsCount}");
            }
            failsCount = 0;
        }
    }
}
