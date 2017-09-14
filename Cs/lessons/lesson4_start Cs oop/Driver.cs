using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson4
{
    class Driver
    {
        private string mName;
        private int mExperience;

        public Driver(string name, int experience)
        {
            mName = name;
            mExperience = experience;
        }
        public string GetName() => mName;
    }
}
