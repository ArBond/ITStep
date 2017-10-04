using System;
using System.Xml;

namespace lesson15_xml
{
    class Program
    {
        static void Main(string[] args)
        {
            //var st = new Student();
            //Console.WriteLine("Enter question:");
            //Console.WriteLine(st.Answer(Console.ReadLine()));

            Console.WriteLine("Выберите город:");
            int idx = 1;
            foreach (var city in Configuration.Instance.Cities)
                Console.WriteLine($"{idx++}: {city.Name}");
            idx = int.Parse(Console.ReadLine());
            var selectedCity = Configuration.Instance.Cities[idx - 1];
            var url = $"http://informer.gismeteo.by/rss/{selectedCity.Code}.xml";
            using (var reader = new XmlTextReader(url))
            {
                var document = new XmlDocument();
                document.Load(reader);
                Console.WriteLine(document.OuterXml);
            }
        }
    }
}
