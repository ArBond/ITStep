using System;
using System.Linq;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using AForge.Video;
using AForge.Video.DirectShow;
using NAudio.Wave;
using System.Threading.Tasks;
using System.Drawing;

namespace client
{
    class Client
    {
        private MainForm mainForm;

        private Bitmap waitingGif;

        public string Name { get; set; } = "User";
        public long Id { get; private set; }

        public Socket TcpSocket { get; private set; }
        //public Socket UdpSocket { get; private set; }
        //private UdpClient receivingUdpClient;

        protected FilterInfoCollection videoDevices;
        protected VideoCaptureDevice activeVideoDevice;

        protected WaveIn currentAudioDevice;
        protected WaveOut friendAudio;
        //буфферный поток для передачи через сеть
        protected BufferedWaveProvider bufferStream;

        protected bool connected = false;

        private Thread receivingThread;

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

        public Client()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            mainForm = new MainForm();
            waitingGif = new Bitmap("waiting.gif");

            mainForm.FormClosing += CloseForm;
            mainForm.ConnectButton.Click += ConnectButton_Click;
            mainForm.StartCameraButton.Click += StartCameraButton_Click;
            mainForm.StartMicroButton.Click += StartMicroButton_Click;
            mainForm.SendMessageButton.Click += SendMessageButton_Click;

            ConnectToServer();
        }

        public void Start()
        {
            Application.Run(mainForm);
        }

        public void ConnectToServer()
        {
            bool connected = Task.Factory.StartNew(() =>
            {
                TcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                var result = TcpSocket.BeginConnect(Dns.GetHostAddresses("bondcher.hopto.org")[0], 70, null, null);

                var success = result.AsyncWaitHandle.WaitOne(4000);

                if (!success)
                {
                    MessageBox.Show("Server is not availabe. Please try to connect later.");
                    return false;
                }
                else
                {
                    return true;
                }

                //TcpSocket.Connect(IPAddress.Parse("192.168.4.65"), 70);

                //UdpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                //TcpSocket.Connect(Dns.GetHostAddresses("bondcher.hopto.org")[0], 70);
                //udpSocket.Connect(IPAddress.Parse("192.168.4.51"), 90);
            }).Result;

            if(connected == true)
            {
                receivingThread = new Thread(new ThreadStart(Receiving));
                receivingThread.Start();
            }
        }

        private void Receiving()
        {
            byte[] receiveBytes = new byte[TcpSocket.ReceiveBufferSize];
            int size;
            byte[] receiveInformation;
            byte[] packageType = new byte[8];

            while (true)
            {
                try
                {
                    //get information and type
                    size = TcpSocket.Receive(receiveBytes);
                    receiveInformation = new byte[size];
                    Array.Copy(receiveBytes, receiveInformation, size);
                    Array.Copy(receiveInformation, size - 24, packageType, 0, 8);
                }
                catch
                {
                    MessageBox.Show("Exeption in getting information from package");
                    break;
                }

                try
                {
                    // signal
                    if (packageType.SequenceEqual(byteStringSignal))
                        GetSignalPackage(receiveInformation);

                    // video
                    else if(packageType.SequenceEqual(byteStringCamVideo))
                    {

                    }

                    // audio
                    else if (packageType.SequenceEqual(byteStringMicAudio))
                    {

                    }

                    // message
                    else if (packageType.SequenceEqual(byteStringTMessage))
                    {
                        GetTMessagePackaage(receiveInformation);
                    }
                }
                catch { }
            }
        }

        private void GetTMessagePackaage(byte[] receiveInformation)
        {
            var message = Encoding.UTF8.GetString(receiveInformation, 0, receiveInformation.Length - 24);
            mainForm.ChatTextBox.AppendText("\r\nFriend  " + DateTime.Now.ToShortTimeString() + " :\r\n" + message + "\r\n");
        }

        private void GetSignalPackage(byte[] receiveInformation)
        {
            byte[] type = new byte[8];
            Array.Copy(receiveInformation, receiveInformation.Length - 16, type, 0, 8);

            // signal connect
            if (type.SequenceEqual(byteStringConnect))
            {

            }

            //signal disconnect
            else if (type.SequenceEqual(byteStringDisConnect))
            {

            }

            //signal agree to connect
            else if (type.SequenceEqual(byteStringYesConnect))
            {

            }

            //signal disagree to connect
            else if (type.SequenceEqual(byteStringNoConnect))
            {

            }

            //signal client limit
            else if (type.SequenceEqual(byteStringClientsLimit))
            {

            }

            //signal id not found
            else if (type.SequenceEqual(byteStringErrorId))
            {

            }

            //signal your id
            else if (type.SequenceEqual(byteStringClientId))
            {
                Id = Int64.Parse(Encoding.UTF8.GetString(receiveInformation, 0, 6));
                mainForm.Text = Id.ToString();
                mainForm.ConnectButton.Enabled = true;
                mainForm.StartCameraButton.Enabled = true;
                mainForm.StartMicroButton.Enabled = true;
            }
        }

        private void SendMessageButton_Click(object sender, EventArgs e)
        {
            byte[] sendingPackage = new byte[mainForm.SendingMessageTextBox.Text.Length + 24];
            byte[] byteMessage = Encoding.UTF8.GetBytes(mainForm.SendingMessageTextBox.Text);
            Array.Copy(byteMessage, sendingPackage, byteMessage.Length);
            Array.Copy(byteStringTMessage, 0, sendingPackage, sendingPackage.Length - 24, 8);
            TcpSocket.Send(sendingPackage);
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            long recipientId;
            var result = Int64.TryParse(mainForm.recipientIdTextBox.Text, out recipientId);
            if (result == false)
            {
                MessageBox.Show("Incorrect ID!");
                return;
            }
            if(connected == false)
            {
                mainForm.friendsPictureBox.Image = waitingGif;
                mainForm.ChatTextBox.Clear();
                mainForm.ConnectButton.Enabled = false;
                SendConnectSignal(recipientId);

            }
            else
            {
                mainForm.friendsPictureBox.Image = null;
                mainForm.friendsPictureBox.Invalidate();
                mainForm.SendMessageButton.Enabled = false;
                connected = false;
                SendDisconnectSignal(recipientId);

                mainForm.ConnectButton.Text = "Connect";
            }
            
        }

        private void SendConnectSignal(long recipientId)
        {
            byte[] sendingPackage = new byte[Name.Length + 30];
            byte[] byteName = Encoding.UTF8.GetBytes(Name);
            Array.Copy(byteName, sendingPackage, byteName.Length);
            Array.Copy(Encoding.UTF8.GetBytes(Id.ToString()), 0, sendingPackage, byteName.Length, 6);
            Array.Copy(byteStringSignal, 0, sendingPackage, sendingPackage.Length - 24, 8);
            Array.Copy(byteStringConnect, 0, sendingPackage, sendingPackage.Length - 16, 8);
            TcpSocket.Send(sendingPackage);
        }

        private void SendDisconnectSignal(long recipientId)
        {
            byte[] sendingPackage = new byte[24];
            Array.Copy(byteStringSignal, sendingPackage, 8);
            Array.Copy(byteStringDisConnect, 0, sendingPackage, 8, 8);
            TcpSocket.Send(sendingPackage);
        }

        private void StartMicroButton_Click(object sender, EventArgs e)
        {

        }

        private void StartCameraButton_Click(object sender, EventArgs e)
        {

        }

        private void CloseForm(object sender, FormClosingEventArgs e)
        {
            receivingThread?.Abort();
        }
    }
}