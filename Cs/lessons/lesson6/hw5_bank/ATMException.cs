using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw5_19._09._17
{

    [Serializable]
    public class ATMException : Exception
    {
        public ErrorCode ErrorCode { get; set; }

        public ATMException(ErrorCode errorCode, string message) : this(message)
        {
            ErrorCode = errorCode;
        }
        public int remainingAttemps { get; set; }
        public ATMException() { }
        public ATMException(string message) : base(message) { }
        public ATMException(string message, Exception inner) : base(message, inner) { }
        protected ATMException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}