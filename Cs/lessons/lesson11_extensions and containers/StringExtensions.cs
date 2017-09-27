using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson11_1
{
    public static class StringExtensions
    {
        public static string RemoveSpaces(this string str)
        {
            return str?.Replace(" ", "");
        }
    }
}
