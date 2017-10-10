using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace lesson18
{
    class Program
    {
        static void Main(string[] args)
        {
            var info = new OsVersionInfo();
            info.size = (uint)Marshal.SizeOf(info);
            WinApiHelper.GetVersionEx(ref info);

            var name = new StringBuilder();
            int size = 50;
            WinApiHelper.GetUserName(name, ref size);

            WinApiHelper.ShowMessageBox(IntPtr.Zero, $"OS build number: {info.buildNumber}", name.ToString(), 0);
        }
    }
}
