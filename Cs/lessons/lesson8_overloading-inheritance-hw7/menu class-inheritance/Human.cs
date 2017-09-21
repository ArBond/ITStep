using System;

namespace lesson8_inheritance
{
    public abstract class Human // sealed class - запрет наследования; можно применить к методам;
    {
        public string Sex { get; set; }

        public Human(string sex) // если в базовом классе объявлен НЕ пустой конструктор, то в наследниках тоже должен быть объявлен контруктор
        {
            Sex = sex;
            Console.WriteLine("Hello! Im human.");
        }

        virtual public void SayHello()
        {
            Console.WriteLine("Hello from human!");
        }

        public abstract void Print();
    }
}