using System;

namespace lesson6
{
    class Program
    {
        static void Main(string[] args)
        {
            //var shop = new Shop();
            //shop.AddLaptop(new Laptop() { Brand = "Dell", Price = 1500 });
            //shop.AddLaptop(new Laptop() { Brand = "Lenovo", Price = 1000 });
            //shop.AddLaptop(new Laptop() { Brand = "Hp", Price = 1100 });
            //shop.AddLaptop(new Laptop() { Brand = "Lenovo", Price = 1200 });

            //Console.WriteLine(shop[1000]?.Brand);
            //var sortLaptops = shop["Lenovo"];
            //foreach(var laptop in sortLaptops)
            //{
            //    Console.WriteLine($"Brand: {laptop.Brand}   Price: {laptop.Price} $");
            //}



            var array = new SmartArray(10);
            while(true)
            {
                int i = Int32.Parse(Console.ReadLine());
                Console.WriteLine(array[i]);
            }

        }
    }
}
