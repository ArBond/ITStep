using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace ExamCS_PilotSimulator
{
    public class City
    {
        public string Name { get; set; }

        public int HeightAdjustment { get; set; }

        public List<Dispatcher> Dispatchers { get; set; }

        public City(string name, List<Dispatcher> dispatchers, int heightAdjustment)
        {
            HeightAdjustment = heightAdjustment;
            Name = name;
            Dispatchers = dispatchers;
        }
    }
}