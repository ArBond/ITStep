using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson6
{
    public class Shop
    {
        private int count = 0;

        private Laptop[] laptops = new Laptop[100];
        public void AddLaptop(Laptop laptop)
        {
            laptops[count++] = laptop;
        }
        
        public Laptop this[int i]
        {
            get
            {
                if(i >= laptops.Length || i < 0)
                {
                    return null;
                }
                return laptops[i];
            }
            set { laptops[i] = value; }
        } 

        public Laptop[] this[string brand]
        {
            get
            {
                var result = new List<Laptop>();
                foreach(var laptop in laptops)
                {
                    if(laptop?.Brand == brand)
                    {
                        result.Add(laptop);
                    }
                }
                return result.ToArray<Laptop>();
            }
        }
    }
}
