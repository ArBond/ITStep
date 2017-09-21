using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson8
{
    public class Square
    {
        public int A { get; set; }

        public static implicit operator Square(int a) // вместо обычного контруктора;   Square s = 10;  вместо  var s = new Square(){10}
        {
            return new Square() { A = a };
        }

        public static explicit operator Square(Rectangle r) // из прямоугольника делаем квадрат; стр 23 в program.cs
        {
            return new Square() { A = Math.Min(r.Height, r.Width) };
        }
    }
}
