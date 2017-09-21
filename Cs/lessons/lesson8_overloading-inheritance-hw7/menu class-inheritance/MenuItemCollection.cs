using System;

namespace lesson8_inheritance
{
    public class MenuItemCollection : MenuItem
    {
        private MenuItem[] items;
        public MenuItemCollection(string title, MenuItem[] items) : base(title)
        {
            this.items = items;
        }
        public override void SelectItem(MenuItem prev = null)
        {
            base.SelectItem(prev);
            for (int i = 0; i < items.Length; i++)
                Console.WriteLine($"{i + 1}: {items[i].Title}");
            int idx = int.Parse(Console.ReadLine());
            if (idx == 0)
            {
                if (prev != null)
                    prev.SelectItem(this);
            }
            else
                items[idx - 1].SelectItem(this);
        }
    }
}
