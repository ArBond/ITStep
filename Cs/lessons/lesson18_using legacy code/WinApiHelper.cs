using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace lesson18
{
    public static class WinApiHelper
    {
        [DllImport("User32.dll", EntryPoint = "MessageBoxW", CharSet = CharSet.Auto)]
        public static extern int ShowMessageBox(IntPtr hWnd, string text, string caption, uint type);

        [DllImport("Kernel32.dll")]
        public static extern bool GetVersionEx(ref OsVersionInfo info);

        [DllImport("Advapi32.dll")]
        public static extern bool GetUserName(StringBuilder name, ref int size);
    }
}
