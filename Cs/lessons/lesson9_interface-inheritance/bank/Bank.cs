using System;

namespace lesson9_Menu
{
    public class Bank
    {
        public decimal Deposite { get; private set; }

        public void SetDeposite(decimal sum)
        {
            Deposite += sum;
        }

        public void WithDraw(decimal sum)
        {
            if(sum > Deposite)
            {
                throw new ApplicationException("Недостаточно средств!");
            }
            Deposite -= sum;
        }
    }
}