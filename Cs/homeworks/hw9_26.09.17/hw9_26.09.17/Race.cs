using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace hw9_26._09._17
{
    public class Race
    {
        public int Distance { get; private set; }
        public List<Car> Cars { get; private set; } = new List<Car>()
        { new PassengerCar(), new SportCar(), new Bus(), new FreightCar()};

        public Race(int distance)
        {
            Distance = distance;
        }

        public event EventHandler<RaceEventArgs> CarStarted;
        public event EventHandler<RaceEventArgs> CarFinished;
        public event EventHandler<RaceEventArgs> CarMoved;

        public void Start()
        {
            foreach (var car in Cars)
                CarStarted(car, new RaceEventArgs(car));
            var timer = new Timer(1000);
            timer.Elapsed += Timer_Elapsed;
            timer.Start();
            Console.ReadLine();
        }

        private void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            Console.Clear();
            foreach (var car in Cars)
            {
                if (car.InRace)
                {
                    car.Move();
                    CarMoved(car, new RaceEventArgs(car));
                    if (car.Distance >= Distance)
                        CarFinished(car, new RaceEventArgs(car));
                }
            }
        }
    }

    public class RaceEventArgs : EventArgs
    {
        public Car Car { get; private set; }

        public RaceEventArgs(Car car)
        {
            Car = car;
        }
    }
}