using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    public class Card
    {
        public int Suit { get; set; }
        public int Value { get; set; }

        public Card(int suit, int value)
        {
            Suit = suit;
            Value = value;
        }

        public override string ToString()
        {
            string cardType = Value.ToString();
            if (Value == 11)
                cardType = "J";
            else if (Value == 12)
                cardType = "Q";
            else if (Value == 13)
                cardType = "K";
            else if(Value == 14)
                cardType = "A";
            return $"{cardType} {(char)(Suit + 3)}";
        }
    }
}
