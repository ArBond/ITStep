using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    public class Card: IComparable<Card>
    {
        public CardSuit Suit { get; set; }
        public CardValue Value { get; set; }

        public Card(CardSuit suit, CardValue value)
        {
            Suit = suit;
            Value = value;
        }

        public static bool operator<(Card card1, Card card2)
        {
            return card1.Value < card2.Value;
        }

        public static bool operator >(Card card1, Card card2)
        {
            return !(card1 < card2);
        }

        public int CompareTo(Card card)
        {
            return Value.CompareTo(card.Value);
        }

        public override string ToString()
        {
            string cardValue;
            string space = " ";
            if (Value < CardValue.Jack)
            {
                cardValue = ((int)Value).ToString();
                if(Value == CardValue.Ten)
                    space = "";
            }
            else
            {
                switch (Value)
                {
                    case CardValue.Jack:
                        cardValue = "J";
                        break;
                    case CardValue.Queen:
                        cardValue = "Q";
                        break;
                    case CardValue.King:
                        cardValue = "K";
                        break;
                    case CardValue.Ace:
                        cardValue = "A";
                        break;
                    default:
                        throw new ArgumentException("Unknown card value");
                }
            }
            var str = new StringBuilder();
            str.AppendLine($"{(char)9484}{(char)9472}{(char)9472}{(char)9472}{(char)9488}");
            str.AppendLine($"{ (char)9474}{cardValue}{space} {(char)9474}");
            str.AppendLine($"{ (char)9474} {(char)Suit} {(char)9474}");
            str.AppendLine($"{ (char)9474} {space}{cardValue}{(char)9474}");
            str.AppendLine($"{(char)9492}{(char)9472}{(char)9472}{(char)9472}{(char)9496}");
            return str.ToString();
        }
    }
}
