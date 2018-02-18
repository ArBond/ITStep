using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;


namespace server
{
    class MyServer
    {
        // ЗАНЯТ ИЛИ НЕ ЗАНЯТ КЛИЕНТ НА СЛУЧАЙ НЕСКОЛЬКИХ КОННЕКТОВ ОДНОВРЕМЕННО

        private long id = 100000;
        public long MaxClientQuantity { get; private set; }

        //private Dictionary<string, string> accounts = new Dictionary<string, string>();
        private Dictionary<long, Socket> activeClientsId = new Dictionary<long, Socket>();
        private Dictionary<Socket, long> activeClientsSockets = new Dictionary<Socket, long>();
        private Dictionary<Socket, Socket> privateConnections = new Dictionary<Socket, Socket>();

        public Socket TcpSocket { get; private set; }
        //public Socket UdpSocket { get; private set; }

        //private EndPoint udpRemoteEndPoint;

        private int serverTcpPort;
        private int serverUdpPort;

        private byte[] byteStringSignal = Encoding.UTF8.GetBytes("mySignal");
        private byte[] byteStringCamVideo = Encoding.UTF8.GetBytes("camVideo");
        private byte[] byteStringMicAudio = Encoding.UTF8.GetBytes("micAudio");
        private byte[] byteStringTMessage = Encoding.UTF8.GetBytes("tMessage");

        //private byte[] byteStringSignIn = Encoding.UTF8.GetBytes("signIn\0\0");
        //private byte[] byteStringSignUp = Encoding.UTF8.GetBytes("signUp\0\0");
        private byte[] byteStringConnect = Encoding.UTF8.GetBytes("connect\0");
        private byte[] byteStringDisConnect = Encoding.UTF8.GetBytes("dConnect");
        private byte[] byteStringYesConnect = Encoding.UTF8.GetBytes("yConnect");
        private byte[] byteStringNoConnect = Encoding.UTF8.GetBytes("nConnect");
        private byte[] byteStringClientsLimit = Encoding.UTF8.GetBytes("cliLimit");
        private byte[] byteStringErrorId = Encoding.UTF8.GetBytes("errorId\0");
        private byte[] byteStringClientId = Encoding.UTF8.GetBytes("clientId");

        public MyServer(int tcpPort, int udpPort, long maxClientQuantity)
        {
            try
            {
                //LoadData();

                MaxClientQuantity = maxClientQuantity;

                serverTcpPort = tcpPort;
                serverUdpPort = udpPort;

                TcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                TcpSocket.Bind(new IPEndPoint(IPAddress.Any, serverTcpPort));
                TcpSocket.Listen(10);

                //UdpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                //UdpSocket.Bind(new IPEndPoint(IPAddress.Any, udpPort));
                //udpRemoteEndPoint = new IPEndPoint(IPAddress.Any, serverUdpPort);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception during start: " + ex.Message);
            }
        }

        //~MyServer()
        //{
        //    SaveData();
        //}

