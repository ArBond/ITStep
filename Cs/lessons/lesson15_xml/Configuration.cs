using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;

namespace lesson15_xml
{
    public sealed class Configuration
    {
        public static Configuration Instance { get; private set; } = new Configuration();

        private Configuration()
        {
            Load();
        }

        public List<City> Cities { get; private set; } = new List<City>();

        private void Load()
        {
            using (var file = File.OpenRead("Cities.config"))
            {
                var reader = new XmlTextReader(file);
                while(reader.Read())
                {
                    if(reader.Name == "city")
                    {
                        var cityName = reader.GetAttribute("Name");
                        var cityCode = reader.GetAttribute("Code");
                        var city = new City()
                        {
                            Name = cityName,
                            Code = cityCode
                        };
                        Cities.Add(city);
                    }
                }
            }
        }
    }
}
