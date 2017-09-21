using System;

namespace lesson8_inheritance
{
    public class Student: Human
    {
        public Student(): base("Undefined")
        {
            Console.WriteLine("Studemt.");
        }

        public override void Print()
        {
            throw new NotImplementedException();
        }

        public override void SayHello()
        {
            Console.WriteLine("Hello from student!");
        }
    }
}