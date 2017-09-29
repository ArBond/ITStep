using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw4_18._09._17
{
    public class Client
    {
        private static int clientCount = 0;
        private int code = ++clientCount;
        private int orderCount = 0;
        private decimal ordersSumm = 0;

        public ClientType Type { get; set; }

        public int Code { get { return code; } }

        public string Name { get; set; }

        public string Address { get; set; }

        public string Phone { get; set; }

        public int OrderCount { get; set; }

        public decimal OrdersSumm { get; set; }

        public override string ToString()
        {
            return $"Client #{code} {Name}:\nAddress: {Address}   Phone: {Phone}   Oreder quantity: {orderCount}   Orders summ: {ordersSumm}";
        }
    }
}