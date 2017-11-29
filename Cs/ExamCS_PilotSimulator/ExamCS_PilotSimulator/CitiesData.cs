using System;
using System.Collections.Generic;

namespace ExamCS_PilotSimulator
{
    public static class CitiseData
    {
        private static Random random = new Random();
        private static City minsk = new City("Минск", new List<Dispatcher> { new Dispatcher("Михаил"), new Dispatcher("Андрей"), new Dispatcher("Павел") }, random.Next(-200, 200));
        private static City mosсow = new City("Москва", new List<Dispatcher> { new Dispatcher("Александр"), new Dispatcher("Генадий"), new Dispatcher("Максим") }, random.Next(-200, 200));
        private static City kiev = new City("Киев", new List<Dispatcher> { new Dispatcher("Виктор"), new Dispatcher("Вова"), new Dispatcher("Артур") }, random.Next(-200, 200));
        private static City paris = new City("Париж", new List<Dispatcher> { new Dispatcher("Даниэль") }, random.Next(-200, 200));
        private static City sanFrancisco = new City("Лос-Анджелес", new List<Dispatcher> { new Dispatcher("Вильям"), new Dispatcher("Дэвид") }, random.Next(-200, 200));
        private static List<City> cities = new List<City>() { minsk, mosсow, kiev, paris, sanFrancisco };

        public static List<City> GetData()
        {
            return cities;
        }
    }
}
