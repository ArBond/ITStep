using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw8_25._09._17
{
    public interface IWorker
    {
        string Name { get; set; }
        bool Check(House house);
    }
}
