using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace server
{
    class Program
    {
        static void Main(string[] args)
        {
            UdpClient sendingUdpClient = new UdpClient();
            UdpClient receivingUdpClient = new UdpClient(90);
            var endPointers = new List<IPEndPoint>();
            IPEndPoint receivingEndPoint = null;

            while (true)
            {
                byte[] receiveBytes = receivingUdpClient.Receive(ref receivingEndPoint);
                if (endPointers.Contains(receivingEndPoint) == false)
                    endPointers.Add(receivingEndPoint);

                Console.WriteLine(receiveBytes.Length);

                foreach(IPEndPoint endPoint in endPointers)
                {
                    if(endPoint != receivingEndPoint)
                        sendingUdpClient.Send(receiveBytes, receiveBytes.Length, endPoint);
                }
            }
        }
    }
}