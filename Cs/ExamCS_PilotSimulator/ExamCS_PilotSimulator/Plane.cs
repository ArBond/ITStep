
namespace ExamCS_PilotSimulator
{
    public class Plane
    {
        public PlaneTypes PlaneType { get; set; }

        public int Speed { get; set; }

        public int Height { get; set; }

        public Plane(PlaneTypes planeType)
        {
            PlaneType = planeType;
        }
    }
}
