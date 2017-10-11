using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace ExamCS_PilotSimulator
{
    public class Flight
    {
        public string PilotName { get; set; }
        public Plane Plane { get; set; }
        public City StartedCity { get; set; }
        public City FinishedCity { get; set; }

        public List<Dispatcher> Dispatchers { get; set; } = new List<Dispatcher>();

        public Flight(Plane plane, string pilotName, City startedCity, City finishedCity)
        {
            PilotName = pilotName;
            Plane = plane;
            StartedCity = startedCity;
            FinishedCity = finishedCity;
        }

        public void ChangeDispatcher()
        {

        }

        public void Start()
        {
            var timer = new Timer(500);
            timer.Elapsed += Timer_Elapsed;
            timer.Start();

            //Func<int, int> changeSpeed;
            //Func<int, int> changeHeignt;

            while (true)
            {
                var key = Console.ReadKey();
                var speedMultiplier = key.Modifiers.HasFlag(ConsoleModifiers.Shift) ? 3 : 1;
                var heightMultiplier = key.Modifiers.HasFlag(ConsoleModifiers.Shift) ? 2 : 1;

                Console.Clear();
                switch (key.Key)
                {
                    case ConsoleKey.UpArrow:
                        Console.WriteLine($"+{250 * heightMultiplier} m");
                        Plane.Speed += 250 * speedMultiplier;
                        break;
                    case ConsoleKey.DownArrow:
                        Console.WriteLine($"-{250 * heightMultiplier} m");
                        Plane.Speed -= 250 * speedMultiplier;
                        break;
                    case ConsoleKey.LeftArrow:
                        Console.WriteLine($"+{50 * speedMultiplier} km/h");
                        Plane.Height += 50 * heightMultiplier;
                        break;
                    case ConsoleKey.RightArrow:
                        Console.WriteLine($"-{50 * speedMultiplier} km/h");
                        Plane.Height -= 50 * heightMultiplier;
                        break;
                    default:
                        break;
                }
            }
        }

        public event EventHandler<FlightEvent> Change;
        public event EventHandler<ReccomentedEvent> Reccomented;

        public delegate int RecommentedHeight(int speed, int N);

        private void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            Change(this, new FlightEvent(Plane));

            RecommentedHeight recFirst = Dispatchers[0].ReccomentedHeight;
            Reccomented(this, new ReccomentedEvent(recFirst(Plane.Speed, StartedCity.HeightAdjustment), Dispatchers[0].Name, StartedCity.Name));

            RecommentedHeight recSecond = Dispatchers[1].ReccomentedHeight;
            Reccomented(this, new ReccomentedEvent(recFirst(Plane.Speed, FinishedCity.HeightAdjustment), Dispatchers[1].Name, FinishedCity.Name));
        }
    }

    public class ReccomentedEvent : EventArgs
    {
        public int ReccHeight { get; set; }
        public string DispatcherName { get; set; }
        public string CityName { get; set; }

        public ReccomentedEvent(int reccHeight, string dispatcherName, string cityName)
        {
            ReccHeight = reccHeight;
            DispatcherName = dispatcherName;
            CityName = cityName;
        }
    }

    public class FlightEvent : EventArgs
    {
        public Plane Plane { get; set; }

        public FlightEvent(Plane plane)
        {
            Plane = plane;
        }
    }
}
