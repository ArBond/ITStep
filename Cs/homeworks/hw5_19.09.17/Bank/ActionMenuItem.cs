using System;

namespace Bank
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
                handler.Handle();
                Console.WriteLine("Operatoin complited");
            }
            catch (ApplicationException ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.ReadLine();
            //prev.SelectItem(null);
        }
    }
}
