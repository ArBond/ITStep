using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    public class Player
    {
        public string Name { get; set; }
        public Deck Cards { get; set; } = new Deck();
        public bool IsContinue { get; set; } = true;

        public Player(string name)
        {
            Name = name;
        }

        public void PrintCards()
        {
            foreach (var card in Cards)
                Console.WriteLine(card);
        }
    }
}
