using System;

namespace lesson8_inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            //var Student = new Student();

            //Human h = null;
            //h = new Student();

            //// варианты обратно получить студента:
            ////1
            //var st1 = (Student)h;

            ////2
            //Console.WriteLine(h is Student);
            //h = new Teacher();
            //Console.WriteLine(h is Student);

            ////3
            //var st2 = h as Student; // если студент в st2 запишется студент, иначе null
            //Console.WriteLine(st2 == null);
            //var st3 = h as Teacher;
            //Console.WriteLine(st3);

            //h.SayHello();
            //h = st1;
            //h.SayHello();


            var menu = new MenuItemCollection(null, new MenuItem[]
            {
                new MenuItemCollection("Баланс", new MenuItem[]
                {
                    new MenuItem("На экран"),
                    new MenuItem("На чек")
                }),
                new MenuItemCollection("Снять", new MenuItem[]
                {
                    new MenuItem("BUN"),
                    new MenuItem("USD")
                })
            });
            menu.SelectItem();
        }
    }
}
