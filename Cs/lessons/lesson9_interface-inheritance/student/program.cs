using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_interface
{
    class Program
    {
        static void Main(string[] args)
        {
            //IStudent student = new Student();
            //((Student)student).LastName = "qwe";

            var list = new StudentList();
            list.AddStudent(new Student() { Name = "Petya", BirthDate = new DateTime(1996, 6, 14)});
            list.AddStudent(new Student() { Name = "Artemi", BirthDate = new DateTime(1997, 9, 12) });
            list.AddStudent(new Student() { Name = "Gena", BirthDate = new DateTime(1996, 2, 24) });
            list.SortByDate();
            foreach (Student student in list)
            {
                if(student != null)
                    Console.WriteLine($"Name: {student.Name}, BirthDate: {student.BirthDate}");
            }
        }
    }
}
