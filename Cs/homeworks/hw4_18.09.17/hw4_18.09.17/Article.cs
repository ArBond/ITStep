using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw4_18._09._17
{
    public class Article
    {
        private static int articleCount = 0;
        private int code = ++articleCount;

        public ArticleType Type { get; set; }

        public int Code { get { return code; } }

        public string Name { get; set; }

        public decimal Price { get; set; }

        public override string ToString()
        {
            return $"Article #{code}:\n   Name: {Name}   Price: {Price}";
        }
    }
}