#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT
    QLabel * lbl;
    QLabel * lbl2;
    QPoint p1,p2;
    QImage * img;
    QPixmap  * pix;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_H