        public void Start()
        {
            Console.WriteLine("Server started...");
            while (true)
            {
                try
                {
                    Socket newSocket = TcpSocket.Accept();
                   
                    if (activeClientsId.Count >= MaxClientQuantity)
                    {
                        byte[] sendingPackage = new byte[24];
                        Array.Copy(byteStringSignal, sendingPackage, 8);
                        Array.Copy(byteStringClientsLimit, 0, sendingPackage, 8, 8);
                        newSocket.Send(sendingPackage);
                        Console.WriteLine("Limit clients(" + MaxClientQuantity + ")" + newSocket.RemoteEndPoint + " can not to connected.");
                    }
                    else
                    {
                        Thread thread = new Thread(() => TcpSocketThread(newSocket));
                        var id = AddClient(newSocket);
                        SendIdToClient(id, newSocket);
                        Console.WriteLine(newSocket.RemoteEndPoint + " online.");
                        thread.Start();
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Error in connecting of new socket: " + ex.Message);
                }
            }
        }

        private void SendIdToClient(long id, Socket socket)
        {
            byte[] sendingPackage = new byte[30];
            Array.Copy(Encoding.UTF8.GetBytes(id.ToString()), sendingPackage, 6);
            Array.Copy(byteStringSignal, 0, sendingPackage, 6, 8);
            Array.Copy(byteStringClientId, 0, sendingPackage, 14, 8);
            socket.Send(sendingPackage);
        }

        private void TcpSocketThread(Socket socket)
        {
            byte[] receiveBytes = new byte[socket.ReceiveBufferSize];
            int size;
            byte[] receiveInformation;
            byte[] packageType = new byte[8];

            while (true)
            {
                try
                {
                    //get information and type
                    size = socket.Receive(receiveBytes);
                    receiveInformation = new byte[size];
                    Array.Copy(receiveBytes, receiveInformation, size); 
                    Array.Copy(receiveInformation, size - 24, packageType, 0, 8);
                }
                catch
                {
                    break;
                }

                try
                {
                    // signal
                    if (packageType.SequenceEqual(byteStringSignal)) 
                        GetSignalPackage(receiveInformation, socket);

                    // audio, video, message
                    else
                        SendOnPackage(receiveInformation, socket);
                }
                catch { }
            }
            Console.WriteLine(socket.RemoteEndPoint + " offline.");

            DeleteClient(socket);   
        }

        private void GetSignalPackage(byte[] receiveInformation, Socket socket)
        {
            byte[] type = new byte[8];
            Array.Copy(receiveInformation, receiveInformation.Length - 16, type, 0, 8);
            
            // signal connect
            if (type.SequenceEqual(byteStringConnect))
            {
                Socket recipient = FindRecipient(receiveInformation);
                if(recipient != null)
                    recipient.Send(receiveInformation);
                else
                    socket.Send(receiveInformation);
            }

            //signal disconnect
            else if (type.SequenceEqual(byteStringDisConnect))
            {
                SendOnPackage(receiveInformation, socket);
                DeletePrivateConnection(socket);
            }

            //signal agree to connect
            else if (type.SequenceEqual(byteStringYesConnect))
            {
                Socket recipient = FindRecipient(receiveInformation);
                if (recipient != null)
                {
                    AddPrivateConnection(recipient, socket);
                    recipient.Send(receiveInformation);
                }
                else
                {
                    byte[] sendingPackage = new byte[16];
                    Array.Copy(byteStringSignal, sendingPackage, 8);
                    Array.Copy(byteStringDisConnect, 0, sendingPackage, 8, 8);
                    socket.Send(sendingPackage);
                }
            }

            //signal disagree to connect
            else if (type.SequenceEqual(byteStringNoConnect))
            {
                SendOnPackage(receiveInformation, socket);
            }

            else
            {
                Console.WriteLine("Error signal type!");
            }
        }

        private void AddPrivateConnection(Socket first, Socket second)
        {
            privateConnections.Add(first, second);
            privateConnections.Add(second, first);
        }

        private Socket FindRecipient(byte[] receiveInformation)
        {
            var recipientId = Int64.Parse(Encoding.UTF8.GetString(receiveInformation, 0, receiveInformation.Length - 30));
            try
            {
                return activeClientsId[recipientId];
            }
            catch
            {
                return null;
            }
        }

        private void DeletePrivateConnection(Socket socket)
        {
            var secondSocket = privateConnections[socket];
            privateConnections.Remove(socket);
            privateConnections.Remove(secondSocket);
        }

        private void SendOnPackage(byte[] receiveInformation, Socket socket)
        {
            try
            {
                privateConnections[socket].Send(receiveInformation);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Send on exception: " + ex.Message);
            }
        }

        private void DeleteClient(Socket socket)
        {
            var id = activeClientsSockets[socket];
            activeClientsId[id].Close();
            activeClientsId.Remove(id);
            activeClientsSockets.Remove(socket);
        }

        private long AddClient(Socket newSocket)
        {
            while (true)
            {
                if (id >= 1000000)
                    id = 100000;
                if(activeClientsId.ContainsKey(id))
                    id++;
                else
                {
                    activeClientsId.Add(id, newSocket);
                    activeClientsSockets.Add(newSocket, id);
                    id++;
                    return id - 1;
                }
            }
        }

        //private void LoadData()
        //{
        //    using (var reader = new StreamReader("accounts.txt"))
        //    {
        //        string[] accountData;
        //        while (!reader.EndOfStream)
        //        {
        //            accountData = reader.ReadLine().Split(' ');
        //            accounts.Add(accountData[0], accountData[1]);
        //        }
        //    }
        //}

        //private void SaveData()
        //{
        //    using (var writer = new StreamWriter("accounts.txt"))
        //    {
        //        foreach (var account in accounts)
        //            writer.WriteLine(account.Key + " " + account.Value);
        //    }
        //}
    }
}




//if (type.SequenceEqual(byteStringSignIn))
//{
//        byte[] sendingPackage = new byte[1];
//        var login = Encoding.UTF8.GetString(receiveInformation, 0, 15);
//        realLogin = login.Substring(0, login.IndexOf('\0'));
//        var password = Encoding.UTF8.GetString(receiveInformation, 15, 15);
//        var realPassword = password.Substring(0, password.IndexOf('\0'));

//        var clientEndPoint = (IPEndPoint)socket.RemoteEndPoint;

//                if (accounts.ContainsKey(realLogin) && accounts[realLogin] == realPassword)
//                {   
//                    activeClientsSockets.Add(realLogin, socket);
//                    Console.WriteLine(realLogin + " " + clientEndPoint.Address + ":" + clientEndPoint.Port + ": Signed in!");
//                }
//                else
//                {
//                    sendingPackage[0] = 49;
//                    Console.WriteLine(realLogin + " " + clientEndPoint.Address + ":" + clientEndPoint.Port + ": Attempt to sign in.");
//                    realLogin = null;
//                }
//                socket.Send(sendingPackage);
//    }
//    else if (type.SequenceEqual(byteStringSignUp))
//    {
//        byte[] sendingPackage = new byte[1];
//        var login = Encoding.UTF8.GetString(receiveInformation, 20, 15);
//        realLogin = login.Substring(0, login.IndexOf('\0'));
//                var password = Encoding.UTF8.GetString(receiveInformation, 35, 15);
//        var realPassword = password.Substring(0, password.IndexOf('\0'));

//        var clientEndPoint = (IPEndPoint)socket.RemoteEndPoint;

//                if(accounts.ContainsKey(realLogin))
//                {
//                    sendingPackage[0] = 49;
//                    Console.WriteLine(realLogin + " " + clientEndPoint.Address + ":" + clientEndPoint.Port + "  Attempt to sign up.");
//                    realLogin = null;
//                }
//                else
//                {
//                    accounts.Add(realLogin, realPassword);
//                    activeClientsSockets.Add(realLogin, socket);
//                    Console.WriteLine(realLogin + " " + clientEndPoint.Address + ":" + clientEndPoint.Port + "  Signed up!");
//                }
//                socket.Send(sendingPackage);
//}