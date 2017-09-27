using System;

namespace hw3_14._09._17
{
    public class Cursor
    {
        public char Symbol { get; set; } = (char)164;

        private int xPos = 0;
        private int yPos = 0;

        public void ChangePos(ConsoleKeyInfo key)
        {
            switch (key.Key)
            {
                case ConsoleKey.UpArrow:
                    if (yPos > 0)
                        yPos--;
                    break;
                case ConsoleKey.DownArrow:
                    if (yPos < 9)
                        yPos++;
                    break;
                case ConsoleKey.LeftArrow:
                    if (xPos > 0)
                        xPos--;
                    break;
                case ConsoleKey.RightArrow:
                    if (xPos < 9)
                        xPos++;
                    break;
                default:
                    break;
            }
        }

        public int[] GetPos() => new int[] { xPos, yPos };
    }
}