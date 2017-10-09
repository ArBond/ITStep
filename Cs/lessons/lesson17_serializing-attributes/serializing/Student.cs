using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace serializable
{
    [Serializable]

    public class Student
    {
        private string test = "test";

        [NonSerialized]
        [XmlIgnore]
        public int[] marks = new int[1000];

        [XmlAttribute]
        public string FullName { get; set; }
        public DateTime BirthDate { get; set; }
        public bool AccesToExam { get; set; }

        [OnSerializing]
        private void OnSerializing(StreamingContext context)
        {
            FullName = FullName.ToUpper();
        }

        [OnDeserialized]
        private void OnDeserialized(StreamingContext context)
        {
            FullName = FullName.ToLower();
        }
    }
}
