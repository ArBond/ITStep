using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamCS_PilotSimulator
{
    public class Dispatcher
    {
        public string Name { get; set; }

        public int PenaltyPoints { get; set; }

        public Dispatcher(string name)
        {
            Name = name;
        }

        public int ReccomentedHeight(int speed, int N)
        {
            return (7 * speed + N);
        }
    }
}
