using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw3_14._09._17
{
    public class Field
    {
        private Cell[,] cells = new Cell[10,10];
        private Cursor cursor = new Cursor();

        public Field()
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    cells[i, j] = new Cell();
                }
            }
        }

        public void Print()
        {
            StringBuilder str = new StringBuilder();

            str.Append($"Your field\n{(char)9484}");
            for(int i = 0; i < 10; i++)
                str.Append((char)9472);
            str.Append($"{(char)9488}\n");
            //byte[] c = { 217 };
            //var cCh = Encoding.GetEncoding("cp866").GetChars(c);

            for (int i = 0; i < 10; i++)
            {
                str.Append((char)9474);
                for (int j = 0; j < 10; j++)
                    str.Append(cells[i,j].GetSymbol());
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
