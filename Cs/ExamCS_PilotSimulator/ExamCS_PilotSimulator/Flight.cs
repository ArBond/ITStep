using System;

namespace ExamCS_PilotSimulator
{
    public class Flight
    {
        public string PilotName { get; set; }
        public Plane Plane { get; set; }
        public City StartedCity { get; set; }
        public City FinishedCity { get; set; }
        public int MaxSpeed { get; set; } = 1000;
        public int MyProperty { get; set; }
        public bool MissionCompleted { get; set; } = false;

        Action printMissionCompleted = Program.PrintMissionCompleted;
        Action<int> printResultPenaltyPoints = Program.PrintResult;
        Action<int, string> printAddedPenaltyPoints = Program.PrintAddedPenaltyPoints;
        Action<string, string, int> printReccomendation = Program.PrintReccomendation;

        public event EventHandler<ChangeDispatcherArgs> ChangeDispatcher;
        public event EventHandler<ChangePlaneParamsArgs> ChangePlane;

        public Flight(Plane plane, string pilotName, City startedCity, City finishedCity)
        {
            PilotName = pilotName;
            Plane = plane;
            StartedCity = startedCity;
            FinishedCity = finishedCity;
        }
        
        public void Start()
        {
            while (CheckFlightFinish() == false)
            {
                ChangePlane(this, new ChangePlaneParamsArgs(Plane));
                PrintReccomendationAndPealtyPoints(StartedCity, printReccomendation);
                PrintReccomendationAndPealtyPoints(FinishedCity, printReccomendation);
                CheckMissionCimpleted();

                var key = Console.ReadKey();
                var speedMultiplier = key.Modifiers.HasFlag(ConsoleModifiers.Shift) ? 3 : 1;
                var heightMultiplier = key.Modifiers.HasFlag(ConsoleModifiers.Shift) ? 2 : 1;

                switch (key.Key)
                {
                    case ConsoleKey.RightArrow:
                        Plane.Speed += 50 * speedMultiplier;
                        break;
                    case ConsoleKey.LeftArrow:
                        Plane.Speed -= 50 * speedMultiplier;
                        if (Plane.Speed < 0)
                            Plane.Speed = 0;
                        break;
                    case ConsoleKey.UpArrow:
                        if (Plane.Speed > 0)
                            Plane.Height += 250 * heightMultiplier;
                        break;
                    case ConsoleKey.DownArrow:
                        if (Plane.Speed > 0)
                            Plane.Height -= 250 * heightMultiplier;
                        break;
                    case ConsoleKey.D:
                        ChangeDispatcher(this, new ChangeDispatcherArgs(StartedCity, FinishedCity));
                        break;
                    default:
                        break;
                }
            }
            PrintResult();
        }

        private void CheckMissionCimpleted()
        {
            if (Plane.Speed >= MaxSpeed)
                MissionCompleted = true;
            if(MissionCompleted)
                printMissionCompleted();
        }

        private bool CheckFlightFinish()
        {
            if (MissionCompleted == true)
                if (Plane.Height == 0 && Plane.Speed == 0)
                    return true;
            return false;
        }

        private void PrintResult()
        {
            int points = 0;
            foreach (var dispatcher in StartedCity.Dispatchers)
                points += dispatcher.PenaltyPoints;
            foreach (var dispatcher in FinishedCity.Dispatchers)
                points += dispatcher.PenaltyPoints;
            printResultPenaltyPoints(points);
        }

        private void PrintReccomendationAndPealtyPoints(City city, Action<string, string, int> printReccomendation)
        {
            
            foreach (var dispatcher in city.Dispatchers)
            {
                if (dispatcher.IsActive)
                {
                    var result = dispatcher.CheckPlaneParams(Plane.Speed, Plane.Height, MaxSpeed, city.HeightAdjustment);
                    if(Plane.Speed > 50)
                        printReccomendation(dispatcher.Name, city.Name, dispatcher.ReccomentedHeight);
                    if (result == false)
                        dispatcher.AddPenaltyPoints(printAddedPenaltyPoints, Plane.Height, Plane.Speed, MaxSpeed);
                    break;
                }
            }
        }
    }

    public class ChangeDispatcherArgs : EventArgs
    {
        public City StatrCity { get; set; }
        public City FinishedCity { get; set; }

        public ChangeDispatcherArgs(City statrCity, City finishedCity)
        {
            StatrCity = statrCity;
            FinishedCity = finishedCity;
        }
    }

    public class ChangePlaneParamsArgs : EventArgs
    {
        public Plane Plane { get; set; }

        public ChangePlaneParamsArgs(Plane plane)
        {
            Plane = plane;
        }
    }
}