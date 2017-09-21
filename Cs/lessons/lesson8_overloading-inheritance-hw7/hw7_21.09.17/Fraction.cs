using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw7_21._09._17
{
    class Fraction
    {
        public int N { get; set; }
        public int D { get; set; }

        public Fraction(int n, int d)
        {
            if (d == 0)
                throw new ArgumentException("Denominator cannot be 0");
            N = n;
            D = d;
        }

        public static Fraction operator *(Fraction f, int i)
        {
            return new Fraction(f.N * i, f.D);
        }

        public static Fraction operator *(int i, Fraction f)
        {
            return f * i;
        }

        public static implicit operator Fraction(double d) // преобразование double в дробь
        {
            return new Fraction((int)(d * 1000), 1000); // 1000 - точность в 3 знака после запятой;
        }
        public static Fraction operator +(Fraction f1, Fraction f2)
        {
            return new Fraction(f1.N * f2.D + f2.N + f1.D, f1.D + f2.D);
        }
    }
}