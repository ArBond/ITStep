﻿using System;
using AForge.Video;
using AForge.Video.DirectShow;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.IO;
using NAudio.Wave;
using client;

namespace hw1_25._01._18_new
{
    [ObsoleteAttribute]
    public partial class MainWindow : Form
    {
        private MyClient client;
        private FilterInfoCollection videoDevices;
        private VideoCaptureDevice activeVideoDevice;

        private WaveIn currentAudioDevice;
        private WaveOut friendAudio;
        //буфферный поток для передачи через сеть
        private BufferedWaveProvider bufferStream;

        private Bitmap currentBitmap;
        private Thread receivingThread;

        public MainWindow()
        {
            InitializeComponent();
            client = new MyClient();
            try
            {
                client.ConnectToServer();
            }
            catch
            {
                MessageBox.Show("Server is not available. Please try to connact later.");
                Application.Exit();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ////video
            //videoDevices = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            //foreach (FilterInfo device in videoDevices)
            //    VideoDevicesComboBox.Items.Add(device.Name);
            //if(VideoDevicesComboBox.Items.Count != 0)
            //    VideoDevicesComboBox.SelectedIndex = 0;


            ////audio
            //currentAudioDevice = new WaveIn();
            //currentAudioDevice.WaveFormat = new WaveFormat(8000, 32, 1);

            //friendAudio = new WaveOut();
            //bufferStream = new BufferedWaveProvider(new WaveFormat(8000, 32, 1));
            ////привязываем поток входящего звука к буферному потоку
            //friendAudio.Init(bufferStream);

            ////наддо будет как то убрать в блок Click_connect
            //currentAudioDevice.StartRecording();

        }

        private void StartCameraButton_Click(object sender, EventArgs e)
        {
            //if (StartCameraButton.Text == "Turn on camera")
            //{
            //    activeVideoDevice = new VideoCaptureDevice(videoDevices[VideoDevicesComboBox.SelectedIndex].MonikerString);
            //    activeVideoDevice.VideoResolution = activeVideoDevice.VideoCapabilities[1];

            //    activeVideoDevice.NewFrame += UpdateMyPictyreBox;
            //    activeVideoDevice.Start();

            //    StartCameraButton.Text = "Turn of camera";
            //}
            //else
            //{
            //    activeVideoDevice.NewFrame -= UpdateMyPictyreBox;
            //    activeVideoDevice.Stop();

            //    MyPictureBox.Image = null;
            //    MyPictureBox.Invalidate();

            //    StartCameraButton.Text = "Turn on camera";
            //}
        }

        //private void UpdateMyPictyreBox(object sender, NewFrameEventArgs eventArgs)
        //{
        //    var oldBitmap = currentBitmap;
        //    currentBitmap = (Bitmap)eventArgs.Frame.Clone();
        //    MyPictureBox.Image = currentBitmap;
        //    oldBitmap?.Dispose();
        //}

        private void ConnectButton_Click(object sender, EventArgs e)
        {

            if (client.Connected == false)
            {
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

        private void SendMessageButton_Click(object sender, EventArgs e)
        {
            if (SendingMessageTextBox.Text.Length == 0)
                return;
            var textMessage = SendingMessageTextBox.Text;
            ChatTextBox.AppendText("\r\nMe  " + DateTime.Now.ToShortTimeString() + " :\r\n" + textMessage + "\r\n");
            SendingMessageTextBox.Clear();
            SendTextMessage(textMessage);
        }

        private void SendTextMessage(string textMessage)
        {
            byte[] type = Encoding.UTF8.GetBytes("tMessage");
            byte[] sendingPackage = Encoding.UTF8.GetBytes(textMessage);
            Array.Resize(ref sendingPackage, sendingPackage.Length + 24);
            type.CopyTo(sendingPackage, textMessage.Length);
            sendingUdpClient?.Send(sendingPackage, sendingPackage.Length, sendingEndPoint);
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
            int bitmapPieceSize = 1000;
            try
            {
                using (var stream = new MemoryStream())
                {
                    var picture = eventArgs.Frame;
                    picture.Save(stream, System.Drawing.Imaging.ImageFormat.Jpeg);
                    byte[] bitMapArray = stream.ToArray();
                    byte[] packageToSend = new byte[bitmapPieceSize + 24];

                    int packageCounter = 0;
                    byte[] bytePackageCounter;
                    byte[] type = Encoding.UTF8.GetBytes("camVideo");
                    int i = 0;
                    for (; i < bitMapArray.Length - bitmapPieceSize; i += bitmapPieceSize)
                    {
                        bytePackageCounter = Encoding.UTF8.GetBytes(packageCounter.ToString().ToArray());
                        Array.Copy(bitMapArray, i, packageToSend, 0, bitmapPieceSize);
                        type.CopyTo(packageToSend, bitmapPieceSize);
                        bytePackageCounter.CopyTo(packageToSend, bitmapPieceSize + 8);
                        sendingUdpClient?.Send(packageToSend, bitmapPieceSize + 24, sendingEndPoint);

                        packageCounter++;
                    }
                    var lastPackageLength = bitMapArray.Length - i + 24;
                    Array.Resize(ref packageToSend, lastPackageLength);
                    Array.Clear(packageToSend, 0, packageToSend.Length);
                    bytePackageCounter = Encoding.UTF8.GetBytes(packageCounter.ToString().ToArray());
                    Array.Copy(bitMapArray, i, packageToSend, 0, lastPackageLength - 24);
                    type.CopyTo(packageToSend, lastPackageLength - 24);
                    bytePackageCounter.CopyTo(packageToSend, lastPackageLength - 16);
                    sendingUdpClient?.Send(packageToSend, lastPackageLength, sendingEndPoint);
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

            using (var memStream = new MemoryStream())
            {
                while (true)
                {
                    try
                    {
                        byte[] receiveBytes = receivingUdpClient.Receive(ref RemoteIpEndPoint);
                        Array.Copy(receiveBytes, receiveBytes.Length - 24, inputType, 0, 8);

                        // video
                        if (Encoding.UTF8.GetString(inputType) == "camVideo")
                        {
                            currentVideoPackage = Convert.ToInt32(Encoding.UTF8.GetString(receiveBytes, receiveBytes.Length - 16, 16));
                            if (currentVideoPackage < lastVideoPackage)
                            {
                                friendsPictureBox.Image = new Bitmap(memStream);
                                memStream.SetLength(0);
                            }
                            lastVideoPackage = currentVideoPackage;
                            memStream.WriteAsync(receiveBytes, 0, receiveBytes.Length - 24);
                        }

                        //audio 
                        else if (Encoding.UTF8.GetString(inputType) == "micAudio")
                        {
                            bufferStream.AddSamples(receiveBytes, 0, receiveBytes.Length - 24);
                        }

                        //message
                        else if (Encoding.UTF8.GetString(inputType) == "tMessage")
                        {
                            var message = Encoding.UTF8.GetString(receiveBytes, 0, receiveBytes.Length - 24);
                            ChatTextBox.AppendText("\r\nFriend  " + DateTime.Now.ToShortTimeString() + " :\r\n" + message + "\r\n");
                        }
                    }
                    catch (Exception ex)
                    {
                        lastVideoPackage = 0;
                    }
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            activeVideoDevice?.SignalToStop();
            receivingUdpClient?.Close();
            receivingThread?.Abort();
            currentAudioDevice.StopRecording();
        }
    }
}












//namespace hw1_25._01._18_new
//{
//    [ObsoleteAttribute]
//    public partial class MainWindow : Form
//    {
//        private MyClient client;
//        private FilterInfoCollection videoDevices;
//        private VideoCaptureDevice activeVideoDevice;
//        private UdpClient sendingUdpClient;
//        private IPEndPoint sendingEndPoint;
//        private UdpClient receivingUdpClient;       

//        private WaveIn currentAudioDevice;
//        private WaveOut friendAudio;
//        //буфферный поток для передачи через сеть
//        private BufferedWaveProvider bufferStream;

//        private Bitmap currentBitmap;
//        private Thread receivingThread;

//        public MainWindow()
//        {
//            InitializeComponent();
//            client = new MyClient();
//            try
//            {
//                client.ConnectToServer();
//            }
//            catch
//            {
//                MessageBox.Show("Server is not available. Please try to connact later.");
//                Application.Exit();
//            }
//        }

//        private void Form1_Load(object sender, EventArgs e)
//        {
//            ////video
//            //videoDevices = new FilterInfoCollection(FilterCategory.VideoInputDevice);
//            //foreach (FilterInfo device in videoDevices)
//            //    VideoDevicesComboBox.Items.Add(device.Name);
//            //if(VideoDevicesComboBox.Items.Count != 0)
//            //    VideoDevicesComboBox.SelectedIndex = 0;


//            ////audio
//            //currentAudioDevice = new WaveIn();
//            //currentAudioDevice.WaveFormat = new WaveFormat(8000, 32, 1);

//            //friendAudio = new WaveOut();
//            //bufferStream = new BufferedWaveProvider(new WaveFormat(8000, 32, 1));
//            ////привязываем поток входящего звука к буферному потоку
//            //friendAudio.Init(bufferStream);

//            ////наддо будет как то убрать в блок Click_connect
//            //currentAudioDevice.StartRecording();

//        }

//        private void StartCameraButton_Click(object sender, EventArgs e)
//        {
//            //if (StartCameraButton.Text == "Turn on camera")
//            //{
//            //    activeVideoDevice = new VideoCaptureDevice(videoDevices[VideoDevicesComboBox.SelectedIndex].MonikerString);
//            //    activeVideoDevice.VideoResolution = activeVideoDevice.VideoCapabilities[1];

//            //    activeVideoDevice.NewFrame += UpdateMyPictyreBox;
//            //    activeVideoDevice.Start();

//            //    StartCameraButton.Text = "Turn of camera";
//            //}
//            //else
//            //{
//            //    activeVideoDevice.NewFrame -= UpdateMyPictyreBox;
//            //    activeVideoDevice.Stop();

//            //    MyPictureBox.Image = null;
//            //    MyPictureBox.Invalidate();

//            //    StartCameraButton.Text = "Turn on camera";
//            //}
//        }

//        //private void UpdateMyPictyreBox(object sender, NewFrameEventArgs eventArgs)
//        //{
//        //    var oldBitmap = currentBitmap;
//        //    currentBitmap = (Bitmap)eventArgs.Frame.Clone();
//        //    MyPictureBox.Image = currentBitmap;
//        //    oldBitmap?.Dispose();
//        //}

//        private void ConnectButton_Click(object sender, EventArgs e)
//        {

//            if (client.Connected == false)
//            {
//                if (activeVideoDevice != null && activeVideoDevice.IsRunning == true)
//                    activeVideoDevice.NewFrame += SendVideoBitmap;

//                if (currentAudioDevice != null)
//                    currentAudioDevice.DataAvailable += SendAudio;

//                friendAudio.Play();

//                receivingThread = new Thread(new ThreadStart(Receiving));
//                receivingThread.Start();

//                ConnectButton.Text = "Disconnect";   
//            }
//            else
//            {
//                receivingThread?.Abort();
//                sendingUdpClient?.Close();
//                receivingUdpClient?.Close();

//                friendsPictureBox.Image = null;
//                friendsPictureBox.Invalidate();

//                if (activeVideoDevice != null)
//                    activeVideoDevice.NewFrame -= SendVideoBitmap;

//                if (currentAudioDevice != null)
//                    currentAudioDevice.DataAvailable -= SendAudio;

//                friendAudio?.Stop();

//                ConnectButton.Text = "Connect";
//            }
//        }

//        private void SendMessageButton_Click(object sender, EventArgs e)
//        {
//            if (SendingMessageTextBox.Text.Length == 0)
//                return;
//            var textMessage = SendingMessageTextBox.Text;
//            ChatTextBox.AppendText("\r\nMe  " + DateTime.Now.ToShortTimeString() + " :\r\n" + textMessage + "\r\n");
//            SendingMessageTextBox.Clear();
//            SendTextMessage(textMessage);
//        }

//        private void SendTextMessage(string textMessage)
//        {
//            byte[] type = Encoding.UTF8.GetBytes("tMessage");
//            byte[] sendingPackage = Encoding.UTF8.GetBytes(textMessage);
//            Array.Resize(ref sendingPackage, sendingPackage.Length + 24);
//            type.CopyTo(sendingPackage, textMessage.Length);
//            sendingUdpClient?.Send(sendingPackage, sendingPackage.Length, sendingEndPoint);
//        }

//        private void SendAudio(object sender, WaveInEventArgs e)
//        {
//            byte[] sendingAudioBuff = e.Buffer;
//            Array.Resize(ref sendingAudioBuff, sendingAudioBuff.Length + 24);
//            byte[] type = Encoding.UTF8.GetBytes("micAudio");

//            type.CopyTo(sendingAudioBuff, sendingAudioBuff.Length - 24);
//            sendingUdpClient?.Send(sendingAudioBuff, sendingAudioBuff.Length, sendingEndPoint);
//        }

//        private void SendVideoBitmap(object sender, NewFrameEventArgs eventArgs)
//        {
//            int bitmapPieceSize = 1000;
//            try
//            {
//                using (var stream = new MemoryStream())
//                {
//                    var picture = eventArgs.Frame;
//                    picture.Save(stream, System.Drawing.Imaging.ImageFormat.Jpeg);
//                    byte[] bitMapArray = stream.ToArray();
//                    byte[] packageToSend = new byte[bitmapPieceSize + 24];

//                    int packageCounter = 0;
//                    byte[] bytePackageCounter;
//                    byte[] type = Encoding.UTF8.GetBytes("camVideo");
//                    int i = 0;
//                    for (; i < bitMapArray.Length - bitmapPieceSize; i += bitmapPieceSize)
//                    {
//                        bytePackageCounter = Encoding.UTF8.GetBytes(packageCounter.ToString().ToArray());
//                        Array.Copy(bitMapArray, i, packageToSend, 0, bitmapPieceSize);
//                        type.CopyTo(packageToSend, bitmapPieceSize);
//                        bytePackageCounter.CopyTo(packageToSend, bitmapPieceSize + 8);
//                        sendingUdpClient?.Send(packageToSend, bitmapPieceSize + 24, sendingEndPoint);

//                        packageCounter++;
//                    }
//                    var lastPackageLength = bitMapArray.Length - i + 24;
//                    Array.Resize(ref packageToSend, lastPackageLength);
//                    Array.Clear(packageToSend, 0, packageToSend.Length);
//                    bytePackageCounter = Encoding.UTF8.GetBytes(packageCounter.ToString().ToArray());
//                    Array.Copy(bitMapArray, i, packageToSend, 0, lastPackageLength - 24);
//                    type.CopyTo(packageToSend, lastPackageLength - 24);
//                    bytePackageCounter.CopyTo(packageToSend, lastPackageLength - 16);
//                    sendingUdpClient?.Send(packageToSend, lastPackageLength, sendingEndPoint);
//                }
//            }
//            catch (Exception ex)
//            {
//            }
//        }

//        private void Receiving()
//        {
//            IPEndPoint RemoteIpEndPoint = null;
//            byte[] inputType = new byte[8];
//            int lastVideoPackage = 0;
//            int currentVideoPackage = 0;

//            using (var memStream = new MemoryStream())
//            {
//                while (true)
//                {
//                    try
//                    {
//                        byte[] receiveBytes = receivingUdpClient.Receive(ref RemoteIpEndPoint);
//                        Array.Copy(receiveBytes, receiveBytes.Length - 24, inputType, 0, 8);

//                        // video
//                        if (Encoding.UTF8.GetString(inputType) == "camVideo")
//                        {
//                            currentVideoPackage = Convert.ToInt32(Encoding.UTF8.GetString(receiveBytes, receiveBytes.Length - 16, 16));
//                            if (currentVideoPackage < lastVideoPackage)
//                            {
//                                friendsPictureBox.Image = new Bitmap(memStream);
//                                memStream.SetLength(0);
//                            }
//                            lastVideoPackage = currentVideoPackage;
//                            memStream.WriteAsync(receiveBytes, 0, receiveBytes.Length - 24);
//                        }

//                        //audio 
//                        else if (Encoding.UTF8.GetString(inputType) == "micAudio")
//                        {
//                            bufferStream.AddSamples(receiveBytes, 0, receiveBytes.Length - 24);
//                        }

//                        //message
//                        else if (Encoding.UTF8.GetString(inputType) == "tMessage")
//                        {
//                            var message = Encoding.UTF8.GetString(receiveBytes, 0, receiveBytes.Length - 24);
//                            ChatTextBox.AppendText("\r\nFriend  " + DateTime.Now.ToShortTimeString() + " :\r\n" + message + "\r\n");
//                        }
//                    }
//                    catch (Exception ex)
//                    {
//                        lastVideoPackage = 0;
//                    }
//                }
//            }
//        }

//        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
//        {
//            activeVideoDevice?.SignalToStop();
//            receivingUdpClient?.Close();
//            receivingThread?.Abort();
//            currentAudioDevice.StopRecording();
//        }
//    }
//}