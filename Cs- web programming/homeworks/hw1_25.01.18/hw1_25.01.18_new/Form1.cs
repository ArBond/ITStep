using System;
using AForge.Video;
using AForge.Video.DirectShow;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.IO;
using NAudio.Wave;

namespace hw1_25._01._18_new
{
    public partial class Form1 : Form
    {
        private FilterInfoCollection videoDevices;
        private VideoCaptureDevice activeVideoDevice;
        private UdpClient sendingUdpClient;
        private IPEndPoint sendingEndPoint;
        private UdpClient receivingUdpClient;       

        private WaveIn currentAudioDevice;
        private WaveOut friendAudio;
        //буфферный поток для передачи через сеть
        private BufferedWaveProvider bufferStream;

        private Bitmap currentBitmap;
        private Thread receivingThread;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //video
            videoDevices = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            foreach (FilterInfo device in videoDevices)
                VideoDevicesComboBox.Items.Add(device.Name);
            VideoDevicesComboBox.SelectedIndex = 0;


            //audio
            currentAudioDevice = new WaveIn();
            currentAudioDevice.WaveFormat = new WaveFormat(8000, 32, 2);

            friendAudio = new WaveOut();
            bufferStream = new BufferedWaveProvider(new WaveFormat(8000, 32, 2));
            //привязываем поток входящего звука к буферному потоку
            friendAudio.Init(bufferStream);

            //наддо будет как то убрать в блок Click_connect
            currentAudioDevice.StartRecording();

        }

        private void StartCameraButton_Click(object sender, EventArgs e)
        {
            if (StartCameraButton.Text == "Turn on camera")
            {
                activeVideoDevice = new VideoCaptureDevice(videoDevices[VideoDevicesComboBox.SelectedIndex].MonikerString);
                activeVideoDevice.VideoResolution = activeVideoDevice.VideoCapabilities[2];
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

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            if (ConnectButton.Text == "Connect")
            {
                sendingUdpClient = new UdpClient();

                sendingEndPoint = new IPEndPoint(IPAddress.Parse(IPAddressTextBox.Text), Int32.Parse(RemotePortTextBox.Text));
                receivingUdpClient = new UdpClient(Int32.Parse(LocalPortTextBox.Text));
                //sendingEndPoint = new IPEndPoint(IPAddress.Parse("192.168.0.103"), 6000);
                //receivingUdpClient = new UdpClient(9000);

                if (activeVideoDevice != null && activeVideoDevice.IsRunning == true)
                    activeVideoDevice.NewFrame += SendVideoBitmap;

                if (currentAudioDevice != null)
                    currentAudioDevice.DataAvailable += SendAudio;

                friendAudio.Play();

                receivingThread = new Thread(new ThreadStart(Receiving));
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

                if (activeVideoDevice != null)
                    activeVideoDevice.NewFrame -= SendVideoBitmap;

                if (currentAudioDevice != null)
                    currentAudioDevice.DataAvailable -= SendAudio;

                friendAudio?.Stop();

                ConnectButton.Text = "Connect";
            }
        }

        private void SendAudio(object sender, WaveInEventArgs e)
        {
            byte[] sendingAudioBuff = e.Buffer;
            Array.Resize(ref sendingAudioBuff, sendingAudioBuff.Length + 24);
            byte[] type = Encoding.UTF8.GetBytes("micAudio");

            type.CopyTo(sendingAudioBuff, sendingAudioBuff.Length - 24);
            sendingUdpClient?.Send(sendingAudioBuff, sendingAudioBuff.Length, sendingEndPoint);
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
                        byte[] bytePackageCounter = Encoding.UTF8.GetBytes(packageCounter.ToString().ToArray());
                        byte[] type = Encoding.UTF8.GetBytes("camVideo");
                        Array.Copy(bitMapArray, i, packageToSend, 0, 1000);
                        type.CopyTo(packageToSend, 1000);
                        bytePackageCounter.CopyTo(packageToSend, 1008);
                        sendingUdpClient?.Send(packageToSend, 1024, sendingEndPoint);

                        packageCounter++;
                    }
                }
            }
            catch (Exception ex)
            {
            }
        }

        private void Receiving()
        {
            IPEndPoint RemoteIpEndPoint = null;
            byte[] inputType = new byte[8];
            int lastVideoPackage = 0;
            int currentVideoPackage = 0;

            try
            {
                using (var stream = new MemoryStream())
                {
                    while (true)
                    {
                        byte[] receiveBytes = receivingUdpClient.Receive(ref RemoteIpEndPoint);
                        Array.Copy(receiveBytes, receiveBytes.Length - 24, inputType, 0, 8);

                        // video
                        if (Encoding.UTF8.GetString(inputType) == "camVideo")
                        {
                            if (currentVideoPackage < lastVideoPackage)
                            {
                                friendsPictureBox.Image = new Bitmap(stream);
                                stream.SetLength(0);
                            }
                            lastVideoPackage = currentVideoPackage;
                            currentVideoPackage = Convert.ToInt32(Encoding.UTF8.GetString(receiveBytes, 1008, 16));
                            stream.WriteAsync(receiveBytes, 0, 1000);
                        }

                        //audio 
                        else if(Encoding.UTF8.GetString(inputType) == "micAudio")
                        {
                            bufferStream.AddSamples(receiveBytes, 0, receiveBytes.Length - 24);
                        }

                        //message
                        else if (Encoding.UTF8.GetString(inputType) == "message")
                        {
                            // will be later
                        }
                    }
                }
            }
            catch (Exception ex)
            {
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            activeVideoDevice?.SignalToStop();
            sendingUdpClient?.Close();
            receivingUdpClient?.Close();
            currentAudioDevice.StopRecording();
        }
    }
}