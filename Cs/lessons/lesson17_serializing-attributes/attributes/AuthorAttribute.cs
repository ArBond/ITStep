using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace attributes
{
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Method, AllowMultiple = true)]
    public class AuthorAttribute: Attribute
    {
        public string Name { get; private set; }
        public DateTime Date { get; private set; }

        public AuthorAttribute(string name, string date)
        {
            Name = name;
            DateTime parsedDate;
            if (DateTime.TryParse(date, out parsedDate))
                Date = parsedDate;
            else
                Date = DateTime.Now;
        }
    }
}
