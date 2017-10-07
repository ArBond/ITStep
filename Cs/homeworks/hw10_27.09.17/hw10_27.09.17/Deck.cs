using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    public class Deck: IEnumerable
    {
        private Queue<Card> deck = new Queue<Card>();
        public int Size { get { return deck.Count; } }

        public void Initialize()
        {
            var list = new List<Card>();
            foreach (var suit in Enum.GetValues(typeof(CardSuit)))
            {
                foreach (var value in Enum.GetValues(typeof(CardValue)))
                    list.Add(new Card((CardSuit)suit, (CardValue)value));
            }
            deck = new Queue<Card>(Shuffle(list));
        }

        private Queue<Card> Shuffle(List<Card> list)
        {
            list = list.OrderBy(a => Guid.NewGuid()).ToList();
            return new Queue<Card>(list);
        }

        public void PushCard(Card card)
        {
            deck.Enqueue(card);
        }

        public Card PopCard()
        {
            return deck.Dequeue();
        }

        public void Print()
        {
            foreach (var card in deck)
                Console.WriteLine(card);
        }

        public IEnumerator GetEnumerator()
        {
            return deck.GetEnumerator();
        }
    }
}
