﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw6_20._09._17
{
    class Complex
    {
        public double A { get; set; }
        public double B { get; set; }

        public Complex(double a, double b)
        {
            A = a;
            B = b;
        }

        public override string ToString()
        {
            return $"{A}{B:+0;-#}i";
        }

        public static Complex operator-(Complex c1, Complex c2)
        {
            return new Complex(c1.A - c2.A, c1.B - c2.B);
        }

        public static Complex operator*(Complex c1, Complex c2)
        {
            var a = c1.A * c2.A - c1.B * c2.B;
            var b = c1.B * c2.A + c1.A * c2.B;
            return new Complex(a, b);
        }

        public static Complex operator *(int i, Complex c)
        {
            return new Complex(i, 0) * c;
        }

        public static Complex operator -(int i, Complex c)
        {
            return new Complex(i, 0) - c;
        }

        public static Complex operator -(Complex c, int i)
        {
            return c - new Complex(i, 0);
        }

        public static Complex operator/(Complex c1, Complex c2)
        {
            var a = (c1.A * c2.A + c1.B * c2.B) / (c2.A * c2.B + c2.A * c2.B);
            var b = (c1.B * c2.A - c1.A * c2.B) / (c2.A * c2.B + c2.A * c2.B);
            return new Complex(a, b);
        }
    }
}