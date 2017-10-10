using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace file
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileName = "text.txt";
            var fileInfo = new FileInfo(fileName);
            StreamWriter writer;
            if (!fileInfo.Exists)
                writer = fileInfo.CreateText();
            else
                writer = fileInfo.AppendText();

            using (writer)
            {
                writer.WriteLine(Console.ReadLine());
            }

            var newFileName = "newText.txt";
            File.Delete(newFileName);
            File.Copy(fileName, newFileName);
            Console.WriteLine(fileInfo.Exists);

            var fileText = File.ReadAllText(newFileName);
            File.WriteAllText(fileInfo.FullName, fileText.Substring(0, 5));
        }
    }
}
