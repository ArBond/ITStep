using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson8
{
    public class Point
    {
        public int X { get; set; }
        public int Y { get; set; }

        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }

        public Point() { }

        public static Point operator ++(Point p)
        {
            p.X++;
            p.Y++;
            return p;
        }

        public static Point operator --(Point p)
        {
            p.X--;
            p.Y--;
            return p;
        }

        public static Point operator -(Point p)
        {
            return new Point() { X = -p.X, Y = -p.Y};
        }

        public static bool operator true(Point p)
        {
            return !(p.X == 0 && p.Y == 0);
        }

        public static bool operator false(Point p)
        {
            return p.X == 0 && p.Y == 0;
        }

        public static Point operator |(Point p1, Point p2)  // p1 || p2  
        {
            if(p1.X != 0 || p1.Y != 0 || p2.X != 0 || p2.Y != 0)
                return p2;
            return new Point();
        }

        public override string ToString()
        {
            return $"X = {X}, Y = {Y}";
        }
    }
}