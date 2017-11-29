using System;

namespace ExamCS_PilotSimulator
{

    [Serializable]
    public class FlightException : Exception
    {
        public FlightException() { }
        public FlightException(string message) : base(message) { }
        public FlightException(string message, Exception inner) : base(message, inner) { }
        protected FlightException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
