using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw5_19._09._17
{

    [Serializable]
    public class CreditCardPinException : Exception
    {
        public int remainingAttemps { get; set; }
        public CreditCardPinException() { }
        public CreditCardPinException(string message) : base(message) { }
        public CreditCardPinException(string message, Exception inner) : base(message, inner) { }
        protected CreditCardPinException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
