using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            var house = new House(1, 4, 4);
            var team = new Team();
            team.Build(house);
        }
    }
}
