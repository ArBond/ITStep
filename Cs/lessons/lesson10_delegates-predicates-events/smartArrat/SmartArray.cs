using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson10_3
{
    public class SmartArray: IEnumerable
    {
        private List<int> array = new List<int>();

        public void Add(int i)
        {
            array.Add(i);
        }

        public IEnumerator GetEnumerator()
        {
            return array.GetEnumerator();
        }

        public SmartArray Where(Predicate<int> predicate)
        {
            var result = new SmartArray();
            foreach(var i in array)
            {
                if (predicate(i))
                    result.Add(i);
            }
            return result;
        }

        public SmartArray Select(Func<int, int> func)
        {
            var result = new SmartArray();
            foreach (var i in array)
                result.Add(func(i));
            return result;
        }

        public int Count(Predicate<int> predicate)
        {
            int count = 0;
            foreach (var i in array)
            {
                if (predicate(i))
                    count++;
            }
            return count;
        }

        public void Print()
        {
            Console.WriteLine(string.Join(", ", array));
        }
    }
}
