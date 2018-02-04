using System;
using AForge.Video;
using AForge.Video.DirectShow;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;
using System.IO;

namespace hw1_25._01._18_new
{
    public partial class Form1 : Form
    {
        private FilterInfoCollection videoDevices;
        private VideoCaptureDevice activeVideoDevice;
        private UdpClient sendingUdpClient;
        private IPEndPoint sendingEndPoint;
        private UdpClient receivingUdpClient;
        private Bitmap currentBitmap;
        private Thread receivingThread;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            videoDevices = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            foreach(FilterInfo device in videoDevices)
                VideoDevicesComboBox.Items.Add(device.Name);
            VideoDevicesComboBox.SelectedIndex = 0;
        }

        private void StartCameraButton_Click(object sender, EventArgs e)
        {
            if (StartCameraButton.Text == "Turn on camera")
            {
                activeVideoDevice = new VideoCaptureDevice(videoDevices[VideoDevicesComboBox.SelectedIndex].MonikerString);
                activeVideoDevice.VideoResolution = activeVideoDevice.VideoCapabilities[3];
                activeVideoDevice.NewFrame += UpdateMyPictyreBox;
                activeVideoDevice.Start();
 
                StartCameraButton.Text = "Turn of camera";
            }
            else
            {
                activeVideoDevice.NewFrame -= UpdateMyPictyreBox;
                activeVideoDevice.Stop();

                MyPictureBox.Image = null;
                MyPictureBox.Invalidate();

                StartCameraButton.Text = "Turn on camera";
            }
        }

        private void UpdateMyPictyreBox(object sender, NewFrameEventArgs eventArgs)
        {
            var oldBitmap = currentBitmap;     
            currentBitmap = (Bitmap)eventArgs.Frame.Clone();
            MyPictureBox.Image = currentBitmap;
            oldBitmap?.Dispose();

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            activeVideoDevice?.SignalToStop();
            receivingUdpClient?.Close();
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            if (ConnectButton.Text == "Connect")
            {
                sendingUdpClient = new UdpClient();

                sendingEndPoint = new IPEndPoint(IPAddress.Parse(IPAddressTextBox.Text), Int32.Parse(RemotePortTextBox.Text));
                receivingUdpClient = new UdpClient(Int32.Parse(LocalPortTextBox.Text));
                //sendingEndPoint = new IPEndPoint(IPAddress.Parse("192.168.0.103"), 6000);
                //receivingUdpClient = new UdpClient(9000);

                if(activeVideoDevice != null && activeVideoDevice.IsRunning == true)
                    activeVideoDevice.NewFrame += SendVideoBitmap;

                receivingThread = new Thread(new ThreadStart(ReceivingVideoBitmap));
                receivingThread.Start();

                ConnectButton.Text = "Disconnect";
            }
            else
            {
                receivingThread?.Abort();
                sendingUdpClient?.Close();
                receivingUdpClient?.Close();

                friendsPictureBox.Image = null;
                friendsPictureBox.Invalidate();

                if(activeVideoDevice != null)
                    activeVideoDevice.NewFrame -= SendVideoBitmap;

                ConnectButton.Text = "Connect";
            }
        }

        private void SendVideoBitmap(object sender, NewFrameEventArgs eventArgs)
        {
            try
            {
                using (var stream = new MemoryStream())
                {
                    var picture = eventArgs.Frame;
                    picture.Save(stream, System.Drawing.Imaging.ImageFormat.Png);
                    byte[] bitMapArray = stream.ToArray();
                    byte[] packageToSend = new byte[1024];

                    int packageCounter = 0;
                    for (int i = 0; i < bitMapArray.Length - 1000; i += 1000)
                    {
                        byte[] buff = Encoding.UTF8.GetBytes( packageCounter.ToString().ToArray());
                        Array.Copy(bitMapArray, i, packageToSend, 0, 1000);
                        buff.CopyTo(packageToSend, 1000);
                        sendingUdpClient?.Send(packageToSend, 1024, sendingEndPoint);

                        packageCounter++;
                    }
                }
            }
            catch (Exception ex)
            {
            }
        }

        private void ReceivingVideoBitmap()
        {
            IPEndPoint RemoteIpEndPoint = null;
            try
            {
                while (true)
                {
                    int lastPackage = 0;
                    int currentPackage = 0;
                    using (var stream = new MemoryStream())
                    {
                        while (currentPackage >= lastPackage)
                        {
                            lastPackage = currentPackage;
                            byte[] receiveBytes = receivingUdpClient.Receive(ref RemoteIpEndPoint);
                            currentPackage = Convert.ToInt32(Encoding.UTF8.GetString(receiveBytes, 1000, 24));
                            stream.WriteAsync(receiveBytes, 0, 1000);
                        }
                        friendsPictureBox.Image = new Bitmap(stream);
                    }
                }
            }
            catch (Exception ex)
            {
            }
        }
    }
}