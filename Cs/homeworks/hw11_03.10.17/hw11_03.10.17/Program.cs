using System;
using System.IO;
using System.Linq;
using System.Text;

namespace hw11_03._10._17
{
    class Program
    {
        static void CreateFile(string fileName)
        {
            if(File.Exists(fileName))
            {
                Console.WriteLine("File already exist.");
                return;
            }
            using (var stream = File.Create(fileName))
            {
                Console.WriteLine("File created.");
            }
        }

        static T[,] ReadArray<T>(StreamReader reader, out int length, out int heigth)
        {
            string[] arrayParams = reader.ReadLine().Split(' ').ToArray();
            length = int.Parse(arrayParams[0]);
            heigth = int.Parse(arrayParams[1]);

            var array = new T[heigth, length];

            for(int i = 0; i < heigth; i++)
            {
                string[] arrayString = reader.ReadLine().Split(' ').ToArray();
                for(int j = 0; j < length; j++)
                {
                    array[i, j] = (T)Convert.ChangeType(arrayString[j], typeof(T));
                }
            }
            return array;
        }

        static void ReadFromFile(string fileName)
        {
            if (!File.Exists(fileName))
            {
                Console.WriteLine("File is missing.");
                return;
            }
            using (var reader = new StreamReader(fileName))
            {
                string[] fioAndBirthDate = reader.ReadLine().Split(' ').ToArray();
                var fioBuilder = new StringBuilder();
                for (int i = 0; i < fioAndBirthDate.Length - 1; i++)
                    fioBuilder.Append($"{fioAndBirthDate[i]} ");
                var fio = fioBuilder.ToString();
                DateTime birthDate = DateTime.Parse(fioAndBirthDate[fioAndBirthDate.Length - 1]);
                int lengthOfDoubleArray;
                int heightOfDoubleArray;
                var doubleArray = ReadArray<double>(reader, out lengthOfDoubleArray, out heightOfDoubleArray);
                int lengthOfIntArray;
                int heightOfIntArray;
                var intArray = ReadArray<int>(reader, out lengthOfIntArray, out heightOfIntArray);
                DateTime recordingTime = DateTime.Parse(reader.ReadLine());

                Console.WriteLine($"Full name: {fio}    Birth date: {birthDate.ToShortDateString()}");
                Console.WriteLine($"Double array(length: {lengthOfDoubleArray} heigth: {heightOfDoubleArray})");
                for (int i = 0; i < heightOfDoubleArray; i++)
                {
                    for (int j = 0; j < lengthOfDoubleArray; j++)
                    {
                        Console.Write($"{doubleArray[i, j]} ");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine($"Int array(length: {lengthOfIntArray} heigth{heightOfIntArray})");
                for (int i = 0; i < heightOfIntArray; i++)
                {
                    for (int j = 0; j < lengthOfIntArray; j++)
                    {
                        Console.Write($"{intArray[i, j]} ");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine(recordingTime.ToShortDateString());
            }
        }

        static void WriteArray<T>(StreamWriter writer, T[,] array, int height, int length)
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    writer.Write($"{array[i, j]} ");
                }
                writer.WriteLine();
            }
        }

        static void RecordToFile(string fileName)
        {
            Console.WriteLine("Enter your full name:");
            var fullName = Console.ReadLine();
            Console.WriteLine("Your birth date:");
            DateTime birthDate;
            while (true)
            {
                if (DateTime.TryParse(Console.ReadLine(), out birthDate))
                    break;
                Console.WriteLine("Invalid date format. Please enter the date again.\n");
            }
            var info = new Information(fullName, birthDate);

            if (!File.Exists(fileName))
            {
                Console.WriteLine("File is missing. Create?\n 1 - yes\n 0 - no\n");
                if(Console.ReadLine() == "0")
                    return;
            }
            var fileInfo = new FileInfo(fileName);
            if(fileInfo.Length != 0)
            {
                Console.Write("File not empty. Overwrite file?\n 1 - yes\n 0 - no\n");
                if (Console.ReadLine() == "0")
                    return;
            }
            using (var writer = new StreamWriter("Day17.txt"))
            {
                writer.WriteLine($"{info.FullName} {birthDate.ToShortDateString()}");
                writer.WriteLine($"{Information.LengthOfDoubleArray} {Information.HeightOfDoubleArray}");
                WriteArray(writer, Information.DoubleArray, Information.HeightOfDoubleArray, Information.LengthOfDoubleArray);
                writer.WriteLine($"{Information.LengthOfIntArray} {Information.HeightOfIntArray}");
                WriteArray(writer, Information.IntArray, Information.HeightOfIntArray, Information.LengthOfIntArray);
                writer.Write(DateTime.Now.ToShortDateString());
            }
            Console.WriteLine("Completed.");
        }

        static void Main(string[] args)
        {
            var fileName = "Day17.txt";
            Console.WriteLine($"Welcome!\nToday we work with file {fileName}");
            var exit = false;
            while(!exit)
            {
                Console.ReadKey();
                Console.Clear();
                Console.WriteLine($"Choose operation:\n 1 - Create file\n 2 - Read from file\n 3 - record to file\n 0 - exit\n");
                switch(Console.ReadLine())
                {
                    case "1":
                        CreateFile(fileName);
                        break;
                    case "2":
                        ReadFromFile(fileName);
                        break;
                    case "3":
                        RecordToFile(fileName);
                        break;
                    case "0":
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("There is no such item.");
                        break;
                }
            }
        }
    }
}
