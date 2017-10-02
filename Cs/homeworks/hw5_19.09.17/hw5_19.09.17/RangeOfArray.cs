using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw5_19._09._17
{
    public class RangeOfArray: IEnumerable
    {
        private int[] array;
        private int beginIdx;
        private int endIdx;

        public int Begin { get { return beginIdx; } }
        public int End { get { return endIdx; } }
        public int Length { get { return Math.Abs(beginIdx - endIdx) + 1; } }

        public RangeOfArray(int begin, int end)
        {
            beginIdx = begin;
            endIdx = end;
            array = new int[Math.Abs(end - begin) + 1];
        }

        public int this[int i]
        {
            get
            {
                if (beginIdx <= endIdx && i >= beginIdx && i <= endIdx ||
                    beginIdx > endIdx && i <= beginIdx && i >= endIdx)
                {
                    return array[Math.Abs(beginIdx - i)];
                }
                throw new IndexOutOfRangeException("get exception");
            }
            set
            {
                if (beginIdx <= endIdx && i >= beginIdx && i <= endIdx ||
                    beginIdx > endIdx && i <= beginIdx && i >= endIdx)
                {
                    array[Math.Abs(beginIdx - i)] = value;
                }
                else
                {
                    throw new IndexOutOfRangeException("set exception");
                }
            }
        }

        public IEnumerator GetEnumerator()
        {
            return array.GetEnumerator();
        }
    }
}