using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson18
{
    public unsafe struct OsVersionInfo
    {
        public uint size;
        public uint majorVersion;
        public uint minorVersion;
        public uint buildNumber;
        public uint platformId;
        public fixed byte servicePackVersion[128];
    }
}
