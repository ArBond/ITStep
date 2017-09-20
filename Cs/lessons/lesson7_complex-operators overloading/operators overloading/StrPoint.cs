using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson7
{
    public struct StrPoint
    {
        public int X { get; set; }
        public int Y { get; set; }

        public StrPoint(int x, int y)
        {
            X = x;
            Y = y;
        }
    }
}