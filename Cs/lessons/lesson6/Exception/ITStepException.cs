using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson6_exceptions
{
    [Serializable]
    public class ITStepException : Exception
    {
        public ITStepException() { }
        public ITStepException(string message) : base(message) { }
        public ITStepException(string message, Exception inner) : base(message, inner) { }
        protected ITStepException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
