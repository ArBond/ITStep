using System;

namespace Bank
{
    [Serializable]
    public class BankException : Exception
    {
        public BankErrorCode ErrorCode { get; set; }

        public BankException(BankErrorCode errorCode, string message) : this(message)
        {
            ErrorCode = errorCode;
        }

        public BankException() { }
        public BankException(string message) : base(message) { }
        public BankException(string message, Exception inner) : base(message, inner) { }
        protected BankException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
