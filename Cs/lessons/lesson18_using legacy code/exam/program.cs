using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamCS_PilotSimulator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Добро пожаловать в тренажер для пилотов!\nВведите ваше имя, пилот:");
            var pilot = new Pilot(Console.ReadLine());
            var startCityName = "Минск";
            Console.WriteLine($"Точка отправления: {startCityName}");
        }
    }
}
