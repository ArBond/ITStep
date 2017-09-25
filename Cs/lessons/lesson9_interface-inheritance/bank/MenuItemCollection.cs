using System;

namespace lesson9_Menu
{
    public class MenuItemCollection : MenuItem
    {
        
        private MenuItem[] items;
        private MenuItem prev;
        public MenuItemCollection(string title, MenuItem[] items) : base(title)
        {
            this.items = items;
        }
        public override void SelectItem(MenuItem prev = null)
        {
            this.prev = this.prev ?? prev;
            base.SelectItem(this.prev);
            for (int i = 0; i < items.Length; i++)
                Console.WriteLine($"{i + 1}: {items[i].Title}");
            int idx = int.Parse(Console.ReadLine());
            if (idx == 0)
            {
                if (this.prev != null)
                    this.prev.SelectItem(this.prev);
            }
            else
                items[idx - 1].SelectItem(this);
        }
    }
}
