using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson11_1
{
    public class Student
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public DateTime BirthDay { get; set; }

        public override int GetHashCode()
        {
            return (Name + Surname).GetHashCode();
        }
    }
}
