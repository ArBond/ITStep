using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lesson19_flows
{
    class Program
    {
        private static ConcurrentQueue<string> queue = new ConcurrentQueue<string>();

        public static void AddWork()
        {
            while (true)
            {
                queue.Enqueue(Guid.NewGuid().ToString());
                Thread.Sleep(100);
            }
        }

        public static void RemoveWord()
        {
            while (true)
            {
                string result;
                if (queue.TryDequeue(out result))
                    Console.WriteLine(result);
                Thread.Sleep(200);
            }
        }

        private static void DoWork()
        {
           for(int i = 0; i < 5; i++)
            {
                var currThread = Thread.CurrentThread;
                Console.WriteLine($"Hello from thread {currThread.ManagedThreadId}");
                Thread.Sleep(1000);
            }
        }

        static void Main(string[] args)
        {
            // using(File.Create("test.txt")) { }
            //var proc1 = Process.Start("test.txt");
            //var proc2 = Process.Start("http:/tut.by");
            //Thread.Sleep(3000);
            //proc1.Kill();



            //var thread1 = new Thread(new ThreadStart(DoWork));
            //thread1.Start();
            //Thread.Sleep(500);
            //var thread2 = new Thread(new ThreadStart(DoWork));
            //thread2.Start();
            //Console.WriteLine($"Thread started");
            //thread2.Join(2000);
            //Console.WriteLine($"Thread finished");
            //thread1.Abort(); // не желательно



            //Task.Factory.StartNew(DoWork);
            //var task = new Task(() => Console.WriteLine("task"));
            //task.Start();
            //task.ContinueWith(t => DoWork());


            Task.Factory.StartNew(AddWork);
            Task.Factory.StartNew(RemoveWord);
            Task.Factory.StartNew(RemoveWord);
            Task.Factory.StartNew(RemoveWord);
            Task.Factory.StartNew(RemoveWord);

            Thread.Sleep(Timeout.Infinite);
        }
    }
}
