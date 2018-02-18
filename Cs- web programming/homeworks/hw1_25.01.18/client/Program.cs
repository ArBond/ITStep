using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace client
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            var client = new Client();
            client.Start();
        }
    }
}
