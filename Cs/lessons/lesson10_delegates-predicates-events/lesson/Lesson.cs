using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson10_1
{

    public class LessonEventArgs : EventArgs
    {
        public string HomeWork { get; set; }

        public int AcceptCount { get; set; }
    }

    public class Lesson
    {
        public event Predicate<string> Started; // как можно делать

        private EventHandler<LessonEventArgs> finished;
        public event EventHandler<LessonEventArgs> Finished // как надо делать
        {
            add
            {
                finished += value;
            }
            remove
            {
                finished -= value;
            }
        }

        public void OnStarted()
        {
            Predicate<string> handler = Started;
            if (handler != null)
            {
                int count = 0;
                foreach (Predicate<string> predicate in handler.GetInvocationList())
                {
                    if (predicate("Идите на занятие пожалуйста!"))
                            count++;
                }
                Console.WriteLine($"Идет на занятие студентов: {count}");
            }
        }

        public void OnFineshed()
        {
            var handler = finished;
            if(handler != null)
            {
                var args = new LessonEventArgs() { HomeWork = "Читай Рихтера пожалйста" };
                handler(this, args);
                Console.WriteLine($"Будет делать домашку: {args.AcceptCount}");
            }
        }
    }
}
