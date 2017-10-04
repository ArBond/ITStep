using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace hw8_25._09._17
{
    public class Team
    {
        public List<Worker> workers = new List<Worker>
        {
            new Worker("Dima"),
            new Worker("Petya"),
            new Worker("Gena"),
            new Worker("Sasha")
        };
        public TeamLeader TeamLeader = new TeamLeader("Abdul");

        public void Build(House house)
        {
            var parts = new StringBuilder();
            var buff = new StringBuilder();
            foreach(var part in house.parts)
            {
                Thread.Sleep(1000);
                Console.Clear();
                buff.Clear();
                buff.Append(part.Build());
                buff.Append(parts);
                parts.Clear();
                parts.Append(buff);

                Console.WriteLine(parts);
            }
        }
    }
}
