using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw4_18._09._17
{
    public class Request
    {
        private static int requestCount = 0;
        private int code = ++requestCount;
        private Client client;

        public PayType Type { get; set; }

        public int Code { get { return code; } }

        public Client Client{ get; set; }

        public string Date { get; } = DateTime.Now.ToString();

        public RequestItem[] Articles { get; set; }

        public decimal Sum
        {
            get
            {
                decimal Sum = 0;
                foreach (var article in Articles)
                {
                    Sum += article.Article.Price * article.CountProduct;
                }
                return Sum;
            }
        }

        public override string ToString()
        {
            var str = new StringBuilder();
            str.Append($"   Request #{code}\nClient: {Client.Name}\nDate: {Date}\nList:\n");
            foreach (var article in Articles)
                str.Append($"{article.Article.Name} x{article.CountProduct}  -  {article.CountProduct * article.Article.Price}\n");
            str.Append($"Total sum: { Sum}");
            return str.ToString();
        }
    }
}