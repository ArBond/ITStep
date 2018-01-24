#include "widget.h"


void Widget::mySlot()
{
    emit mySignal("Good World!");
}

void Widget::myGoodSlot()
{
    lbl->setText("Woooooow!");
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton("Push Me!",this);
    btn->move(50,50);
    lbl = new QLabel("Hello World",this);
    lbl->setFont(QFont("Times New Roman",28));
    connect(btn,SIGNAL(clicked()),SLOT(myGoodSlot()));
    //connect(this,SIGNAL(mySignal(QString)),
    //                 lbl,SLOT(setText(QString)));
    setGeometry(200,200,200,100);
}

Widget::~Widget()
{

}
