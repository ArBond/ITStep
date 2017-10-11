using System;
using System.Collections.Generic;
using System.Threading;

namespace ExamCS_PilotSimulator
{
    class Program
    {
        static void Main(string[] args)
        {
            var flight = GetPreFlightInformation();

            Console.WriteLine($"Отлично, для начала полета надо связаться с диспетчерами точек отправления и прибытия:");
            AddDispatcher(flight, flight.StartedCity);
            AddDispatcher(flight, flight.FinishedCity);

            flight.ChangePlane += Flight_Change;
            flight.ChangeDispatcher += Flight_ChangeDispatcher;

            Console.WriteLine("Для начала полета нажмите любую клавишу:");
            Console.ReadLine();

            try
            {
                flight.Start();
            }
            catch (FlightException ex)
            {
                Console.WriteLine(ex.Message);
                Thread.Sleep(3000);
            }
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
            return (PlaneTypes)(choice - 1);
        }

        static void AddDispatcher(Flight flight, City city)
        {
            Console.WriteLine($"Доступные диспетчеры({city.Name}): ");
            for (int i = 0; i < city.Dispatchers.Count; i++)
                Console.WriteLine($"{i + 1}: {city.Dispatchers[i].Name}");
            int choice;
            do
                choice = int.Parse(Console.ReadLine());
            while (choice < 1 || choice > city.Dispatchers.Count);
            city.Dispatchers[choice - 1].IsActive = true;
        }

        static Flight GetPreFlightInformation()
        {
            var flightCities = CitiseData.GetData();

            Console.WriteLine("Добро пожаловать в тренажер пилота самолета!\nВведите ваше имя пилот: ");
            var pilotName = Console.ReadLine();
            Console.Clear();

            Console.WriteLine($"На каком самолете будете тренироваться? Достуны следующие самолеты:");
            var planeType = ChoosePlane();
            Console.Clear();

            Console.WriteLine("Выберите место старта. Доступные города:");
            var startedCity = ChooseCity(flightCities);
            Console.WriteLine("Выберите место финиша:");
            var finishedCity = ChooseCity(flightCities);
            Console.Clear();

            return new Flight(new Plane(planeType), pilotName, startedCity, finishedCity);
        }

        public static void PrintMissionCompleted()
        {
            Console.WriteLine($"Задание выполнено. Посадите самолет.");
        }

        public static void PrintResult(int points)
        {
            Console.WriteLine($"Ваш результат: {points} штрафных очков.");
        }

        public static void PrintAddedPenaltyPoints(int points, string message)
        {
            Console.WriteLine($"+ {points} штрафных очков. {message}");
        }

        public static void PrintReccomendation(string dispatcherName, string cityName, int reccomentedHeihgt)
        {
            Console.WriteLine($"Диспетчер {dispatcherName}({cityName}): рекомендованая высота: {reccomentedHeihgt}");
        }

        private static void Flight_ChangeDispatcher(object sender, ChangeDispatcherArgs e)
        {
            Dispatcher firstActiveDispatcher = null;
            Dispatcher secondActiveDispatcher = null;
            List<Dispatcher> NoActiveDistpatchersInStartCity = new List<Dispatcher>();
            List<Dispatcher> NoActiveDistpatchersInFinishedCity = new List<Dispatcher>();
            Console.Clear();
            Console.WriteLine("Какого диспетчера хотите сменить?");
            foreach (var dispetcher in e.StatrCity.Dispatchers)
            {
                if (dispetcher.IsActive)
                {
                    firstActiveDispatcher = dispetcher;
                    Console.WriteLine($"1 - {dispetcher.Name}({e.StatrCity.Name})");
                }
                else
                    NoActiveDistpatchersInStartCity.Add(dispetcher);
            }
            foreach (var dispetcher in e.FinishedCity.Dispatchers)
            {
                if (dispetcher.IsActive)
                {
                    secondActiveDispatcher = dispetcher;
                    Console.WriteLine($"2 - {dispetcher.Name}({e.FinishedCity.Name})");
                }
                else
                    NoActiveDistpatchersInFinishedCity.Add(dispetcher);
            }

            int choice;
            do
                choice = int.Parse(Console.ReadLine());
            while (choice < 1 || choice > 2);

            if (choice == 1)
            {
                if (e.StatrCity.Dispatchers.Count > 1)
                {
                    ChangeDispatcher(NoActiveDistpatchersInStartCity);
                    firstActiveDispatcher.IsActive = false;
                }
                else
                    Console.WriteLine("Извините но в этом городе больше нет свободных диспетчеров");
            }
            else
            {
                if (e.FinishedCity.Dispatchers.Count > 1)
                {
                    secondActiveDispatcher.IsActive = false;
                    ChangeDispatcher(NoActiveDistpatchersInFinishedCity);
                }
                else
                    Console.WriteLine("Извините но в этом городе больше нет свободных диспетчеров");
            }
        }

        private static void ChangeDispatcher(List<Dispatcher> dispatchers)
        {
            Console.WriteLine($"Свободные диспетчеры:");
            for (int i = 0; i < dispatchers.Count; i++)
                Console.WriteLine($"{i + 1}: {dispatchers[i].Name}");
            int choice;
            do
                choice = int.Parse(Console.ReadLine());
            while (choice < 1 || choice > dispatchers.Capacity);
            dispatchers[choice - 1].IsActive = true;
        }

        private static void Flight_Change(object sender, ChangePlaneParamsArgs e)
        {
            Console.Clear();
            Console.WriteLine($"{e.Plane.PlaneType}: скорость: {e.Plane.Speed}, высота: {e.Plane.Height}");
        }
    }
}