using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson5
{
    public class Student
    {
        private string name;
        private int[] marks = new int[100];

        public string Name  // propfull + tab  -  фаст кодинг
        {
            get; //{ return name; }
            set;//{ name = value.Trim(); }
        }

        public double AverageMark
        {
            get {return marks.Average(); }
        }

        public Presence Presence { get; set; }

        public bool WasOnLeson
        {
            get { return Presence != Presence.Absent; }
        }

        //public int Mark
        //{
        //    get { return mark; }
        //    set { mark = Math.Min(12, Math.Max(0, value)); }
        //}


    }
}
