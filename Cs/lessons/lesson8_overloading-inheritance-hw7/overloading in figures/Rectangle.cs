using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson8
{
    public class Rectangle
    {
        public int Height { get; set; }
        public int Width { get; set; }

        public static implicit operator Rectangle(Square s) // из квдарата в прямоугольник
        {
            return new Rectangle() { Height = s.A, Width = s.A };
        }
    }
}
