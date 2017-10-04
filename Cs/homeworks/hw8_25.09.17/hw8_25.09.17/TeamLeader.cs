using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    public class TeamLeader: IWorker
    {
        public string Name { get; set; }

        public TeamLeader(string name)
        {
            Name = name;
        }

        public bool Check(House house)
        {
            int buildWindowsCount = 0;
            int buildWallsCount = 0;
            int buildBasementLayers = 0;
            int buildDoor = 0;

            int count;
            for (count = 0; count < house.basementLayersQuantity; count++)
            {
                if (house.parts[count].IsBuild)
                    buildBasementLayers++;
            }
            if (house.parts[count++].IsBuild)
                buildDoor++;
            for (int i = 0; i < (house.WindowQuantity < house.WallsQuantity ? house.WindowQuantity * 2 : house.WallsQuantity * 2); i++)
            {
                if (house.parts[count++].IsBuild)
                    buildWallsCount++;
                if (house.parts[count++].IsBuild)
                    buildWindowsCount++;
            }
            for (int i = 0; i < house.WallsQuantity; i++)
            {
                if (house.parts[count++].IsBuild)
                    buildWallsCount++;
            }

            if (house.parts[count].IsBuild)
            {
                Console.WriteLine("House is build");
                return true;
            }
            else
            {
                var report = new StringBuilder();
                if (buildBasementLayers != 0)
                    report.Append($"{buildBasementLayers} layers basement build;\n");
                if(buildDoor != 0)
                    report.Append($"Door is build;\n");
                if(buildWallsCount != 0)
                    report.Append($"{buildWallsCount} walls are build;\n");
                if(buildWindowsCount != 0)
                    report.Append($"{buildWindowsCount} windows are build;\n");
                Console.WriteLine(report);
                return false;
            }
        }
    }
}
