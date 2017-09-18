using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson5
{
    [Flags]
    public enum Permission
    {
        Read = 1,
        Write = 2,
        Execute = 4,
        Delete = 8,
        ReadWrite = Read | Write
    }
}
