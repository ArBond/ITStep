using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace ExamCS_PilotSimulator
{
    class Program
    {
        static List<City> GetCitiesData()
        {
            var random = new Random();
            var minsk = new City("Минск", new List<Dispatcher> { new Dispatcher("Михаил"), new Dispatcher("Андрей"), new Dispatcher("Павел") }, random.Next(-200, 200));
            var mosсow = new City("Москва", new List<Dispatcher> { new Dispatcher("Александр"), new Dispatcher("Генадий"), new Dispatcher("Максим") }, random.Next(-200, 200));
            var paris = new City("Париж", new List<Dispatcher> { new Dispatcher("Даниэль"), new Dispatcher("Пабло") }, random.Next(-200, 200));
            var sanFrancisco = new City("Сан-Франциско", new List<Dispatcher> { new Dispatcher("Вильям"), new Dispatcher("Дэвид") }, random.Next(-200, 200));
            var cities = new List<City>() { minsk, mosсow, paris, sanFrancisco };
            return cities;
        }

        static City ChooseCity(List<City> flightCities)
        {
            for (int i = 0; i < flightCities.Count; i++)
                Console.WriteLine($"{i + 1}: {flightCities[i].Name}");

            int choice = 0;
            do
                choice = int.Parse(Console.ReadLine());
            while (choice < 1 || choice > flightCities.Count);
            var city = flightCities[choice - 1];
            flightCities.Remove(city);
            return city;
        }

        static PlaneTypes ChoosePlane()
        {
            for(int i = 0; i < (int)PlaneTypes.EndingNoUsed; i++)
                Console.WriteLine($"{i + 1}: {(PlaneTypes)i}");
            int choice;
            do
                choice = int.Parse(Console.ReadLine());
            while (choice < 1 || choice > (int)PlaneTypes.EndingNoUsed);
            return (PlaneTypes)choice;
        }

        static void AddDispatcher(Flight flight, City startedCity)
        {
            Console.WriteLine($"Доступные диспетчеры({startedCity.Name}): ");
            for (int i = 0; i < startedCity.Dispatchers.Count; i++)
                Console.WriteLine($"{i + 1}: {startedCity.Dispatchers[i].Name}");
            int choice;
            do
                choice = int.Parse(Console.ReadLine());
            while (choice < 1 || choice > startedCity.Dispatchers.Count);
            flight.Dispatchers.Add(startedCity.Dispatchers[choice - 1]);
        }

        static void Main(string[] args)
        {
            var flightCities = GetCitiesData();

            Console.WriteLine("Добро пожаловать в тренажер пилота самолета!\nВведите ваше имя пилот: ");
            var pilotName = Console.ReadLine();

            Console.WriteLine($"На каком самолете будете тренироваться? Достуны следующие самолеты:");
            var planeType = ChoosePlane();

            Console.WriteLine("Выберите место старта. Доступные города:");
            var startedCity = ChooseCity(flightCities);
            Console.WriteLine("Выберите место финиша. Доступные города:");
            var finishedCity = ChooseCity(flightCities);

            var flight = new Flight(new Plane(planeType), pilotName, startedCity, finishedCity);

            Console.WriteLine($"{startedCity.Name} -> {finishedCity.Name}.\nОтлично, для начала полета надо связаться с диспетчерами точек отправления  и прибытия:");
            AddDispatcher(flight, startedCity);
            AddDispatcher(flight, finishedCity);

            Console.ReadLine();

            flight.Change += Flight_Change;
            flight.Reccomented += Flight_Reccomented;
            flight.Start();
        }

        private static void Flight_Reccomented(object sender, ReccomentedEvent e)
        {
            Console.WriteLine($"Диспетчер {e.DispatcherName}({e.CityName}): рекомендованая высота: {e.ReccHeight}");
        }

        private static void Flight_Change(object sender, FlightEvent e)
        {
            Console.Clear();
            Console.WriteLine($"{e.Plane.PlaneType}: скорость: {e.Plane.Speed}, высота: {e.Plane.Height}");
        }
    }
}
