using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    public class Basement: IPart
    {
        public StringBuilder Part { get; private set; }
        public bool IsBuild { get; private set; } = false;

        public string Build()
        {
            Part = new StringBuilder();
            Part.Append($" {(char)9619}{(char)9619}{(char)9619}{(char)9619}{(char)9619}{(char)9619}{(char)9619}{(char)9619}{(char)9619}{(char)9619}\n");
            IsBuild = true;
            return Part.ToString();
        }
    }
}
