using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw5_19._09._17
{

    [Serializable]
    public class CreditCardLockException : Exception
    {
        public CreditCardLockException() { }
        public CreditCardLockException(string message) : base(message) { }
        public CreditCardLockException(string message, Exception inner) : base(message, inner) { }
        protected CreditCardLockException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
