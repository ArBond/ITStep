using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson15_xml
{
    public class CityWeather
    {
        public City City { get; set; }
        public List<Weather> WeatherItems { get; private set; } = new List<Weather>();
    }
}
