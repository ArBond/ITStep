using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson4
{
    partial class Student
    {
        // readonly - только для чтения. Можно объявить в классе или в конструкторе
        // static - поле определяется для всего класса а не для каждого объекта

        public int mAge = 0;
        public static String s = "str";
        public String mName;

        static Student() // выполняется 1 раз в приложении до первого вызова контруктора
        {

        }
        public Student(String name)
        {
            mName = name;
        }
        public Student(String name, int age):
            this(name)   // используем предыдущий конструктор
        {
            mAge = age;
        }
        
        public void SayHello(Student student, String name)
        {
            student.mAge = 10;
            Console.WriteLine($"Hello, {name}!");
        }

        public void SayHello(params string[] names)    // params
        {
            Console.WriteLine("Hello, " + string.Join(",", names));
        }

        public string Ansver(string Question)
        {
            return "I dont know...";
        }

        public int GetAge()      //  варианты return-а
        {
            return 15;
        }
        // или    public int GetAge() => 15;

        public bool TryAnswer(out string answer)  //  ref - out
        {
            answer = "42";
            return true;
        }
    }
}
