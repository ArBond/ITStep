#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString path;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();

    void on_actionOpen_Font_triggered();

    void on_actionOpen_Color_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
