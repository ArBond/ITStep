using System;
using System.IO;
using System.Xml;

namespace lesson15_xml
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Выберите город:");
            int idx = 1;
            foreach (var city in Configuration.Instance.Cities)
                Console.WriteLine($"{idx++}: {city.Name}");
            idx = int.Parse(Console.ReadLine());
            var selectedCity = Configuration.Instance.Cities[idx - 1];

            var manager = new WeatherManager();
            var cityWeather = manager.LoadWeather(selectedCity);

            Console.WriteLine($"Погода в городе {cityWeather.City.Name}:");
            foreach(var item in cityWeather.WeatherItems)
            {
                Console.WriteLine($"{item.TimeOfDay} {item.Date.ToString("dd, MM, yyyy")}:   {item.LowTemperature} - {item.HighTemperature} C");
            }
        }
    }
}
