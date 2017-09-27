using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson11_1
{
    class Program
    {
        static void Main(string[] args)
        {
                    // Extensions

            //var input = Console.ReadLine();
            //Console.WriteLine(input.RemoveSpaces());
            //var arr = new int[11];
            //int page = 0;
            //int perPage = 5;
            //arr.Skip(page * perPage).Take(perPage).ToArray();
            //page++;
            //arr.Where(x => x > 0).Select(x => x * x).FirstOrDefault(x => x == 9);



                    // Containers

            var sergey = new Student() { Name = "Sergey", Surname = "Breasd", BirthDay = new DateTime(1967, 12, 7) };
            var sergey2 = new Student() { Name = "Sergey", Surname = "Godny", BirthDay = new DateTime(1987, 7, 29) };
            var tema = new Student() { Name = "Tema", Surname = "Pregor", BirthDay = new DateTime(1992, 3, 12) };
            var ivan = new Student() { Name = "Ivan", Surname = "Bush", BirthDay = new DateTime(1974, 2, 25) };


            //list
            var list = new List<Student>() { sergey, sergey2, tema, ivan };
            list.OrderBy(x => x.Name).Print();
            list.OrderBy(x => x.BirthDay.GetAge()).Print();


            var enumenator = list.GetEnumerator();         // под капотом foreach
            while (enumenator.MoveNext())
            {
                var student = enumenator.Current;
                student.Print();
            }


            //arrayList
            var arrayList = new ArrayList();
            arrayList.Add(1);
            arrayList.Add("qwe");
            arrayList.Add(new Student());


            //stack
            var stack = new Stack<string>();
            stack.Push("One");
            stack.Push("two");
            stack.Push("three");
            Console.WriteLine(stack.Peek());
            foreach (var element in stack)
                Console.WriteLine(element);


            ////queue
            var queue = new Queue<Student>();
            queue.Enqueue(sergey);
            queue.Enqueue(tema);
            queue.Enqueue(ivan);
            queue.Peek().Print();


            //sortedList
            var sortedList = new SortedList<string, Student>();
            sortedList.Add(sergey.Name, sergey);
            sortedList.Add(tema.Name, tema);
            sortedList.Add(ivan.Name, ivan);
            sortedList.Values.Print();


            //dictionary
            var dictionary = new Dictionary<string, int>();
            dictionary.Add("one", 1); // или ->
            dictionary["two"] = 2;
            dictionary["two"]++;
            if (dictionary.ContainsKey("three"))
                dictionary["three"]++;
            else
                dictionary["three"] = 3;
            dictionary["four"] = 4;
            int result;
            if (dictionary.TryGetValue("four", out result))
                result++;
            Console.WriteLine(dictionary["four"]);
            foreach (var pair in dictionary)
                Console.WriteLine(pair.Key + ' ' + pair.Value);


            //mapMapov
            var mapMapov = new Dictionary<string, Dictionary<string, string>>()
            {
                ["two"] = new Dictionary<string, string>()
                {
                    ["first"] = "1",
                    ["second"] = "2"
                },
                ["three"] = new Dictionary<string, string>()
                {
                    ["first"] = "1",
                    ["second"] = "2"
                }
            };
            Console.WriteLine(mapMapov["two"]["first"]);


            //lookup
            var lookup = list.ToLookup(x => x.Name);
            lookup["Sergey"].Print();
            Console.WriteLine(lookup.Contains("Sergey"));
        }
    }
}
