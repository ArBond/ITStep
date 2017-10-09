using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap; // add reference soap in solution explorer
using System.Xml.Serialization;

namespace serializable
{
    class Program
    {
        static void Main(string[] args)
        {
            var student = new Student() { FullName = "Artemi Bondarenko", BirthDate = new DateTime(1997, 12, 08), AccesToExam = true };

            var fileName = "student.bin";    //  BinaryFormatter
            using (var stream = File.OpenWrite(fileName))
            {
                var formatter = new BinaryFormatter();
                formatter.Serialize(stream, student);
            }

            using (var stream = File.OpenRead(fileName))
            {
                var formatter = new BinaryFormatter();
                var newStudent = (Student)formatter.Deserialize(stream);
                Console.WriteLine($"{newStudent.FullName}  {newStudent.BirthDate.ToShortDateString()}\nAccesToExam: {newStudent.AccesToExam}");
            }


            fileName = "student.xml";     //  SoapFormatter
            using (var stream = File.OpenWrite(fileName))
            {
                var formatter = new SoapFormatter();
                formatter.Serialize(stream, student);
            }

            using (var stream = File.OpenRead(fileName))
            {
                var formatter = new SoapFormatter();
                var newStudent = (Student)formatter.Deserialize(stream);
                Console.WriteLine($"{newStudent.FullName}  {newStudent.BirthDate.ToShortDateString()}\nAccesToExam: {newStudent.AccesToExam}");
            }


            fileName = "studentXml.xml";    //  XmlSerializer    <-  сериализует только паблик свойста и поля, у него свои аттрибуты
            using (var stream = new FileStream(fileName, FileMode.Create))
            {
                var formatter = new XmlSerializer(typeof(Student));
                formatter.Serialize(stream, student);
            }

            using (var stream = File.OpenRead(fileName))
            {
                var formatter = new XmlSerializer(typeof(Student));
                var newStudent = (Student)formatter.Deserialize(stream);
                Console.WriteLine($"{newStudent.FullName}  {newStudent.BirthDate.ToShortDateString()}\nAccesToExam: {newStudent.AccesToExam}");
            }
        }
    }
}
