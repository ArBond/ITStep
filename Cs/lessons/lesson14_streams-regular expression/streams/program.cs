using System;
using System.IO;

namespace lesson14_streams
{
    class Program
    {
        static void Main(string[] args)
        {
            //SelectDirectory(".");
            using (var stream = File.Create("text.txt", 256))
            {
                Console.WriteLine(stream.Name);
                stream.WriteByte(123);

                using (var writer = new StreamWriter(stream)) // или using или flush
                {
                    writer.WriteLine("Hello bich");
                    writer.WriteLine("10");
                    writer.WriteLine(true);
                }
            }

            using (var stream = File.OpenRead("text.txt"))
            {
                Console.WriteLine(stream.ReadByte());

                using (var reader = new StreamReader(stream))
                {
                    Console.WriteLine(reader.ReadToEnd());
                }
            }

            using (var stream = new FileStream("test.bin", FileMode.Create))
            {
                var writer = new BinaryWriter(stream);
                writer.Write("Hello bich");
                writer.Write(10);
                writer.Write(true);
                writer.Flush();
                writer.Seek(0, SeekOrigin.Begin);

                using (var reader = new BinaryReader(stream))
                {
                    Console.WriteLine(reader.ReadString());
                    Console.WriteLine(reader.ReadInt32());
                    Console.WriteLine(reader.ReadBoolean());
                }
            }
        }

        public static void SelectDirectory(string current)
        {
            if (!Directory.Exists(current))
            {
                Console.WriteLine("Directory not  found.");
                return;
            }
            var info = new DirectoryInfo(current);
            Console.WriteLine(info.FullName);
            foreach (var subDir in info.GetDirectories())
                Console.WriteLine(subDir.Name);

            foreach (var file in info.GetFiles())
                Console.WriteLine(file.Name);
        }
    }
}
