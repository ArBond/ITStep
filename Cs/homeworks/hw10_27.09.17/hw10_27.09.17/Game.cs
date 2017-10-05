using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    public class Game
    {
        private Deck Deck { get; set; } = new Deck();
        public List<Player> Players { get; set; } = new List<Player>();

        public Game()
        {
            Deck.Initialize();
        }

        public void SetPlayers()
        {
            int playersQuantity;
            Console.WriteLine("Enter the players quantity(2 - 4):");
            do
            {
                playersQuantity = int.Parse(Console.ReadLine());
            }
            while (playersQuantity < 2 || playersQuantity > 4);
            Console.WriteLine("Enter names:");
            for (int i = 0; i < playersQuantity; i++)
            {
                Console.WriteLine($"Player #{i + 1}:");
                Players.Add(new Player(Console.ReadLine()));
            }
            GiveOutCards(playersQuantity);
        }

        private void GiveOutCards(int playersQuantity)
        {
            for(int i = 0; i < (36 / playersQuantity); i++)
            {
                for(int j = 0; j < playersQuantity; j++)
                {
                    var card = Deck.PopCard();
                    Players[j].Cards.PushCard(card);
                }
            }
        }

        public void Play()
        {
            var roundsCards = new Queue<Card>();
            Player loozerInRound = null;

            int count = 0;
            while(true)
            {
                count++;
                int MaxCard;
                int QuantityMaxCards;

                do
                {
                    MaxCard = 0;
                    QuantityMaxCards = 0;
                    for (int i = 0; i < Players.Count; i++)
                    {
                        if (Players[i].IsContinue == true && Players[i].Cards.Length > 0)
                        {
                            var card = Players[i].Cards.PopCard();
                            roundsCards.Enqueue(card);

                            if (card.Value > MaxCard)
                            {
                                MaxCard = card.Value;
                                QuantityMaxCards = 1;
                                loozerInRound = Players[i];
                                for (int j = 0; j < i; j++)
                                    Players[j].IsContinue = false;
                            }
                            else if (card.Value == MaxCard)
                                QuantityMaxCards++;
                            else
                                Players[i].IsContinue = false;
                        }
                    }
                    if (QuantityMaxCards == 1)
                    {
                        foreach (var card in roundsCards)
                            loozerInRound.Cards.PushCard(card);
                        roundsCards.Clear();
                        for (int i = 0; i < Players.Count; i++)
                        {
                            if (Players[i].Cards.Length > 0)
                                Players[i].IsContinue = true;
                        }
                    }
                    else
                    {
                        for (int i = 0; i < Players.Count; i++)
                        {
                            if (Players[i].IsContinue == true && Players[i].Cards.Length > 0)
                            {
                                var card = Players[i].Cards.PopCard();
                                roundsCards.Enqueue(card);
                            }
                        }
                    }
                    Console.WriteLine(count);
                }
                while (QuantityMaxCards != 1);

                if(loozerInRound.Cards.Length >= 36)
                {
                    return;
                }
            }
        }
    }
}