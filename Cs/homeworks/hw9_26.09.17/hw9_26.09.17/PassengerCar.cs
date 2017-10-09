using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw9_26._09._17
{
    public class PassengerCar : Car
    {
        public PassengerCar() : base("Volvo", 300)
        {
        }

        public override void Move()
        {
            var random = new Random();
            Speed += random.Next() % 40 - 15;
            if (Speed > MaxSpeed)
                Speed = MaxSpeed;
            else if (Speed < 0)
                Speed = 0;

            Distance += (int)(Speed / 3.6);
        }
    }
}
