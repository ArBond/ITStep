using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson11_1
{
    public static class StudentExtensions
    {
        public static int GetAge(this DateTime date)
        {
            return (int)((DateTime.Now - date).Days / 365.25);
        }
        public static void Print(this Student st)
        {
            var age = st.BirthDay.GetAge();
            Console.WriteLine($"{st.Name} {st.Surname}, Age: {age}");
        }

        public static void Print(this IEnumerable<Student> students)
        {
            foreach (var st in students)
            {
                st.Print();
            }
        }
    }
}