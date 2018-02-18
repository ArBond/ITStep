namespace server
{
    class Program
    {
        static void Main(string[] args)
        {
            var server = new MyServer(70, 90, 2);
            server.Start();
        }
    }
}