using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamCS_PilotSimulator
{
    public class Dispatcher
    {
        public string Name { get; set; }

        public bool IsActive { get; set; } = false;

        public City City { get; set; }

        public Dispatcher(string name, City city)
        {
            Name = name;
            City = city;
        }
    }
}
