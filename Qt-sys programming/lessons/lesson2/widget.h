#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT
    QLabel * lbl;
    QPushButton * btn;
signals:
    void mySignal(QString);
public slots:
    void mySlot();
    void myGoodSlot();
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
