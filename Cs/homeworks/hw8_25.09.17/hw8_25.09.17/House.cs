using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    public class House: IEnumerable
    {
        public List<IPart> parts = new List<IPart>();
        public int basementLayersQuantity { get; private set; }
        public int WindowQuantity { get; private set; }
        public int WallsQuantity { get; private set; }

        public House(int basementLayersQuantity, int WindowQuantity, int WallsQuantity)
        {
            for (int i = 0; i < basementLayersQuantity; i++)
                parts.Add(new Basement());
            parts.Add(new Door());
            int count;
            for(count = 0; count < (WindowQuantity < WallsQuantity ? WindowQuantity : WallsQuantity); count++)
            {
                parts.Add(new Walls());
                parts.Add(new Window());
            }
            for(int i = count; i < WallsQuantity; i++)
                parts.Add(new Walls());
            parts.Add(new Roof());
        }

        public IEnumerator GetEnumerator()
        {
            return parts.GetEnumerator();
        }
    }
}
