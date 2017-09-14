using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks; 

namespace lesson4
{
    class Program
    {
        static void Main(string[] args)
        {
            //var student = new Student("Tolik");

            //student.mAge = 1;
            //Student.s = " ";

            //var name = "Artem";
            //student.SayHello(student, name);
            //Console.WriteLine(student.Ansver("You cool?"));

            //Console.Write($"Age: {student.GetAge()}");

            //Console.WriteLine();
            //string answer;
            //if(student.TryAnswer(out answer))
            //{
            //    Console.WriteLine(answer);
            //}
            //student.SayHello("Artem");
            //student.SayHello("Artem", " Sergey", " Sahsa");

            //Console.WriteLine($"Hight: {student.GetHight()} sm");

            FuelTung tang = new FuelTung("95", 50);
            Driver driver = new Driver("Popov Vasili", 10);
            Car car = new Car("Audi", 300, tang, driver);

            int distance = 0;
            int lap = 0;
            var random = new Random();

            while (true)
            {
                if (random.Next() % 2 == 0)
                    car.Accelerate();
                else
                    car.Brake();
                distance += car.GetSpeed();
                Console.WriteLine($"Driver: {driver.GetName()}, Speed: {car.GetSpeed()} Distance: {distance} Lap: {lap}");
                if (distance >= 1000)
                {
                    distance = car.GetSpeed() * 5;
                    lap++;
                }

                System.Threading.Thread.Sleep(1000);
            }
        }
    }
}
