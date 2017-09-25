using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_interface
{
    public interface IStudent
    {
        string Name { get; set; }

        void DoHomeWork();

        string this[int i] { get; set; }
    }
}
