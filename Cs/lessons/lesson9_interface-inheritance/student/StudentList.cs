using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_interface
{
    public class StudentList: IEnumerable
    {
        private int count = 0;

        private Student[] students = new Student[20];

        public void AddStudent(Student s)
        {
            students[count++] = s;
            Array.Sort(students);
        }

        public void SortByDate()
        {
            Array.Sort(students, new BirthDateComparer());
        }

        public IEnumerator GetEnumerator()
        {
            return students.GetEnumerator();
        }
    }
}
