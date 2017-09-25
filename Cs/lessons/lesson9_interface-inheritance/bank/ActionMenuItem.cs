using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson9_Menu
{
    public class ActionMenuItem : MenuItem
    {

        private IMenuItemHandler handler;
        public ActionMenuItem(string title, IMenuItemHandler handler) : base(title)
        {
            this.handler = handler;
        }

        public override void SelectItem(MenuItem prev = null)
        {
            base.SelectItem(prev);
            try
            {
                this.handler.Handle();
            }
            catch(ApplicationException ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.ReadLine();
            prev.SelectItem(null);
        }
    }
}
