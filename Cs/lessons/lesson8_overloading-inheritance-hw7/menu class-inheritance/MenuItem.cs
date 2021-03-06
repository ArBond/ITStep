﻿using System;

namespace lesson8_inheritance
{
    public class MenuItem
    {
        public string Title { get; set; }

        public MenuItem(string title)
        {
            Title = title;
        }

        public virtual void SelectItem(MenuItem prev = null)
        {
            Console.Clear();
        }
    }
}