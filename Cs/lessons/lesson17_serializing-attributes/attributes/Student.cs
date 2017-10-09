using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace attributes
{
    [Author("Artemi", "09.10.17")]
    public class Student
    {
        public string FullName { get; set; }

        public DateTime BirthDate { get; set; }

        [Author("Artemi", "09.10.17")]
        public void Learn(string knowlage)
        {
            throw new NotSupportedException();
        }

        [Author("Artemi", "09.10.17")]
        [Author("Alex", "10.10.17")]
        public void DoNothing()
        {
        }
    }
}
