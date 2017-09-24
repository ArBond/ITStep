using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw3_14._09._17
{
    public class Field
    {
        public Cell[,] cells = new Cell[10,10];

        public Field(Cursor cursor)
        {
            for (int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    cells[i, j] = new Cell();
                }
            }
        }

        public void Print(Cursor cursor)
        {
            StringBuilder str = new StringBuilder();

            str.Append((char)9484);
            for (int i = 0; i < 10; i++)
                str.Append((char)9472);
            str.Append($"{(char)9488}\n");

            byte[] c = { 249 };
            var cCh = Encoding.GetEncoding("cp866").GetChars(c);

            for (int i = 0; i < 10; i++)
            {
                str.Append((char)9474);
                for (int j = 0; j < 10; j++)
                {
                    if (cursor != null && cursor.GetPos()[0] == j && cursor.GetPos()[1] == i)
                        str.Append((char)164);
                    else if (cells[i, j].IsShip == true && cells[i, j].IsShoted == true)
                        str.Append('X');
                    else if (cursor == null && cells[i, j].IsShip == true)
                        str.Append((char)9608);
                    else if (cells[i, j].IsShoted == true)
                        str.Append((char)8729);
                    else
                        str.Append(' ');
                }
                str.Append($"{(char)9474}\n");
            }

            str.Append((char)9492);
            for (int i = 0; i < 10; i++)
                str.Append((char)9472);
            str.Append((char)9496);

            Console.WriteLine(str);
        }
    }
}
