using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw5_19._09._17
{
    public class CreditCard
    {
        private string pin;
        private int failsCount = 0;
        private const int maxAttempts = 3;
        private string Number { get; set; }
        public CreditCard(string number, string pin)
        {
            this.pin = pin;
            this.Number = number;
        }

        public void Authorize(string pin)
        {
            if (this.pin != pin)
            {
                failsCount++;
                if (failsCount == maxAttempts)
                    throw new CreditCardLockException("Card Blocked");
                throw new CreditCardPinException($"Pin error! Trys: {maxAttempts - failsCount}")
                {
                    remainingAttemps = maxAttempts - failsCount
                };
            }
        }
    }
}
