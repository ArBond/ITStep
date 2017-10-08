using System;

namespace hw11_03._10._17
{
    public struct Information
    {
        public static int[,] IntArray { get; } = new int[2, 4] { { 1, 3, 5, 7 }, { 2, 4, 6, 8 } };
        public static int LengthOfIntArray { get; } = 4;
        public static int HeightOfIntArray { get; } = 2;

        public static double[,] DoubleArray { get; } = new double[3, 2] { { 1.14, 4.92 }, { 2.3, 5.1 }, { 3.23, 6.55 } };
        public static int LengthOfDoubleArray { get; } = 2;
        public static int HeightOfDoubleArray { get; } = 3;

        public string FullName { get; private set; }
        public DateTime BirthDate { get; private set; }

        public Information(string fullName, DateTime birthDate)
        {
            FullName = fullName;
            BirthDate = birthDate;
        }
    }
}
