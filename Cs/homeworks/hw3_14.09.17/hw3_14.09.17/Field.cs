using System;
using System.Text;

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

        public void Print(Cursor cursor, bool drowShips)
        {
            StringBuilder str = new StringBuilder();

            str.Append((char)9484);
            for (int i = 0; i < 10; i++)
                str.Append((char)9472);
            str.Append($"{(char)9488}\n");

            for (int i = 0; i < 10; i++)
            {
                str.Append((char)9474);
                for (int j = 0; j < 10; j++)
                {
                    if (cursor != null && cursor.GetPos()[0] == j && cursor.GetPos()[1] == i)
                    {
                        if (cells[cursor.GetPos()[1], cursor.GetPos()[0]].IsShip == true && cells[cursor.GetPos()[1], cursor.GetPos()[0]].IsShoted == true)
                            str.Append('#');
                        else
                            str.Append(cursor.Symbol);
                    }
                    else if (cells[i, j].IsShip == true && cells[i, j].IsShoted == true)
                        str.Append('X');
                    else if (drowShips == true && cells[i, j].IsShip == true)
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
