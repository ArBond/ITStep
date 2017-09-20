using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw3_14._09._17
{
    public class Cell
    {
        private char symbol = ' ';

        public void SetSymbol(char symbol)
        {
            this.symbol = symbol;
        }

        public char GetSymbol() => symbol;
    }
}