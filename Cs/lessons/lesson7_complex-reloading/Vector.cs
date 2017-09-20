using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson7
{
    public class Vector
    {
        public int DeltaX { get; set; }
        public int DeltaY { get; set; }

        public Vector() {}

        public Vector(Point p1, Point p2)
        {
            DeltaX = p2.X - p1.X;
            DeltaY = p2.Y - p1.Y;
        }

        public static Vector operator+(Vector v1, Vector v2)
        {
            return new Vector()
            {
                DeltaX = v1.DeltaX + v2.DeltaX,
                DeltaY = v1.DeltaY + v2.DeltaY
            };
        }

        public static Vector operator *(Vector v1, int i)
        {
            return new Vector()
            {
                DeltaX = v1.DeltaX * i,
                DeltaY = v1.DeltaY * i
            };
        }

        public static Vector operator *(int i, Vector v)
        {
            return v * i;
        }

        public override string ToString()
        {
            return $"DeltaX: {DeltaX}, DeltaY: {DeltaY}";
        }

        public override bool Equals(object obj)
        {
            var vector = (Vector)obj;
            return DeltaX == vector.DeltaX && DeltaY == vector.DeltaY;
        }

        public static bool operator ==(Vector v1, Vector v2)
        {
            return v1.Equals(v2);
        }

        public static bool operator !=(Vector v1, Vector v2)
        {
            return !(v1 == v2);  //!(v1.Equals(v2));
        }

        public static bool operator >(Vector v1, Vector v2)
        {
            return Math.Sqrt(v1.DeltaX * v1.DeltaY + v1.DeltaY * v1.DeltaY) >
                Math.Sqrt(v2.DeltaX * v2.DeltaY + v2.DeltaY * v2.DeltaY);
        }

        public static bool operator <(Vector v1, Vector v2)
        {
            return !(v1 > v2);
        }
    }
}