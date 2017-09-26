using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson10_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Func<double, double, double> operation = Math.Min;  // <- готовый длегат;  или использовать свой:  MathOperation operation = Math.Min
            //Console.WriteLine(operation(10, 15));
            //operation = Math.Max;
            //Console.WriteLine(operation(10, 15));

            //operation += Math.Min;
            //operation += Math.Log; // operation = (MathOperation)Delegate.Combine(operation, (MathOperation)Math.Log);

            //foreach (var o in operation.GetInvocationList())
            //    Console.WriteLine(o.DynamicInvoke(10, 15));

            //Action<string[]> action = Main;
            ////action(null);

            //Predicate<double> predicate1 = delegate (double d) { return d > 0; };
            //Predicate<double> predicate2 = d => d > 0;
            //Console.WriteLine(predicate1(-1));
            //Console.WriteLine(predicate2(1));


            Lesson lesson = new Lesson();
            lesson.Started += Lesson_Started;
            lesson.Started += x => false;
            lesson.Started += x => x.Contains("пожалуйста");

            lesson.OnStarted();

            lesson.Finished += Lesson_Finished;
            lesson.Finished += (sender, e) => e.AcceptCount++;

            lesson.OnFineshed();
        }

        private static void Lesson_Finished(object sender, LessonEventArgs e)
        {
            e.AcceptCount++;
        }

        private static bool Lesson_Started(string str)
        {
            return true;
        }
    }
}
