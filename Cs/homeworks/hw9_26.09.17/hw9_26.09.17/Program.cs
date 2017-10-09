using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw9_26._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            var race = new Race(100);
            race.CarStarted += Race_CarStarted;
            race.CarMoved += Race_CarMoved;
            race.CarFinished += Race_CarFinished;
            race.Start();
        }

        private static void Race_CarMoved(object sender, RaceEventArgs e)
        {
            Console.WriteLine($"{e.Car.Mark}:  speed: {e.Car.Speed} km/h,   distance: {e.Car.Distance} m.");
        }

        private static void Race_CarStarted(object sender, RaceEventArgs e)
        {
            Console.WriteLine($"{e.Car.Mark} is started!");
            e.Car.InRace = true;
        }

        private static void Race_CarFinished(object sender, RaceEventArgs e)
        {
            Console.WriteLine($"{e.Car.Mark} is finished!");
            e.Car.InRace = false;
        }
    }
}
