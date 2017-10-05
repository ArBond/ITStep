using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml;

namespace lesson15_xml
{
    public class WeatherManager
    {
        public const string ArchiveDirectoryName = "Archive";
        public readonly Dictionary<string, TimeOfDay> timesOfDay = new Dictionary<string, TimeOfDay>
        {
            ["Утро"] = TimeOfDay.Morning,
            ["День"] = TimeOfDay.Afternoon,
            ["Вечер"] = TimeOfDay.Evening,
            ["Ночь"] = TimeOfDay.Night
        };

        private void DownLoad(City city, string fileName)
        {
            var url = $"http://informer.gismeteo.by/rss/{city.Code}.xml";

            using (var reader = new XmlTextReader(url))
            {
                if (!Directory.Exists(ArchiveDirectoryName))
                    Directory.CreateDirectory(ArchiveDirectoryName);

                var document = new XmlDocument();
                document.Load(reader);
                document.Save(fileName);
            }
        }

        private CityWeather Parse(string fileName, City city)
        {
            var cityWeather = new CityWeather() { City = city};
            using (var reader = new XmlTextReader(File.OpenRead(fileName)))
            {
                var document = new XmlDocument();
                document.Load(reader);
                var items = document.GetElementsByTagName("item");
                foreach (XmlNode item in items)
                {
                    var weather = new Weather();
                    foreach (XmlNode node in item.ChildNodes)
                    {
                        if (node.Name == "title")
                        {
                            var regex = new Regex(@"(\w+): (Утро|День|Вечер|Ночь) (\d\d \w\w\w, \w\w\w)");
                            var match = regex.Match(node.InnerText);
                            if (match == null || !match.Success)
                                throw new FormatException("Invalid format");
                            weather.TimeOfDay = timesOfDay[match.Groups[2].Value];
                            weather.Date = DateTime.Parse(match.Groups[3].Value);
                        }
                        else if (node.Name == "description")
                        {
                            var match = Regex.Match(node.InnerText, @"(-?\d+)\.\.(-?\d+) С");
                            weather.LowTemperature = int.Parse(match.Groups[1].Value);
                            weather.HighTemperature = int.Parse(match.Groups[2].Value);
                        }
                    }
                    cityWeather.WeatherItems.Add(weather);
                } 
            }
            return cityWeather;
        }

        public CityWeather LoadWeather(City city)
        {
            var fileName = $"{ArchiveDirectoryName}\\{city.Name}_{DateTime.Now.ToString("dd.MM.yyyy")}.xml";
            var fileInfo = new FileInfo(fileName);

            if (!fileInfo.Exists || (DateTime.Now - fileInfo.LastWriteTime).Hours > 0)
                DownLoad(city, fileName);

            return Parse(fileName, city);
        }
    }
}