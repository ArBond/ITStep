using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw7_21._09._17
{
    public class Fraction
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

        public static implicit operator Fraction(int i)
        {
            return new Fraction(i, 1);
        }

        public static implicit operator Fraction(double d)
        {
            return new Fraction((int)(d * 100000), 100000).Reduce();
        }

        public static Fraction operator +(Fraction f1, Fraction f2)
        {
            return new Fraction(f1.N * f2.D + f2.N * f1.D, f1.D * f2.D).Reduce();
        }

        public static Fraction operator -(Fraction f1, Fraction f2)
        {
            return new Fraction(f1.N * f2.D - f2.N * f1.D, f1.D * f2.D).Reduce();
        }

        public static Fraction operator *(Fraction f1, Fraction f2)
        {
            return new Fraction(f1.N * f2.N, f1.D * f2.D).Reduce();
        }

        public static Fraction operator /(Fraction f1, Fraction f2)
        {
            return new Fraction(f1.N * f2.D, f1.D * f2.N).Reduce();
        }

        public static bool operator ==(Fraction f1, Fraction f2)
        {
            return f1.N / f1.D == f2.N / f2.D;
        }

        public static bool operator !=(Fraction f1, Fraction f2)
        {
            return !(f1 == f2);
        }

        public static bool operator >(Fraction f1, Fraction f2)
        {
            return f1.N / f1.D > f2.N / f2.D;
        }

        public static bool operator <(Fraction f1, Fraction f2)
        {
            return !(f1 > f2);
        }

        public static bool operator true(Fraction f)
        {
            return f.N < f.D;
        }

        public static bool operator false(Fraction f)
        {
            return f.N > f.D;
        }

        public Fraction Reduce()
        {
            var n = Math.Abs(N);
            var d = Math.Abs(D);
            while (Math.Abs(n) != Math.Abs(d))
            {
                if (n > d)
                    n = n - d;
                else d = d - n;
            }
            N /= n;
            D /= n;
            return new Fraction(N, D);
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return $"{N}/{D}";
        }
    }
}
