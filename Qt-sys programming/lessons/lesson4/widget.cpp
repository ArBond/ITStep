#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel;
    //lbl2 = new QLabel;
    //lbl->setFont(QFont("Arial",28));
    //lbl->setText("Hi!");
    //lbl2->setFont(QFont("Arial",28));
    //lbl2->setText("Bie!");
//Layouts----------------------------
    //auto lay = new QHBoxLayout(this);
    //lay->addWidget(lbl);
    //lay->addWidget(lbl2);
   // img = new QImage(QSize(400,400),QImage::Format_RGB32);
    pix = new QPixmap(200,200);
    //pix->fromImage(*img);
    pix->fill(QColor(255,0,0));
    lbl->setPixmap(*pix);
    auto lay = new QHBoxLayout(this);
    lay->addWidget(lbl);
    setMinimumSize(600,400);
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() ==
            Qt::ControlModifier|Qt::AltModifier) {
        if(event->key() == Qt::Key_P)
        {
            lbl2->setText("Program");
        }
    }
    QWidget::keyPressEvent(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(p1.isNull()) p1 = event->pos();
        else if (!p1.isNull()) {
            p2 = event->pos();
            this->repaint();
            p1 = p2 = QPoint();

        }
    }
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(QBrush(QColor(0,128,25)),7));
    painter.drawLine(p1,p2);
    QWidget::paintEvent(event);
}
