#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
   path =  QFileDialog::getOpenFileName(this);
   if(!path.isEmpty())
   {
       QFile file(path);
       file.open(QIODevice::ReadOnly);
       ui->textEdit->setText(QString(file.readAll()));
       file.close();
   }
}

void MainWindow::on_actionOpen_Font_triggered()
{
    bool ok = true;
    ui->textEdit->setFont(QFontDialog::getFont(&ok));
}

void MainWindow::on_actionOpen_Color_triggered()
{
    ui->textEdit->selectAll();
  ui->textEdit->setTextColor(QColorDialog::getColor());

}
