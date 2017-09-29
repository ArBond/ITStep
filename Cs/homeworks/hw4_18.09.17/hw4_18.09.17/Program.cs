using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace hw4_18._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            var banana = new Article() { Name = "Banana", Type = ArticleType.Fruits, Price = 1 };
            var cherry = new Article() { Name = "Cherry", Type = ArticleType.Berries, Price = 2 };
            var tomato = new Article() { Name = "Tomato", Type = ArticleType.Vegetables, Price = 0.7M };

            var client1 = new Client() { Name = "Bondarenko Artemi", Address = "Minsk", Phone = "+375 29 111 11 11" };

            var RequestItem1 = new RequestItem() { Article = banana, CountProduct = 2 };
            var RequestItem2 = new RequestItem() { Article = cherry, CountProduct = 1 };
            var RequestItem3 = new RequestItem() { Article = tomato, CountProduct = 1 };

            var request1 = new Request() { Client = client1, Type = PayType.Cash, Articles = new RequestItem[] { RequestItem1, RequestItem2, RequestItem3 } };

            Console.WriteLine(request1);

            Thread.Sleep(1000);
            var request2 = new Request() { Client = client1, Type = PayType.Cash, Articles = new RequestItem[] { new RequestItem() { Article = tomato, CountProduct = 3 } } };

            Console.WriteLine(request2);
        }
    }
}