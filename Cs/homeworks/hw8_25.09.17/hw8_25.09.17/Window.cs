using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    public class Window: IPart
    {
        public StringBuilder Part { get; private set; }
        public bool IsBuild { get; private set; } = false;

        public string Build()
        {
            Part = new StringBuilder();
            Part.Append($" {(char)9474}  {(char)9484}{(char)9472}{(char)9472}{(char)9488}  {(char)9474}\n");
            Part.Append($" {(char)9474}  {(char)9474}  {(char)9474}  {(char)9474}\n");
            Part.Append($" {(char)9474}  {(char)9492}{(char)9472}{(char)9472}{(char)9496}  {(char)9474}\n");
            IsBuild = true;
            return Part.ToString();
        }
    }
}
