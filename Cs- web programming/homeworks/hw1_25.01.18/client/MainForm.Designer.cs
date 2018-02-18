using System.Windows.Forms;

namespace client
{
    partial class MainForm
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
            this.ChatTextBox = new System.Windows.Forms.TextBox();
            this.SendingMessageTextBox = new System.Windows.Forms.TextBox();
            this.SendMessageButton = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.MyPictureBox = new System.Windows.Forms.PictureBox();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.recipientIdTextBox = new System.Windows.Forms.TextBox();
            this.VideoDevicesComboBox = new System.Windows.Forms.ComboBox();
            this.StartCameraButton = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.mainMenuStrip = new System.Windows.Forms.MenuStrip();
            this.connectionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tryToConnectToServerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.webSiteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutBoncherToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutBoncherToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.StartMicroButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.friendsPictureBox)).BeginInit();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.MyPictureBox)).BeginInit();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.mainMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // friendsPictureBox
            // 
            this.friendsPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.friendsPictureBox.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.friendsPictureBox.Location = new System.Drawing.Point(3, 3);
            this.friendsPictureBox.Name = "friendsPictureBox";
            this.friendsPictureBox.Size = new System.Drawing.Size(559, 340);
            this.friendsPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.friendsPictureBox.TabIndex = 0;
            this.friendsPictureBox.TabStop = false;
            // 
            // ChatTextBox
            // 
            this.ChatTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel2.SetColumnSpan(this.ChatTextBox, 2);
            this.ChatTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ChatTextBox.Location = new System.Drawing.Point(3, 349);
            this.ChatTextBox.Multiline = true;
            this.ChatTextBox.Name = "ChatTextBox";
            this.ChatTextBox.ReadOnly = true;
            this.ChatTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.ChatTextBox.Size = new System.Drawing.Size(559, 80);
            this.ChatTextBox.TabIndex = 8;
            // 
            // SendingMessageTextBox
            // 
            this.SendingMessageTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SendingMessageTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SendingMessageTextBox.Location = new System.Drawing.Point(3, 3);
            this.SendingMessageTextBox.Multiline = true;
            this.SendingMessageTextBox.Name = "SendingMessageTextBox";
            this.SendingMessageTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.SendingMessageTextBox.Size = new System.Drawing.Size(478, 41);
            this.SendingMessageTextBox.TabIndex = 9;
            // 
            // SendMessageButton
            // 
            this.SendMessageButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.SendMessageButton.Enabled = false;
            this.SendMessageButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SendMessageButton.Location = new System.Drawing.Point(489, 5);
            this.SendMessageButton.Name = "SendMessageButton";
            this.SendMessageButton.Size = new System.Drawing.Size(67, 39);
            this.SendMessageButton.TabIndex = 11;
            this.SendMessageButton.Text = "Send";
            this.SendMessageButton.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 80.34037F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 19.65963F));
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel4, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 24);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(711, 491);
            this.tableLayoutPanel1.TabIndex = 15;
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel4.ColumnCount = 1;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel4.Controls.Add(this.StartMicroButton, 0, 4);
            this.tableLayoutPanel4.Controls.Add(this.MyPictureBox, 0, 0);
            this.tableLayoutPanel4.Controls.Add(this.VideoDevicesComboBox, 0, 2);
            this.tableLayoutPanel4.Controls.Add(this.StartCameraButton, 0, 3);
            this.tableLayoutPanel4.Controls.Add(this.label4, 0, 1);
            this.tableLayoutPanel4.Controls.Add(this.ConnectButton, 0, 7);
            this.tableLayoutPanel4.Controls.Add(this.recipientIdTextBox, 0, 6);
            this.tableLayoutPanel4.Controls.Add(this.label1, 0, 5);
            this.tableLayoutPanel4.Location = new System.Drawing.Point(574, 3);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 8;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 90F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 45F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 42F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 47F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 51F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 120F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 33F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 35F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(134, 485);
            this.tableLayoutPanel4.TabIndex = 1;
            // 
            // MyPictureBox
            // 
            this.MyPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.MyPictureBox.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.tableLayoutPanel4.SetColumnSpan(this.MyPictureBox, 2);
            this.MyPictureBox.Location = new System.Drawing.Point(3, 3);
            this.MyPictureBox.Margin = new System.Windows.Forms.Padding(3, 3, 3, 2);
            this.MyPictureBox.Name = "MyPictureBox";
            this.MyPictureBox.Size = new System.Drawing.Size(128, 85);
            this.MyPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.MyPictureBox.TabIndex = 1;
            this.MyPictureBox.TabStop = false;
            // 
            // ConnectButton
            // 
            this.ConnectButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.ConnectButton.Enabled = false;
            this.ConnectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ConnectButton.Location = new System.Drawing.Point(3, 434);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(128, 45);
            this.ConnectButton.TabIndex = 10;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(19, 375);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(95, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Friend login:";
            // 
            // recipientIdTextBox
            // 
            this.recipientIdTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.recipientIdTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.recipientIdTextBox.Location = new System.Drawing.Point(3, 398);
            this.recipientIdTextBox.Name = "recipientIdTextBox";
            this.recipientIdTextBox.Size = new System.Drawing.Size(128, 26);
            this.recipientIdTextBox.TabIndex = 5;
            // 
            // VideoDevicesComboBox
            // 
            this.VideoDevicesComboBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.VideoDevicesComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.VideoDevicesComboBox.FormattingEnabled = true;
            this.VideoDevicesComboBox.Location = new System.Drawing.Point(3, 138);
            this.VideoDevicesComboBox.Name = "VideoDevicesComboBox";
            this.VideoDevicesComboBox.Size = new System.Drawing.Size(128, 24);
            this.VideoDevicesComboBox.TabIndex = 12;
            // 
            // StartCameraButton
            // 
            this.StartCameraButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.StartCameraButton.Enabled = false;
            this.StartCameraButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.StartCameraButton.Location = new System.Drawing.Point(3, 187);
            this.StartCameraButton.Name = "StartCameraButton";
            this.StartCameraButton.Size = new System.Drawing.Size(128, 27);
            this.StartCameraButton.TabIndex = 14;
            this.StartCameraButton.Text = "Turn on camera";
            this.StartCameraButton.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(29, 95);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(76, 40);
            this.label4.TabIndex = 13;
            this.label4.Text = "Available cameras:";
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel2.ColumnCount = 1;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel3, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.friendsPictureBox, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.ChatTextBox, 0, 1);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 3;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 80F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 52F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(565, 485);
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 75F));
            this.tableLayoutPanel3.Controls.Add(this.SendingMessageTextBox, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.SendMessageButton, 1, 0);
            this.tableLayoutPanel3.Location = new System.Drawing.Point(3, 435);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 1;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(559, 47);
            this.tableLayoutPanel3.TabIndex = 0;
            // 
            // mainMenuStrip
            // 
            this.mainMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.connectionsToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.mainMenuStrip.Location = new System.Drawing.Point(0, 0);
            this.mainMenuStrip.Name = "mainMenuStrip";
            this.mainMenuStrip.Size = new System.Drawing.Size(711, 24);
            this.mainMenuStrip.TabIndex = 16;
            this.mainMenuStrip.Text = "menuStrip1";
            // 
            // connectionsToolStripMenuItem
            // 
            this.connectionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tryToConnectToServerToolStripMenuItem});
            this.connectionsToolStripMenuItem.Name = "connectionsToolStripMenuItem";
            this.connectionsToolStripMenuItem.Size = new System.Drawing.Size(86, 20);
            this.connectionsToolStripMenuItem.Text = "Connections";
            // 
            // tryToConnectToServerToolStripMenuItem
            // 
            this.tryToConnectToServerToolStripMenuItem.Name = "tryToConnectToServerToolStripMenuItem";
            this.tryToConnectToServerToolStripMenuItem.Size = new System.Drawing.Size(199, 22);
            this.tryToConnectToServerToolStripMenuItem.Text = "Try to connect to server";
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
            this.settingsToolStripMenuItem.Text = "Settings";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.webSiteToolStripMenuItem,
            this.aboutBoncherToolStripMenuItem,
            this.aboutBoncherToolStripMenuItem1});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // webSiteToolStripMenuItem
            // 
            this.webSiteToolStripMenuItem.Name = "webSiteToolStripMenuItem";
            this.webSiteToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.webSiteToolStripMenuItem.Text = "Website";
            // 
            // aboutBoncherToolStripMenuItem
            // 
            this.aboutBoncherToolStripMenuItem.Name = "aboutBoncherToolStripMenuItem";
            this.aboutBoncherToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.aboutBoncherToolStripMenuItem.Text = "Send feedback";
            // 
            // aboutBoncherToolStripMenuItem1
            // 
            this.aboutBoncherToolStripMenuItem1.Name = "aboutBoncherToolStripMenuItem1";
            this.aboutBoncherToolStripMenuItem1.Size = new System.Drawing.Size(154, 22);
            this.aboutBoncherToolStripMenuItem1.Text = "About Boncher";
            // 
            // StartMicroButton
            // 
            this.StartMicroButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.StartMicroButton.Enabled = false;
            this.StartMicroButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.StartMicroButton.Location = new System.Drawing.Point(3, 236);
            this.StartMicroButton.Name = "StartMicroButton";
            this.StartMicroButton.Size = new System.Drawing.Size(128, 27);
            this.StartMicroButton.TabIndex = 15;
            this.StartMicroButton.Text = "Turn on micro";
            this.StartMicroButton.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.ClientSize = new System.Drawing.Size(711, 515);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.mainMenuStrip);
            this.MainMenuStrip = this.mainMenuStrip;
            this.MinimumSize = new System.Drawing.Size(650, 500);
            this.Name = "MainForm";
            ((System.ComponentModel.ISupportInitialize)(this.friendsPictureBox)).EndInit();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel4.ResumeLayout(false);
            this.tableLayoutPanel4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.MyPictureBox)).EndInit();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel3.PerformLayout();
            this.mainMenuStrip.ResumeLayout(false);
            this.mainMenuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        protected internal PictureBox friendsPictureBox;
        protected internal TextBox ChatTextBox;
        protected internal TextBox SendingMessageTextBox;
        protected internal Button SendMessageButton;
        protected internal TableLayoutPanel tableLayoutPanel1;
        protected internal TableLayoutPanel tableLayoutPanel2;
        protected internal TableLayoutPanel tableLayoutPanel3;
        protected internal TableLayoutPanel tableLayoutPanel4;
        protected internal PictureBox MyPictureBox;
        protected internal Button ConnectButton;
        protected internal Label label1;
        protected internal TextBox recipientIdTextBox;
        protected internal ComboBox VideoDevicesComboBox;
        protected internal Button StartCameraButton;
        protected internal Label label4;
        private MenuStrip mainMenuStrip;
        private ToolStripMenuItem connectionsToolStripMenuItem;
        private ToolStripMenuItem tryToConnectToServerToolStripMenuItem;
        private ToolStripMenuItem settingsToolStripMenuItem;
        private ToolStripMenuItem helpToolStripMenuItem;
        private ToolStripMenuItem webSiteToolStripMenuItem;
        private ToolStripMenuItem aboutBoncherToolStripMenuItem;
        private ToolStripMenuItem aboutBoncherToolStripMenuItem1;
        protected internal Button StartMicroButton;
    }
}