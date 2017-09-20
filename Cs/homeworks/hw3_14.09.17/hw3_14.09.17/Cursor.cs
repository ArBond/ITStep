using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw3_14._09._17
{
    public class Cursor
    {
        private char symbol = '@';
        private int xPos = 0;
        private int yPos = 0;

        public void ChangeX(int xPos)
        {
            if(xPos >= 0 && xPos < 10)
                this.xPos = xPos;

        }

        public void ChangeY(int yPos)
        {
            if (yPos >= 0 && yPos < 10)
                this.yPos = yPos;
        }

        public int GetX() => xPos;

        public int GetY() => yPos;
    }
}
