using System;

namespace Bank
{
    public class MenuItemCollection: MenuItem
    {
        private MenuItem[] items;
        private MenuItem prev;

        public MenuItemCollection(string title, MenuItem[] items): base(title)
        {
            this.items = items;
        }

        public override void SelectItem(MenuItem prev = null)
        {
            this.prev = this.prev ?? prev;
            base.SelectItem(this.prev);
            for (int i = 0; i < items.Length - 1; i++)
                Console.WriteLine($"{i + 1}: {items[i].Title}");
            Console.WriteLine($"0: {items[items.Length - 1].Title}");
            int idx = int.Parse(Console.ReadLine());
            if (idx == 0)
            {
                if (this.prev != null)
                    this.prev.SelectItem(prev);
                throw new BankException(BankErrorCode.Exit, "Good luck!");
            }
            else
                if (idx >= items.Length || idx < 0)
                    throw new BankException(BankErrorCode.NotSuchItem, "There is no such item.");
                items[idx - 1].SelectItem(this);
        }
    }
}