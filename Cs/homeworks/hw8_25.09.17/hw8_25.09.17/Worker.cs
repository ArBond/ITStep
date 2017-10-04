using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    public class Worker : IWorker
    {
        public string Name { get; set; }

        public Worker(string name)
        {
            Name = name;
        }

        public bool Check(House house)
        {
            return true; //ничего полезного не придумал
        }
    }
}
