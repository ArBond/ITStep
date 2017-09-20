using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson6
{
    class SmartArray
    {
        private int[] array;

        public SmartArray(int count)
        {
            array = new int[count];
        }

        public int this[int i]
        {
            get
            {
                if (i <= 0)
                    i += array.Length;
                if(i > 0 && i < array.Length)
                    return array[i];
                throw new ArgumentOutOfRangeException();
            }
        }
    }
}
