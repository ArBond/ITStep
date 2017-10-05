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
        public int Length { get { return deck.Count; } }

        public void Initialize()
        {
            var list = new List<Card>();
            for (int i = 0; i < 4; i++)
            {
                for (int j = 6; j < 15; j++)
                    list.Add(new Card(i, j));
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
