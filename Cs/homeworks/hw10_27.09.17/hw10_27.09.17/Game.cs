using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    public class Game
    {
        private Deck Deck { get; set; }
        public List<Player> Players { get; set; } = new List<Player>();

        public Game()
        {
            Deck = new Deck();
            Deck.Initialize();
        }

        public void SetPlayers()
        {
            int playersQuantity;
            Console.WriteLine("Enter the players quantity(2 - 4):");
            do
                playersQuantity = int.Parse(Console.ReadLine());
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
            for(int i = 0; i < (Deck.Size / playersQuantity);)
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
            var roundsCards = new List<Card>();
            int deleteCount;
            while (Players.Count != 1)
            {
                var activePlayers = new List<Player>(Players);
                while (activePlayers.Count != 1)
                {
                    Console.Clear();
                    var currentCards = new List<Card>();
                    var activePlayersSize = activePlayers.Count;

                    for(int i = 0; i < activePlayersSize; i++)
                    {
                        Console.WriteLine($" {Players[i].Name}(cards: {Players[i].Cards.Size})");
                        if (Players[i].Cards.Size != 0)
                        {
                            var currentCard = Players[i].Cards.PopCard();
                            currentCards.Add(currentCard);
                            Console.WriteLine(currentCard);
                        }
                        else
                            activePlayers.Remove(Players[i]);
                    }
                    Thread.Sleep(1000);

                    deleteCount = 0;
                    for (int i = 0; i < currentCards.Count; i++)
                    {
                        if (currentCards[i] < currentCards.Max())
                            activePlayers.Remove(activePlayers[i - deleteCount++]);
                    }

                    foreach (var card in currentCards)
                        roundsCards.Add(card);
                }
                roundsCards = roundsCards.OrderBy(a => Guid.NewGuid()).ToList();
                foreach (var card in roundsCards)
                    activePlayers[0].Cards.PushCard(card);
                roundsCards.Clear();
                Console.WriteLine($"{activePlayers[0].Name} take cards!");
                Thread.Sleep(1500);

                deleteCount = 0;
                for (int i = 0; i < Players.Count; i++)
                {
                    if (Players[i].Cards.Size == 0)
                        Players.Remove(Players[i - deleteCount++]);
                }
            }
            Console.WriteLine($"{Players[0].Name} the winner!");
        }
    }
}