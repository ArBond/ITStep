using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson5
{
    class Program
    {
        static public void SetXes(ref pointStruct p1, pointClass p2)
        {
            p1.SetX(100);
            p2.SetX(200);
        }

        static void PrintStudent(Student st)
        {
            Console.WriteLine(st?.Name);
        }

        static void Main(string[] args)
        {
            //var p1 = new pointStruct(10, 20);
            //Console.WriteLine(p1);

            //var p2 = new pointClass(15, 25);
            //Console.WriteLine(p2);

            //p1.SetX(-10);
            //p2.SetX(-15);
            //Console.WriteLine(p1);
            //Console.WriteLine(p2);

            //SetXes(ref p1, p2);
            //Console.WriteLine(p1);
            //Console.WriteLine(p2);

            //pointStruct? p3 = null;
            //Nullable<pointStruct> p4 = new pointStruct(0, 0);

            //Console.WriteLine(p3.HasValue);
            //Console.WriteLine(p4.HasValue);
            //Console.WriteLine(p4.Value);

            //if (p3 == null)
            //    p3 = new pointStruct(0, 0); // или
            //p3 = p3 ?? new pointStruct(0, 0);



            //var ArtemPermission = Permission.Read;
            //var ReadWrite = Permission.ReadWrite;

            //Console.WriteLine(ReadWrite.HasFlag(Permission.Write));
            //bool result = System.Enum.TryParse(Console.ReadLine(), out ArtemPermission);
            //Console.WriteLine(ArtemPermission);



            var student = new Student();
            student.Name = "Artemi";
            Console.WriteLine(student.Name);

            PrintStudent(null);


        }
    }
}
