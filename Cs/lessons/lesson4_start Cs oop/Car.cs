using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson4
{
    class Car
    {
        private readonly string mModel;
        private int mSpeed = 0;
        private int mMaxSpeed;
        private FuelTung mFuelTung;
        private Driver mDriver;

        public Car(string model, int maxSpeed, FuelTung tung, Driver driver)
        {
            mModel = model;
            mMaxSpeed = maxSpeed;
            mFuelTung = tung;
            mDriver = driver;
        }

        public int GetSpeed() => mSpeed;
        public void Accelerate()
        {
            mSpeed += 10;
        }
        public void Brake()
        {
            if (mSpeed - 10 >= 0)
                mSpeed -= 10;
        }
    }
}
