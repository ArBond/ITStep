using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamCS_PilotSimulator
{
    public class Flight
    {
        public City StartCity { get; set; } = new City("Minsk");
        public City FinishCity { get; set; }
        public Pilot Pilot { get; set; }
        public Plane Plane { get; set; } = new Plane("777");
        public List<Dispatcher> Dispatchers { get; set; } = new List<Dispatcher>();

        public Flight(Pilot pilot, City finishCity)
        {
            Pilot = pilot;
            FinishCity = finishCity;
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
                Console.WriteLine();
        }
    }
}
