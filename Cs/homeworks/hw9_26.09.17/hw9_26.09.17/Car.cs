using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw9_26._09._17
{
    public abstract class Car
    {
        public bool InRace { get; set; }
        public int Speed { get; protected set; }
        public int MaxSpeed { get; private set; }
        public int Distance { get; protected set; }
        public string Mark { get; private set; }

        public Car(string mark, int maxSpeed)
        {
            Mark = mark;
            MaxSpeed = maxSpeed;
        }

        public abstract void Move();
    }
}
