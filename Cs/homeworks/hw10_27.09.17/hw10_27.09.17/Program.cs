using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw10_27._09._17
{
    class Program
    {
        static void Main(string[] args)
        {
            var game = new Game();
            game.SetPlayers();
            game.Play();
        }
    }
}
