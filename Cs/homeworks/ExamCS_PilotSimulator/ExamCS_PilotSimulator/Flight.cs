using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamCS_PilotSimulator
{
    public class Flight
    {
        public Pilot Pilot { get; set; }
        public Plane Plane { get; set; }
        public List<Dispatcher> Dispatchers { get; set; } = new List<Dispatcher>();

        public Flight(Pilot pilot, Plane plane)
        {
            Pilot = pilot;
            Plane = plane;
        }

        public void AddDispatcher(Dispatcher dispatcher)
        {
            Dispatchers.Add(dispatcher);
        }

        public void DeleteDispatcher(Dispatcher dispatcher)
        {
            if (Dispatchers.Count > 2)
                Dispatchers.Remove(dispatcher);
            else
                throw new InvalidOperationException();
        }
    }
}
