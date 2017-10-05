using System;

namespace lesson15_xml
{
    /// <summary>
    /// Represents IT academy student
    /// </summary>
    public class Student
    {
        /// <summary>
        /// Student name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Inirializes a new instances of <see cref="Student"/> class.
        /// </summary>
        public Student()
        {
        }

        /// <summary>
        /// Provides an answer to the specified <paramref name="question"/>
        /// </summary>
        /// <param name="question">Should end with question sign</param>
        /// <returns>Comma separated answers</returns>
        public string Answer(string question)
        {
            return "I don't know";
        }
    }
}
