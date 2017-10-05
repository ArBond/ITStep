using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson15_xml
{
    public class Weather
    {
        public TimeOfDay TimeOfDay { get; set; }
        public DateTime Date { get; set; }
        public int LowTemperature { get; set; }
        public int HighTemperature { get; set; }
    }
}
