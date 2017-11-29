using System;

namespace ExamCS_PilotSimulator
{
    public class Dispatcher
    {
        public string Name { get; set; }
        public int PenaltyPoints { get; set; }
        public int ReccomentedHeight { get; set; }
        public bool IsActive { get; set; } = false;
        public bool IsPilotMissionCompleted { get; set; } = false;

        public Dispatcher(string name)
        {
            Name = name;
        }

        public void AddPenaltyPoints(Action<int, string> printPoints, int height, int speed, int maxSpeed)
        {
            int points = 0;
            string message = "";
            if (speed > maxSpeed)
            {
                message = "Немедленно снизте скорость!";
                points += 100;
            }
            if (Math.Abs(height - ReccomentedHeight) > 600)
                points += 50;
            else if (Math.Abs(height - ReccomentedHeight) > 300)
                points += 25;
            PenaltyPoints += points;
            if(speed > 50)
                printPoints(points, message);
        }

        public bool CheckPlaneParams(int speed, int height, int maxSpeed, int N)
        {
            ReccomentedHeight = 7 * speed + N;
            if(height < 0)
                throw new FlightException("Земля близко! Самолет разбился.");
            if (speed == 0 && height != 0)
                throw new FlightException("Нулевая скорость! Штопор! Самолет разбился.");
            if(Math.Abs(height - ReccomentedHeight) > 1000)
                throw new FlightException("Слишком большое отклонение от рекомендуемой высоты (больше 1000 м). Вы непригодны.");
            if(PenaltyPoints >= 1000)
                throw new FlightException("Вы набрали 1000 штрафных очков от одного диспетчера. Вы непригодны.");
            if (speed > maxSpeed || Math.Abs(height - ReccomentedHeight) > 300)
                return false;
            return true;
        }
    }
}
