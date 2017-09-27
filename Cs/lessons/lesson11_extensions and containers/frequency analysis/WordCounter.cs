using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson11_List
{
    public class WordCounter
    {
        public void Work()
        {
            var input = Console.ReadLine();
            var separators = new char[] { ' ', ',', '.', ':', '-', '?', '(', ')' };
            var words = input.Split(separators).Where(w => !string.IsNullOrEmpty(w)).ToArray();

            //вариант 1
            //var dictionary = new Dictionary<string, int>(StringComparer.CurrentCultureIgnoreCase);
            //foreach(var  word in words)
            //{
            //    if (dictionary.ContainsKey(word))
            //        dictionary[word]++;
            //    else
            //        dictionary[word] = 1;
            //}
            //foreach (var key in dictionary.Keys)
            //    Console.WriteLine($"{key}  {dictionary[key]}");

            //вариант 2
            var lookup = words.ToLookup(x => x, StringComparer.CurrentCultureIgnoreCase);
            foreach(var item in lookup)
                Console.WriteLine($"{item.Key}:  {item.Count()}");
        }
    }
}
