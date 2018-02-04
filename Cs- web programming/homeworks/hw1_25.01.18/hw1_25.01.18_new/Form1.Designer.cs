using System.Windows.Forms;

namespace hw1_25._01._18_new
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.friendsPictureBox = new System.Windows.Forms.PictureBox();
            this.MyPictureBox = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.IPAddressTextBox = new System.Windows.Forms.TextBox();
            this.LocalPortTextBox = new System.Windows.Forms.TextBox();
            this.RemotePortTextBox = new System.Windows.Forms.TextBox();
            this.ChatTextBox = new System.Windows.Forms.TextBox();
            this.SendingMessageTextBox = new System.Windows.Forms.TextBox();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.SendMessageButton = new System.Windows.Forms.Button();
            this.VideoDevicesComboBox = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.StartCameraButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.friendsPictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.MyPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // friendsPictureBox
            // 
            this.friendsPictureBox.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.friendsPictureBox.Location = new System.Drawing.Point(20, 12);
            this.friendsPictureBox.Name = "friendsPictureBox";
            this.friendsPictureBox.Size = new System.Drawing.Size(454, 321);
            this.friendsPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.friendsPictureBox.TabIndex = 0;
            this.friendsPictureBox.TabStop = false;
            // 
            // MyPictureBox
            // 
            this.MyPictureBox.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.MyPictureBox.Location = new System.Drawing.Point(494, 12);
            this.MyPictureBox.Name = "MyPictureBox";
            this.MyPictureBox.Size = new System.Drawing.Size(131, 88);
            this.MyPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.MyPictureBox.TabIndex = 1;
            this.MyPictureBox.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(512, 138);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "IP address:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(512, 260);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(102, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Remote port:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(518, 199);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 20);
            this.label3.TabIndex = 4;
            this.label3.Text = "Local port:";
            // 
            // IPAddressTextBox
            // 
            this.IPAddressTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.IPAddressTextBox.Location = new System.Drawing.Point(494, 161);
            this.IPAddressTextBox.Name = "IPAddressTextBox";
            this.IPAddressTextBox.Size = new System.Drawing.Size(131, 26);
            this.IPAddressTextBox.TabIndex = 5;
            // 
            // LocalPortTextBox
            // 
            this.LocalPortTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LocalPortTextBox.Location = new System.Drawing.Point(494, 222);
            this.LocalPortTextBox.Name = "LocalPortTextBox";
            this.LocalPortTextBox.Size = new System.Drawing.Size(131, 26);
            this.LocalPortTextBox.TabIndex = 6;
            // 
            // RemotePortTextBox
            // 
            this.RemotePortTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RemotePortTextBox.Location = new System.Drawing.Point(494, 283);
            this.RemotePortTextBox.Name = "RemotePortTextBox";
            this.RemotePortTextBox.Size = new System.Drawing.Size(131, 26);
            this.RemotePortTextBox.TabIndex = 7;
            // 
            // ChatTextBox
            // 
            this.ChatTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ChatTextBox.Location = new System.Drawing.Point(20, 352);
            this.ChatTextBox.Multiline = true;
            this.ChatTextBox.Name = "ChatTextBox";
            this.ChatTextBox.Size = new System.Drawing.Size(454, 106);
            this.ChatTextBox.TabIndex = 8;
            // 
            // SendingMessageTextBox
            // 
            this.SendingMessageTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SendingMessageTextBox.Location = new System.Drawing.Point(20, 464);
            this.SendingMessageTextBox.Multiline = true;
            this.SendingMessageTextBox.Name = "SendingMessageTextBox";
            this.SendingMessageTextBox.Size = new System.Drawing.Size(381, 39);
            this.SendingMessageTextBox.TabIndex = 9;
            // 
            // ConnectButton
            // 
            this.ConnectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ConnectButton.Location = new System.Drawing.Point(494, 445);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(131, 57);
            this.ConnectButton.TabIndex = 10;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            this.ConnectButton.Click += new System.EventHandler(this.ConnectButton_Click);
            // 
            // SendMessageButton
            // 
            this.SendMessageButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SendMessageButton.Location = new System.Drawing.Point(407, 464);
            this.SendMessageButton.Name = "SendMessageButton";
            this.SendMessageButton.Size = new System.Drawing.Size(67, 39);
            this.SendMessageButton.TabIndex = 11;
            this.SendMessageButton.Text = "Send";
            this.SendMessageButton.UseVisualStyleBackColor = true;
            // 
            // VideoDevicesComboBox
            // 
            this.VideoDevicesComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.VideoDevicesComboBox.FormattingEnabled = true;
            this.VideoDevicesComboBox.Location = new System.Drawing.Point(494, 354);
            this.VideoDevicesComboBox.Name = "VideoDevicesComboBox";
            this.VideoDevicesComboBox.Size = new System.Drawing.Size(131, 24);
            this.VideoDevicesComboBox.TabIndex = 12;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(491, 331);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(141, 20);
            this.label4.TabIndex = 13;
            this.label4.Text = "Available cameras:";
            // 
            // StartCameraButton
            // 
            this.StartCameraButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.StartCameraButton.Location = new System.Drawing.Point(494, 384);
            this.StartCameraButton.Name = "StartCameraButton";
            this.StartCameraButton.Size = new System.Drawing.Size(131, 33);
            this.StartCameraButton.TabIndex = 14;
            this.StartCameraButton.Text = "Turn on camera";
            this.StartCameraButton.UseVisualStyleBackColor = true;
            this.StartCameraButton.Click += new System.EventHandler(this.StartCameraButton_Click);
            // 
            // Form1
            // 
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.ClientSize = new System.Drawing.Size(641, 515);
            this.Controls.Add(this.StartCameraButton);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.VideoDevicesComboBox);
            this.Controls.Add(this.SendMessageButton);
            this.Controls.Add(this.ConnectButton);
            this.Controls.Add(this.SendingMessageTextBox);
            this.Controls.Add(this.ChatTextBox);
            this.Controls.Add(this.RemotePortTextBox);
            this.Controls.Add(this.LocalPortTextBox);
            this.Controls.Add(this.IPAddressTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.MyPictureBox);
            this.Controls.Add(this.friendsPictureBox);
            this.Name = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.friendsPictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.MyPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private PictureBox friendsPictureBox;
        private PictureBox MyPictureBox;
        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox IPAddressTextBox;
        private TextBox LocalPortTextBox;
        private TextBox RemotePortTextBox;
        private TextBox ChatTextBox;
        private TextBox SendingMessageTextBox;
        private Button ConnectButton;
        private Button SendMessageButton;
        private ComboBox VideoDevicesComboBox;
        private Label label4;
        private Button StartCameraButton;
    }
}

